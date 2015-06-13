/*
 * File:        lptmr.h
 * Purpose:     Provide common low power timer functions
 *
 * Notes:
 */

#ifndef __LPTMR_H__
#define __LPTMR_H__

/*******************************************************************
*                           Header Files
********************************************************************/
#include "derivative.h"

/*******************************************************************
*                             Globals
********************************************************************/
extern unsigned char u8LptStatus;

#define LPT_INTERRUPT_EVENT		EVENT(u8LptStatus,0)
#define LPT_INTERRUPT	                COMPARE(u8LptStatus,0)
#define LPT_INTERRUPT_CLEAR		CLEAR(u8LptStatus,0)

/*******************************************************************
*                              Types
********************************************************************/

typedef enum
{
 LPT_PRE_1,
 LPT_PRE_2,
 LPT_PRE_4,
 LPT_PRE_8,
 LPT_PRE_16,
 LPT_PRE_32,
 LPT_PRE_64,
 LPT_PRE_128,
 LPT_PRE_256,
 LPT_PRE_512,
 LPT_PRE_1024,
 LPT_PRE_2048,
 LPT_PRE_4096,
 LPT_PRE_8192,
 LPT_PRE_16384,
 LPT_PRE_32768,
 LPT_PRE_65536 
}LPT_PRESCALER_VALUES;

typedef enum
{
 LPT_CLK_MCGIRCLK,
 LPT_CLK_LPO,
 LPT_CLK_ERCLK32K,
 LPT_CLK_OSCERCLK 
}LPT_CLOCK_SOURCES;

/*******************************************************************
*                            Definitions
********************************************************************/
/********************************************************************
* Macro: lpt_timer_init_ms
*
* Description: Initializes the LPT timer calling the function lpt_timer_init
*              LPT is initialized using 1KHz LPO with prescaler = 1 in order
*              to generate 1mS per count.
*
* Input: unsigned short time_ms
*        time in mS to count before an interrupt is launched.
*
* Input: unsigned char inten
*        Defines if LPT interrupt generation is enabled or not
*        TRUE = Interrupts enabled
*        FALSE = Interrupts disabled, use polling
*
* Output: void
**********************************************************************/
#define lpt_timer_init_ms(time_ms,inten)  lpt_timer_init(time_ms, LPT_CLK_LPO, LPT_PRE_1, inten)

/********************************************************************/

/* Function prototypes */

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
void time_delay_ms(unsigned int);

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
void lpt_timer_init(unsigned short u16CompareVal, unsigned char u8ClkSource, unsigned char u8Prescaler, unsigned char u8IntEn);

/********************************************************************
* Function: lpt_timer_deinit
*
* Description: Disables the LPT
*
* Input: void
*
* Output: void
**********************************************************************/
void lpt_timer_deinit(void);

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
extern void lpt_timer_isr(void);

/********************************************************************/

#endif /* __LPTMR_H__ */
