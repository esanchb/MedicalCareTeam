/*****************************************************************
*                          Header Files
*****************************************************************/
#include "MM_Timers.h"


/*****************************************************************
*                           Definitions
*****************************************************************/



/*****************************************************************
*                             Globals
*****************************************************************/

 UINT8 u8Tpm1Ch0Flag = FALSE;

/*****************************************************************
*                       Function Prototypes
*****************************************************************/

void vfnTPM1_CH0_Init(void)
  {
   TPM1C0SC = 0x50; //Output Compare Mode
   TPM1C0V = TPM1CH0_MODULO;
   TPM1SC = 0x0D; //Bus clock, Preescaler 32, Enabled
  }
/******************************************************************/  
  
void vfnTPM1_CH0_Deinit(void)
  {
   TPM1SC = 0;
  }
/******************************************************************/  
interrupt VectorNumber_Vtpm1ch0 void TPM1_CH0_ISR (void)
  {
   TPM1C0SC;//Dummy Read
   TPM1C0SC_CH0F = 0; //Clear Flag
   TPM1C0V += TPM1CH0_MODULO;
   u8Tpm1Ch0Flag = TRUE;
   
   Sample_number++; //Needed by HeartRate.h each 1mS
   msOccured++;     //Needed by HeartRate.h each 1mS
  }