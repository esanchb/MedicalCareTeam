#ifndef MM_TIMERS
#define MM_TIMERS

/*****************************************************************
*                          Header Files
*****************************************************************/
#include "derivative.h"
#include "PublicTypes.h"
#include "HeartRate.h"

/*****************************************************************
*                           Definitions
*****************************************************************/

#define TPM1CH0_MODULO      750 //1mS 24Mhz Bus, 32 Prescaler

/*****************************************************************
*                             Globals
*****************************************************************/

extern UINT8 u8Tpm1Ch0Flag;

/*****************************************************************
*                       Function Prototypes
*****************************************************************/

extern void vfnTPM1_CH0_Init(void);
extern void vfnTPM1_CH0_Deinit(void);
void TPM1_CH0_ISR (void);

#endif