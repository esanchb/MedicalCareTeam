/****************************************************************************
 *                            FIR for Kinetis
 ******************************************************************************
 *
 * Freescale Semiconductor Inc.
 * (c) Copyright 2004-2011 Freescale Semiconductor, Inc.
 * ALL RIGHTS RESERVED.
 *
 ******************************************************************************
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
 * IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
*****************************************************************************
* @file: Kinetis_FIR.c
* 
* @author : Santiago Lopez [SL]  Freescale Americas
*
* @version: 1.0
*
* @description: Program to implement Finite Impulse Response Filters on Kinetis
******************************************************************************/

#include "Kinetis_FIR.h"

/******************************************************************************
*                                  Globals
*******************************************************************************/

/*Coeficients for band pass filter 0.1Hz - 150Hz*/

int gi32FIR_Coeficients1 [] = {
0,-63,-278,-552,-614,-68,1445,3997,7119,9635,9756,5509,-4490,-20096,-38816,-55509,-62878,-52858,-18704,42740,129254,232586,339327,
433272,498780,524286,505032,444227,352326,244605,137715,46149,-20474,-58683,-70839,-63503,-45126,-23764,-5408,6767,12246,12390,9412,
5462,2057,-102,-998,-1015,-641,-257,-46,0
};



int g32SpO2_Coefs[]=
{
0,-4,-6,-10,-13,-14,-14,-12,-7,0,8,17,24,27,25,17,2,-19,-43,-67,-87,-99,-100,-87,-59,-19,29,79,122,151,157,136,84,5,-95,-205,-308,
-388,-427,-411,-328,-174,49,331,653,993,1323,1617,1848,1996,2047,1996,1848,1617,1323,993,653,331,49,-174,-328,-411,-427,-388,-308,
-205,-95,5,84,136,157,151,122,79,29,-19,-59,-87,-100,-99,-87,-67,-43,-19,2,17,25,27,24,17,8,0,-7,-12,-14,-14,-13,-10,-6,-4,0
};

int g32SpO2_Baseline_Coefs[]=
{
0,8,31,69,122,188,267,358,458,568,684,805,930,1055,1181,1304,1423,1536,1641,1737,1822,1895,1955,2000,2031,2047,2046,2031,2000,
1955,1895,1822,1737,1641,1536,1423,1304,1181,1055,930,805,684,568,458,358,267,188,122,69,31,8,0
};

int gi32ADC_Buffer[FILTER_ORDER] = {0};

unsigned long gu16FIR_Data[FIR_DATA_TO_SEND] = {0};

unsigned char gu8FilterDataReady=0;

unsigned long gu16IR_Samples[SPO2_FILTER_ORDER] = {0};

unsigned long gu16R_Samples[SPO2_FILTER_ORDER] = {0};

unsigned long gu16R_Base[SPO2_BASELINE_FILTER_ORDER] = {0};

unsigned long gu16IR_Base[SPO2_BASELINE_FILTER_ORDER] = {0};

/*****************************************************************************
*                                 Functions
*****************************************************************************/

void vfnFilter_Periodic_Task (void)  
{
 static unsigned char u8FIR_ActualSample = FILTER_ORDER-1;
 static unsigned char u8FIR_Data_To_Send_Index = FIR_DATA_TO_SEND;
 volatile unsigned int u32FilteredValue;
 
 /* Put your data to be filtered here
    TestBuffer[u8FIR_ActualSample] += INPUT_OFFSET;
 */
   gi32ADC_Buffer[u8FIR_ActualSample] = (int)(ADC1_Read16b(0));
   
#ifndef BYPASS
   gi32ADC_Buffer[u8FIR_ActualSample] += INPUT_OFFSET; 
   gi32ADC_Buffer[u8FIR_ActualSample] /= INPUT_DIVISOR;
#endif
 
 /* Execute the filter 
 u32FilteredValue = u32Filter_Execution (&TestBuffer[u8FIR_ActualSample],&TestBuffer[FILTER_ORDER],&gi32FIR_Coeficients1[0]); 
 */
   
 u32FilteredValue = i32Filter_Execution (&gi32ADC_Buffer[u8FIR_ActualSample],&gi32ADC_Buffer[FILTER_ORDER],&gi32FIR_Coeficients1[0], FILTER_ORDER);
 
 u32FilteredValue/=OUTPUT_DIVISOR;  //This is the output data for the actual sample
 
 #ifdef BYPASS
 u32FilteredValue = gi32ADC_Buffer[u8FIR_ActualSample];   
 #endif   
 
 if(u8FIR_ActualSample)
 { 
  u8FIR_ActualSample--; 
 }
 else
 {
  u8FIR_ActualSample += (unsigned char)(FILTER_ORDER-1); 
 }
 
#if (!((defined BYPASS)||(defined DAC0_TEST))) 
 /* Signal treatment for MED-EKG */

 if(u32FilteredValue > 0xFFFF)
    u32FilteredValue = 0xFFFF;
 
 u32FilteredValue = (unsigned long) u32FilteredValue;
 
 HR_periodic_task ((unsigned long) u32FilteredValue); //Calculate HR before sign the signal 
 
 /*Signal Signing proccess*/
#if 0 //JAVA AFE does not need sign change
 if (u32FilteredValue > 0x7FFF)
 {
  u32FilteredValue-=0x8000;
 }
 else
 {
   /* Sign change */
   u32FilteredValue |= 0x00008000; //Add sign bit
 }
#endif
 
#endif
 
 gu16FIR_Data[u8FIR_Data_To_Send_Index-1] = (unsigned long)(u32FilteredValue); //send data to buffer
 u8FIR_Data_To_Send_Index--;
 
 if(!u8FIR_Data_To_Send_Index)
 {
  gu8FilterDataReady=TRUE;
  u8FIR_Data_To_Send_Index=FIR_DATA_TO_SEND;
 }
 
 
#if (defined DAC0_TEST)
 u32FilteredValue /=16; 
 
 if (u32FilteredValue>4095)
     u32FilteredValue=4095;
 
 DACDAT0 = u32FilteredValue; 
#endif
 
}

