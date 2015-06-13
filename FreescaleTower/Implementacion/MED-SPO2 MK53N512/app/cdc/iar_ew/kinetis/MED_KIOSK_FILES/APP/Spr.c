/************************************************************************************************************/
/* Services performed by Pounce Consulting in this matter are performed AS IS and without any warranty.		*/
/* CUSTOMER retains the final decision relative to the total design and functionality of the end			*/
/* product.                                                                                     			*/
/* Pounce Consulting neither guarantees nor will be held liable by CUSTOMER for the success of this project.*/
/*                                                                                                  		*/
/* Pounce Consulting disclaims all warranties, express, implied or statutory including, but not limited to, */
/* implied warranty of merchantability or fitness for a particular purpose on any hardware,         		*/
/* software ore advise supplied to the project by Pounce Consulting, and or any product resulting from      */
/* Pounce Consulting services.                                                                              */
/* In no event shall Pounce Consulting be liable for incidental or consequential damages arising out of     */
/* this agreement. CUSTOMER agrees to hold Pounce Consulting harmless against any and all claims demands or */
/* actions by anyone on account of any damage,or injury, whether commercial, contractual, or        		*/
/* tortuous, rising directly or indirectly as a result of the advise or assistance supplied CUSTOMER		*/
/* in connectionwith product, services or goods supplied under this Agreement.                      		*/
/************************************************************************************************************/

#include "Spr.h"


//public variables
UINT8 Spr_IsMeasurementComplete;
UINT8 Spr_GraphData[SPR_OUTBUFFER_SIZE];

//states
static void StateInit(void);
static void StateIdle(void);
static void StateWaitForInhalation(void);
static void StateMeasuringInhalation(void);
static void StateWaitForExhalation(void);
static void StateMeasuringExhalation(void);


//timer events
static void TimerSampleAdcSpr_Event(void);

//send data to PC
static void SendSprGraphDataToPc(void);


/** Main Spr state machine states */
typedef enum
{
	STATE_INIT,
	STATE_IDLE,
	STATE_WAIT_FOR_INHALATION,
	STATE_MEASURING_INHALATION,
	STATE_WAIT_FOR_EXHALATION,
	STATE_MEASURING_EXHALATION,
} SprStates_e;


/* Main state machine */
void (*const SprStateMachine[]) (void) =
{
	StateInit,
	StateIdle,
	StateWaitForInhalation,
	StateMeasuringInhalation,
	StateWaitForExhalation,
	StateMeasuringExhalation,
};

/* Private variables */
static MovingAverage_uint16_t SprPressureSignal;

static UINT8 SprActualState = STATE_INIT;
static UINT8 IsnewSampleAvailable;
static UINT8 SprActualEvent = EVENT_SPR_NONE;
static UINT16 SprPressureSignalOffset = 0;


static UINT8 IgnoreInitialSamplesCounter;

//timers
static UINT8 TimerSampleAdcSpr;

//for sending data
static UINT8 SprBufferIndex;


/*************************************************************/



/* States and substates */
static void StateInit(void)
{
	static UINT16 initSamples = INIT_SAMPLES;
	static UINT32 initSamplesSum = 0;

	if (IsnewSampleAvailable)
	{
		IsnewSampleAvailable = FALSE;	
		
		if (IgnoreInitialSamplesCounter > 0)
		{
			IgnoreInitialSamplesCounter--;
		}
		else
		{		
			if (initSamples > 0)
			{
				initSamples--;
				initSamplesSum += SprPressureSignal.Result;
			}
			else
			{
				SprPressureSignalOffset = (UINT16) (initSamplesSum/(INIT_SAMPLES));
				//SprPressureSignalOffset = 2048;
				Spr_AbortMeasurement();
				initSamplesSum = 0;
				Spr_IsMeasurementComplete = TRUE;
			}				
		}
	}
}

static void StateIdle(void)
{
	//do nothing
}






static void StateWaitForInhalation(void)
{
	if (IsnewSampleAvailable)
	{
		IsnewSampleAvailable = FALSE;

		#ifdef NO_THRESHOLD
		SendSprGraphDataToPc();
		#else

		if(IgnoreInitialSamplesCounter>0)
		{
			IgnoreInitialSamplesCounter--;
		}
		else
		{				
			if (SprPressureSignal.Result < (SprPressureSignalOffset - INHALATION_DETECTION_THRESHOLD))
			{
				SprActualState = STATE_MEASURING_INHALATION;
			}
		}
		#endif
	}
}




