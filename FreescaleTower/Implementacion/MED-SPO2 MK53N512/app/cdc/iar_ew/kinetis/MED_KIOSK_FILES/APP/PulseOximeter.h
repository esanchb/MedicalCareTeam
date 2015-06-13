#ifndef _PULSE_OXIMETER
#define _PULSE_OXIMETER


#include "derivative.h" /* include peripheral declarations */
#include "PublicTypes.h"
#include "ADC.h"
#include "AverageFilter.h"
#include "SwTimer.h"
#include "Kinetis_FTM.h"
#include "OPAMP.h"
//#include "TPM2.h"
//#include "TpmPwm1.h"

//#define SPO2_DEBUG
#define SPO2_EXTERNAL_OPAMPS

#define SPO2_FIR   //For FIR Filtering

#if (defined SPO2_FIR)
#include "Kinetis_FIR.h"
#endif

/** ADC sampling period in ms */
#define SPO2_SAMPLING_PERIOD				1	//in ms

#ifdef SPO2_DEBUG
	#define SPO2_UPDATE_GRAPH_PERIOD			6	//in ms
#else
	#define SPO2_UPDATE_GRAPH_PERIOD			4	//in ms
#endif

/** ADC channel for pressure sensor output */
#define	SPO2_ADC_CHANNEL_OUTPUT_SIGNAL		0	//ADC1 channel number

/** ADC channel for heart beat signal */
#define	SPO2_ADC_CHANNEL_BASELINE_SIGNAL		0


#define	SPO2_REAL_TIME_DATA_ARRAY_LENGTH		64		//bytes

#define SPO2_ARRAY_LENGTH			10 //8
#define OLDEST_ELEMENT				SPO2_ARRAY_LENGTH-1
#define NEWEST_ELEMENT				0


/* Change in K50 Board */

/* Switch control pin */
#define SPO2_PIN                          11
#define SPO2_PORT                         C         //Just to know
#define SPO2_CLOCK_CONF                   SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK
#define SPO2_PIN_PCR                      PORTC_PCR11
#define SPO2_PIN_DIR_REG                  GPIOC_PDDR
#define SPO2_PIN_OUT_REG                  GPIOC_PDOR
#define SPO2_PIN_COR_REG                  GPIOC_PCOR

#define SPO2_INIT_SWITCH_CONTROL_PIN()	 SPO2_CLOCK_CONF;\
                                         SPO2_PIN_PCR= PORT_PCR_MUX(1);\
                                         SPO2_PIN_DIR_REG |= (1<<SPO2_PIN)

#define SPO2_SET_SWITCH_CONTROL(control)	 SpO2_Set_Switch_Control (control)



void SpO2_Set_Switch_Control (UINT8 Control);

/** Task that must be called periodically in tha main loop */
void  SpO2_PeriodicTask(void);

/** Starts a SpO2 measurement 
	\returns TRUE if success, FALSE if already running */
UINT8 SpO2_StartMeasurement(void);

/** Stops a SpO2 measurement */
void  SpO2_AbortMeasurement(void);

/** Starts a SpO2 measurement 
	\returns TRUE if success, FALSE if already running */
UINT8 SpO2_DiagnosticModeStartMeasurement(void);

/** Stops a SpO2 measurement */
void  SpO2_DiagnosticModeStopMeasurement(void);


/** Call this function once before the main loop */
void SpO2_Init(void);

/** Array of pointers to functions to execute SpO2 events */
extern const pFunc_t SpO2_Events[];	

extern UINT8 SpO2_HeartRate;
extern UINT8 SpO2_SaturationValue;
extern UINT8 SpO2Graph[];
extern UINT8 SpO2_HeartBeatDetected;

/** These are the possible events that the SpO2 can generate */
typedef enum
{
	SPO2_EVENT_NONE,
	SPO2_EVENT_MEASUREMENT_COMPLETE_OK,
	SPO2_EVENT_MEASUREMENT_ERROR,
	SPO2_EVENT_NEW_DATA_READY,
	SPO2_EVENT_DEBUG_MODE_NEW_DATA_READY,
} SpO2_Event_e;


/** Main SpO2 state machine states */
typedef enum
{
	SPO2_STATE_IDLE,
	SPO2_STATE_MEASURING	
} SpO2States_e;


#endif //_PULSE_OXIMETER