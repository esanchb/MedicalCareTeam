#ifndef _GLUCOSE_METER
#define _GLUCOSE_METER


#include "derivative.h" /* include peripheral declarations */
#include "PublicTypes.h"
#include "ADC.h"
#include "AverageFilter.h"
#include "SwTimer.h"


/* Glucose meter parameters */

/* All timers are in ms */

/** The time in ms that will elapse between the blood is detected and the current is measured */
#define FINISH_GLUCOSE_MEASUREMENT_TIME		5000

/** The sampling period where the strip current will be measured */
#define GLUCOSE_SAMPLING_PERIOD				50	//ms


/* Pin definitions */

/** The ADC channel of Working Electrode 1 */
#define ADC_CHANNEL_WORKING_ELECTRODE1	0

/** The ADC channel of Working Electrode 2 */
#define ADC_CHANNEL_WORKING_ELECTRODE2	8

/** The voltage blood detection voltage threshold in mV */
#define BLOOD_DETECT_THRESHOLD_mV		560		//mV corresponds to 1uA approx

/** ADC Reference voltage in mV */
#define REF_VOLTAGE_mV					3300	//mV

/** ADC resolution in bits */
#define GLU_ADC_RESOLUTION					255

#define BLOOD_DETECT_THRESHOLD		(UINT32)(((UINT32)BLOOD_DETECT_THRESHOLD_mV*(UINT32)GLU_ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)

/** Voltage Offset of the electrodes */
#define	ELECTRODES_VOLTAGE_OFFSET_mV			100		//mV

/** Same but in ADC counts */
//#define	ELECTRODES_VOLTAGE_OFFSET			(UINT32)(((UINT32)ELECTRODES_VOLTAGE_OFFSET_mV*(UINT32)GLU_ADC_RESOLUTION)/(UINT32)REF_VOLTAGE_mV)
#define	ELECTRODES_VOLTAGE_OFFSET			37



#define GLU_GRAPH_DATA_ARRAY_SIZE	16


////////////////////////////
//#define GLU_DEBUG		//define this to send real time data to PC for debug
//////////////////////


/** Starts a glucose measurement 
	\returns TRUE if the measurement was started, FALSE if not
*/
UINT8 GlucoseMeter_StartMeasurement(void);

/** Abort a glucose measurement */
void GlucoseMeter_AbortMeasurement(void);

/** The Periodic task that must be called from main */
void GlucoseMeter_PeriodicTask(void);

/** Call this function once on initization */
void GlucoseMeter_Init(void);

/** 
	Starts a glucose calibration routine 
	\param knownGlucoseValue A known glucose vale in mgr/dl
	\returns TRUE if the measurement was started, FALSE if not
*/
UINT8 GlucoseMeter_StartCalibration(UINT16 knownGlucoseValue);

/** The result of the glucose measurment in mgr/dl */
extern UINT16 GlucoseMeter_GlucoseValue;

/** The calibration constant for the */
extern INT16 GlucoseMeter_CalibrationConstant;

/** Array of functions for the Glucose Events. Must be defined in upper layer */
extern const pFunc_t GlucoseMeter_Events[];	


extern UINT8 GlucoseMeter_GraphDataToPc[GLU_GRAPH_DATA_ARRAY_SIZE];


typedef enum
{
	EVENT_GLU_NONE,						/**< No event */
	EVENT_GLU_BLOOD_DETECTED,			/**< Blood was detected */
	EVENT_GLU_FINISH_MEASUREMENT_OK,	/**< Measurement finished correctly */
	EVENT_GLU_FINISH_CALIBRATION_OK,	/**< Calibration finished correctly */
	EVENT_GLU_DEBUG_NEW_DATA_READY,		/**< Send real time ADC data for dedub */
} GlucoseMeter_Event_e;

#endif //_GLUCOSE_METER