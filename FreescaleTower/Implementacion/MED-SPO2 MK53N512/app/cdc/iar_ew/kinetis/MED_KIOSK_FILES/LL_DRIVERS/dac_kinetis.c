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
 * @file dac_kinetis.c
 *
 * @author  
 *
 * @version 1.0
 *
 * @date Feb-09-2013
 *
 * @brief DAC functions for Kinetis microcontrollers
 *
 *****************************************************************************/

/*****************************************************************************
 * Header files
 ****************************************************************************/
#include "derivative.h"
#include "dac_kinetis.h"

/*****************************************************************************
 * Functions
 ****************************************************************************/
void vfnDacInit(tDAC_CONFIG DacCfg)
{
	if(DacCfg.DacModule == DAC0)
		SIM_SCGC2 |= SIM_SCGC2_DAC0_MASK;
		//TODO Enable IRQ
	
	if(DacCfg.DacModule == DAC1)
		SIM_SCGC2 |= SIM_SCGC2_DAC1_MASK;
		//TODO Enable IRQ
	
	DAC_C0_REG(DacCfg.DacModule) = DacCfg.u8DacRefvTrigPowermode;
	DAC_C0_REG(DacCfg.DacModule) |= DacCfg.u8DacIntEn;
	
	DAC_C1_REG(DacCfg.DacModule) = DacCfg.u8DacDmaBufferenBuffermode;
	
	if(DacCfg.u8DacDmaBufferenBuffermode & (1<<DAC_C1_DACBFEN_SHIFT))
	{
		DAC_C1_REG(DacCfg.DacModule)|= DacCfg.u8DacBufferWms;
		
		if(DacCfg.u8DacBufferUp != 0)
		DAC_C2_REG(DacCfg.DacModule) = DacCfg.u8DacBufferUp;
	}
	
	DAC_C0_REG(DacCfg.DacModule) |= DAC_C0_DACEN_MASK;
}

/******************************************************************************/
unsigned char u8DacLoadVal(DAC_MemMapPtr Module, unsigned short u16Value, unsigned char u8Index)
{
	if(u8Index > 15)
		return DAC_ERR;
	
	if(u16Value > 4095)
		return DAC_ERR;
	
	DAC_DATL_REG(Module,u8Index) = ((unsigned char)(u16Value & 0x00FFu));
	DAC_DATH_REG(Module,u8Index) = ((unsigned char)((u16Value & 0xFF00u) >> 0x08u));
	
	return DAC_OK;
}

/******************************************************************************/
unsigned char u8DacLoadBuff (DAC_MemMapPtr Module, unsigned short* pBuffer, unsigned char u8Size)
{
	unsigned char u8ErrReport;
	unsigned char u8Index;
	
	if(u8Size > 16)
		return DAC_ERR;
	
	for(u8Index = 0; u8Index < u8Size; u8Index++)
	{
		u8ErrReport = u8DacLoadVal(Module, *pBuffer, u8Index);
		pBuffer++;
		
		if(u8ErrReport == DAC_ERR)
			return DAC_ERR;
	}
	
	return DAC_OK;
}

/*******************************************************************************/
void vfnDacSwTrigger(DAC_MemMapPtr Module)
{
	DAC_C0_REG(Module) |= DAC_C0_DACSWTRG_MASK;
}

/******************************************************************************/
void vfnDacDeinit(DAC_MemMapPtr Module)
{
	if(Module == DAC0)
		SIM_SCGC2 |= SIM_SCGC2_DAC0_MASK;
		
	if(Module == DAC1)
		SIM_SCGC2 |= SIM_SCGC2_DAC1_MASK;
	
	DAC_C0_REG(Module) = 0x00u;
	DAC_C1_REG(Module) = 0x00u;
	DAC_C2_REG(Module) = 0x0Fu;
	
	if(Module == DAC0)
		SIM_SCGC2 &= ~SIM_SCGC2_DAC0_MASK;
		//TODO Disable IRQ
		
	if(Module == DAC1)
		SIM_SCGC2 &= ~SIM_SCGC2_DAC1_MASK;
		//TODO Disable IRQ
}