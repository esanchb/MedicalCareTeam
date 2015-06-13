/****************************************************************************
*                           FTM Driver for Kinetis
*****************************************************************************
* @file: Kinetis_FTM.c
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


#include "Kinetis_FTM.h"

/*****************************************************************************
*                                Definitions
*****************************************************************************/

 

#define FTM0_MOD_VALUE  750    //1mS using 48Mhz in System Clock with a prescaler of 64 
#define FTM1_MOD_VALUE  15     //10uS per count  

#define FTM2_PWMCH1_PORT      PORTA_PCR11 //PWM Output on PTA11
#define FTM2_PWMCH1_PIN       11
#define FTM2_PWMCH1_PINDDR    GPIOA_PDDR
#define FTM2_PWMCH1_PINCLR    GPIOA_PCOR
#define FTM2_PWMCH1_PINSET    GPIOA_PSOR

/*****************************************************************************
*                                  Globals
*****************************************************************************/

unsigned char gu8FTM0_TOF = 0;

unsigned char FTM_DecrementValue = 0;

/*****************************************************************************
*                                  Locals
*****************************************************************************/

unsigned long ElapsedTimeIn_us=0;

/*****************************************************************************
*                                 Functions  
*****************************************************************************/

void FTM0_Init (void)
{ 
  SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK; //Gives clock to FTM0
  
  FTM0_MOD = FTM0_MOD_VALUE;
  FTM0_SC = (FTM_SC_CLKS(1) | FTM_SC_TOIE_MASK | FTM_SC_PS(6));   //Runs FTM System Clock Prescaler = 64
  
  NVICICPR1|=(1<<30);                     //Clear any pending interrupts on FTM0
  NVICISER1|=(1<<30);                     //Enable interrupts from FTM0 module  
}

/*****************************************************************************/

void FTM1_Init(void)
{
  SIM_SCGC6 |= SIM_SCGC6_FTM1_MASK; //Gives clock to FTM1
  
  FTM1_MOD = FTM1_MOD_VALUE;
  FTM1_SC = (FTM_SC_CLKS(1) | FTM_SC_TOIE_MASK | FTM_SC_PS(5));   //Runs FTM System Clock Prescaler = 32
  
  NVICICPR1|=(UINT32)(1<<31);                     //Clear any pending interrupts on FTM1
  NVICISER1|=(UINT32)(1<<31);                     //Enable interrupts from FTM1 module  
}

/*****************************************************************************/

void FTM1_Deinit (void)
{
 FTM1_SC = 0;
 FTM1_CNT = 0;
}

/*****************************************************************************/

void FTM0_ISR (void)
{
 FTM0_SC &= ~FTM_SC_TOF_MASK;
 
 FTM0_MOD=FTM0_MOD_VALUE;
 gu8FTM0_TOF = 1;
 FTM_DecrementValue = 1; 
}

/*****************************************************************************/

void FTM1_ISR (void)
{
 FTM1_SC &= ~FTM_SC_TOF_MASK;
 
 FTM1_MOD=FTM1_MOD_VALUE;
 ElapsedTimeIn_us += FTM1_OVF_PERIOD_us;
 
}

/*****************************************************************************/

void FTM2_Init(void)
{
 SIM_SCGC3 |= SIM_SCGC3_FTM2_MASK; //Gives clock to FTM2
  
 FTM2_SC = FTM2_SC_CONFIG;
 FTM2_MOD = FTM2_MODULO;
 FTM2_CH1_Init();
}

/*****************************************************************************/

void FTM2_CH1_Init (void)
{
  FTM2_C1SC = (FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK); //High True Pulses Edge Aligned PWM
  FTM2_C1V = (unsigned long)(FTM2_MODULO/2); //50% PWM
  FTM2_PWMCH1_PORT = PORT_PCR_MUX(3); //Go to PWM mode
}

/*****************************************************************************/

void FTM2_CH1_PWM_Start(unsigned long u16DutyCycle)
{
 FTM2_C1V = u16DutyCycle;
 FTM2_PWMCH1_PORT = PORT_PCR_MUX(3); //Enables PWM Output
 FTM2_SC |= FTM_SC_CLKS(1); //System clock on FTM2, start generating PWM
}

/*****************************************************************************/

void FTM2_CH1_PWM_Stop (unsigned char u8PinStatus)
{
  FTM2_PWMCH1_PORT = PORT_PCR_MUX(1); //Set as GPIO
  FTM2_PWMCH1_PINDDR |= (1<<FTM2_PWMCH1_PIN); //Set as GPIO to control the pin level
  if(u8PinStatus)
   FTM2_PWMCH1_PINSET |= (1<<FTM2_PWMCH1_PIN); //Set the output
  else
   FTM2_PWMCH1_PINCLR |= (1<<FTM2_PWMCH1_PIN); //Clear the output
  
  FTM2_SC &= ~FTM_SC_CLKS_MASK; // No clock selected, FTM2 Stops

  FTM2_CNT = 0; //Resets Counter
}