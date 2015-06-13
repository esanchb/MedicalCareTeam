/*
 * File:        lptmr.c
 * Purpose:     Provide common low power timer functions
 *
 * Notes:       Right now only function provided is used
 *              to generate a delay in ms. This driver
 *              could be expanded to include more functions
 *              in the future.
 *              
 */

/*******************************************************************
*                           Header Files
********************************************************************/
#include "lptmr.h"

/*******************************************************************
*                             Globals
*******************************************************************/
unsigned char u8LptStatus = 0;

/********************************************************************
* Function: time_delay_ms
*
* Description: Uses the LPT timer as a ms delay generator using the LPO.
*              No interrupt is needed here but MCU does nothing until delay
*              has been completed
*
* Input: unsigned int count_val
*        This is the time in mS for the delay
*
* Output: void
**********************************************************************/
void time_delay_ms(unsigned int count_val)
{
  /* Make sure the clock to the LPTMR is enabled */
  SIM_SCGC5|=SIM_SCGC5_LPTIMER_MASK; 
  
  /* Set the compare value to the number of ms to delay */
  LPTMR0_CMR = count_val; 
  
  /* Set up LPTMR to use 1kHz LPO with no prescaler as its clock source */
  LPTMR0_PSR = LPTMR_PSR_PCS(1)|LPTMR_PSR_PBYP_MASK; 
  
  /* Start the timer */
  LPTMR0_CSR |= LPTMR_CSR_TEN_MASK; 

  /* Wait for counter to reach compare value */
  while (!(LPTMR0_CSR & LPTMR_CSR_TCF_MASK));
  
  /* Clear Timer Compare Flag */
  LPTMR0_CSR &= ~LPTMR_CSR_TEN_MASK;
  
  return;
}

/********************************************************************
* Function: lpt_timer_init
*
* Description: Initializes LPT as timer
*
* Input: unsigned short u16CompareVal
*        Value to be set in the LPTMR0_CMR register. When the LPT counter reaches this value
*         the counter is reset and interrupt is called if enabled.
*
* Input: unsigned char u8ClkSource
*        Clock source for the LPT. Select one of the four clock sources above.
*
* Input: unsigned char u8Prescaler
*        Prescaler value to divide the LPT clock source. Select one of the 16 preescaler options
*        above
*
* Input: unsigned char u8IntEn
*        Selects interrupt status
*        TRUE = Interrupts enabled
*        FALSE = Interrupts disabled, use polling
*
* Output: void
*
* Warning: Desired clock source must be configured before calling this function.
**********************************************************************/

void lpt_timer_init(unsigned short u16CompareVal, unsigned char u8ClkSource, unsigned char u8Prescaler, unsigned char u8IntEn)
{
 /* Enables clock on LPT */
 SIM_SCGC5 |= SIM_SCGC5_LPTIMER_MASK;
 
 /* Configure LPT clock source and prescaler */
 if(u8Prescaler == LPT_PRE_1)
 {
  LPTMR0_PSR = (LPTMR_PSR_PBYP_MASK | LPTMR_PSR_PCS(u8ClkSource));
 }
 else
 {
  LPTMR0_PSR = (LPTMR_PSR_PRESCALE(u8Prescaler-1) | LPTMR_PSR_PCS(u8ClkSource));
 }
 
 /* Load compare value to compare register */
 LPTMR0_CMR = u16CompareVal;
 
 if(u8IntEn == 1)
 {
   LPTMR0_CSR = (LPTMR_CSR_TIE_MASK | LPTMR_CSR_TEN_MASK);
   //enable_irq(85);
 }
 else
 {
   LPTMR0_CSR = LPTMR_CSR_TEN_MASK;
 }
 
 /* LPT Timer is now enabled */
}

/********************************************************************
* Function: lpt_timer_deinit
*
* Description: Disables the LPT
*
* Input: void
*
* Output: void
**********************************************************************/

void lpt_timer_deinit(void)
{
 LPTMR0_CSR = 0;  //Turn Off LPT
 SIM_SCGC5 &= (~SIM_SCGC5_LPTIMER_MASK); //Disable clock on LPT 
 
 /* LPT Timer is now disabled */
}
 
/********************************************************************
* Function: lpt_timer_isr
*
* Description: Interrupt service function for LPT interrupts
*
* Input: void
*
* Output: void
*
* Warning: Function must be registered in the vector table.
**********************************************************************/
 
 void lpt_timer_isr(void)
 {
  LPTMR0_CSR |= LPTMR_CSR_TCF_MASK; //Clears Flag
  
  /* Implement your ISR action here!! */
  LPT_INTERRUPT_EVENT;
 }