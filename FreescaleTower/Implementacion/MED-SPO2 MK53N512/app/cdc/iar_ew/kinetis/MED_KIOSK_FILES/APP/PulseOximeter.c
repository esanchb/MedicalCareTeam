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

#include "PulseOximeter.h"

//public variables
UINT8 SpO2_HeartRate;
UINT8 SpO2_SaturationValue;
UINT8 SpO2_HeartBeatDetected;
UINT8 SpO2Graph[SPO2_REAL_TIME_DATA_ARRAY_LENGTH];


/* Private functions */

//states
static void StateIdle(void);
static void StateMeasuring(void);

//functions
static void SaveGraphData(void);
static void ResetVariables(void);
static void CalculateHeartRateAndSpO2(void);

static void CalibrateIRLedIntensity(void);
static void CalibrateRedLedIntensity(void);

static void DoCalculations(void);
static void FindMaxAndMin(void);

void vfnCleanBuffer (unsigned long *pu16BufferToClean, unsigned long u16BufferSize);


//timer events
static void TimerSendGraphData_Event(void);


/* Main state machine */
const pFunc_t SpO2StateMachine[] =
{
	StateIdle,
	StateMeasuring
};



typedef enum
{
	SPO2_CONTROL_RED,
	SPO2_CONTROL_IR,
}SPO2_CONTROLS; //@TEST

/* Private variables */
static MovingAverage_uint16_t SpO2RedLedSignal;
static MovingAverage_uint16_t SpO2IRLedSignal;
static MovingAverage_uint16_t SpO2RedBaselineSignal;
static MovingAverage_uint16_t SpO2IRBaselineSignal;

static UINT16 SpO2IRMax = 0;
static UINT16 SpO2IRMin = 0;

static UINT16 SpO2RedMax = 0;
static UINT16 SpO2RedMin = 0;

static UINT8 SpO2ValidValue;

static UINT8 SpO2HeartRateArray[SPO2_ARRAY_LENGTH];
static UINT8 SpO2SpO2Array[SPO2_ARRAY_LENGTH];

UINT8 CopyOfSpO2HeartRateArray[SPO2_ARRAY_LENGTH];
UINT8 CopyOfSpO2SpO2Array[SPO2_ARRAY_LENGTH];



static UINT16 SpO2SamplesBetweenPulses = 0; //counts the samples between 2 max points to calculate the HR


static UINT8 SpO2ActualState = SPO2_STATE_IDLE;
//static UINT8 SpO2ActualSubState = 0; //@TEST
static UINT8 SpO2ActualSubStateSubState = 0;

static UINT8 IsTimeToUpdateGraphData = FALSE;
static UINT8 SpO2ActualEvent = SPO2_EVENT_NONE;
static UINT8 SpO2IsDiagnosticMode = FALSE;

//static UINT8 IsSignalStable = FALSE; //@TEST
static UINT16 TimerToRecalibrate = 0;


//timers
static UINT8 TimerSendGraphData;

				


//sending real time data

static UINT8 SpO2GraphActualPosition;

#define INITIAL_PWM_PERCENTAGE      0

static UINT16 PwmRedValue = INITIAL_PWM_PERCENTAGE;
static UINT16 PwmIRValue = INITIAL_PWM_PERCENTAGE;



#define SPO2_PWM_LEDS_CHANNEL	1		//PWM channel for LEDs
#define SPO2_PWM_OFFSET_VALUE	2		//PWM channel for signal offset



#define ADC_RESOLUTION			4095
#define REF_VOLTAGE_mV			3300	//mV

#define _1000mV		(UINT32)(((UINT32)1000*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)
#define _500mV		(UINT32)(((UINT32)500*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)
#define _100mV		(UINT32)(((UINT32)100*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)
#define _50mV		(UINT32)(((UINT32)50*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)
#define _10mV		(UINT32)(((UINT32)10*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)
#define _5mV		(UINT32)(((UINT32)5*(UINT32)ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)



#define BASELINE_SETPOINT				_1000mV+_100mV+_100mV
#define BASELINE_SETPOINT_UPPER_LIMIT_MAX		(BASELINE_SETPOINT +_500mV+_100mV)//1000
#define BASELINE_SETPOINT_UPPER_LIMIT_MID		(BASELINE_SETPOINT +_100mV+_100mV+_100mV)//500
#define BASELINE_SETPOINT_UPPER_LIMIT_MIN		(BASELINE_SETPOINT +_100mV)//50

#define BASELINE_SETPOINT_LOWER_LIMIT_MAX		(BASELINE_SETPOINT -_500mV-_100mV)//1000
#define BASELINE_SETPOINT_LOWER_LIMIT_MID		(BASELINE_SETPOINT -_100mV-_100mV-_100mV)//500
#define BASELINE_SETPOINT_LOWER_LIMIT_MIN		(BASELINE_SETPOINT -_100mV)//50

#define GRAPH_OFFSET _1000mV+_100mV+_100mV
#define TOLERANCE    _100mV

#define PWM_MAX_VALUE	FTM2_MODULO


#define PWM_LARGE_STEP	100//50
#define PWM_MID_STEP	50//10
#define PWM_SHORT_STEP	5 //1


#define IR_ON_TIME_us		50
#define IR_OFF_TIME_us		450

#define RED_ON_TIME_us		50
#define RED_OFF_TIME_us		450





/*************************************************************/

#define Pwm_Start(dutyCycle)	FTM2_CH1_PWM_Start(dutyCycle)
#define Pwm_Stop(PinValue)	FTM2_CH1_PWM_Stop(PinValue)

#define START_TIMER_us()			FTM1_Init()
#define STOP_TIMER_us()				FTM1_Deinit()


unsigned long gu16SpO2Offset=0;


/* States and substates */

/******************************************************************************
*                                 State Idle
******************************************************************************/

static void StateIdle(void)
{
	//do nothing
}


/******************************************************************************
*                              State Measuring
******************************************************************************/

