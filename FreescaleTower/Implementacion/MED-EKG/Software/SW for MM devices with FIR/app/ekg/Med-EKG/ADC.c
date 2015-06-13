#include "ADC.h"

void ADC_Init12b(UINT16 activeChannelsMask)
{
/*
    ADCCFG_MODE = 0b01; //12 bit conversion mode
  	ADCSC2 = 0x00;
  	ADCSC1 = ADCSC1_ADCH_MASK;	//disable channels
    APCTL1 = activeChannelsMask & 0x00FF;
    APCTL2 = activeChannelsMask >> 8;
*/
}


void ADC_Init8b(UINT16 activeChannelsMask)
{
/*    ADCCFG_MODE = 0b00; //8 bit conversion mode
  	ADCSC2 = 0x00;
  	ADCSC1 = ADCSC1_ADCH_MASK;
    APCTL1 = activeChannelsMask & 0x00FF;
    APCTL2 = activeChannelsMask >> 8;
*/
}


void ADC_Init16b(UINT16 activeChannelsMask)
{
	ADCCFG1_MODE = 0b11;	//16bit mode
	ADCSC1A = ADCSC1A_ADCHA;	//disable module
	APCTL1 = activeChannelsMask & 0x00FF;
	APCTL2 = activeChannelsMask >> 8;

/*
	Insert code here to enable ADC in 16-bit mode conversion
	Enable channels passed by activeChannelsMask parameter
*/
}


UINT16 ADC_Read16b(UINT8 channelNumber)
{
	//insert code to read ADC
	ADCSC1A = channelNumber & ADCSC1A_ADCHA_MASK;	/* Write to ADCSC1 to start conversion */
	while (ADCSC2_ADACT == 1); 				  	/* Wait if the conversion is in progress */
	while (ADCSC1A_COCOA == 0); 					/* Wait until the conversion is complete */
	return ADCRA; 
}



UINT16 ADC_Read12b(UINT8 channelNumber)
{
//	ADCSC1 = channelNumber & ADCSC1_ADCH_MASK;	/* Write to ADCSC1 to start conversion */
//	while (ADCSC2_ADACT == 1); 				  	/* Wait if the conversion is in progress */
//	while (ADCSC1_COCO == 0); 					/* Wait until the conversion is complete */
//	return ADCR; /* */
}


UINT8 ADC_Read8b(UINT8 channelNumber)
{
/*
	ADCSC1 = channelNumber & ADCSC1_ADCH_MASK;	// Write to ADCSC1 to start conversion
	while (ADCSC2_ADACT == 1); 				  	// Wait if the conversion is in progress
	while (ADCSC1_COCO == 0); 					// Wait until the conversion is complete 
	return ADCRL;
	*/
}
