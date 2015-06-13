#include "GlucoseMeter.h"


/* Private functions */

static void StateIdle(void);				/**< "Do nothing" state */
static void StateWaitingForBlood(void);		/**< "Waiting for blood" state */
static void StateMeasuring(void);			/**< "Measuring" state */

static void FinishGlucoseMeasurement_TimerEvent(void);	/**< When this timer has elapsed, the electrode current will be measured (using the ADC)*/
static void SampleGlucose_TimerEvent(void);	/**< Timer to read the ADC periodically */

static void SendGraphDataToPc(void);


/** Main state machine */
void (*const GlucoseMeterStateMachine[]) (void) =
{
	StateIdle,
	StateWaitingForBlood,
	StateMeasuring
};

/* Private Macros */

typedef enum
{
	STATE_IDLE,
	STATE_WAITING_FOR_BLOOD,
	STATE_MEASURING
} GlucoseMeterStates_e;

/* Private variables */


static MovingAverage_uint8_t Electrode1;	/**< Average object for storing the Electrode 1 sample */	
static MovingAverage_uint8_t Electrode2;	/**< Average object for storing the Electrode 2 sampl */
static UINT8 GlucoseMeterActualState = STATE_IDLE;	/**< State machine actual state */
static UINT8 GlucoseMeterActualEvent = EVENT_GLU_NONE;	/**< Actual event */
static UINT8 TimerSampleAdc;		/**< Timer ID to sample the glucose value */
static UINT8 TimerWait5sec;			/**< Timer ID to count 5 seconds before measuring the electrode voltage (current converted to voltage)*/

static UINT8 IsCalibration = FALSE;				/**< To know if the actual measurement is a calibration */
static UINT16 KnownGlucoseValueForCalibration; 	/**< Calibration value that should be stored */




//#define VREF_5V

#ifdef VREF_5V

/** Glucose real values look-up table for Vref = 5V*/
static const UINT16 GlucoseLookUpTable[] = 
{
	0, 2, 4, 6, 9, 11, 13, 15, 17, 19, 22, 24, 26, 28, 30, 33, 35, 37, 39, 41, 44, 46, 48, 50, 52, 55, 57, 59, 61, 64, 66, 68, 71, 73, 75, 77, 80, 82, 84, 87, 89, 91, 94, 96, 98, 100, 103, 105, 108, 110, 112, 115, 117, 119, 122, 124, 126, 129, 131, 134, 136, 138, 141, 143, 146, 148, 150, 153, 155, 158, 160, 163, 165, 168, 170, 172, 175, 177, 180, 182, 185, 187, 190, 192, 195, 197, 200, 202, 205, 207, 210, 212, 215, 218, 220, 223, 225, 228, 230, 233, 235, 238, 241, 243, 246, 248, 251, 254, 256, 259, 261, 264, 267, 269, 272, 275, 277, 280, 282, 285, 288, 290, 293, 296, 298, 301, 304, 307, 309, 312, 315, 317, 320, 323, 325, 328, 331, 334, 336, 339, 342, 345, 347, 350, 353, 356, 359, 361, 364, 367, 370, 372, 375, 378, 381, 384, 386, 389, 392, 395, 398, 401, 403, 406, 409, 412, 415, 418, 421, 424, 426, 429, 432, 435, 438, 441, 444, 447, 450, 453, 455, 458, 461, 464, 467, 470, 473, 476, 479, 482, 485, 488, 491, 494, 497, 500, 503, 506, 509, 512, 515, 518, 521, 524, 527, 530, 533, 536, 539, 542, 545, 548, 551, 554, 557, 561, 564, 567, 570, 573, 576, 579, 582, 585, 588, 592, 595, 598, 601, 604, 607, 610, 614, 617, 620, 623, 626, 629, 633, 636, 639, 642, 645, 649, 652, 655, 658, 661, 665, 668, 671, 674, 678, 681, 684, 687
};

