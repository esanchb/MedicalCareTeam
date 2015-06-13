/******************************************************************************
*                            Freescale Semiconductor
*
* Name: Main_App.c
*
* Description: Main application routines
*
* MCU: MK53N512CMD100
*
* Version for IAR 6.4
*******************************************************************************/

/******************************************************************************
*                               Header Files
******************************************************************************/
#include "Main_App.h"

/******************************************************************************
*                                 Definitions
******************************************************************************/
#define SPO2_MEASUREMENT        0x09u

/******************************************************************************
*                                   Structs
******************************************************************************/

/******************************************************************************
*                                   Locals
******************************************************************************/
/* Virtual COM Application start Init Flag */
static volatile boolean start_app = FALSE;
/* Virtual COM Application Carrier Activate Flag */
static volatile boolean start_transactions = FALSE;
/* Receive Buffer */
static uint_8 g_curr_recv_buf[DATA_BUFF_SIZE];
/* Send Buffer */
static uint_8 g_curr_send_buf[DATA_BUFF_SIZE];
/* Receive Data Size */
static uint_8 g_recv_size;
/* Send Data Size */
static uint_8 g_send_size;



UINT8 InBuffer[32];	//From the PC to the MCU
UINT8 OutBuffer[128];	//From the MCU to the PC
UINT8 OutSize;
UINT8 InSize;

UINT16 IdNumber = 0;
UINT8 MainActualState;

UINT8 TimerSendDummyData;

void TimerSendDummyData_Event(void);
void EnableAFE(UINT8 measurementId);

/*****************************************************************************
*                             Function definitions
******************************************************************************/

static void USB_App_Callback(uint_8 controller_ID,
                        uint_8 event_type, void* val);
static void USB_Notify_Callback(uint_8 controller_ID,
                        uint_8 event_type, void* val);

/* Applications*/
void TestApp_Init(void);
void TestApp_Task(void);

/* AFEs functions */
void vfnEnable_AFE (void);
void vfnDisable_AFE (void);

/* SpO2 */
void SpO2StartMeasurementReq(void);
void SpO2AbortMeasurementReq(void);
void SpO2MeasurementCompleteOkInd(void);
void SpO2MeasurementErrorInd(void);


void SpO2DiagnosticModeStartMeasurementReq(void);
void SpO2DiagnosticModeStopMeasurementReq(void);
void SpO2NewDataReadyInd(void);
void SpO2DebugModeNewDataReadyInd(void);

/* Serial comm */
void SerialComm_PeriodicTask(void);
void SerialComm_SendData(void);

const pFunc_t SpO2_Events[] = 
{
	NULL,							//SPO2_EVENT_NONE,
	SpO2MeasurementCompleteOkInd, 	//SPO2_EVENT_MEASUREMENT_COMPLETE_OK,
	SpO2MeasurementErrorInd,			//SPO2_EVENT_MEASUREMENT_ERROR,
	SpO2NewDataReadyInd,				//SPO2_EVENT_NEW_DATA_READY
	SpO2DebugModeNewDataReadyInd		//SPO2_EVENT_DEBUG_MODE_NEW_DATA_READY
};

const pFunc_t ExecuteCommandReq[] =
{
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	
	NULL,
	NULL,
	NULL,
	NULL,
		
	NULL,
	NULL,
	NULL,
	
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	
	NULL,
	NULL,
	NULL,
		
	NULL,
	NULL,
	NULL,

	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
		
	SpO2StartMeasurementReq,				//SPO2_START_MEASUREMENT,
	SpO2AbortMeasurementReq,				//SPO2_ABORT_MEASURMENT,
	NULL,							//SPO2_MEASURMENT_COMPLETE_OK,
	NULL,							//SPO2_MEASURMENT_ERROR,

	SpO2DiagnosticModeStartMeasurementReq,                  //SPO2_DIAGNOSTIC_MODE_START_MEASURMENT,
	SpO2DiagnosticModeStopMeasurementReq,                   //SPO2_DIAGNOSTIC_MODE_STOP_MEASURMENT,
	NULL,	
	NULL,	
	NULL,	
	NULL	
};

/*******************************************************************************
*                                Functions
********************************************************************************/



