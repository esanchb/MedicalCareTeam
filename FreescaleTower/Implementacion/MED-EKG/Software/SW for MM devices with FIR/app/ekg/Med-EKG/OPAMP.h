#ifndef _OPAMP
#define _OPAMP


#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "PublicTypes.h"

	#define Gain4       0x04
	#define Gain6       0x08
	#define Gain9       0x0C
	#define Gain13      0x10
	
	#define Gain17      0x14
	#define Gain2       0x05
	#define Gain3       0x09
	#define Gain4half   0x0D
	#define Gain6half   0x11
	#define Gain8half   0x15

void opamp1_gp_mode(void) ;
void opamp2_gp_mode(void) ;

void TRIAMP1C0_HighMode(void);
void TRIAMP2C0_HighMode(void);

void opamp1_noninverting_mode(byte gain);
void opamp2_noninverting_mode(byte gain);


#endif //_ADC