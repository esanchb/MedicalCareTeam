/******************************************************************************
*                                                  
*  (c) copyright Freescale Semiconductor 2010
*  ALL RIGHTS RESERVED
*
*  File Name:   HeartRate.c
*                                                                          
*  Description: HR detection and AGC algorithms 
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


/* Includes */
#include "HeartRate.h"
#include "OPAMP.h"


/* Heart Rate  datection and Gain adjust variables */
UINT16 FirstSample;
UINT16 SecondSample;
UINT16 ThirdSample;

UINT16 HR_buffer[HR_PULSES_AVERAGE];
UINT8  HR_buffer_index = 0;
UINT16 Averaged_HR = 0;
UINT16 HR_watchdog = 0;

UINT16 Sample_number = 0;
UINT16 Sample_compare = ADJUST_WINDOW_TIME;
UINT16 Min_value = 0xFFFF;
UINT16 Max_value = 0x0000;
UINT16 Amplitude_value;
UINT8  msOccured = 0;

UINT16 OldPulseTime = 0; 
UINT16 NewPulseTime = 0;
UINT16 BeatsPeriod = 0;

UINT8 u8Gain_index = 9;
const UINT8 MMAmpGain[] = 
{
 Gain2,
 Gain3,
 Gain4,
 Gain4half,    
 Gain6,
 Gain6half,  
 Gain8half,  
 Gain9,    
 Gain13,   
 Gain17
};



/*****************************************************************************************/

void HR_periodic_task (UINT16 new_sample)
{
  if (new_sample < Min_value) 
  {
    Min_value = new_sample; 
  }
  if (new_sample > Max_value) 
  {
    Max_value = new_sample;
  }
  
  SamplingCheck(new_sample);
  
  if( (FirstSample > SecondSample) && (SecondSample > ThirdSample) &&
      ((FirstSample - ThirdSample)>HR_SLOPE_THRESHOLD_CALC)             
    ) 
  {                                                             
    HR_calculation(BeatsPeriod);                      
  }
  
  AGC_task();
  
  if ( HR_watchdog > (100*HR_MAX_TIME_WITHOUT_PULSES) )  
  {
    Averaged_HR = 0;  
  }
}

/*****************************************************************************************/

void HR_calculation(UINT16 time_between_pulses)
{
   UINT8  pulse_counter = 0;
   UINT16 Average_HR_Value = 0;
   
   OldPulseTime = NewPulseTime;
   NewPulseTime = Sample_number;
   BeatsPeriod =  (UINT16)(NewPulseTime - OldPulseTime);
  
   if (time_between_pulses > HR_WINDOW_SAMPLES)
   { 
     PTFD_PTFD1 = 1;
     
     HR_watchdog = 0;
     HR_buffer[HR_buffer_index] = (UINT16)(60000/time_between_pulses);
     
     if(++HR_buffer_index == HR_PULSES_AVERAGE)
     {
       HR_buffer_index = 0;
     }
     
     for ( pulse_counter = 0; pulse_counter<HR_PULSES_AVERAGE; pulse_counter++ )
     {
        Average_HR_Value += HR_buffer[pulse_counter];
     }
     
     Averaged_HR = (UINT16)(Average_HR_Value/HR_PULSES_AVERAGE);
     Average_HR_Value = 0;
   }
}

/*****************************************************************************************/

void AGC_task(void)
{
  if (Sample_number == Sample_compare)  
  {  
    //if (Min_value != Max_value)
    {
      Amplitude_value = (UINT16)(Max_value - Min_value);
    
      Min_value = 0xFFFF;
      Max_value = 0x0000;
    }
    Sample_compare += ADJUST_WINDOW_TIME;
  
    if ( (Amplitude_value < IDEAL_AMPLITUDE_LOW ) && (u8Gain_index<9) ) 
    {
      u8Gain_index++;
      if ( Amplitude_value < (IDEAL_AMPLITUDE_LOW/2) && (u8Gain_index<9) )
      {        
        u8Gain_index++;
      }
    } 
  
    if ( (Amplitude_value > IDEAL_AMPLITUDE_HI ) && (u8Gain_index) ) 
    {
      u8Gain_index--;
      if ( Amplitude_value > (2*IDEAL_AMPLITUDE_HI) && (u8Gain_index) ) 
      {        
        u8Gain_index--;
      }
    }
    opamp2_noninverting_mode(MMAmpGain[u8Gain_index]);
  }
}

/*****************************************************************************************/  

void SamplingCheck (UINT16 FilterOutput)
{
 if(msOccured >= COUNT_FOR_10mS)
 {
  HR_watchdog++;
     
  FirstSample = SecondSample;
  SecondSample = ThirdSample;
  ThirdSample = (UINT16)(FilterOutput);
  
  #ifdef BEAT_LED
    PTFD_PTFD1 = 0; 
  #endif
  
  msOccured = 0;  
 }
}
