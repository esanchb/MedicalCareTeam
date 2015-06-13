#ifndef _ADC
#define _ADC

#include "derivative.h" /* include peripheral declarations */
#include "PublicTypes.h"





void ADC0_Init8b(void);
void ADC1_Init8b(void);
void ADC0_Init12b(void);
void ADC1_Init12b(void);
void ADC0_Init16b(void);
void ADC1_Init16b(void);


UINT8 ADC0_Read8b(UINT8 channelNumber);
UINT8 ADC1_Read8b(UINT8 channelNumber);
UINT16 ADC0_Read12b(UINT8 channelNumber);
UINT16 ADC1_Read12b(UINT8 channelNumber);
UINT16 ADC0_Read16b(UINT8 channelNumber);
UINT16 ADC1_Read16b(UINT8 channelNumber);






#endif //_ADC