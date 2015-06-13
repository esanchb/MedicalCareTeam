/******************************************************************************
*                                                  
*  (c) copyright Freescale Semiconductor 2010
*  ALL RIGHTS RESERVED
*
*  File Name:   EcgFir.c
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

/*****************************************************************************
*                               Header Files
*****************************************************************************/

#include "EcgFir.h"

/*****************************************************************************
*                          State Machine Functions
*****************************************************************************/
void vfnEcgFirStateIdle(void);
void vfnEcgFirStateMeasuring(void);

UINT32 u32MAC(INT32 *SamplePtr, INT32 *BuffEdge, INT32 *CoefPtr, UINT8 FilterOrder);

/* Main State Machine */
void (*const EcgFirStateMachine[]) (void) =
  {
    vfnEcgFirStateIdle,
    vfnEcgFirStateMeasuring
  };
  
/*****************************************************************************
*                                 Private Macros
*****************************************************************************/
typedef enum
  {
    STATE_IDLE,
    STATE_MEASURING
  }EcgStates;
  
typedef enum
  {
   WAITING_TIMER,
   TAKING_SAMPLE,
   FILTER_SAMPLE,
   SIGN_SAMPLE,
   SAVE_RESULT,
   SEND_SERIAL_DATA   
  }EcgSubStates;

typedef enum
  {
   NULL0,
   NULL1,
   NULL2,
   NULL3,
   SEND_ECG_DATA
  }EcgFirEvents;
  
/*****************************************************************************
*                              Global Variables
*****************************************************************************/
UINT16 au16EcgFilteredData [MAX_ECG_DATA] = {0};
  
  
/*****************************************************************************
*                              Private variables
*****************************************************************************/

UINT8 u8EcgFirActualState;
UINT8 u8EcgFirPreviousState;

INT32 a32ADC_Buffer[ECG_FIR_FILTER_ORDER] = {0};
INT32 a32BR_Buffer[BR_FIR_FILTER_ORDER] = {0};

/****************************************************************************
*                      Filter Coeficients for MCF51MM256
****************************************************************************/

#if (defined _MCF51MM256_H)

const INT32 i32EcgFilterCoefs[] =
{
0,-7,-36,-76,-47,168,574,837,267,-1724,-4717,-6626,-4328,3973,15688,22698,14604,-13670,-53815,-81914,
-66505,14714,158021,327707,467301,524287,475599,339474,166641,15799,-72737,-91293,-61148,-15846,
17285,27456,19415,5038,-5633,-8870,-6511,-2463,396,1298,936,292,-89,-160,-92,-26,-1,1
};

const INT32 i32BrFilterCoefs[] = //50Hz - 60Hz Band Reject Filter
{
 0,-1,3,0,1,0,-4,-3,-11,-7,-14,-9,-10,-3,3,9,21,24,36,32,35,23,13,-5,-26,-41,-63,-68,-78,-66,-55,
-26,7,42,82,107,133,132,127,93,52,-5,-68,-123,-178,-203,-219,-193,-155,-83,0,90,181,247,301,306,288,
219,129,11,-115,-231,-335,-390,-416,-376,-302,-176,-29,130,285,403,490,505,476,373,232,51,-140,-317,
-470,-557,-595,-546,-446,-277,-78,136,341,499,614,641,608,486,318,102,-125,-335,-515,-621,32767,-621,
-515,-335,-125,102,318,486,608,641,614,499,341,136,-78,-277,-446,-546,-595,-557,-470,-317,-140,51,232,
373,476,505,490,403,285,130,-29,-176,-302,-376,-416,-390,-335,-231,-115,11,129,219,288,306,301,247,181,
90,0,-83,-155,-193,-219,-203,-178,-123,-68,-5,52,93,127,132,133,107,82,42,7,-26,-55,-66,-78,-68,-63,-41,
-26,-5,13,23,35,32,36,24,21,9,3,-3,-10,-9,-14,-7,-11,-3,-4,0,1,0,3,-1,0
};

/****************************************************************************/

/****************************************************************************
*                      Filter Coeficients for MC9S08MM128
****************************************************************************/

#elif (defined _MC9S08MM128_H)

const INT32 i32EcgFilterCoefs[] =
{
 0,
-26511,
29815,
201218,
424913,
524287,
424913,
201218,
29815,
-26511,
0
};

const INT32 i32BrFilterCoefs[] = //50Hz - 60Hz Band Reject Filter
{
 9,
-22,
-137,
-352,
-574,
32767,
-574,
-352,
-137,
-22,
9
};

#endif


/*****************************************************************************
*                         Function Definitions
*****************************************************************************/

void vfnEcgFirStateIdle (void)
  {
   //Do nothing
  }
  
