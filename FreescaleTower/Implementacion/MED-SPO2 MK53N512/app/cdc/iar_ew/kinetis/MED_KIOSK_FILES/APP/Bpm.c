#include "Bpm.h"

//public variables
UINT16 Bpm_HeartRate;
UINT8 Bpm_SystolicPressure;
UINT8 Bpm_DiastolicPressure;
UINT8 Bpm_LeakTestResult;
UINT8 Bpm_MeanArterialPressure;
UINT8 Bpm_ActualPressureValue;
UINT8 Bpm_ErrorCode = BPM_ERROR_OK;
UINT8 Bpm_HearBeatDetected = FALSE;

#ifdef BPM_DEBUG
UINT8 Bpm_GraphData[BPM_BUFFER_SIZE];
#endif


/* Private functions */

//states
static void StateIdle(void);
static void StateMeasuring(void);
static void StateLeakTest(void);

//state measuring sub-states
static void StateMeasuringSubStateIgnoringInitialPoints(void);
static void StateMeasuringSubStateFindingMaxPoint(void);
static void StateMeasuringSubStateFindingMinPoint(void);

//functions
static void SendRealTimeDataToPc(void);
static UINT8 ConvertAdcValueTommHg(UINT16 adcValue);
static void BpmResetVariables(void);
static void ReportMeasurementError(void);

//timer events
static void TimerSampleAdcBpm_Event(void);
static void TimerLeakTest_Event(void);



/* Main state machine */
void (*const BpmStateMachine[]) (void) =
{
	StateIdle,
	StateMeasuring,
	StateLeakTest
};


/* Private variables */
static MovingAverage_uint16_t HeartBeatSignal;
static MovingAverage_uint16_t PressureSignal;

static UINT8 BpmActualState = STATE_IDLE;
static UINT8 BpmActualSubState = 0;
static UINT8 IsnewSampleAvailable;
static UINT8 BpmActualEvent = EVENT_BPM_NONE;
static UINT16 Bpm_MaxPressureValue = 1900;
static UINT8 Bpm_PulseDetected = FALSE;
static UINT8 Bpm_MaxPressureCalculated = FALSE;
static UINT8 Bpm_SubsateCalculateMaxPressureValue = FINDING_LARGE_PULSE;
static UINT16 BpmSamplesBetweenPulses = 0;



//timers
static UINT8 TimerSampleAdcBpm;
static UINT8 TimerLeakTest;
static UINT8 TimerTurnOffBpm;


static UINT16 BpmPressureArray[BPM_ARRAY_LENGTH];
static UINT16 BpmEnvelopeArray[BPM_ARRAY_LENGTH];
static UINT16 Bpm_HeartRateArray[BPM_ARRAY_LENGTH] = 0;


static UINT16 MaxHeartBeatValue;
static UINT16 MinHeartBeatValue;
static UINT8 CurrentArrayPosition;
static UINT16 BpmIgnoreSamplesCounter = 0;

//for debug (sending real time data)
static UINT8 BpmBufferIndex;
//end debug




/*************************************************************/



/* States and substates */

static void StateIdle(void)
{
	//do nothing
}



