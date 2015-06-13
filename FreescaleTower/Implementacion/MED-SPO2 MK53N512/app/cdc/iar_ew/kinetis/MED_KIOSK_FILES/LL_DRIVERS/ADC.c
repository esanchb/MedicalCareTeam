#include "ADC.h"

//****************************************************************************/
//                               ADC DRIVERS
//                             FOR KINETIS K50
//****************************************************************************/

void ADC0_Init12b(void)
{
  SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;

  ADC0_CFG1 = (ADC_CFG1_MODE(1) | ADC_CFG1_ADIV(2));
  ADC0_SC1A = ADC_SC1_ADCH(31); //disable module
}


void ADC1_Init12b (void)
{
  SIM_SCGC3 |= SIM_SCGC3_ADC1_MASK;
  
  ADC1_CFG1 = (ADC_CFG1_MODE(1) | ADC_CFG1_ADIV(2));
  ADC1_SC1A = ADC_SC1_ADCH(31); //disable module
}


void ADC0_Init8b(void)
{
  SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
  
  ADC0_CFG1 = (ADC_CFG1_MODE(0) | ADC_CFG1_ADIV(2));
  ADC0_SC1A = ADC_SC1_ADCH(31); //disable module
}

void ADC1_Init8b(void)
{
  SIM_SCGC3 |= SIM_SCGC3_ADC1_MASK;
  
  ADC1_CFG1 = (ADC_CFG1_MODE(0) | ADC_CFG1_ADIV(2));
  ADC1_SC1A = ADC_SC1_ADCH(31); //disable module
}


void ADC0_Init16b(void)
{
        SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK; //Gives clock to ADC0
	
        ADC0_CFG1 = (ADC_CFG1_MODE(3) | ADC_CFG1_ADIV(2)); //16bit mode
	ADC0_SC1A = ADC_SC1_ADCH(31); //disable module

        /* Configure ADC pins as ADC Inputs manually */
        
        /*In Kinetis the ADC pins are ADC inputs by default */
        
}

void ADC1_Init16b(void)
{
        SIM_SCGC3 |= SIM_SCGC3_ADC1_MASK; //Gives clock to ADC0
	
        ADC1_CFG1 = (ADC_CFG1_MODE(3) | ADC_CFG1_ADIV(2)); //16bit mode
	ADC1_SC1A = ADC_SC1_ADCH(31); //disable module

        /* Configure ADC pins as ADC Inputs manually */
        
        /*In Kinetis the ADC pins are ADC inputs by default */
               
}


UINT16 ADC0_Read16b(UINT8 channelNumber)
{
	ADC0_SC1A = channelNumber & ADC_SC1_ADCH_MASK;	                /* Write to ADCSC1 to start conversion */
	while ((ADC0_SC2 & 0x80)); 				  	/* Wait if the conversion is in progress */
	while (!(ADC0_SC1A & 0x80)); 					/* Wait until the conversion is complete */
	return ADC0_RA; 
}

UINT16 ADC1_Read16b(UINT8 channelNumber)
{
	ADC1_SC1A = channelNumber & ADC_SC1_ADCH_MASK;	                /* Write to ADCSC1 to start conversion */
	while ((ADC1_SC2 & 0x80)); 				  	/* Wait if the conversion is in progress */
	while (!(ADC1_SC1A & 0x80)); 					/* Wait until the conversion is complete */
	return ADC1_RA; 
}


UINT16 ADC0_Read12b(UINT8 channelNumber)
{
        ADC0_SC1A = channelNumber & ADC_SC1_ADCH_MASK;
        while ((ADC0_SC2 & 0x80));
        while (!(ADC0_SC1A & 0x80));
        return ADC0_RA;
}

UINT16 ADC1_Read12b(UINT8 channelNumber)
{
        ADC1_SC1A = channelNumber & ADC_SC1_ADCH_MASK;	
        while ((ADC1_SC2 & 0x80));
        while (!(ADC1_SC1A & 0x80));
        return ADC1_RA;          
}


UINT8 ADC0_Read8b(UINT8 channelNumber)
{
        ADC0_SC1A = channelNumber & ADC_SC1_ADCH_MASK;
        while ((ADC0_SC2 & 0x80));
        while (!(ADC0_SC1A & 0x80));
        return (UINT8)(ADC0_RA);
}

UINT8 ADC1_Read8b(UINT8 channelNumber)
{
        ADC1_SC1A = channelNumber & ADC_SC1_ADCH_MASK;	
        while ((ADC1_SC2 & 0x80));
        while (!(ADC1_SC1A & 0x80));
        return (UINT8)(ADC1_RA);  
}