void vfnEcgFirStateMeasuring (void)
  {
   static UINT8 u8BufferActualPosition=ECG_FIR_FILTER_ORDER-1;
   static UINT8 u8BrfActualPosition = BR_FIR_FILTER_ORDER-1;
   static UINT8 u8FilteredDataActualPosition = MAX_ECG_DATA;
   static UINT8 u8ActualSubState = 0;
   static UINT32 u32FilterResult;
   
   switch (u8ActualSubState)
  {
    case 0:
    if (TIMER_FLAG)
      {
       u8ActualSubState++;
       TIMER_FLAG = FALSE;
      }
    break;
    
    case 1:
     a32ADC_Buffer[u8BufferActualPosition]= ADC_Read16b(ECG_FIR_ADC_INPUT);
     a32ADC_Buffer[u8BufferActualPosition]+= ECG_FIR_INPUT_OFFSET;
     a32ADC_Buffer[u8BufferActualPosition]/= ECG_FIR_INPUT_DIV;
     
     u8ActualSubState++;
     break;
     
    case 2:
    u32FilterResult = u32MAC(&a32ADC_Buffer[u8BufferActualPosition], &a32ADC_Buffer[ECG_FIR_FILTER_ORDER-1], &i32EcgFilterCoefs[0], ECG_FIR_FILTER_ORDER); 
    u32FilterResult /= ECG_FIR_OUTPUT_DIV;
    
    /* Band Pass Filter */
    a32BR_Buffer[u8BrfActualPosition] = u32FilterResult;
    a32BR_Buffer[u8BrfActualPosition] += BR_FIR_INPUT_OFFSET;
    a32BR_Buffer[u8BrfActualPosition] /= BR_FIR_INPUT_DIV;
    
    u32FilterResult = u32MAC(&a32BR_Buffer[u8BrfActualPosition], &a32BR_Buffer[BR_FIR_FILTER_ORDER-1], &i32BrFilterCoefs[0], BR_FIR_FILTER_ORDER); 
    u32FilterResult /= BR_FIR_OUTPUT_DIV;
   
    if (u8BufferActualPosition)
     {
      u8BufferActualPosition--;
     }
    else
     {
      u8BufferActualPosition = ECG_FIR_FILTER_ORDER-1;
     }
     
    if (u8BrfActualPosition)
     {
      u8BrfActualPosition--;
     }
    else
     {
      u8BrfActualPosition = BR_FIR_FILTER_ORDER-1;
     }
     
     
     
    u8ActualSubState++;
    break;
    
    case 3:
    HR_periodic_task((UINT16)u32FilterResult);
    u8ActualSubState++;
    break;
    
    case 4:
    if (u32FilterResult > 0xFFFF)
        u32FilterResult = 0xFFFF;
    
#ifdef ADD_SIGN      //Add sign to the ECG points
    if (u32FilterResult > 0x7FFF)
      {
        u32FilterResult -= 0x8000;
      }
    else
      {
        u32FilterResult |= 0x8000; //Add Sign Bit  
      }
#endif

    u8ActualSubState++;
    break;
    
    case 5:
    u8FilteredDataActualPosition--;
    au16EcgFilteredData[u8FilteredDataActualPosition] = (UINT16)u32FilterResult;
    if(u8FilteredDataActualPosition == 0)
      {
       u8FilteredDataActualPosition = MAX_ECG_DATA;
       u8ActualSubState++;
      }
    else
      {
       u8ActualSubState = 0;
      }
    break;
    
    case 6:
    EcgFir_Events[SEND_ECG_DATA]();
    u8ActualSubState = 0;
    break;
    
    default:
    //Something went wrong
    break;
           
  }
       
  }
   
  
void vfnEcgFirPeriodicTask (void)
  {
   EcgFirStateMachine[u8EcgFirActualState](); 
  }
  
UINT8 EcgFir_DiagnosticModeStartMeasurement (void)
  {
   ADC_Init16b(8);
   APCTL2 |= 0x01; //Enable Channel 8
   TIMER_INIT;
   u8EcgFirActualState = STATE_MEASURING;
   return TRUE;
  }
  
 void EcgFir_DiagnosticModeStopMeasurement (void)
  {
   TIMER_DEINIT;
   u8EcgFirActualState = STATE_IDLE;
  }
  
/****************************************************************************************
*                                  Filter Execution 
****************************************************************************************/

UINT32 u32MAC(INT32 *SamplePtr, INT32 *BuffEdge, INT32 *CoefPtr, UINT8 FilterOrder)
{
  UINT8 FltOrder = FilterOrder;
	INT32 Mul = 0;
	INT32 Add = 0;

#if (defined _MCF51MM256_H)

     asm
     {
          move.l SamplePtr,A0
          move.l CoefPtr,A1
          move.l #0,MACSR
          move.l #0,ACC
     }
     
#endif

	while(FltOrder--)
	{
	     if(SamplePtr == BuffEdge)
	     {
	          SamplePtr -= FilterOrder-1;
            #if (defined _MCF51MM256_H)
               asm
                {
                  move.l SamplePtr,A0
                }
            #endif
	     }
	     

#if (defined _MCF51MM256_H)

	     asm
	     {
	          move.l (A0)+,D0
	          move.l (A1)+,D1
	          MAC.l D0,D1
	     }
	     SamplePtr++;
	     CoefPtr++; 
	     
#else
       Mul = (INT32)((*SamplePtr++) * (*CoefPtr++));
	     Add += Mul;
#endif
	}
#if (defined _MCF51MM256_H)

	asm
	{
	     move.l ACC,D0
	     move.l D0,Add
	}
	
#endif

     if(Add & (INT32)(0x80000000))
     {
          return(0);
     }
     return((UINT32)(Add));
}  