static void StateLeakTest(void)
{
	if (IsnewSampleAvailable)
	{
		IsnewSampleAvailable = FALSE;
		
		#ifdef BPM_DEBUG
		SendRealTimeDataToPc();
		#endif

		switch (BpmActualSubState)
		{

			case LEAK_TEST_SUBSTATE_INFLATING_PHASE_0:
				//do nothing
				//wait for timeout to occur
				break;

			case LEAK_TEST_SUBSTATE_PARTIALLY_INFLATED:
				//if the pressure is below MAYOR_LEAK_PRESSURE_THRESHOLD, there is mayor leak

				if (PressureSignal.Result < MAYOR_LEAK_PRESSURE_THRESHOLD)
				{
					//stop test and send event
					Bpm_AbortLeakTest();
					Bpm_LeakTestResult = MAYOR_LEAK;
					BpmActualEvent = EVENT_BPM_LEAK_TEST_COMPLETE;
					SwTimer_StartTimer(TimerTurnOffBpm, TURN_OFF_BPM_TIME);
				}
				else
				{
					BpmActualSubState = LEAK_TEST_SUBSTATE_INFLATING_PHASE_1;
				}

				break;

			case LEAK_TEST_SUBSTATE_INFLATING_PHASE_1:
				//when the desired pressure is reached, stop the motor and check for leaks

				if (PressureSignal.Result > LEAK_TEST_MAX_PRESSURE_VALUE)
				{
					BPM_STOP_MOTOR();
					//start timer to continue test
					SwTimer_StartTimer(TimerLeakTest, LEAK_TEST_TOTALLY_INFLATED_TIMEOUT);
					BpmActualSubState = LEAK_TEST_SUBSTATE_TOTALLY_INFLATED;
				}

				break;


			case LEAK_TEST_SUBSTATE_TOTALLY_INFLATED:
				//wait for timeout to occur
				break;


			case LEAK_TEST_SUBSTATE_CHECK_LEAKS:
				//if the pressure is below MINOR_LEAK_PRESSURE_THRESHOLD, there is minor leak

				if (PressureSignal.Result < MAYOR_LEAK_PRESSURE_THRESHOLD)
				{
					Bpm_LeakTestResult = MAYOR_LEAK;
				}
				else if (PressureSignal.Result < MINOR_LEAK_PRESSURE_THRESHOLD)
				{
					Bpm_LeakTestResult = MINOR_LEAK;
				}
				else if (PressureSignal.Result < NO_LEAK_PRESSURE_THRESHOLD)
				{
					Bpm_LeakTestResult = NO_LEAK;
				}

				//stop test and send event
				Bpm_AbortLeakTest();

				BpmActualEvent = EVENT_BPM_LEAK_TEST_COMPLETE;

				break;
		}
	}
}