/*********************************************************************************************************************************/

/*********************************************************************************************************************************/

int i32Filter_Execution (int *pi32ActualSample, int *pi32BufferLimit, int *pi32Coefptr, unsigned char u8Filter_Order)
{
 volatile unsigned char u8Filter_Order_Copy = u8Filter_Order;
 volatile int i32Accumulate = 0;
  
#if (defined CODE)
 volatile int i32Multiply = 0;
#endif
 
 while (u8Filter_Order--)
 {
   
#if (defined CODE)
   i32Multiply = (int) ((*pi32ActualSample++)*(*pi32Coefptr++));
   i32Accumulate += i32Multiply;
#elif (defined MAC)
   i32Accumulate = __smlal(i32Accumulate,(*pi32ActualSample++),(*pi32Coefptr++)); //Assembly routine for Signed Multiply and Accumulate DSP instruction 
#else
#error "Invalid Definition"
#endif
   
   if(pi32ActualSample == pi32BufferLimit)
      pi32ActualSample -= u8Filter_Order_Copy;
   
 } 
   
    /* Uncoment this to remove sign */ 
   if(i32Accumulate & (int)(0x80000000))
   return(0); 
   
   return (unsigned int)i32Accumulate;   
 }

/**************************************************************************************************************************************/

/*****************************************************************************
*                          SPO2 Kinetis Internal filter
*****************************************************************************/



int u32SPO2_Filter(unsigned long u16NewSample, int* LEDBuffer)
{
 static unsigned char SPO2_ActualSample = SPO2_FILTER_ORDER-1;
 unsigned int u32FilteredValue;
 
 //gu16SPO2_Samples[SPO2_ActualSample]=u16NewSample+SPO2_INPUT_OFFSET;
 *(LEDBuffer+SPO2_ActualSample)=u16NewSample+SPO2_INPUT_OFFSET;
 
 u32FilteredValue = i32Filter_Execution((LEDBuffer+SPO2_ActualSample), (LEDBuffer+SPO2_FILTER_ORDER), &g32SpO2_Coefs[0], SPO2_FILTER_ORDER);
 
 u32FilteredValue= u32FilteredValue/SPO2_OUTPUT_DIV;
 
 if(SPO2_ActualSample)
 { 
  SPO2_ActualSample--; 
 }
 else
 {
  SPO2_ActualSample += (unsigned char)(SPO2_FILTER_ORDER-1); 
 }
 
#if 1   //Avoids overflow with 12bits
 if (u32FilteredValue>0x0FFF)
   u32FilteredValue=0x0FFF;
#endif
 
 return u32FilteredValue; 
}

/*************************************************************************************/

int u32SPO2_BaselineFilter(unsigned long u16NewSample, int* LEDBuffer)
{
 static unsigned char SPO2_ActualSample = SPO2_FILTER_ORDER-1;
 unsigned int u32FilteredValue;
 
 //gu16SPO2_Samples[SPO2_ActualSample]=u16NewSample+SPO2_INPUT_OFFSET;
 *(LEDBuffer+SPO2_ActualSample)=u16NewSample+SPO2_BASELINE_INPUT_OFFSET;
 
 u32FilteredValue = i32Filter_Execution((LEDBuffer+SPO2_ActualSample), (LEDBuffer+SPO2_BASELINE_FILTER_ORDER), &g32SpO2_Baseline_Coefs[0], SPO2_BASELINE_FILTER_ORDER);
 
 u32FilteredValue= u32FilteredValue/SPO2_BASELINE_OUTPUT_DIV;
 
 if(SPO2_ActualSample)
 { 
  SPO2_ActualSample--; 
 }
 else
 {
  SPO2_ActualSample += (unsigned char)(SPO2_BASELINE_FILTER_ORDER-1); 
 }
 
#if 1   //Avoids overflow with 12bits
 if (u32FilteredValue>0x0FFF)
   u32FilteredValue=0x0FFF;
#endif
 
 return u32FilteredValue; 
}