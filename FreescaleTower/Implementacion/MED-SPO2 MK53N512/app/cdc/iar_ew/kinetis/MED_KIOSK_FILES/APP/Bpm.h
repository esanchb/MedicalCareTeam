#ifndef _BLOOD_PRESSURE_MONITOR
#define _BLOOD_PRESSURE_MONITOR


#include "derivative.h" /* include peripheral declarations */
#include "PublicTypes.h"
#include "ADC.h"
#include "AverageFilter.h"
#include "SwTimer.h"


/** ADC sampling period in ms */
#define BPM_SAMPLING_PERIOD				10	//in ms

/** ADC channel for pressure sensor output */
#define	ADC_CHANNEL_PRESSURE_SIGNAL		8	//ADC channel number

/** ADC channel for heart beat signal */
#define	ADC_CHANNEL_HEART_BEAT_SIGNAL	0

/** Pin for driving the motor */
#define BPM_MOTOR_PIN		asm ("NOP")//PTDD_PTDD4  Change this pins

/** Data directon for motor pin */
#define BPM_MOTOR_DD_PIN	asm ("NOP")//PTDDD_PTDDD4

/** Pin for driving the valve */
#define BPM_VALVE_PIN		asm ("NOP")//PTDD_PTDD5			//pin that controls valve

/** Data direction for valve */
#define BPM_VALVE_DD_PIN	asm ("NOP")//PTDDD_PTDDD5

#define BPM_CLOSE_VALVE()	asm ("NOP")//BPM_VALVE_PIN = 1
#define BPM_OPEN_VALVE()	asm ("NOP")//BPM_VALVE_PIN = 0

#define BPM_START_MOTOR()	asm ("NOP")//BPM_MOTOR_PIN = 0
#define BPM_STOP_MOTOR()	asm ("NOP")//BPM_MOTOR_PIN = 1


/** Buffer size for storing the real-time data */
#define BPM_BUFFER_SIZE						16

#define _70_PERCENT		7
#define _50_PERCENT		5

/* !!!!! Need to change this to mmHg units, currently it is ADC samples units */

/** The BPM will inflate until this pressure value is reached */
#define INITIAL_MAX_PRESSURE_VALUE 		1900
#define LARGE_PULSE_THRESHOLD	 		500		//larger than small pulse threshold
#define SMALL_PULSE_THRESHOLD	 		400		//it was 800 before

#define BPM_MINUMUM_TIME_BETWEEN_POINTS 30

/** In leak test mode, the device will inflate until this pressure is reached */
#define LEAK_TEST_MAX_PRESSURE_VALUE	1600

//if the pressure doesn't reach MAYOR_LEAK_PRESSURE_THRESHOLD ADC counts in MAYOR_LEAK_TIMEOUT ms, there is a mayor leakage
#define	LEAK_TEST_PARTIALLY_INFLATED_TIMEOUT	10000 //ms
#define MAYOR_LEAK_PRESSURE_THRESHOLD			250  //ADC counts


//once inflated, this is the time that the pressure must be mantained
#define	LEAK_TEST_TOTALLY_INFLATED_TIMEOUT			10000 //ms

//after inflated, if the pressure goes down to x ADC, there is a minor leakage
#define MINOR_LEAK_PRESSURE_THRESHOLD		1400  //ADC counts

//after inflated, if the pressure goes down to x ADC, there is a leakage
#define NO_LEAK_PRESSURE_THRESHOLD		1500  //ADC counts




//comparation window size = max sampling period / sampling period
#define BPM_COMPARATION_WINDOW_SIZE			10	

/** Peak slope must be greater thant this, in order to be detected as a pulse */
#define BPM_MINIMUM_AMPLITUDE  50

#define BPM_MINIMUM_PRESSURE  550	//this corresponds to 40mmHg

/** The BPM will be deaf during this time at the beginning to avoid false peaks */
#define BPM_INITIAL_DELAY		1500   //Number of samples. Sampling perdiod = 10 ms, therefore delay = 10 seconds

/** Number of elements in the array to save the envelope and presure values */
#define BPM_ARRAY_LENGTH		255


#define ADITIONAL_INFLATE_PRESSURE		120		//pressure in adc counts


#define MAX_PRESSURE_VALUE				2130		//200 mmHg

#define SAMPLES_TO_IGNORE_AT_START		50		//50 samples * 10ms = 500 ms ignored at start


