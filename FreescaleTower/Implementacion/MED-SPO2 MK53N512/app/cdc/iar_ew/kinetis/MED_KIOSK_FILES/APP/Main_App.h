/******************************************************************************
*                            Freescale Semiconductor
*
* Name: Main_App.h
*
* Description: Main application routines
*
* MCU: Kinetis (K5x)
*
* Version for IAR 6.1
*******************************************************************************/

#ifndef _MAIN_APPS_H_
#define _MAIN_APPS_H_

#include "derivative.h"
#include "types.h"          /* Contains User Defined Data Types */

#include "SwTimer.h"
#include "SystemConfig.h"
#include "SerialCommands.h"
#include "PulseOximeter.h"
#include "OPAMP.h"
#include "usb_cdc.h"        /* USB CDC Class Header File */
#include "DAC.h"
#include "TWR_K50_UI.h"
#include "Kinetis_FIR.h"
#include "Kinetis_FTM.h"
#include "opamp_detect.h"

/*****************************************************************************
*                                Definitions
*******************************************************************************/

#define  CONTROLLER_ID      (0)   /* ID to identify USB CONTROLLER */ 

#define  DATA_BUFF_SIZE     (96)

/*****************************************************************************
*                            Function Definition
*****************************************************************************/

/* Applications*/
extern void TestApp_Init(void);
extern void TestApp_Task(void);

/* Measurement Engine Handler */
void vfnTurnOffMeasurementEngine(void);
void vfnStartSPO2MeasurementEngine(void);


#endif