#else
static const UINT16 GlucoseLookUpTable[] = 
/** Glucose real values look-up table for Vref = 3V*/
{
	0, 2, 5, 7, 9, 12, 14, 16, 18, 21, 23, 25, 28, 30, 32, 35, 37, 39, 42, 44, 46, 49, 51, 53, 55, 58, 60, 62, 65, 67, 69, 72, 74, 76, 79, 81, 83, 86, 88, 90, 92, 95, 97, 99, 102, 104, 106, 109, 111, 113, 116, 118, 120, 122, 125, 127, 129, 132, 134, 136, 139, 141, 143, 146, 148, 150, 153, 155, 157, 159, 162, 164, 166, 169, 171, 173, 176, 178, 180, 183, 185, 187, 189, 192, 194, 196, 199, 201, 203, 206, 208, 210, 213, 215, 217, 220, 222, 224, 226, 229, 231, 233, 236, 238, 240, 243, 245, 247, 250, 252, 254, 257, 259, 261, 263, 266, 268, 270, 273, 275, 277, 280, 282, 284, 287, 289, 291, 293, 296, 298, 300, 303, 305, 307, 310, 312, 314, 317, 319, 321, 324, 326, 328, 330, 333, 335, 337, 340, 342, 344, 347, 349, 351, 354, 356, 358, 361, 363, 365, 367, 370, 372, 374, 377, 379, 381, 384, 386, 388, 391, 393, 395, 397, 400, 402, 404, 407, 409, 411, 414, 416, 418, 421, 423, 425, 428, 430, 432, 434, 437, 439, 441, 444, 446, 448, 451, 453, 455, 458, 460, 462, 464, 467, 469, 471, 474, 476, 478, 481, 483, 485, 488, 490, 492, 495, 497, 499, 501, 504, 506, 508, 511, 513, 515, 518, 520, 522, 525, 527, 529, 532, 534, 536, 538, 541, 543, 545, 548, 550, 552, 555, 557, 559, 562, 564, 566, 568, 571, 573, 575, 578, 580, 582, 585, 587, 589
};
#endif


/* Public variables */
UINT16 GlucoseMeter_GlucoseValue;
INT16 GlucoseMeter_CalibrationConstant = -400;
UINT8 GlucoseMeter_GraphDataToPc[GLU_GRAPH_DATA_ARRAY_SIZE];

/*************************************************************/



/* Private function definitions */

static void StateIdle(void)
{
	//do nothing
}




static void StateWaitingForBlood(void)
{
	//when blood is detected, call the event and start timer
	if (Electrode1.Result >= BLOOD_DETECT_THRESHOLD)
	{
		GlucoseMeterActualState = STATE_MEASURING;
		GlucoseMeterActualEvent	= EVENT_GLU_BLOOD_DETECTED;
		SwTimer_StartTimer(TimerWait5sec, FINISH_GLUCOSE_MEASUREMENT_TIME);
	}
	
}

static void StateMeasuring(void)
{
	//the timer is reading, when it finishes we process the data

}





static void FinishGlucoseMeasurement_TimerEvent(void)
{
	INT16 tempGlucoseValue;		
	UINT8 tableIndex = Electrode1.Result;	//generate index for the table with the average of the 2 samples 
	
	if (!IsCalibration)
	{
		//search for the real glucose value in the look up table and add calibration constant			
		tempGlucoseValue = GlucoseLookUpTable[tableIndex] + GlucoseMeter_CalibrationConstant;
		
		if (tempGlucoseValue < 0)
		{
			GlucoseMeter_GlucoseValue = 0;
		}
		else
		{
			GlucoseMeter_GlucoseValue = (UINT16)tempGlucoseValue;
		}
		GlucoseMeterActualEvent = EVENT_GLU_FINISH_MEASUREMENT_OK;	
	}
	else
	{
		GlucoseMeter_CalibrationConstant = KnownGlucoseValueForCalibration - GlucoseLookUpTable[tableIndex];
		
		/* 
			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		    TO DO: need to change this to write in calibration constant in Flash memory
		   	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		 */		
		IsCalibration = FALSE;
		GlucoseMeterActualEvent = EVENT_GLU_FINISH_CALIBRATION_OK;
	}
	
	GlucoseMeterActualState = STATE_IDLE;		
	SwTimer_StopTimer(TimerWait5sec);	//stop both timers
	SwTimer_StopTimer(TimerSampleAdc);	
}




