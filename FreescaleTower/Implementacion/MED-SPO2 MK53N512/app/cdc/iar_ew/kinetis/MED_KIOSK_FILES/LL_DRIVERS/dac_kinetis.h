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
 * @file dac_kinetis.h
 *
 * @author  
 *
 * @version 1.0
 *
 * @date Feb-09-2013
 *
 * @brief DAC functions for Kinetis microcontrollers
 * 
 * @ToDo Interrupt support
 *
 *****************************************************************************/

#ifndef DAC_KINETIS_H_
#define DAC_KINETIS_H_

/*****************************************************************************
 * Type definitions
 ****************************************************************************/
typedef struct{
	DAC_MemMapPtr DacModule;					//Mandatory DAC module to use (i.e. DAC0)
	unsigned char u8DacRefvTrigPowermode;		//Mandatory DAC Vref, Trigger and power mode (see lists below)
	unsigned char u8DacIntEn;					//Optional Enable selected interrupts (See interrupts available below. Separate interrupts with OR "|")
	unsigned char u8DacDmaBufferenBuffermode;   //Optional enable DMA, buffer and select buffer mode
	unsigned char u8DacBufferWms;				//Optional watermark select for buffer mode (see list below)
	unsigned char u8DacBufferUp;				//Optional upper limit value for buffer
}tDAC_CONFIG;

/*****************************************************************************
 * User definitions
 ****************************************************************************/
/********************** General **********************/
#define DAC_OK	0
#define DAC_ERR 1

/********************** DacModule Options *********************/ 
//DAC modules
#define DAC0	DAC0_BASE_PTR
#define DAC1	DAC1_BASE_PTR

/********************** u8DacRefvTrigPowermode Options *********************/ 
//Reference voltages
#define DACREF_1	(0<<DAC_C0_DACRFS_SHIFT)
#define DACREF_2	(1<<DAC_C0_DACRFS_SHIFT)

//Trigger options
#define DAC_HW_TRIGGER	(0<<DAC_C0_DACTRGSEL_SHIFT)
#define DAC_SW_TRIGGER	(1<<DAC_C0_DACTRGSEL_SHIFT)

//Power modes
#define DAC_HIGH_POWER	(0<<DAC_C0_LPEN_SHIFT)
#define DAC_LOW_POWER	(1<<DAC_C0_LPEN_SHIFT)

/********************** u8DacIntEn Options *********************/ 
//Interrupts available
#define DAC_WATERMARK_INT		(1<<DAC_C0_DACBWIEN_SHIFT)
#define DAC_POINTER_TOP_INT		(1<<DAC_C0_DACBTIEN_SHIFT)
#define DAC_POINTER_BOT_INT		(1<<DAC_C0_DACBBIEN_SHIFT)

/********************** u8DacDmaBufferenBuffermode Options *********************/ 
//DMA
#define DAC_DMA_DIS		(0<<DAC_C1_DMAEN_SHIFT)
#define DAC_DMA_EN		(1<<DAC_C1_DMAEN_SHIFT)

//Buffer
#define DAC_BUFFER_DIS		(0<<DAC_C1_DACBFEN_SHIFT)
#define DAC_BUFFER_EN		(1<<DAC_C1_DACBFEN_SHIFT)

//Buffer modes
#define DAC_BUFFER_NORMAL		(DAC_C1_DACBFMD(0))
#define DAC_BUFFER_SWING		(DAC_C1_DACBFMD(1))
#define DAC_BUFFER_ONETIMESCAN	(DAC_C1_DACBFMD(2))

/********************** u8DacBufferWms Options *********************/ 
//Watermark options
#define DAC_WTRM_1WORD		(DAC_C1_DACBFWM(0))
#define DAC_WTRM_2WORD		(DAC_C1_DACBFWM(1))
#define DAC_WTRM_3WORD		(DAC_C1_DACBFWM(2))
#define DAC_WTRM_4WORD		(DAC_C1_DACBFWM(3))

/*****************************************************************************
 * Function prototypes
 ****************************************************************************/
void vfnDacInit(tDAC_CONFIG DacCfg);
unsigned char u8DacLoadVal(DAC_MemMapPtr Module, unsigned short u16Value, unsigned char u8Index);
unsigned char u8DacLoadBuff (DAC_MemMapPtr Module, unsigned short* pBuffer, unsigned char u8Size);
void vfnDacSwTrigger(DAC_MemMapPtr Module);
void vfnDacDeinit(DAC_MemMapPtr Module);


#endif /* DAC_KINETIS_H_ */