static void StateMeasuring(void)
{
	UINT16 poxOutputSignalRaw, SpO2BaselineSignalRaw;
	
	/* read SPO2 signals: these are the steps:
		1. turn on IR LED
		2. wait 
		3. read baseline and read IR signal
		4. turn off IR LED (both LEDs off)
		5. wait 
		6. turn on Red LED
		7. wait 
		8. read Red signal
		9. turn off Red LED (both LEDs off)
		10. wait
	*/
	
	UINT16 elapsedTimeCopy = ElapsedTimeIn_us;

	switch (SpO2ActualSubStateSubState)
	{
		case 0:		
			SPO2_SET_SWITCH_CONTROL(SPO2_CONTROL_IR);	//set switch to select IR signals
			Pwm_Start(PwmIRValue);	//start pwm with IR value
			START_TIMER_us();	//start timer to wait 250us
			
		
			SpO2ActualSubStateSubState++;
			break;
			
		case 1:
			if (elapsedTimeCopy >= IR_ON_TIME_us)
			{			
				ElapsedTimeIn_us = 0;

				{
					poxOutputSignalRaw =   ADC1_Read12b(SPO2_ADC_CHANNEL_OUTPUT_SIGNAL);	//read IR baseline and IR signal
					SpO2BaselineSignalRaw = ADC0_Read12b(SPO2_ADC_CHANNEL_BASELINE_SIGNAL);
                                        
                                        #if (defined SPO2_FIR)
                                        poxOutputSignalRaw = u32SPO2_Filter(poxOutputSignalRaw,&gu16IR_Samples[0]);
                                        //SpO2BaselineSignalRaw = ADC0_Read12b(SPO2_ADC_CHANNEL_OUTPUT_SIGNAL); //Read IR Baseline
                                        SpO2BaselineSignalRaw = u32SPO2_BaselineFilter(SpO2BaselineSignalRaw, &gu16IR_Base[0]);//Remove AC
                                        #endif
									
					MovingAverage_PushNewValue16b(&SpO2IRBaselineSignal, SpO2BaselineSignalRaw);	//store IR baseline and IR signal
					MovingAverage_PushNewValue16b(&SpO2IRLedSignal, poxOutputSignalRaw);
				}				
				
				
				Pwm_Stop(0);		//turn off LEDs									
				SpO2ActualSubStateSubState++;
			}
			break;
	
		case 2:
			if (elapsedTimeCopy >= IR_OFF_TIME_us)
			{
				ElapsedTimeIn_us = 0;
//PTFD_PTFD2 = 1;

				SPO2_SET_SWITCH_CONTROL(SPO2_CONTROL_RED);	//set switch to select Red signal								
				Pwm_Start(PwmRedValue);	//start pwm for Red LED
				SpO2ActualSubStateSubState++;					
			}
			break;
			
		case 3:
			if (elapsedTimeCopy >= RED_ON_TIME_us)
			{				
				ElapsedTimeIn_us = 0;
//PTFD_PTFD2 = 0;				
				//if (IsTimeToUpdateGraphData)
				{					
					poxOutputSignalRaw = ADC1_Read12b(SPO2_ADC_CHANNEL_OUTPUT_SIGNAL);	//Read RED signal
					SpO2BaselineSignalRaw = ADC0_Read12b(SPO2_ADC_CHANNEL_BASELINE_SIGNAL);	//Read RED baseline				
                                        
                                        #if (defined SPO2_FIR)
                                        poxOutputSignalRaw = u32SPO2_Filter(poxOutputSignalRaw,&gu16R_Samples[0]);
                                        //SpO2BaselineSignalRaw = ADC0_Read12b(SPO2_ADC_CHANNEL_OUTPUT_SIGNAL);		//Read RED baseline
                                        SpO2BaselineSignalRaw = u32SPO2_BaselineFilter(SpO2BaselineSignalRaw, &gu16R_Base[0]);//Remove AC
                                        #endif
                                        
					MovingAverage_PushNewValue16b(&SpO2RedBaselineSignal, SpO2BaselineSignalRaw);	//store Red baseline and red signal
					MovingAverage_PushNewValue16b(&SpO2RedLedSignal, poxOutputSignalRaw);
				}

				Pwm_Stop(0);		//turn off LEDs
		
				SpO2ActualSubStateSubState++;
			}
			break;
			
		case 4:
			if (elapsedTimeCopy >= RED_OFF_TIME_us)
			{			
				ElapsedTimeIn_us = 0;
				SpO2ActualSubStateSubState = 0;				
				SpO2SamplesBetweenPulses++;
							
				if (IsTimeToUpdateGraphData && SpO2IsDiagnosticMode)
				{					
					IsTimeToUpdateGraphData = FALSE;										
					SaveGraphData();
					SwTimer_StartTimer(TimerSendGraphData, SPO2_UPDATE_GRAPH_PERIOD);
				}

				#define RECALIBRATE_TIME	512
									
				if (TimerToRecalibrate == 0)
				{
					static unsigned char toogle = 0;
					
					#define MAX_CALIBRATION_ATTEMPTS	128
					static UINT16 calibrationAttempts = 0;
														
					//check if both baselines are within the limits					
					if 	((SpO2IRBaselineSignal.Result > BASELINE_SETPOINT_UPPER_LIMIT_MIN)  || (SpO2IRBaselineSignal.Result < BASELINE_SETPOINT_LOWER_LIMIT_MIN) ||
						((SpO2RedBaselineSignal.Result > BASELINE_SETPOINT_UPPER_LIMIT_MIN) || (SpO2RedBaselineSignal.Result < BASELINE_SETPOINT_LOWER_LIMIT_MIN)))
					{

						if (toogle == SPO2_CONTROL_RED)
						{
							if ((SpO2RedBaselineSignal.Result > BASELINE_SETPOINT_UPPER_LIMIT_MID) || (SpO2RedBaselineSignal.Result < BASELINE_SETPOINT_LOWER_LIMIT_MID))
							{
								CalibrateRedLedIntensity();						
								TimerToRecalibrate = 16;
								
								//if (calibrationAttempts < 0xFF)
								{
									calibrationAttempts++;
								}
							}
							toogle = SPO2_CONTROL_IR;							
						}
						else if (toogle == SPO2_CONTROL_IR)
						{							
							if ((SpO2IRBaselineSignal.Result > BASELINE_SETPOINT_UPPER_LIMIT_MID)  || (SpO2IRBaselineSignal.Result < BASELINE_SETPOINT_LOWER_LIMIT_MID))
							{
								CalibrateIRLedIntensity();
								TimerToRecalibrate = 16;

								//if (calibrationAttempts < 0xFF)
								{
									calibrationAttempts++;
								}							
							}
							toogle = SPO2_CONTROL_RED;
						}
					}
					else
					{					
						TimerToRecalibrate = RECALIBRATE_TIME;
						calibrationAttempts = 0;
					}
									
				}
				else
				{
					TimerToRecalibrate--;					
				}
				
				
				//if (IsSignalStable)
				{
					FindMaxAndMin();
				}
				
				if ((SpO2ValidValue >= 10) && (!SpO2IsDiagnosticMode))
				{
					//generate pox ok event
					SpO2ActualEvent = SPO2_EVENT_MEASUREMENT_COMPLETE_OK;
					SpO2_AbortMeasurement();
				}
			}
			break;
	}
}