void TestApp_Init(void) 
{       
    uint_8   error; 

    /* AFIs Init */  
    GPIOS_CLOCK_INIT //Enables all GPIOs  
    vfnEnable_AFE(); //Enable Medical Connector 
    SwTimer_Init();
  
    /* Board UI initialization */
    LED1_INIT
    LED2_INIT
      
    LED1_ON
     
    g_recv_size = 0;
    g_send_size= 0;
    DisableInterrupts;		

    /* Initialize the USB interface */
    error = USB_Class_CDC_Init(CONTROLLER_ID,USB_App_Callback,
                                NULL,USB_Notify_Callback);
    if(error != USB_OK)
    {
        /* Error initializing USB-CDC Class */
        return;
    }
    EnableInterrupts;

}

void TestApp_Task(void)
{
  SpO2_PeriodicTask();
	
  SwTimer_PeriodicTask();
  SerialComm_PeriodicTask();
//  MainStateMachine[MainActualState](); 
}
void SerialComm_PeriodicTask(void)
{	
  unsigned char u8BufferCounter;
  
		
  //if there is data, read it
  if(g_recv_size)
  {
   for (u8BufferCounter=0; u8BufferCounter<g_recv_size; u8BufferCounter++)
   {
     InBuffer[u8BufferCounter]=g_curr_recv_buf[u8BufferCounter]; 
   }
   InSize = g_recv_size;
   g_recv_size=0;
  }

  //if there is data, parse it and execute command
  if (InSize>0)
  {	
          //there is new data
          if (InBuffer[PACKET_TYPE] == REQ)
          {
                  if (ExecuteCommandReq[InBuffer[COMMAND_OPCODE]] != NULL)
                  {
                          //check if OPCCODE is in a valid range
//                          if ((InBuffer[COMMAND_OPCODE] <= LAST_COMMAND))
//                          {
                                  ExecuteCommandReq[InBuffer[COMMAND_OPCODE]]();
//                          }
                  }	
          }
          
          InSize = 0;
  }
}


void SerialComm_SendData(void)
{
  UINT8 i=0;
  
  if (OutSize>0)			
  {			
    g_send_size = OutSize;
    for(i=0;i<OutSize;i++)
    {
     g_curr_send_buf[i]=OutBuffer[i]; 
    }
    
    USB_Class_CDC_Interface_DIC_Send_Data(CONTROLLER_ID, &g_curr_send_buf[0],g_send_size);

    OutSize = 0;
  }
	
}

/******************************************************************************
*                             Pulse Oximeter
*******************************************************************************/
/**
	Starts a pulse oximetry test (not diagnostic mode) and sends a CFM
*/
void SpO2StartMeasurementReq(void)
{	
         vfnStartSPO2MeasurementEngine();
         vfnEnable_AFE();
		
        //execute command and send confirm
        OutBuffer[OutSize++] = CFM;
        OutBuffer[OutSize++] = SPO2_START_MEASUREMENT;
        OutBuffer[OutSize++] = 1;	//data bytes
        
        if (SpO2_StartMeasurement() == TRUE)
        {
                OutBuffer[OutSize++] = ERROR_OK;	
        }
        else
        {
                OutBuffer[OutSize++] = ERROR_BUSY;
        }
        
        (void)SerialComm_SendData();
}


/**
	Aborts a pulse oximetry test (not diagnostic mode) and sends a CFM
*/
void SpO2AbortMeasurementReq(void)
{		
      //execute command and send confirm
      OutBuffer[OutSize++] = CFM;
      OutBuffer[OutSize++] = SPO2_ABORT_MEASUREMENT;
      OutBuffer[OutSize++] = 0;	//data bytes

      //execute command here
      SpO2_AbortMeasurement();
      
      (void)SerialComm_SendData();
      vfnTurnOffMeasurementEngine();
      vfnDisable_AFE();
}


/**
	When the SPO2 measurement is complete, the MCU sends and IND to the host with the following data:
		- Oxygen saturation value
		- Heart rate
*/
void SpO2MeasurementCompleteOkInd(void)
{
		
      OutBuffer[OutSize++] = IND;
      OutBuffer[OutSize++] = SPO2_MEASUREMENT_COMPLETE_OK;
      OutBuffer[OutSize++] = 2;				//data bytes
      
      OutBuffer[OutSize++] = SpO2_SaturationValue;
      OutBuffer[OutSize++] = SpO2_HeartRate;
              
      (void)SerialComm_SendData();
      vfnTurnOffMeasurementEngine();
      vfnDisable_AFE();
}


/**
	This IND is sent to the host if the SPO2 measurement was not completed correctly
*/
void SpO2MeasurementErrorInd(void)
{		
      OutBuffer[OutSize++] = IND;
      OutBuffer[OutSize++] = SPO2_MEASUREMENT_ERROR;
      OutBuffer[OutSize++] = 0;
      (void)SerialComm_SendData();
}


