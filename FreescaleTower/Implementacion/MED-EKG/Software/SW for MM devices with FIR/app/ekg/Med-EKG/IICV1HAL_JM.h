#ifndef __IICV1HALGB
#define __IICV1HALGB

#include "derivative.h"

#define IICIF           IICS_IICIF
#define IIC_ARBL        IICS_ARBL
#define IIC_RXAK        IICS_RXAK
#define IIC_BUSY        IICS_BUSY
#define IIC_IAAS        IICS_IAAS
#define IIC_SLAVE_ADD   IICA
#define IIC_CLOCK_RATE  IICF_ICR
#define IIC_CLOCK_DIV   IICF_MULT

#define IIC_CLOCK_DIV_VALUE 	0
#define IIC_CLOCK_RATE_VALUE 	0x11	//400kHz
//#define IIC_CLOCK_RATE_VALUE 	0x20	//150kHz

#define IIC_CONTROL_REGISTER IICC1

#define IIC_CONTROL_REGISTER_VALUE (IICC1_IICEN_MASK|IICC1_IICIE_MASK)

#define IIC_TXAK IICC1_TXAK
#define IIC_TX   IICC1_TX
#define IIC_MST  IICC1_MST
#define IIC_RSTA IICC1_RSTA

#define IIC_DATA_REGISTER  IICD

/*****************************************************************************/
#endif