static void StateMeasuring(void)
{
	if (IsnewSampleAvailable)
	{
		IsnewSampleAvailable = FALSE;

		if (BpmIgnoreSamplesCounter > 0)
		{
			BpmIgnoreSamplesCounter--;
		}
		else
		{
			BpmSamplesBetweenPulses++;
			
			
			

			if ((PressureSignal.Result > Bpm_MaxPressureValue) || (PressureSignal.Result > MAX_PRESSURE_VALUE))
			{
				UINT16 i = 0;
				UINT16 envelopeMAPValue = 0;
				UINT16 envelopeSysValue = 0;
				UINT16 envelopeDiaValue = 0;

				UINT16 SystolicAdcValue;
				UINT16 DiastolicAdcValue;

				UINT16 envelopeMAPIndex = 0;


				Bpm_ErrorCode = BPM_ERROR_OK;
				
				//for debugging only
				//UINT8 envelopeDiaIndex = 0;
				//UINT8 envelopeSysIndex = 0;
				//end debug


				Bpm_AbortMeasurement();

				//perform analysis

				//find maximum envelope value (MAP)

				for (i = 0; i < CurrentArrayPosition; i++)
				{
					if (BpmEnvelopeArray[i] > envelopeMAPValue)
					{
						envelopeMAPValue = BpmEnvelopeArray[i];
						envelopeMAPIndex = i;
					}
				}
				Bpm_MeanArterialPressure = ConvertAdcValueTommHg(BpmPressureArray[envelopeMAPIndex]);

				//find value that matches 70% and 50%
				envelopeSysValue = (envelopeMAPValue * _70_PERCENT) / 10;

				envelopeDiaValue = (envelopeMAPValue * _50_PERCENT) / 10;


				//find in the array, the pressure value that matches systolic
				//it starts searching from the last value, to the MAP value
				for (i = CurrentArrayPosition; i > envelopeMAPIndex; i--)
				{
					if (BpmEnvelopeArray[i] >= envelopeSysValue)
					{
						SystolicAdcValue = BpmPressureArray[i];

						//the inflating pressure was not enough, this guy must visit a doctor!!!

						if (i == CurrentArrayPosition)
						{
							//!!!!!!!!!!!!!!!!!!!!!!!!!
							// TO DO: need to restart measurment with a higher max pressure
							//!!!!!!!!!!!!!!!!!!!!!!!!!!
							Bpm_ErrorCode = BPM_ERROR_NOT_ENOUGH_INFLATING_PRESSURE;
							ReportMeasurementError();
							//BpmActualEvent = EVENT_BPM_MEASUREMENT_ERROR;
							return;
						}

						//envelopeSysIndex = i; 	//just for debug
						break;
					}
				}

				//didn't find a systolic pressure
				if (i == envelopeMAPIndex)
				{
					Bpm_ErrorCode = BPM_ERROR_SYSTOLIC_NOT_FOUND;
					ReportMeasurementError();
					//BpmActualEvent = EVENT_BPM_MEASUREMENT_ERROR;
					return;
				}

				
				#define VALID_DIASTOLIC_INDEX		2	
				#define ERROR_DIASTOLIC_INDEX		envelopeMAPIndex - 4


				//find in the array, the pressure value that matches systolic
				for (i = 0; i < envelopeMAPIndex; i++)
				{
					if (BpmEnvelopeArray[i] >= envelopeDiaValue)
					{
						DiastolicAdcValue = BpmPressureArray[i];
						
						//a high pulse was found at the beginning, maybe the patient moved the arm
						if ((i > VALID_DIASTOLIC_INDEX) && (i < ERROR_DIASTOLIC_INDEX))
						{
							//envelopeDiaIndex = i;		//just for debug						
							break;												
						}
					}
				}

				//didn't find diastolic pressure
				if (i == envelopeMAPIndex)
				{
					Bpm_ErrorCode = BPM_ERROR_DIASTOLIC_NOT_FOUND;
					ReportMeasurementError();
					//BpmActualEvent = EVENT_BPM_MEASUREMENT_ERROR;
					return;
				}
				

				//calculate HeartRate
				for (i = (envelopeMAPIndex - 4); i < (envelopeMAPIndex + 4); i++)
				{
					Bpm_HeartRate += Bpm_HeartRateArray[i];
				}

				Bpm_HeartRate /= 8;


				if (Bpm_ErrorCode != BPM_ERROR_OK)
				{
					ReportMeasurementError();
					//BpmActualEvent = EVENT_BPM_MEASUREMENT_ERROR;
				}

				else	//measurement was ok
				{
					Bpm_SystolicPressure = ConvertAdcValueTommHg(SystolicAdcValue);		//Calculate systolic pressure in mmHg
					Bpm_DiastolicPressure = ConvertAdcValueTommHg(DiastolicAdcValue);	//Calculate diastolic pressure in mmHg
					BpmActualEvent = EVENT_BPM_MEASUREMENT_COMPLETE_OK;
					SwTimer_StartTimer(TimerTurnOffBpm, TURN_OFF_BPM_TIME);
				}
			}
			else	//the max pressure hasn't been reached, find min and max points
			{
				switch (BpmActualSubState)
				{

					case BPM_STATE_MEASURING_SUBSTATE_DELAY:
						StateMeasuringSubStateIgnoringInitialPoints();
						break;

					case BPM_STATE_MEASURING_SUBSTATE_FIND_MAX_POINT:
						StateMeasuringSubStateFindingMaxPoint();
						break;

					case BPM_STATE_MEASURING_SUBSTATE_FIND_MIN_POINT:
						StateMeasuringSubStateFindingMinPoint();
						break;
				}
			}
		}
	}
}


static void StateMeasuringSubStateIgnoringInitialPoints(void)
{
	static UINT16 samplesLeftForDelay = BPM_INITIAL_DELAY;

	if (samplesLeftForDelay == 0)
	{
		BpmActualSubState = BPM_STATE_MEASURING_SUBSTATE_FIND_MAX_POINT;
		samplesLeftForDelay = BPM_INITIAL_DELAY;

		//report an error if the pressure is not changing

		if (PressureSignal.Result < MAYOR_LEAK_PRESSURE_THRESHOLD)
		{
			Bpm_ErrorCode = BPM_ERROR_AIR_LEAKAGE;
			ReportMeasurementError();
			
		}
	}
	else
	{
		samplesLeftForDelay--;
	}
}


