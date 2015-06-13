#include "PublicTypes.h"

//temperature sensor
static void writetmp275(volatile UINT8 addr, volatile UINT8 Pointer_register, UINT8 Num_Bytes, volatile UINT8 Data1, volatile UINT8 Data2);
static UINT16 readtmp275(volatile UINT8 addr, volatile UINT8 Pointer_register);
static UINT16 ReadTemperatureSensor(void);

//weight
static UINT32 ReadScale(void);
static void delay (UINT16 x);
static UINT16 Read_ADC (void);
static void W_tare(void);


//sonar
static UINT16 ReadSonar(void);



/*****************************************************
*** Author: Marco Olivares
*** www.mpa.com.mx
*****************************************************/

UINT16 _TARE;             // Referred to a 0 Kgs platform

#define  WAIT_CYCLE  5000






static void delay (UINT16 x)
{
	for (;x;x--);
}


static UINT16 Read_ADC (void)
{
	UINT8 i;
	volatile UINT16 Data;
	volatile UINT32 Avg = 0;
	#define MAXIMUS 	30

	for (i = 1; i <= MAXIMUS ; i++)
	{
		Data = ADC_Read12b(DC_WEIGHT_CHANNEL);
		Avg = Avg + Data;
		delay(WAIT_CYCLE);
	}

	return (UINT16)(Avg / (UINT16) MAXIMUS);
}

static void W_tare(void)
{
	// Consider that the scale platform is empty.
	_TARE = Read_ADC() - 7;
}


static UINT32 ReadScale(void)
{
	/*
	For 200Kg load cell

	Vlt 	ADC	Grs	Formula
	11.7	8	     0	  -9
	15.3	11 	 124	 123
	63.4	50	1845	1834
	63.9	51	1866	1878
	81.4	65	2493	2492
	115.4	93	3709	3721
	133.5	108	4358	4379
	185.1	149	6200	6178


	*/

/* old code for small scale
	volatile UINT16  i;

	i = Read_ADC();

	if ((i - _TARE) > 20)
//     i = ((230*(i - _TARE)) - 4607) / 10;
		i = ((230 * (i - _TARE)) - 3900) / 10;
	else
		i = 0;

	return i;
	*/
	
	volatile UINT32  ixw;

	ixw = Read_ADC();

	if ((ixw - _TARE) > 20)
		ixw = ((438 * (ixw - _TARE)) - 3601) / 10 + 10;
	else
		ixw = 0;

	return ixw;	
}






/*****************************************************
*** Author: Marco Olivares
*** www.mpa.com.mx
*****************************************************/




void writetmp275(volatile UINT8 addr, volatile UINT8 Pointer_register, UINT8 Num_Bytes, volatile UINT8 Data1, volatile UINT8 Data2)
{
	/* Addr es la dirección física del dispositivo i2c
	   Pointer_register es dependiendo de la configuración según el manual pueden ser 00, 01, 10 y 11
	       los últimos dos bits solamente
	   Num_bytes es el nuúmero de bytes a recibir solo puede ser 1 o 2
	   Data1 y Data2 son los datos a escribir
	*/
	addr = (addr & 0x07) << 1;
	addr = 0x90 | addr;
	Pointer_register = Pointer_register & 0x03;
	start();

	if (!byteout(addr))
		if (!byteout(Pointer_register))
			if (!byteout(Data1))
				if (Num_Bytes == 2)
					if (!byteout(Data2));

	stop();
}


UINT16 readtmp275(volatile UINT8 addr, volatile UINT8 Pointer_register)
{
	/* Addr es la dirección física del dispositivo i2c
	   Pointer_register es dependiendo de la configuración según el manual pueden ser 00, 01, 10 y 11
	       los últimos dos bits solamente
	*/
	volatile UINT16 Data1;
	volatile UINT16 Data2;
	addr = (addr & 0x07) << 1;
	addr = 0x90 | addr;
	Pointer_register = Pointer_register & 0x03;
	start();

	if (!byteout(addr))
		if (!byteout(Pointer_register))
		{
			start();

			if (!byteout(addr | 0x01))
			{
//            Data1 = (UINT16)bytein(ACK) << 4;
//            Data2 = Data1 | (0x000f & ((UINT16)bytein(ACK)>>4));
				Data1 = (UINT16)bytein(ACK) * 1000;
				Data2 = (bytein(ACK) >> 4) * 62 + Data1;
				stop();
				return Data2;
			}
			else
			{
				stop();
				return 0xffff;
			}

		}
}



UINT16 ReadTemperatureSensor(void)
{
	UINT16 x;
	writetmp275(0, 1, 1, 0xE1, 0); //Initialize the chip

	for (x = 0;x < 0xcccc;x++);

	return readtmp275(0, 0);
}





UINT16 ReadSonar(void)
{
	volatile UINT16 Data1 = 800;

	start();

	if (!byteout(0xE0))
		if (!byteout(0))
			byteout(0x51);

	stop();
	
	while (Data1--)    //A brief pause it's very important!
		scl_delay();

	start();

	if (!byteout(0xE0))
		if (!byteout(0))
		{
			start();

			if (!byteout(0xE1))
			{
				(void)   bytein(ACK);
				(void)   bytein(ACK);
				Data1 =  bytein(ACK);
				Data1 = + bytein(NACK);
				stop();
				return Data1;
			}
			else
			{
				stop();
				return 0xff;
			}
		}
}
