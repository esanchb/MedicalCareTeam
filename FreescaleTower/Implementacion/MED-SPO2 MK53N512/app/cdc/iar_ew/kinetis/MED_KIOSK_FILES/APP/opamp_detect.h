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
* @file: opamp_detect.h
* 
* @author : 
*
* @version: 1.0
*
* @description: OpAmp detection functions for Analog Front End units
******************************************************************************/

#ifndef _OPAMP_DETECT_H_
#define _OPAMP_DETECT_H_

/*****************************************************************************
* Header files
*****************************************************************************/
#include "derivative.h"
#include "ADC.h"
#include "TWR_K50_UI.h"
#include "lptmr.h"
#include "dac_kinetis.h"
#include "OPAMP.h"

/****************************************************************************
* User definitions
****************************************************************************/
#define OPAMPS_NOT_PRESENT      0
#define OPAMPS_PRESENT          1

#define ADC_REFV_mV		3300
#define _1_mV			(65535/ADC_REFV_mV)

/****************************************************************************
* Function definition
****************************************************************************/
unsigned char u8OpCheckGlu (void);
unsigned char u8OpCheckSpo2 (void);
unsigned char u8OpCheckBpm (void);

#endif
/* End Of File */