#define TURN_OFF_BPM_TIME			8000	//ms	 leave the valve open after measuring


//#define BPM_DEBUG	

/** Stores the heart rate value in beats per minute (not implemented right now */
extern UINT16 Bpm_HeartRate;

/** Stores the systolic pressure in mmHg */
extern UINT8 Bpm_SystolicPressure;

/** Stores the diastolic pressure in mmHg */
extern UINT8 Bpm_DiastolicPressure;

/** Stores the Mean Arterial Pressure in mmHg */
extern UINT8 Bpm_MeanArterialPressure;

/** Stores the leak test result */
extern UINT8 Bpm_LeakTestResult;

/** Stores the error code of the measurement */
extern UINT8 Bpm_ErrorCode;

/** Stores the actual pressure value in mmHg */
extern UINT8 Bpm_ActualPressureValue;

extern UINT8 Bpm_HearBeatDetected;

#ifdef BPM_DEBUG
extern UINT8 Bpm_GraphData[BPM_BUFFER_SIZE];
#endif

/** Task that must be called periodically in tha main loop */
void  Bpm_PeriodicTask(void);

/** Starts a Bpm measurement 
	\returns TRUE if success, FALSE if already running */
UINT8 Bpm_StartMeasurement(void);

/** Stops a Bpm measurement */
void  Bpm_AbortMeasurement(void);

/** Starts a Leak test. This will inflate the cuff at certain pressure and will mantain 
	the valve closed for some time and check if the pressure decays to find air leaks 
	\returns TRUE if success, FALSE if already running some test or measurement	*/
UINT8 Bpm_StartLeakTest(void);

/** Aborts a leak test */
void  Bpm_AbortLeakTest(void);


/** Call this function once before the main loop.
	\param pBuffer 
	\bufferSize Number of samples to store before sending them to PC. Must be multiple of 4 */
void Bpm_Init(void);

/** Array of pointers to functions to execute Bpm events */
extern const pFunc_t Bpm_Events[];	

/** These are the possible events that the Bpm can generate */
typedef enum
{
	EVENT_BPM_NONE,
	EVENT_BPM_MEASUREMENT_COMPLETE_OK,
	EVENT_BPM_MEASUREMENT_ERROR,
	EVENT_BPM_LEAK_TEST_COMPLETE,
	EVENT_BPM_NEW_DATA_READY,				//for debug only
	EVENT_BPM_SEND_PRESSURE_VALUE_TO_PC,
	EVENT_BPM_CUFF_DEINFLATED,
} Bpm_Event_e;

/** Leak test error code results */
typedef enum
{
	NO_LEAK,
	MINOR_LEAK,
	MAYOR_LEAK,
} Bpm_LeakErrorCodes_e;



typedef enum
{
	BPM_ERROR_OK,
	BPM_ERROR_NOT_ENOUGH_INFLATING_PRESSURE,
	BPM_ERROR_SYSTOLIC_NOT_FOUND,
	BPM_ERROR_DIASTOLIC_NOT_FOUND,
	BPM_ERROR_PATIENT_MOVED_ARM,
	BPM_ERROR_AIR_LEAKAGE,	
	BPM_ERROR_ARRAY_IS_FULL,
} Bpm_ErrorCodes_e;

/** Main Bpm state machine states */
typedef enum
{
	STATE_IDLE,
	STATE_MEASURING,
	STATE_LEAK_TEST
} BpmStates_e;

/** Substates for the LeakTest state */
typedef enum
{
	LEAK_TEST_SUBSTATE_INFLATING_PHASE_0,
	LEAK_TEST_SUBSTATE_PARTIALLY_INFLATED,
	LEAK_TEST_SUBSTATE_INFLATING_PHASE_1,
	LEAK_TEST_SUBSTATE_TOTALLY_INFLATED,
	LEAK_TEST_SUBSTATE_CHECK_LEAKS
} Bpm_LeakTestSubStates_e;

/** Substates for the measuring state */
typedef enum
{
	BPM_STATE_MEASURING_SUBSTATE_DELAY,
	BPM_STATE_MEASURING_SUBSTATE_FIND_MAX_POINT,
	BPM_STATE_MEASURING_SUBSTATE_FIND_MIN_POINT,
	
};

typedef enum
{
	FINDING_LARGE_PULSE,
	FINDING_SMALL_PULSE,
	VALIDATE_MAX_PRESSURE_VALUE
};
		


#endif //_BLOOD_PRESSURE_MONITOR