static void SampleGlucose_TimerEvent(void)
{
	UINT8 rawElectrode1, rawElectrode2;
	//read electrodes and average values
			
	rawElectrode1 = ADC_Read8b(ADC_CHANNEL_WORKING_ELECTRODE1);
	rawElectrode2 = ADC_Read8b(ADC_CHANNEL_WORKING_ELECTRODE2);
	
	//this is a temporary fix because I don't have negative power supply
	if (rawElectrode1 <= ELECTRODES_VOLTAGE_OFFSET)
	{
		rawElectrode1 = 0;
	}
	else
	{
		rawElectrode1 -= ELECTRODES_VOLTAGE_OFFSET;
	}

	if (rawElectrode2 <= ELECTRODES_VOLTAGE_OFFSET)
	{
		rawElectrode2 = 0;
	}
	else
	{
		rawElectrode2 -= ELECTRODES_VOLTAGE_OFFSET;
	}

	
	MovingAverage_PushNewValue8b(&Electrode1, rawElectrode1);	
	MovingAverage_PushNewValue8b(&Electrode2, rawElectrode2);
	
	#ifdef GLU_DEBUG
	SendGraphDataToPc();
	#endif
	
	SwTimer_StartTimer(TimerSampleAdc, GLUCOSE_SAMPLING_PERIOD);		
}


static void SendGraphDataToPc(void)
{
	static UINT8 actualPosition = 0;
	
	//store data and send it when the buffer is full
	if (actualPosition < GLU_GRAPH_DATA_ARRAY_SIZE)
	{
		GlucoseMeter_GraphDataToPc[actualPosition++] = Electrode1.Result;
		GlucoseMeter_GraphDataToPc[actualPosition++] = Electrode2.Result;
	}
	else
	{
		//buffer is full, call the EVENT_ECG_DATA_READY event
		GlucoseMeterActualEvent = EVENT_GLU_DEBUG_NEW_DATA_READY;		
		actualPosition = 0;
	}	
}


/*******************************
* Public functions
********************************/

/* call this only once at the beginning of the application */
void GlucoseMeter_Init(void)	
{
	TimerSampleAdc = SwTimer_CreateTimer(SampleGlucose_TimerEvent);
	TimerWait5sec = SwTimer_CreateTimer(FinishGlucoseMeasurement_TimerEvent);
}


UINT8 GlucoseMeter_StartMeasurement(void)
{
	UINT8 status = FALSE;
				 
	if (GlucoseMeterActualState == STATE_IDLE)
	{
		ADC_Init8b(1<<ADC_CHANNEL_WORKING_ELECTRODE1|
		 	   	   1<<ADC_CHANNEL_WORKING_ELECTRODE2);

		GlucoseMeter_GlucoseValue = 0;
		GlucoseMeterActualState = STATE_WAITING_FOR_BLOOD;
		
		MovingAverage_Clear8b(&Electrode1);
		MovingAverage_Clear8b(&Electrode2);
		
		//start timer to measure glucose every GLUCOSE_SAMPLING_PERIOD ms				
		SwTimer_StartTimer(TimerSampleAdc, GLUCOSE_SAMPLING_PERIOD);		
		status = TRUE;
	}
	else
	{
		status = FALSE;
	}
	return status;
}


void GlucoseMeter_AbortMeasurement(void)
{
	IsCalibration = FALSE;
	SwTimer_StopTimer(TimerWait5sec);	//stop both timers
	SwTimer_StopTimer(TimerSampleAdc);
	GlucoseMeterActualState = STATE_IDLE;	
}


UINT8 GlucoseMeter_StartCalibration(UINT16 knownGlucoseValue)
{
	IsCalibration = TRUE;
	KnownGlucoseValueForCalibration = knownGlucoseValue;
	return (GlucoseMeter_StartMeasurement());		
}


void GlucoseMeter_PeriodicTask(void)
{
	/* State machine handler */
	GlucoseMeterStateMachine[GlucoseMeterActualState]();
	
	/* Event handler */
	if (GlucoseMeterActualEvent != EVENT_GLU_NONE)
	{
		if (GlucoseMeter_Events[GlucoseMeterActualEvent] != NULL)
		{			
			GlucoseMeter_Events[GlucoseMeterActualEvent]();	//execute registered event
			GlucoseMeterActualEvent = EVENT_GLU_NONE;
		}		
	}
}
