/******************************************************************************
*                                                  
*  (c) copyright Freescale Semiconductor 2010
*  ALL RIGHTS RESERVED
*
*  File Name:   EcgFir.ch
*                                                                          
*  Description: FIR Filter for ECG 
*                                                                                     
*  Assembler:   Codewarrior for HC(S)08 V6.3
*                                            
*  Version:     1.0                                                         
*                                                                                                                                                         
*  Author:      Jose Santiago Lopez Ramirez
*                                                                                       
*  Location:    Guadalajara,Mexico                                              
*                                                                                                                  
*                                                  
* UPDATED HISTORY:
*
* REV   YYYY.MM.DD  AUTHOR            DESCRIPTION OF CHANGE
* ---   ----------  ------            --------------------- 
* 1.0   2011.03.22  Santiago Lopez    Initial version
* 
******************************************************************************/ 
/* Freescale  is  not  obligated  to  provide  any  support, upgrades or new */
/* releases  of  the Software. Freescale may make changes to the Software at */
/* any time, without any obligation to notify or provide updated versions of */
/* the  Software  to you. Freescale expressly disclaims any warranty for the */
/* Software.  The  Software is provided as is, without warranty of any kind, */
/* either  express  or  implied,  including, without limitation, the implied */
/* warranties  of  merchantability,  fitness  for  a  particular purpose, or */
/* non-infringement.  You  assume  the entire risk arising out of the use or */
/* performance of the Software, or any systems you design using the software */
/* (if  any).  Nothing  may  be construed as a warranty or representation by */
/* Freescale  that  the  Software  or  any derivative work developed with or */
/* incorporating  the  Software  will  be  free  from  infringement  of  the */
/* intellectual property rights of third parties. In no event will Freescale */
/* be  liable,  whether in contract, tort, or otherwise, for any incidental, */
/* special,  indirect, consequential or punitive damages, including, but not */
/* limited  to,  damages  for  any loss of use, loss of time, inconvenience, */
/* commercial loss, or lost profits, savings, or revenues to the full extent */
/* such  may be disclaimed by law. The Software is not fault tolerant and is */
/* not  designed,  manufactured  or  intended by Freescale for incorporation */
/* into  products intended for use or resale in on-line control equipment in */
/* hazardous, dangerous to life or potentially life-threatening environments */
/* requiring  fail-safe  performance,  such  as  in the operation of nuclear */
/* facilities,  aircraft  navigation  or  communication systems, air traffic */
/* control,  direct  life  support machines or weapons systems, in which the */
/* failure  of  products  could  lead  directly to death, personal injury or */
/* severe  physical  or  environmental  damage  (High  Risk Activities). You */
/* specifically  represent and warrant that you will not use the Software or */
/* any  derivative  work of the Software for High Risk Activities.           */
/* Freescale  and the Freescale logos are registered trademarks of Freescale */
/* Semiconductor Inc.                                                        */ 
/*****************************************************************************/

#ifndef ECG_FIR_H_
#define ECG_FIR_H_

/*****************************************************************
*                          Header files
*****************************************************************/

#include "derivative.h"
#include "PublicTypes.h"

#include "ADC.h"
#include "OPAMP.h"
#include "MM_Timers.h"
#include "HeartRate.h"

/*****************************************************************
*                           Definitions
*****************************************************************/

#define ECG_FIR_ADC_INPUT     8 //ADC Input Channel

//#define ADD_SIGN                //Uncomment for adding sign to the ECG results 

/*****************************************************************
*                  Filter Definitions for MCF51MM256
*****************************************************************/
#if (defined _MCF51MM256_H)

/* Filter Offsets */

#define ECG_FIR_INPUT_OFFSET   -5000 //-18000
#define ECG_FIR_INPUT_DIV      300    //300
#define ECG_FIR_OUTPUT_DIV     3500   //7500

/* Filter Constants */

#define ECG_FIR_FILTER_ORDER      51
#define BR_FIR_FILTER_ORDER       200
#define MAX_ECG_DATA              32

/* BP Filter Offsets */

#define BR_FIR_INPUT_OFFSET    -0
#define BR_FIR_INPUT_DIV       150
#define BR_FIR_OUTPUT_DIV      500
/******************************************************************/

/******************************************************************
*                 Filter Definitions for MC9S08MM128
******************************************************************/

#elif (defined _MC9S08MM128_H)

#define ECG_FIR_INPUT_OFFSET   -12000 //-18000
#define ECG_FIR_INPUT_DIV      300    //300
#define ECG_FIR_OUTPUT_DIV     1750   //7500

/* Filter Constants */

#define ECG_FIR_FILTER_ORDER      10
#define BR_FIR_FILTER_ORDER       10
#define MAX_ECG_DATA              32

/* BP Filter Offsets */

#define BR_FIR_INPUT_OFFSET    -0
#define BR_FIR_INPUT_DIV       150
#define BR_FIR_OUTPUT_DIV      500

#endif

/*****************************************************************/

/* Timer Settings */

#define TIMER_FLAG            u8Tpm1Ch0Flag
#define TIMER_INIT            vfnTPM1_CH0_Init()
#define TIMER_DEINIT          vfnTPM1_CH0_Deinit()
                                        

/*****************************************************************
*                       Global Variables
*****************************************************************/

extern UINT16 au16EcgFilteredData[MAX_ECG_DATA];

extern const pFunc_t EcgFir_Events[];

extern const INT32 i32EcgFilterCoefs[];

/*****************************************************************
*                       Global Functions
*****************************************************************/

extern void vfnEcgFirPeriodicTask (void);

extern UINT8 EcgFir_DiagnosticModeStartMeasurement (void);

extern void EcgFir_DiagnosticModeStopMeasurement (void);

#endif
