/****************************************************************************
*                           FTM Driver for Kinetis
*****************************************************************************
* @file: Kinetis_FTM.h
* 
* @author : Santiago Lopez [SL]  Freescale Americas
*
* @version: 1.0 for IAR
*
* @date: 13/01/11
*
* @description: Drivers for Kinetis Flex Timer
*******************************************************************************
* @changes:
*
*    Date       Author         Version               Description of Change
*
*  13/01/11       SL             1.0                    Initial Version
******************************************************************************/

#ifndef _KINETIS_FTM_H_
#define _KINETIS_FTM_H_

#include "derivative.h"
#include "PublicTypes.h"

/*****************************************************************************
*                                  Globals
*****************************************************************************/

extern unsigned char gu8FTM0_TOF;
extern unsigned char FTM_DecrementValue;     //Value for SWTimer

#define FTM1_OVF_PERIOD_us     10

#define FTM2_SC_CONFIG         (FTM_SC_PS(1)); //Frec divided by 2
#define FTM2_MODULO             500//1200 //For 20Khz on PWM
#define FTM2_CH1_PWM_MAX_VAL    FTM2_MODULO

extern unsigned char FTM_DecrementValue;

extern unsigned long ElapsedTimeIn_us;

/*****************************************************************************
*                          Function Definitions  
*****************************************************************************/

extern  void FTM0_Init (void);
void FTM0_ISR (void);
extern void FTM1_Init(void);
extern void FTM1_Deinit (void);
void FTM1_ISR (void);
extern void FTM2_Init(void);
void FTM2_CH1_Init (void);
extern void FTM2_CH1_PWM_Start(unsigned long u16DutyCycle);
extern void FTM2_CH1_PWM_Stop (unsigned char u8PinStatus);


#endif