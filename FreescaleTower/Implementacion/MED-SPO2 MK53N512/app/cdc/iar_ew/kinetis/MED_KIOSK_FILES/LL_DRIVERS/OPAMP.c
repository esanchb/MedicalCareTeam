#include "OPAMP.h"

//****************************************************************************/
//                           OPAMP/TRIAMP DRIVERS
//                             FOR KINETIS K50
//                 
//                        !* Preliminary Version
//****************************************************************************/

/*****************************************************************************
*                                   Globals
******************************************************************************/
const UINT8 AmpGain[] = 
{
 Gain2,
 Gain3,
 Gain4,
 Gain5,
 Gain6,
 Gain7,
 Gain8,
 Gain9,
 Gain10,
 Gain11,
 Gain12,
 Gain13,
 Gain14,
 Gain15,
 Gain16,
 Gain17,
 Gain18
};


//connect function generator output to INPx- and the same DC offset as INPx- to INPx+, this will remove the DC offset at output
void opamp1_gp_mode(void)
{
	ENABLE_OPAMPS;
  
        OPAMP0_C2 = (OPAMP_C2_AMPPSEL(0) | OPAMP_C2_AMPNSEL(0));  // Positive input INP1+ ; Negative Input INP- 
        OPAMP0_C0 = (OPAMP_C0_EN_MASK | OPAMP_C0_MODE(2)); //General Purpose OPAMP; OPAMP Enabled
        
       /* Refer to Reference Manual for more information */

}

void opamp2_gp_mode(void)
{
	ENABLE_OPAMPS;
  
        OPAMP1_C2 = (OPAMP_C2_AMPPSEL(0) | OPAMP_C2_AMPNSEL(0));  // Positive input INP1+ ; Negative Input INP- 
        OPAMP1_C0 = (OPAMP_C0_EN_MASK | OPAMP_C0_MODE(2)); //General Purpose OPAMP; OPAMP Enabled
        
       /* Refer to Reference Manual for more information */
}

 void TRIAMP1C0_HighMode(void)
 {
   ENABLE_TRIAMPS;
   TRIAMP0_C0 = TRIAMP_C0_TRIAMPEN_MASK; // High power Mode
 }


 void TRIAMP2C0_HighMode(void) 
 {
  ENABLE_TRIAMPS; 
  TRIAMP1_C0 = TRIAMP_C0_TRIAMPEN_MASK; // High power Mode
 }
 
 void opamp1_noninverting_mode(unsigned char gain){
   
   OPAMP0_C1 = gain;     //Set Gain
   OPAMP0_C2 = (OPAMP_C2_AMPPSEL(0) | OPAMP_C2_AMPNSEL(0));  // Positive input INP1+ ; Negative Input INP- 
   OPAMP0_C0 = (OPAMP_C0_EN_MASK | OPAMP_C0_MODE(3)); //Non-Inverting PGA ; OPAMP Enabled
   
   /* Refer to Reference Manual for more information */
 }


  void opamp2_noninverting_mode(unsigned char gain){
  
   OPAMP1_C1 = gain;     //Set Gain
   OPAMP1_C2 = (OPAMP_C2_AMPPSEL(0) | OPAMP_C2_AMPNSEL(0));  // Positive input INP1+ ; Negative Input INP- 
   OPAMP1_C0 = (OPAMP_C0_EN_MASK | OPAMP_C0_MODE(3)); //Non-Inverting PGA ; OPAMP Enabled
   
   /* Refer to Reference Manual for more information */
 }

 void vfnDisable_All_Operationals (void)
 {
  OPAMP0_C0 = 0;
  OPAMP1_C0 = 0;
  TRIAMP0_C0 = 0;
  TRIAMP1_C0 = 0;
 }

void opamp0_buffer_highspeed_mode(void)
{
	ENABLE_OPAMPS;
        OPAMP0_C2 = (OPAMP_C2_AMPPSEL(0) | OPAMP_C2_AMPNSEL(0));  // Positive input INP1+ ; Negative Input INP- 
        OPAMP0_C0 = (OPAMP_C0_EN_MASK | OPAMP_C0_MODE(0)); //OPAMP Enabled; Buffer mode
}