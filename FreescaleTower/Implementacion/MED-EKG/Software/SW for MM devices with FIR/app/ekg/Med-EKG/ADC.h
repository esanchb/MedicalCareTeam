#ifndef _ADC
#define _ADC


#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "PublicTypes.h"


#define ADC_ENABLE()        ATD1C = ATD1C_ATDPU_MASK|ATD1C_DJM_MASK
#define ADC_DISABLE()       ATD1C = 0

#define START_CONVERSION(channel)    ATD1SC_ATDCH = channel;


void ADC_Init8b(UINT16 activeChannelsMask);
void ADC_Init12b(UINT16 activeChannelsMask);
void ADC_Init16b(UINT16 activeChannelsMask);


UINT8 ADC_Read8b(UINT8 channelNumber);
UINT16 ADC_Read12b(UINT8 channelNumber);
UINT16 ADC_Read16b(UINT8 channelNumber);






#endif //_ADC