/**
	Starts a pulse oximetry diagnostic test (graphical mode) and sends a CFM
*/
void SpO2DiagnosticModeStartMeasurementReq(void)
{
      vfnStartSPO2MeasurementEngine();
      vfnEnable_AFE();
      
      //execute command and send confirm
      OutBuffer[OutSize++] = CFM;
      OutBuffer[OutSize++] = SPO2_DIAGNOSTIC_MODE_START_MEASUREMENT;
      OutBuffer[OutSize++] = 1;	//data bytes
      
      if (SpO2_DiagnosticModeStartMeasurement() == TRUE)
      {
              OutBuffer[OutSize++] = ERROR_OK;	
      }
      else
      {
              OutBuffer[OutSize++] = ERROR_BUSY;
      }
      
      (void)SerialComm_SendData();		
}

/**
	Stops a pulse oximetry diagnostic test (graphical mode) and sends a CFM
*/
void SpO2DiagnosticModeStopMeasurementReq(void)
{		
  OutBuffer[OutSize++] = CFM;
  OutBuffer[OutSize++] = SPO2_DIAGNOSTIC_MODE_STOP_MEASUREMENT;
  OutBuffer[OutSize++] = 0;	//data bytes

  //execute command here
  SpO2_DiagnosticModeStopMeasurement();
  
  (void)SerialComm_SendData();
  vfnTurnOffMeasurementEngine();
  vfnDisable_AFE();
}


/**
	This IND is sent to the host when new data from the SPO2 graph is available.
	It sends the following:
		- 32 unsigned words containing the graph information
		- 1 byte containing current oxygen saturation value
		- 1 byte containing current heart rate value
*/
void SpO2NewDataReadyInd(void)
{
  static UINT16 SpO2PacketId = 0;
  UINT8 i;
  //copy SpO2Buffer to OutBuffer and send data
  OutBuffer[OutSize++] = IND;
  OutBuffer[OutSize++] = SPO2_DIAGNOSTIC_MODE_NEW_DATA_READY;
  OutBuffer[OutSize++] = SPO2_REAL_TIME_DATA_ARRAY_LENGTH + 4;	//packetId(2 bytes) + SpO2 data(64 bytes) + SpO2(1 bytes) + heart beat(1 bytes)
  
  OutBuffer[OutSize++] = (UINT8) (SpO2PacketId >> 8);
  OutBuffer[OutSize++] = (UINT8) (SpO2PacketId & 0x00FF);
  
  SpO2PacketId++;
                  
  for (i=0; i<SPO2_REAL_TIME_DATA_ARRAY_LENGTH; i++)
  {
          OutBuffer[OutSize++] = SpO2Graph[i];
  }
  
  OutBuffer[OutSize++] = SpO2_SaturationValue;	//SpO2
  OutBuffer[OutSize++] = SpO2_HeartRate;		//HR
  
  (void)SerialComm_SendData();

}

/**
	This is for debugging purposes only.It sends both IR and Red graphs to the host
*/
void SpO2DebugModeNewDataReadyInd(void)
{
	
  static UINT16 SpO2PacketId = 0;
  UINT8 i;
  //copy SpO2Buffer to OutBuffer and send data
  OutBuffer[OutSize++] = IND;
  OutBuffer[OutSize++] = SPO2_DEBUG_MODE_NEW_DATA_READY;
  OutBuffer[OutSize++] = SPO2_REAL_TIME_DATA_ARRAY_LENGTH + 5;	//packetId(2 bytes) + SpO2 data(64 bytes) + SpO2(1 bytes) + heart beat(1 bytes) + //HeartBeatDetected
  
  OutBuffer[OutSize++] = (UINT8) (SpO2PacketId >> 8);
  OutBuffer[OutSize++] = (UINT8) (SpO2PacketId & 0x00FF);
  
  SpO2PacketId++;
                  
  for (i=0; i<SPO2_REAL_TIME_DATA_ARRAY_LENGTH; i++)
  {
          OutBuffer[OutSize++] = SpO2Graph[i];
  }

  OutBuffer[OutSize++] = SpO2_SaturationValue;	//SpO2
  OutBuffer[OutSize++] = SpO2_HeartRate;	//HR
  OutBuffer[OutSize++] = SpO2_HeartBeatDetected;
                  
  SpO2_HeartBeatDetected = FALSE;	
  (void)SerialComm_SendData();

}


