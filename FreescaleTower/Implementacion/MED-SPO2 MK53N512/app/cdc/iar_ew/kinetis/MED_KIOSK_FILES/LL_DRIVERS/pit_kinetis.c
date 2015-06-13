/******************************************************************************
 *
 * Freescale Semiconductor Inc.
 * (c) Copyright 2004-2013 Freescale Semiconductor, Inc.
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
 **************************************************************************//*!
 *
 * @file pit_kinetis.c
 *
 * @author  
 *
 * @version 1.0
 *
 * @date Feb-21-2013
 *
 * @brief Driver functions for Periodic Interrupt Timer (PIT) on Kinetis
 *
 *****************************************************************************/

//TODO: Deinit function

/******
 * Header files
 */

#include "pit_kinetis.h"
#include "nvic.h"

/******
 * Globals
 */
unsigned char u8PitIrqFlag = 0;

/******
 * Functions
 */

/********//*
 * @function	u8PinInit
 * 
 * @description Initializes a PIT channel
 * 
 * @input
 * 	-u8Channel: PIT channel to initialize (i.e PIT_CH0)
 *  -u8IntEn: Interrupt enable (1 = TRUE, 0 = FALSE)
 *  -u32Modulo: Modulo value for the selected channel
 *  
 * @output
 * -unsigned char: Error status (PIT_OK or PIT_ERR)
 */

unsigned char u8PitInit(unsigned char u8Channel, unsigned char u8IntEn, unsigned int u32Modulo)
{
	if(u8Channel > PIT_CH3)
		return PIT_ERR;
	
	// Clocking to PIT module
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
	
	//Enable PIT module timers
	PIT_MCR &= ~PIT_MCR_MDIS_MASK;
	
	//Load modulo value
	PIT_LDVAL_REG(PIT_BASE_PTR,u8Channel) = u32Modulo;
	
	// Enable interrupts if selected
	if(u8IntEn > 0)
	{
		PIT_TCTRL_REG(PIT_BASE_PTR,u8Channel) |= PIT_TCTRL_TIE_MASK;
		
		if(u8Channel == PIT_CH0)
			u8NvicEnableIrq(INT_PIT0 - 16);
		if(u8Channel == PIT_CH1)
			u8NvicEnableIrq(INT_PIT1 - 16);
		if(u8Channel == PIT_CH2)
			u8NvicEnableIrq(INT_PIT2 - 16);
		if(u8Channel == PIT_CH3)
			u8NvicEnableIrq(INT_PIT3 - 16);
	}
	
	//Enable selected PIT channel
	PIT_TCTRL_REG(PIT_BASE_PTR,u8Channel) |= PIT_TCTRL_TEN_MASK;
	
	return PIT_OK;
}

unsigned char u8PitDeinit (unsigned char u8Channel)
{
	if(u8Channel > PIT_CH3)
		return PIT_ERR;
	
	PIT_TCTRL_REG(PIT_BASE_PTR,u8Channel) = 0;
	
	return PIT_OK;
}

/********//*
 * @function	vfnPit0Isr
 * 
 * @description Interrupt service routine for PIT0
 * 
 * @input
 *  
 * @output
 * 
 * @warning	Function must be declared in the interrupt vector table prior use
 */
void vfnPit0Isr (void)
{
	PIT_TFLG0 |= PIT_TFLG_TIF_MASK;			//Clear interrupt flag
	PIT0_EVENT;							//Set PIT0 software flag
}

/********//*
 * @function	vfnPit1Isr
 * 
 * @description Interrupt service routine for PIT1
 * 
 * @input
 *  
 * @output
 * 
 * @warning	Function must be declared in the interrupt vector table prior use
 */
void vfnPit1Isr (void)
{
	PIT_TFLG1 |= PIT_TFLG_TIF_MASK;			//Clear interrupt flag
	PIT1_EVENT;							//Set PIT1 software flag
}

/********//*
 * @function	vfnPit2Isr
 * 
 * @description Interrupt service routine for PIT2
 * 
 * @input
 *  
 * @output
 * 
 * @warning	Function must be declared in the interrupt vector table prior use
 */
void vfnPit2Isr (void)
{
	PIT_TFLG2 |= PIT_TFLG_TIF_MASK;			//Clear interrupt flag
	PIT2_EVENT;							//Set PIT2 software flag
}

/********//*
 * @function	vfnPit3Isr
 * 
 * @description Interrupt service routine for PIT3
 * 
 * @input
 *  
 * @output
 * 
 * @warning	Function must be declared in the interrupt vector table prior use
 */
void vfnPit3Isr (void)
{
	PIT_TFLG3 |= PIT_TFLG_TIF_MASK;			//Clear interrupt flag
	PIT3_EVENT;							//Set PIT3 software flag
}