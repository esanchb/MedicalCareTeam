#ifndef __HWT
#define __HWT

#include "derivative.h" /* include peripheral declarations */
#include "PublicTypes.h"


#define sda      PTGD_PTGD0
#define scl      PTGD_PTGD1

#define sdadir   PTGDD_PTGDD0
#define scldir   PTGDD_PTGDD1

#define pu_sda   PTGPE_PTGPE0

#define	ADC_WEIGHT_CHANNEL	7

#define HWT_BOARD_ENABLE_PIN		PTED_PTED2
#define HWT_BOARD_ENABLE_PIN_DD		PTEDD_PTEDD2

#define HWT_ENABLE_BOARD()		HWT_BOARD_ENABLE_PIN = 0	
#define HWT_DISABLE_BOARD()		HWT_BOARD_ENABLE_PIN = 1


extern UINT8 Hwt_Height;
extern UINT8 Hwt_Weight;
extern UINT16 Hwt_Temperature;

void Hwt_StartReadingTemperature(void);
void Hwt_StartReadingWeight(void);
void Hwt_StartReadingHeight(void);
void Hwt_Init(void);
void Hwt_PeriodicTask(void);

void Hwt_StopReadingTemperature(void);
void Hwt_StopReadingHeight(void);
void Hwt_StopReadingWeight(void);


extern const pFunc_t Hwt_Events[];


#endif