/******************************************************************************
*                            Calibrate RED LED
******************************************************************************/



static void CalibrateRedLedIntensity(void)
{
	//if signal is larger than setpoint
	if (SpO2RedBaselineSignal.Result > BASELINE_SETPOINT_UPPER_LIMIT_MAX)
	{
		if (PwmRedValue > PWM_LARGE_STEP)
		{
			//decrease offset by large steps
			PwmRedValue -= PWM_LARGE_STEP;			
		}
		else if (PwmRedValue > PWM_MID_STEP)
		{
			//decrease offset by large steps
			PwmRedValue -= PWM_MID_STEP;			
		}
		else if (PwmRedValue > PWM_SHORT_STEP)
		{
			//decrease offset by large steps
			PwmRedValue -= PWM_SHORT_STEP;			
		}
		//else PwmRedValue = PWM_MAX_VALUE;
	}
	else if (SpO2RedBaselineSignal.Result > BASELINE_SETPOINT_UPPER_LIMIT_MID)
	{
		//decrease offset by midium steps
		if (PwmRedValue > PWM_MID_STEP)
		{
			//decrease offset by large steps
			PwmRedValue -= PWM_MID_STEP;			
		}
		else if (PwmRedValue > PWM_SHORT_STEP)
		{
			//decrease offset by large steps
			PwmRedValue -= PWM_SHORT_STEP;			
		}		
	}
	else if (SpO2RedBaselineSignal.Result > BASELINE_SETPOINT_UPPER_LIMIT_MIN)
	{
		//decrease offset by short steps		
		if (PwmRedValue > PWM_SHORT_STEP)
		{
			//decrease offset by large steps
			PwmRedValue -= PWM_SHORT_STEP;			
		}
	}
	
	
	//if signal is lower than setpoint	
	
	else if (SpO2RedBaselineSignal.Result < BASELINE_SETPOINT_LOWER_LIMIT_MAX)
	{
		//increase offset by large steps
		if (PwmRedValue < (PWM_MAX_VALUE - PWM_LARGE_STEP))
		{
			//decrease offset by large steps
			PwmRedValue += PWM_LARGE_STEP;
		}	
		else if (PwmRedValue < (PWM_MAX_VALUE - PWM_MID_STEP))
		{
			//decrease offset by large steps
			PwmRedValue += PWM_MID_STEP;
		}
		else if (PwmRedValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
		{
			//decrease offset by large steps
			PwmRedValue += PWM_SHORT_STEP;			
		}
		//else PwmRedValue = 0;
		
	}
	else if (SpO2RedBaselineSignal.Result < BASELINE_SETPOINT_LOWER_LIMIT_MID)
	{
		//increase offset by medium steps
		if (PwmRedValue < (PWM_MAX_VALUE - PWM_MID_STEP))
		{
			//decrease offset by large steps
			PwmRedValue += PWM_MID_STEP;
		}	
		else if (PwmRedValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
		{
			//decrease offset by large steps
			PwmRedValue += PWM_SHORT_STEP;
		}	
	}
	else if (SpO2RedBaselineSignal.Result < BASELINE_SETPOINT_LOWER_LIMIT_MIN)
	{
		//increase offset by short steps		
		if (PwmRedValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
		{
			//decrease offset by large steps
			PwmRedValue += PWM_SHORT_STEP;
		}
	}	
}

/******************************************************************************
*                              Calibrate IR LED
******************************************************************************/
	
static void CalibrateIRLedIntensity(void)
{
	//if signal is larger than setpoint
	if (SpO2IRBaselineSignal.Result > BASELINE_SETPOINT_UPPER_LIMIT_MAX)
	{
		if (PwmIRValue > PWM_LARGE_STEP)
		{
			//decrease offset by large steps
			PwmIRValue -= PWM_LARGE_STEP;			
		}
		else if (PwmIRValue > PWM_MID_STEP)
		{
			//decrease offset by large steps
			PwmIRValue -= PWM_MID_STEP;			
		}
		else if (PwmIRValue > PWM_SHORT_STEP)
		{
			//decrease offset by large steps
			PwmIRValue -= PWM_SHORT_STEP;			
		}
		//else PwmIRValue = PWM_MAX_VALUE;
	}
	else if (SpO2IRBaselineSignal.Result > BASELINE_SETPOINT_UPPER_LIMIT_MID)
	{
		//decrease offset by midium steps
		if (PwmIRValue > PWM_MID_STEP)
		{
			//decrease offset by large steps
			PwmIRValue -= PWM_MID_STEP;			
		}
		else if (PwmIRValue > PWM_SHORT_STEP)
		{
			//decrease offset by large steps
			PwmIRValue -= PWM_SHORT_STEP;			
		}		
	}
	else if (SpO2IRBaselineSignal.Result > BASELINE_SETPOINT_UPPER_LIMIT_MIN)
	{
		//decrease offset by short steps		
		if (PwmIRValue > PWM_SHORT_STEP)
		{
			//decrease offset by large steps
			PwmIRValue -= PWM_SHORT_STEP;			
		}
	}
	
	
	//if signal is lower than setpoint	
	
	else if (SpO2IRBaselineSignal.Result < BASELINE_SETPOINT_LOWER_LIMIT_MAX)
	{
		//increase offset by large steps
		if (PwmIRValue < (PWM_MAX_VALUE - PWM_LARGE_STEP))
		{
			//decrease offset by large steps
			PwmIRValue += PWM_LARGE_STEP;
		}
		else if (PwmIRValue < (PWM_MAX_VALUE - PWM_MID_STEP))
		{
			//decrease offset by large steps
			PwmIRValue += PWM_MID_STEP;
		}
		else if (PwmIRValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
		{
			//decrease offset by large steps
			PwmIRValue += PWM_SHORT_STEP;
		}
		//else PwmIRValue = 0;
	}
	else if (SpO2IRBaselineSignal.Result < BASELINE_SETPOINT_LOWER_LIMIT_MID)
	{
		//increase offset by medium steps
		if (PwmIRValue < (PWM_MAX_VALUE - PWM_MID_STEP))
		{
			//decrease offset by large steps
			PwmIRValue += PWM_MID_STEP;
		}
		else if (PwmIRValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
		{
			//decrease offset by large steps
			PwmIRValue += PWM_SHORT_STEP;
		}	
	}
	else if (SpO2IRBaselineSignal.Result < BASELINE_SETPOINT_LOWER_LIMIT_MIN)
	{
		//increase offset by short steps		
		if (PwmIRValue < (PWM_MAX_VALUE - PWM_SHORT_STEP))
		{
			//decrease offset by large steps
			PwmIRValue += PWM_SHORT_STEP;
		}
	}		
}


typedef enum
{
	
	SPO2_SUBSTATE_FINDING_MAX,
	SPO2_SUBSTATE_FINDING_MIN
}SPO2_SUBSTATES; //@TEST


//the max freq we want to detect is 4Hz (250ms) (a person with tachicardia)
//we are sampling signal every 1ms so the comparation window must be 250 samples (250ms)

#define COMPARATION_WINDOW_INTERVAL		250			//samples between max and min


//TO DO: Add watchdog timer

UINT8 maxCounter = 0;
UINT8 minCounter = 0;
UINT16 IRPeakToPeakVoltage = 0;
UINT16 RedPeakToPeakVoltage = 0;
UINT16 IrRms = 0;
UINT16 RedRms = 0;

//0, 301, 602, 778, 903, 1000, 1079, 1146, 1204, 1255, 1301, 1342, 1380, 1414, 1447, 1477, 1505, 1531, 1556, 1579, 1602, 1623, 1643, 1662, 1681, 1698, 1716, 1732, 1748, 1763, 1778, 1792, 1806, 1819, 1832, 1845, 1857, 1869, 1880, 1892, 1903, 1913, 1924, 1934, 1944, 1954, 1963, 1973, 1982, 1991, 2000, 2008, 2017, 2025, 2033, 2041, 2049, 2056, 2064, 2071, 2079, 2086, 2093, 2100, 2107, 2113, 2120, 2127, 2133, 2139, 2146, 2152, 2158, 2164, 2170, 2176, 2181, 2187, 2193, 2198, 2204, 2209, 2214, 2220, 2225, 2230, 2235, 2240, 2245, 2250, 2255, 2260, 2264, 2269, 2274, 2278, 2283, 2287, 2292, 2296, 2301, 2305, 2309, 2313, 2318, 2322, 2326, 2330, 2334, 2338, 2342, 2346, 2350, 2354, 2357, 2361, 2365, 2369, 2372, 2376, 2380, 2383, 2387, 2390, 2394, 2397, 2401, 2404, 2408, 2411, 2414, 2418, 2421, 2424, 2428, 2431, 2434, 2437, 2440, 2444, 2447, 2450, 2453, 2456, 2459, 2462, 2465, 2468, 2471, 2474, 2477, 2480, 2482, 2485, 2488, 2491, 2494, 2496, 2499, 2502, 2505, 2507, 2510, 2513, 2515, 2518, 2521, 2523, 2526, 2528, 2531, 2534, 2536, 2539, 2541, 2544, 2546, 2549, 2551, 2553, 2556, 2558, 2561, 2563, 2565, 2568, 2570, 2572, 2575, 2577, 2579, 2582, 2584, 2586, 2588, 2591, 2593, 2595, 2597, 2599, 2602, 2604, 2606, 2608, 2610, 2612, 2614, 2617, 2619, 2621, 2623, 2625, 2627, 2629, 2631, 2633, 2635, 2637, 2639, 2641, 2643, 2645, 2647, 2649, 2651, 2653, 2655, 2657, 2658, 2660, 2662, 2664, 2666, 2668, 2670, 2672, 2673, 2675, 2677, 2679, 2681, 2683, 2684, 2686, 2688, 2690, 2691, 2693, 2695, 2697, 2698, 2700, 2702, 2704, 2705, 2707, 2709, 2710, 2712, 2714, 2716, 2717, 2719, 2720, 2722, 2724, 2725, 2727, 2729, 2730, 2732, 2733, 2735, 2737, 2738, 2740, 2741, 2743, 2745, 2746, 2748, 2749, 2751, 2752, 2754, 2755, 2757, 2758, 2760, 2761, 2763, 2764, 2766, 2767, 2769, 2770, 2772, 2773, 2775, 2776, 2778, 2779, 2781, 2782, 2783, 2785, 2786, 2788, 2789, 2790, 2792, 2793, 2795, 2796, 2797, 2799, 2800, 2802, 2803, 2804, 2806, 2807, 2808, 2810, 2811, 2812, 2814, 2815, 2816, 2818, 2819, 2820, 2822, 2823, 2824, 2826, 2827, 2828, 2829, 2831, 2832, 2833, 2835, 2836, 2837, 2838, 2840, 2841, 2842, 2843, 2845, 2846, 2847, 2848, 2850, 2851, 2852, 2853, 2854, 2856, 2857, 2858, 2859, 2860, 2862, 2863, 2864, 2865, 2866, 2868, 2869, 2870, 2871, 2872, 2873, 2875, 2876, 2877, 2878, 2879, 2880, 2881, 2883, 2884, 2885, 2886, 2887, 2888, 2889, 2890, 2892, 2893, 2894, 2895, 2896, 2897, 2898, 2899, 2900, 2902, 2903, 2904, 2905, 2906, 2907, 2908, 2909, 2910, 2911, 2912, 2913, 2914, 2915, 2916, 2918, 2919, 2920, 2921, 2922, 2923, 2924, 2925, 2926, 2927, 2928, 2929, 2930, 2931, 2932, 2933, 2934, 2935, 2936, 2937, 2938, 2939, 2940, 2941, 2942, 2943, 2944, 2945, 2946, 2947, 2948, 2949, 2950, 2951, 2952, 2953, 2954, 2955, 2956, 2957, 2958, 2959, 2959, 2960, 2961, 2962, 2963, 2964, 2965, 2966, 2967, 2968, 2969, 2970, 2971, 2972, 2973, 2974, 2974, 2975, 2976, 2977, 2978, 2979, 2980, 2981, 2982, 2983, 2984, 2984, 2985, 2986, 2987, 2988, 2989, 2990, 2991, 2992, 2992, 2993, 2994, 2995, 2996, 2997, 2998, 2999, 3000, 3000, 3001, 3002, 3003, 3004, 3005, 3006, 3006, 3007, 3008, 3009


const UINT16 Log10LookUpTable[] = 
{
 0, 301, 602, 778, 903, 1000, 1079, 1146, 1204, 1255, 1301, 1342, 1380, 1414, 1447, 1477, 1505, 1531, 1556, 1579, 1602, 1623, 1643, 1662, 1681, 1698, 1716, 1732, 1748, 1763, 1778, 1792, 1806, 1819, 1832, 1845, 1857, 1869, 1880, 1892, 1903, 1913, 1924, 1934, 1944, 1954, 1963, 1973, 1982, 1991, 2000, 2008, 2017, 2025, 2033, 2041, 2049, 2056, 2064, 2071, 2079, 2086, 2093, 2100, 2107, 2113, 2120, 2127, 2133, 2139, 2146, 2152, 2158, 2164, 2170, 2176, 2181, 2187, 2193, 2198, 2204, 2209, 2214, 2220, 2225, 2230, 2235, 2240, 2245, 2250, 2255, 2260, 2264, 2269, 2274, 2278, 2283, 2287, 2292, 2296, 2301, 2305, 2309, 2313, 2318, 2322, 2326, 2330, 2334, 2338, 2342, 2346, 2350, 2354, 2357, 2361, 2365, 2369, 2372, 2376, 2380, 2383, 2387, 2390, 2394, 2397, 2401, 2404, 2408, 2411, 2414, 2418, 2421, 2424, 2428, 2431, 2434, 2437, 2440, 2444, 2447, 2450, 2453, 2456, 2459, 2462, 2465, 2468, 2471, 2474, 2477, 2480, 2482, 2485, 2488, 2491, 2494, 2496, 2499, 2502, 2505, 2507, 2510, 2513, 2515, 2518, 2521, 2523, 2526, 2528, 2531, 2534, 2536, 2539, 2541, 2544, 2546, 2549, 2551, 2553, 2556, 2558, 2561, 2563, 2565, 2568, 2570, 2572, 2575, 2577, 2579, 2582, 2584, 2586, 2588, 2591, 2593, 2595, 2597, 2599, 2602, 2604, 2606, 2608, 2610, 2612, 2614, 2617, 2619, 2621, 2623, 2625, 2627, 2629, 2631, 2633, 2635, 2637, 2639, 2641, 2643, 2645, 2647, 2649, 2651, 2653, 2655, 2657, 2658, 2660, 2662, 2664, 2666, 2668, 2670, 2672, 2673, 2675, 2677, 2679, 2681, 2683, 2684, 2686, 2688, 2690, 2691, 2693, 2695, 2697, 2698, 2700, 2702, 2704, 2705, 2707, 2709, 2710, 2712, 2714, 2716, 2717, 2719, 2720, 2722, 2724, 2725, 2727, 2729, 2730, 2732, 2733, 2735, 2737, 2738, 2740, 2741, 2743, 2745, 2746, 2748, 2749, 2751, 2752, 2754, 2755, 2757, 2758, 2760, 2761, 2763, 2764, 2766, 2767, 2769, 2770, 2772, 2773, 2775, 2776, 2778, 2779, 2781, 2782, 2783, 2785, 2786, 2788, 2789, 2790, 2792, 2793, 2795, 2796, 2797, 2799, 2800, 2802, 2803, 2804, 2806, 2807, 2808, 2810, 2811, 2812, 2814, 2815, 2816, 2818, 2819, 2820, 2822, 2823, 2824, 2826, 2827, 2828, 2829, 2831, 2832, 2833, 2835, 2836, 2837, 2838, 2840, 2841, 2842, 2843, 2845, 2846, 2847, 2848, 2850, 2851, 2852, 2853, 2854, 2856, 2857, 2858, 2859, 2860, 2862, 2863, 2864, 2865, 2866, 2868, 2869, 2870, 2871, 2872, 2873, 2875, 2876, 2877, 2878, 2879, 2880, 2881, 2883, 2884, 2885, 2886, 2887, 2888, 2889, 2890, 2892, 2893, 2894, 2895, 2896, 2897, 2898, 2899, 2900, 2902, 2903, 2904, 2905, 2906, 2907, 2908, 2909, 2910, 2911, 2912, 2913, 2914, 2915, 2916, 2918, 2919, 2920, 2921, 2922, 2923, 2924, 2925, 2926, 2927, 2928, 2929, 2930, 2931, 2932, 2933, 2934, 2935, 2936, 2937, 2938, 2939, 2940, 2941, 2942, 2943, 2944, 2945, 2946, 2947, 2948, 2949, 2950, 2951, 2952, 2953, 2954, 2955, 2956, 2957, 2958, 2959, 2959, 2960, 2961, 2962, 2963, 2964, 2965, 2966, 2967, 2968, 2969, 2970, 2971, 2972, 2973, 2974, 2974, 2975, 2976, 2977, 2978, 2979, 2980, 2981, 2982, 2983, 2984, 2984, 2985, 2986, 2987, 2988, 2989, 2990, 2991, 2992, 2992, 2993, 2994, 2995, 2996, 2997, 2998, 2999, 3000, 3000, 3001, 3002, 3003, 3004, 3005, 3006, 3006, 3007, 3008, 3009
};

const UINT8 RatioLookUp [] =
{
 100,100,100,100,100,100,99 ,97 ,90 ,86 ,82,74,66 ,58 ,50 ,41 ,33 ,25 ,17 ,9 ,0 
};

/******************************************************************************
*                             Find MAX and MIN
******************************************************************************/


static void FindMaxAndMin(void)
{
	static UINT16 comparationWindowTimer;
	static UINT8 subStateFindingMaxAndMin;
		
	
	if (subStateFindingMaxAndMin == SPO2_SUBSTATE_FINDING_MAX)
	{
		//if the SpO2 signal is going up
		if (SpO2IRLedSignal.Result > SpO2IRMax)
		{
			SpO2IRMax = SpO2IRLedSignal.Result;							//store new max values
			SpO2RedMax = SpO2RedLedSignal.Result;
			
			comparationWindowTimer = COMPARATION_WINDOW_INTERVAL;		//restart counter				
		}
		else
		{	
			//slope changed, now signal is going down
			comparationWindowTimer--;
			
			if (comparationWindowTimer == 0)
			{
				//no more max peaks detected in the window time, go to detection of min
				subStateFindingMaxAndMin = SPO2_SUBSTATE_FINDING_MIN;
				maxCounter++;
				SpO2IRMin = SpO2IRMax;
				SpO2RedMin = SpO2RedMax;
			}
		}
	}
	else if (subStateFindingMaxAndMin == SPO2_SUBSTATE_FINDING_MIN)
	{
		//if the SpO2 signal is going down
		if (SpO2IRLedSignal.Result < SpO2IRMin)
		{
			SpO2IRMin = SpO2IRLedSignal.Result;							//store new min values
			SpO2RedMin = SpO2RedLedSignal.Result;
			comparationWindowTimer = COMPARATION_WINDOW_INTERVAL;		//restart counter
		}
		else
		{	
			//slope changed, now signal is going up
			comparationWindowTimer--;
			
			if (comparationWindowTimer == 0)
			{
				//no more min peaks detected in the window time, go to next state
				subStateFindingMaxAndMin = SPO2_SUBSTATE_FINDING_MAX;					
				minCounter++;
                                
                                gu16SpO2Offset = SpO2IRMin;

				DoCalculations();		//do calculations before updating min and max values
				
				SpO2IRMax = SpO2IRMin;
				SpO2RedMax = SpO2RedMin;
				SpO2_HeartBeatDetected = TRUE;				
			}
		}
	}
}

/******************************************************************************
*                               Do Calculations
******************************************************************************/

static void DoCalculations(void)
{
	UINT8 poxInstantaneousHeartRate;
	UINT8 poxInstantaneousSpO2;
	UINT8 i=0;
	
	UINT32 numerator;
	UINT16 lookUpTableIndex = 0;
        
        /* Freescale Algorithm Variables */
        //UINT32 u32RedIrRatio; //@TEST
	
	
	IRPeakToPeakVoltage = SpO2IRMax - SpO2IRMin;		//calculate peak to peak voltage
	RedPeakToPeakVoltage = SpO2RedMax - SpO2RedMin;
	
	if (IRPeakToPeakVoltage < 2000 && RedPeakToPeakVoltage < 2000)
	{
		//calculate Vrms = 0.5*Vpp/sqrt(2)
		numerator = (UINT32)((UINT32)IRPeakToPeakVoltage * 707);
		IrRms = (UINT16)((UINT32)(numerator)/(UINT32)(2*1000));
		
		numerator = (UINT32)((UINT32)RedPeakToPeakVoltage * 707);
		RedRms = (UINT16)((UINT32)(numerator)/(UINT32)(2*1000));
		
		if (RedRms < 1024 && IrRms < 1024)
		{			
	
                        lookUpTableIndex = (UINT16)(RedRms/2);
			numerator = (UINT32)((UINT32)Log10LookUpTable[lookUpTableIndex]*(UINT32)100);
			
			lookUpTableIndex = (UINT16)(IrRms/2);

			poxInstantaneousSpO2 = (UINT8) ((UINT32)(numerator)/(UINT32)Log10LookUpTable[lookUpTableIndex]);
			//poxInstantaneousSpO2 = RatioLookUp[poxInstantaneousSpO2];
                  
                  
			if (poxInstantaneousSpO2 > 100)
			{
				poxInstantaneousSpO2 = 100;
			}
			
			//Calculate instantaneous HR //60000
			poxInstantaneousHeartRate = (UINT8) (60000 / (SpO2SamplesBetweenPulses));// * SPO2_SAMPLING_PERIOD));
			
			//Shift samples of FIFO	
			for (i=OLDEST_ELEMENT; i>NEWEST_ELEMENT; i--)
			{
				SpO2HeartRateArray[i] = SpO2HeartRateArray[i-1];	
				SpO2SpO2Array[i] = SpO2SpO2Array[i-1];
			}
			
			//insert new sample into FIFO
			SpO2HeartRateArray[NEWEST_ELEMENT] = poxInstantaneousHeartRate;
			SpO2SpO2Array[NEWEST_ELEMENT] = poxInstantaneousSpO2;				
					
			CalculateHeartRateAndSpO2();		//calculate average of medians
			
			SpO2SamplesBetweenPulses = 0;		//Restart samples counter 									
		}
                
		else
		{
			SpO2_HeartRate = 0;
			SpO2_SaturationValue = 0;
		}
	
	}
	else
	{
		SpO2_HeartRate = 0;
		SpO2_SaturationValue = 0;
	}
	
}

/******************************************************************************
*                          Calculate HR and SpO2
******************************************************************************/

static void CalculateHeartRateAndSpO2(void)
//order HearRate values in array and average samples in the middle		
{
	UINT8 startIndex;
	UINT8 smallestIndex;
	UINT8 currentIndex;
	UINT8 tempStoreValue;
	UINT16 sum;
	UINT8 i;
	
	//Create a copy of the arrays
	for (i=0; i<SPO2_ARRAY_LENGTH; i++)
	{
		CopyOfSpO2HeartRateArray[i] = SpO2HeartRateArray[i];		
		CopyOfSpO2SpO2Array[i] = SpO2SpO2Array[i];
	}
	
	// Order array values in ascending order 
	for (startIndex = 0; startIndex < SPO2_ARRAY_LENGTH; startIndex++)
	{
		smallestIndex = startIndex;

		for (currentIndex = startIndex + 1; currentIndex < SPO2_ARRAY_LENGTH; currentIndex++)
		{
			if (CopyOfSpO2HeartRateArray[currentIndex] < CopyOfSpO2HeartRateArray[smallestIndex])
			{
				smallestIndex = currentIndex;
			}
		}

		tempStoreValue = (UINT8) CopyOfSpO2HeartRateArray[startIndex];

		CopyOfSpO2HeartRateArray[startIndex] = CopyOfSpO2HeartRateArray[smallestIndex];
		CopyOfSpO2HeartRateArray[smallestIndex] = tempStoreValue;
	}						
	
	// Calculate HR averaging values from 2-5 (avoids using false HR values)
	//
	//	 		 	                  		  [0,1,2,3,4,5,6,7] 
	//										   | |         | |
	//										   | |         | |
	//									remove - -         - -
	
	sum = 0;
	
	for (i = 2; i < 6; i++)
	{
		sum += CopyOfSpO2HeartRateArray[i];
	}

	SpO2_HeartRate = (UINT8)(sum / 4);
	
	
	//Same procedure, but with SpO2 array
	
	
	// Order array values in ascending order 
	for (startIndex = 0; startIndex < SPO2_ARRAY_LENGTH; startIndex++)
	{
		smallestIndex = startIndex;

		for (currentIndex = startIndex + 1; currentIndex < SPO2_ARRAY_LENGTH; currentIndex++)
		{
			if (CopyOfSpO2SpO2Array[currentIndex] < CopyOfSpO2SpO2Array[smallestIndex])
			{
				smallestIndex = currentIndex;
			}
		}

		tempStoreValue = (UINT8) CopyOfSpO2SpO2Array[startIndex];

		CopyOfSpO2SpO2Array[startIndex] = CopyOfSpO2SpO2Array[smallestIndex];
		CopyOfSpO2SpO2Array[smallestIndex] = tempStoreValue;
	}						
	
	// Calculate SpO2 averaging values from 2-5 (avoids using false values)
	//
	//	 		 	                  		  [0,1,2,3,4,5,6,7] 
	//										   | |         | |
	//										   | |         | |
	//									remove - -         - -
	
	sum = 0;
	
	for (i = 2; i < 6; i++)
	{
		sum += CopyOfSpO2SpO2Array[i];
	}

	SpO2_SaturationValue = (UINT8)(sum / 4);
	
	SpO2ValidValue++;
	
}

/******************************************************************************
*                                 Reset Variables
******************************************************************************/

static void ResetVariables(void)
{
	UINT8 i = 0;
	
	//Reset variables
	SpO2IRMax = 0;
	SpO2IRMin = 4096;
	
	SpO2RedMax = 0;
	SpO2RedMin = 4096;

	SpO2SamplesBetweenPulses = 0;
	
	PwmRedValue = INITIAL_PWM_PERCENTAGE;
	PwmIRValue = INITIAL_PWM_PERCENTAGE;
	
	SpO2ValidValue = 0;
		
	SpO2ActualSubStateSubState = 0;	
		
	IsTimeToUpdateGraphData = FALSE;	
	ElapsedTimeIn_us = 0;		
	TimerToRecalibrate = 0;
	

	//clean arrays
	for (i=0; i<SPO2_ARRAY_LENGTH; i++)
	{
		CopyOfSpO2HeartRateArray[i] = 0;
		CopyOfSpO2SpO2Array[i] = 0;
		
		SpO2HeartRateArray[i] = 0;
		SpO2SpO2Array[i] = 0;
	}
        
        //clean filter buffers
#ifdef SPO2_FIR
      vfnCleanBuffer(&gu16IR_Samples[0],SPO2_FILTER_ORDER);
      vfnCleanBuffer(&gu16R_Samples[0],SPO2_FILTER_ORDER);
      vfnCleanBuffer(&gu16IR_Base[0],SPO2_BASELINE_FILTER_ORDER);
      vfnCleanBuffer(&gu16R_Base[0],SPO2_BASELINE_FILTER_ORDER);
#endif
}


#define ZERO_VALUE		2024

#ifdef SPO2_DEBUG
static void SaveGraphData(void)
{
	//store data and send it when the buffer is full
	if (SpO2GraphActualPosition < SPO2_REAL_TIME_DATA_ARRAY_LENGTH)
	{
		//if(IsSignalStable)
		{			
			//send SpO2Signal
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(SpO2IRLedSignal.Result >> 8); 		//higher byte
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(SpO2IRLedSignal.Result & 0x00FF); 	//lower byte
			
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(SpO2RedLedSignal.Result >> 8); 		//higher byte
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(SpO2RedLedSignal.Result & 0x00FF); 	//lower byte
		}
		/*else
		{
			//send SpO2Signal
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(ZERO_VALUE >> 8); 		//higher byte
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(ZERO_VALUE & 0x00FF); 	//lower byte
			
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(ZERO_VALUE >> 8); 		//higher byte
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(ZERO_VALUE & 0x00FF); 	//lower byte
			
		}*/
	}
	else
	{
		//buffer is full, call the data ready event
		//SpO2ActualEvent = SPO2_EVENT_NEW_DATA_READY;
		SpO2ActualEvent = SPO2_EVENT_DEBUG_MODE_NEW_DATA_READY;
		SpO2GraphActualPosition = 0;
	}
}

#else



#define AMPLIFY_SIGNAL
#define AMPLIFICATION_FACTOR		1	//scale factor (ideally should be power of two)

static void SaveGraphData(void)
{	
	//store data and send it when the buffer is full
	if (SpO2GraphActualPosition < SPO2_REAL_TIME_DATA_ARRAY_LENGTH)
	{
		//if(IsSignalStable)
		{			
			//send SpO2Signal
			#ifdef AMPLIFY_SIGNAL
                  
			INT16 dataToSend = 0;
			UINT16 dataSigned = 0;
   
			dataToSend = (INT16)(SpO2IRLedSignal.Result - 2047);
                        dataToSend = dataToSend*AMPLIFICATION_FACTOR;			
			
                        dataToSend += 2047;

                        //dataToSend = (INT16)(SpO2RedBaselineSignal.Result -2047);//Test pusposes only
                        
			
			if (dataToSend > 4095)
			{
				dataToSend = 4095;
			}
			else if (dataToSend < 0)
			{
				dataToSend = 0;
			}
                        
			dataSigned = (UINT16)(dataToSend);

                       #ifdef SPO2_FIR
                        dataSigned = SpO2IRLedSignal.Result - SpO2IRBaselineSignal.Result; //Remove actual Level
                        dataSigned *= AMPLIFICATION_FACTOR;
                        dataSigned += GRAPH_OFFSET; //Add 1.2V offset for graph	
                       #endif                   
                        
                        
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(dataSigned >> 8); 		//higher byte
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(dataSigned & 0x00FF); 	//lower byte
			
			#else
                        SpO2IRLedSignal.Result -= SpO2IRBaselineSignal.Result; //Remove actual Level
                        SpO2IRLedSignal.Result += GRAPH_OFFSET; //Add 1.2V offset for graph

		
                        SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(SpO2IRLedSignal.Result >> 8); 		//higher byte
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(SpO2IRLedSignal.Result & 0x00FF); 	//lower byte
                    
                        SpO2IRLedSignal.Result -= GRAPH_OFFSET; //Return it to it's original state
                        SpO2IRLedSignal.Result += gu16SpO2Offset;
                        
			#endif
		}/*
		else
		{
			//send SpO2Signal
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(ZERO_VALUE >> 8); 		//higher byte
			SpO2Graph[SpO2GraphActualPosition++] = (UINT8)(ZERO_VALUE & 0x00FF); 	//lower byte						
		}*/
	}
	else
	{
		//buffer is full, call the data ready event
		SpO2ActualEvent = SPO2_EVENT_NEW_DATA_READY;		
		SpO2GraphActualPosition = 0;
	}
}
#endif

static void TimerSendGraphData_Event(void)
{
	IsTimeToUpdateGraphData = TRUE;
}



void SpO2_Init(void)
{
	SPO2_INIT_SWITCH_CONTROL_PIN();		//Init GPIOs
	TimerSendGraphData = SwTimer_CreateTimer(TimerSendGraphData_Event);	//create timer
	FTM1_Init();
	FTM2_Init();
        FTM2_CH1_PWM_Stop(0);
}


void SpO2_PeriodicTask(void)
{
	/* State machine handler */
	SpO2StateMachine[SpO2ActualState]();

	/* Event handler */
	if (SpO2ActualEvent != SPO2_EVENT_NONE)
	{
		if (SpO2_Events[SpO2ActualEvent] != NULL)
		{
			SpO2_Events[SpO2ActualEvent]();	//execute registered event
			SpO2ActualEvent = SPO2_EVENT_NONE;
		}
	}
	
}


UINT8 SpO2_StartMeasurement(void)
{
	UINT8 status = FALSE;

	if (SpO2ActualState == SPO2_STATE_IDLE)
	{
		ADC0_Init12b();
                ADC1_Init12b();


		SpO2IsDiagnosticMode = FALSE;
		SpO2ActualState = SPO2_STATE_MEASURING;
		ResetVariables();		
	
		SwTimer_StartTimer(TimerSendGraphData, SPO2_UPDATE_GRAPH_PERIOD);	//start timer to sample ADC
		status = TRUE;			
	}
	else
	{
		status = FALSE;
	}

	return status;	
}


void SpO2_AbortMeasurement(void)
{
	SpO2ActualState = SPO2_STATE_IDLE;
	SwTimer_StopTimer(TimerSendGraphData);
	
	STOP_TIMER_us();				
	Pwm_Stop(0);		//turn off LEDs
}


UINT8 SpO2_DiagnosticModeStartMeasurement(void)
{
	UINT8 status = FALSE;

	if (SpO2ActualState == SPO2_STATE_IDLE)
	{
		ADC0_Init12b();
                ADC1_Init12b();


		SpO2IsDiagnosticMode = TRUE;
		SpO2ActualState = SPO2_STATE_MEASURING;
		ResetVariables();		
	
		SwTimer_StartTimer(TimerSendGraphData, SPO2_UPDATE_GRAPH_PERIOD);	//start timer to sample ADC
		status = TRUE;
		
	}
	else
	{
		status = FALSE;
	}

	return status;
}


void SpO2_DiagnosticModeStopMeasurement(void)
{
	SpO2_AbortMeasurement();
}

void SpO2_Set_Switch_Control (UINT8 Control)
{
 if(Control)
 SPO2_PIN_OUT_REG |= (1<<SPO2_PIN);
 
 if(!Control)
 SPO2_PIN_COR_REG |= (1<<SPO2_PIN);

}

void vfnCleanBuffer (unsigned long *pu16BufferToClean, unsigned long u16BufferSize)
{
 unsigned char u8Counter;
   
   for(u8Counter=0;u8Counter<u16BufferSize;u8Counter++)
   {
    *pu16BufferToClean=0;
    pu16BufferToClean++;
   }
}