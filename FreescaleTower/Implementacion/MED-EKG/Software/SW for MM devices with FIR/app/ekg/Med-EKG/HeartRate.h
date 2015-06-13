/******************************************************************************
*                                                  
*  (c) copyright Freescale Semiconductor 2010
*  ALL RIGHTS RESERVED
*
*  File Name:   HeartRate.h
*                                                                          
*  Description: Header file for HR detection and AGC algorithms 
*                                                                                     
*  Assembler:   Codewarrior for HC(S)08 V6.3
*                                            
*  Version:     1.0                                                         
*                                                                                                                                                         
*  Author:      Carlos Jose Maria Casillas Mora
*                                                                                       
*  Location:    Guadalajara,Mexico                                              
*                                                                                                                  
*                                                  
* UPDATED HISTORY:
*
* REV   YYYY.MM.DD  AUTHOR            DESCRIPTION OF CHANGE
* ---   ----------  ------            --------------------- 
* 1.0   2010.10.04  Carlos Casillas   Initial version
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


#ifndef _HeartRate_H_
  #define _HeartRate_H_


/* Includes */
#include "PublicTypes.h"

/* Common user definitions */
#define HR_MAX_TIME_WITHOUT_PULSES	      3	   //time in seconds
#define HR_WINDOW_SAMPLES                 250   
#define HR_PULSES_AVERAGE                 6
#define ADJUST_WINDOW_TIME                1200  // msec
#define COUNT_FOR_10mS                    10 // 10mS/Sample_number period 


#if  1

/* User definitions for MC9S08MM128 */
#define HR_SLOPE_THRESHOLD_CALC           4000
#define IDEAL_AMPLITUDE_LOW               10000
#define IDEAL_AMPLITUDE_HI                15000  

#elif (defined _MCF51MM256_H)

/* User definitions for MCF51MM256 */
#define HR_SLOPE_THRESHOLD_CALC           4500
#define IDEAL_AMPLITUDE_LOW               10000
#define IDEAL_AMPLITUDE_HI                15000   

#endif

#define BEAT_LED

/* Heart Rate  datection and Gain adjust variables */
extern UINT16 FirstSample;
extern UINT16 SecondSample;
extern UINT16 ThirdSample;

extern UINT16 HR_buffer[HR_PULSES_AVERAGE];
extern UINT8  HR_buffer_index;
extern UINT16 Averaged_HR;
extern UINT16 HR_watchdog;

extern UINT16 Sample_number;
extern UINT16 Sample_compare;
extern UINT16 Min_value;
extern UINT16 Max_value;
extern UINT16 Amplitude_value;
extern UINT8  msOccured;

extern UINT16 OldPulseTime; 
extern UINT16 NewPulseTime;
extern UINT16 BeatsPeriod;

extern UINT8 u8Gain_index;
extern const UINT8 AmpGain[];


/* Prototypes */
extern void HR_periodic_task (UINT16 new_sample);
extern void HR_calculation (UINT16 time_between_pulses);
extern void AGC_task (void);
void SamplingCheck (UINT16 FilterOutput);


#endif /* _HeartRate_H_ */