static void StateMeasuringSubStateFindingMaxPoint(void)
{
	static UINT8 samplesLeftBeforeRestartingMaxCounter = 0;

	//if the heart beat signal is going up

	if (HeartBeatSignal.Result > MaxHeartBeatValue)
	{
		samplesLeftBeforeRestartingMaxCounter = BPM_COMPARATION_WINDOW_SIZE;
		MaxHeartBeatValue = HeartBeatSignal.Result;
	}
	else
	{
		samplesLeftBeforeRestartingMaxCounter--;

		//if no more maximum peaks detected

		if (samplesLeftBeforeRestartingMaxCounter == 0)
		{
		
			MinHeartBeatValue = MaxHeartBeatValue;
			BpmActualSubState = BPM_STATE_MEASURING_SUBSTATE_FIND_MIN_POINT;
			Bpm_HeartRateArray[CurrentArrayPosition] = 60000 / (BpmSamplesBetweenPulses * BPM_SAMPLING_PERIOD);
			BpmSamplesBetweenPulses = 0;

			samplesLeftBeforeRestartingMaxCounter = BPM_COMPARATION_WINDOW_SIZE;
		}
	}
}



static void StateMeasuringSubStateFindingMinPoint(void)
{
	static UINT8 samplesLeftBeforeRestartingMinCounter = 0;
	UINT16 heartbeatAmplitude;

	//if the signal is going down

	if (HeartBeatSignal.Result < MinHeartBeatValue)
	{
		samplesLeftBeforeRestartingMinCounter = BPM_COMPARATION_WINDOW_SIZE;
		MinHeartBeatValue = HeartBeatSignal.Result;
	}
	else	//the slope changed
	{
		samplesLeftBeforeRestartingMinCounter--;

		//no more negative peaks found

		if (samplesLeftBeforeRestartingMinCounter == 0)
		{
			samplesLeftBeforeRestartingMinCounter = BPM_COMPARATION_WINDOW_SIZE;

			//if the slope is big enough, report this as a peak and store the amplitude and pressure value


			
			
			if ((HeartBeatSignal.Result - MinHeartBeatValue) > BPM_MINIMUM_AMPLITUDE)
			{
					if (CurrentArrayPosition < BPM_ARRAY_LENGTH)	//space is available in the array
					{												
						heartbeatAmplitude = MaxHeartBeatValue - MinHeartBeatValue;

						if ((heartbeatAmplitude > BPM_MINIMUM_AMPLITUDE) && 
							(PressureSignal.Result > BPM_MINIMUM_PRESSURE)) //ignores small pulses or pulse when Pressure is below 40 mmHg (minumum diastolic pressure)
						{
							BpmEnvelopeArray[CurrentArrayPosition] = heartbeatAmplitude;
							BpmPressureArray[CurrentArrayPosition] = PressureSignal.Result;
							
							Bpm_HearBeatDetected = TRUE;


							switch (Bpm_SubsateCalculateMaxPressureValue)
							{

								case FINDING_LARGE_PULSE:

									if (BpmEnvelopeArray[CurrentArrayPosition] > LARGE_PULSE_THRESHOLD)  // first large pulse is detected
									{
										Bpm_SubsateCalculateMaxPressureValue = FINDING_SMALL_PULSE;
									}

									break;

								case FINDING_SMALL_PULSE:

									if (BpmEnvelopeArray[CurrentArrayPosition] < SMALL_PULSE_THRESHOLD) //check if a pulse falls below 500, weak pulses mean systolic pressure has been passed
									{
										Bpm_MaxPressureValue = PressureSignal.Result + ADITIONAL_INFLATE_PRESSURE; //adjust maximum inflation pressure above current pressure
										Bpm_SubsateCalculateMaxPressureValue = VALIDATE_MAX_PRESSURE_VALUE;
									}

									break;

								case VALIDATE_MAX_PRESSURE_VALUE:

									if (BpmEnvelopeArray[CurrentArrayPosition] > LARGE_PULSE_THRESHOLD) //check if a large pulse is detected, means the weak peak detected before was not above systolic pressure
									{
										Bpm_MaxPressureValue = INITIAL_MAX_PRESSURE_VALUE;
										Bpm_SubsateCalculateMaxPressureValue = FINDING_SMALL_PULSE;

									}

									break;
							}

							CurrentArrayPosition++;

						}
					}
					else
					{
						//array is full
						Bpm_ErrorCode = BPM_ERROR_ARRAY_IS_FULL;
						ReportMeasurementError();
					}
					
					MaxHeartBeatValue = MinHeartBeatValue;
					BpmActualSubState = BPM_STATE_MEASURING_SUBSTATE_FIND_MAX_POINT;
					
					//change state
			}
		}
	}
}







