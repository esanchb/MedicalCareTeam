/****************************************************************************
 *                            OpAmp Detection
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
* @file: opamp_detect.c
* 
* @author : 
*
* @version: 1.0
*
* @description: OpAmp detection functions for Analog Front End units
******************************************************************************/

/*****************************************************************************
* Header files
*****************************************************************************/
#include "opamp_detect.h"

/*****************************************************************************
* Functions
*****************************************************************************/
unsigned char u8OpCheckGlu (void)
{
 unsigned short u16AdcRead = 0;
 
 MEDCON_INIT();                                                                 //Initialize Medical Connector
 
 ADC0_Init16b();								//Initialize ADC1 in order to read OpAmp0 Out
 MEDCON_PWRON();								//Turn on medical connector

 time_delay_ms(100);                                                            //Wait 100mS for signal stabilization
 
 u16AdcRead = ADC0_Read16b(0);							//Read ADC0_CH0 (OpAmp0 Out)

 if(u16AdcRead >= (_1_mV*300) && u16AdcRead <= (_1_mV*700))			//Check if ADC0 is into the range (300mV-700mV)
 {
 	return OPAMPS_PRESENT;							//Baseline present, OpAmps are populated 
 }
 else
 { 
	return OPAMPS_NOT_PRESENT;						//No baseline present, OpAmps are not populated
 } 

}

/******************************************************************************/
unsigned char u8OpCheckSpo2 (void)
{
  unsigned short u16AdcRead = 0;
  
  MEDCON_INIT();                                                                //Initialize Medical Connector
  
  ADC1_Init16b();								//Initialize ADC1 so we can read TRIAMP1 Out
  MEDCON_PWRON();								//Turn on medical connector
  
  time_delay_ms(100);                                                           //Wait 100mS for signal stabilization

  u16AdcRead = ADC1_Read16b(22);						//Read TRIAMP1 Out (ADC1_SE22)
  
  if(u16AdcRead >= (_1_mV * 1500) && u16AdcRead <= (_1_mV * 1800))	        //Check if TRIAMP1_OUT = VCC/2
  {
          return OPAMPS_PRESENT;						//TRIAMP1_OUT = VCC/2 OpAmps present
  }
  else
  {
          return OPAMPS_NOT_PRESENT;						//OpAmps not present
  }

}

/******************************************************************************/
unsigned char u8OpCheckBpm (void)
{
  unsigned short u16AdcRead = 0;
  unsigned char u8Counter;
  tDAC_CONFIG tSineWave;
  
  //Sine wave points
  unsigned short au16Sine[16] = {
		155,
		214,
		265,
		298,
		310,
		298,
		265,
		214,
		155,
		96,
		45,
		12,
		0,
		12,
		45,
		96
};
  
  //Configure DAC in buffer mode to generate a sine wave
  tSineWave.DacModule = DAC0;
  tSineWave.u8DacRefvTrigPowermode = DACREF_2 | DAC_SW_TRIGGER | DAC_LOW_POWER;
  tSineWave.u8DacIntEn = 0x00u;
  tSineWave.u8DacDmaBufferenBuffermode = DAC_BUFFER_EN | DAC_BUFFER_NORMAL;
  tSineWave.u8DacBufferWms = 0x00u;
  tSineWave.u8DacBufferUp = 0x0Fu;
  
  MEDCON_INIT();                                                                //Initialize Medical Connector
  
  ADC0_Init16b();								//Initialize ADC1 so we can read TRIAMP1 Out
  MEDCON_PWRON();								//Turn on medical connector
  vfnDacInit(tSineWave);                                                        //Initialize DAC
  u8DacLoadBuff(DAC0, &au16Sine[0], 16);                                        //Load buffer with sine wave points
  opamp0_buffer_highspeed_mode();                                               //Enable OpAmp0 as general purpose OpAmp
  OPAMP0_C2 = OPAMP_C2_AMPPSEL(4);                                              //OpAmp0 INP+ is DAC0 out
  
  for(u8Counter = 0; u8Counter < 96; u8Counter++)
  {
    //Generate 6 sequences of a sine wave. If nothing is detected at the output, OpAmps are not present
    vfnDacSwTrigger(DAC0);                                                      //Sw triger to change buffer position
    time_delay_ms(12);                                                          //12mS delay between points
    u16AdcRead = ADC0_Read16b(0);                                               //Read OpAmp1 output at ADC0_CH0
    
    if(u16AdcRead > (_1_mV * 2000))                                             //Check if output is greater than 2V (OpAmps present)
    {
      vfnDacDeinit(DAC0);
      return OPAMPS_PRESENT;
    }
  }
  
  vfnDacDeinit(DAC0);
  return OPAMPS_NOT_PRESENT;                                                    //If ADC0_CH0 does not detect peaks in 6 sequences of sine report OpAmps not present
}