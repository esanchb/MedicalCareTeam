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

/**
	\file
	\brief 	This file handles the reading of the spirometer AFE.
	\author Samuel Quiroz
	\date 2011-25-01
*/

#ifndef _SPR
#define _SPR


#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "PublicTypes.h"
#include "ADC.h"
#include "AverageFilter.h"
#include "SwTimer.h"
#include "SystemConfig.h"

#define 	SPR_OUTBUFFER_SIZE						16
	
#define 	ADC_CHANNEL_SPR_PRESSURE_SIGNAL		0

#define		SPR_SAMPLING_PERIOD					10		//ms
#define		SENSOR_WARM_UP_TIME					50		//ms

#define		INHALATION_DETECTION_THRESHOLD 		25		//ADC counts

#define		IGNORED_INITIAL_SAMPLES				32		//number of samples that will be ignored at the beginning of each measuremnt
														//this is because the moving average stabilization and the sensor warm up time

#define 	STOP_DETECTION_THRESHOLD			5		//adc counts


#define 	INIT_SAMPLES						256		//initial samples to get an average of the offset value

//#define	NO_THRESHOLD				//define this to send graph data all the time, until the PC sends the abort command

extern UINT8 Spr_IsMeasurementComplete;
extern UINT8 Spr_GraphData[SPR_OUTBUFFER_SIZE];

void  Spr_PeriodicTask(void);
UINT8 Spr_StartMeasurement(void);
void  Spr_AbortMeasurement(void);




/** Call this function once before the main loop. */	
void Spr_Init(void);

/** Array of pointers to functions to execute Spr events */
extern const pFunc_t Spr_Events[];	

/** These are the possible events that the Spr can generate */
typedef enum
{
	EVENT_SPR_NONE,
	EVENT_SPR_MEASUREMENT_COMPLETE_OK,
	EVENT_SPR_MEASUREMENT_ERROR,
	EVENT_SPR_NEW_DATA_READY
} Spr_Event_e;






#endif //_SPR