static UINT8 ConvertAdcValueTommHg(UINT16 adcValue)
{
	UINT32 pressureInmmHg;

	pressureInmmHg = (UINT32)adcValue * 555;
	pressureInmmHg /= 4096;
	pressureInmmHg -= 22;
	pressureInmmHg *= 75;
	pressureInmmHg /= 100;
	return ((UINT8)pressureInmmHg);
}


static void ReportMeasurementError(void)
{
	Bpm_AbortMeasurement();
	BpmActualEvent = EVENT_BPM_MEASUREMENT_ERROR;
}

static void BpmResetVariables(void)
{

	UINT8 i;

	//Restore variables

	MaxHeartBeatValue = 0;
	MinHeartBeatValue = 4096;
	CurrentArrayPosition = 0;
	Bpm_MaxPressureValue = INITIAL_MAX_PRESSURE_VALUE;
	Bpm_PulseDetected = FALSE;
	Bpm_MaxPressureCalculated = FALSE;
	Bpm_SubsateCalculateMaxPressureValue = FINDING_LARGE_PULSE;
	BpmSamplesBetweenPulses = 0;
	
	//clean arrays
	for (i = 0; i < BPM_ARRAY_LENGTH; i++)
	{
		BpmEnvelopeArray[i] = 0;
		BpmPressureArray[i] = 0;
		Bpm_HeartRateArray[i] = 0;
	}

}



#ifdef BPM_DEBUG
static void SendRealTimeDataToPc(void)
{
	//store data and send it when the buffer is full
	if (BpmBufferIndex < BPM_BUFFER_SIZE)
	{
		//send pressure signal
		Bpm_GraphData[BpmBufferIndex++] = (UINT8)(PressureSignal.Result >> 8); 		//higher byte;
		Bpm_GraphData[BpmBufferIndex++] = (UINT8)(PressureSignal.Result & 0x00FF); 	//lower byte

		//send heart beat signal
		Bpm_GraphData[BpmBufferIndex++] = (UINT8)(HeartBeatSignal.Result >> 8); 		//higher byte
		Bpm_GraphData[BpmBufferIndex++] = (UINT8)(HeartBeatSignal.Result & 0x00FF); 	//lower byte
	}
	else
	{
		//buffer is full, call the EVENT_ECG_DATA_READY event
		BpmActualEvent = EVENT_BPM_NEW_DATA_READY;
		BpmBufferIndex = 0;
	}
}
#endif



#define SAMPLES_BEFORE_SENDING_PRESSURE_SIGNAL		25
UINT8 SamplesBeforeSendingPressureSignal = SAMPLES_BEFORE_SENDING_PRESSURE_SIGNAL;


static void TimerSampleAdcBpm_Event(void)
{
	
	UINT16 heartRateSignalRaw, pressureSignalRaw;

	//sample ADC signals
	heartRateSignalRaw = ADC_Read12b(ADC_CHANNEL_HEART_BEAT_SIGNAL);
	pressureSignalRaw = ADC_Read12b(ADC_CHANNEL_PRESSURE_SIGNAL);

	//perform moving average to avoid noise
	MovingAverage_PushNewValue16b(&HeartBeatSignal, heartRateSignalRaw);
	MovingAverage_PushNewValue16b(&PressureSignal, pressureSignalRaw);

	IsnewSampleAvailable = TRUE;
	SwTimer_StartTimer(TimerSampleAdcBpm, BPM_SAMPLING_PERIOD);

	
	#ifdef BPM_DEBUG
	SendRealTimeDataToPc();
	#endif
	
	if (SamplesBeforeSendingPressureSignal == 0)
	{
		//generate event
		Bpm_ActualPressureValue = ConvertAdcValueTommHg(PressureSignal.Result);
		SamplesBeforeSendingPressureSignal = SAMPLES_BEFORE_SENDING_PRESSURE_SIGNAL;
		BpmActualEvent = EVENT_BPM_SEND_PRESSURE_VALUE_TO_PC;		
	}
	else
	{
		SamplesBeforeSendingPressureSignal--;	
	}
}


static void TimerLeakTest_Event(void)
{
	switch (BpmActualSubState)
	{

		case LEAK_TEST_SUBSTATE_INFLATING_PHASE_0:
			BpmActualSubState = LEAK_TEST_SUBSTATE_PARTIALLY_INFLATED;
			break;

		case LEAK_TEST_SUBSTATE_TOTALLY_INFLATED:
			BpmActualSubState = LEAK_TEST_SUBSTATE_CHECK_LEAKS;
			break;
	}
}



