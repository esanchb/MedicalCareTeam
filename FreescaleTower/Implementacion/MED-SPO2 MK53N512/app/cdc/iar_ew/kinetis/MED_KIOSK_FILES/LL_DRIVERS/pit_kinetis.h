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
 * @file pit_kinetis.h
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

#ifndef PIT_KINETIS_H_
#define PIT_KINETIS_H_

/******
 * Header Files
 */
#include "derivative.h"

/******
 * Globals
 */
extern unsigned char u8PitIrqFlag;

/******
 * User definitions
 */
typedef enum{
	PIT_CH0,
	PIT_CH1,
	PIT_CH2,
	PIT_CH3
}PIT_CHANNEL_OPTIONS;

typedef enum{
	PIT_OK,
	PIT_ERR
}PIT_ERROR_STATUS;

/* Interrupt Flags */
#define PIT0_INTERRUPT			(u8PitIrqFlag & (1<<0))
#define PIT0_EVENT		        u8PitIrqFlag |= (1<<0)
#define PIT0_CLEAR			u8PitIrqFlag &= ~(1<<0)

#define PIT1_INTERRUPT			(u8PitIrqFlag & (1<<1))
#define PIT1_EVENT			u8PitIrqFlag |= (1<<1)
#define PIT1_CLEAR			u8PitIrqFlag &= ~(1<<1)

#define PIT2_INTERRUPT			(u8PitIrqFlag & (1<<2))
#define PIT2_EVENT			u8PitIrqFlag |= (1<<2)
#define PIT2_CLEAR			u8PitIrqFlag &= ~(1<<2)

#define PIT3_INTERRUPT			(u8PitIrqFlag & (1<<3))
#define PIT3_EVENT			u8PitIrqFlag |= (1<<3)
#define PIT3_CLEAR			u8PitIrqFlag &= ~(1<<3)

/******
 * Function prototypes
 */
unsigned char u8PitInit(unsigned char u8Channel, unsigned char u8IntEn, unsigned int u32Modulo);
unsigned char u8PitDeinit (unsigned char u8Channel);
void vfnPit0Isr (void);
void vfnPit1Isr (void);
void vfnPit2Isr (void);
void vfnPit3Isr (void);

#endif /* PIT_KINETIS_H_ */
