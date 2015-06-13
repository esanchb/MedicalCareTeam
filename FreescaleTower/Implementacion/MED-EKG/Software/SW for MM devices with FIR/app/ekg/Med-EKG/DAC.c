#include "DAC.h"




void DAC12_Vin_SWtrig(void)  {
//Reference source selection = 0

DACC0 = (
 !DACC0_DACBIE_MASK  | // DACBIE =0 , buffer read pointer  bottom flag interrupt is disabled             
 !DACC0_DACTIE_MASK  | // DACTIE = 0 ,buffer read pointer top flag interrupt is disabled            
 !DACC0_DACWIE_MASK  | // DACWIE = 0, buffer water mark interrupt disabled            
 !DACC0_LPEN_MASK    | // LPEN = 0, low power mode            
 !DACC0_DACSTRG_MASK | // ?            
  DACC0_DACTSEL_MASK | //DACTSEL =1, Databuffer outputs to DACO pin whenever a write to DACDAT0     
  DACC0_DACRFS_MASK  |          
  DACC0_DACEN_MASK     //DAC enalbed
 );  


DACC0_DACRFS = 1 ;//DACRFS = 1, Vin = =Vext = VDDA    

//DACC0_DACRFS = 0 ;//DACRFS = 0, Vin = vint = VREFO   

//VREFSC = 0x81 ;// Enable Vrefo and select internal mode
VREFSC = 0x82; // Tight-regulation mode buffer enabled is reconmended over low buffered mode
while (!VREFSC_VREFST  ){} // wait till the VREFSC is stable


DACC1 = ( 
 !DACC1_DACBFE_MASK   |  // Buffer read pointer is disabled, converted data is always the first word of buffer = DACCCDAT0            
 !DACC1_DACBFMD0_MASK |             
 !DACC1_DACBFMD1_MASK |             
 !DACC1_DACBFWM0_MASK |           
 !DACC1_DACBFWM1_MASK             
  ) ;

DACC2 = 0x0F;

 DACDAT0 = 2047;// base from 3.3 ext referece voltage, to get 1.6V output
 
   //DACDAT0 = 1905;// base from 3.3 ext referece voltage, to get 1.5V output
   //DACDAT0 = 620;// base from 3.3 ext referece voltage, to get 0.5V output
   //DACDAT0 = 320;// base from 3.3 ext referece voltage, to get xx output
}
