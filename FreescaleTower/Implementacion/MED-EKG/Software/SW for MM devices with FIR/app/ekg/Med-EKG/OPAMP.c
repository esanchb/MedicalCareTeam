#include "OPAMP.h"




//connect function generator output to INPx- and the same DC offset as INPx- to INPx+, this will remove the DC offset at output
void opamp1_gp_mode(void)
{
	GPAMP1C2_AMPPSEL = 0b000;	//positive select is INP0+
	GPAMP1C2_AMPNSEL = 0b000;	//positive select is INP0-
	GPAMP1C0_LPEN = 0b0;	//high speed mode
	GPAMP1C0_MODE = 0b10;	//general purpose AMP mode
	GPAMP1C0_GPAMPEN = 0b1;	//enable OPAMP

}

void opamp2_gp_mode(void)
{
	
	GPAMP2C2_AMPPSEL = 0b000;	//positive select is INP1+
	GPAMP2C2_AMPNSEL = 0b000;	//negative select is INP1-
	GPAMP2C0_LPEN = 0b0;	//high speed mode
	GPAMP2C0_MODE = 0b10;	//general purpose AMP mode
	GPAMP2C0_GPAMPEN = 0b1;	//enable OPAMP
}

 void TRIAMP1C0_HighMode(void) {
TIAMP1C0 = 0x80 ; // High power Mode
}


  void TRIAMP2C0_HighMode(void) {
TIAMP2C0 = 0x80 ; // High power Mode
}
 
 void opamp1_noninverting_mode(byte gain){
  

 GPAMP1C2_AMPPSEL = 0b000;	//positive select is INP0+
 //GPAMP1C2_AMPNSEL = 0b111;	//positive select is GND
 GPAMP1C2_AMPPSEL = 0b000;	//positive select is INP0-
	
	
	GPAMP1C0_LPEN = 0b0;	//high speed mode
	GPAMP1C0_MODE = 0b11;	//noninverting PGA mode
	GPAMP1C0_GPAMPEN = 0b1;	//enable OPAMP
	

	GPAMP1C1	=  gain;
	
	//GPAMP1C0_GPAMPEN = 0b0;	//disable OPAMP
 }


  void opamp2_noninverting_mode(byte gain){
  

 GPAMP2C2_AMPPSEL = 0b000;	//positive select is INP0+
 //GPAMP1C2_AMPNSEL = 0b111;	//positive select is GND
 GPAMP2C2_AMPPSEL = 0b000;	//positive select is INP0-
	
	
	GPAMP2C0_LPEN = 0b0;	//high speed mode
	GPAMP2C0_MODE = 0b11;	//noninverting PGA mode
	GPAMP2C0_GPAMPEN = 0b1;	//enable OPAMP
	

	GPAMP2C1	=  gain;
	
	//GPAMP1C0_GPAMPEN = 0b0;	//disable OPAMP
 }