static void StateMeasuringInhalation(void)
{
	if (IsnewSampleAvailable)
	{
		IsnewSampleAvailable = FALSE;
		
		SendSprGraphDataToPc();
		
		//if signal goes back to "zero", measure exhalation
		if ((SprPressureSignal.Result) >= SprPressureSignalOffset)
		{
			SprActualState = STATE_WAIT_FOR_EXHALATION;
		}
	}
}


static void StateWaitForExhalation(void)
{
	if (IsnewSampleAvailable)
	{
		IsnewSampleAvailable = FALSE;
		
		//wait here until signal goes above the detection threshold
		if (SprPressureSignal.Result > (SprPressureSignalOffset + INHALATION_DETECTION_THRESHOLD))
		{
			SprActualState = STATE_MEASURING_EXHALATION;
		}
	}	
}
	
	
static void StateMeasuringExhalation(void)
{
	if (IsnewSampleAvailable)
	{
		IsnewSampleAvailable = FALSE;
		
		SendSprGraphDataToPc();
			
		//check if exhalation has finished
		
		if ((SprPressureSignal.Result) <= (SprPressureSignalOffset + STOP_DETECTION_THRESHOLD))
		{
			SprActualEvent = EVENT_SPR_NEW_DATA_READY;
			Spr_IsMeasurementComplete = TRUE;			
			Spr_AbortMeasurement();
		}
	}
}




static void SendSprGraphDataToPc(void)
{
	//store data and send it when the buffer is full
	if (SprBufferIndex < SPR_OUTBUFFER_SIZE)
	{	          
                //send flow signal
		Spr_GraphData[SprBufferIndex++] = (UINT8)(SprPressureSignal.Result >> 8); 		//higher byte
		Spr_GraphData[SprBufferIndex++] = (UINT8)(SprPressureSignal.Result & 0x00FF); 	//lower byte				
	}
	else
	{
		//buffer is full, call the NEW_DATA_READY event
		SprActualEvent = EVENT_SPR_NEW_DATA_READY;
		SprBufferIndex = 0;
	}							
}




static void TimerSampleAdcSpr_Event(void)
{
	UINT16 SprPressureSignalRaw;
	
	//sample ADC signals
	SprPressureSignalRaw = ADC0_Read12b(ADC_CHANNEL_SPR_PRESSURE_SIGNAL);

	//perform moving average to avoid noise
	MovingAverage_PushNewValue16b(&SprPressureSignal, SprPressureSignalRaw);
	
	//SprPressureSignal.Result = 	SprPressureSignalRaw; //test if the problem is in moving average
	
	IsnewSampleAvailable = TRUE;
	SwTimer_StartTimer(TimerSampleAdcSpr, SPR_SAMPLING_PERIOD);
}





/*******************************
* Public functions
*********************************/

/* call this only once at the beginning of the application */
void Spr_Init(void)
{	
	SprActualState = STATE_INIT;
	//SprPressureSignalOffset = 2048;
	//SPR_BOARD_ON();		//turn on board because SPR needs to measure initial offset    
	
	TimerSampleAdcSpr = SwTimer_CreateTimer(TimerSampleAdcSpr_Event);	
		
	ADC0_Init12b();
	
	IgnoreInitialSamplesCounter = IGNORED_INITIAL_SAMPLES;
	
	//perform initial measurment to obtain signal offset
	SwTimer_StartTimer(TimerSampleAdcSpr, SENSOR_WARM_UP_TIME);	
}



UINT8 Spr_StartMeasurement(void)
{
	UINT8 status = FALSE;
				 
	if (SprActualState == STATE_IDLE)
	{
		ADC0_Init12b();
			 	
		SprBufferIndex = 0;
		
		SprActualState = STATE_WAIT_FOR_INHALATION;		
		Spr_IsMeasurementComplete = FALSE;
		
		//SprPressureSignalOffset = 2170;
		
		IgnoreInitialSamplesCounter = IGNORED_INITIAL_SAMPLES;
		
		//start timer to sample ADC 				
		SwTimer_StartTimer(TimerSampleAdcSpr, SENSOR_WARM_UP_TIME);		
		
		status = TRUE;
	}
	else
	{
		status = FALSE;
	}
	return status;
}




void Spr_AbortMeasurement(void)
{
	SwTimer_StopTimer(TimerSampleAdcSpr);
	SprActualState = STATE_IDLE;
	
	//SPR_BOARD_OFF();
}



void Spr_PeriodicTask(void)
{
	/* State machine handler */
	SprStateMachine[SprActualState]();

	/* Event handler */
	if (SprActualEvent != EVENT_SPR_NONE)
	{
		if (Spr_Events[SprActualEvent] != NULL)
		{			
			Spr_Events[SprActualEvent]();	//execute registered event
			SprActualEvent = EVENT_SPR_NONE;
		}		
	}	
}