static void TimerTurnOffBpm_Event(void)
{
	BpmActualEvent = EVENT_BPM_CUFF_DEINFLATED;
}



/*******************************
* Public functions
*********************************/

/* call this only once at the beginning of the application */
void Bpm_Init(void)
{
	TimerSampleAdcBpm = SwTimer_CreateTimer(TimerSampleAdcBpm_Event);
	TimerLeakTest =  SwTimer_CreateTimer(TimerLeakTest_Event);
	TimerTurnOffBpm = SwTimer_CreateTimer(TimerTurnOffBpm_Event);
}


UINT8 Bpm_StartMeasurement(void)
{
	UINT8 status = FALSE;

	if (BpmActualState == STATE_IDLE)
	{
		

		BPM_CLOSE_VALVE();
		BPM_STOP_MOTOR();
/* Uncoment this when pins are ready */
//		BPM_MOTOR_DD_PIN = OUTPUT;
//		BPM_VALVE_DD_PIN = OUTPUT;

		BpmResetVariables();

		ADC_Init12b(1 << ADC_CHANNEL_PRESSURE_SIGNAL |
		            1 << ADC_CHANNEL_HEART_BEAT_SIGNAL);


		BpmActualState = STATE_MEASURING;
		BpmBufferIndex = 0;
		
		BpmIgnoreSamplesCounter = SAMPLES_TO_IGNORE_AT_START;

		//start timer to sample ADC
		SwTimer_StartTimer(TimerSampleAdcBpm, BPM_SAMPLING_PERIOD);

		BPM_CLOSE_VALVE();
		BPM_START_MOTOR();

		status = TRUE;
	}
	else
	{
		status = FALSE;
	}

	return status;
}




void Bpm_AbortMeasurement(void)
{
	BPM_STOP_MOTOR();
	BPM_OPEN_VALVE();

	SwTimer_StopTimer(TimerSampleAdcBpm);
	BpmActualState = STATE_IDLE;
	BpmActualSubState = 0;
	SwTimer_StartTimer(TimerTurnOffBpm, TURN_OFF_BPM_TIME);
}



void Bpm_PeriodicTask(void)
{
	/* State machine handler */
	BpmStateMachine[BpmActualState]();

	/* Event handler */

	if (BpmActualEvent != EVENT_BPM_NONE)
	{
		if (Bpm_Events[BpmActualEvent] != NULL)
		{
			Bpm_Events[BpmActualEvent]();	//execute registered event
			BpmActualEvent = EVENT_BPM_NONE;
		}
	}

}



//close valve and inflate
//if pressure doesnt increase in a period of time, there is leakeage
//when pressure reaches desired value, stop motor
//measure time, if pressure decreases a certain value during that time, there is leakage

UINT8 Bpm_StartLeakTest(void)
{
	UINT8 status = FALSE;

	if (BpmActualState == STATE_IDLE)
	{
		ADC_Init12b(1 << ADC_CHANNEL_PRESSURE_SIGNAL);

		BpmActualState = STATE_LEAK_TEST;

		BpmBufferIndex = 0;

		//start timer to sample ADC
		SwTimer_StartTimer(TimerSampleAdcBpm, BPM_SAMPLING_PERIOD);

		//start timer to check leaks
		SwTimer_StartTimer(TimerLeakTest, LEAK_TEST_PARTIALLY_INFLATED_TIMEOUT);
		BpmActualSubState = LEAK_TEST_SUBSTATE_INFLATING_PHASE_0;

		BPM_CLOSE_VALVE();
		BPM_START_MOTOR();

		status = TRUE;
	}
	else
	{
		status = FALSE;
	}

	return status;
}


void Bpm_AbortLeakTest(void)
{
	SwTimer_StopTimer(TimerSampleAdcBpm);
	SwTimer_StopTimer(TimerLeakTest);
	BPM_STOP_MOTOR();
	BPM_OPEN_VALVE();
	BpmActualState = STATE_IDLE;
	BpmActualSubState = 0;
	SwTimer_StartTimer(TimerTurnOffBpm, TURN_OFF_BPM_TIME);
}



