/*
 * Note: This file is recreated by the project wizard whenever the MCU is
 *       changed and should not be edited by hand
 */

/* Include the derivative-specific header file */
#include <MK53N512CMD100.h>

#define EVENT(gu8Status,bit)		gu8Status |= (1<<bit)
#define COMPARE(gu8Status,bit)		gu8Status & (1<<bit)
#define CLEAR(gu8Status,bit)		gu8Status &=  ~(1<<bit)