/******************************************************************************
 *
 *    @name        USB_Notify_Callback
 *
 *    @brief       This function handles PSTN Sub Class callbacks
 *
 *    @param       controller_ID    : Controller ID
 *    @param       event_type       : PSTN Event Type
 *    @param       val              : gives the configuration value
 *
 *    @return      None
 *
 *****************************************************************************
 * This function handles USB_APP_CDC_CARRIER_ACTIVATED and
 * USB_APP_CDC_CARRIER_DEACTIVATED PSTN Events
 *****************************************************************************/

static void USB_Notify_Callback (
    uint_8 controller_ID,   /* [IN] Controller ID */
    uint_8 event_type,      /* [IN] PSTN Event Type */
    void* val               /* [IN] gives the configuration value */
)
{
    UNUSED (controller_ID)
    UNUSED (val)
    if(start_app == TRUE)
    {
        if(event_type == USB_APP_CDC_CARRIER_ACTIVATED)
        {
            start_transactions = TRUE;
        }
        else if(event_type == USB_APP_CDC_CARRIER_DEACTIVATED)
        {
            start_transactions = FALSE;
        }
    }
    return;
}

/******************************************************************************
 *
 *    @name        USB_App_Callback
 *
 *    @brief       This function handles Class callback
 *
 *    @param       controller_ID    : Controller ID
 *    @param       event_type       : Value of the event
 *    @param       val              : gives the configuration value
 *
 *    @return      None
 *
 *****************************************************************************
 * This function is called from the class layer whenever reset occurs or enum
 * is complete. After the enum is complete this function sets a variable so
 * that the application can start.
 * This function also receives DATA Send and RECEIVED Events
 *****************************************************************************/

static void USB_App_Callback (
    uint_8 controller_ID,   /* [IN] Controller ID */
    uint_8 event_type,      /* [IN] value of the event */
    void* val               /* [IN] gives the configuration value */
)
{
    UNUSED (controller_ID)
    UNUSED (val)
    if(event_type == USB_APP_BUS_RESET)
    {
        start_app=FALSE;
    }
    else if(event_type == USB_APP_ENUM_COMPLETE)
    {
        start_app=TRUE;
    }
    else if((event_type == USB_APP_DATA_RECEIVED))
    //&&            (start_transactions == TRUE))
    {
        /* Copy Received Data buffer to Application Buffer */
        USB_PACKET_SIZE BytesToBeCopied;
        APP_DATA_STRUCT* dp_rcv = (APP_DATA_STRUCT*)val;
        uint_8 index;
        BytesToBeCopied = (USB_PACKET_SIZE)((dp_rcv->data_size > DATA_BUFF_SIZE) ?
                                      DATA_BUFF_SIZE:dp_rcv->data_size);
        for(index = 0; index<BytesToBeCopied ; index++)
        {
            g_curr_recv_buf[index]= dp_rcv->data_ptr[index];
        }
        g_recv_size = index;
        (void)USB_Class_CDC_Interface_DIC_Recv_Data(CONTROLLER_ID, NULL, 0);
    }
    else if((event_type == USB_APP_SEND_COMPLETE)&&
                                              (start_transactions == TRUE))
    {
        /* Previous Send is complete. Queue next receive */
        (void)USB_Class_CDC_Interface_DIC_Recv_Data(CONTROLLER_ID, NULL, 0);
    }

    return;
}

/*****************************************************************************
*                        Measurement Engine Handler
*****************************************************************************/

void vfnTurnOffMeasurementEngine (void)
{
 vfnDisable_All_Operationals();
 DISABLE_DAC; 
}

void vfnStartSPO2MeasurementEngine (void)
{
 if(u8OpCheckSpo2())
 {
   vfnDisable_All_Operationals ();
 }
 else
 {
 opamp1_gp_mode();
 opamp2_gp_mode();
 TRIAMP1C0_HighMode();
 TRIAMP2C0_HighMode();
 }
 SpO2_Init(); 
}

void vfnEnable_AFE (void)
{
  SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; //Clock to PORTC
  PORTC_PCR14 = PORT_PCR_MUX(1); //PTC14 as GPIO
  GPIOC_PDDR |= (1<<14); //PTC14 as output
  GPIOC_PCOR |= (1<<14); //AFEs Enabled
  
  LED1_OFF
  LED2_ON
}

void vfnDisable_AFE (void)
{
 GPIOC_PSOR |= (1<<14); //Disable AFEs

 LED1_ON
 LED2_OFF
}