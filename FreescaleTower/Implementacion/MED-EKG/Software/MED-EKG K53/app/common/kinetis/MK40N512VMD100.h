/*
** ###################################################################
**     Processor:           MK40N512VMD100
**     Compilers:           Freescale C/C++ for Embedded ARM
**                          IAR ANSI C/C++ Compiler for ARM
**     Reference manual:    K40P144M100SF2RM, Rev. 1 Draft A, 30 July 2010
**     Version:             rev. 0.3, 2010-09-05
**
**     Abstract:
**         This header file implements peripheral memory map for MK40N512VMD100
**         processor.
**
**     Copyright: 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 0.1 (2010-04-10)
**         Initial version
**     - rev. 0.2 (2010-08-31)
**         TSI base address fixed
**     - rev. 0.3 (2010-09-05)
**         AXBS registers for unimplemented masters/slaves removed
**
** ###################################################################
*/

/*! \file MK40N512VMD100.h */
/*! \version 0.3 */
/*! \date 2010-09-05 */
/*! \brief Peripheral memory map for MK40N512VMD100 */
/*! \detailed This header file implements peripheral memory map for MK40N512VMD100
      processor. */


/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Activation of the proper MCU and prevention from activation of multiple MCU libraries */

#if !defined(MCU_MK40N512VMD100)  /* Check if this MCU has not been already activated... */

/* Check if another MCU has not been activated yet */
#if (defined(MCU_ACTIVE))
  #error MK40N512VMD100 MCU library: There is already active another MCU library. Do #include of one "*_MCU.h" only.
#else /* (!defined(MCU_ACTIVE)) */
  #define MCU_ACTIVE  /* Mark there is some MCU already active */
  #define MCU_MK40N512VMD100  /* Mark specific MCU as active */
#endif /* (!defined(MCU_ACTIVE)) */

#include <stdint.h>

/*! Memory map version 0.3 */
#define MCU_MEM_MAP_VERSION ((0 << 8) | 3)

#ifndef __RESET_WATCHDOG
  #define __RESET_WATCHDOG()  (void)(WDOG_REFRESH = 0xA602, WDOG_REFRESH = 0xB480)
#endif /* __RESET_WATCHDOG */
/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*! \addtogroup Interrupt_vector_numbers Interrupt vector numbers */
/*! \{ */

/*! Interrupt Number Definitions */
typedef enum {
  INT_Initial_Stack_Pointer    = 0,                /*!< Initial stack pointer */
  INT_Initial_Program_Counter  = 1,                /*!< Initial program counter */
  INT_NMI                      = 2,                /*!< Non-maskable interrupt */
  INT_Hard_Fault               = 3,                /*!< Hard fault exception */
  INT_Reserved4                = 4,                /*!< Reserved interrupt 4 */
  INT_Bus_Fault                = 5,                /*!< Bus fault exception */
  INT_Usage_Fault              = 6,                /*!< Usage fault exception */
  INT_Reserved7                = 7,                /*!< Reserved interrupt 7 */
  INT_Reserved8                = 8,                /*!< Reserved interrupt 8 */
  INT_Reserved9                = 9,                /*!< Reserved interrupt 9 */
  INT_Reserved10               = 10,               /*!< Reserved interrupt 10 */
  INT_SVCall                   = 11,               /*!< A supervisor call exception */
  INT_DebugMonitor             = 12,               /*!< Debug Monitor */
  INT_Reserved13               = 13,               /*!< Reserved interrupt 13 */
  INT_PendableSrvReq           = 14,               /*!< PendSV exception - request for system level service */
  INT_SysTick                  = 15,               /*!< SysTick Interrupt */
  INT_DMA0                     = 16,               /*!< DMA Channel 0 Transfer Complete */
  INT_DMA1                     = 17,               /*!< DMA Channel 1 Transfer Complete */
  INT_DMA2                     = 18,               /*!< DMA Channel 2 Transfer Complete */
  INT_DMA3                     = 19,               /*!< DMA Channel 3 Transfer Complete */
  INT_DMA4                     = 20,               /*!< DMA Channel 4 Transfer Complete */
  INT_DMA5                     = 21,               /*!< DMA Channel 5 Transfer Complete */
  INT_DMA6                     = 22,               /*!< DMA Channel 6 Transfer Complete */
  INT_DMA7                     = 23,               /*!< DMA Channel 7 Transfer Complete */
  INT_DMA8                     = 24,               /*!< DMA Channel 8 Transfer Complete */
  INT_DMA9                     = 25,               /*!< DMA Channel 9 Transfer Complete */
  INT_DMA10                    = 26,               /*!< DMA Channel 10 Transfer Complete */
  INT_DMA11                    = 27,               /*!< DMA Channel 11 Transfer Complete */
  INT_DMA12                    = 28,               /*!< DMA Channel 12 Transfer Complete */
  INT_DMA13                    = 29,               /*!< DMA Channel 13 Transfer Complete */
  INT_DMA14                    = 30,               /*!< DMA Channel 14 Transfer Complete */
  INT_DMA15                    = 31,               /*!< DMA Channel 15 Transfer Complete */
  INT_DMA_Error                = 32,               /*!< DMA Error Interrupt */
  INT_MCM                      = 33,               /*!< Normal Interrupt */
  INT_FTFL                     = 34,               /*!< FTFL Interrupt */
  INT_Read_Collision           = 35,               /*!< Read Collision Interrupt */
  INT_LVD_LVW                  = 36,               /*!< Low Voltage Detect, Low Voltage Warning */
  INT_LLW                      = 37,               /*!< Low Leakage Wakeup */
  INT_Watchdog                 = 38,               /*!< WDOG Interrupt */
  INT_Reserved39               = 39,               /*!< Reserved interrupt 39 */
  INT_I2C0                     = 40,               /*!< I2C0 interrupt */
  INT_I2C1                     = 41,               /*!< I2C1 interrupt */
  INT_SPI0                     = 42,               /*!< SPI0 Interrupt */
  INT_SPI1                     = 43,               /*!< SPI1 Interrupt */
  INT_SPI2                     = 44,               /*!< SPI2 Interrupt */
  INT_CAN0_ORed_Message_buffer = 45,               /*!< CAN0 OR'd Message Buffers Interrupt */
  INT_CAN0_Bus_Off             = 46,               /*!< CAN0 Bus Off Interrupt */
  INT_CAN0_Error               = 47,               /*!< CAN0 Error Interrupt */
  INT_CAN0_Tx_Warning          = 48,               /*!< CAN0 Tx Warning Interrupt */
  INT_CAN0_Rx_Warning          = 49,               /*!< CAN0 Rx Warning Interrupt */
  INT_CAN0_Wake_Up             = 50,               /*!< CAN0 Wake Up Interrupt */
  INT_CAN0_IMEU                = 51,               /*!< CAN0 Individual Matching Elements Update (IMEU) Interrupt */
  INT_CAN0_Lost_Rx             = 52,               /*!< CAN0 Lost Receive Interrupt */
  INT_CAN1_ORed_Message_buffer = 53,               /*!< CAN1 OR'd Message Buffers Interrupt */
  INT_CAN1_Bus_Off             = 54,               /*!< CAN1 Bus Off Interrupt */
  INT_CAN1_Error               = 55,               /*!< CAN1 Error Interrupt */
  INT_CAN1_Tx_Warning          = 56,               /*!< CAN1 Tx Warning Interrupt */
  INT_CAN1_Rx_Warning          = 57,               /*!< CAN1 Rx Warning Interrupt */
  INT_CAN1_Wake_Up             = 58,               /*!< CAN1 Wake Up Interrupt */
  INT_CAN1_IMEU                = 59,               /*!< CAN1 Individual Matching Elements Update (IMEU) Interrupt */
  INT_CAN1_Lost_Rx             = 60,               /*!< CAN1 Lost Receive Interrupt */
  INT_UART0_RX_TX              = 61,               /*!< UART0 Receive/Transmit interrupt */
  INT_UART0_ERR                = 62,               /*!< UART0 Error interrupt */
  INT_UART1_RX_TX              = 63,               /*!< UART1 Receive/Transmit interrupt */
  INT_UART1_ERR                = 64,               /*!< UART1 Error interrupt */
  INT_UART2_RX_TX              = 65,               /*!< UART2 Receive/Transmit interrupt */
  INT_UART2_ERR                = 66,               /*!< UART2 Error interrupt */
  INT_UART3_RX_TX              = 67,               /*!< UART3 Receive/Transmit interrupt */
  INT_UART3_ERR                = 68,               /*!< UART3 Error interrupt */
  INT_UART4_RX_TX              = 69,               /*!< UART4 Receive/Transmit interrupt */
  INT_UART4_ERR                = 70,               /*!< UART4 Error interrupt */
  INT_UART5_RX_TX              = 71,               /*!< UART5 Receive/Transmit interrupt */
  INT_UART5_ERR                = 72,               /*!< UART5 Error interrupt */
  INT_ADC0                     = 73,               /*!< ADC0 interrupt */
  INT_ADC1                     = 74,               /*!< ADC1 interrupt */
  INT_HSCMP0                   = 75,               /*!< HSCMP0 interrupt */
  INT_HSCMP1                   = 76,               /*!< HSCMP1 interrupt */
  INT_HSCMP2                   = 77,               /*!< HSCMP2 interrupt */
  INT_FTM0                     = 78,               /*!< FTM0 fault, overflow and channels interrupt */
  INT_FTM1                     = 79,               /*!< FTM1 fault, overflow and channels interrupt */
  INT_FTM2                     = 80,               /*!< FTM2 fault, overflow and channels interrupt */
  INT_CMT                      = 81,               /*!< CMT interrupt */
  INT_SRTC                     = 82,               /*!< SRTC interrupt */
  INT_Reserved83               = 83,               /*!< Reserved interrupt 83 */
  INT_PIT0                     = 84,               /*!< PIT timer channel 0 interrupt */
  INT_PIT1                     = 85,               /*!< PIT timer channel 1 interrupt */
  INT_PIT2                     = 86,               /*!< PIT timer channel 2 interrupt */
  INT_PIT3                     = 87,               /*!< PIT timer channel 3 interrupt */
  INT_PDB0                     = 88,               /*!< PDB0 Interrupt */
  INT_USB0                     = 89,               /*!< USB0 interrupt */
  INT_USBDCD                   = 90,               /*!< USBDCD Interrupt */
  INT_Reserved91               = 91,               /*!< Reserved interrupt 91 */
  INT_Reserved92               = 92,               /*!< Reserved interrupt 92 */
  INT_Reserved93               = 93,               /*!< Reserved interrupt 93 */
  INT_Reserved94               = 94,               /*!< Reserved interrupt 94 */
  INT_I2S0                     = 95,               /*!< I2S0 Interrupt */
  INT_SDHC                     = 96,               /*!< SDHC Interrupt */
  INT_DAC0                     = 97,               /*!< DAC0 interrupt */
  INT_DAC1                     = 98,               /*!< DAC1 interrupt */
  INT_TSI0                     = 99,               /*!< TSI0 Interrupt */
  INT_MCG                      = 100,              /*!< MCG Interrupt */
  INT_LPTimer                  = 101,              /*!< LPTimer interrupt */
  INT_LCD                      = 102,              /*!< Segment LCD Interrupt */
  INT_PORTA                    = 103,              /*!< Port A interrupt */
  INT_PORTB                    = 104,              /*!< Port B interrupt */
  INT_PORTC                    = 105,              /*!< Port C interrupt */
  INT_PORTD                    = 106,              /*!< Port D interrupt */
  INT_PORTE                    = 107,              /*!< Port E interrupt */
  INT_Reserved108              = 108,              /*!< Reserved interrupt 108 */
  INT_Reserved109              = 109,              /*!< Reserved interrupt 109 */
  INT_Reserved110              = 110,              /*!< Reserved interrupt 110 */
  INT_Reserved111              = 111,              /*!< Reserved interrupt 111 */
  INT_Reserved112              = 112,              /*!< Reserved interrupt 112 */
  INT_Reserved113              = 113,              /*!< Reserved interrupt 113 */
  INT_Reserved114              = 114,              /*!< Reserved interrupt 114 */
  INT_Reserved115              = 115,              /*!< Reserved interrupt 115 */
  INT_Reserved116              = 116,              /*!< Reserved interrupt 116 */
  INT_Reserved117              = 117,              /*!< Reserved interrupt 117 */
  INT_Reserved118              = 118,              /*!< Reserved interrupt 118 */
  INT_Reserved119              = 119               /*!< Reserved interrupt 119 */
} IRQInterruptIndex;

/*! \} */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Peripheral type defines
   ---------------------------------------------------------------------------- */

/*! \addtogroup Peripheral_defines Peripheral type defines */
/*! \{ */


/*
** Start of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ADC
   ---------------------------------------------------------------------------- */

/*! \addtogroup ADC_Peripheral ADC */
/*! \{ */

/*! ADC - Peripheral register structure */
typedef struct ADC_MemMap {
  uint32_t SC1[2];                                 /*!< ADC status and control registers 1, array offset: 0x0, array step: 0x4 */
  uint32_t CFG1;                                   /*!< ADC configuration register 1, offset: 0x8 */
  uint32_t CFG2;                                   /*!< Configuration register 2, offset: 0xC */
  uint32_t R[2];                                   /*!< ADC data result register, array offset: 0x10, array step: 0x4 */
  uint32_t CV1;                                    /*!< Compare value registers, offset: 0x18 */
  uint32_t CV2;                                    /*!< Compare value registers, offset: 0x1C */
  uint32_t SC2;                                    /*!< Status and control register 2, offset: 0x20 */
  uint32_t SC3;                                    /*!< Status and control register 3, offset: 0x24 */
  uint32_t OFS;                                    /*!< ADC offset correction register, offset: 0x28 */
  uint32_t PG;                                     /*!< ADC plus-side gain register, offset: 0x2C */
  uint32_t MG;                                     /*!< ADC minus-side gain register, offset: 0x30 */
  uint32_t CLPD;                                   /*!< ADC plus-side general calibration value register, offset: 0x34 */
  uint32_t CLPS;                                   /*!< ADC plus-side general calibration value register, offset: 0x38 */
  uint32_t CLP4;                                   /*!< ADC plus-side general calibration value register, offset: 0x3C */
  uint32_t CLP3;                                   /*!< ADC plus-side general calibration value register, offset: 0x40 */
  uint32_t CLP2;                                   /*!< ADC plus-side general calibration value register, offset: 0x44 */
  uint32_t CLP1;                                   /*!< ADC plus-side general calibration value register, offset: 0x48 */
  uint32_t CLP0;                                   /*!< ADC plus-side general calibration value register, offset: 0x4C */
  uint32_t PGA;                                    /*!< ADC PGA register, offset: 0x50 */
  uint32_t CLMD;                                   /*!< ADC minus-side general calibration value register, offset: 0x54 */
  uint32_t CLMS;                                   /*!< ADC minus-side general calibration value register, offset: 0x58 */
  uint32_t CLM4;                                   /*!< ADC minus-side general calibration value register, offset: 0x5C */
  uint32_t CLM3;                                   /*!< ADC minus-side general calibration value register, offset: 0x60 */
  uint32_t CLM2;                                   /*!< ADC minus-side general calibration value register, offset: 0x64 */
  uint32_t CLM1;                                   /*!< ADC minus-side general calibration value register, offset: 0x68 */
  uint32_t CLM0;                                   /*!< ADC minus-side general calibration value register, offset: 0x6C */
} volatile *ADC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros */
/*! \{ */


/* ADC - Register accessors */
#define ADC_SC1_REG(base,index)                  ((base)->SC1[index])
#define ADC_CFG1_REG(base)                       ((base)->CFG1)
#define ADC_CFG2_REG(base)                       ((base)->CFG2)
#define ADC_R_REG(base,index)                    ((base)->R[index])
#define ADC_CV1_REG(base)                        ((base)->CV1)
#define ADC_CV2_REG(base)                        ((base)->CV2)
#define ADC_SC2_REG(base)                        ((base)->SC2)
#define ADC_SC3_REG(base)                        ((base)->SC3)
#define ADC_OFS_REG(base)                        ((base)->OFS)
#define ADC_PG_REG(base)                         ((base)->PG)
#define ADC_MG_REG(base)                         ((base)->MG)
#define ADC_CLPD_REG(base)                       ((base)->CLPD)
#define ADC_CLPS_REG(base)                       ((base)->CLPS)
#define ADC_CLP4_REG(base)                       ((base)->CLP4)
#define ADC_CLP3_REG(base)                       ((base)->CLP3)
#define ADC_CLP2_REG(base)                       ((base)->CLP2)
#define ADC_CLP1_REG(base)                       ((base)->CLP1)
#define ADC_CLP0_REG(base)                       ((base)->CLP0)
#define ADC_PGA_REG(base)                        ((base)->PGA)
#define ADC_CLMD_REG(base)                       ((base)->CLMD)
#define ADC_CLMS_REG(base)                       ((base)->CLMS)
#define ADC_CLM4_REG(base)                       ((base)->CLM4)
#define ADC_CLM3_REG(base)                       ((base)->CLM3)
#define ADC_CLM2_REG(base)                       ((base)->CLM2)
#define ADC_CLM1_REG(base)                       ((base)->CLM1)
#define ADC_CLM0_REG(base)                       ((base)->CLM0)

/*! \} */ /* end of group ADC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup ADC_Register_Masks ADC Register Masks */
/*! \{ */

/* SC1 Bit Fields */
#define ADC_SC1_ADCH_MASK                        0x1Fu
#define ADC_SC1_ADCH_SHIFT                       0
#define ADC_SC1_ADCH(x)                          (((x)<<ADC_SC1_ADCH_SHIFT)&ADC_SC1_ADCH_MASK)
#define ADC_SC1_DIFF_MASK                        0x20u
#define ADC_SC1_DIFF_SHIFT                       5
#define ADC_SC1_AIEN_MASK                        0x40u
#define ADC_SC1_AIEN_SHIFT                       6
#define ADC_SC1_COCO_MASK                        0x80u
#define ADC_SC1_COCO_SHIFT                       7
/* CFG1 Bit Fields */
#define ADC_CFG1_ADICLK_MASK                     0x3u
#define ADC_CFG1_ADICLK_SHIFT                    0
#define ADC_CFG1_ADICLK(x)                       (((x)<<ADC_CFG1_ADICLK_SHIFT)&ADC_CFG1_ADICLK_MASK)
#define ADC_CFG1_MODE_MASK                       0xCu
#define ADC_CFG1_MODE_SHIFT                      2
#define ADC_CFG1_MODE(x)                         (((x)<<ADC_CFG1_MODE_SHIFT)&ADC_CFG1_MODE_MASK)
#define ADC_CFG1_ADLSMP_MASK                     0x10u
#define ADC_CFG1_ADLSMP_SHIFT                    4
#define ADC_CFG1_ADIV_MASK                       0x60u
#define ADC_CFG1_ADIV_SHIFT                      5
#define ADC_CFG1_ADIV(x)                         (((x)<<ADC_CFG1_ADIV_SHIFT)&ADC_CFG1_ADIV_MASK)
#define ADC_CFG1_ADLPC_MASK                      0x80u
#define ADC_CFG1_ADLPC_SHIFT                     7
/* CFG2 Bit Fields */
#define ADC_CFG2_ADLSTS_MASK                     0x3u
#define ADC_CFG2_ADLSTS_SHIFT                    0
#define ADC_CFG2_ADLSTS(x)                       (((x)<<ADC_CFG2_ADLSTS_SHIFT)&ADC_CFG2_ADLSTS_MASK)
#define ADC_CFG2_ADHSC_MASK                      0x4u
#define ADC_CFG2_ADHSC_SHIFT                     2
#define ADC_CFG2_ADACKEN_MASK                    0x8u
#define ADC_CFG2_ADACKEN_SHIFT                   3
#define ADC_CFG2_MUXSEL_MASK                     0x10u
#define ADC_CFG2_MUXSEL_SHIFT                    4
/* R Bit Fields */
#define ADC_R_D_MASK                             0xFFFFu
#define ADC_R_D_SHIFT                            0
#define ADC_R_D(x)                               (((x)<<ADC_R_D_SHIFT)&ADC_R_D_MASK)
/* CV1 Bit Fields */
#define ADC_CV1_CV_MASK                          0xFFFFu
#define ADC_CV1_CV_SHIFT                         0
#define ADC_CV1_CV(x)                            (((x)<<ADC_CV1_CV_SHIFT)&ADC_CV1_CV_MASK)
/* CV2 Bit Fields */
#define ADC_CV2_CV_MASK                          0xFFFFu
#define ADC_CV2_CV_SHIFT                         0
#define ADC_CV2_CV(x)                            (((x)<<ADC_CV2_CV_SHIFT)&ADC_CV2_CV_MASK)
/* SC2 Bit Fields */
#define ADC_SC2_REFSEL_MASK                      0x3u
#define ADC_SC2_REFSEL_SHIFT                     0
#define ADC_SC2_REFSEL(x)                        (((x)<<ADC_SC2_REFSEL_SHIFT)&ADC_SC2_REFSEL_MASK)
#define ADC_SC2_DMAEN_MASK                       0x4u
#define ADC_SC2_DMAEN_SHIFT                      2
#define ADC_SC2_ACREN_MASK                       0x8u
#define ADC_SC2_ACREN_SHIFT                      3
#define ADC_SC2_ACFGT_MASK                       0x10u
#define ADC_SC2_ACFGT_SHIFT                      4
#define ADC_SC2_ACFE_MASK                        0x20u
#define ADC_SC2_ACFE_SHIFT                       5
#define ADC_SC2_ADTRG_MASK                       0x40u
#define ADC_SC2_ADTRG_SHIFT                      6
#define ADC_SC2_ADACT_MASK                       0x80u
#define ADC_SC2_ADACT_SHIFT                      7
/* SC3 Bit Fields */
#define ADC_SC3_AVGS_MASK                        0x3u
#define ADC_SC3_AVGS_SHIFT                       0
#define ADC_SC3_AVGS(x)                          (((x)<<ADC_SC3_AVGS_SHIFT)&ADC_SC3_AVGS_MASK)
#define ADC_SC3_AVGE_MASK                        0x4u
#define ADC_SC3_AVGE_SHIFT                       2
#define ADC_SC3_ADCO_MASK                        0x8u
#define ADC_SC3_ADCO_SHIFT                       3
#define ADC_SC3_CALF_MASK                        0x40u
#define ADC_SC3_CALF_SHIFT                       6
#define ADC_SC3_CAL_MASK                         0x80u
#define ADC_SC3_CAL_SHIFT                        7
/* OFS Bit Fields */
#define ADC_OFS_OFS_MASK                         0xFFFFu
#define ADC_OFS_OFS_SHIFT                        0
#define ADC_OFS_OFS(x)                           (((x)<<ADC_OFS_OFS_SHIFT)&ADC_OFS_OFS_MASK)
/* PG Bit Fields */
#define ADC_PG_PG_MASK                           0xFFFFu
#define ADC_PG_PG_SHIFT                          0
#define ADC_PG_PG(x)                             (((x)<<ADC_PG_PG_SHIFT)&ADC_PG_PG_MASK)
/* MG Bit Fields */
#define ADC_MG_MG_MASK                           0xFFFFu
#define ADC_MG_MG_SHIFT                          0
#define ADC_MG_MG(x)                             (((x)<<ADC_MG_MG_SHIFT)&ADC_MG_MG_MASK)
/* CLPD Bit Fields */
#define ADC_CLPD_CLPD_MASK                       0x3Fu
#define ADC_CLPD_CLPD_SHIFT                      0
#define ADC_CLPD_CLPD(x)                         (((x)<<ADC_CLPD_CLPD_SHIFT)&ADC_CLPD_CLPD_MASK)
/* CLPS Bit Fields */
#define ADC_CLPS_CLPS_MASK                       0x3Fu
#define ADC_CLPS_CLPS_SHIFT                      0
#define ADC_CLPS_CLPS(x)                         (((x)<<ADC_CLPS_CLPS_SHIFT)&ADC_CLPS_CLPS_MASK)
/* CLP4 Bit Fields */
#define ADC_CLP4_CLP4_MASK                       0x3FFu
#define ADC_CLP4_CLP4_SHIFT                      0
#define ADC_CLP4_CLP4(x)                         (((x)<<ADC_CLP4_CLP4_SHIFT)&ADC_CLP4_CLP4_MASK)
/* CLP3 Bit Fields */
#define ADC_CLP3_CLP3_MASK                       0x1FFu
#define ADC_CLP3_CLP3_SHIFT                      0
#define ADC_CLP3_CLP3(x)                         (((x)<<ADC_CLP3_CLP3_SHIFT)&ADC_CLP3_CLP3_MASK)
/* CLP2 Bit Fields */
#define ADC_CLP2_CLP2_MASK                       0xFFu
#define ADC_CLP2_CLP2_SHIFT                      0
#define ADC_CLP2_CLP2(x)                         (((x)<<ADC_CLP2_CLP2_SHIFT)&ADC_CLP2_CLP2_MASK)
/* CLP1 Bit Fields */
#define ADC_CLP1_CLP1_MASK                       0x7Fu
#define ADC_CLP1_CLP1_SHIFT                      0
#define ADC_CLP1_CLP1(x)                         (((x)<<ADC_CLP1_CLP1_SHIFT)&ADC_CLP1_CLP1_MASK)
/* CLP0 Bit Fields */
#define ADC_CLP0_CLP0_MASK                       0x3Fu
#define ADC_CLP0_CLP0_SHIFT                      0
#define ADC_CLP0_CLP0(x)                         (((x)<<ADC_CLP0_CLP0_SHIFT)&ADC_CLP0_CLP0_MASK)
/* PGA Bit Fields */
#define ADC_PGA_PGAG_MASK                        0xF0000u
#define ADC_PGA_PGAG_SHIFT                       16
#define ADC_PGA_PGAG(x)                          (((x)<<ADC_PGA_PGAG_SHIFT)&ADC_PGA_PGAG_MASK)
#define ADC_PGA_PGALP_MASK                       0x100000u
#define ADC_PGA_PGALP_SHIFT                      20
#define ADC_PGA_PGACHP_MASK                      0x200000u
#define ADC_PGA_PGACHP_SHIFT                     21
#define ADC_PGA_PGAEN_MASK                       0x800000u
#define ADC_PGA_PGAEN_SHIFT                      23
/* CLMD Bit Fields */
#define ADC_CLMD_CLMD_MASK                       0x3Fu
#define ADC_CLMD_CLMD_SHIFT                      0
#define ADC_CLMD_CLMD(x)                         (((x)<<ADC_CLMD_CLMD_SHIFT)&ADC_CLMD_CLMD_MASK)
/* CLMS Bit Fields */
#define ADC_CLMS_CLMS_MASK                       0x3Fu
#define ADC_CLMS_CLMS_SHIFT                      0
#define ADC_CLMS_CLMS(x)                         (((x)<<ADC_CLMS_CLMS_SHIFT)&ADC_CLMS_CLMS_MASK)
/* CLM4 Bit Fields */
#define ADC_CLM4_CLM4_MASK                       0x3FFu
#define ADC_CLM4_CLM4_SHIFT                      0
#define ADC_CLM4_CLM4(x)                         (((x)<<ADC_CLM4_CLM4_SHIFT)&ADC_CLM4_CLM4_MASK)
/* CLM3 Bit Fields */
#define ADC_CLM3_CLM3_MASK                       0x1FFu
#define ADC_CLM3_CLM3_SHIFT                      0
#define ADC_CLM3_CLM3(x)                         (((x)<<ADC_CLM3_CLM3_SHIFT)&ADC_CLM3_CLM3_MASK)
/* CLM2 Bit Fields */
#define ADC_CLM2_CLM2_MASK                       0xFFu
#define ADC_CLM2_CLM2_SHIFT                      0
#define ADC_CLM2_CLM2(x)                         (((x)<<ADC_CLM2_CLM2_SHIFT)&ADC_CLM2_CLM2_MASK)
/* CLM1 Bit Fields */
#define ADC_CLM1_CLM1_MASK                       0x7Fu
#define ADC_CLM1_CLM1_SHIFT                      0
#define ADC_CLM1_CLM1(x)                         (((x)<<ADC_CLM1_CLM1_SHIFT)&ADC_CLM1_CLM1_MASK)
/* CLM0 Bit Fields */
#define ADC_CLM0_CLM0_MASK                       0x3Fu
#define ADC_CLM0_CLM0_SHIFT                      0
#define ADC_CLM0_CLM0(x)                         (((x)<<ADC_CLM0_CLM0_SHIFT)&ADC_CLM0_CLM0_MASK)

/*! \} */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/*! Peripheral ADC0 base pointer */
#define ADC0_BASE_PTR                            ((ADC_MemMapPtr)0x4003B000u)
/*! Peripheral ADC1 base pointer */
#define ADC1_BASE_PTR                            ((ADC_MemMapPtr)0x400BB000u)

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros */
/*! \{ */


/* ADC - Register instance definitions */
/* ADC0 */
#define ADC0_SC1A                                ADC_SC1_REG(ADC0_BASE_PTR,0)
#define ADC0_SC1B                                ADC_SC1_REG(ADC0_BASE_PTR,1)
#define ADC0_CFG1                                ADC_CFG1_REG(ADC0_BASE_PTR)
#define ADC0_CFG2                                ADC_CFG2_REG(ADC0_BASE_PTR)
#define ADC0_RA                                  ADC_R_REG(ADC0_BASE_PTR,0)
#define ADC0_RB                                  ADC_R_REG(ADC0_BASE_PTR,1)
#define ADC0_CV1                                 ADC_CV1_REG(ADC0_BASE_PTR)
#define ADC0_CV2                                 ADC_CV2_REG(ADC0_BASE_PTR)
#define ADC0_SC2                                 ADC_SC2_REG(ADC0_BASE_PTR)
#define ADC0_SC3                                 ADC_SC3_REG(ADC0_BASE_PTR)
#define ADC0_OFS                                 ADC_OFS_REG(ADC0_BASE_PTR)
#define ADC0_PG                                  ADC_PG_REG(ADC0_BASE_PTR)
#define ADC0_MG                                  ADC_MG_REG(ADC0_BASE_PTR)
#define ADC0_CLPD                                ADC_CLPD_REG(ADC0_BASE_PTR)
#define ADC0_CLPS                                ADC_CLPS_REG(ADC0_BASE_PTR)
#define ADC0_CLP4                                ADC_CLP4_REG(ADC0_BASE_PTR)
#define ADC0_CLP3                                ADC_CLP3_REG(ADC0_BASE_PTR)
#define ADC0_CLP2                                ADC_CLP2_REG(ADC0_BASE_PTR)
#define ADC0_CLP1                                ADC_CLP1_REG(ADC0_BASE_PTR)
#define ADC0_CLP0                                ADC_CLP0_REG(ADC0_BASE_PTR)
#define ADC0_PGA                                 ADC_PGA_REG(ADC0_BASE_PTR)
#define ADC0_CLMD                                ADC_CLMD_REG(ADC0_BASE_PTR)
#define ADC0_CLMS                                ADC_CLMS_REG(ADC0_BASE_PTR)
#define ADC0_CLM4                                ADC_CLM4_REG(ADC0_BASE_PTR)
#define ADC0_CLM3                                ADC_CLM3_REG(ADC0_BASE_PTR)
#define ADC0_CLM2                                ADC_CLM2_REG(ADC0_BASE_PTR)
#define ADC0_CLM1                                ADC_CLM1_REG(ADC0_BASE_PTR)
#define ADC0_CLM0                                ADC_CLM0_REG(ADC0_BASE_PTR)
/* ADC1 */
#define ADC1_SC1A                                ADC_SC1_REG(ADC1_BASE_PTR,0)
#define ADC1_SC1B                                ADC_SC1_REG(ADC1_BASE_PTR,1)
#define ADC1_CFG1                                ADC_CFG1_REG(ADC1_BASE_PTR)
#define ADC1_CFG2                                ADC_CFG2_REG(ADC1_BASE_PTR)
#define ADC1_RA                                  ADC_R_REG(ADC1_BASE_PTR,0)
#define ADC1_RB                                  ADC_R_REG(ADC1_BASE_PTR,1)
#define ADC1_CV1                                 ADC_CV1_REG(ADC1_BASE_PTR)
#define ADC1_CV2                                 ADC_CV2_REG(ADC1_BASE_PTR)
#define ADC1_SC2                                 ADC_SC2_REG(ADC1_BASE_PTR)
#define ADC1_SC3                                 ADC_SC3_REG(ADC1_BASE_PTR)
#define ADC1_OFS                                 ADC_OFS_REG(ADC1_BASE_PTR)
#define ADC1_PG                                  ADC_PG_REG(ADC1_BASE_PTR)
#define ADC1_MG                                  ADC_MG_REG(ADC1_BASE_PTR)
#define ADC1_CLPD                                ADC_CLPD_REG(ADC1_BASE_PTR)
#define ADC1_CLPS                                ADC_CLPS_REG(ADC1_BASE_PTR)
#define ADC1_CLP4                                ADC_CLP4_REG(ADC1_BASE_PTR)
#define ADC1_CLP3                                ADC_CLP3_REG(ADC1_BASE_PTR)
#define ADC1_CLP2                                ADC_CLP2_REG(ADC1_BASE_PTR)
#define ADC1_CLP1                                ADC_CLP1_REG(ADC1_BASE_PTR)
#define ADC1_CLP0                                ADC_CLP0_REG(ADC1_BASE_PTR)
#define ADC1_PGA                                 ADC_PGA_REG(ADC1_BASE_PTR)
#define ADC1_CLMD                                ADC_CLMD_REG(ADC1_BASE_PTR)
#define ADC1_CLMS                                ADC_CLMS_REG(ADC1_BASE_PTR)
#define ADC1_CLM4                                ADC_CLM4_REG(ADC1_BASE_PTR)
#define ADC1_CLM3                                ADC_CLM3_REG(ADC1_BASE_PTR)
#define ADC1_CLM2                                ADC_CLM2_REG(ADC1_BASE_PTR)
#define ADC1_CLM1                                ADC_CLM1_REG(ADC1_BASE_PTR)
#define ADC1_CLM0                                ADC_CLM0_REG(ADC1_BASE_PTR)

/*! \} */ /* end of group ADC_Register_Accessor_Macros */


/*! \} */ /* end of group ADC_Peripheral */


/* ----------------------------------------------------------------------------
   -- AIPS
   ---------------------------------------------------------------------------- */

/*! \addtogroup AIPS_Peripheral AIPS */
/*! \{ */

/*! AIPS - Peripheral register structure */
typedef struct AIPS_MemMap {
  uint32_t MPRA;                                   /*!< Master Privilege Register A, offset: 0x0 */
  uint8_t RESERVED_0[28];
  uint32_t PACRA;                                  /*!< Peripheral Access Control Register, offset: 0x20 */
  uint32_t PACRB;                                  /*!< Peripheral Access Control Register, offset: 0x24 */
  uint32_t PACRC;                                  /*!< Peripheral Access Control Register, offset: 0x28 */
  uint32_t PACRD;                                  /*!< Peripheral Access Control Register, offset: 0x2C */
  uint32_t PACRE;                                  /*!< Peripheral Access Control Register, offset: 0x30 */
  uint32_t PACRF;                                  /*!< Peripheral Access Control Register, offset: 0x34 */
  uint32_t PACRG;                                  /*!< Peripheral Access Control Register, offset: 0x38 */
  uint32_t PACRH;                                  /*!< Peripheral Access Control Register, offset: 0x3C */
  uint32_t PACRI;                                  /*!< Peripheral Access Control Register, offset: 0x40 */
  uint32_t PACRJ;                                  /*!< Peripheral Access Control Register, offset: 0x44 */
  uint32_t PACRK;                                  /*!< Peripheral Access Control Register, offset: 0x48 */
  uint32_t PACRL;                                  /*!< Peripheral Access Control Register, offset: 0x4C */
  uint32_t PACRM;                                  /*!< Peripheral Access Control Register, offset: 0x50 */
  uint32_t PACRN;                                  /*!< Peripheral Access Control Register, offset: 0x54 */
  uint32_t PACRO;                                  /*!< Peripheral Access Control Register, offset: 0x58 */
  uint32_t PACRP;                                  /*!< Peripheral Access Control Register, offset: 0x5C */
} volatile *AIPS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- AIPS - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup AIPS_Register_Accessor_Macros AIPS - Register accessor macros */
/*! \{ */


/* AIPS - Register accessors */
#define AIPS_MPRA_REG(base)                      ((base)->MPRA)
#define AIPS_PACRA_REG(base)                     ((base)->PACRA)
#define AIPS_PACRB_REG(base)                     ((base)->PACRB)
#define AIPS_PACRC_REG(base)                     ((base)->PACRC)
#define AIPS_PACRD_REG(base)                     ((base)->PACRD)
#define AIPS_PACRE_REG(base)                     ((base)->PACRE)
#define AIPS_PACRF_REG(base)                     ((base)->PACRF)
#define AIPS_PACRG_REG(base)                     ((base)->PACRG)
#define AIPS_PACRH_REG(base)                     ((base)->PACRH)
#define AIPS_PACRI_REG(base)                     ((base)->PACRI)
#define AIPS_PACRJ_REG(base)                     ((base)->PACRJ)
#define AIPS_PACRK_REG(base)                     ((base)->PACRK)
#define AIPS_PACRL_REG(base)                     ((base)->PACRL)
#define AIPS_PACRM_REG(base)                     ((base)->PACRM)
#define AIPS_PACRN_REG(base)                     ((base)->PACRN)
#define AIPS_PACRO_REG(base)                     ((base)->PACRO)
#define AIPS_PACRP_REG(base)                     ((base)->PACRP)

/*! \} */ /* end of group AIPS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- AIPS Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup AIPS_Register_Masks AIPS Register Masks */
/*! \{ */

/* MPRA Bit Fields */
#define AIPS_MPRA_MPL5_MASK                      0x100u
#define AIPS_MPRA_MPL5_SHIFT                     8
#define AIPS_MPRA_MTW5_MASK                      0x200u
#define AIPS_MPRA_MTW5_SHIFT                     9
#define AIPS_MPRA_MTR5_MASK                      0x400u
#define AIPS_MPRA_MTR5_SHIFT                     10
#define AIPS_MPRA_MPL4_MASK                      0x1000u
#define AIPS_MPRA_MPL4_SHIFT                     12
#define AIPS_MPRA_MTW4_MASK                      0x2000u
#define AIPS_MPRA_MTW4_SHIFT                     13
#define AIPS_MPRA_MTR4_MASK                      0x4000u
#define AIPS_MPRA_MTR4_SHIFT                     14
#define AIPS_MPRA_MPL2_MASK                      0x100000u
#define AIPS_MPRA_MPL2_SHIFT                     20
#define AIPS_MPRA_MTW2_MASK                      0x200000u
#define AIPS_MPRA_MTW2_SHIFT                     21
#define AIPS_MPRA_MTR2_MASK                      0x400000u
#define AIPS_MPRA_MTR2_SHIFT                     22
#define AIPS_MPRA_MPL1_MASK                      0x1000000u
#define AIPS_MPRA_MPL1_SHIFT                     24
#define AIPS_MPRA_MTW1_MASK                      0x2000000u
#define AIPS_MPRA_MTW1_SHIFT                     25
#define AIPS_MPRA_MTR1_MASK                      0x4000000u
#define AIPS_MPRA_MTR1_SHIFT                     26
#define AIPS_MPRA_MPL0_MASK                      0x10000000u
#define AIPS_MPRA_MPL0_SHIFT                     28
#define AIPS_MPRA_MTW0_MASK                      0x20000000u
#define AIPS_MPRA_MTW0_SHIFT                     29
#define AIPS_MPRA_MTR0_MASK                      0x40000000u
#define AIPS_MPRA_MTR0_SHIFT                     30
/* PACRA Bit Fields */
#define AIPS_PACRA_TP7_MASK                      0x1u
#define AIPS_PACRA_TP7_SHIFT                     0
#define AIPS_PACRA_WP7_MASK                      0x2u
#define AIPS_PACRA_WP7_SHIFT                     1
#define AIPS_PACRA_SP7_MASK                      0x4u
#define AIPS_PACRA_SP7_SHIFT                     2
#define AIPS_PACRA_TP6_MASK                      0x10u
#define AIPS_PACRA_TP6_SHIFT                     4
#define AIPS_PACRA_WP6_MASK                      0x20u
#define AIPS_PACRA_WP6_SHIFT                     5
#define AIPS_PACRA_SP6_MASK                      0x40u
#define AIPS_PACRA_SP6_SHIFT                     6
#define AIPS_PACRA_TP5_MASK                      0x100u
#define AIPS_PACRA_TP5_SHIFT                     8
#define AIPS_PACRA_WP5_MASK                      0x200u
#define AIPS_PACRA_WP5_SHIFT                     9
#define AIPS_PACRA_SP5_MASK                      0x400u
#define AIPS_PACRA_SP5_SHIFT                     10
#define AIPS_PACRA_TP4_MASK                      0x1000u
#define AIPS_PACRA_TP4_SHIFT                     12
#define AIPS_PACRA_WP4_MASK                      0x2000u
#define AIPS_PACRA_WP4_SHIFT                     13
#define AIPS_PACRA_SP4_MASK                      0x4000u
#define AIPS_PACRA_SP4_SHIFT                     14
#define AIPS_PACRA_TP3_MASK                      0x10000u
#define AIPS_PACRA_TP3_SHIFT                     16
#define AIPS_PACRA_WP3_MASK                      0x20000u
#define AIPS_PACRA_WP3_SHIFT                     17
#define AIPS_PACRA_SP3_MASK                      0x40000u
#define AIPS_PACRA_SP3_SHIFT                     18
#define AIPS_PACRA_TP2_MASK                      0x100000u
#define AIPS_PACRA_TP2_SHIFT                     20
#define AIPS_PACRA_WP2_MASK                      0x200000u
#define AIPS_PACRA_WP2_SHIFT                     21
#define AIPS_PACRA_SP2_MASK                      0x400000u
#define AIPS_PACRA_SP2_SHIFT                     22
#define AIPS_PACRA_TP1_MASK                      0x1000000u
#define AIPS_PACRA_TP1_SHIFT                     24
#define AIPS_PACRA_WP1_MASK                      0x2000000u
#define AIPS_PACRA_WP1_SHIFT                     25
#define AIPS_PACRA_SP1_MASK                      0x4000000u
#define AIPS_PACRA_SP1_SHIFT                     26
#define AIPS_PACRA_TP0_MASK                      0x10000000u
#define AIPS_PACRA_TP0_SHIFT                     28
#define AIPS_PACRA_WP0_MASK                      0x20000000u
#define AIPS_PACRA_WP0_SHIFT                     29
#define AIPS_PACRA_SP0_MASK                      0x40000000u
#define AIPS_PACRA_SP0_SHIFT                     30
/* PACRB Bit Fields */
#define AIPS_PACRB_TP7_MASK                      0x1u
#define AIPS_PACRB_TP7_SHIFT                     0
#define AIPS_PACRB_WP7_MASK                      0x2u
#define AIPS_PACRB_WP7_SHIFT                     1
#define AIPS_PACRB_SP7_MASK                      0x4u
#define AIPS_PACRB_SP7_SHIFT                     2
#define AIPS_PACRB_TP6_MASK                      0x10u
#define AIPS_PACRB_TP6_SHIFT                     4
#define AIPS_PACRB_WP6_MASK                      0x20u
#define AIPS_PACRB_WP6_SHIFT                     5
#define AIPS_PACRB_SP6_MASK                      0x40u
#define AIPS_PACRB_SP6_SHIFT                     6
#define AIPS_PACRB_TP5_MASK                      0x100u
#define AIPS_PACRB_TP5_SHIFT                     8
#define AIPS_PACRB_WP5_MASK                      0x200u
#define AIPS_PACRB_WP5_SHIFT                     9
#define AIPS_PACRB_SP5_MASK                      0x400u
#define AIPS_PACRB_SP5_SHIFT                     10
#define AIPS_PACRB_TP4_MASK                      0x1000u
#define AIPS_PACRB_TP4_SHIFT                     12
#define AIPS_PACRB_WP4_MASK                      0x2000u
#define AIPS_PACRB_WP4_SHIFT                     13
#define AIPS_PACRB_SP4_MASK                      0x4000u
#define AIPS_PACRB_SP4_SHIFT                     14
#define AIPS_PACRB_TP3_MASK                      0x10000u
#define AIPS_PACRB_TP3_SHIFT                     16
#define AIPS_PACRB_WP3_MASK                      0x20000u
#define AIPS_PACRB_WP3_SHIFT                     17
#define AIPS_PACRB_SP3_MASK                      0x40000u
#define AIPS_PACRB_SP3_SHIFT                     18
#define AIPS_PACRB_TP2_MASK                      0x100000u
#define AIPS_PACRB_TP2_SHIFT                     20
#define AIPS_PACRB_WP2_MASK                      0x200000u
#define AIPS_PACRB_WP2_SHIFT                     21
#define AIPS_PACRB_SP2_MASK                      0x400000u
#define AIPS_PACRB_SP2_SHIFT                     22
#define AIPS_PACRB_TP1_MASK                      0x1000000u
#define AIPS_PACRB_TP1_SHIFT                     24
#define AIPS_PACRB_WP1_MASK                      0x2000000u
#define AIPS_PACRB_WP1_SHIFT                     25
#define AIPS_PACRB_SP1_MASK                      0x4000000u
#define AIPS_PACRB_SP1_SHIFT                     26
#define AIPS_PACRB_TP0_MASK                      0x10000000u
#define AIPS_PACRB_TP0_SHIFT                     28
#define AIPS_PACRB_WP0_MASK                      0x20000000u
#define AIPS_PACRB_WP0_SHIFT                     29
#define AIPS_PACRB_SP0_MASK                      0x40000000u
#define AIPS_PACRB_SP0_SHIFT                     30
/* PACRC Bit Fields */
#define AIPS_PACRC_TP7_MASK                      0x1u
#define AIPS_PACRC_TP7_SHIFT                     0
#define AIPS_PACRC_WP7_MASK                      0x2u
#define AIPS_PACRC_WP7_SHIFT                     1
#define AIPS_PACRC_SP7_MASK                      0x4u
#define AIPS_PACRC_SP7_SHIFT                     2
#define AIPS_PACRC_TP6_MASK                      0x10u
#define AIPS_PACRC_TP6_SHIFT                     4
#define AIPS_PACRC_WP6_MASK                      0x20u
#define AIPS_PACRC_WP6_SHIFT                     5
#define AIPS_PACRC_SP6_MASK                      0x40u
#define AIPS_PACRC_SP6_SHIFT                     6
#define AIPS_PACRC_TP5_MASK                      0x100u
#define AIPS_PACRC_TP5_SHIFT                     8
#define AIPS_PACRC_WP5_MASK                      0x200u
#define AIPS_PACRC_WP5_SHIFT                     9
#define AIPS_PACRC_SP5_MASK                      0x400u
#define AIPS_PACRC_SP5_SHIFT                     10
#define AIPS_PACRC_TP4_MASK                      0x1000u
#define AIPS_PACRC_TP4_SHIFT                     12
#define AIPS_PACRC_WP4_MASK                      0x2000u
#define AIPS_PACRC_WP4_SHIFT                     13
#define AIPS_PACRC_SP4_MASK                      0x4000u
#define AIPS_PACRC_SP4_SHIFT                     14
#define AIPS_PACRC_TP3_MASK                      0x10000u
#define AIPS_PACRC_TP3_SHIFT                     16
#define AIPS_PACRC_WP3_MASK                      0x20000u
#define AIPS_PACRC_WP3_SHIFT                     17
#define AIPS_PACRC_SP3_MASK                      0x40000u
#define AIPS_PACRC_SP3_SHIFT                     18
#define AIPS_PACRC_TP2_MASK                      0x100000u
#define AIPS_PACRC_TP2_SHIFT                     20
#define AIPS_PACRC_WP2_MASK                      0x200000u
#define AIPS_PACRC_WP2_SHIFT                     21
#define AIPS_PACRC_SP2_MASK                      0x400000u
#define AIPS_PACRC_SP2_SHIFT                     22
#define AIPS_PACRC_TP1_MASK                      0x1000000u
#define AIPS_PACRC_TP1_SHIFT                     24
#define AIPS_PACRC_WP1_MASK                      0x2000000u
#define AIPS_PACRC_WP1_SHIFT                     25
#define AIPS_PACRC_SP1_MASK                      0x4000000u
#define AIPS_PACRC_SP1_SHIFT                     26
#define AIPS_PACRC_TP0_MASK                      0x10000000u
#define AIPS_PACRC_TP0_SHIFT                     28
#define AIPS_PACRC_WP0_MASK                      0x20000000u
#define AIPS_PACRC_WP0_SHIFT                     29
#define AIPS_PACRC_SP0_MASK                      0x40000000u
#define AIPS_PACRC_SP0_SHIFT                     30
/* PACRD Bit Fields */
#define AIPS_PACRD_TP7_MASK                      0x1u
#define AIPS_PACRD_TP7_SHIFT                     0
#define AIPS_PACRD_WP7_MASK                      0x2u
#define AIPS_PACRD_WP7_SHIFT                     1
#define AIPS_PACRD_SP7_MASK                      0x4u
#define AIPS_PACRD_SP7_SHIFT                     2
#define AIPS_PACRD_TP6_MASK                      0x10u
#define AIPS_PACRD_TP6_SHIFT                     4
#define AIPS_PACRD_WP6_MASK                      0x20u
#define AIPS_PACRD_WP6_SHIFT                     5
#define AIPS_PACRD_SP6_MASK                      0x40u
#define AIPS_PACRD_SP6_SHIFT                     6
#define AIPS_PACRD_TP5_MASK                      0x100u
#define AIPS_PACRD_TP5_SHIFT                     8
#define AIPS_PACRD_WP5_MASK                      0x200u
#define AIPS_PACRD_WP5_SHIFT                     9
#define AIPS_PACRD_SP5_MASK                      0x400u
#define AIPS_PACRD_SP5_SHIFT                     10
#define AIPS_PACRD_TP4_MASK                      0x1000u
#define AIPS_PACRD_TP4_SHIFT                     12
#define AIPS_PACRD_WP4_MASK                      0x2000u
#define AIPS_PACRD_WP4_SHIFT                     13
#define AIPS_PACRD_SP4_MASK                      0x4000u
#define AIPS_PACRD_SP4_SHIFT                     14
#define AIPS_PACRD_TP3_MASK                      0x10000u
#define AIPS_PACRD_TP3_SHIFT                     16
#define AIPS_PACRD_WP3_MASK                      0x20000u
#define AIPS_PACRD_WP3_SHIFT                     17
#define AIPS_PACRD_SP3_MASK                      0x40000u
#define AIPS_PACRD_SP3_SHIFT                     18
#define AIPS_PACRD_TP2_MASK                      0x100000u
#define AIPS_PACRD_TP2_SHIFT                     20
#define AIPS_PACRD_WP2_MASK                      0x200000u
#define AIPS_PACRD_WP2_SHIFT                     21
#define AIPS_PACRD_SP2_MASK                      0x400000u
#define AIPS_PACRD_SP2_SHIFT                     22
#define AIPS_PACRD_TP1_MASK                      0x1000000u
#define AIPS_PACRD_TP1_SHIFT                     24
#define AIPS_PACRD_WP1_MASK                      0x2000000u
#define AIPS_PACRD_WP1_SHIFT                     25
#define AIPS_PACRD_SP1_MASK                      0x4000000u
#define AIPS_PACRD_SP1_SHIFT                     26
#define AIPS_PACRD_TP0_MASK                      0x10000000u
#define AIPS_PACRD_TP0_SHIFT                     28
#define AIPS_PACRD_WP0_MASK                      0x20000000u
#define AIPS_PACRD_WP0_SHIFT                     29
#define AIPS_PACRD_SP0_MASK                      0x40000000u
#define AIPS_PACRD_SP0_SHIFT                     30
/* PACRE Bit Fields */
#define AIPS_PACRE_TP7_MASK                      0x1u
#define AIPS_PACRE_TP7_SHIFT                     0
#define AIPS_PACRE_WP7_MASK                      0x2u
#define AIPS_PACRE_WP7_SHIFT                     1
#define AIPS_PACRE_SP7_MASK                      0x4u
#define AIPS_PACRE_SP7_SHIFT                     2
#define AIPS_PACRE_TP6_MASK                      0x10u
#define AIPS_PACRE_TP6_SHIFT                     4
#define AIPS_PACRE_WP6_MASK                      0x20u
#define AIPS_PACRE_WP6_SHIFT                     5
#define AIPS_PACRE_SP6_MASK                      0x40u
#define AIPS_PACRE_SP6_SHIFT                     6
#define AIPS_PACRE_TP5_MASK                      0x100u
#define AIPS_PACRE_TP5_SHIFT                     8
#define AIPS_PACRE_WP5_MASK                      0x200u
#define AIPS_PACRE_WP5_SHIFT                     9
#define AIPS_PACRE_SP5_MASK                      0x400u
#define AIPS_PACRE_SP5_SHIFT                     10
#define AIPS_PACRE_TP4_MASK                      0x1000u
#define AIPS_PACRE_TP4_SHIFT                     12
#define AIPS_PACRE_WP4_MASK                      0x2000u
#define AIPS_PACRE_WP4_SHIFT                     13
#define AIPS_PACRE_SP4_MASK                      0x4000u
#define AIPS_PACRE_SP4_SHIFT                     14
#define AIPS_PACRE_TP3_MASK                      0x10000u
#define AIPS_PACRE_TP3_SHIFT                     16
#define AIPS_PACRE_WP3_MASK                      0x20000u
#define AIPS_PACRE_WP3_SHIFT                     17
#define AIPS_PACRE_SP3_MASK                      0x40000u
#define AIPS_PACRE_SP3_SHIFT                     18
#define AIPS_PACRE_TP2_MASK                      0x100000u
#define AIPS_PACRE_TP2_SHIFT                     20
#define AIPS_PACRE_WP2_MASK                      0x200000u
#define AIPS_PACRE_WP2_SHIFT                     21
#define AIPS_PACRE_SP2_MASK                      0x400000u
#define AIPS_PACRE_SP2_SHIFT                     22
#define AIPS_PACRE_TP1_MASK                      0x1000000u
#define AIPS_PACRE_TP1_SHIFT                     24
#define AIPS_PACRE_WP1_MASK                      0x2000000u
#define AIPS_PACRE_WP1_SHIFT                     25
#define AIPS_PACRE_SP1_MASK                      0x4000000u
#define AIPS_PACRE_SP1_SHIFT                     26
#define AIPS_PACRE_TP0_MASK                      0x10000000u
#define AIPS_PACRE_TP0_SHIFT                     28
#define AIPS_PACRE_WP0_MASK                      0x20000000u
#define AIPS_PACRE_WP0_SHIFT                     29
#define AIPS_PACRE_SP0_MASK                      0x40000000u
#define AIPS_PACRE_SP0_SHIFT                     30
/* PACRF Bit Fields */
#define AIPS_PACRF_TP7_MASK                      0x1u
#define AIPS_PACRF_TP7_SHIFT                     0
#define AIPS_PACRF_WP7_MASK                      0x2u
#define AIPS_PACRF_WP7_SHIFT                     1
#define AIPS_PACRF_SP7_MASK                      0x4u
#define AIPS_PACRF_SP7_SHIFT                     2
#define AIPS_PACRF_TP6_MASK                      0x10u
#define AIPS_PACRF_TP6_SHIFT                     4
#define AIPS_PACRF_WP6_MASK                      0x20u
#define AIPS_PACRF_WP6_SHIFT                     5
#define AIPS_PACRF_SP6_MASK                      0x40u
#define AIPS_PACRF_SP6_SHIFT                     6
#define AIPS_PACRF_TP5_MASK                      0x100u
#define AIPS_PACRF_TP5_SHIFT                     8
#define AIPS_PACRF_WP5_MASK                      0x200u
#define AIPS_PACRF_WP5_SHIFT                     9
#define AIPS_PACRF_SP5_MASK                      0x400u
#define AIPS_PACRF_SP5_SHIFT                     10
#define AIPS_PACRF_TP4_MASK                      0x1000u
#define AIPS_PACRF_TP4_SHIFT                     12
#define AIPS_PACRF_WP4_MASK                      0x2000u
#define AIPS_PACRF_WP4_SHIFT                     13
#define AIPS_PACRF_SP4_MASK                      0x4000u
#define AIPS_PACRF_SP4_SHIFT                     14
#define AIPS_PACRF_TP3_MASK                      0x10000u
#define AIPS_PACRF_TP3_SHIFT                     16
#define AIPS_PACRF_WP3_MASK                      0x20000u
#define AIPS_PACRF_WP3_SHIFT                     17
#define AIPS_PACRF_SP3_MASK                      0x40000u
#define AIPS_PACRF_SP3_SHIFT                     18
#define AIPS_PACRF_TP2_MASK                      0x100000u
#define AIPS_PACRF_TP2_SHIFT                     20
#define AIPS_PACRF_WP2_MASK                      0x200000u
#define AIPS_PACRF_WP2_SHIFT                     21
#define AIPS_PACRF_SP2_MASK                      0x400000u
#define AIPS_PACRF_SP2_SHIFT                     22
#define AIPS_PACRF_TP1_MASK                      0x1000000u
#define AIPS_PACRF_TP1_SHIFT                     24
#define AIPS_PACRF_WP1_MASK                      0x2000000u
#define AIPS_PACRF_WP1_SHIFT                     25
#define AIPS_PACRF_SP1_MASK                      0x4000000u
#define AIPS_PACRF_SP1_SHIFT                     26
#define AIPS_PACRF_TP0_MASK                      0x10000000u
#define AIPS_PACRF_TP0_SHIFT                     28
#define AIPS_PACRF_WP0_MASK                      0x20000000u
#define AIPS_PACRF_WP0_SHIFT                     29
#define AIPS_PACRF_SP0_MASK                      0x40000000u
#define AIPS_PACRF_SP0_SHIFT                     30
/* PACRG Bit Fields */
#define AIPS_PACRG_TP7_MASK                      0x1u
#define AIPS_PACRG_TP7_SHIFT                     0
#define AIPS_PACRG_WP7_MASK                      0x2u
#define AIPS_PACRG_WP7_SHIFT                     1
#define AIPS_PACRG_SP7_MASK                      0x4u
#define AIPS_PACRG_SP7_SHIFT                     2
#define AIPS_PACRG_TP6_MASK                      0x10u
#define AIPS_PACRG_TP6_SHIFT                     4
#define AIPS_PACRG_WP6_MASK                      0x20u
#define AIPS_PACRG_WP6_SHIFT                     5
#define AIPS_PACRG_SP6_MASK                      0x40u
#define AIPS_PACRG_SP6_SHIFT                     6
#define AIPS_PACRG_TP5_MASK                      0x100u
#define AIPS_PACRG_TP5_SHIFT                     8
#define AIPS_PACRG_WP5_MASK                      0x200u
#define AIPS_PACRG_WP5_SHIFT                     9
#define AIPS_PACRG_SP5_MASK                      0x400u
#define AIPS_PACRG_SP5_SHIFT                     10
#define AIPS_PACRG_TP4_MASK                      0x1000u
#define AIPS_PACRG_TP4_SHIFT                     12
#define AIPS_PACRG_WP4_MASK                      0x2000u
#define AIPS_PACRG_WP4_SHIFT                     13
#define AIPS_PACRG_SP4_MASK                      0x4000u
#define AIPS_PACRG_SP4_SHIFT                     14
#define AIPS_PACRG_TP3_MASK                      0x10000u
#define AIPS_PACRG_TP3_SHIFT                     16
#define AIPS_PACRG_WP3_MASK                      0x20000u
#define AIPS_PACRG_WP3_SHIFT                     17
#define AIPS_PACRG_SP3_MASK                      0x40000u
#define AIPS_PACRG_SP3_SHIFT                     18
#define AIPS_PACRG_TP2_MASK                      0x100000u
#define AIPS_PACRG_TP2_SHIFT                     20
#define AIPS_PACRG_WP2_MASK                      0x200000u
#define AIPS_PACRG_WP2_SHIFT                     21
#define AIPS_PACRG_SP2_MASK                      0x400000u
#define AIPS_PACRG_SP2_SHIFT                     22
#define AIPS_PACRG_TP1_MASK                      0x1000000u
#define AIPS_PACRG_TP1_SHIFT                     24
#define AIPS_PACRG_WP1_MASK                      0x2000000u
#define AIPS_PACRG_WP1_SHIFT                     25
#define AIPS_PACRG_SP1_MASK                      0x4000000u
#define AIPS_PACRG_SP1_SHIFT                     26
#define AIPS_PACRG_TP0_MASK                      0x10000000u
#define AIPS_PACRG_TP0_SHIFT                     28
#define AIPS_PACRG_WP0_MASK                      0x20000000u
#define AIPS_PACRG_WP0_SHIFT                     29
#define AIPS_PACRG_SP0_MASK                      0x40000000u
#define AIPS_PACRG_SP0_SHIFT                     30
/* PACRH Bit Fields */
#define AIPS_PACRH_TP7_MASK                      0x1u
#define AIPS_PACRH_TP7_SHIFT                     0
#define AIPS_PACRH_WP7_MASK                      0x2u
#define AIPS_PACRH_WP7_SHIFT                     1
#define AIPS_PACRH_SP7_MASK                      0x4u
#define AIPS_PACRH_SP7_SHIFT                     2
#define AIPS_PACRH_TP6_MASK                      0x10u
#define AIPS_PACRH_TP6_SHIFT                     4
#define AIPS_PACRH_WP6_MASK                      0x20u
#define AIPS_PACRH_WP6_SHIFT                     5
#define AIPS_PACRH_SP6_MASK                      0x40u
#define AIPS_PACRH_SP6_SHIFT                     6
#define AIPS_PACRH_TP5_MASK                      0x100u
#define AIPS_PACRH_TP5_SHIFT                     8
#define AIPS_PACRH_WP5_MASK                      0x200u
#define AIPS_PACRH_WP5_SHIFT                     9
#define AIPS_PACRH_SP5_MASK                      0x400u
#define AIPS_PACRH_SP5_SHIFT                     10
#define AIPS_PACRH_TP4_MASK                      0x1000u
#define AIPS_PACRH_TP4_SHIFT                     12
#define AIPS_PACRH_WP4_MASK                      0x2000u
#define AIPS_PACRH_WP4_SHIFT                     13
#define AIPS_PACRH_SP4_MASK                      0x4000u
#define AIPS_PACRH_SP4_SHIFT                     14
#define AIPS_PACRH_TP3_MASK                      0x10000u
#define AIPS_PACRH_TP3_SHIFT                     16
#define AIPS_PACRH_WP3_MASK                      0x20000u
#define AIPS_PACRH_WP3_SHIFT                     17
#define AIPS_PACRH_SP3_MASK                      0x40000u
#define AIPS_PACRH_SP3_SHIFT                     18
#define AIPS_PACRH_TP2_MASK                      0x100000u
#define AIPS_PACRH_TP2_SHIFT                     20
#define AIPS_PACRH_WP2_MASK                      0x200000u
#define AIPS_PACRH_WP2_SHIFT                     21
#define AIPS_PACRH_SP2_MASK                      0x400000u
#define AIPS_PACRH_SP2_SHIFT                     22
#define AIPS_PACRH_TP1_MASK                      0x1000000u
#define AIPS_PACRH_TP1_SHIFT                     24
#define AIPS_PACRH_WP1_MASK                      0x2000000u
#define AIPS_PACRH_WP1_SHIFT                     25
#define AIPS_PACRH_SP1_MASK                      0x4000000u
#define AIPS_PACRH_SP1_SHIFT                     26
#define AIPS_PACRH_TP0_MASK                      0x10000000u
#define AIPS_PACRH_TP0_SHIFT                     28
#define AIPS_PACRH_WP0_MASK                      0x20000000u
#define AIPS_PACRH_WP0_SHIFT                     29
#define AIPS_PACRH_SP0_MASK                      0x40000000u
#define AIPS_PACRH_SP0_SHIFT                     30
/* PACRI Bit Fields */
#define AIPS_PACRI_TP7_MASK                      0x1u
#define AIPS_PACRI_TP7_SHIFT                     0
#define AIPS_PACRI_WP7_MASK                      0x2u
#define AIPS_PACRI_WP7_SHIFT                     1
#define AIPS_PACRI_SP7_MASK                      0x4u
#define AIPS_PACRI_SP7_SHIFT                     2
#define AIPS_PACRI_TP6_MASK                      0x10u
#define AIPS_PACRI_TP6_SHIFT                     4
#define AIPS_PACRI_WP6_MASK                      0x20u
#define AIPS_PACRI_WP6_SHIFT                     5
#define AIPS_PACRI_SP6_MASK                      0x40u
#define AIPS_PACRI_SP6_SHIFT                     6
#define AIPS_PACRI_TP5_MASK                      0x100u
#define AIPS_PACRI_TP5_SHIFT                     8
#define AIPS_PACRI_WP5_MASK                      0x200u
#define AIPS_PACRI_WP5_SHIFT                     9
#define AIPS_PACRI_SP5_MASK                      0x400u
#define AIPS_PACRI_SP5_SHIFT                     10
#define AIPS_PACRI_TP4_MASK                      0x1000u
#define AIPS_PACRI_TP4_SHIFT                     12
#define AIPS_PACRI_WP4_MASK                      0x2000u
#define AIPS_PACRI_WP4_SHIFT                     13
#define AIPS_PACRI_SP4_MASK                      0x4000u
#define AIPS_PACRI_SP4_SHIFT                     14
#define AIPS_PACRI_TP3_MASK                      0x10000u
#define AIPS_PACRI_TP3_SHIFT                     16
#define AIPS_PACRI_WP3_MASK                      0x20000u
#define AIPS_PACRI_WP3_SHIFT                     17
#define AIPS_PACRI_SP3_MASK                      0x40000u
#define AIPS_PACRI_SP3_SHIFT                     18
#define AIPS_PACRI_TP2_MASK                      0x100000u
#define AIPS_PACRI_TP2_SHIFT                     20
#define AIPS_PACRI_WP2_MASK                      0x200000u
#define AIPS_PACRI_WP2_SHIFT                     21
#define AIPS_PACRI_SP2_MASK                      0x400000u
#define AIPS_PACRI_SP2_SHIFT                     22
#define AIPS_PACRI_TP1_MASK                      0x1000000u
#define AIPS_PACRI_TP1_SHIFT                     24
#define AIPS_PACRI_WP1_MASK                      0x2000000u
#define AIPS_PACRI_WP1_SHIFT                     25
#define AIPS_PACRI_SP1_MASK                      0x4000000u
#define AIPS_PACRI_SP1_SHIFT                     26
#define AIPS_PACRI_TP0_MASK                      0x10000000u
#define AIPS_PACRI_TP0_SHIFT                     28
#define AIPS_PACRI_WP0_MASK                      0x20000000u
#define AIPS_PACRI_WP0_SHIFT                     29
#define AIPS_PACRI_SP0_MASK                      0x40000000u
#define AIPS_PACRI_SP0_SHIFT                     30
/* PACRJ Bit Fields */
#define AIPS_PACRJ_TP7_MASK                      0x1u
#define AIPS_PACRJ_TP7_SHIFT                     0
#define AIPS_PACRJ_WP7_MASK                      0x2u
#define AIPS_PACRJ_WP7_SHIFT                     1
#define AIPS_PACRJ_SP7_MASK                      0x4u
#define AIPS_PACRJ_SP7_SHIFT                     2
#define AIPS_PACRJ_TP6_MASK                      0x10u
#define AIPS_PACRJ_TP6_SHIFT                     4
#define AIPS_PACRJ_WP6_MASK                      0x20u
#define AIPS_PACRJ_WP6_SHIFT                     5
#define AIPS_PACRJ_SP6_MASK                      0x40u
#define AIPS_PACRJ_SP6_SHIFT                     6
#define AIPS_PACRJ_TP5_MASK                      0x100u
#define AIPS_PACRJ_TP5_SHIFT                     8
#define AIPS_PACRJ_WP5_MASK                      0x200u
#define AIPS_PACRJ_WP5_SHIFT                     9
#define AIPS_PACRJ_SP5_MASK                      0x400u
#define AIPS_PACRJ_SP5_SHIFT                     10
#define AIPS_PACRJ_TP4_MASK                      0x1000u
#define AIPS_PACRJ_TP4_SHIFT                     12
#define AIPS_PACRJ_WP4_MASK                      0x2000u
#define AIPS_PACRJ_WP4_SHIFT                     13
#define AIPS_PACRJ_SP4_MASK                      0x4000u
#define AIPS_PACRJ_SP4_SHIFT                     14
#define AIPS_PACRJ_TP3_MASK                      0x10000u
#define AIPS_PACRJ_TP3_SHIFT                     16
#define AIPS_PACRJ_WP3_MASK                      0x20000u
#define AIPS_PACRJ_WP3_SHIFT                     17
#define AIPS_PACRJ_SP3_MASK                      0x40000u
#define AIPS_PACRJ_SP3_SHIFT                     18
#define AIPS_PACRJ_TP2_MASK                      0x100000u
#define AIPS_PACRJ_TP2_SHIFT                     20
#define AIPS_PACRJ_WP2_MASK                      0x200000u
#define AIPS_PACRJ_WP2_SHIFT                     21
#define AIPS_PACRJ_SP2_MASK                      0x400000u
#define AIPS_PACRJ_SP2_SHIFT                     22
#define AIPS_PACRJ_TP1_MASK                      0x1000000u
#define AIPS_PACRJ_TP1_SHIFT                     24
#define AIPS_PACRJ_WP1_MASK                      0x2000000u
#define AIPS_PACRJ_WP1_SHIFT                     25
#define AIPS_PACRJ_SP1_MASK                      0x4000000u
#define AIPS_PACRJ_SP1_SHIFT                     26
#define AIPS_PACRJ_TP0_MASK                      0x10000000u
#define AIPS_PACRJ_TP0_SHIFT                     28
#define AIPS_PACRJ_WP0_MASK                      0x20000000u
#define AIPS_PACRJ_WP0_SHIFT                     29
#define AIPS_PACRJ_SP0_MASK                      0x40000000u
#define AIPS_PACRJ_SP0_SHIFT                     30
/* PACRK Bit Fields */
#define AIPS_PACRK_TP7_MASK                      0x1u
#define AIPS_PACRK_TP7_SHIFT                     0
#define AIPS_PACRK_WP7_MASK                      0x2u
#define AIPS_PACRK_WP7_SHIFT                     1
#define AIPS_PACRK_SP7_MASK                      0x4u
#define AIPS_PACRK_SP7_SHIFT                     2
#define AIPS_PACRK_TP6_MASK                      0x10u
#define AIPS_PACRK_TP6_SHIFT                     4
#define AIPS_PACRK_WP6_MASK                      0x20u
#define AIPS_PACRK_WP6_SHIFT                     5
#define AIPS_PACRK_SP6_MASK                      0x40u
#define AIPS_PACRK_SP6_SHIFT                     6
#define AIPS_PACRK_TP5_MASK                      0x100u
#define AIPS_PACRK_TP5_SHIFT                     8
#define AIPS_PACRK_WP5_MASK                      0x200u
#define AIPS_PACRK_WP5_SHIFT                     9
#define AIPS_PACRK_SP5_MASK                      0x400u
#define AIPS_PACRK_SP5_SHIFT                     10
#define AIPS_PACRK_TP4_MASK                      0x1000u
#define AIPS_PACRK_TP4_SHIFT                     12
#define AIPS_PACRK_WP4_MASK                      0x2000u
#define AIPS_PACRK_WP4_SHIFT                     13
#define AIPS_PACRK_SP4_MASK                      0x4000u
#define AIPS_PACRK_SP4_SHIFT                     14
#define AIPS_PACRK_TP3_MASK                      0x10000u
#define AIPS_PACRK_TP3_SHIFT                     16
#define AIPS_PACRK_WP3_MASK                      0x20000u
#define AIPS_PACRK_WP3_SHIFT                     17
#define AIPS_PACRK_SP3_MASK                      0x40000u
#define AIPS_PACRK_SP3_SHIFT                     18
#define AIPS_PACRK_TP2_MASK                      0x100000u
#define AIPS_PACRK_TP2_SHIFT                     20
#define AIPS_PACRK_WP2_MASK                      0x200000u
#define AIPS_PACRK_WP2_SHIFT                     21
#define AIPS_PACRK_SP2_MASK                      0x400000u
#define AIPS_PACRK_SP2_SHIFT                     22
#define AIPS_PACRK_TP1_MASK                      0x1000000u
#define AIPS_PACRK_TP1_SHIFT                     24
#define AIPS_PACRK_WP1_MASK                      0x2000000u
#define AIPS_PACRK_WP1_SHIFT                     25
#define AIPS_PACRK_SP1_MASK                      0x4000000u
#define AIPS_PACRK_SP1_SHIFT                     26
#define AIPS_PACRK_TP0_MASK                      0x10000000u
#define AIPS_PACRK_TP0_SHIFT                     28
#define AIPS_PACRK_WP0_MASK                      0x20000000u
#define AIPS_PACRK_WP0_SHIFT                     29
#define AIPS_PACRK_SP0_MASK                      0x40000000u
#define AIPS_PACRK_SP0_SHIFT                     30
/* PACRL Bit Fields */
#define AIPS_PACRL_TP7_MASK                      0x1u
#define AIPS_PACRL_TP7_SHIFT                     0
#define AIPS_PACRL_WP7_MASK                      0x2u
#define AIPS_PACRL_WP7_SHIFT                     1
#define AIPS_PACRL_SP7_MASK                      0x4u
#define AIPS_PACRL_SP7_SHIFT                     2
#define AIPS_PACRL_TP6_MASK                      0x10u
#define AIPS_PACRL_TP6_SHIFT                     4
#define AIPS_PACRL_WP6_MASK                      0x20u
#define AIPS_PACRL_WP6_SHIFT                     5
#define AIPS_PACRL_SP6_MASK                      0x40u
#define AIPS_PACRL_SP6_SHIFT                     6
#define AIPS_PACRL_TP5_MASK                      0x100u
#define AIPS_PACRL_TP5_SHIFT                     8
#define AIPS_PACRL_WP5_MASK                      0x200u
#define AIPS_PACRL_WP5_SHIFT                     9
#define AIPS_PACRL_SP5_MASK                      0x400u
#define AIPS_PACRL_SP5_SHIFT                     10
#define AIPS_PACRL_TP4_MASK                      0x1000u
#define AIPS_PACRL_TP4_SHIFT                     12
#define AIPS_PACRL_WP4_MASK                      0x2000u
#define AIPS_PACRL_WP4_SHIFT                     13
#define AIPS_PACRL_SP4_MASK                      0x4000u
#define AIPS_PACRL_SP4_SHIFT                     14
#define AIPS_PACRL_TP3_MASK                      0x10000u
#define AIPS_PACRL_TP3_SHIFT                     16
#define AIPS_PACRL_WP3_MASK                      0x20000u
#define AIPS_PACRL_WP3_SHIFT                     17
#define AIPS_PACRL_SP3_MASK                      0x40000u
#define AIPS_PACRL_SP3_SHIFT                     18
#define AIPS_PACRL_TP2_MASK                      0x100000u
#define AIPS_PACRL_TP2_SHIFT                     20
#define AIPS_PACRL_WP2_MASK                      0x200000u
#define AIPS_PACRL_WP2_SHIFT                     21
#define AIPS_PACRL_SP2_MASK                      0x400000u
#define AIPS_PACRL_SP2_SHIFT                     22
#define AIPS_PACRL_TP1_MASK                      0x1000000u
#define AIPS_PACRL_TP1_SHIFT                     24
#define AIPS_PACRL_WP1_MASK                      0x2000000u
#define AIPS_PACRL_WP1_SHIFT                     25
#define AIPS_PACRL_SP1_MASK                      0x4000000u
#define AIPS_PACRL_SP1_SHIFT                     26
#define AIPS_PACRL_TP0_MASK                      0x10000000u
#define AIPS_PACRL_TP0_SHIFT                     28
#define AIPS_PACRL_WP0_MASK                      0x20000000u
#define AIPS_PACRL_WP0_SHIFT                     29
#define AIPS_PACRL_SP0_MASK                      0x40000000u
#define AIPS_PACRL_SP0_SHIFT                     30
/* PACRM Bit Fields */
#define AIPS_PACRM_TP7_MASK                      0x1u
#define AIPS_PACRM_TP7_SHIFT                     0
#define AIPS_PACRM_WP7_MASK                      0x2u
#define AIPS_PACRM_WP7_SHIFT                     1
#define AIPS_PACRM_SP7_MASK                      0x4u
#define AIPS_PACRM_SP7_SHIFT                     2
#define AIPS_PACRM_TP6_MASK                      0x10u
#define AIPS_PACRM_TP6_SHIFT                     4
#define AIPS_PACRM_WP6_MASK                      0x20u
#define AIPS_PACRM_WP6_SHIFT                     5
#define AIPS_PACRM_SP6_MASK                      0x40u
#define AIPS_PACRM_SP6_SHIFT                     6
#define AIPS_PACRM_TP5_MASK                      0x100u
#define AIPS_PACRM_TP5_SHIFT                     8
#define AIPS_PACRM_WP5_MASK                      0x200u
#define AIPS_PACRM_WP5_SHIFT                     9
#define AIPS_PACRM_SP5_MASK                      0x400u
#define AIPS_PACRM_SP5_SHIFT                     10
#define AIPS_PACRM_TP4_MASK                      0x1000u
#define AIPS_PACRM_TP4_SHIFT                     12
#define AIPS_PACRM_WP4_MASK                      0x2000u
#define AIPS_PACRM_WP4_SHIFT                     13
#define AIPS_PACRM_SP4_MASK                      0x4000u
#define AIPS_PACRM_SP4_SHIFT                     14
#define AIPS_PACRM_TP3_MASK                      0x10000u
#define AIPS_PACRM_TP3_SHIFT                     16
#define AIPS_PACRM_WP3_MASK                      0x20000u
#define AIPS_PACRM_WP3_SHIFT                     17
#define AIPS_PACRM_SP3_MASK                      0x40000u
#define AIPS_PACRM_SP3_SHIFT                     18
#define AIPS_PACRM_TP2_MASK                      0x100000u
#define AIPS_PACRM_TP2_SHIFT                     20
#define AIPS_PACRM_WP2_MASK                      0x200000u
#define AIPS_PACRM_WP2_SHIFT                     21
#define AIPS_PACRM_SP2_MASK                      0x400000u
#define AIPS_PACRM_SP2_SHIFT                     22
#define AIPS_PACRM_TP1_MASK                      0x1000000u
#define AIPS_PACRM_TP1_SHIFT                     24
#define AIPS_PACRM_WP1_MASK                      0x2000000u
#define AIPS_PACRM_WP1_SHIFT                     25
#define AIPS_PACRM_SP1_MASK                      0x4000000u
#define AIPS_PACRM_SP1_SHIFT                     26
#define AIPS_PACRM_TP0_MASK                      0x10000000u
#define AIPS_PACRM_TP0_SHIFT                     28
#define AIPS_PACRM_WP0_MASK                      0x20000000u
#define AIPS_PACRM_WP0_SHIFT                     29
#define AIPS_PACRM_SP0_MASK                      0x40000000u
#define AIPS_PACRM_SP0_SHIFT                     30
/* PACRN Bit Fields */
#define AIPS_PACRN_TP7_MASK                      0x1u
#define AIPS_PACRN_TP7_SHIFT                     0
#define AIPS_PACRN_WP7_MASK                      0x2u
#define AIPS_PACRN_WP7_SHIFT                     1
#define AIPS_PACRN_SP7_MASK                      0x4u
#define AIPS_PACRN_SP7_SHIFT                     2
#define AIPS_PACRN_TP6_MASK                      0x10u
#define AIPS_PACRN_TP6_SHIFT                     4
#define AIPS_PACRN_WP6_MASK                      0x20u
#define AIPS_PACRN_WP6_SHIFT                     5
#define AIPS_PACRN_SP6_MASK                      0x40u
#define AIPS_PACRN_SP6_SHIFT                     6
#define AIPS_PACRN_TP5_MASK                      0x100u
#define AIPS_PACRN_TP5_SHIFT                     8
#define AIPS_PACRN_WP5_MASK                      0x200u
#define AIPS_PACRN_WP5_SHIFT                     9
#define AIPS_PACRN_SP5_MASK                      0x400u
#define AIPS_PACRN_SP5_SHIFT                     10
#define AIPS_PACRN_TP4_MASK                      0x1000u
#define AIPS_PACRN_TP4_SHIFT                     12
#define AIPS_PACRN_WP4_MASK                      0x2000u
#define AIPS_PACRN_WP4_SHIFT                     13
#define AIPS_PACRN_SP4_MASK                      0x4000u
#define AIPS_PACRN_SP4_SHIFT                     14
#define AIPS_PACRN_TP3_MASK                      0x10000u
#define AIPS_PACRN_TP3_SHIFT                     16
#define AIPS_PACRN_WP3_MASK                      0x20000u
#define AIPS_PACRN_WP3_SHIFT                     17
#define AIPS_PACRN_SP3_MASK                      0x40000u
#define AIPS_PACRN_SP3_SHIFT                     18
#define AIPS_PACRN_TP2_MASK                      0x100000u
#define AIPS_PACRN_TP2_SHIFT                     20
#define AIPS_PACRN_WP2_MASK                      0x200000u
#define AIPS_PACRN_WP2_SHIFT                     21
#define AIPS_PACRN_SP2_MASK                      0x400000u
#define AIPS_PACRN_SP2_SHIFT                     22
#define AIPS_PACRN_TP1_MASK                      0x1000000u
#define AIPS_PACRN_TP1_SHIFT                     24
#define AIPS_PACRN_WP1_MASK                      0x2000000u
#define AIPS_PACRN_WP1_SHIFT                     25
#define AIPS_PACRN_SP1_MASK                      0x4000000u
#define AIPS_PACRN_SP1_SHIFT                     26
#define AIPS_PACRN_TP0_MASK                      0x10000000u
#define AIPS_PACRN_TP0_SHIFT                     28
#define AIPS_PACRN_WP0_MASK                      0x20000000u
#define AIPS_PACRN_WP0_SHIFT                     29
#define AIPS_PACRN_SP0_MASK                      0x40000000u
#define AIPS_PACRN_SP0_SHIFT                     30
/* PACRO Bit Fields */
#define AIPS_PACRO_TP7_MASK                      0x1u
#define AIPS_PACRO_TP7_SHIFT                     0
#define AIPS_PACRO_WP7_MASK                      0x2u
#define AIPS_PACRO_WP7_SHIFT                     1
#define AIPS_PACRO_SP7_MASK                      0x4u
#define AIPS_PACRO_SP7_SHIFT                     2
#define AIPS_PACRO_TP6_MASK                      0x10u
#define AIPS_PACRO_TP6_SHIFT                     4
#define AIPS_PACRO_WP6_MASK                      0x20u
#define AIPS_PACRO_WP6_SHIFT                     5
#define AIPS_PACRO_SP6_MASK                      0x40u
#define AIPS_PACRO_SP6_SHIFT                     6
#define AIPS_PACRO_TP5_MASK                      0x100u
#define AIPS_PACRO_TP5_SHIFT                     8
#define AIPS_PACRO_WP5_MASK                      0x200u
#define AIPS_PACRO_WP5_SHIFT                     9
#define AIPS_PACRO_SP5_MASK                      0x400u
#define AIPS_PACRO_SP5_SHIFT                     10
#define AIPS_PACRO_TP4_MASK                      0x1000u
#define AIPS_PACRO_TP4_SHIFT                     12
#define AIPS_PACRO_WP4_MASK                      0x2000u
#define AIPS_PACRO_WP4_SHIFT                     13
#define AIPS_PACRO_SP4_MASK                      0x4000u
#define AIPS_PACRO_SP4_SHIFT                     14
#define AIPS_PACRO_TP3_MASK                      0x10000u
#define AIPS_PACRO_TP3_SHIFT                     16
#define AIPS_PACRO_WP3_MASK                      0x20000u
#define AIPS_PACRO_WP3_SHIFT                     17
#define AIPS_PACRO_SP3_MASK                      0x40000u
#define AIPS_PACRO_SP3_SHIFT                     18
#define AIPS_PACRO_TP2_MASK                      0x100000u
#define AIPS_PACRO_TP2_SHIFT                     20
#define AIPS_PACRO_WP2_MASK                      0x200000u
#define AIPS_PACRO_WP2_SHIFT                     21
#define AIPS_PACRO_SP2_MASK                      0x400000u
#define AIPS_PACRO_SP2_SHIFT                     22
#define AIPS_PACRO_TP1_MASK                      0x1000000u
#define AIPS_PACRO_TP1_SHIFT                     24
#define AIPS_PACRO_WP1_MASK                      0x2000000u
#define AIPS_PACRO_WP1_SHIFT                     25
#define AIPS_PACRO_SP1_MASK                      0x4000000u
#define AIPS_PACRO_SP1_SHIFT                     26
#define AIPS_PACRO_TP0_MASK                      0x10000000u
#define AIPS_PACRO_TP0_SHIFT                     28
#define AIPS_PACRO_WP0_MASK                      0x20000000u
#define AIPS_PACRO_WP0_SHIFT                     29
#define AIPS_PACRO_SP0_MASK                      0x40000000u
#define AIPS_PACRO_SP0_SHIFT                     30
/* PACRP Bit Fields */
#define AIPS_PACRP_TP7_MASK                      0x1u
#define AIPS_PACRP_TP7_SHIFT                     0
#define AIPS_PACRP_WP7_MASK                      0x2u
#define AIPS_PACRP_WP7_SHIFT                     1
#define AIPS_PACRP_SP7_MASK                      0x4u
#define AIPS_PACRP_SP7_SHIFT                     2
#define AIPS_PACRP_TP6_MASK                      0x10u
#define AIPS_PACRP_TP6_SHIFT                     4
#define AIPS_PACRP_WP6_MASK                      0x20u
#define AIPS_PACRP_WP6_SHIFT                     5
#define AIPS_PACRP_SP6_MASK                      0x40u
#define AIPS_PACRP_SP6_SHIFT                     6
#define AIPS_PACRP_TP5_MASK                      0x100u
#define AIPS_PACRP_TP5_SHIFT                     8
#define AIPS_PACRP_WP5_MASK                      0x200u
#define AIPS_PACRP_WP5_SHIFT                     9
#define AIPS_PACRP_SP5_MASK                      0x400u
#define AIPS_PACRP_SP5_SHIFT                     10
#define AIPS_PACRP_TP4_MASK                      0x1000u
#define AIPS_PACRP_TP4_SHIFT                     12
#define AIPS_PACRP_WP4_MASK                      0x2000u
#define AIPS_PACRP_WP4_SHIFT                     13
#define AIPS_PACRP_SP4_MASK                      0x4000u
#define AIPS_PACRP_SP4_SHIFT                     14
#define AIPS_PACRP_TP3_MASK                      0x10000u
#define AIPS_PACRP_TP3_SHIFT                     16
#define AIPS_PACRP_WP3_MASK                      0x20000u
#define AIPS_PACRP_WP3_SHIFT                     17
#define AIPS_PACRP_SP3_MASK                      0x40000u
#define AIPS_PACRP_SP3_SHIFT                     18
#define AIPS_PACRP_TP2_MASK                      0x100000u
#define AIPS_PACRP_TP2_SHIFT                     20
#define AIPS_PACRP_WP2_MASK                      0x200000u
#define AIPS_PACRP_WP2_SHIFT                     21
#define AIPS_PACRP_SP2_MASK                      0x400000u
#define AIPS_PACRP_SP2_SHIFT                     22
#define AIPS_PACRP_TP1_MASK                      0x1000000u
#define AIPS_PACRP_TP1_SHIFT                     24
#define AIPS_PACRP_WP1_MASK                      0x2000000u
#define AIPS_PACRP_WP1_SHIFT                     25
#define AIPS_PACRP_SP1_MASK                      0x4000000u
#define AIPS_PACRP_SP1_SHIFT                     26
#define AIPS_PACRP_TP0_MASK                      0x10000000u
#define AIPS_PACRP_TP0_SHIFT                     28
#define AIPS_PACRP_WP0_MASK                      0x20000000u
#define AIPS_PACRP_WP0_SHIFT                     29
#define AIPS_PACRP_SP0_MASK                      0x40000000u
#define AIPS_PACRP_SP0_SHIFT                     30

/*! \} */ /* end of group AIPS_Register_Masks */


/* AIPS - Peripheral instance base addresses */
/*! Peripheral AIPS0 base pointer */
#define AIPS0_BASE_PTR                           ((AIPS_MemMapPtr)0x40000000u)
/*! Peripheral AIPS1 base pointer */
#define AIPS1_BASE_PTR                           ((AIPS_MemMapPtr)0x40080000u)

/* ----------------------------------------------------------------------------
   -- AIPS - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup AIPS_Register_Accessor_Macros AIPS - Register accessor macros */
/*! \{ */


/* AIPS - Register instance definitions */
/* AIPS0 */
#define AIPS0_MPRA                               AIPS_MPRA_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRA                              AIPS_PACRA_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRB                              AIPS_PACRB_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRC                              AIPS_PACRC_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRD                              AIPS_PACRD_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRE                              AIPS_PACRE_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRF                              AIPS_PACRF_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRG                              AIPS_PACRG_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRH                              AIPS_PACRH_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRI                              AIPS_PACRI_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRJ                              AIPS_PACRJ_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRK                              AIPS_PACRK_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRL                              AIPS_PACRL_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRM                              AIPS_PACRM_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRN                              AIPS_PACRN_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRO                              AIPS_PACRO_REG(AIPS0_BASE_PTR)
#define AIPS0_PACRP                              AIPS_PACRP_REG(AIPS0_BASE_PTR)
/* AIPS1 */
#define AIPS1_MPRA                               AIPS_MPRA_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRA                              AIPS_PACRA_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRB                              AIPS_PACRB_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRC                              AIPS_PACRC_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRD                              AIPS_PACRD_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRE                              AIPS_PACRE_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRF                              AIPS_PACRF_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRG                              AIPS_PACRG_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRH                              AIPS_PACRH_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRI                              AIPS_PACRI_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRJ                              AIPS_PACRJ_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRK                              AIPS_PACRK_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRL                              AIPS_PACRL_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRM                              AIPS_PACRM_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRN                              AIPS_PACRN_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRO                              AIPS_PACRO_REG(AIPS1_BASE_PTR)
#define AIPS1_PACRP                              AIPS_PACRP_REG(AIPS1_BASE_PTR)

/*! \} */ /* end of group AIPS_Register_Accessor_Macros */


/*! \} */ /* end of group AIPS_Peripheral */


/* ----------------------------------------------------------------------------
   -- AXBS
   ---------------------------------------------------------------------------- */

/*! \addtogroup AXBS_Peripheral AXBS */
/*! \{ */

/*! AXBS - Peripheral register structure */
typedef struct AXBS_MemMap {
  struct {                                         /* offset: 0x0, array step: 0x100 */
    uint32_t PRS;                                    /*!< Priority Registers Slave, array offset: 0x0, array step: 0x100 */
    uint8_t RESERVED_0[12];
    uint32_t CRS;                                    /*!< Control Register, array offset: 0x10, array step: 0x100 */
    uint8_t RESERVED_1[236];
  } SLAVE[5];
  uint8_t RESERVED_0[768];
  uint32_t MGPCR0;                                 /*!< Master General Purpose Control Register, offset: 0x800 */
  uint8_t RESERVED_1[252];
  uint32_t MGPCR1;                                 /*!< Master General Purpose Control Register, offset: 0x900 */
  uint8_t RESERVED_2[252];
  uint32_t MGPCR2;                                 /*!< Master General Purpose Control Register, offset: 0xA00 */
  uint8_t RESERVED_3[508];
  uint32_t MGPCR4;                                 /*!< Master General Purpose Control Register, offset: 0xC00 */
  uint8_t RESERVED_4[252];
  uint32_t MGPCR5;                                 /*!< Master General Purpose Control Register, offset: 0xD00 */
} volatile *AXBS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- AXBS - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup AXBS_Register_Accessor_Macros AXBS - Register accessor macros */
/*! \{ */


/* AXBS - Register accessors */
#define AXBS_PRS_REG(base,index)                 ((base)->SLAVE[index].PRS)
#define AXBS_CRS_REG(base,index)                 ((base)->SLAVE[index].CRS)
#define AXBS_MGPCR0_REG(base)                    ((base)->MGPCR0)
#define AXBS_MGPCR1_REG(base)                    ((base)->MGPCR1)
#define AXBS_MGPCR2_REG(base)                    ((base)->MGPCR2)
#define AXBS_MGPCR4_REG(base)                    ((base)->MGPCR4)
#define AXBS_MGPCR5_REG(base)                    ((base)->MGPCR5)

/*! \} */ /* end of group AXBS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- AXBS Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup AXBS_Register_Masks AXBS Register Masks */
/*! \{ */

/* PRS Bit Fields */
#define AXBS_PRS_M0_MASK                         0x7u
#define AXBS_PRS_M0_SHIFT                        0
#define AXBS_PRS_M0(x)                           (((x)<<AXBS_PRS_M0_SHIFT)&AXBS_PRS_M0_MASK)
#define AXBS_PRS_M1_MASK                         0x70u
#define AXBS_PRS_M1_SHIFT                        4
#define AXBS_PRS_M1(x)                           (((x)<<AXBS_PRS_M1_SHIFT)&AXBS_PRS_M1_MASK)
#define AXBS_PRS_M2_MASK                         0x700u
#define AXBS_PRS_M2_SHIFT                        8
#define AXBS_PRS_M2(x)                           (((x)<<AXBS_PRS_M2_SHIFT)&AXBS_PRS_M2_MASK)
#define AXBS_PRS_M3_MASK                         0x7000u
#define AXBS_PRS_M3_SHIFT                        12
#define AXBS_PRS_M3(x)                           (((x)<<AXBS_PRS_M3_SHIFT)&AXBS_PRS_M3_MASK)
#define AXBS_PRS_M4_MASK                         0x70000u
#define AXBS_PRS_M4_SHIFT                        16
#define AXBS_PRS_M4(x)                           (((x)<<AXBS_PRS_M4_SHIFT)&AXBS_PRS_M4_MASK)
#define AXBS_PRS_M5_MASK                         0x700000u
#define AXBS_PRS_M5_SHIFT                        20
#define AXBS_PRS_M5(x)                           (((x)<<AXBS_PRS_M5_SHIFT)&AXBS_PRS_M5_MASK)
/* CRS Bit Fields */
#define AXBS_CRS_PARK_MASK                       0x7u
#define AXBS_CRS_PARK_SHIFT                      0
#define AXBS_CRS_PARK(x)                         (((x)<<AXBS_CRS_PARK_SHIFT)&AXBS_CRS_PARK_MASK)
#define AXBS_CRS_PCTL_MASK                       0x30u
#define AXBS_CRS_PCTL_SHIFT                      4
#define AXBS_CRS_PCTL(x)                         (((x)<<AXBS_CRS_PCTL_SHIFT)&AXBS_CRS_PCTL_MASK)
#define AXBS_CRS_ARB_MASK                        0x300u
#define AXBS_CRS_ARB_SHIFT                       8
#define AXBS_CRS_ARB(x)                          (((x)<<AXBS_CRS_ARB_SHIFT)&AXBS_CRS_ARB_MASK)
#define AXBS_CRS_HLP_MASK                        0x40000000u
#define AXBS_CRS_HLP_SHIFT                       30
#define AXBS_CRS_RO_MASK                         0x80000000u
#define AXBS_CRS_RO_SHIFT                        31
/* MGPCR0 Bit Fields */
#define AXBS_MGPCR0_AULB_MASK                    0x7u
#define AXBS_MGPCR0_AULB_SHIFT                   0
#define AXBS_MGPCR0_AULB(x)                      (((x)<<AXBS_MGPCR0_AULB_SHIFT)&AXBS_MGPCR0_AULB_MASK)
/* MGPCR1 Bit Fields */
#define AXBS_MGPCR1_AULB_MASK                    0x7u
#define AXBS_MGPCR1_AULB_SHIFT                   0
#define AXBS_MGPCR1_AULB(x)                      (((x)<<AXBS_MGPCR1_AULB_SHIFT)&AXBS_MGPCR1_AULB_MASK)
/* MGPCR2 Bit Fields */
#define AXBS_MGPCR2_AULB_MASK                    0x7u
#define AXBS_MGPCR2_AULB_SHIFT                   0
#define AXBS_MGPCR2_AULB(x)                      (((x)<<AXBS_MGPCR2_AULB_SHIFT)&AXBS_MGPCR2_AULB_MASK)
/* MGPCR4 Bit Fields */
#define AXBS_MGPCR4_AULB_MASK                    0x7u
#define AXBS_MGPCR4_AULB_SHIFT                   0
#define AXBS_MGPCR4_AULB(x)                      (((x)<<AXBS_MGPCR4_AULB_SHIFT)&AXBS_MGPCR4_AULB_MASK)
/* MGPCR5 Bit Fields */
#define AXBS_MGPCR5_AULB_MASK                    0x7u
#define AXBS_MGPCR5_AULB_SHIFT                   0
#define AXBS_MGPCR5_AULB(x)                      (((x)<<AXBS_MGPCR5_AULB_SHIFT)&AXBS_MGPCR5_AULB_MASK)

/*! \} */ /* end of group AXBS_Register_Masks */


/* AXBS - Peripheral instance base addresses */
/*! Peripheral AXBS base pointer */
#define AXBS_BASE_PTR                            ((AXBS_MemMapPtr)0x40004000u)

/* ----------------------------------------------------------------------------
   -- AXBS - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup AXBS_Register_Accessor_Macros AXBS - Register accessor macros */
/*! \{ */


/* AXBS - Register instance definitions */
/* AXBS */
#define AXBS_PRS0                                AXBS_PRS_REG(AXBS_BASE_PTR,0)
#define AXBS_CRS0                                AXBS_CRS_REG(AXBS_BASE_PTR,0)
#define AXBS_PRS1                                AXBS_PRS_REG(AXBS_BASE_PTR,1)
#define AXBS_CRS1                                AXBS_CRS_REG(AXBS_BASE_PTR,1)
#define AXBS_PRS2                                AXBS_PRS_REG(AXBS_BASE_PTR,2)
#define AXBS_CRS2                                AXBS_CRS_REG(AXBS_BASE_PTR,2)
#define AXBS_PRS3                                AXBS_PRS_REG(AXBS_BASE_PTR,3)
#define AXBS_CRS3                                AXBS_CRS_REG(AXBS_BASE_PTR,3)
#define AXBS_PRS4                                AXBS_PRS_REG(AXBS_BASE_PTR,4)
#define AXBS_CRS4                                AXBS_CRS_REG(AXBS_BASE_PTR,4)
#define AXBS_MGPCR0                              AXBS_MGPCR0_REG(AXBS_BASE_PTR)
#define AXBS_MGPCR1                              AXBS_MGPCR1_REG(AXBS_BASE_PTR)
#define AXBS_MGPCR2                              AXBS_MGPCR2_REG(AXBS_BASE_PTR)
#define AXBS_MGPCR4                              AXBS_MGPCR4_REG(AXBS_BASE_PTR)
#define AXBS_MGPCR5                              AXBS_MGPCR5_REG(AXBS_BASE_PTR)

/*! \} */ /* end of group AXBS_Register_Accessor_Macros */


/*! \} */ /* end of group AXBS_Peripheral */


/* ----------------------------------------------------------------------------
   -- CAN
   ---------------------------------------------------------------------------- */

/*! \addtogroup CAN_Peripheral CAN */
/*! \{ */

/*! CAN - Peripheral register structure */
typedef struct CAN_MemMap {
  uint32_t MCR;                                    /*!< Module Configuration Register, offset: 0x0 */
  uint32_t CTRL1;                                  /*!< Control 1 Register, offset: 0x4 */
  uint32_t TIMER;                                  /*!< Free Running Timer, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t RXMGMASK;                               /*!< Rx Mailboxes Global Mask Register, offset: 0x10 */
  uint32_t RX14MASK;                               /*!< Rx 14 Mask Register, offset: 0x14 */
  uint32_t RX15MASK;                               /*!< Rx 15 Mask Register, offset: 0x18 */
  uint32_t ECR;                                    /*!< Error Counter, offset: 0x1C */
  uint32_t ESR1;                                   /*!< Error and Status 1 Register, offset: 0x20 */
  uint32_t IMASK2;                                 /*!< Interrupt Masks 2 Register, offset: 0x24 */
  uint32_t IMASK1;                                 /*!< Interrupt Masks 1 Register, offset: 0x28 */
  uint32_t IFLAG2;                                 /*!< Interrupt Flags 2 Register, offset: 0x2C */
  uint32_t IFLAG1;                                 /*!< Interrupt Flags 1 Register, offset: 0x30 */
  uint32_t CTRL2;                                  /*!< Control 2 Register, offset: 0x34 */
  uint32_t ESR2;                                   /*!< Error and Status 2 Register, offset: 0x38 */
  uint32_t IMEUR;                                  /*!< Individual Matching Elements Update Register, offset: 0x3C */
  uint32_t LRFR;                                   /*!< Lost Rx Frames Register, offset: 0x40 */
  uint32_t CRCR;                                   /*!< CRC Register, offset: 0x44 */
  uint32_t RXFGMASK;                               /*!< Rx FIFO Global Mask Register, offset: 0x48 */
  uint32_t RXFIR;                                  /*!< Rx FIFO Information Register, offset: 0x4C */
  uint8_t RESERVED_1[2096];
  uint32_t RXIMR[16];                              /*!< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
} volatile *CAN_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CAN - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CAN_Register_Accessor_Macros CAN - Register accessor macros */
/*! \{ */


/* CAN - Register accessors */
#define CAN_MCR_REG(base)                        ((base)->MCR)
#define CAN_CTRL1_REG(base)                      ((base)->CTRL1)
#define CAN_TIMER_REG(base)                      ((base)->TIMER)
#define CAN_RXMGMASK_REG(base)                   ((base)->RXMGMASK)
#define CAN_RX14MASK_REG(base)                   ((base)->RX14MASK)
#define CAN_RX15MASK_REG(base)                   ((base)->RX15MASK)
#define CAN_ECR_REG(base)                        ((base)->ECR)
#define CAN_ESR1_REG(base)                       ((base)->ESR1)
#define CAN_IMASK2_REG(base)                     ((base)->IMASK2)
#define CAN_IMASK1_REG(base)                     ((base)->IMASK1)
#define CAN_IFLAG2_REG(base)                     ((base)->IFLAG2)
#define CAN_IFLAG1_REG(base)                     ((base)->IFLAG1)
#define CAN_CTRL2_REG(base)                      ((base)->CTRL2)
#define CAN_ESR2_REG(base)                       ((base)->ESR2)
#define CAN_IMEUR_REG(base)                      ((base)->IMEUR)
#define CAN_LRFR_REG(base)                       ((base)->LRFR)
#define CAN_CRCR_REG(base)                       ((base)->CRCR)
#define CAN_RXFGMASK_REG(base)                   ((base)->RXFGMASK)
#define CAN_RXFIR_REG(base)                      ((base)->RXFIR)
#define CAN_RXIMR_REG(base,index)                ((base)->RXIMR[index])

/*! \} */ /* end of group CAN_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CAN Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup CAN_Register_Masks CAN Register Masks */
/*! \{ */

/* MCR Bit Fields */
#define CAN_MCR_MAXMB_MASK                       0x7Fu
#define CAN_MCR_MAXMB_SHIFT                      0
#define CAN_MCR_MAXMB(x)                         (((x)<<CAN_MCR_MAXMB_SHIFT)&CAN_MCR_MAXMB_MASK)
#define CAN_MCR_IDAM_MASK                        0x300u
#define CAN_MCR_IDAM_SHIFT                       8
#define CAN_MCR_IDAM(x)                          (((x)<<CAN_MCR_IDAM_SHIFT)&CAN_MCR_IDAM_MASK)
#define CAN_MCR_AEN_MASK                         0x1000u
#define CAN_MCR_AEN_SHIFT                        12
#define CAN_MCR_LPRIOEN_MASK                     0x2000u
#define CAN_MCR_LPRIOEN_SHIFT                    13
#define CAN_MCR_IRMQ_MASK                        0x10000u
#define CAN_MCR_IRMQ_SHIFT                       16
#define CAN_MCR_SRXDIS_MASK                      0x20000u
#define CAN_MCR_SRXDIS_SHIFT                     17
#define CAN_MCR_DOZE_MASK                        0x40000u
#define CAN_MCR_DOZE_SHIFT                       18
#define CAN_MCR_WAKSRC_MASK                      0x80000u
#define CAN_MCR_WAKSRC_SHIFT                     19
#define CAN_MCR_LPMACK_MASK                      0x100000u
#define CAN_MCR_LPMACK_SHIFT                     20
#define CAN_MCR_WRNEN_MASK                       0x200000u
#define CAN_MCR_WRNEN_SHIFT                      21
#define CAN_MCR_SLFWAK_MASK                      0x400000u
#define CAN_MCR_SLFWAK_SHIFT                     22
#define CAN_MCR_SUPV_MASK                        0x800000u
#define CAN_MCR_SUPV_SHIFT                       23
#define CAN_MCR_FRZACK_MASK                      0x1000000u
#define CAN_MCR_FRZACK_SHIFT                     24
#define CAN_MCR_SOFTRST_MASK                     0x2000000u
#define CAN_MCR_SOFTRST_SHIFT                    25
#define CAN_MCR_WAKMSK_MASK                      0x4000000u
#define CAN_MCR_WAKMSK_SHIFT                     26
#define CAN_MCR_NOTRDY_MASK                      0x8000000u
#define CAN_MCR_NOTRDY_SHIFT                     27
#define CAN_MCR_HALT_MASK                        0x10000000u
#define CAN_MCR_HALT_SHIFT                       28
#define CAN_MCR_RFEN_MASK                        0x20000000u
#define CAN_MCR_RFEN_SHIFT                       29
#define CAN_MCR_FRZ_MASK                         0x40000000u
#define CAN_MCR_FRZ_SHIFT                        30
#define CAN_MCR_MDIS_MASK                        0x80000000u
#define CAN_MCR_MDIS_SHIFT                       31
/* CTRL1 Bit Fields */
#define CAN_CTRL1_PROPSEG_MASK                   0x7u
#define CAN_CTRL1_PROPSEG_SHIFT                  0
#define CAN_CTRL1_PROPSEG(x)                     (((x)<<CAN_CTRL1_PROPSEG_SHIFT)&CAN_CTRL1_PROPSEG_MASK)
#define CAN_CTRL1_LOM_MASK                       0x8u
#define CAN_CTRL1_LOM_SHIFT                      3
#define CAN_CTRL1_LBUF_MASK                      0x10u
#define CAN_CTRL1_LBUF_SHIFT                     4
#define CAN_CTRL1_TSYN_MASK                      0x20u
#define CAN_CTRL1_TSYN_SHIFT                     5
#define CAN_CTRL1_BOFFREC_MASK                   0x40u
#define CAN_CTRL1_BOFFREC_SHIFT                  6
#define CAN_CTRL1_SMP_MASK                       0x80u
#define CAN_CTRL1_SMP_SHIFT                      7
#define CAN_CTRL1_RWRNMSK_MASK                   0x400u
#define CAN_CTRL1_RWRNMSK_SHIFT                  10
#define CAN_CTRL1_TWRNMSK_MASK                   0x800u
#define CAN_CTRL1_TWRNMSK_SHIFT                  11
#define CAN_CTRL1_LPB_MASK                       0x1000u
#define CAN_CTRL1_LPB_SHIFT                      12
#define CAN_CTRL1_CLKSRC_MASK                    0x2000u
#define CAN_CTRL1_CLKSRC_SHIFT                   13
#define CAN_CTRL1_ERRMSK_MASK                    0x4000u
#define CAN_CTRL1_ERRMSK_SHIFT                   14
#define CAN_CTRL1_BOFFMSK_MASK                   0x8000u
#define CAN_CTRL1_BOFFMSK_SHIFT                  15
#define CAN_CTRL1_PSEG2_MASK                     0x70000u
#define CAN_CTRL1_PSEG2_SHIFT                    16
#define CAN_CTRL1_PSEG2(x)                       (((x)<<CAN_CTRL1_PSEG2_SHIFT)&CAN_CTRL1_PSEG2_MASK)
#define CAN_CTRL1_PSEG1_MASK                     0x380000u
#define CAN_CTRL1_PSEG1_SHIFT                    19
#define CAN_CTRL1_PSEG1(x)                       (((x)<<CAN_CTRL1_PSEG1_SHIFT)&CAN_CTRL1_PSEG1_MASK)
#define CAN_CTRL1_RJW_MASK                       0xC00000u
#define CAN_CTRL1_RJW_SHIFT                      22
#define CAN_CTRL1_RJW(x)                         (((x)<<CAN_CTRL1_RJW_SHIFT)&CAN_CTRL1_RJW_MASK)
#define CAN_CTRL1_PRESDIV_MASK                   0xFF000000u
#define CAN_CTRL1_PRESDIV_SHIFT                  24
#define CAN_CTRL1_PRESDIV(x)                     (((x)<<CAN_CTRL1_PRESDIV_SHIFT)&CAN_CTRL1_PRESDIV_MASK)
/* TIMER Bit Fields */
#define CAN_TIMER_TIMER_MASK                     0xFFFFu
#define CAN_TIMER_TIMER_SHIFT                    0
#define CAN_TIMER_TIMER(x)                       (((x)<<CAN_TIMER_TIMER_SHIFT)&CAN_TIMER_TIMER_MASK)
/* RXMGMASK Bit Fields */
#define CAN_RXMGMASK_MG_MASK                     0xFFFFFFFFu
#define CAN_RXMGMASK_MG_SHIFT                    0
#define CAN_RXMGMASK_MG(x)                       (((x)<<CAN_RXMGMASK_MG_SHIFT)&CAN_RXMGMASK_MG_MASK)
/* RX14MASK Bit Fields */
#define CAN_RX14MASK_RX14M_MASK                  0xFFFFFFFFu
#define CAN_RX14MASK_RX14M_SHIFT                 0
#define CAN_RX14MASK_RX14M(x)                    (((x)<<CAN_RX14MASK_RX14M_SHIFT)&CAN_RX14MASK_RX14M_MASK)
/* RX15MASK Bit Fields */
#define CAN_RX15MASK_RX15M_MASK                  0xFFFFFFFFu
#define CAN_RX15MASK_RX15M_SHIFT                 0
#define CAN_RX15MASK_RX15M(x)                    (((x)<<CAN_RX15MASK_RX15M_SHIFT)&CAN_RX15MASK_RX15M_MASK)
/* ECR Bit Fields */
#define CAN_ECR_TXERRCNT_MASK                    0xFFu
#define CAN_ECR_TXERRCNT_SHIFT                   0
#define CAN_ECR_TXERRCNT(x)                      (((x)<<CAN_ECR_TXERRCNT_SHIFT)&CAN_ECR_TXERRCNT_MASK)
#define CAN_ECR_RXERRCNT_MASK                    0xFF00u
#define CAN_ECR_RXERRCNT_SHIFT                   8
#define CAN_ECR_RXERRCNT(x)                      (((x)<<CAN_ECR_RXERRCNT_SHIFT)&CAN_ECR_RXERRCNT_MASK)
/* ESR1 Bit Fields */
#define CAN_ESR1_WAKINT_MASK                     0x1u
#define CAN_ESR1_WAKINT_SHIFT                    0
#define CAN_ESR1_ERRINT_MASK                     0x2u
#define CAN_ESR1_ERRINT_SHIFT                    1
#define CAN_ESR1_BOFFINT_MASK                    0x4u
#define CAN_ESR1_BOFFINT_SHIFT                   2
#define CAN_ESR1_RX_MASK                         0x8u
#define CAN_ESR1_RX_SHIFT                        3
#define CAN_ESR1_FLTCONF_MASK                    0x30u
#define CAN_ESR1_FLTCONF_SHIFT                   4
#define CAN_ESR1_FLTCONF(x)                      (((x)<<CAN_ESR1_FLTCONF_SHIFT)&CAN_ESR1_FLTCONF_MASK)
#define CAN_ESR1_TX_MASK                         0x40u
#define CAN_ESR1_TX_SHIFT                        6
#define CAN_ESR1_IDLE_MASK                       0x80u
#define CAN_ESR1_IDLE_SHIFT                      7
#define CAN_ESR1_RXWRN_MASK                      0x100u
#define CAN_ESR1_RXWRN_SHIFT                     8
#define CAN_ESR1_TXWRN_MASK                      0x200u
#define CAN_ESR1_TXWRN_SHIFT                     9
#define CAN_ESR1_STFERR_MASK                     0x400u
#define CAN_ESR1_STFERR_SHIFT                    10
#define CAN_ESR1_FRMERR_MASK                     0x800u
#define CAN_ESR1_FRMERR_SHIFT                    11
#define CAN_ESR1_CRCERR_MASK                     0x1000u
#define CAN_ESR1_CRCERR_SHIFT                    12
#define CAN_ESR1_ACKERR_MASK                     0x2000u
#define CAN_ESR1_ACKERR_SHIFT                    13
#define CAN_ESR1_BIT0ERR_MASK                    0x4000u
#define CAN_ESR1_BIT0ERR_SHIFT                   14
#define CAN_ESR1_BIT1ERR_MASK                    0x8000u
#define CAN_ESR1_BIT1ERR_SHIFT                   15
#define CAN_ESR1_RWRNINT_MASK                    0x10000u
#define CAN_ESR1_RWRNINT_SHIFT                   16
#define CAN_ESR1_TWRNINT_MASK                    0x20000u
#define CAN_ESR1_TWRNINT_SHIFT                   17
#define CAN_ESR1_SYNCH_MASK                      0x40000u
#define CAN_ESR1_SYNCH_SHIFT                     18
/* IMASK2 Bit Fields */
#define CAN_IMASK2_BUFHM_MASK                    0xFFFFFFFFu
#define CAN_IMASK2_BUFHM_SHIFT                   0
#define CAN_IMASK2_BUFHM(x)                      (((x)<<CAN_IMASK2_BUFHM_SHIFT)&CAN_IMASK2_BUFHM_MASK)
/* IMASK1 Bit Fields */
#define CAN_IMASK1_BUFLM_MASK                    0xFFFFFFFFu
#define CAN_IMASK1_BUFLM_SHIFT                   0
#define CAN_IMASK1_BUFLM(x)                      (((x)<<CAN_IMASK1_BUFLM_SHIFT)&CAN_IMASK1_BUFLM_MASK)
/* IFLAG2 Bit Fields */
#define CAN_IFLAG2_BUFHI_MASK                    0xFFFFFFFFu
#define CAN_IFLAG2_BUFHI_SHIFT                   0
#define CAN_IFLAG2_BUFHI(x)                      (((x)<<CAN_IFLAG2_BUFHI_SHIFT)&CAN_IFLAG2_BUFHI_MASK)
/* IFLAG1 Bit Fields */
#define CAN_IFLAG1_BUF4TO0I_MASK                 0x1Fu
#define CAN_IFLAG1_BUF4TO0I_SHIFT                0
#define CAN_IFLAG1_BUF4TO0I(x)                   (((x)<<CAN_IFLAG1_BUF4TO0I_SHIFT)&CAN_IFLAG1_BUF4TO0I_MASK)
#define CAN_IFLAG1_BUF5I_MASK                    0x20u
#define CAN_IFLAG1_BUF5I_SHIFT                   5
#define CAN_IFLAG1_BUF6I_MASK                    0x40u
#define CAN_IFLAG1_BUF6I_SHIFT                   6
#define CAN_IFLAG1_BUF7I_MASK                    0x80u
#define CAN_IFLAG1_BUF7I_SHIFT                   7
#define CAN_IFLAG1_BUF31TO8I_MASK                0xFFFFFF00u
#define CAN_IFLAG1_BUF31TO8I_SHIFT               8
#define CAN_IFLAG1_BUF31TO8I(x)                  (((x)<<CAN_IFLAG1_BUF31TO8I_SHIFT)&CAN_IFLAG1_BUF31TO8I_MASK)
/* CTRL2 Bit Fields */
#define CAN_CTRL2_IMEUMASK_MASK                  0x1u
#define CAN_CTRL2_IMEUMASK_SHIFT                 0
#define CAN_CTRL2_LOSTRMMSK_MASK                 0x2u
#define CAN_CTRL2_LOSTRMMSK_SHIFT                1
#define CAN_CTRL2_LOSTRLMSK_MASK                 0x4u
#define CAN_CTRL2_LOSTRLMSK_SHIFT                2
#define CAN_CTRL2_EACEN_MASK                     0x10000u
#define CAN_CTRL2_EACEN_SHIFT                    16
#define CAN_CTRL2_RRS_MASK                       0x20000u
#define CAN_CTRL2_RRS_SHIFT                      17
#define CAN_CTRL2_MRP_MASK                       0x40000u
#define CAN_CTRL2_MRP_SHIFT                      18
#define CAN_CTRL2_TASD_MASK                      0xF80000u
#define CAN_CTRL2_TASD_SHIFT                     19
#define CAN_CTRL2_TASD(x)                        (((x)<<CAN_CTRL2_TASD_SHIFT)&CAN_CTRL2_TASD_MASK)
#define CAN_CTRL2_RFFN_MASK                      0xF000000u
#define CAN_CTRL2_RFFN_SHIFT                     24
#define CAN_CTRL2_RFFN(x)                        (((x)<<CAN_CTRL2_RFFN_SHIFT)&CAN_CTRL2_RFFN_MASK)
#define CAN_CTRL2_WRMFRZ_MASK                    0x10000000u
#define CAN_CTRL2_WRMFRZ_SHIFT                   28
#define CAN_CTRL2_IMEUEN_MASK                    0x80000000u
#define CAN_CTRL2_IMEUEN_SHIFT                   31
/* ESR2 Bit Fields */
#define CAN_ESR2_IMEUF_MASK                      0x1u
#define CAN_ESR2_IMEUF_SHIFT                     0
#define CAN_ESR2_LOSTRMF_MASK                    0x2u
#define CAN_ESR2_LOSTRMF_SHIFT                   1
#define CAN_ESR2_LOSTRLF_MASK                    0x4u
#define CAN_ESR2_LOSTRLF_SHIFT                   2
#define CAN_ESR2_IMB_MASK                        0x2000u
#define CAN_ESR2_IMB_SHIFT                       13
#define CAN_ESR2_VPS_MASK                        0x4000u
#define CAN_ESR2_VPS_SHIFT                       14
#define CAN_ESR2_LPTM_MASK                       0x7F0000u
#define CAN_ESR2_LPTM_SHIFT                      16
#define CAN_ESR2_LPTM(x)                         (((x)<<CAN_ESR2_LPTM_SHIFT)&CAN_ESR2_LPTM_MASK)
/* IMEUR Bit Fields */
#define CAN_IMEUR_IMEUP_MASK                     0x7Fu
#define CAN_IMEUR_IMEUP_SHIFT                    0
#define CAN_IMEUR_IMEUP(x)                       (((x)<<CAN_IMEUR_IMEUP_SHIFT)&CAN_IMEUR_IMEUP_MASK)
#define CAN_IMEUR_IMEUREQ_MASK                   0x100u
#define CAN_IMEUR_IMEUREQ_SHIFT                  8
#define CAN_IMEUR_IMEUACK_MASK                   0x200u
#define CAN_IMEUR_IMEUACK_SHIFT                  9
/* LRFR Bit Fields */
#define CAN_LRFR_LOSTRMP_MASK                    0x1FFu
#define CAN_LRFR_LOSTRMP_SHIFT                   0
#define CAN_LRFR_LOSTRMP(x)                      (((x)<<CAN_LRFR_LOSTRMP_SHIFT)&CAN_LRFR_LOSTRMP_MASK)
#define CAN_LRFR_LFIFOMTC_MASK                   0x8000u
#define CAN_LRFR_LFIFOMTC_SHIFT                  15
#define CAN_LRFR_LOSTRLP_MASK                    0x7F0000u
#define CAN_LRFR_LOSTRLP_SHIFT                   16
#define CAN_LRFR_LOSTRLP(x)                      (((x)<<CAN_LRFR_LOSTRLP_SHIFT)&CAN_LRFR_LOSTRLP_MASK)
/* CRCR Bit Fields */
#define CAN_CRCR_TXCRC_MASK                      0x7FFFu
#define CAN_CRCR_TXCRC_SHIFT                     0
#define CAN_CRCR_TXCRC(x)                        (((x)<<CAN_CRCR_TXCRC_SHIFT)&CAN_CRCR_TXCRC_MASK)
#define CAN_CRCR_MBCRC_MASK                      0x7F0000u
#define CAN_CRCR_MBCRC_SHIFT                     16
#define CAN_CRCR_MBCRC(x)                        (((x)<<CAN_CRCR_MBCRC_SHIFT)&CAN_CRCR_MBCRC_MASK)
/* RXFGMASK Bit Fields */
#define CAN_RXFGMASK_FGM_MASK                    0xFFFFFFFFu
#define CAN_RXFGMASK_FGM_SHIFT                   0
#define CAN_RXFGMASK_FGM(x)                      (((x)<<CAN_RXFGMASK_FGM_SHIFT)&CAN_RXFGMASK_FGM_MASK)
/* RXFIR Bit Fields */
#define CAN_RXFIR_IDHIT_MASK                     0x1FFu
#define CAN_RXFIR_IDHIT_SHIFT                    0
#define CAN_RXFIR_IDHIT(x)                       (((x)<<CAN_RXFIR_IDHIT_SHIFT)&CAN_RXFIR_IDHIT_MASK)
/* RXIMR Bit Fields */
#define CAN_RXIMR_MI_MASK                        0xFFFFFFFFu
#define CAN_RXIMR_MI_SHIFT                       0
#define CAN_RXIMR_MI(x)                          (((x)<<CAN_RXIMR_MI_SHIFT)&CAN_RXIMR_MI_MASK)

/*! \} */ /* end of group CAN_Register_Masks */


/* CAN - Peripheral instance base addresses */
/*! Peripheral CAN0 base pointer */
#define CAN0_BASE_PTR                            ((CAN_MemMapPtr)0x40024000u)
/*! Peripheral CAN1 base pointer */
#define CAN1_BASE_PTR                            ((CAN_MemMapPtr)0x400A4000u)

/* ----------------------------------------------------------------------------
   -- CAN - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CAN_Register_Accessor_Macros CAN - Register accessor macros */
/*! \{ */


/* CAN - Register instance definitions */
/* CAN0 */
#define CAN0_MCR                                 CAN_MCR_REG(CAN0_BASE_PTR)
#define CAN0_CTRL1                               CAN_CTRL1_REG(CAN0_BASE_PTR)
#define CAN0_TIMER                               CAN_TIMER_REG(CAN0_BASE_PTR)
#define CAN0_RXMGMASK                            CAN_RXMGMASK_REG(CAN0_BASE_PTR)
#define CAN0_RX14MASK                            CAN_RX14MASK_REG(CAN0_BASE_PTR)
#define CAN0_RX15MASK                            CAN_RX15MASK_REG(CAN0_BASE_PTR)
#define CAN0_ECR                                 CAN_ECR_REG(CAN0_BASE_PTR)
#define CAN0_ESR1                                CAN_ESR1_REG(CAN0_BASE_PTR)
#define CAN0_IMASK2                              CAN_IMASK2_REG(CAN0_BASE_PTR)
#define CAN0_IMASK1                              CAN_IMASK1_REG(CAN0_BASE_PTR)
#define CAN0_IFLAG2                              CAN_IFLAG2_REG(CAN0_BASE_PTR)
#define CAN0_IFLAG1                              CAN_IFLAG1_REG(CAN0_BASE_PTR)
#define CAN0_CTRL2                               CAN_CTRL2_REG(CAN0_BASE_PTR)
#define CAN0_ESR2                                CAN_ESR2_REG(CAN0_BASE_PTR)
#define CAN0_IMEUR                               CAN_IMEUR_REG(CAN0_BASE_PTR)
#define CAN0_LRFR                                CAN_LRFR_REG(CAN0_BASE_PTR)
#define CAN0_CRCR                                CAN_CRCR_REG(CAN0_BASE_PTR)
#define CAN0_RXFGMASK                            CAN_RXFGMASK_REG(CAN0_BASE_PTR)
#define CAN0_RXFIR                               CAN_RXFIR_REG(CAN0_BASE_PTR)
#define CAN0_RXIMR0                              CAN_RXIMR_REG(CAN0_BASE_PTR,0)
#define CAN0_RXIMR1                              CAN_RXIMR_REG(CAN0_BASE_PTR,1)
#define CAN0_RXIMR2                              CAN_RXIMR_REG(CAN0_BASE_PTR,2)
#define CAN0_RXIMR3                              CAN_RXIMR_REG(CAN0_BASE_PTR,3)
#define CAN0_RXIMR4                              CAN_RXIMR_REG(CAN0_BASE_PTR,4)
#define CAN0_RXIMR5                              CAN_RXIMR_REG(CAN0_BASE_PTR,5)
#define CAN0_RXIMR6                              CAN_RXIMR_REG(CAN0_BASE_PTR,6)
#define CAN0_RXIMR7                              CAN_RXIMR_REG(CAN0_BASE_PTR,7)
#define CAN0_RXIMR8                              CAN_RXIMR_REG(CAN0_BASE_PTR,8)
#define CAN0_RXIMR9                              CAN_RXIMR_REG(CAN0_BASE_PTR,9)
#define CAN0_RXIMR10                             CAN_RXIMR_REG(CAN0_BASE_PTR,10)
#define CAN0_RXIMR11                             CAN_RXIMR_REG(CAN0_BASE_PTR,11)
#define CAN0_RXIMR12                             CAN_RXIMR_REG(CAN0_BASE_PTR,12)
#define CAN0_RXIMR13                             CAN_RXIMR_REG(CAN0_BASE_PTR,13)
#define CAN0_RXIMR14                             CAN_RXIMR_REG(CAN0_BASE_PTR,14)
#define CAN0_RXIMR15                             CAN_RXIMR_REG(CAN0_BASE_PTR,15)
/* CAN1 */
#define CAN1_MCR                                 CAN_MCR_REG(CAN1_BASE_PTR)
#define CAN1_CTRL1                               CAN_CTRL1_REG(CAN1_BASE_PTR)
#define CAN1_TIMER                               CAN_TIMER_REG(CAN1_BASE_PTR)
#define CAN1_RXMGMASK                            CAN_RXMGMASK_REG(CAN1_BASE_PTR)
#define CAN1_RX14MASK                            CAN_RX14MASK_REG(CAN1_BASE_PTR)
#define CAN1_RX15MASK                            CAN_RX15MASK_REG(CAN1_BASE_PTR)
#define CAN1_ECR                                 CAN_ECR_REG(CAN1_BASE_PTR)
#define CAN1_ESR1                                CAN_ESR1_REG(CAN1_BASE_PTR)
#define CAN1_IMASK2                              CAN_IMASK2_REG(CAN1_BASE_PTR)
#define CAN1_IMASK1                              CAN_IMASK1_REG(CAN1_BASE_PTR)
#define CAN1_IFLAG2                              CAN_IFLAG2_REG(CAN1_BASE_PTR)
#define CAN1_IFLAG1                              CAN_IFLAG1_REG(CAN1_BASE_PTR)
#define CAN1_CTRL2                               CAN_CTRL2_REG(CAN1_BASE_PTR)
#define CAN1_ESR2                                CAN_ESR2_REG(CAN1_BASE_PTR)
#define CAN1_IMEUR                               CAN_IMEUR_REG(CAN1_BASE_PTR)
#define CAN1_LRFR                                CAN_LRFR_REG(CAN1_BASE_PTR)
#define CAN1_CRCR                                CAN_CRCR_REG(CAN1_BASE_PTR)
#define CAN1_RXFGMASK                            CAN_RXFGMASK_REG(CAN1_BASE_PTR)
#define CAN1_RXFIR                               CAN_RXFIR_REG(CAN1_BASE_PTR)
#define CAN1_RXIMR0                              CAN_RXIMR_REG(CAN1_BASE_PTR,0)
#define CAN1_RXIMR1                              CAN_RXIMR_REG(CAN1_BASE_PTR,1)
#define CAN1_RXIMR2                              CAN_RXIMR_REG(CAN1_BASE_PTR,2)
#define CAN1_RXIMR3                              CAN_RXIMR_REG(CAN1_BASE_PTR,3)
#define CAN1_RXIMR4                              CAN_RXIMR_REG(CAN1_BASE_PTR,4)
#define CAN1_RXIMR5                              CAN_RXIMR_REG(CAN1_BASE_PTR,5)
#define CAN1_RXIMR6                              CAN_RXIMR_REG(CAN1_BASE_PTR,6)
#define CAN1_RXIMR7                              CAN_RXIMR_REG(CAN1_BASE_PTR,7)
#define CAN1_RXIMR8                              CAN_RXIMR_REG(CAN1_BASE_PTR,8)
#define CAN1_RXIMR9                              CAN_RXIMR_REG(CAN1_BASE_PTR,9)
#define CAN1_RXIMR10                             CAN_RXIMR_REG(CAN1_BASE_PTR,10)
#define CAN1_RXIMR11                             CAN_RXIMR_REG(CAN1_BASE_PTR,11)
#define CAN1_RXIMR12                             CAN_RXIMR_REG(CAN1_BASE_PTR,12)
#define CAN1_RXIMR13                             CAN_RXIMR_REG(CAN1_BASE_PTR,13)
#define CAN1_RXIMR14                             CAN_RXIMR_REG(CAN1_BASE_PTR,14)
#define CAN1_RXIMR15                             CAN_RXIMR_REG(CAN1_BASE_PTR,15)

/*! \} */ /* end of group CAN_Register_Accessor_Macros */


/*! \} */ /* end of group CAN_Peripheral */


/* ----------------------------------------------------------------------------
   -- CMT
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMT_Peripheral CMT */
/*! \{ */

/*! CMT - Peripheral register structure */
typedef struct CMT_MemMap {
  uint8_t CGH1;                                    /*!< CMT Carrier Generator High Data Register 1, offset: 0x0 */
  uint8_t CGL1;                                    /*!< CMT Carrier Generator Low Data Register 1, offset: 0x1 */
  uint8_t CGH2;                                    /*!< CMT Carrier Generator High Data Register 2, offset: 0x2 */
  uint8_t CGL2;                                    /*!< CMT Carrier Generator Low Data Register 2, offset: 0x3 */
  uint8_t OC;                                      /*!< CMT Output Control Register, offset: 0x4 */
  uint8_t MSC;                                     /*!< CMT Modulator Status and Control Register, offset: 0x5 */
  uint8_t CMD1;                                    /*!< CMT Modulator Data Register Mark High, offset: 0x6 */
  uint8_t CMD2;                                    /*!< CMT Modulator Data Register Mark Low, offset: 0x7 */
  uint8_t CMD3;                                    /*!< CMT Modulator Data Register Space High, offset: 0x8 */
  uint8_t CMD4;                                    /*!< CMT Modulator Data Register Space Low, offset: 0x9 */
  uint8_t PPS;                                     /*!< CMT Primary Prescaler Register, offset: 0xA */
  uint8_t DMA;                                     /*!< CMT Direct Memory Access, offset: 0xB */
} volatile *CMT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CMT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMT_Register_Accessor_Macros CMT - Register accessor macros */
/*! \{ */


/* CMT - Register accessors */
#define CMT_CGH1_REG(base)                       ((base)->CGH1)
#define CMT_CGL1_REG(base)                       ((base)->CGL1)
#define CMT_CGH2_REG(base)                       ((base)->CGH2)
#define CMT_CGL2_REG(base)                       ((base)->CGL2)
#define CMT_OC_REG(base)                         ((base)->OC)
#define CMT_MSC_REG(base)                        ((base)->MSC)
#define CMT_CMD1_REG(base)                       ((base)->CMD1)
#define CMT_CMD2_REG(base)                       ((base)->CMD2)
#define CMT_CMD3_REG(base)                       ((base)->CMD3)
#define CMT_CMD4_REG(base)                       ((base)->CMD4)
#define CMT_PPS_REG(base)                        ((base)->PPS)
#define CMT_DMA_REG(base)                        ((base)->DMA)

/*! \} */ /* end of group CMT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CMT Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMT_Register_Masks CMT Register Masks */
/*! \{ */

/* CGH1 Bit Fields */
#define CMT_CGH1_PH_MASK                         0xFFu
#define CMT_CGH1_PH_SHIFT                        0
#define CMT_CGH1_PH(x)                           (((x)<<CMT_CGH1_PH_SHIFT)&CMT_CGH1_PH_MASK)
/* CGL1 Bit Fields */
#define CMT_CGL1_PL_MASK                         0xFFu
#define CMT_CGL1_PL_SHIFT                        0
#define CMT_CGL1_PL(x)                           (((x)<<CMT_CGL1_PL_SHIFT)&CMT_CGL1_PL_MASK)
/* CGH2 Bit Fields */
#define CMT_CGH2_SH_MASK                         0xFFu
#define CMT_CGH2_SH_SHIFT                        0
#define CMT_CGH2_SH(x)                           (((x)<<CMT_CGH2_SH_SHIFT)&CMT_CGH2_SH_MASK)
/* CGL2 Bit Fields */
#define CMT_CGL2_SL_MASK                         0xFFu
#define CMT_CGL2_SL_SHIFT                        0
#define CMT_CGL2_SL(x)                           (((x)<<CMT_CGL2_SL_SHIFT)&CMT_CGL2_SL_MASK)
/* OC Bit Fields */
#define CMT_OC_IROPEN_MASK                       0x20u
#define CMT_OC_IROPEN_SHIFT                      5
#define CMT_OC_CMTPOL_MASK                       0x40u
#define CMT_OC_CMTPOL_SHIFT                      6
#define CMT_OC_IROL_MASK                         0x80u
#define CMT_OC_IROL_SHIFT                        7
/* MSC Bit Fields */
#define CMT_MSC_MCGEN_MASK                       0x1u
#define CMT_MSC_MCGEN_SHIFT                      0
#define CMT_MSC_EOCIE_MASK                       0x2u
#define CMT_MSC_EOCIE_SHIFT                      1
#define CMT_MSC_FSK_MASK                         0x4u
#define CMT_MSC_FSK_SHIFT                        2
#define CMT_MSC_BASE_MASK                        0x8u
#define CMT_MSC_BASE_SHIFT                       3
#define CMT_MSC_EXSPC_MASK                       0x10u
#define CMT_MSC_EXSPC_SHIFT                      4
#define CMT_MSC_CMTDIV_MASK                      0x60u
#define CMT_MSC_CMTDIV_SHIFT                     5
#define CMT_MSC_CMTDIV(x)                        (((x)<<CMT_MSC_CMTDIV_SHIFT)&CMT_MSC_CMTDIV_MASK)
#define CMT_MSC_EOCF_MASK                        0x80u
#define CMT_MSC_EOCF_SHIFT                       7
/* CMD1 Bit Fields */
#define CMT_CMD1_MB_MASK                         0xFFu
#define CMT_CMD1_MB_SHIFT                        0
#define CMT_CMD1_MB(x)                           (((x)<<CMT_CMD1_MB_SHIFT)&CMT_CMD1_MB_MASK)
/* CMD2 Bit Fields */
#define CMT_CMD2_MB_MASK                         0xFFu
#define CMT_CMD2_MB_SHIFT                        0
#define CMT_CMD2_MB(x)                           (((x)<<CMT_CMD2_MB_SHIFT)&CMT_CMD2_MB_MASK)
/* CMD3 Bit Fields */
#define CMT_CMD3_SB_MASK                         0xFFu
#define CMT_CMD3_SB_SHIFT                        0
#define CMT_CMD3_SB(x)                           (((x)<<CMT_CMD3_SB_SHIFT)&CMT_CMD3_SB_MASK)
/* CMD4 Bit Fields */
#define CMT_CMD4_SB_MASK                         0xFFu
#define CMT_CMD4_SB_SHIFT                        0
#define CMT_CMD4_SB(x)                           (((x)<<CMT_CMD4_SB_SHIFT)&CMT_CMD4_SB_MASK)
/* PPS Bit Fields */
#define CMT_PPS_PPSDIV_MASK                      0xFu
#define CMT_PPS_PPSDIV_SHIFT                     0
#define CMT_PPS_PPSDIV(x)                        (((x)<<CMT_PPS_PPSDIV_SHIFT)&CMT_PPS_PPSDIV_MASK)
/* DMA Bit Fields */
#define CMT_DMA_DMA_MASK                         0x1u
#define CMT_DMA_DMA_SHIFT                        0

/*! \} */ /* end of group CMT_Register_Masks */


/* CMT - Peripheral instance base addresses */
/*! Peripheral CMT base pointer */
#define CMT_BASE_PTR                             ((CMT_MemMapPtr)0x40062000u)

/* ----------------------------------------------------------------------------
   -- CMT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMT_Register_Accessor_Macros CMT - Register accessor macros */
/*! \{ */


/* CMT - Register instance definitions */
/* CMT */
#define CMT_CGH1                                 CMT_CGH1_REG(CMT_BASE_PTR)
#define CMT_CGL1                                 CMT_CGL1_REG(CMT_BASE_PTR)
#define CMT_CGH2                                 CMT_CGH2_REG(CMT_BASE_PTR)
#define CMT_CGL2                                 CMT_CGL2_REG(CMT_BASE_PTR)
#define CMT_OC                                   CMT_OC_REG(CMT_BASE_PTR)
#define CMT_MSC                                  CMT_MSC_REG(CMT_BASE_PTR)
#define CMT_CMD1                                 CMT_CMD1_REG(CMT_BASE_PTR)
#define CMT_CMD2                                 CMT_CMD2_REG(CMT_BASE_PTR)
#define CMT_CMD3                                 CMT_CMD3_REG(CMT_BASE_PTR)
#define CMT_CMD4                                 CMT_CMD4_REG(CMT_BASE_PTR)
#define CMT_PPS                                  CMT_PPS_REG(CMT_BASE_PTR)
#define CMT_DMA                                  CMT_DMA_REG(CMT_BASE_PTR)

/*! \} */ /* end of group CMT_Register_Accessor_Macros */


/*! \} */ /* end of group CMT_Peripheral */


/* ----------------------------------------------------------------------------
   -- CRC
   ---------------------------------------------------------------------------- */

/*! \addtogroup CRC_Peripheral CRC */
/*! \{ */

/*! CRC - Peripheral register structure */
typedef struct CRC_MemMap {
  uint16_t LOW;                                    /*!< CRC Low Word Register, offset: 0x0 */
  uint16_t HIGH;                                   /*!< CRC High Word Register, offset: 0x2 */
  uint16_t GPOLYL;                                 /*!< Polynomial Low Word Register, offset: 0x4 */
  uint16_t GPOLYH;                                 /*!< Polynomial High Word Register, offset: 0x6 */
  uint8_t RESERVED_0[8];
  uint16_t CTRL;                                   /*!< Control Register, offset: 0x10 */
} volatile *CRC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros */
/*! \{ */


/* CRC - Register accessors */
#define CRC_LOW_REG(base)                        ((base)->LOW)
#define CRC_HIGH_REG(base)                       ((base)->HIGH)
#define CRC_GPOLYL_REG(base)                     ((base)->GPOLYL)
#define CRC_GPOLYH_REG(base)                     ((base)->GPOLYH)
#define CRC_CTRL_REG(base)                       ((base)->CTRL)

/*! \} */ /* end of group CRC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup CRC_Register_Masks CRC Register Masks */
/*! \{ */

/* LOW Bit Fields */
#define CRC_LOW_CRCLL_MASK                       0xFFu
#define CRC_LOW_CRCLL_SHIFT                      0
#define CRC_LOW_CRCLL(x)                         (((x)<<CRC_LOW_CRCLL_SHIFT)&CRC_LOW_CRCLL_MASK)
#define CRC_LOW_CRCLU_MASK                       0xFF00u
#define CRC_LOW_CRCLU_SHIFT                      8
#define CRC_LOW_CRCLU(x)                         (((x)<<CRC_LOW_CRCLU_SHIFT)&CRC_LOW_CRCLU_MASK)
/* HIGH Bit Fields */
#define CRC_HIGH_CRCHL_MASK                      0xFFu
#define CRC_HIGH_CRCHL_SHIFT                     0
#define CRC_HIGH_CRCHL(x)                        (((x)<<CRC_HIGH_CRCHL_SHIFT)&CRC_HIGH_CRCHL_MASK)
#define CRC_HIGH_CRCHU_MASK                      0xFF00u
#define CRC_HIGH_CRCHU_SHIFT                     8
#define CRC_HIGH_CRCHU(x)                        (((x)<<CRC_HIGH_CRCHU_SHIFT)&CRC_HIGH_CRCHU_MASK)
/* GPOLYL Bit Fields */
#define CRC_GPOLYL_POLYL_MASK                    0xFFFFu
#define CRC_GPOLYL_POLYL_SHIFT                   0
#define CRC_GPOLYL_POLYL(x)                      (((x)<<CRC_GPOLYL_POLYL_SHIFT)&CRC_GPOLYL_POLYL_MASK)
/* GPOLYH Bit Fields */
#define CRC_GPOLYH_POLYH_MASK                    0xFFFFu
#define CRC_GPOLYH_POLYH_SHIFT                   0
#define CRC_GPOLYH_POLYH(x)                      (((x)<<CRC_GPOLYH_POLYH_SHIFT)&CRC_GPOLYH_POLYH_MASK)
/* CTRL Bit Fields */
#define CRC_CTRL_TCRC_MASK                       0x100u
#define CRC_CTRL_TCRC_SHIFT                      8
#define CRC_CTRL_WAS_MASK                        0x200u
#define CRC_CTRL_WAS_SHIFT                       9
#define CRC_CTRL_FXOR_MASK                       0x400u
#define CRC_CTRL_FXOR_SHIFT                      10
#define CRC_CTRL_TOTR_MASK                       0x3000u
#define CRC_CTRL_TOTR_SHIFT                      12
#define CRC_CTRL_TOTR(x)                         (((x)<<CRC_CTRL_TOTR_SHIFT)&CRC_CTRL_TOTR_MASK)
#define CRC_CTRL_TOT_MASK                        0xC000u
#define CRC_CTRL_TOT_SHIFT                       14
#define CRC_CTRL_TOT(x)                          (((x)<<CRC_CTRL_TOT_SHIFT)&CRC_CTRL_TOT_MASK)

/*! \} */ /* end of group CRC_Register_Masks */


/* CRC - Peripheral instance base addresses */
/*! Peripheral CRC base pointer */
#define CRC_BASE_PTR                             ((CRC_MemMapPtr)0x40032000u)

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros */
/*! \{ */


/* CRC - Register instance definitions */
/* CRC */
#define CRC_LOW                                  CRC_LOW_REG(CRC_BASE_PTR)
#define CRC_HIGH                                 CRC_HIGH_REG(CRC_BASE_PTR)
#define CRC_GPOLYL                               CRC_GPOLYL_REG(CRC_BASE_PTR)
#define CRC_GPOLYH                               CRC_GPOLYH_REG(CRC_BASE_PTR)
#define CRC_CTRL                                 CRC_CTRL_REG(CRC_BASE_PTR)

/*! \} */ /* end of group CRC_Register_Accessor_Macros */


/*! \} */ /* end of group CRC_Peripheral */


/* ----------------------------------------------------------------------------
   -- DAC
   ---------------------------------------------------------------------------- */

/*! \addtogroup DAC_Peripheral DAC */
/*! \{ */

/*! DAC - Peripheral register structure */
typedef struct DAC_MemMap {
  struct {                                         /* offset: 0x0, array step: 0x2 */
    uint8_t DATL;                                    /*!< DAC Data Low Register, array offset: 0x0, array step: 0x2 */
    uint8_t DATH;                                    /*!< DAC Data High Register, array offset: 0x1, array step: 0x2 */
  } DAT[16];
  uint8_t SR;                                      /*!< DAC Status Register, offset: 0x20 */
  uint8_t C0;                                      /*!< DAC Control Register, offset: 0x21 */
  uint8_t C1;                                      /*!< DAC Control Register 1, offset: 0x22 */
  uint8_t C2;                                      /*!< DAC Control Register 2, offset: 0x23 */
} volatile *DAC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros */
/*! \{ */


/* DAC - Register accessors */
#define DAC_DATL_REG(base,index)                 ((base)->DAT[index].DATL)
#define DAC_DATH_REG(base,index)                 ((base)->DAT[index].DATH)
#define DAC_SR_REG(base)                         ((base)->SR)
#define DAC_C0_REG(base)                         ((base)->C0)
#define DAC_C1_REG(base)                         ((base)->C1)
#define DAC_C2_REG(base)                         ((base)->C2)

/*! \} */ /* end of group DAC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup DAC_Register_Masks DAC Register Masks */
/*! \{ */

/* DATL Bit Fields */
#define DAC_DATL_DATA_MASK                       0xFFu
#define DAC_DATL_DATA_SHIFT                      0
#define DAC_DATL_DATA(x)                         (((x)<<DAC_DATL_DATA_SHIFT)&DAC_DATL_DATA_MASK)
/* DATH Bit Fields */
#define DAC_DATH_DATA_MASK                       0xFu
#define DAC_DATH_DATA_SHIFT                      0
#define DAC_DATH_DATA(x)                         (((x)<<DAC_DATH_DATA_SHIFT)&DAC_DATH_DATA_MASK)
/* SR Bit Fields */
#define DAC_SR_DACBFRPBF_MASK                    0x1u
#define DAC_SR_DACBFRPBF_SHIFT                   0
#define DAC_SR_DACBFRPTF_MASK                    0x2u
#define DAC_SR_DACBFRPTF_SHIFT                   1
#define DAC_SR_DACBFWMF_MASK                     0x4u
#define DAC_SR_DACBFWMF_SHIFT                    2
/* C0 Bit Fields */
#define DAC_C0_DACBBIEN_MASK                     0x1u
#define DAC_C0_DACBBIEN_SHIFT                    0
#define DAC_C0_DACBTIEN_MASK                     0x2u
#define DAC_C0_DACBTIEN_SHIFT                    1
#define DAC_C0_DACBWIEN_MASK                     0x4u
#define DAC_C0_DACBWIEN_SHIFT                    2
#define DAC_C0_LPEN_MASK                         0x8u
#define DAC_C0_LPEN_SHIFT                        3
#define DAC_C0_DACSWTRG_MASK                     0x10u
#define DAC_C0_DACSWTRG_SHIFT                    4
#define DAC_C0_DACTRGSEL_MASK                    0x20u
#define DAC_C0_DACTRGSEL_SHIFT                   5
#define DAC_C0_DACRFS_MASK                       0x40u
#define DAC_C0_DACRFS_SHIFT                      6
#define DAC_C0_DACEN_MASK                        0x80u
#define DAC_C0_DACEN_SHIFT                       7
/* C1 Bit Fields */
#define DAC_C1_DACBFEN_MASK                      0x1u
#define DAC_C1_DACBFEN_SHIFT                     0
#define DAC_C1_DACBFMD_MASK                      0x6u
#define DAC_C1_DACBFMD_SHIFT                     1
#define DAC_C1_DACBFMD(x)                        (((x)<<DAC_C1_DACBFMD_SHIFT)&DAC_C1_DACBFMD_MASK)
#define DAC_C1_DACBFWM_MASK                      0x18u
#define DAC_C1_DACBFWM_SHIFT                     3
#define DAC_C1_DACBFWM(x)                        (((x)<<DAC_C1_DACBFWM_SHIFT)&DAC_C1_DACBFWM_MASK)
#define DAC_C1_DMAEN_MASK                        0x80u
#define DAC_C1_DMAEN_SHIFT                       7
/* C2 Bit Fields */
#define DAC_C2_DACBFUP_MASK                      0xFu
#define DAC_C2_DACBFUP_SHIFT                     0
#define DAC_C2_DACBFUP(x)                        (((x)<<DAC_C2_DACBFUP_SHIFT)&DAC_C2_DACBFUP_MASK)
#define DAC_C2_DACBFRP_MASK                      0xF0u
#define DAC_C2_DACBFRP_SHIFT                     4
#define DAC_C2_DACBFRP(x)                        (((x)<<DAC_C2_DACBFRP_SHIFT)&DAC_C2_DACBFRP_MASK)

/*! \} */ /* end of group DAC_Register_Masks */


/* DAC - Peripheral instance base addresses */
/*! Peripheral DAC0 base pointer */
#define DAC0_BASE_PTR                            ((DAC_MemMapPtr)0x400CC000u)
/*! Peripheral DAC1 base pointer */
#define DAC1_BASE_PTR                            ((DAC_MemMapPtr)0x400CD000u)

/* ----------------------------------------------------------------------------
   -- DAC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup DAC_Register_Accessor_Macros DAC - Register accessor macros */
/*! \{ */


/* DAC - Register instance definitions */
/* DAC0 */
#define DAC0_DAT0L                               DAC_DATL_REG(DAC0_BASE_PTR,0)
#define DAC0_DAT0H                               DAC_DATH_REG(DAC0_BASE_PTR,0)
#define DAC0_DAT1L                               DAC_DATL_REG(DAC0_BASE_PTR,1)
#define DAC0_DAT1H                               DAC_DATH_REG(DAC0_BASE_PTR,1)
#define DAC0_DAT2L                               DAC_DATL_REG(DAC0_BASE_PTR,2)
#define DAC0_DAT2H                               DAC_DATH_REG(DAC0_BASE_PTR,2)
#define DAC0_DAT3L                               DAC_DATL_REG(DAC0_BASE_PTR,3)
#define DAC0_DAT3H                               DAC_DATH_REG(DAC0_BASE_PTR,3)
#define DAC0_DAT4L                               DAC_DATL_REG(DAC0_BASE_PTR,4)
#define DAC0_DAT4H                               DAC_DATH_REG(DAC0_BASE_PTR,4)
#define DAC0_DAT5L                               DAC_DATL_REG(DAC0_BASE_PTR,5)
#define DAC0_DAT5H                               DAC_DATH_REG(DAC0_BASE_PTR,5)
#define DAC0_DAT6L                               DAC_DATL_REG(DAC0_BASE_PTR,6)
#define DAC0_DAT6H                               DAC_DATH_REG(DAC0_BASE_PTR,6)
#define DAC0_DAT7L                               DAC_DATL_REG(DAC0_BASE_PTR,7)
#define DAC0_DAT7H                               DAC_DATH_REG(DAC0_BASE_PTR,7)
#define DAC0_DAT8L                               DAC_DATL_REG(DAC0_BASE_PTR,8)
#define DAC0_DAT8H                               DAC_DATH_REG(DAC0_BASE_PTR,8)
#define DAC0_DAT9L                               DAC_DATL_REG(DAC0_BASE_PTR,9)
#define DAC0_DAT9H                               DAC_DATH_REG(DAC0_BASE_PTR,9)
#define DAC0_DAT10L                              DAC_DATL_REG(DAC0_BASE_PTR,10)
#define DAC0_DAT10H                              DAC_DATH_REG(DAC0_BASE_PTR,10)
#define DAC0_DAT11L                              DAC_DATL_REG(DAC0_BASE_PTR,11)
#define DAC0_DAT11H                              DAC_DATH_REG(DAC0_BASE_PTR,11)
#define DAC0_DAT12L                              DAC_DATL_REG(DAC0_BASE_PTR,12)
#define DAC0_DAT12H                              DAC_DATH_REG(DAC0_BASE_PTR,12)
#define DAC0_DAT13L                              DAC_DATL_REG(DAC0_BASE_PTR,13)
#define DAC0_DAT13H                              DAC_DATH_REG(DAC0_BASE_PTR,13)
#define DAC0_DAT14L                              DAC_DATL_REG(DAC0_BASE_PTR,14)
#define DAC0_DAT14H                              DAC_DATH_REG(DAC0_BASE_PTR,14)
#define DAC0_DAT15L                              DAC_DATL_REG(DAC0_BASE_PTR,15)
#define DAC0_DAT15H                              DAC_DATH_REG(DAC0_BASE_PTR,15)
#define DAC0_SR                                  DAC_SR_REG(DAC0_BASE_PTR)
#define DAC0_C0                                  DAC_C0_REG(DAC0_BASE_PTR)
#define DAC0_C1                                  DAC_C1_REG(DAC0_BASE_PTR)
#define DAC0_C2                                  DAC_C2_REG(DAC0_BASE_PTR)
/* DAC1 */
#define DAC1_DAT0L                               DAC_DATL_REG(DAC1_BASE_PTR,0)
#define DAC1_DAT0H                               DAC_DATH_REG(DAC1_BASE_PTR,0)
#define DAC1_DAT1L                               DAC_DATL_REG(DAC1_BASE_PTR,1)
#define DAC1_DAT1H                               DAC_DATH_REG(DAC1_BASE_PTR,1)
#define DAC1_DAT2L                               DAC_DATL_REG(DAC1_BASE_PTR,2)
#define DAC1_DAT2H                               DAC_DATH_REG(DAC1_BASE_PTR,2)
#define DAC1_DAT3L                               DAC_DATL_REG(DAC1_BASE_PTR,3)
#define DAC1_DAT3H                               DAC_DATH_REG(DAC1_BASE_PTR,3)
#define DAC1_DAT4L                               DAC_DATL_REG(DAC1_BASE_PTR,4)
#define DAC1_DAT4H                               DAC_DATH_REG(DAC1_BASE_PTR,4)
#define DAC1_DAT5L                               DAC_DATL_REG(DAC1_BASE_PTR,5)
#define DAC1_DAT5H                               DAC_DATH_REG(DAC1_BASE_PTR,5)
#define DAC1_DAT6L                               DAC_DATL_REG(DAC1_BASE_PTR,6)
#define DAC1_DAT6H                               DAC_DATH_REG(DAC1_BASE_PTR,6)
#define DAC1_DAT7L                               DAC_DATL_REG(DAC1_BASE_PTR,7)
#define DAC1_DAT7H                               DAC_DATH_REG(DAC1_BASE_PTR,7)
#define DAC1_DAT8L                               DAC_DATL_REG(DAC1_BASE_PTR,8)
#define DAC1_DAT8H                               DAC_DATH_REG(DAC1_BASE_PTR,8)
#define DAC1_DAT9L                               DAC_DATL_REG(DAC1_BASE_PTR,9)
#define DAC1_DAT9H                               DAC_DATH_REG(DAC1_BASE_PTR,9)
#define DAC1_DAT10L                              DAC_DATL_REG(DAC1_BASE_PTR,10)
#define DAC1_DAT10H                              DAC_DATH_REG(DAC1_BASE_PTR,10)
#define DAC1_DAT11L                              DAC_DATL_REG(DAC1_BASE_PTR,11)
#define DAC1_DAT11H                              DAC_DATH_REG(DAC1_BASE_PTR,11)
#define DAC1_DAT12L                              DAC_DATL_REG(DAC1_BASE_PTR,12)
#define DAC1_DAT12H                              DAC_DATH_REG(DAC1_BASE_PTR,12)
#define DAC1_DAT13L                              DAC_DATL_REG(DAC1_BASE_PTR,13)
#define DAC1_DAT13H                              DAC_DATH_REG(DAC1_BASE_PTR,13)
#define DAC1_DAT14L                              DAC_DATL_REG(DAC1_BASE_PTR,14)
#define DAC1_DAT14H                              DAC_DATH_REG(DAC1_BASE_PTR,14)
#define DAC1_DAT15L                              DAC_DATL_REG(DAC1_BASE_PTR,15)
#define DAC1_DAT15H                              DAC_DATH_REG(DAC1_BASE_PTR,15)
#define DAC1_SR                                  DAC_SR_REG(DAC1_BASE_PTR)
#define DAC1_C0                                  DAC_C0_REG(DAC1_BASE_PTR)
#define DAC1_C1                                  DAC_C1_REG(DAC1_BASE_PTR)
#define DAC1_C2                                  DAC_C2_REG(DAC1_BASE_PTR)

/*! \} */ /* end of group DAC_Register_Accessor_Macros */


/*! \} */ /* end of group DAC_Peripheral */


/* ----------------------------------------------------------------------------
   -- DMAMUX
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMAMUX_Peripheral DMAMUX */
/*! \{ */

/*! DMAMUX - Peripheral register structure */
typedef struct DMAMUX_MemMap {
  uint8_t CHCFG[16];                               /*!< Channel Configuration Register, array offset: 0x0, array step: 0x1 */
} volatile *DMAMUX_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DMAMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMAMUX_Register_Accessor_Macros DMAMUX - Register accessor macros */
/*! \{ */


/* DMAMUX - Register accessors */
#define DMAMUX_CHCFG_REG(base,index)             ((base)->CHCFG[index])

/*! \} */ /* end of group DMAMUX_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMAMUX_Register_Masks DMAMUX Register Masks */
/*! \{ */

/* CHCFG Bit Fields */
#define DMAMUX_CHCFG_SOURCE_MASK                 0x3Fu
#define DMAMUX_CHCFG_SOURCE_SHIFT                0
#define DMAMUX_CHCFG_SOURCE(x)                   (((x)<<DMAMUX_CHCFG_SOURCE_SHIFT)&DMAMUX_CHCFG_SOURCE_MASK)
#define DMAMUX_CHCFG_TRIG_MASK                   0x40u
#define DMAMUX_CHCFG_TRIG_SHIFT                  6
#define DMAMUX_CHCFG_ENBL_MASK                   0x80u
#define DMAMUX_CHCFG_ENBL_SHIFT                  7

/*! \} */ /* end of group DMAMUX_Register_Masks */


/* DMAMUX - Peripheral instance base addresses */
/*! Peripheral DMAMUX base pointer */
#define DMAMUX_BASE_PTR                          ((DMAMUX_MemMapPtr)0x40021000u)

/* ----------------------------------------------------------------------------
   -- DMAMUX - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMAMUX_Register_Accessor_Macros DMAMUX - Register accessor macros */
/*! \{ */


/* DMAMUX - Register instance definitions */
/* DMAMUX */
#define DMAMUX_CHCFG0                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,0)
#define DMAMUX_CHCFG1                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,1)
#define DMAMUX_CHCFG2                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,2)
#define DMAMUX_CHCFG3                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,3)
#define DMAMUX_CHCFG4                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,4)
#define DMAMUX_CHCFG5                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,5)
#define DMAMUX_CHCFG6                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,6)
#define DMAMUX_CHCFG7                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,7)
#define DMAMUX_CHCFG8                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,8)
#define DMAMUX_CHCFG9                            DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,9)
#define DMAMUX_CHCFG10                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,10)
#define DMAMUX_CHCFG11                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,11)
#define DMAMUX_CHCFG12                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,12)
#define DMAMUX_CHCFG13                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,13)
#define DMAMUX_CHCFG14                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,14)
#define DMAMUX_CHCFG15                           DMAMUX_CHCFG_REG(DMAMUX_BASE_PTR,15)

/*! \} */ /* end of group DMAMUX_Register_Accessor_Macros */


/*! \} */ /* end of group DMAMUX_Peripheral */


/* ----------------------------------------------------------------------------
   -- EWM
   ---------------------------------------------------------------------------- */

/*! \addtogroup EWM_Peripheral EWM */
/*! \{ */

/*! EWM - Peripheral register structure */
typedef struct EWM_MemMap {
  uint8_t CTRL;                                    /*!< Control Register, offset: 0x0 */
  uint8_t SERV;                                    /*!< Service Register, offset: 0x1 */
  uint8_t CMPL;                                    /*!< Compare Low Register, offset: 0x2 */
  uint8_t CMPH;                                    /*!< Compare High Register, offset: 0x3 */
} volatile *EWM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- EWM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup EWM_Register_Accessor_Macros EWM - Register accessor macros */
/*! \{ */


/* EWM - Register accessors */
#define EWM_CTRL_REG(base)                       ((base)->CTRL)
#define EWM_SERV_REG(base)                       ((base)->SERV)
#define EWM_CMPL_REG(base)                       ((base)->CMPL)
#define EWM_CMPH_REG(base)                       ((base)->CMPH)

/*! \} */ /* end of group EWM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- EWM Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup EWM_Register_Masks EWM Register Masks */
/*! \{ */

/* CTRL Bit Fields */
#define EWM_CTRL_EWMEN_MASK                      0x1u
#define EWM_CTRL_EWMEN_SHIFT                     0
#define EWM_CTRL_ASSIN_MASK                      0x2u
#define EWM_CTRL_ASSIN_SHIFT                     1
#define EWM_CTRL_INEN_MASK                       0x4u
#define EWM_CTRL_INEN_SHIFT                      2
/* SERV Bit Fields */
#define EWM_SERV_SERVICE_MASK                    0xFFu
#define EWM_SERV_SERVICE_SHIFT                   0
#define EWM_SERV_SERVICE(x)                      (((x)<<EWM_SERV_SERVICE_SHIFT)&EWM_SERV_SERVICE_MASK)
/* CMPL Bit Fields */
#define EWM_CMPL_COMPAREL_MASK                   0xFFu
#define EWM_CMPL_COMPAREL_SHIFT                  0
#define EWM_CMPL_COMPAREL(x)                     (((x)<<EWM_CMPL_COMPAREL_SHIFT)&EWM_CMPL_COMPAREL_MASK)
/* CMPH Bit Fields */
#define EWM_CMPH_COMPAREH_MASK                   0xFFu
#define EWM_CMPH_COMPAREH_SHIFT                  0
#define EWM_CMPH_COMPAREH(x)                     (((x)<<EWM_CMPH_COMPAREH_SHIFT)&EWM_CMPH_COMPAREH_MASK)

/*! \} */ /* end of group EWM_Register_Masks */


/* EWM - Peripheral instance base addresses */
/*! Peripheral EWM base pointer */
#define EWM_BASE_PTR                             ((EWM_MemMapPtr)0x4005F000u)

/* ----------------------------------------------------------------------------
   -- EWM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup EWM_Register_Accessor_Macros EWM - Register accessor macros */
/*! \{ */


/* EWM - Register instance definitions */
/* EWM */
#define EWM_CTRL                                 EWM_CTRL_REG(EWM_BASE_PTR)
#define EWM_SERV                                 EWM_SERV_REG(EWM_BASE_PTR)
#define EWM_CMPL                                 EWM_CMPL_REG(EWM_BASE_PTR)
#define EWM_CMPH                                 EWM_CMPH_REG(EWM_BASE_PTR)

/*! \} */ /* end of group EWM_Register_Accessor_Macros */


/*! \} */ /* end of group EWM_Peripheral */


/* ----------------------------------------------------------------------------
   -- FB
   ---------------------------------------------------------------------------- */

/*! \addtogroup FB_Peripheral FB */
/*! \{ */

/*! FB - Peripheral register structure */
typedef struct FB_MemMap {
  struct {                                         /* offset: 0x0, array step: 0xC */
    uint32_t CSAR;                                   /*!< Chip select address register, array offset: 0x0, array step: 0xC */
    uint32_t CSMR;                                   /*!< Chip select mask register, array offset: 0x4, array step: 0xC */
    uint32_t CSCR;                                   /*!< Chip select control register, array offset: 0x8, array step: 0xC */
  } CS[6];
  uint8_t RESERVED_0[24];
  uint32_t CSPMCR;                                 /*!< Chip select port multiplexing control register, offset: 0x60 */
} volatile *FB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FB_Register_Accessor_Macros FB - Register accessor macros */
/*! \{ */


/* FB - Register accessors */
#define FB_CSAR_REG(base,index)                  ((base)->CS[index].CSAR)
#define FB_CSMR_REG(base,index)                  ((base)->CS[index].CSMR)
#define FB_CSCR_REG(base,index)                  ((base)->CS[index].CSCR)
#define FB_CSPMCR_REG(base)                      ((base)->CSPMCR)

/*! \} */ /* end of group FB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FB Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup FB_Register_Masks FB Register Masks */
/*! \{ */

/* CSAR Bit Fields */
#define FB_CSAR_BA_MASK                          0xFFFF0000u
#define FB_CSAR_BA_SHIFT                         16
#define FB_CSAR_BA(x)                            (((x)<<FB_CSAR_BA_SHIFT)&FB_CSAR_BA_MASK)
/* CSMR Bit Fields */
#define FB_CSMR_V_MASK                           0x1u
#define FB_CSMR_V_SHIFT                          0
#define FB_CSMR_WP_MASK                          0x100u
#define FB_CSMR_WP_SHIFT                         8
#define FB_CSMR_BAM_MASK                         0xFFFF0000u
#define FB_CSMR_BAM_SHIFT                        16
#define FB_CSMR_BAM(x)                           (((x)<<FB_CSMR_BAM_SHIFT)&FB_CSMR_BAM_MASK)
/* CSCR Bit Fields */
#define FB_CSCR_BSTW_MASK                        0x8u
#define FB_CSCR_BSTW_SHIFT                       3
#define FB_CSCR_BSTR_MASK                        0x10u
#define FB_CSCR_BSTR_SHIFT                       4
#define FB_CSCR_BEM_MASK                         0x20u
#define FB_CSCR_BEM_SHIFT                        5
#define FB_CSCR_PS_MASK                          0xC0u
#define FB_CSCR_PS_SHIFT                         6
#define FB_CSCR_PS(x)                            (((x)<<FB_CSCR_PS_SHIFT)&FB_CSCR_PS_MASK)
#define FB_CSCR_AA_MASK                          0x100u
#define FB_CSCR_AA_SHIFT                         8
#define FB_CSCR_BLS_MASK                         0x200u
#define FB_CSCR_BLS_SHIFT                        9
#define FB_CSCR_WS_MASK                          0xFC00u
#define FB_CSCR_WS_SHIFT                         10
#define FB_CSCR_WS(x)                            (((x)<<FB_CSCR_WS_SHIFT)&FB_CSCR_WS_MASK)
#define FB_CSCR_WRAH_MASK                        0x30000u
#define FB_CSCR_WRAH_SHIFT                       16
#define FB_CSCR_WRAH(x)                          (((x)<<FB_CSCR_WRAH_SHIFT)&FB_CSCR_WRAH_MASK)
#define FB_CSCR_RDAH_MASK                        0xC0000u
#define FB_CSCR_RDAH_SHIFT                       18
#define FB_CSCR_RDAH(x)                          (((x)<<FB_CSCR_RDAH_SHIFT)&FB_CSCR_RDAH_MASK)
#define FB_CSCR_ASET_MASK                        0x300000u
#define FB_CSCR_ASET_SHIFT                       20
#define FB_CSCR_ASET(x)                          (((x)<<FB_CSCR_ASET_SHIFT)&FB_CSCR_ASET_MASK)
#define FB_CSCR_EXALE_MASK                       0x400000u
#define FB_CSCR_EXALE_SHIFT                      22
#define FB_CSCR_SWSEN_MASK                       0x800000u
#define FB_CSCR_SWSEN_SHIFT                      23
#define FB_CSCR_SWS_MASK                         0xFC000000u
#define FB_CSCR_SWS_SHIFT                        26
#define FB_CSCR_SWS(x)                           (((x)<<FB_CSCR_SWS_SHIFT)&FB_CSCR_SWS_MASK)
/* CSPMCR Bit Fields */
#define FB_CSPMCR_GROUP5_MASK                    0xF000u
#define FB_CSPMCR_GROUP5_SHIFT                   12
#define FB_CSPMCR_GROUP5(x)                      (((x)<<FB_CSPMCR_GROUP5_SHIFT)&FB_CSPMCR_GROUP5_MASK)
#define FB_CSPMCR_GROUP4_MASK                    0xF0000u
#define FB_CSPMCR_GROUP4_SHIFT                   16
#define FB_CSPMCR_GROUP4(x)                      (((x)<<FB_CSPMCR_GROUP4_SHIFT)&FB_CSPMCR_GROUP4_MASK)
#define FB_CSPMCR_GROUP3_MASK                    0xF00000u
#define FB_CSPMCR_GROUP3_SHIFT                   20
#define FB_CSPMCR_GROUP3(x)                      (((x)<<FB_CSPMCR_GROUP3_SHIFT)&FB_CSPMCR_GROUP3_MASK)
#define FB_CSPMCR_GROUP2_MASK                    0xF000000u
#define FB_CSPMCR_GROUP2_SHIFT                   24
#define FB_CSPMCR_GROUP2(x)                      (((x)<<FB_CSPMCR_GROUP2_SHIFT)&FB_CSPMCR_GROUP2_MASK)
#define FB_CSPMCR_GROUP1_MASK                    0xF0000000u
#define FB_CSPMCR_GROUP1_SHIFT                   28
#define FB_CSPMCR_GROUP1(x)                      (((x)<<FB_CSPMCR_GROUP1_SHIFT)&FB_CSPMCR_GROUP1_MASK)

/*! \} */ /* end of group FB_Register_Masks */


/* FB - Peripheral instance base addresses */
/*! Peripheral FB base pointer */
#define FB_BASE_PTR                              ((FB_MemMapPtr)0x4000C000u)

/* ----------------------------------------------------------------------------
   -- FB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FB_Register_Accessor_Macros FB - Register accessor macros */
/*! \{ */


/* FB - Register instance definitions */
/* FB */
#define FB_CSAR0                                 FB_CSAR_REG(FB_BASE_PTR,0)
#define FB_CSMR0                                 FB_CSMR_REG(FB_BASE_PTR,0)
#define FB_CSCR0                                 FB_CSCR_REG(FB_BASE_PTR,0)
#define FB_CSAR1                                 FB_CSAR_REG(FB_BASE_PTR,1)
#define FB_CSMR1                                 FB_CSMR_REG(FB_BASE_PTR,1)
#define FB_CSCR1                                 FB_CSCR_REG(FB_BASE_PTR,1)
#define FB_CSAR2                                 FB_CSAR_REG(FB_BASE_PTR,2)
#define FB_CSMR2                                 FB_CSMR_REG(FB_BASE_PTR,2)
#define FB_CSCR2                                 FB_CSCR_REG(FB_BASE_PTR,2)
#define FB_CSAR3                                 FB_CSAR_REG(FB_BASE_PTR,3)
#define FB_CSMR3                                 FB_CSMR_REG(FB_BASE_PTR,3)
#define FB_CSCR3                                 FB_CSCR_REG(FB_BASE_PTR,3)
#define FB_CSAR4                                 FB_CSAR_REG(FB_BASE_PTR,4)
#define FB_CSMR4                                 FB_CSMR_REG(FB_BASE_PTR,4)
#define FB_CSCR4                                 FB_CSCR_REG(FB_BASE_PTR,4)
#define FB_CSAR5                                 FB_CSAR_REG(FB_BASE_PTR,5)
#define FB_CSMR5                                 FB_CSMR_REG(FB_BASE_PTR,5)
#define FB_CSCR5                                 FB_CSCR_REG(FB_BASE_PTR,5)
#define FB_CSPMCR                                FB_CSPMCR_REG(FB_BASE_PTR)

/*! \} */ /* end of group FB_Register_Accessor_Macros */


/*! \} */ /* end of group FB_Peripheral */


/* ----------------------------------------------------------------------------
   -- FMC
   ---------------------------------------------------------------------------- */

/*! \addtogroup FMC_Peripheral FMC */
/*! \{ */

/*! FMC - Peripheral register structure */
typedef struct FMC_MemMap {
  uint32_t PFAPR;                                  /*!< Flash Access Protection Register, offset: 0x0 */
  uint32_t PFB0CR;                                 /*!< Flash Bank 0 Control Register, offset: 0x4 */
  uint32_t PFB1CR;                                 /*!< Flash Bank 1 Control Register, offset: 0x8 */
  uint8_t RESERVED_0[244];
  uint32_t TAGVD[4][8];                            /*!< Cache Directory Storage, array offset: 0x100, array step: index*0x20, index2*0x4 */
  uint8_t RESERVED_1[128];
  struct {                                         /* offset: 0x200, array step: index*0x40, index2*0x8 */
    uint32_t DATA_U;                                 /*!< Cache Data Storage (upper word), array offset: 0x200, array step: index*0x40, index2*0x8 */
    uint32_t DATA_L;                                 /*!< Cache Data Storage (lower word), array offset: 0x204, array step: index*0x40, index2*0x8 */
  } SET[4][8];
} volatile *FMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FMC_Register_Accessor_Macros FMC - Register accessor macros */
/*! \{ */


/* FMC - Register accessors */
#define FMC_PFAPR_REG(base)                      ((base)->PFAPR)
#define FMC_PFB0CR_REG(base)                     ((base)->PFB0CR)
#define FMC_PFB1CR_REG(base)                     ((base)->PFB1CR)
#define FMC_TAGVD_REG(base,index,index2)         ((base)->TAGVD[index][index2])
#define FMC_DATA_U_REG(base,index,index2)        ((base)->SET[index][index2].DATA_U)
#define FMC_DATA_L_REG(base,index,index2)        ((base)->SET[index][index2].DATA_L)

/*! \} */ /* end of group FMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup FMC_Register_Masks FMC Register Masks */
/*! \{ */

/* PFAPR Bit Fields */
#define FMC_PFAPR_M0AP_MASK                      0x3u
#define FMC_PFAPR_M0AP_SHIFT                     0
#define FMC_PFAPR_M0AP(x)                        (((x)<<FMC_PFAPR_M0AP_SHIFT)&FMC_PFAPR_M0AP_MASK)
#define FMC_PFAPR_M1AP_MASK                      0xCu
#define FMC_PFAPR_M1AP_SHIFT                     2
#define FMC_PFAPR_M1AP(x)                        (((x)<<FMC_PFAPR_M1AP_SHIFT)&FMC_PFAPR_M1AP_MASK)
#define FMC_PFAPR_M2AP_MASK                      0x30u
#define FMC_PFAPR_M2AP_SHIFT                     4
#define FMC_PFAPR_M2AP(x)                        (((x)<<FMC_PFAPR_M2AP_SHIFT)&FMC_PFAPR_M2AP_MASK)
#define FMC_PFAPR_M3AP_MASK                      0xC0u
#define FMC_PFAPR_M3AP_SHIFT                     6
#define FMC_PFAPR_M3AP(x)                        (((x)<<FMC_PFAPR_M3AP_SHIFT)&FMC_PFAPR_M3AP_MASK)
#define FMC_PFAPR_M4AP_MASK                      0x300u
#define FMC_PFAPR_M4AP_SHIFT                     8
#define FMC_PFAPR_M4AP(x)                        (((x)<<FMC_PFAPR_M4AP_SHIFT)&FMC_PFAPR_M4AP_MASK)
#define FMC_PFAPR_M5AP_MASK                      0xC00u
#define FMC_PFAPR_M5AP_SHIFT                     10
#define FMC_PFAPR_M5AP(x)                        (((x)<<FMC_PFAPR_M5AP_SHIFT)&FMC_PFAPR_M5AP_MASK)
#define FMC_PFAPR_M6AP_MASK                      0x3000u
#define FMC_PFAPR_M6AP_SHIFT                     12
#define FMC_PFAPR_M6AP(x)                        (((x)<<FMC_PFAPR_M6AP_SHIFT)&FMC_PFAPR_M6AP_MASK)
#define FMC_PFAPR_M7AP_MASK                      0xC000u
#define FMC_PFAPR_M7AP_SHIFT                     14
#define FMC_PFAPR_M7AP(x)                        (((x)<<FMC_PFAPR_M7AP_SHIFT)&FMC_PFAPR_M7AP_MASK)
#define FMC_PFAPR_M0PFD_MASK                     0x10000u
#define FMC_PFAPR_M0PFD_SHIFT                    16
#define FMC_PFAPR_M1PFD_MASK                     0x20000u
#define FMC_PFAPR_M1PFD_SHIFT                    17
#define FMC_PFAPR_M2PFD_MASK                     0x40000u
#define FMC_PFAPR_M2PFD_SHIFT                    18
#define FMC_PFAPR_M3PFD_MASK                     0x80000u
#define FMC_PFAPR_M3PFD_SHIFT                    19
#define FMC_PFAPR_M4PFD_MASK                     0x100000u
#define FMC_PFAPR_M4PFD_SHIFT                    20
#define FMC_PFAPR_M5PFD_MASK                     0x200000u
#define FMC_PFAPR_M5PFD_SHIFT                    21
#define FMC_PFAPR_M6PFD_MASK                     0x400000u
#define FMC_PFAPR_M6PFD_SHIFT                    22
#define FMC_PFAPR_M7PFD_MASK                     0x800000u
#define FMC_PFAPR_M7PFD_SHIFT                    23
/* PFB0CR Bit Fields */
#define FMC_PFB0CR_B0SEBE_MASK                   0x1u
#define FMC_PFB0CR_B0SEBE_SHIFT                  0
#define FMC_PFB0CR_B0IPE_MASK                    0x2u
#define FMC_PFB0CR_B0IPE_SHIFT                   1
#define FMC_PFB0CR_B0DPE_MASK                    0x4u
#define FMC_PFB0CR_B0DPE_SHIFT                   2
#define FMC_PFB0CR_B0ICE_MASK                    0x8u
#define FMC_PFB0CR_B0ICE_SHIFT                   3
#define FMC_PFB0CR_B0DCE_MASK                    0x10u
#define FMC_PFB0CR_B0DCE_SHIFT                   4
#define FMC_PFB0CR_CRC_MASK                      0xE0u
#define FMC_PFB0CR_CRC_SHIFT                     5
#define FMC_PFB0CR_CRC(x)                        (((x)<<FMC_PFB0CR_CRC_SHIFT)&FMC_PFB0CR_CRC_MASK)
#define FMC_PFB0CR_B0MW_MASK                     0x60000u
#define FMC_PFB0CR_B0MW_SHIFT                    17
#define FMC_PFB0CR_B0MW(x)                       (((x)<<FMC_PFB0CR_B0MW_SHIFT)&FMC_PFB0CR_B0MW_MASK)
#define FMC_PFB0CR_S_B_INV_MASK                  0x80000u
#define FMC_PFB0CR_S_B_INV_SHIFT                 19
#define FMC_PFB0CR_CINV_WAY_MASK                 0xF00000u
#define FMC_PFB0CR_CINV_WAY_SHIFT                20
#define FMC_PFB0CR_CINV_WAY(x)                   (((x)<<FMC_PFB0CR_CINV_WAY_SHIFT)&FMC_PFB0CR_CINV_WAY_MASK)
#define FMC_PFB0CR_CLCK_WAY_MASK                 0xF000000u
#define FMC_PFB0CR_CLCK_WAY_SHIFT                24
#define FMC_PFB0CR_CLCK_WAY(x)                   (((x)<<FMC_PFB0CR_CLCK_WAY_SHIFT)&FMC_PFB0CR_CLCK_WAY_MASK)
#define FMC_PFB0CR_B0RWSC_MASK                   0xF0000000u
#define FMC_PFB0CR_B0RWSC_SHIFT                  28
#define FMC_PFB0CR_B0RWSC(x)                     (((x)<<FMC_PFB0CR_B0RWSC_SHIFT)&FMC_PFB0CR_B0RWSC_MASK)
/* PFB1CR Bit Fields */
#define FMC_PFB1CR_B1SEBE_MASK                   0x1u
#define FMC_PFB1CR_B1SEBE_SHIFT                  0
#define FMC_PFB1CR_B1IPE_MASK                    0x2u
#define FMC_PFB1CR_B1IPE_SHIFT                   1
#define FMC_PFB1CR_B1DPE_MASK                    0x4u
#define FMC_PFB1CR_B1DPE_SHIFT                   2
#define FMC_PFB1CR_B1ICE_MASK                    0x8u
#define FMC_PFB1CR_B1ICE_SHIFT                   3
#define FMC_PFB1CR_B1DCE_MASK                    0x10u
#define FMC_PFB1CR_B1DCE_SHIFT                   4
#define FMC_PFB1CR_B1MW_MASK                     0x60000u
#define FMC_PFB1CR_B1MW_SHIFT                    17
#define FMC_PFB1CR_B1MW(x)                       (((x)<<FMC_PFB1CR_B1MW_SHIFT)&FMC_PFB1CR_B1MW_MASK)
#define FMC_PFB1CR_B1RWSC_MASK                   0xF0000000u
#define FMC_PFB1CR_B1RWSC_SHIFT                  28
#define FMC_PFB1CR_B1RWSC(x)                     (((x)<<FMC_PFB1CR_B1RWSC_SHIFT)&FMC_PFB1CR_B1RWSC_MASK)
/* TAGVD Bit Fields */
#define FMC_TAGVD_valid_MASK                     0x1u
#define FMC_TAGVD_valid_SHIFT                    0
#define FMC_TAGVD_tag_MASK                       0x7FFC0u
#define FMC_TAGVD_tag_SHIFT                      6
#define FMC_TAGVD_tag(x)                         (((x)<<FMC_TAGVD_tag_SHIFT)&FMC_TAGVD_tag_MASK)
/* DATA_U Bit Fields */
#define FMC_DATA_U_data_MASK                     0xFFFFFFFFu
#define FMC_DATA_U_data_SHIFT                    0
#define FMC_DATA_U_data(x)                       (((x)<<FMC_DATA_U_data_SHIFT)&FMC_DATA_U_data_MASK)
/* DATA_L Bit Fields */
#define FMC_DATA_L_data_MASK                     0xFFFFFFFFu
#define FMC_DATA_L_data_SHIFT                    0
#define FMC_DATA_L_data(x)                       (((x)<<FMC_DATA_L_data_SHIFT)&FMC_DATA_L_data_MASK)

/*! \} */ /* end of group FMC_Register_Masks */


/* FMC - Peripheral instance base addresses */
/*! Peripheral FMC base pointer */
#define FMC_BASE_PTR                             ((FMC_MemMapPtr)0x4001F000u)

/* ----------------------------------------------------------------------------
   -- FMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FMC_Register_Accessor_Macros FMC - Register accessor macros */
/*! \{ */


/* FMC - Register instance definitions */
/* FMC */
#define FMC_PFAPR                                FMC_PFAPR_REG(FMC_BASE_PTR)
#define FMC_PFB0CR                               FMC_PFB0CR_REG(FMC_BASE_PTR)
#define FMC_PFB1CR                               FMC_PFB1CR_REG(FMC_BASE_PTR)
#define FMC_TAGVDW0S0                            FMC_TAGVD_REG(FMC_BASE_PTR,0,0)
#define FMC_TAGVDW0S1                            FMC_TAGVD_REG(FMC_BASE_PTR,0,1)
#define FMC_TAGVDW0S2                            FMC_TAGVD_REG(FMC_BASE_PTR,0,2)
#define FMC_TAGVDW0S3                            FMC_TAGVD_REG(FMC_BASE_PTR,0,3)
#define FMC_TAGVDW0S4                            FMC_TAGVD_REG(FMC_BASE_PTR,0,4)
#define FMC_TAGVDW0S5                            FMC_TAGVD_REG(FMC_BASE_PTR,0,5)
#define FMC_TAGVDW0S6                            FMC_TAGVD_REG(FMC_BASE_PTR,0,6)
#define FMC_TAGVDW0S7                            FMC_TAGVD_REG(FMC_BASE_PTR,0,7)
#define FMC_TAGVDW1S0                            FMC_TAGVD_REG(FMC_BASE_PTR,1,0)
#define FMC_TAGVDW1S1                            FMC_TAGVD_REG(FMC_BASE_PTR,1,1)
#define FMC_TAGVDW1S2                            FMC_TAGVD_REG(FMC_BASE_PTR,1,2)
#define FMC_TAGVDW1S3                            FMC_TAGVD_REG(FMC_BASE_PTR,1,3)
#define FMC_TAGVDW1S4                            FMC_TAGVD_REG(FMC_BASE_PTR,1,4)
#define FMC_TAGVDW1S5                            FMC_TAGVD_REG(FMC_BASE_PTR,1,5)
#define FMC_TAGVDW1S6                            FMC_TAGVD_REG(FMC_BASE_PTR,1,6)
#define FMC_TAGVDW1S7                            FMC_TAGVD_REG(FMC_BASE_PTR,1,7)
#define FMC_TAGVDW2S0                            FMC_TAGVD_REG(FMC_BASE_PTR,2,0)
#define FMC_TAGVDW2S1                            FMC_TAGVD_REG(FMC_BASE_PTR,2,1)
#define FMC_TAGVDW2S2                            FMC_TAGVD_REG(FMC_BASE_PTR,2,2)
#define FMC_TAGVDW2S3                            FMC_TAGVD_REG(FMC_BASE_PTR,2,3)
#define FMC_TAGVDW2S4                            FMC_TAGVD_REG(FMC_BASE_PTR,2,4)
#define FMC_TAGVDW2S5                            FMC_TAGVD_REG(FMC_BASE_PTR,2,5)
#define FMC_TAGVDW2S6                            FMC_TAGVD_REG(FMC_BASE_PTR,2,6)
#define FMC_TAGVDW2S7                            FMC_TAGVD_REG(FMC_BASE_PTR,2,7)
#define FMC_TAGVDW3S0                            FMC_TAGVD_REG(FMC_BASE_PTR,3,0)
#define FMC_TAGVDW3S1                            FMC_TAGVD_REG(FMC_BASE_PTR,3,1)
#define FMC_TAGVDW3S2                            FMC_TAGVD_REG(FMC_BASE_PTR,3,2)
#define FMC_TAGVDW3S3                            FMC_TAGVD_REG(FMC_BASE_PTR,3,3)
#define FMC_TAGVDW3S4                            FMC_TAGVD_REG(FMC_BASE_PTR,3,4)
#define FMC_TAGVDW3S5                            FMC_TAGVD_REG(FMC_BASE_PTR,3,5)
#define FMC_TAGVDW3S6                            FMC_TAGVD_REG(FMC_BASE_PTR,3,6)
#define FMC_TAGVDW3S7                            FMC_TAGVD_REG(FMC_BASE_PTR,3,7)
#define FMC_DATAW0S0U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,0)
#define FMC_DATAW0S0L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,0)
#define FMC_DATAW0S1U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,1)
#define FMC_DATAW0S1L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,1)
#define FMC_DATAW0S2U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,2)
#define FMC_DATAW0S2L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,2)
#define FMC_DATAW0S3U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,3)
#define FMC_DATAW0S3L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,3)
#define FMC_DATAW0S4U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,4)
#define FMC_DATAW0S4L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,4)
#define FMC_DATAW0S5U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,5)
#define FMC_DATAW0S5L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,5)
#define FMC_DATAW0S6U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,6)
#define FMC_DATAW0S6L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,6)
#define FMC_DATAW0S7U                            FMC_DATA_U_REG(FMC_BASE_PTR,0,7)
#define FMC_DATAW0S7L                            FMC_DATA_L_REG(FMC_BASE_PTR,0,7)
#define FMC_DATAW1S0U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,0)
#define FMC_DATAW1S0L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,0)
#define FMC_DATAW1S1U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,1)
#define FMC_DATAW1S1L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,1)
#define FMC_DATAW1S2U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,2)
#define FMC_DATAW1S2L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,2)
#define FMC_DATAW1S3U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,3)
#define FMC_DATAW1S3L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,3)
#define FMC_DATAW1S4U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,4)
#define FMC_DATAW1S4L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,4)
#define FMC_DATAW1S5U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,5)
#define FMC_DATAW1S5L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,5)
#define FMC_DATAW1S6U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,6)
#define FMC_DATAW1S6L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,6)
#define FMC_DATAW1S7U                            FMC_DATA_U_REG(FMC_BASE_PTR,1,7)
#define FMC_DATAW1S7L                            FMC_DATA_L_REG(FMC_BASE_PTR,1,7)
#define FMC_DATAW2S0U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,0)
#define FMC_DATAW2S0L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,0)
#define FMC_DATAW2S1U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,1)
#define FMC_DATAW2S1L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,1)
#define FMC_DATAW2S2U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,2)
#define FMC_DATAW2S2L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,2)
#define FMC_DATAW2S3U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,3)
#define FMC_DATAW2S3L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,3)
#define FMC_DATAW2S4U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,4)
#define FMC_DATAW2S4L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,4)
#define FMC_DATAW2S5U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,5)
#define FMC_DATAW2S5L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,5)
#define FMC_DATAW2S6U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,6)
#define FMC_DATAW2S6L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,6)
#define FMC_DATAW2S7U                            FMC_DATA_U_REG(FMC_BASE_PTR,2,7)
#define FMC_DATAW2S7L                            FMC_DATA_L_REG(FMC_BASE_PTR,2,7)
#define FMC_DATAW3S0U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,0)
#define FMC_DATAW3S0L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,0)
#define FMC_DATAW3S1U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,1)
#define FMC_DATAW3S1L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,1)
#define FMC_DATAW3S2U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,2)
#define FMC_DATAW3S2L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,2)
#define FMC_DATAW3S3U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,3)
#define FMC_DATAW3S3L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,3)
#define FMC_DATAW3S4U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,4)
#define FMC_DATAW3S4L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,4)
#define FMC_DATAW3S5U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,5)
#define FMC_DATAW3S5L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,5)
#define FMC_DATAW3S6U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,6)
#define FMC_DATAW3S6L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,6)
#define FMC_DATAW3S7U                            FMC_DATA_U_REG(FMC_BASE_PTR,3,7)
#define FMC_DATAW3S7L                            FMC_DATA_L_REG(FMC_BASE_PTR,3,7)

/*! \} */ /* end of group FMC_Register_Accessor_Macros */


/*! \} */ /* end of group FMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- FTFL
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTFL_Peripheral FTFL */
/*! \{ */

/*! FTFL - Peripheral register structure */
typedef struct FTFL_MemMap {
  uint8_t FSTAT;                                   /*!< Flash Status Register, offset: 0x0 */
  uint8_t FCNFG;                                   /*!< Flash Configuration Register, offset: 0x1 */
  uint8_t FSEC;                                    /*!< Flash Security Register, offset: 0x2 */
  uint8_t FOPT;                                    /*!< Flash Option Register, offset: 0x3 */
  uint8_t FCCOB3;                                  /*!< Flash Common Command Object Registers, offset: 0x4 */
  uint8_t FCCOB2;                                  /*!< Flash Common Command Object Registers, offset: 0x5 */
  uint8_t FCCOB1;                                  /*!< Flash Common Command Object Registers, offset: 0x6 */
  uint8_t FCCOB0;                                  /*!< Flash Common Command Object Registers, offset: 0x7 */
  uint8_t FCCOB7;                                  /*!< Flash Common Command Object Registers, offset: 0x8 */
  uint8_t FCCOB6;                                  /*!< Flash Common Command Object Registers, offset: 0x9 */
  uint8_t FCCOB5;                                  /*!< Flash Common Command Object Registers, offset: 0xA */
  uint8_t FCCOB4;                                  /*!< Flash Common Command Object Registers, offset: 0xB */
  uint8_t FCCOBB;                                  /*!< Flash Common Command Object Registers, offset: 0xC */
  uint8_t FCCOBA;                                  /*!< Flash Common Command Object Registers, offset: 0xD */
  uint8_t FCCOB9;                                  /*!< Flash Common Command Object Registers, offset: 0xE */
  uint8_t FCCOB8;                                  /*!< Flash Common Command Object Registers, offset: 0xF */
  uint8_t FPROT3;                                  /*!< Program Flash Protection Registers, offset: 0x10 */
  uint8_t FPROT2;                                  /*!< Program Flash Protection Registers, offset: 0x11 */
  uint8_t FPROT1;                                  /*!< Program Flash Protection Registers, offset: 0x12 */
  uint8_t FPROT0;                                  /*!< Program Flash Protection Registers, offset: 0x13 */
  uint8_t RESERVED_0[2];
  uint8_t FEPROT;                                  /*!< EEPROM Protection Register, offset: 0x16 */
  uint8_t FDPROT;                                  /*!< Data Flash Protection Register, offset: 0x17 */
} volatile *FTFL_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTFL - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTFL_Register_Accessor_Macros FTFL - Register accessor macros */
/*! \{ */


/* FTFL - Register accessors */
#define FTFL_FSTAT_REG(base)                     ((base)->FSTAT)
#define FTFL_FCNFG_REG(base)                     ((base)->FCNFG)
#define FTFL_FSEC_REG(base)                      ((base)->FSEC)
#define FTFL_FOPT_REG(base)                      ((base)->FOPT)
#define FTFL_FCCOB3_REG(base)                    ((base)->FCCOB3)
#define FTFL_FCCOB2_REG(base)                    ((base)->FCCOB2)
#define FTFL_FCCOB1_REG(base)                    ((base)->FCCOB1)
#define FTFL_FCCOB0_REG(base)                    ((base)->FCCOB0)
#define FTFL_FCCOB7_REG(base)                    ((base)->FCCOB7)
#define FTFL_FCCOB6_REG(base)                    ((base)->FCCOB6)
#define FTFL_FCCOB5_REG(base)                    ((base)->FCCOB5)
#define FTFL_FCCOB4_REG(base)                    ((base)->FCCOB4)
#define FTFL_FCCOBB_REG(base)                    ((base)->FCCOBB)
#define FTFL_FCCOBA_REG(base)                    ((base)->FCCOBA)
#define FTFL_FCCOB9_REG(base)                    ((base)->FCCOB9)
#define FTFL_FCCOB8_REG(base)                    ((base)->FCCOB8)
#define FTFL_FPROT3_REG(base)                    ((base)->FPROT3)
#define FTFL_FPROT2_REG(base)                    ((base)->FPROT2)
#define FTFL_FPROT1_REG(base)                    ((base)->FPROT1)
#define FTFL_FPROT0_REG(base)                    ((base)->FPROT0)
#define FTFL_FEPROT_REG(base)                    ((base)->FEPROT)
#define FTFL_FDPROT_REG(base)                    ((base)->FDPROT)

/*! \} */ /* end of group FTFL_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTFL Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTFL_Register_Masks FTFL Register Masks */
/*! \{ */

/* FSTAT Bit Fields */
#define FTFL_FSTAT_MGSTAT0_MASK                  0x1u
#define FTFL_FSTAT_MGSTAT0_SHIFT                 0
#define FTFL_FSTAT_FPVIOL_MASK                   0x10u
#define FTFL_FSTAT_FPVIOL_SHIFT                  4
#define FTFL_FSTAT_ACCERR_MASK                   0x20u
#define FTFL_FSTAT_ACCERR_SHIFT                  5
#define FTFL_FSTAT_RDCOLERR_MASK                 0x40u
#define FTFL_FSTAT_RDCOLERR_SHIFT                6
#define FTFL_FSTAT_CCIF_MASK                     0x80u
#define FTFL_FSTAT_CCIF_SHIFT                    7
/* FCNFG Bit Fields */
#define FTFL_FCNFG_EEERDY_MASK                   0x1u
#define FTFL_FCNFG_EEERDY_SHIFT                  0
#define FTFL_FCNFG_RAMRDY_MASK                   0x2u
#define FTFL_FCNFG_RAMRDY_SHIFT                  1
#define FTFL_FCNFG_PFLSH_MASK                    0x4u
#define FTFL_FCNFG_PFLSH_SHIFT                   2
#define FTFL_FCNFG_SWAP_MASK                     0x8u
#define FTFL_FCNFG_SWAP_SHIFT                    3
#define FTFL_FCNFG_ERSSUSP_MASK                  0x10u
#define FTFL_FCNFG_ERSSUSP_SHIFT                 4
#define FTFL_FCNFG_ERSAREQ_MASK                  0x20u
#define FTFL_FCNFG_ERSAREQ_SHIFT                 5
#define FTFL_FCNFG_RDCOLLIE_MASK                 0x40u
#define FTFL_FCNFG_RDCOLLIE_SHIFT                6
#define FTFL_FCNFG_CCIE_MASK                     0x80u
#define FTFL_FCNFG_CCIE_SHIFT                    7
/* FSEC Bit Fields */
#define FTFL_FSEC_SEC_MASK                       0x3u
#define FTFL_FSEC_SEC_SHIFT                      0
#define FTFL_FSEC_SEC(x)                         (((x)<<FTFL_FSEC_SEC_SHIFT)&FTFL_FSEC_SEC_MASK)
#define FTFL_FSEC_FSLACC_MASK                    0xCu
#define FTFL_FSEC_FSLACC_SHIFT                   2
#define FTFL_FSEC_FSLACC(x)                      (((x)<<FTFL_FSEC_FSLACC_SHIFT)&FTFL_FSEC_FSLACC_MASK)
#define FTFL_FSEC_MEEN_MASK                      0x30u
#define FTFL_FSEC_MEEN_SHIFT                     4
#define FTFL_FSEC_MEEN(x)                        (((x)<<FTFL_FSEC_MEEN_SHIFT)&FTFL_FSEC_MEEN_MASK)
#define FTFL_FSEC_KEYEN_MASK                     0xC0u
#define FTFL_FSEC_KEYEN_SHIFT                    6
#define FTFL_FSEC_KEYEN(x)                       (((x)<<FTFL_FSEC_KEYEN_SHIFT)&FTFL_FSEC_KEYEN_MASK)
/* FOPT Bit Fields */
#define FTFL_FOPT_OPT_MASK                       0xFFu
#define FTFL_FOPT_OPT_SHIFT                      0
#define FTFL_FOPT_OPT(x)                         (((x)<<FTFL_FOPT_OPT_SHIFT)&FTFL_FOPT_OPT_MASK)
/* FCCOB3 Bit Fields */
#define FTFL_FCCOB3_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB3_CCOBn_SHIFT                  0
#define FTFL_FCCOB3_CCOBn(x)                     (((x)<<FTFL_FCCOB3_CCOBn_SHIFT)&FTFL_FCCOB3_CCOBn_MASK)
/* FCCOB2 Bit Fields */
#define FTFL_FCCOB2_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB2_CCOBn_SHIFT                  0
#define FTFL_FCCOB2_CCOBn(x)                     (((x)<<FTFL_FCCOB2_CCOBn_SHIFT)&FTFL_FCCOB2_CCOBn_MASK)
/* FCCOB1 Bit Fields */
#define FTFL_FCCOB1_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB1_CCOBn_SHIFT                  0
#define FTFL_FCCOB1_CCOBn(x)                     (((x)<<FTFL_FCCOB1_CCOBn_SHIFT)&FTFL_FCCOB1_CCOBn_MASK)
/* FCCOB0 Bit Fields */
#define FTFL_FCCOB0_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB0_CCOBn_SHIFT                  0
#define FTFL_FCCOB0_CCOBn(x)                     (((x)<<FTFL_FCCOB0_CCOBn_SHIFT)&FTFL_FCCOB0_CCOBn_MASK)
/* FCCOB7 Bit Fields */
#define FTFL_FCCOB7_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB7_CCOBn_SHIFT                  0
#define FTFL_FCCOB7_CCOBn(x)                     (((x)<<FTFL_FCCOB7_CCOBn_SHIFT)&FTFL_FCCOB7_CCOBn_MASK)
/* FCCOB6 Bit Fields */
#define FTFL_FCCOB6_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB6_CCOBn_SHIFT                  0
#define FTFL_FCCOB6_CCOBn(x)                     (((x)<<FTFL_FCCOB6_CCOBn_SHIFT)&FTFL_FCCOB6_CCOBn_MASK)
/* FCCOB5 Bit Fields */
#define FTFL_FCCOB5_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB5_CCOBn_SHIFT                  0
#define FTFL_FCCOB5_CCOBn(x)                     (((x)<<FTFL_FCCOB5_CCOBn_SHIFT)&FTFL_FCCOB5_CCOBn_MASK)
/* FCCOB4 Bit Fields */
#define FTFL_FCCOB4_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB4_CCOBn_SHIFT                  0
#define FTFL_FCCOB4_CCOBn(x)                     (((x)<<FTFL_FCCOB4_CCOBn_SHIFT)&FTFL_FCCOB4_CCOBn_MASK)
/* FCCOBB Bit Fields */
#define FTFL_FCCOBB_CCOBn_MASK                   0xFFu
#define FTFL_FCCOBB_CCOBn_SHIFT                  0
#define FTFL_FCCOBB_CCOBn(x)                     (((x)<<FTFL_FCCOBB_CCOBn_SHIFT)&FTFL_FCCOBB_CCOBn_MASK)
/* FCCOBA Bit Fields */
#define FTFL_FCCOBA_CCOBn_MASK                   0xFFu
#define FTFL_FCCOBA_CCOBn_SHIFT                  0
#define FTFL_FCCOBA_CCOBn(x)                     (((x)<<FTFL_FCCOBA_CCOBn_SHIFT)&FTFL_FCCOBA_CCOBn_MASK)
/* FCCOB9 Bit Fields */
#define FTFL_FCCOB9_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB9_CCOBn_SHIFT                  0
#define FTFL_FCCOB9_CCOBn(x)                     (((x)<<FTFL_FCCOB9_CCOBn_SHIFT)&FTFL_FCCOB9_CCOBn_MASK)
/* FCCOB8 Bit Fields */
#define FTFL_FCCOB8_CCOBn_MASK                   0xFFu
#define FTFL_FCCOB8_CCOBn_SHIFT                  0
#define FTFL_FCCOB8_CCOBn(x)                     (((x)<<FTFL_FCCOB8_CCOBn_SHIFT)&FTFL_FCCOB8_CCOBn_MASK)
/* FPROT3 Bit Fields */
#define FTFL_FPROT3_PROT_MASK                    0xFFu
#define FTFL_FPROT3_PROT_SHIFT                   0
#define FTFL_FPROT3_PROT(x)                      (((x)<<FTFL_FPROT3_PROT_SHIFT)&FTFL_FPROT3_PROT_MASK)
/* FPROT2 Bit Fields */
#define FTFL_FPROT2_PROT_MASK                    0xFFu
#define FTFL_FPROT2_PROT_SHIFT                   0
#define FTFL_FPROT2_PROT(x)                      (((x)<<FTFL_FPROT2_PROT_SHIFT)&FTFL_FPROT2_PROT_MASK)
/* FPROT1 Bit Fields */
#define FTFL_FPROT1_PROT_MASK                    0xFFu
#define FTFL_FPROT1_PROT_SHIFT                   0
#define FTFL_FPROT1_PROT(x)                      (((x)<<FTFL_FPROT1_PROT_SHIFT)&FTFL_FPROT1_PROT_MASK)
/* FPROT0 Bit Fields */
#define FTFL_FPROT0_PROT_MASK                    0xFFu
#define FTFL_FPROT0_PROT_SHIFT                   0
#define FTFL_FPROT0_PROT(x)                      (((x)<<FTFL_FPROT0_PROT_SHIFT)&FTFL_FPROT0_PROT_MASK)
/* FEPROT Bit Fields */
#define FTFL_FEPROT_EPROT_MASK                   0xFFu
#define FTFL_FEPROT_EPROT_SHIFT                  0
#define FTFL_FEPROT_EPROT(x)                     (((x)<<FTFL_FEPROT_EPROT_SHIFT)&FTFL_FEPROT_EPROT_MASK)
/* FDPROT Bit Fields */
#define FTFL_FDPROT_DPROT_MASK                   0xFFu
#define FTFL_FDPROT_DPROT_SHIFT                  0
#define FTFL_FDPROT_DPROT(x)                     (((x)<<FTFL_FDPROT_DPROT_SHIFT)&FTFL_FDPROT_DPROT_MASK)

/*! \} */ /* end of group FTFL_Register_Masks */


/* FTFL - Peripheral instance base addresses */
/*! Peripheral FTFL base pointer */
#define FTFL_BASE_PTR                            ((FTFL_MemMapPtr)0x40020000u)

/* ----------------------------------------------------------------------------
   -- FTFL - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTFL_Register_Accessor_Macros FTFL - Register accessor macros */
/*! \{ */


/* FTFL - Register instance definitions */
/* FTFL */
#define FTFL_FSTAT                               FTFL_FSTAT_REG(FTFL_BASE_PTR)
#define FTFL_FCNFG                               FTFL_FCNFG_REG(FTFL_BASE_PTR)
#define FTFL_FSEC                                FTFL_FSEC_REG(FTFL_BASE_PTR)
#define FTFL_FOPT                                FTFL_FOPT_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB3                              FTFL_FCCOB3_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB2                              FTFL_FCCOB2_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB1                              FTFL_FCCOB1_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB0                              FTFL_FCCOB0_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB7                              FTFL_FCCOB7_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB6                              FTFL_FCCOB6_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB5                              FTFL_FCCOB5_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB4                              FTFL_FCCOB4_REG(FTFL_BASE_PTR)
#define FTFL_FCCOBB                              FTFL_FCCOBB_REG(FTFL_BASE_PTR)
#define FTFL_FCCOBA                              FTFL_FCCOBA_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB9                              FTFL_FCCOB9_REG(FTFL_BASE_PTR)
#define FTFL_FCCOB8                              FTFL_FCCOB8_REG(FTFL_BASE_PTR)
#define FTFL_FPROT3                              FTFL_FPROT3_REG(FTFL_BASE_PTR)
#define FTFL_FPROT2                              FTFL_FPROT2_REG(FTFL_BASE_PTR)
#define FTFL_FPROT1                              FTFL_FPROT1_REG(FTFL_BASE_PTR)
#define FTFL_FPROT0                              FTFL_FPROT0_REG(FTFL_BASE_PTR)
#define FTFL_FEPROT                              FTFL_FEPROT_REG(FTFL_BASE_PTR)
#define FTFL_FDPROT                              FTFL_FDPROT_REG(FTFL_BASE_PTR)

/*! \} */ /* end of group FTFL_Register_Accessor_Macros */


/*! \} */ /* end of group FTFL_Peripheral */


/* ----------------------------------------------------------------------------
   -- NV
   ---------------------------------------------------------------------------- */

/*! \addtogroup NV_Peripheral NV */
/*! \{ */

/*! NV - Peripheral register structure */
typedef struct NV_MemMap {
  uint8_t BACKKEY0;                                /*!< Backdoor Comparison Key 0., offset: 0x0 */
  uint8_t BACKKEY1;                                /*!< Backdoor Comparison Key 1., offset: 0x1 */
  uint8_t BACKKEY2;                                /*!< Backdoor Comparison Key 2., offset: 0x2 */
  uint8_t BACKKEY3;                                /*!< Backdoor Comparison Key 3., offset: 0x3 */
  uint8_t BACKKEY4;                                /*!< Backdoor Comparison Key 4., offset: 0x4 */
  uint8_t BACKKEY5;                                /*!< Backdoor Comparison Key 5., offset: 0x5 */
  uint8_t BACKKEY6;                                /*!< Backdoor Comparison Key 6., offset: 0x6 */
  uint8_t BACKKEY7;                                /*!< Backdoor Comparison Key 7., offset: 0x7 */
  uint8_t NVPROT3;                                 /*!< Non-volatile P-Flash Protection 1 - Low Register, offset: 0x8 */
  uint8_t NVPROT2;                                 /*!< Non-volatile P-Flash Protection 1 - High Register, offset: 0x9 */
  uint8_t NVPROT1;                                 /*!< Non-volatile P-Flash Protection 0 - Low Register, offset: 0xA */
  uint8_t NVPROT0;                                 /*!< Non-volatile P-Flash Protection 0 - High Register, offset: 0xB */
  uint8_t NVDPROT;                                 /*!< Non-volatile D-Flash Protection Register, offset: 0xC */
  uint8_t NVEPROT;                                 /*!< Non-volatile EERAM Protection Register, offset: 0xD */
  uint8_t NVOPT;                                   /*!< Non-volatile Flash Option Register, offset: 0xE */
  uint8_t NVSEC;                                   /*!< Non-volatile Flash Security Register, offset: 0xF */
} volatile *NV_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup NV_Register_Accessor_Macros NV - Register accessor macros */
/*! \{ */


/* NV - Register accessors */
#define NV_BACKKEY0_REG(base)                    ((base)->BACKKEY0)
#define NV_BACKKEY1_REG(base)                    ((base)->BACKKEY1)
#define NV_BACKKEY2_REG(base)                    ((base)->BACKKEY2)
#define NV_BACKKEY3_REG(base)                    ((base)->BACKKEY3)
#define NV_BACKKEY4_REG(base)                    ((base)->BACKKEY4)
#define NV_BACKKEY5_REG(base)                    ((base)->BACKKEY5)
#define NV_BACKKEY6_REG(base)                    ((base)->BACKKEY6)
#define NV_BACKKEY7_REG(base)                    ((base)->BACKKEY7)
#define NV_NVPROT3_REG(base)                     ((base)->NVPROT3)
#define NV_NVPROT2_REG(base)                     ((base)->NVPROT2)
#define NV_NVPROT1_REG(base)                     ((base)->NVPROT1)
#define NV_NVPROT0_REG(base)                     ((base)->NVPROT0)
#define NV_NVDPROT_REG(base)                     ((base)->NVDPROT)
#define NV_NVEPROT_REG(base)                     ((base)->NVEPROT)
#define NV_NVOPT_REG(base)                       ((base)->NVOPT)
#define NV_NVSEC_REG(base)                       ((base)->NVSEC)

/*! \} */ /* end of group NV_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NV Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup NV_Register_Masks NV Register Masks */
/*! \{ */

/* BACKKEY0 Bit Fields */
#define NV_BACKKEY0_KEY_MASK                     0xFFu
#define NV_BACKKEY0_KEY_SHIFT                    0
#define NV_BACKKEY0_KEY(x)                       (((x)<<NV_BACKKEY0_KEY_SHIFT)&NV_BACKKEY0_KEY_MASK)
/* BACKKEY1 Bit Fields */
#define NV_BACKKEY1_KEY_MASK                     0xFFu
#define NV_BACKKEY1_KEY_SHIFT                    0
#define NV_BACKKEY1_KEY(x)                       (((x)<<NV_BACKKEY1_KEY_SHIFT)&NV_BACKKEY1_KEY_MASK)
/* BACKKEY2 Bit Fields */
#define NV_BACKKEY2_KEY_MASK                     0xFFu
#define NV_BACKKEY2_KEY_SHIFT                    0
#define NV_BACKKEY2_KEY(x)                       (((x)<<NV_BACKKEY2_KEY_SHIFT)&NV_BACKKEY2_KEY_MASK)
/* BACKKEY3 Bit Fields */
#define NV_BACKKEY3_KEY_MASK                     0xFFu
#define NV_BACKKEY3_KEY_SHIFT                    0
#define NV_BACKKEY3_KEY(x)                       (((x)<<NV_BACKKEY3_KEY_SHIFT)&NV_BACKKEY3_KEY_MASK)
/* BACKKEY4 Bit Fields */
#define NV_BACKKEY4_KEY_MASK                     0xFFu
#define NV_BACKKEY4_KEY_SHIFT                    0
#define NV_BACKKEY4_KEY(x)                       (((x)<<NV_BACKKEY4_KEY_SHIFT)&NV_BACKKEY4_KEY_MASK)
/* BACKKEY5 Bit Fields */
#define NV_BACKKEY5_KEY_MASK                     0xFFu
#define NV_BACKKEY5_KEY_SHIFT                    0
#define NV_BACKKEY5_KEY(x)                       (((x)<<NV_BACKKEY5_KEY_SHIFT)&NV_BACKKEY5_KEY_MASK)
/* BACKKEY6 Bit Fields */
#define NV_BACKKEY6_KEY_MASK                     0xFFu
#define NV_BACKKEY6_KEY_SHIFT                    0
#define NV_BACKKEY6_KEY(x)                       (((x)<<NV_BACKKEY6_KEY_SHIFT)&NV_BACKKEY6_KEY_MASK)
/* BACKKEY7 Bit Fields */
#define NV_BACKKEY7_KEY_MASK                     0xFFu
#define NV_BACKKEY7_KEY_SHIFT                    0
#define NV_BACKKEY7_KEY(x)                       (((x)<<NV_BACKKEY7_KEY_SHIFT)&NV_BACKKEY7_KEY_MASK)
/* NVPROT3 Bit Fields */
#define NV_NVPROT3_PROT_MASK                     0xFFu
#define NV_NVPROT3_PROT_SHIFT                    0
#define NV_NVPROT3_PROT(x)                       (((x)<<NV_NVPROT3_PROT_SHIFT)&NV_NVPROT3_PROT_MASK)
/* NVPROT2 Bit Fields */
#define NV_NVPROT2_PROT_MASK                     0xFFu
#define NV_NVPROT2_PROT_SHIFT                    0
#define NV_NVPROT2_PROT(x)                       (((x)<<NV_NVPROT2_PROT_SHIFT)&NV_NVPROT2_PROT_MASK)
/* NVPROT1 Bit Fields */
#define NV_NVPROT1_PROT_MASK                     0xFFu
#define NV_NVPROT1_PROT_SHIFT                    0
#define NV_NVPROT1_PROT(x)                       (((x)<<NV_NVPROT1_PROT_SHIFT)&NV_NVPROT1_PROT_MASK)
/* NVPROT0 Bit Fields */
#define NV_NVPROT0_PROT_MASK                     0xFFu
#define NV_NVPROT0_PROT_SHIFT                    0
#define NV_NVPROT0_PROT(x)                       (((x)<<NV_NVPROT0_PROT_SHIFT)&NV_NVPROT0_PROT_MASK)
/* NVDPROT Bit Fields */
#define NV_NVDPROT_DPROT_MASK                    0xFFu
#define NV_NVDPROT_DPROT_SHIFT                   0
#define NV_NVDPROT_DPROT(x)                      (((x)<<NV_NVDPROT_DPROT_SHIFT)&NV_NVDPROT_DPROT_MASK)
/* NVEPROT Bit Fields */
#define NV_NVEPROT_EPROT_MASK                    0xFFu
#define NV_NVEPROT_EPROT_SHIFT                   0
#define NV_NVEPROT_EPROT(x)                      (((x)<<NV_NVEPROT_EPROT_SHIFT)&NV_NVEPROT_EPROT_MASK)
/* NVOPT Bit Fields */
#define NV_NVOPT_NVOPT_MASK                      0xFFu
#define NV_NVOPT_NVOPT_SHIFT                     0
#define NV_NVOPT_NVOPT(x)                        (((x)<<NV_NVOPT_NVOPT_SHIFT)&NV_NVOPT_NVOPT_MASK)
/* NVSEC Bit Fields */
#define NV_NVSEC_SEC_MASK                        0x3u
#define NV_NVSEC_SEC_SHIFT                       0
#define NV_NVSEC_SEC(x)                          (((x)<<NV_NVSEC_SEC_SHIFT)&NV_NVSEC_SEC_MASK)
#define NV_NVSEC_FSLACC_MASK                     0xCu
#define NV_NVSEC_FSLACC_SHIFT                    2
#define NV_NVSEC_FSLACC(x)                       (((x)<<NV_NVSEC_FSLACC_SHIFT)&NV_NVSEC_FSLACC_MASK)
#define NV_NVSEC_MEEN_MASK                       0x30u
#define NV_NVSEC_MEEN_SHIFT                      4
#define NV_NVSEC_MEEN(x)                         (((x)<<NV_NVSEC_MEEN_SHIFT)&NV_NVSEC_MEEN_MASK)
#define NV_NVSEC_KEYEN_MASK                      0xC0u
#define NV_NVSEC_KEYEN_SHIFT                     6
#define NV_NVSEC_KEYEN(x)                        (((x)<<NV_NVSEC_KEYEN_SHIFT)&NV_NVSEC_KEYEN_MASK)

/*! \} */ /* end of group NV_Register_Masks */


/* NV - Peripheral instance base addresses */
/*! Peripheral FTFL_FlashConfig base pointer */
#define FTFL_FlashConfig_BASE_PTR                ((NV_MemMapPtr)0x400u)

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup NV_Register_Accessor_Macros NV - Register accessor macros */
/*! \{ */


/* NV - Register instance definitions */
/* FTFL_FlashConfig */
#define NV_BACKKEY0                              NV_BACKKEY0_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY1                              NV_BACKKEY1_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY2                              NV_BACKKEY2_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY3                              NV_BACKKEY3_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY4                              NV_BACKKEY4_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY5                              NV_BACKKEY5_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY6                              NV_BACKKEY6_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_BACKKEY7                              NV_BACKKEY7_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_NVPROT3                               NV_NVPROT3_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_NVPROT2                               NV_NVPROT2_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_NVPROT1                               NV_NVPROT1_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_NVPROT0                               NV_NVPROT0_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_NVDPROT                               NV_NVDPROT_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_NVEPROT                               NV_NVEPROT_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_NVOPT                                 NV_NVOPT_REG(FTFL_FlashConfig_BASE_PTR)
#define NV_NVSEC                                 NV_NVSEC_REG(FTFL_FlashConfig_BASE_PTR)

/*! \} */ /* end of group NV_Register_Accessor_Macros */


/*! \} */ /* end of group NV_Peripheral */


/* ----------------------------------------------------------------------------
   -- FTM
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTM_Peripheral FTM */
/*! \{ */

/*! FTM - Peripheral register structure */
typedef struct FTM_MemMap {
  uint32_t SC;                                     /*!< Status and Control, offset: 0x0 */
  uint32_t CNT;                                    /*!< Counter, offset: 0x4 */
  uint32_t MOD;                                    /*!< Modulo, offset: 0x8 */
  struct {                                         /* offset: 0xC, array step: 0x8 */
    uint32_t CnSC;                                   /*!< Channel (n) Status and Control, array offset: 0xC, array step: 0x8 */
    uint32_t CnV;                                    /*!< Channel (n) Value, array offset: 0x10, array step: 0x8 */
  } CONTROLS[8];
  uint32_t CNTIN;                                  /*!< Counter Initial Value, offset: 0x4C */
  uint32_t STATUS;                                 /*!< Capture and Compare Status, offset: 0x50 */
  uint32_t MODE;                                   /*!< Features Mode Selection, offset: 0x54 */
  uint32_t SYNC;                                   /*!< Synchronization, offset: 0x58 */
  uint32_t OUTINIT;                                /*!< Initial State for Channels Output, offset: 0x5C */
  uint32_t OUTMASK;                                /*!< Output Mask, offset: 0x60 */
  uint32_t COMBINE;                                /*!< Function for Linked Channels, offset: 0x64 */
  uint32_t DEADTIME;                               /*!< Deadtime Insertion Control, offset: 0x68 */
  uint32_t EXTTRIG;                                /*!< FTM External Trigger, offset: 0x6C */
  uint32_t POL;                                    /*!< Channels Polarity, offset: 0x70 */
  uint32_t FMS;                                    /*!< Fault Mode Status, offset: 0x74 */
  uint32_t FILTER;                                 /*!< Input Capture Filter Control, offset: 0x78 */
  uint32_t FLTCTRL;                                /*!< Fault Control, offset: 0x7C */
  uint32_t QDCTRL;                                 /*!< Quadrature Decoder Control and Status, offset: 0x80 */
  uint32_t CONF;                                   /*!< Configuration, offset: 0x84 */
  uint32_t FLTPOL;                                 /*!< FTM Fault Input Polarity, offset: 0x88 */
  uint32_t SYNCONF;                                /*!< Synchronization Configuration, offset: 0x8C */
  uint32_t INVCTRL;                                /*!< FTM Inverting Control, offset: 0x90 */
  uint32_t SWOCTRL;                                /*!< FTM Software Output Control, offset: 0x94 */
  uint32_t PWMLOAD;                                /*!< FTM PWM Load, offset: 0x98 */
} volatile *FTM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros */
/*! \{ */


/* FTM - Register accessors */
#define FTM_SC_REG(base)                         ((base)->SC)
#define FTM_CNT_REG(base)                        ((base)->CNT)
#define FTM_MOD_REG(base)                        ((base)->MOD)
#define FTM_CnSC_REG(base,index)                 ((base)->CONTROLS[index].CnSC)
#define FTM_CnV_REG(base,index)                  ((base)->CONTROLS[index].CnV)
#define FTM_CNTIN_REG(base)                      ((base)->CNTIN)
#define FTM_STATUS_REG(base)                     ((base)->STATUS)
#define FTM_MODE_REG(base)                       ((base)->MODE)
#define FTM_SYNC_REG(base)                       ((base)->SYNC)
#define FTM_OUTINIT_REG(base)                    ((base)->OUTINIT)
#define FTM_OUTMASK_REG(base)                    ((base)->OUTMASK)
#define FTM_COMBINE_REG(base)                    ((base)->COMBINE)
#define FTM_DEADTIME_REG(base)                   ((base)->DEADTIME)
#define FTM_EXTTRIG_REG(base)                    ((base)->EXTTRIG)
#define FTM_POL_REG(base)                        ((base)->POL)
#define FTM_FMS_REG(base)                        ((base)->FMS)
#define FTM_FILTER_REG(base)                     ((base)->FILTER)
#define FTM_FLTCTRL_REG(base)                    ((base)->FLTCTRL)
#define FTM_QDCTRL_REG(base)                     ((base)->QDCTRL)
#define FTM_CONF_REG(base)                       ((base)->CONF)
#define FTM_FLTPOL_REG(base)                     ((base)->FLTPOL)
#define FTM_SYNCONF_REG(base)                    ((base)->SYNCONF)
#define FTM_INVCTRL_REG(base)                    ((base)->INVCTRL)
#define FTM_SWOCTRL_REG(base)                    ((base)->SWOCTRL)
#define FTM_PWMLOAD_REG(base)                    ((base)->PWMLOAD)

/*! \} */ /* end of group FTM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTM Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTM_Register_Masks FTM Register Masks */
/*! \{ */

/* SC Bit Fields */
#define FTM_SC_PS_MASK                           0x7u
#define FTM_SC_PS_SHIFT                          0
#define FTM_SC_PS(x)                             (((x)<<FTM_SC_PS_SHIFT)&FTM_SC_PS_MASK)
#define FTM_SC_CLKS_MASK                         0x18u
#define FTM_SC_CLKS_SHIFT                        3
#define FTM_SC_CLKS(x)                           (((x)<<FTM_SC_CLKS_SHIFT)&FTM_SC_CLKS_MASK)
#define FTM_SC_CPWMS_MASK                        0x20u
#define FTM_SC_CPWMS_SHIFT                       5
#define FTM_SC_TOIE_MASK                         0x40u
#define FTM_SC_TOIE_SHIFT                        6
#define FTM_SC_TOF_MASK                          0x80u
#define FTM_SC_TOF_SHIFT                         7
/* CNT Bit Fields */
#define FTM_CNT_COUNT_MASK                       0xFFFFu
#define FTM_CNT_COUNT_SHIFT                      0
#define FTM_CNT_COUNT(x)                         (((x)<<FTM_CNT_COUNT_SHIFT)&FTM_CNT_COUNT_MASK)
/* MOD Bit Fields */
#define FTM_MOD_MOD_MASK                         0xFFFFu
#define FTM_MOD_MOD_SHIFT                        0
#define FTM_MOD_MOD(x)                           (((x)<<FTM_MOD_MOD_SHIFT)&FTM_MOD_MOD_MASK)
/* CnSC Bit Fields */
#define FTM_CnSC_DMA_MASK                        0x1u
#define FTM_CnSC_DMA_SHIFT                       0
#define FTM_CnSC_ELSA_MASK                       0x4u
#define FTM_CnSC_ELSA_SHIFT                      2
#define FTM_CnSC_ELSB_MASK                       0x8u
#define FTM_CnSC_ELSB_SHIFT                      3
#define FTM_CnSC_MSA_MASK                        0x10u
#define FTM_CnSC_MSA_SHIFT                       4
#define FTM_CnSC_MSB_MASK                        0x20u
#define FTM_CnSC_MSB_SHIFT                       5
#define FTM_CnSC_CHIE_MASK                       0x40u
#define FTM_CnSC_CHIE_SHIFT                      6
#define FTM_CnSC_CHF_MASK                        0x80u
#define FTM_CnSC_CHF_SHIFT                       7
/* CnV Bit Fields */
#define FTM_CnV_VAL_MASK                         0xFFFFu
#define FTM_CnV_VAL_SHIFT                        0
#define FTM_CnV_VAL(x)                           (((x)<<FTM_CnV_VAL_SHIFT)&FTM_CnV_VAL_MASK)
/* CNTIN Bit Fields */
#define FTM_CNTIN_INIT_MASK                      0xFFFFu
#define FTM_CNTIN_INIT_SHIFT                     0
#define FTM_CNTIN_INIT(x)                        (((x)<<FTM_CNTIN_INIT_SHIFT)&FTM_CNTIN_INIT_MASK)
/* STATUS Bit Fields */
#define FTM_STATUS_CH0F_MASK                     0x1u
#define FTM_STATUS_CH0F_SHIFT                    0
#define FTM_STATUS_CH1F_MASK                     0x2u
#define FTM_STATUS_CH1F_SHIFT                    1
#define FTM_STATUS_CH2F_MASK                     0x4u
#define FTM_STATUS_CH2F_SHIFT                    2
#define FTM_STATUS_CH3F_MASK                     0x8u
#define FTM_STATUS_CH3F_SHIFT                    3
#define FTM_STATUS_CH4F_MASK                     0x10u
#define FTM_STATUS_CH4F_SHIFT                    4
#define FTM_STATUS_CH5F_MASK                     0x20u
#define FTM_STATUS_CH5F_SHIFT                    5
#define FTM_STATUS_CH6F_MASK                     0x40u
#define FTM_STATUS_CH6F_SHIFT                    6
#define FTM_STATUS_CH7F_MASK                     0x80u
#define FTM_STATUS_CH7F_SHIFT                    7
/* MODE Bit Fields */
#define FTM_MODE_FTMEN_MASK                      0x1u
#define FTM_MODE_FTMEN_SHIFT                     0
#define FTM_MODE_INIT_MASK                       0x2u
#define FTM_MODE_INIT_SHIFT                      1
#define FTM_MODE_WPDIS_MASK                      0x4u
#define FTM_MODE_WPDIS_SHIFT                     2
#define FTM_MODE_PWMSYNC_MASK                    0x8u
#define FTM_MODE_PWMSYNC_SHIFT                   3
#define FTM_MODE_CAPTEST_MASK                    0x10u
#define FTM_MODE_CAPTEST_SHIFT                   4
#define FTM_MODE_FAULTM_MASK                     0x60u
#define FTM_MODE_FAULTM_SHIFT                    5
#define FTM_MODE_FAULTM(x)                       (((x)<<FTM_MODE_FAULTM_SHIFT)&FTM_MODE_FAULTM_MASK)
#define FTM_MODE_FAULTIE_MASK                    0x80u
#define FTM_MODE_FAULTIE_SHIFT                   7
/* SYNC Bit Fields */
#define FTM_SYNC_CNTMIN_MASK                     0x1u
#define FTM_SYNC_CNTMIN_SHIFT                    0
#define FTM_SYNC_CNTMAX_MASK                     0x2u
#define FTM_SYNC_CNTMAX_SHIFT                    1
#define FTM_SYNC_REINIT_MASK                     0x4u
#define FTM_SYNC_REINIT_SHIFT                    2
#define FTM_SYNC_SYNCHOM_MASK                    0x8u
#define FTM_SYNC_SYNCHOM_SHIFT                   3
#define FTM_SYNC_TRIG0_MASK                      0x10u
#define FTM_SYNC_TRIG0_SHIFT                     4
#define FTM_SYNC_TRIG1_MASK                      0x20u
#define FTM_SYNC_TRIG1_SHIFT                     5
#define FTM_SYNC_TRIG2_MASK                      0x40u
#define FTM_SYNC_TRIG2_SHIFT                     6
#define FTM_SYNC_SWSYNC_MASK                     0x80u
#define FTM_SYNC_SWSYNC_SHIFT                    7
/* OUTINIT Bit Fields */
#define FTM_OUTINIT_CH0OI_MASK                   0x1u
#define FTM_OUTINIT_CH0OI_SHIFT                  0
#define FTM_OUTINIT_CH1OI_MASK                   0x2u
#define FTM_OUTINIT_CH1OI_SHIFT                  1
#define FTM_OUTINIT_CH2OI_MASK                   0x4u
#define FTM_OUTINIT_CH2OI_SHIFT                  2
#define FTM_OUTINIT_CH3OI_MASK                   0x8u
#define FTM_OUTINIT_CH3OI_SHIFT                  3
#define FTM_OUTINIT_CH4OI_MASK                   0x10u
#define FTM_OUTINIT_CH4OI_SHIFT                  4
#define FTM_OUTINIT_CH5OI_MASK                   0x20u
#define FTM_OUTINIT_CH5OI_SHIFT                  5
#define FTM_OUTINIT_CH6OI_MASK                   0x40u
#define FTM_OUTINIT_CH6OI_SHIFT                  6
#define FTM_OUTINIT_CH7OI_MASK                   0x80u
#define FTM_OUTINIT_CH7OI_SHIFT                  7
/* OUTMASK Bit Fields */
#define FTM_OUTMASK_CH0OM_MASK                   0x1u
#define FTM_OUTMASK_CH0OM_SHIFT                  0
#define FTM_OUTMASK_CH1OM_MASK                   0x2u
#define FTM_OUTMASK_CH1OM_SHIFT                  1
#define FTM_OUTMASK_CH2OM_MASK                   0x4u
#define FTM_OUTMASK_CH2OM_SHIFT                  2
#define FTM_OUTMASK_CH3OM_MASK                   0x8u
#define FTM_OUTMASK_CH3OM_SHIFT                  3
#define FTM_OUTMASK_CH4OM_MASK                   0x10u
#define FTM_OUTMASK_CH4OM_SHIFT                  4
#define FTM_OUTMASK_CH5OM_MASK                   0x20u
#define FTM_OUTMASK_CH5OM_SHIFT                  5
#define FTM_OUTMASK_CH6OM_MASK                   0x40u
#define FTM_OUTMASK_CH6OM_SHIFT                  6
#define FTM_OUTMASK_CH7OM_MASK                   0x80u
#define FTM_OUTMASK_CH7OM_SHIFT                  7
/* COMBINE Bit Fields */
#define FTM_COMBINE_COMBINE0_MASK                0x1u
#define FTM_COMBINE_COMBINE0_SHIFT               0
#define FTM_COMBINE_COMP0_MASK                   0x2u
#define FTM_COMBINE_COMP0_SHIFT                  1
#define FTM_COMBINE_DECAPEN0_MASK                0x4u
#define FTM_COMBINE_DECAPEN0_SHIFT               2
#define FTM_COMBINE_DECAP0_MASK                  0x8u
#define FTM_COMBINE_DECAP0_SHIFT                 3
#define FTM_COMBINE_DTEN0_MASK                   0x10u
#define FTM_COMBINE_DTEN0_SHIFT                  4
#define FTM_COMBINE_SYNCEN0_MASK                 0x20u
#define FTM_COMBINE_SYNCEN0_SHIFT                5
#define FTM_COMBINE_FAULTEN0_MASK                0x40u
#define FTM_COMBINE_FAULTEN0_SHIFT               6
#define FTM_COMBINE_COMBINE1_MASK                0x100u
#define FTM_COMBINE_COMBINE1_SHIFT               8
#define FTM_COMBINE_COMP1_MASK                   0x200u
#define FTM_COMBINE_COMP1_SHIFT                  9
#define FTM_COMBINE_DECAPEN1_MASK                0x400u
#define FTM_COMBINE_DECAPEN1_SHIFT               10
#define FTM_COMBINE_DECAP1_MASK                  0x800u
#define FTM_COMBINE_DECAP1_SHIFT                 11
#define FTM_COMBINE_DTEN1_MASK                   0x1000u
#define FTM_COMBINE_DTEN1_SHIFT                  12
#define FTM_COMBINE_SYNCEN1_MASK                 0x2000u
#define FTM_COMBINE_SYNCEN1_SHIFT                13
#define FTM_COMBINE_FAULTEN1_MASK                0x4000u
#define FTM_COMBINE_FAULTEN1_SHIFT               14
#define FTM_COMBINE_COMBINE2_MASK                0x10000u
#define FTM_COMBINE_COMBINE2_SHIFT               16
#define FTM_COMBINE_COMP2_MASK                   0x20000u
#define FTM_COMBINE_COMP2_SHIFT                  17
#define FTM_COMBINE_DECAPEN2_MASK                0x40000u
#define FTM_COMBINE_DECAPEN2_SHIFT               18
#define FTM_COMBINE_DECAP2_MASK                  0x80000u
#define FTM_COMBINE_DECAP2_SHIFT                 19
#define FTM_COMBINE_DTEN2_MASK                   0x100000u
#define FTM_COMBINE_DTEN2_SHIFT                  20
#define FTM_COMBINE_SYNCEN2_MASK                 0x200000u
#define FTM_COMBINE_SYNCEN2_SHIFT                21
#define FTM_COMBINE_FAULTEN2_MASK                0x400000u
#define FTM_COMBINE_FAULTEN2_SHIFT               22
#define FTM_COMBINE_COMBINE3_MASK                0x1000000u
#define FTM_COMBINE_COMBINE3_SHIFT               24
#define FTM_COMBINE_COMP3_MASK                   0x2000000u
#define FTM_COMBINE_COMP3_SHIFT                  25
#define FTM_COMBINE_DECAPEN3_MASK                0x4000000u
#define FTM_COMBINE_DECAPEN3_SHIFT               26
#define FTM_COMBINE_DECAP3_MASK                  0x8000000u
#define FTM_COMBINE_DECAP3_SHIFT                 27
#define FTM_COMBINE_DTEN3_MASK                   0x10000000u
#define FTM_COMBINE_DTEN3_SHIFT                  28
#define FTM_COMBINE_SYNCEN3_MASK                 0x20000000u
#define FTM_COMBINE_SYNCEN3_SHIFT                29
#define FTM_COMBINE_FAULTEN3_MASK                0x40000000u
#define FTM_COMBINE_FAULTEN3_SHIFT               30
/* DEADTIME Bit Fields */
#define FTM_DEADTIME_DTVAL_MASK                  0x3Fu
#define FTM_DEADTIME_DTVAL_SHIFT                 0
#define FTM_DEADTIME_DTVAL(x)                    (((x)<<FTM_DEADTIME_DTVAL_SHIFT)&FTM_DEADTIME_DTVAL_MASK)
#define FTM_DEADTIME_DTPS_MASK                   0xC0u
#define FTM_DEADTIME_DTPS_SHIFT                  6
#define FTM_DEADTIME_DTPS(x)                     (((x)<<FTM_DEADTIME_DTPS_SHIFT)&FTM_DEADTIME_DTPS_MASK)
/* EXTTRIG Bit Fields */
#define FTM_EXTTRIG_CH2TRIG_MASK                 0x1u
#define FTM_EXTTRIG_CH2TRIG_SHIFT                0
#define FTM_EXTTRIG_CH3TRIG_MASK                 0x2u
#define FTM_EXTTRIG_CH3TRIG_SHIFT                1
#define FTM_EXTTRIG_CH4TRIG_MASK                 0x4u
#define FTM_EXTTRIG_CH4TRIG_SHIFT                2
#define FTM_EXTTRIG_CH5TRIG_MASK                 0x8u
#define FTM_EXTTRIG_CH5TRIG_SHIFT                3
#define FTM_EXTTRIG_CH0TRIG_MASK                 0x10u
#define FTM_EXTTRIG_CH0TRIG_SHIFT                4
#define FTM_EXTTRIG_CH1TRIG_MASK                 0x20u
#define FTM_EXTTRIG_CH1TRIG_SHIFT                5
#define FTM_EXTTRIG_INITTRIGEN_MASK              0x40u
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             6
#define FTM_EXTTRIG_TRIGF_MASK                   0x80u
#define FTM_EXTTRIG_TRIGF_SHIFT                  7
/* POL Bit Fields */
#define FTM_POL_POL0_MASK                        0x1u
#define FTM_POL_POL0_SHIFT                       0
#define FTM_POL_POL1_MASK                        0x2u
#define FTM_POL_POL1_SHIFT                       1
#define FTM_POL_POL2_MASK                        0x4u
#define FTM_POL_POL2_SHIFT                       2
#define FTM_POL_POL3_MASK                        0x8u
#define FTM_POL_POL3_SHIFT                       3
#define FTM_POL_POL4_MASK                        0x10u
#define FTM_POL_POL4_SHIFT                       4
#define FTM_POL_POL5_MASK                        0x20u
#define FTM_POL_POL5_SHIFT                       5
#define FTM_POL_POL6_MASK                        0x40u
#define FTM_POL_POL6_SHIFT                       6
#define FTM_POL_POL7_MASK                        0x80u
#define FTM_POL_POL7_SHIFT                       7
/* FMS Bit Fields */
#define FTM_FMS_FAULTF0_MASK                     0x1u
#define FTM_FMS_FAULTF0_SHIFT                    0
#define FTM_FMS_FAULTF1_MASK                     0x2u
#define FTM_FMS_FAULTF1_SHIFT                    1
#define FTM_FMS_FAULTF2_MASK                     0x4u
#define FTM_FMS_FAULTF2_SHIFT                    2
#define FTM_FMS_FAULTF3_MASK                     0x8u
#define FTM_FMS_FAULTF3_SHIFT                    3
#define FTM_FMS_FAULTIN_MASK                     0x20u
#define FTM_FMS_FAULTIN_SHIFT                    5
#define FTM_FMS_WPEN_MASK                        0x40u
#define FTM_FMS_WPEN_SHIFT                       6
#define FTM_FMS_FAULTF_MASK                      0x80u
#define FTM_FMS_FAULTF_SHIFT                     7
/* FILTER Bit Fields */
#define FTM_FILTER_CH0FVAL_MASK                  0xFu
#define FTM_FILTER_CH0FVAL_SHIFT                 0
#define FTM_FILTER_CH0FVAL(x)                    (((x)<<FTM_FILTER_CH0FVAL_SHIFT)&FTM_FILTER_CH0FVAL_MASK)
#define FTM_FILTER_CH1FVAL_MASK                  0xF0u
#define FTM_FILTER_CH1FVAL_SHIFT                 4
#define FTM_FILTER_CH1FVAL(x)                    (((x)<<FTM_FILTER_CH1FVAL_SHIFT)&FTM_FILTER_CH1FVAL_MASK)
#define FTM_FILTER_CH2FVAL_MASK                  0xF00u
#define FTM_FILTER_CH2FVAL_SHIFT                 8
#define FTM_FILTER_CH2FVAL(x)                    (((x)<<FTM_FILTER_CH2FVAL_SHIFT)&FTM_FILTER_CH2FVAL_MASK)
#define FTM_FILTER_CH3FVAL_MASK                  0xF000u
#define FTM_FILTER_CH3FVAL_SHIFT                 12
#define FTM_FILTER_CH3FVAL(x)                    (((x)<<FTM_FILTER_CH3FVAL_SHIFT)&FTM_FILTER_CH3FVAL_MASK)
/* FLTCTRL Bit Fields */
#define FTM_FLTCTRL_FAULT0EN_MASK                0x1u
#define FTM_FLTCTRL_FAULT0EN_SHIFT               0
#define FTM_FLTCTRL_FAULT1EN_MASK                0x2u
#define FTM_FLTCTRL_FAULT1EN_SHIFT               1
#define FTM_FLTCTRL_FAULT2EN_MASK                0x4u
#define FTM_FLTCTRL_FAULT2EN_SHIFT               2
#define FTM_FLTCTRL_FAULT3EN_MASK                0x8u
#define FTM_FLTCTRL_FAULT3EN_SHIFT               3
#define FTM_FLTCTRL_FFLTR0EN_MASK                0x10u
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               4
#define FTM_FLTCTRL_FFLTR1EN_MASK                0x20u
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               5
#define FTM_FLTCTRL_FFLTR2EN_MASK                0x40u
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               6
#define FTM_FLTCTRL_FFLTR3EN_MASK                0x80u
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               7
#define FTM_FLTCTRL_FFVAL_MASK                   0xF00u
#define FTM_FLTCTRL_FFVAL_SHIFT                  8
#define FTM_FLTCTRL_FFVAL(x)                     (((x)<<FTM_FLTCTRL_FFVAL_SHIFT)&FTM_FLTCTRL_FFVAL_MASK)
/* QDCTRL Bit Fields */
#define FTM_QDCTRL_QUADEN_MASK                   0x1u
#define FTM_QDCTRL_QUADEN_SHIFT                  0
#define FTM_QDCTRL_TOFDIR_MASK                   0x2u
#define FTM_QDCTRL_TOFDIR_SHIFT                  1
#define FTM_QDCTRL_QUADIR_MASK                   0x4u
#define FTM_QDCTRL_QUADIR_SHIFT                  2
#define FTM_QDCTRL_QUADMODE_MASK                 0x8u
#define FTM_QDCTRL_QUADMODE_SHIFT                3
#define FTM_QDCTRL_PHBPOL_MASK                   0x10u
#define FTM_QDCTRL_PHBPOL_SHIFT                  4
#define FTM_QDCTRL_PHAPOL_MASK                   0x20u
#define FTM_QDCTRL_PHAPOL_SHIFT                  5
#define FTM_QDCTRL_PHBFLTREN_MASK                0x40u
#define FTM_QDCTRL_PHBFLTREN_SHIFT               6
#define FTM_QDCTRL_PHAFLTREN_MASK                0x80u
#define FTM_QDCTRL_PHAFLTREN_SHIFT               7
/* CONF Bit Fields */
#define FTM_CONF_NUMTOF_MASK                     0x1Fu
#define FTM_CONF_NUMTOF_SHIFT                    0
#define FTM_CONF_NUMTOF(x)                       (((x)<<FTM_CONF_NUMTOF_SHIFT)&FTM_CONF_NUMTOF_MASK)
#define FTM_CONF_BDMMODE_MASK                    0xC0u
#define FTM_CONF_BDMMODE_SHIFT                   6
#define FTM_CONF_BDMMODE(x)                      (((x)<<FTM_CONF_BDMMODE_SHIFT)&FTM_CONF_BDMMODE_MASK)
#define FTM_CONF_GTBEEN_MASK                     0x200u
#define FTM_CONF_GTBEEN_SHIFT                    9
#define FTM_CONF_GTBEOUT_MASK                    0x400u
#define FTM_CONF_GTBEOUT_SHIFT                   10
/* FLTPOL Bit Fields */
#define FTM_FLTPOL_FLT0POL_MASK                  0x1u
#define FTM_FLTPOL_FLT0POL_SHIFT                 0
#define FTM_FLTPOL_FLT1POL_MASK                  0x2u
#define FTM_FLTPOL_FLT1POL_SHIFT                 1
#define FTM_FLTPOL_FLT2POL_MASK                  0x4u
#define FTM_FLTPOL_FLT2POL_SHIFT                 2
#define FTM_FLTPOL_FLT3POL_MASK                  0x8u
#define FTM_FLTPOL_FLT3POL_SHIFT                 3
/* SYNCONF Bit Fields */
#define FTM_SYNCONF_HWTRIGMODE_MASK              0x1u
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             0
#define FTM_SYNCONF_CNTINC_MASK                  0x4u
#define FTM_SYNCONF_CNTINC_SHIFT                 2
#define FTM_SYNCONF_INVC_MASK                    0x10u
#define FTM_SYNCONF_INVC_SHIFT                   4
#define FTM_SYNCONF_SWOC_MASK                    0x20u
#define FTM_SYNCONF_SWOC_SHIFT                   5
#define FTM_SYNCONF_SYNCMODE_MASK                0x80u
#define FTM_SYNCONF_SYNCMODE_SHIFT               7
#define FTM_SYNCONF_SWRSTCNT_MASK                0x100u
#define FTM_SYNCONF_SWRSTCNT_SHIFT               8
#define FTM_SYNCONF_SWWRBUF_MASK                 0x200u
#define FTM_SYNCONF_SWWRBUF_SHIFT                9
#define FTM_SYNCONF_SWOM_MASK                    0x400u
#define FTM_SYNCONF_SWOM_SHIFT                   10
#define FTM_SYNCONF_SWINVC_MASK                  0x800u
#define FTM_SYNCONF_SWINVC_SHIFT                 11
#define FTM_SYNCONF_SWSOC_MASK                   0x1000u
#define FTM_SYNCONF_SWSOC_SHIFT                  12
#define FTM_SYNCONF_HWRSTCNT_MASK                0x10000u
#define FTM_SYNCONF_HWRSTCNT_SHIFT               16
#define FTM_SYNCONF_HWWRBUF_MASK                 0x20000u
#define FTM_SYNCONF_HWWRBUF_SHIFT                17
#define FTM_SYNCONF_HWOM_MASK                    0x40000u
#define FTM_SYNCONF_HWOM_SHIFT                   18
#define FTM_SYNCONF_HWINVC_MASK                  0x80000u
#define FTM_SYNCONF_HWINVC_SHIFT                 19
#define FTM_SYNCONF_HWSOC_MASK                   0x100000u
#define FTM_SYNCONF_HWSOC_SHIFT                  20
/* INVCTRL Bit Fields */
#define FTM_INVCTRL_INV0EN_MASK                  0x1u
#define FTM_INVCTRL_INV0EN_SHIFT                 0
#define FTM_INVCTRL_INV1EN_MASK                  0x2u
#define FTM_INVCTRL_INV1EN_SHIFT                 1
#define FTM_INVCTRL_INV2EN_MASK                  0x4u
#define FTM_INVCTRL_INV2EN_SHIFT                 2
#define FTM_INVCTRL_INV3EN_MASK                  0x8u
#define FTM_INVCTRL_INV3EN_SHIFT                 3
/* SWOCTRL Bit Fields */
#define FTM_SWOCTRL_CH0OC_MASK                   0x1u
#define FTM_SWOCTRL_CH0OC_SHIFT                  0
#define FTM_SWOCTRL_CH1OC_MASK                   0x2u
#define FTM_SWOCTRL_CH1OC_SHIFT                  1
#define FTM_SWOCTRL_CH2OC_MASK                   0x4u
#define FTM_SWOCTRL_CH2OC_SHIFT                  2
#define FTM_SWOCTRL_CH3OC_MASK                   0x8u
#define FTM_SWOCTRL_CH3OC_SHIFT                  3
#define FTM_SWOCTRL_CH4OC_MASK                   0x10u
#define FTM_SWOCTRL_CH4OC_SHIFT                  4
#define FTM_SWOCTRL_CH5OC_MASK                   0x20u
#define FTM_SWOCTRL_CH5OC_SHIFT                  5
#define FTM_SWOCTRL_CH6OC_MASK                   0x40u
#define FTM_SWOCTRL_CH6OC_SHIFT                  6
#define FTM_SWOCTRL_CH7OC_MASK                   0x80u
#define FTM_SWOCTRL_CH7OC_SHIFT                  7
#define FTM_SWOCTRL_CH0OCV_MASK                  0x100u
#define FTM_SWOCTRL_CH0OCV_SHIFT                 8
#define FTM_SWOCTRL_CH1OCV_MASK                  0x200u
#define FTM_SWOCTRL_CH1OCV_SHIFT                 9
#define FTM_SWOCTRL_CH2OCV_MASK                  0x400u
#define FTM_SWOCTRL_CH2OCV_SHIFT                 10
#define FTM_SWOCTRL_CH3OCV_MASK                  0x800u
#define FTM_SWOCTRL_CH3OCV_SHIFT                 11
#define FTM_SWOCTRL_CH4OCV_MASK                  0x1000u
#define FTM_SWOCTRL_CH4OCV_SHIFT                 12
#define FTM_SWOCTRL_CH5OCV_MASK                  0x2000u
#define FTM_SWOCTRL_CH5OCV_SHIFT                 13
#define FTM_SWOCTRL_CH6OCV_MASK                  0x4000u
#define FTM_SWOCTRL_CH6OCV_SHIFT                 14
#define FTM_SWOCTRL_CH7OCV_MASK                  0x8000u
#define FTM_SWOCTRL_CH7OCV_SHIFT                 15
/* PWMLOAD Bit Fields */
#define FTM_PWMLOAD_CH0SEL_MASK                  0x1u
#define FTM_PWMLOAD_CH0SEL_SHIFT                 0
#define FTM_PWMLOAD_CH1SEL_MASK                  0x2u
#define FTM_PWMLOAD_CH1SEL_SHIFT                 1
#define FTM_PWMLOAD_CH2SEL_MASK                  0x4u
#define FTM_PWMLOAD_CH2SEL_SHIFT                 2
#define FTM_PWMLOAD_CH3SEL_MASK                  0x8u
#define FTM_PWMLOAD_CH3SEL_SHIFT                 3
#define FTM_PWMLOAD_CH4SEL_MASK                  0x10u
#define FTM_PWMLOAD_CH4SEL_SHIFT                 4
#define FTM_PWMLOAD_CH5SEL_MASK                  0x20u
#define FTM_PWMLOAD_CH5SEL_SHIFT                 5
#define FTM_PWMLOAD_CH6SEL_MASK                  0x40u
#define FTM_PWMLOAD_CH6SEL_SHIFT                 6
#define FTM_PWMLOAD_CH7SEL_MASK                  0x80u
#define FTM_PWMLOAD_CH7SEL_SHIFT                 7
#define FTM_PWMLOAD_LDOK_MASK                    0x200u
#define FTM_PWMLOAD_LDOK_SHIFT                   9

/*! \} */ /* end of group FTM_Register_Masks */


/* FTM - Peripheral instance base addresses */
/*! Peripheral FTM0 base pointer */
#define FTM0_BASE_PTR                            ((FTM_MemMapPtr)0x40038000u)
/*! Peripheral FTM1 base pointer */
#define FTM1_BASE_PTR                            ((FTM_MemMapPtr)0x40039000u)
/*! Peripheral FTM2 base pointer */
#define FTM2_BASE_PTR                            ((FTM_MemMapPtr)0x400B8000u)

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros */
/*! \{ */


/* FTM - Register instance definitions */
/* FTM0 */
#define FTM0_SC                                  FTM_SC_REG(FTM0_BASE_PTR)
#define FTM0_CNT                                 FTM_CNT_REG(FTM0_BASE_PTR)
#define FTM0_MOD                                 FTM_MOD_REG(FTM0_BASE_PTR)
#define FTM0_C0SC                                FTM_CnSC_REG(FTM0_BASE_PTR,0)
#define FTM0_C0V                                 FTM_CnV_REG(FTM0_BASE_PTR,0)
#define FTM0_C1SC                                FTM_CnSC_REG(FTM0_BASE_PTR,1)
#define FTM0_C1V                                 FTM_CnV_REG(FTM0_BASE_PTR,1)
#define FTM0_C2SC                                FTM_CnSC_REG(FTM0_BASE_PTR,2)
#define FTM0_C2V                                 FTM_CnV_REG(FTM0_BASE_PTR,2)
#define FTM0_C3SC                                FTM_CnSC_REG(FTM0_BASE_PTR,3)
#define FTM0_C3V                                 FTM_CnV_REG(FTM0_BASE_PTR,3)
#define FTM0_C4SC                                FTM_CnSC_REG(FTM0_BASE_PTR,4)
#define FTM0_C4V                                 FTM_CnV_REG(FTM0_BASE_PTR,4)
#define FTM0_C5SC                                FTM_CnSC_REG(FTM0_BASE_PTR,5)
#define FTM0_C5V                                 FTM_CnV_REG(FTM0_BASE_PTR,5)
#define FTM0_C6SC                                FTM_CnSC_REG(FTM0_BASE_PTR,6)
#define FTM0_C6V                                 FTM_CnV_REG(FTM0_BASE_PTR,6)
#define FTM0_C7SC                                FTM_CnSC_REG(FTM0_BASE_PTR,7)
#define FTM0_C7V                                 FTM_CnV_REG(FTM0_BASE_PTR,7)
#define FTM0_CNTIN                               FTM_CNTIN_REG(FTM0_BASE_PTR)
#define FTM0_STATUS                              FTM_STATUS_REG(FTM0_BASE_PTR)
#define FTM0_MODE                                FTM_MODE_REG(FTM0_BASE_PTR)
#define FTM0_SYNC                                FTM_SYNC_REG(FTM0_BASE_PTR)
#define FTM0_OUTINIT                             FTM_OUTINIT_REG(FTM0_BASE_PTR)
#define FTM0_OUTMASK                             FTM_OUTMASK_REG(FTM0_BASE_PTR)
#define FTM0_COMBINE                             FTM_COMBINE_REG(FTM0_BASE_PTR)
#define FTM0_DEADTIME                            FTM_DEADTIME_REG(FTM0_BASE_PTR)
#define FTM0_EXTTRIG                             FTM_EXTTRIG_REG(FTM0_BASE_PTR)
#define FTM0_POL                                 FTM_POL_REG(FTM0_BASE_PTR)
#define FTM0_FMS                                 FTM_FMS_REG(FTM0_BASE_PTR)
#define FTM0_FILTER                              FTM_FILTER_REG(FTM0_BASE_PTR)
#define FTM0_FLTCTRL                             FTM_FLTCTRL_REG(FTM0_BASE_PTR)
#define FTM0_QDCTRL                              FTM_QDCTRL_REG(FTM0_BASE_PTR)
#define FTM0_CONF                                FTM_CONF_REG(FTM0_BASE_PTR)
#define FTM0_FLTPOL                              FTM_FLTPOL_REG(FTM0_BASE_PTR)
#define FTM0_SYNCONF                             FTM_SYNCONF_REG(FTM0_BASE_PTR)
#define FTM0_INVCTRL                             FTM_INVCTRL_REG(FTM0_BASE_PTR)
#define FTM0_SWOCTRL                             FTM_SWOCTRL_REG(FTM0_BASE_PTR)
#define FTM0_PWMLOAD                             FTM_PWMLOAD_REG(FTM0_BASE_PTR)
/* FTM1 */
#define FTM1_SC                                  FTM_SC_REG(FTM1_BASE_PTR)
#define FTM1_CNT                                 FTM_CNT_REG(FTM1_BASE_PTR)
#define FTM1_MOD                                 FTM_MOD_REG(FTM1_BASE_PTR)
#define FTM1_C0SC                                FTM_CnSC_REG(FTM1_BASE_PTR,0)
#define FTM1_C0V                                 FTM_CnV_REG(FTM1_BASE_PTR,0)
#define FTM1_C1SC                                FTM_CnSC_REG(FTM1_BASE_PTR,1)
#define FTM1_C1V                                 FTM_CnV_REG(FTM1_BASE_PTR,1)
#define FTM1_CNTIN                               FTM_CNTIN_REG(FTM1_BASE_PTR)
#define FTM1_STATUS                              FTM_STATUS_REG(FTM1_BASE_PTR)
#define FTM1_MODE                                FTM_MODE_REG(FTM1_BASE_PTR)
#define FTM1_SYNC                                FTM_SYNC_REG(FTM1_BASE_PTR)
#define FTM1_OUTINIT                             FTM_OUTINIT_REG(FTM1_BASE_PTR)
#define FTM1_OUTMASK                             FTM_OUTMASK_REG(FTM1_BASE_PTR)
#define FTM1_COMBINE                             FTM_COMBINE_REG(FTM1_BASE_PTR)
#define FTM1_DEADTIME                            FTM_DEADTIME_REG(FTM1_BASE_PTR)
#define FTM1_EXTTRIG                             FTM_EXTTRIG_REG(FTM1_BASE_PTR)
#define FTM1_POL                                 FTM_POL_REG(FTM1_BASE_PTR)
#define FTM1_FMS                                 FTM_FMS_REG(FTM1_BASE_PTR)
#define FTM1_FILTER                              FTM_FILTER_REG(FTM1_BASE_PTR)
#define FTM1_FLTCTRL                             FTM_FLTCTRL_REG(FTM1_BASE_PTR)
#define FTM1_QDCTRL                              FTM_QDCTRL_REG(FTM1_BASE_PTR)
#define FTM1_CONF                                FTM_CONF_REG(FTM1_BASE_PTR)
#define FTM1_FLTPOL                              FTM_FLTPOL_REG(FTM1_BASE_PTR)
#define FTM1_SYNCONF                             FTM_SYNCONF_REG(FTM1_BASE_PTR)
#define FTM1_INVCTRL                             FTM_INVCTRL_REG(FTM1_BASE_PTR)
#define FTM1_SWOCTRL                             FTM_SWOCTRL_REG(FTM1_BASE_PTR)
#define FTM1_PWMLOAD                             FTM_PWMLOAD_REG(FTM1_BASE_PTR)
/* FTM2 */
#define FTM2_SC                                  FTM_SC_REG(FTM2_BASE_PTR)
#define FTM2_CNT                                 FTM_CNT_REG(FTM2_BASE_PTR)
#define FTM2_MOD                                 FTM_MOD_REG(FTM2_BASE_PTR)
#define FTM2_C0SC                                FTM_CnSC_REG(FTM2_BASE_PTR,0)
#define FTM2_C0V                                 FTM_CnV_REG(FTM2_BASE_PTR,0)
#define FTM2_C1SC                                FTM_CnSC_REG(FTM2_BASE_PTR,1)
#define FTM2_C1V                                 FTM_CnV_REG(FTM2_BASE_PTR,1)
#define FTM2_CNTIN                               FTM_CNTIN_REG(FTM2_BASE_PTR)
#define FTM2_STATUS                              FTM_STATUS_REG(FTM2_BASE_PTR)
#define FTM2_MODE                                FTM_MODE_REG(FTM2_BASE_PTR)
#define FTM2_SYNC                                FTM_SYNC_REG(FTM2_BASE_PTR)
#define FTM2_OUTINIT                             FTM_OUTINIT_REG(FTM2_BASE_PTR)
#define FTM2_OUTMASK                             FTM_OUTMASK_REG(FTM2_BASE_PTR)
#define FTM2_COMBINE                             FTM_COMBINE_REG(FTM2_BASE_PTR)
#define FTM2_DEADTIME                            FTM_DEADTIME_REG(FTM2_BASE_PTR)
#define FTM2_EXTTRIG                             FTM_EXTTRIG_REG(FTM2_BASE_PTR)
#define FTM2_POL                                 FTM_POL_REG(FTM2_BASE_PTR)
#define FTM2_FMS                                 FTM_FMS_REG(FTM2_BASE_PTR)
#define FTM2_FILTER                              FTM_FILTER_REG(FTM2_BASE_PTR)
#define FTM2_FLTCTRL                             FTM_FLTCTRL_REG(FTM2_BASE_PTR)
#define FTM2_QDCTRL                              FTM_QDCTRL_REG(FTM2_BASE_PTR)
#define FTM2_CONF                                FTM_CONF_REG(FTM2_BASE_PTR)
#define FTM2_FLTPOL                              FTM_FLTPOL_REG(FTM2_BASE_PTR)
#define FTM2_SYNCONF                             FTM_SYNCONF_REG(FTM2_BASE_PTR)
#define FTM2_INVCTRL                             FTM_INVCTRL_REG(FTM2_BASE_PTR)
#define FTM2_SWOCTRL                             FTM_SWOCTRL_REG(FTM2_BASE_PTR)
#define FTM2_PWMLOAD                             FTM_PWMLOAD_REG(FTM2_BASE_PTR)

/*! \} */ /* end of group FTM_Register_Accessor_Macros */


/*! \} */ /* end of group FTM_Peripheral */


/* ----------------------------------------------------------------------------
   -- CMP
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMP_Peripheral CMP */
/*! \{ */

/*! CMP - Peripheral register structure */
typedef struct CMP_MemMap {
  uint8_t CR0;                                     /*!< CMP Control Register 0, offset: 0x0 */
  uint8_t CR1;                                     /*!< CMP Control Register 1, offset: 0x1 */
  uint8_t FPR;                                     /*!< CMP Filter Period Register, offset: 0x2 */
  uint8_t SCR;                                     /*!< CMP Status and Control Register, offset: 0x3 */
  uint8_t DACCR;                                   /*!< DAC Control Register, offset: 0x4 */
  uint8_t MUXCR;                                   /*!< MUX Control Register, offset: 0x5 */
} volatile *CMP_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros */
/*! \{ */


/* CMP - Register accessors */
#define CMP_CR0_REG(base)                        ((base)->CR0)
#define CMP_CR1_REG(base)                        ((base)->CR1)
#define CMP_FPR_REG(base)                        ((base)->FPR)
#define CMP_SCR_REG(base)                        ((base)->SCR)
#define CMP_DACCR_REG(base)                      ((base)->DACCR)
#define CMP_MUXCR_REG(base)                      ((base)->MUXCR)

/*! \} */ /* end of group CMP_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CMP Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMP_Register_Masks CMP Register Masks */
/*! \{ */

/* CR0 Bit Fields */
#define CMP_CR0_HYSTCTR_MASK                     0x3u
#define CMP_CR0_HYSTCTR_SHIFT                    0
#define CMP_CR0_HYSTCTR(x)                       (((x)<<CMP_CR0_HYSTCTR_SHIFT)&CMP_CR0_HYSTCTR_MASK)
#define CMP_CR0_FILTER_CNT_MASK                  0x70u
#define CMP_CR0_FILTER_CNT_SHIFT                 4
#define CMP_CR0_FILTER_CNT(x)                    (((x)<<CMP_CR0_FILTER_CNT_SHIFT)&CMP_CR0_FILTER_CNT_MASK)
/* CR1 Bit Fields */
#define CMP_CR1_EN_MASK                          0x1u
#define CMP_CR1_EN_SHIFT                         0
#define CMP_CR1_OPE_MASK                         0x2u
#define CMP_CR1_OPE_SHIFT                        1
#define CMP_CR1_COS_MASK                         0x4u
#define CMP_CR1_COS_SHIFT                        2
#define CMP_CR1_INV_MASK                         0x8u
#define CMP_CR1_INV_SHIFT                        3
#define CMP_CR1_PMODE_MASK                       0x10u
#define CMP_CR1_PMODE_SHIFT                      4
#define CMP_CR1_WE_MASK                          0x40u
#define CMP_CR1_WE_SHIFT                         6
#define CMP_CR1_SE_MASK                          0x80u
#define CMP_CR1_SE_SHIFT                         7
/* FPR Bit Fields */
#define CMP_FPR_FILT_PER_MASK                    0xFFu
#define CMP_FPR_FILT_PER_SHIFT                   0
#define CMP_FPR_FILT_PER(x)                      (((x)<<CMP_FPR_FILT_PER_SHIFT)&CMP_FPR_FILT_PER_MASK)
/* SCR Bit Fields */
#define CMP_SCR_COUT_MASK                        0x1u
#define CMP_SCR_COUT_SHIFT                       0
#define CMP_SCR_CFF_MASK                         0x2u
#define CMP_SCR_CFF_SHIFT                        1
#define CMP_SCR_CFR_MASK                         0x4u
#define CMP_SCR_CFR_SHIFT                        2
#define CMP_SCR_IEF_MASK                         0x8u
#define CMP_SCR_IEF_SHIFT                        3
#define CMP_SCR_IER_MASK                         0x10u
#define CMP_SCR_IER_SHIFT                        4
#define CMP_SCR_SMELB_MASK                       0x20u
#define CMP_SCR_SMELB_SHIFT                      5
#define CMP_SCR_DMAEN_MASK                       0x40u
#define CMP_SCR_DMAEN_SHIFT                      6
/* DACCR Bit Fields */
#define CMP_DACCR_VOSEL_MASK                     0x3Fu
#define CMP_DACCR_VOSEL_SHIFT                    0
#define CMP_DACCR_VOSEL(x)                       (((x)<<CMP_DACCR_VOSEL_SHIFT)&CMP_DACCR_VOSEL_MASK)
#define CMP_DACCR_VRSEL_MASK                     0x40u
#define CMP_DACCR_VRSEL_SHIFT                    6
#define CMP_DACCR_DACEN_MASK                     0x80u
#define CMP_DACCR_DACEN_SHIFT                    7
/* MUXCR Bit Fields */
#define CMP_MUXCR_MSEL_MASK                      0x7u
#define CMP_MUXCR_MSEL_SHIFT                     0
#define CMP_MUXCR_MSEL(x)                        (((x)<<CMP_MUXCR_MSEL_SHIFT)&CMP_MUXCR_MSEL_MASK)
#define CMP_MUXCR_PSEL_MASK                      0x38u
#define CMP_MUXCR_PSEL_SHIFT                     3
#define CMP_MUXCR_PSEL(x)                        (((x)<<CMP_MUXCR_PSEL_SHIFT)&CMP_MUXCR_PSEL_MASK)
#define CMP_MUXCR_MEN_MASK                       0x40u
#define CMP_MUXCR_MEN_SHIFT                      6
#define CMP_MUXCR_PEN_MASK                       0x80u
#define CMP_MUXCR_PEN_SHIFT                      7

/*! \} */ /* end of group CMP_Register_Masks */


/* CMP - Peripheral instance base addresses */
/*! Peripheral HSCMP0 base pointer */
#define HSCMP0_BASE_PTR                          ((CMP_MemMapPtr)0x40073000u)
/*! Peripheral HSCMP1 base pointer */
#define HSCMP1_BASE_PTR                          ((CMP_MemMapPtr)0x40073008u)
/*! Peripheral HSCMP2 base pointer */
#define HSCMP2_BASE_PTR                          ((CMP_MemMapPtr)0x40073010u)

/* ----------------------------------------------------------------------------
   -- CMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup CMP_Register_Accessor_Macros CMP - Register accessor macros */
/*! \{ */


/* CMP - Register instance definitions */
/* HSCMP0 */
#define CMP0_CR0                                 CMP_CR0_REG(HSCMP0_BASE_PTR)
#define CMP0_CR1                                 CMP_CR1_REG(HSCMP0_BASE_PTR)
#define CMP0_FPR                                 CMP_FPR_REG(HSCMP0_BASE_PTR)
#define CMP0_SCR                                 CMP_SCR_REG(HSCMP0_BASE_PTR)
#define CMP0_DACCR                               CMP_DACCR_REG(HSCMP0_BASE_PTR)
#define CMP0_MUXCR                               CMP_MUXCR_REG(HSCMP0_BASE_PTR)
/* HSCMP1 */
#define CMP1_CR0                                 CMP_CR0_REG(HSCMP1_BASE_PTR)
#define CMP1_CR1                                 CMP_CR1_REG(HSCMP1_BASE_PTR)
#define CMP1_FPR                                 CMP_FPR_REG(HSCMP1_BASE_PTR)
#define CMP1_SCR                                 CMP_SCR_REG(HSCMP1_BASE_PTR)
#define CMP1_DACCR                               CMP_DACCR_REG(HSCMP1_BASE_PTR)
#define CMP1_MUXCR                               CMP_MUXCR_REG(HSCMP1_BASE_PTR)
/* HSCMP2 */
#define CMP2_CR0                                 CMP_CR0_REG(HSCMP2_BASE_PTR)
#define CMP2_CR1                                 CMP_CR1_REG(HSCMP2_BASE_PTR)
#define CMP2_FPR                                 CMP_FPR_REG(HSCMP2_BASE_PTR)
#define CMP2_SCR                                 CMP_SCR_REG(HSCMP2_BASE_PTR)
#define CMP2_DACCR                               CMP_DACCR_REG(HSCMP2_BASE_PTR)
#define CMP2_MUXCR                               CMP_MUXCR_REG(HSCMP2_BASE_PTR)

/*! \} */ /* end of group CMP_Register_Accessor_Macros */


/*! \} */ /* end of group CMP_Peripheral */


/* ----------------------------------------------------------------------------
   -- I2C
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2C_Peripheral I2C */
/*! \{ */

/*! I2C - Peripheral register structure */
typedef struct I2C_MemMap {
  uint8_t A1;                                      /*!< IIC address register 1, offset: 0x0 */
  uint8_t F;                                       /*!< IIC frequency divider register, offset: 0x1 */
  uint8_t C1;                                      /*!< IIC control register 1, offset: 0x2 */
  uint8_t S;                                       /*!< IIC status register, offset: 0x3 */
  uint8_t D;                                       /*!< IIC data I/O register, offset: 0x4 */
  uint8_t C2;                                      /*!< IIC control register 2, offset: 0x5 */
  uint8_t FLT;                                     /*!< IIC programmable input glitch filter, offset: 0x6 */
  uint8_t RA;                                      /*!< IIC range address register, offset: 0x7 */
  uint8_t SMB;                                     /*!< IIC SMBus control and status register, offset: 0x8 */
  uint8_t A2;                                      /*!< IIC address register 2, offset: 0x9 */
  uint8_t SLTH;                                    /*!< IIC SCL low timeout register high, offset: 0xA */
  uint8_t SLTL;                                    /*!< IIC SCL low timeout register low, offset: 0xB */
} volatile *I2C_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros */
/*! \{ */


/* I2C - Register accessors */
#define I2C_A1_REG(base)                         ((base)->A1)
#define I2C_F_REG(base)                          ((base)->F)
#define I2C_C1_REG(base)                         ((base)->C1)
#define I2C_S_REG(base)                          ((base)->S)
#define I2C_D_REG(base)                          ((base)->D)
#define I2C_C2_REG(base)                         ((base)->C2)
#define I2C_FLT_REG(base)                        ((base)->FLT)
#define I2C_RA_REG(base)                         ((base)->RA)
#define I2C_SMB_REG(base)                        ((base)->SMB)
#define I2C_A2_REG(base)                         ((base)->A2)
#define I2C_SLTH_REG(base)                       ((base)->SLTH)
#define I2C_SLTL_REG(base)                       ((base)->SLTL)

/*! \} */ /* end of group I2C_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2C_Register_Masks I2C Register Masks */
/*! \{ */

/* A1 Bit Fields */
#define I2C_A1_AD_MASK                           0xFEu
#define I2C_A1_AD_SHIFT                          1
#define I2C_A1_AD(x)                             (((x)<<I2C_A1_AD_SHIFT)&I2C_A1_AD_MASK)
/* F Bit Fields */
#define I2C_F_ICR_MASK                           0x3Fu
#define I2C_F_ICR_SHIFT                          0
#define I2C_F_ICR(x)                             (((x)<<I2C_F_ICR_SHIFT)&I2C_F_ICR_MASK)
#define I2C_F_MULT_MASK                          0xC0u
#define I2C_F_MULT_SHIFT                         6
#define I2C_F_MULT(x)                            (((x)<<I2C_F_MULT_SHIFT)&I2C_F_MULT_MASK)
/* C1 Bit Fields */
#define I2C_C1_DMAEN_MASK                        0x1u
#define I2C_C1_DMAEN_SHIFT                       0
#define I2C_C1_WUEN_MASK                         0x2u
#define I2C_C1_WUEN_SHIFT                        1
#define I2C_C1_RSTA_MASK                         0x4u
#define I2C_C1_RSTA_SHIFT                        2
#define I2C_C1_TXAK_MASK                         0x8u
#define I2C_C1_TXAK_SHIFT                        3
#define I2C_C1_TX_MASK                           0x10u
#define I2C_C1_TX_SHIFT                          4
#define I2C_C1_MST_MASK                          0x20u
#define I2C_C1_MST_SHIFT                         5
#define I2C_C1_IICIE_MASK                        0x40u
#define I2C_C1_IICIE_SHIFT                       6
#define I2C_C1_IICEN_MASK                        0x80u
#define I2C_C1_IICEN_SHIFT                       7
/* S Bit Fields */
#define I2C_S_RXAK_MASK                          0x1u
#define I2C_S_RXAK_SHIFT                         0
#define I2C_S_IICIF_MASK                         0x2u
#define I2C_S_IICIF_SHIFT                        1
#define I2C_S_SRW_MASK                           0x4u
#define I2C_S_SRW_SHIFT                          2
#define I2C_S_RAM_MASK                           0x8u
#define I2C_S_RAM_SHIFT                          3
#define I2C_S_ARBL_MASK                          0x10u
#define I2C_S_ARBL_SHIFT                         4
#define I2C_S_BUSY_MASK                          0x20u
#define I2C_S_BUSY_SHIFT                         5
#define I2C_S_IAAS_MASK                          0x40u
#define I2C_S_IAAS_SHIFT                         6
#define I2C_S_TCF_MASK                           0x80u
#define I2C_S_TCF_SHIFT                          7
/* D Bit Fields */
#define I2C_D_DATA_MASK                          0xFFu
#define I2C_D_DATA_SHIFT                         0
#define I2C_D_DATA(x)                            (((x)<<I2C_D_DATA_SHIFT)&I2C_D_DATA_MASK)
/* C2 Bit Fields */
#define I2C_C2_AD_MASK                           0x7u
#define I2C_C2_AD_SHIFT                          0
#define I2C_C2_AD(x)                             (((x)<<I2C_C2_AD_SHIFT)&I2C_C2_AD_MASK)
#define I2C_C2_RMEN_MASK                         0x8u
#define I2C_C2_RMEN_SHIFT                        3
#define I2C_C2_SBRC_MASK                         0x10u
#define I2C_C2_SBRC_SHIFT                        4
#define I2C_C2_HDRS_MASK                         0x20u
#define I2C_C2_HDRS_SHIFT                        5
#define I2C_C2_ADEXT_MASK                        0x40u
#define I2C_C2_ADEXT_SHIFT                       6
#define I2C_C2_GCAEN_MASK                        0x80u
#define I2C_C2_GCAEN_SHIFT                       7
/* FLT Bit Fields */
#define I2C_FLT_FLT_MASK                         0x1Fu
#define I2C_FLT_FLT_SHIFT                        0
#define I2C_FLT_FLT(x)                           (((x)<<I2C_FLT_FLT_SHIFT)&I2C_FLT_FLT_MASK)
/* RA Bit Fields */
#define I2C_RA_RAD_MASK                          0xFEu
#define I2C_RA_RAD_SHIFT                         1
#define I2C_RA_RAD(x)                            (((x)<<I2C_RA_RAD_SHIFT)&I2C_RA_RAD_MASK)
/* SMB Bit Fields */
#define I2C_SMB_SHTF2IE_MASK                     0x1u
#define I2C_SMB_SHTF2IE_SHIFT                    0
#define I2C_SMB_SHTF2_MASK                       0x2u
#define I2C_SMB_SHTF2_SHIFT                      1
#define I2C_SMB_SHTF1_MASK                       0x4u
#define I2C_SMB_SHTF1_SHIFT                      2
#define I2C_SMB_SLTF_MASK                        0x8u
#define I2C_SMB_SLTF_SHIFT                       3
#define I2C_SMB_TCKSEL_MASK                      0x10u
#define I2C_SMB_TCKSEL_SHIFT                     4
#define I2C_SMB_SIICAEN_MASK                     0x20u
#define I2C_SMB_SIICAEN_SHIFT                    5
#define I2C_SMB_ALERTEN_MASK                     0x40u
#define I2C_SMB_ALERTEN_SHIFT                    6
#define I2C_SMB_FACK_MASK                        0x80u
#define I2C_SMB_FACK_SHIFT                       7
/* A2 Bit Fields */
#define I2C_A2_SAD_MASK                          0xFEu
#define I2C_A2_SAD_SHIFT                         1
#define I2C_A2_SAD(x)                            (((x)<<I2C_A2_SAD_SHIFT)&I2C_A2_SAD_MASK)
/* SLTH Bit Fields */
#define I2C_SLTH_SSLT_MASK                       0xFFu
#define I2C_SLTH_SSLT_SHIFT                      0
#define I2C_SLTH_SSLT(x)                         (((x)<<I2C_SLTH_SSLT_SHIFT)&I2C_SLTH_SSLT_MASK)
/* SLTL Bit Fields */
#define I2C_SLTL_SSLT_MASK                       0xFFu
#define I2C_SLTL_SSLT_SHIFT                      0
#define I2C_SLTL_SSLT(x)                         (((x)<<I2C_SLTL_SSLT_SHIFT)&I2C_SLTL_SSLT_MASK)

/*! \} */ /* end of group I2C_Register_Masks */


/* I2C - Peripheral instance base addresses */
/*! Peripheral I2C0 base pointer */
#define I2C0_BASE_PTR                            ((I2C_MemMapPtr)0x40066000u)
/*! Peripheral I2C1 base pointer */
#define I2C1_BASE_PTR                            ((I2C_MemMapPtr)0x40067000u)

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros */
/*! \{ */


/* I2C - Register instance definitions */
/* I2C0 */
#define I2C0_A1                                  I2C_A1_REG(I2C0_BASE_PTR)
#define I2C0_F                                   I2C_F_REG(I2C0_BASE_PTR)
#define I2C0_C1                                  I2C_C1_REG(I2C0_BASE_PTR)
#define I2C0_S                                   I2C_S_REG(I2C0_BASE_PTR)
#define I2C0_D                                   I2C_D_REG(I2C0_BASE_PTR)
#define I2C0_C2                                  I2C_C2_REG(I2C0_BASE_PTR)
#define I2C0_FLT                                 I2C_FLT_REG(I2C0_BASE_PTR)
#define I2C0_RA                                  I2C_RA_REG(I2C0_BASE_PTR)
#define I2C0_SMB                                 I2C_SMB_REG(I2C0_BASE_PTR)
#define I2C0_A2                                  I2C_A2_REG(I2C0_BASE_PTR)
#define I2C0_SLTH                                I2C_SLTH_REG(I2C0_BASE_PTR)
#define I2C0_SLTL                                I2C_SLTL_REG(I2C0_BASE_PTR)
/* I2C1 */
#define I2C1_A1                                  I2C_A1_REG(I2C1_BASE_PTR)
#define I2C1_F                                   I2C_F_REG(I2C1_BASE_PTR)
#define I2C1_C1                                  I2C_C1_REG(I2C1_BASE_PTR)
#define I2C1_S                                   I2C_S_REG(I2C1_BASE_PTR)
#define I2C1_D                                   I2C_D_REG(I2C1_BASE_PTR)
#define I2C1_C2                                  I2C_C2_REG(I2C1_BASE_PTR)
#define I2C1_FLT                                 I2C_FLT_REG(I2C1_BASE_PTR)
#define I2C1_RA                                  I2C_RA_REG(I2C1_BASE_PTR)
#define I2C1_SMB                                 I2C_SMB_REG(I2C1_BASE_PTR)
#define I2C1_A2                                  I2C_A2_REG(I2C1_BASE_PTR)
#define I2C1_SLTH                                I2C_SLTH_REG(I2C1_BASE_PTR)
#define I2C1_SLTL                                I2C_SLTL_REG(I2C1_BASE_PTR)

/*! \} */ /* end of group I2C_Register_Accessor_Macros */


/*! \} */ /* end of group I2C_Peripheral */


/* ----------------------------------------------------------------------------
   -- I2S
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2S_Peripheral I2S */
/*! \{ */

/*! I2S - Peripheral register structure */
typedef struct I2S_MemMap {
  uint32_t TX0;                                    /*!< I2S Transmit Data Registers 0, offset: 0x0 */
  uint32_t TX1;                                    /*!< I2S Transmit Data Registers 1, offset: 0x4 */
  uint32_t RX0;                                    /*!< I2S Receive Data Registers 0, offset: 0x8 */
  uint32_t RX1;                                    /*!< I2S Receive Data Registers 1, offset: 0xC */
  uint32_t CR;                                     /*!< I2S Control Register, offset: 0x10 */
  uint32_t ISR;                                    /*!< I2S Interrupt Status Register, offset: 0x14 */
  uint32_t IER;                                    /*!< I2S Interrupt Enable Register, offset: 0x18 */
  uint32_t TCR;                                    /*!< I2S Transmit Configuration Register, offset: 0x1C */
  uint32_t RCR;                                    /*!< I2S Receive Configuration Register, offset: 0x20 */
  uint32_t TCCR;                                   /*!< I2S Transmit Clock Control Registers, offset: 0x24 */
  uint32_t RCCR;                                   /*!< I2S Receive Clock Control Registers, offset: 0x28 */
  uint32_t FCSR;                                   /*!< I2S FIFO Control/Status Register, offset: 0x2C */
  uint8_t RESERVED_0[8];
  uint32_t ACNT;                                   /*!< I2S AC97 Control Register, offset: 0x38 */
  uint32_t ACADD;                                  /*!< I2S AC97 Command Address Register, offset: 0x3C */
  uint32_t ACDAT;                                  /*!< I2S AC97 Command Data Register, offset: 0x40 */
  uint32_t ATAG;                                   /*!< I2S AC97 Tag Register, offset: 0x44 */
  uint32_t TMSK;                                   /*!< I2S Transmit Time Slot Mask Register, offset: 0x48 */
  uint32_t RMSK;                                   /*!< I2S Receive Time Slot Mask Register, offset: 0x4C */
  uint32_t ACCST;                                  /*!< I2S AC97 Channel Status Register, offset: 0x50 */
  uint32_t ACCEN;                                  /*!< I2S AC97 Channel Enable Register, offset: 0x54 */
  uint32_t ACCDIS;                                 /*!< I2S AC97 Channel Disable Register, offset: 0x58 */
} volatile *I2S_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2S - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2S_Register_Accessor_Macros I2S - Register accessor macros */
/*! \{ */


/* I2S - Register accessors */
#define I2S_TX0_REG(base)                        ((base)->TX0)
#define I2S_TX1_REG(base)                        ((base)->TX1)
#define I2S_RX0_REG(base)                        ((base)->RX0)
#define I2S_RX1_REG(base)                        ((base)->RX1)
#define I2S_CR_REG(base)                         ((base)->CR)
#define I2S_ISR_REG(base)                        ((base)->ISR)
#define I2S_IER_REG(base)                        ((base)->IER)
#define I2S_TCR_REG(base)                        ((base)->TCR)
#define I2S_RCR_REG(base)                        ((base)->RCR)
#define I2S_TCCR_REG(base)                       ((base)->TCCR)
#define I2S_RCCR_REG(base)                       ((base)->RCCR)
#define I2S_FCSR_REG(base)                       ((base)->FCSR)
#define I2S_ACNT_REG(base)                       ((base)->ACNT)
#define I2S_ACADD_REG(base)                      ((base)->ACADD)
#define I2S_ACDAT_REG(base)                      ((base)->ACDAT)
#define I2S_ATAG_REG(base)                       ((base)->ATAG)
#define I2S_TMSK_REG(base)                       ((base)->TMSK)
#define I2S_RMSK_REG(base)                       ((base)->RMSK)
#define I2S_ACCST_REG(base)                      ((base)->ACCST)
#define I2S_ACCEN_REG(base)                      ((base)->ACCEN)
#define I2S_ACCDIS_REG(base)                     ((base)->ACCDIS)

/*! \} */ /* end of group I2S_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2S Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2S_Register_Masks I2S Register Masks */
/*! \{ */

/* TX0 Bit Fields */
#define I2S_TX0_TX0_MASK                         0xFFFFFFFFu
#define I2S_TX0_TX0_SHIFT                        0
#define I2S_TX0_TX0(x)                           (((x)<<I2S_TX0_TX0_SHIFT)&I2S_TX0_TX0_MASK)
/* TX1 Bit Fields */
#define I2S_TX1_TX1_MASK                         0xFFFFFFFFu
#define I2S_TX1_TX1_SHIFT                        0
#define I2S_TX1_TX1(x)                           (((x)<<I2S_TX1_TX1_SHIFT)&I2S_TX1_TX1_MASK)
/* RX0 Bit Fields */
#define I2S_RX0_RX0_MASK                         0xFFFFFFFFu
#define I2S_RX0_RX0_SHIFT                        0
#define I2S_RX0_RX0(x)                           (((x)<<I2S_RX0_RX0_SHIFT)&I2S_RX0_RX0_MASK)
/* RX1 Bit Fields */
#define I2S_RX1_RX1_MASK                         0xFFFFFFFFu
#define I2S_RX1_RX1_SHIFT                        0
#define I2S_RX1_RX1(x)                           (((x)<<I2S_RX1_RX1_SHIFT)&I2S_RX1_RX1_MASK)
/* CR Bit Fields */
#define I2S_CR_SSIEN_MASK                        0x1u
#define I2S_CR_SSIEN_SHIFT                       0
#define I2S_CR_TE_MASK                           0x2u
#define I2S_CR_TE_SHIFT                          1
#define I2S_CR_RE_MASK                           0x4u
#define I2S_CR_RE_SHIFT                          2
#define I2S_CR_NET_MASK                          0x8u
#define I2S_CR_NET_SHIFT                         3
#define I2S_CR_SYN_MASK                          0x10u
#define I2S_CR_SYN_SHIFT                         4
#define I2S_CR_I2SMODE_MASK                      0x60u
#define I2S_CR_I2SMODE_SHIFT                     5
#define I2S_CR_I2SMODE(x)                        (((x)<<I2S_CR_I2SMODE_SHIFT)&I2S_CR_I2SMODE_MASK)
#define I2S_CR_SYSCLKEN_MASK                     0x80u
#define I2S_CR_SYSCLKEN_SHIFT                    7
#define I2S_CR_TCHEN_MASK                        0x100u
#define I2S_CR_TCHEN_SHIFT                       8
#define I2S_CR_CLKIST_MASK                       0x200u
#define I2S_CR_CLKIST_SHIFT                      9
#define I2S_CR_TFRCLKDIS_MASK                    0x400u
#define I2S_CR_TFRCLKDIS_SHIFT                   10
#define I2S_CR_RFRCLKDIS_MASK                    0x800u
#define I2S_CR_RFRCLKDIS_SHIFT                   11
#define I2S_CR_SYNCTXFS_MASK                     0x1000u
#define I2S_CR_SYNCTXFS_SHIFT                    12
/* ISR Bit Fields */
#define I2S_ISR_TFE0_MASK                        0x1u
#define I2S_ISR_TFE0_SHIFT                       0
#define I2S_ISR_TFE1_MASK                        0x2u
#define I2S_ISR_TFE1_SHIFT                       1
#define I2S_ISR_RFF0_MASK                        0x4u
#define I2S_ISR_RFF0_SHIFT                       2
#define I2S_ISR_RFF1_MASK                        0x8u
#define I2S_ISR_RFF1_SHIFT                       3
#define I2S_ISR_RLS_MASK                         0x10u
#define I2S_ISR_RLS_SHIFT                        4
#define I2S_ISR_TLS_MASK                         0x20u
#define I2S_ISR_TLS_SHIFT                        5
#define I2S_ISR_RFS_MASK                         0x40u
#define I2S_ISR_RFS_SHIFT                        6
#define I2S_ISR_TFS_MASK                         0x80u
#define I2S_ISR_TFS_SHIFT                        7
#define I2S_ISR_TUE0_MASK                        0x100u
#define I2S_ISR_TUE0_SHIFT                       8
#define I2S_ISR_TUE1_MASK                        0x200u
#define I2S_ISR_TUE1_SHIFT                       9
#define I2S_ISR_ROE0_MASK                        0x400u
#define I2S_ISR_ROE0_SHIFT                       10
#define I2S_ISR_ROE1_MASK                        0x800u
#define I2S_ISR_ROE1_SHIFT                       11
#define I2S_ISR_TDE0_MASK                        0x1000u
#define I2S_ISR_TDE0_SHIFT                       12
#define I2S_ISR_TDE1_MASK                        0x2000u
#define I2S_ISR_TDE1_SHIFT                       13
#define I2S_ISR_RDR0_MASK                        0x4000u
#define I2S_ISR_RDR0_SHIFT                       14
#define I2S_ISR_RDR1_MASK                        0x8000u
#define I2S_ISR_RDR1_SHIFT                       15
#define I2S_ISR_RXT_MASK                         0x10000u
#define I2S_ISR_RXT_SHIFT                        16
#define I2S_ISR_CMDDU_MASK                       0x20000u
#define I2S_ISR_CMDDU_SHIFT                      17
#define I2S_ISR_CMDAU_MASK                       0x40000u
#define I2S_ISR_CMDAU_SHIFT                      18
#define I2S_ISR_TRFC_MASK                        0x800000u
#define I2S_ISR_TRFC_SHIFT                       23
#define I2S_ISR_RFRC_MASK                        0x1000000u
#define I2S_ISR_RFRC_SHIFT                       24
/* IER Bit Fields */
#define I2S_IER_TFE0EN_MASK                      0x1u
#define I2S_IER_TFE0EN_SHIFT                     0
#define I2S_IER_TFE1EN_MASK                      0x2u
#define I2S_IER_TFE1EN_SHIFT                     1
#define I2S_IER_RFF0EN_MASK                      0x4u
#define I2S_IER_RFF0EN_SHIFT                     2
#define I2S_IER_RFF1EN_MASK                      0x8u
#define I2S_IER_RFF1EN_SHIFT                     3
#define I2S_IER_RLSEN_MASK                       0x10u
#define I2S_IER_RLSEN_SHIFT                      4
#define I2S_IER_TLSEN_MASK                       0x20u
#define I2S_IER_TLSEN_SHIFT                      5
#define I2S_IER_RFSEN_MASK                       0x40u
#define I2S_IER_RFSEN_SHIFT                      6
#define I2S_IER_TFSEN_MASK                       0x80u
#define I2S_IER_TFSEN_SHIFT                      7
#define I2S_IER_TUE0EN_MASK                      0x100u
#define I2S_IER_TUE0EN_SHIFT                     8
#define I2S_IER_TUE1EN_MASK                      0x200u
#define I2S_IER_TUE1EN_SHIFT                     9
#define I2S_IER_ROE0EN_MASK                      0x400u
#define I2S_IER_ROE0EN_SHIFT                     10
#define I2S_IER_ROE1EN_MASK                      0x800u
#define I2S_IER_ROE1EN_SHIFT                     11
#define I2S_IER_TDE0EN_MASK                      0x1000u
#define I2S_IER_TDE0EN_SHIFT                     12
#define I2S_IER_TDE1EN_MASK                      0x2000u
#define I2S_IER_TDE1EN_SHIFT                     13
#define I2S_IER_RDR0EN_MASK                      0x4000u
#define I2S_IER_RDR0EN_SHIFT                     14
#define I2S_IER_RDR1EN_MASK                      0x8000u
#define I2S_IER_RDR1EN_SHIFT                     15
#define I2S_IER_RXTEN_MASK                       0x10000u
#define I2S_IER_RXTEN_SHIFT                      16
#define I2S_IER_CMDDUEN_MASK                     0x20000u
#define I2S_IER_CMDDUEN_SHIFT                    17
#define I2S_IER_CMDAUEN_MASK                     0x40000u
#define I2S_IER_CMDAUEN_SHIFT                    18
#define I2S_IER_TIE_MASK                         0x80000u
#define I2S_IER_TIE_SHIFT                        19
#define I2S_IER_TDMAE_MASK                       0x100000u
#define I2S_IER_TDMAE_SHIFT                      20
#define I2S_IER_RIE_MASK                         0x200000u
#define I2S_IER_RIE_SHIFT                        21
#define I2S_IER_RDMAE_MASK                       0x400000u
#define I2S_IER_RDMAE_SHIFT                      22
#define I2S_IER_TFRC_EN_MASK                     0x800000u
#define I2S_IER_TFRC_EN_SHIFT                    23
#define I2S_IER_RFRC_EN_MASK                     0x1000000u
#define I2S_IER_RFRC_EN_SHIFT                    24
/* TCR Bit Fields */
#define I2S_TCR_TEFS_MASK                        0x1u
#define I2S_TCR_TEFS_SHIFT                       0
#define I2S_TCR_TFSL_MASK                        0x2u
#define I2S_TCR_TFSL_SHIFT                       1
#define I2S_TCR_TFSI_MASK                        0x4u
#define I2S_TCR_TFSI_SHIFT                       2
#define I2S_TCR_TSCKP_MASK                       0x8u
#define I2S_TCR_TSCKP_SHIFT                      3
#define I2S_TCR_TSHFD_MASK                       0x10u
#define I2S_TCR_TSHFD_SHIFT                      4
#define I2S_TCR_TXDIR_MASK                       0x20u
#define I2S_TCR_TXDIR_SHIFT                      5
#define I2S_TCR_TFDIR_MASK                       0x40u
#define I2S_TCR_TFDIR_SHIFT                      6
#define I2S_TCR_TFEN0_MASK                       0x80u
#define I2S_TCR_TFEN0_SHIFT                      7
#define I2S_TCR_TFEN1_MASK                       0x100u
#define I2S_TCR_TFEN1_SHIFT                      8
#define I2S_TCR_TXBIT0_MASK                      0x200u
#define I2S_TCR_TXBIT0_SHIFT                     9
/* RCR Bit Fields */
#define I2S_RCR_REFS_MASK                        0x1u
#define I2S_RCR_REFS_SHIFT                       0
#define I2S_RCR_RFSL_MASK                        0x2u
#define I2S_RCR_RFSL_SHIFT                       1
#define I2S_RCR_RFSI_MASK                        0x4u
#define I2S_RCR_RFSI_SHIFT                       2
#define I2S_RCR_RSCKP_MASK                       0x8u
#define I2S_RCR_RSCKP_SHIFT                      3
#define I2S_RCR_RSHFD_MASK                       0x10u
#define I2S_RCR_RSHFD_SHIFT                      4
#define I2S_RCR_RXDIR_MASK                       0x20u
#define I2S_RCR_RXDIR_SHIFT                      5
#define I2S_RCR_RFDIR_MASK                       0x40u
#define I2S_RCR_RFDIR_SHIFT                      6
#define I2S_RCR_RFEN0_MASK                       0x80u
#define I2S_RCR_RFEN0_SHIFT                      7
#define I2S_RCR_RFEN1_MASK                       0x100u
#define I2S_RCR_RFEN1_SHIFT                      8
#define I2S_RCR_RXBIT0_MASK                      0x200u
#define I2S_RCR_RXBIT0_SHIFT                     9
#define I2S_RCR_RXEXT_MASK                       0x400u
#define I2S_RCR_RXEXT_SHIFT                      10
/* TCCR Bit Fields */
#define I2S_TCCR_PM_MASK                         0xFFu
#define I2S_TCCR_PM_SHIFT                        0
#define I2S_TCCR_PM(x)                           (((x)<<I2S_TCCR_PM_SHIFT)&I2S_TCCR_PM_MASK)
#define I2S_TCCR_DC_MASK                         0x1F00u
#define I2S_TCCR_DC_SHIFT                        8
#define I2S_TCCR_DC(x)                           (((x)<<I2S_TCCR_DC_SHIFT)&I2S_TCCR_DC_MASK)
#define I2S_TCCR_WL_MASK                         0x1E000u
#define I2S_TCCR_WL_SHIFT                        13
#define I2S_TCCR_WL(x)                           (((x)<<I2S_TCCR_WL_SHIFT)&I2S_TCCR_WL_MASK)
#define I2S_TCCR_PSR_MASK                        0x20000u
#define I2S_TCCR_PSR_SHIFT                       17
#define I2S_TCCR_DIV2_MASK                       0x40000u
#define I2S_TCCR_DIV2_SHIFT                      18
/* RCCR Bit Fields */
#define I2S_RCCR_PM_MASK                         0xFFu
#define I2S_RCCR_PM_SHIFT                        0
#define I2S_RCCR_PM(x)                           (((x)<<I2S_RCCR_PM_SHIFT)&I2S_RCCR_PM_MASK)
#define I2S_RCCR_DC_MASK                         0x1F00u
#define I2S_RCCR_DC_SHIFT                        8
#define I2S_RCCR_DC(x)                           (((x)<<I2S_RCCR_DC_SHIFT)&I2S_RCCR_DC_MASK)
#define I2S_RCCR_WL_MASK                         0x1E000u
#define I2S_RCCR_WL_SHIFT                        13
#define I2S_RCCR_WL(x)                           (((x)<<I2S_RCCR_WL_SHIFT)&I2S_RCCR_WL_MASK)
#define I2S_RCCR_PSR_MASK                        0x20000u
#define I2S_RCCR_PSR_SHIFT                       17
#define I2S_RCCR_DIV2_MASK                       0x40000u
#define I2S_RCCR_DIV2_SHIFT                      18
/* FCSR Bit Fields */
#define I2S_FCSR_TFWM0_MASK                      0xFu
#define I2S_FCSR_TFWM0_SHIFT                     0
#define I2S_FCSR_TFWM0(x)                        (((x)<<I2S_FCSR_TFWM0_SHIFT)&I2S_FCSR_TFWM0_MASK)
#define I2S_FCSR_RFWM0_MASK                      0xF0u
#define I2S_FCSR_RFWM0_SHIFT                     4
#define I2S_FCSR_RFWM0(x)                        (((x)<<I2S_FCSR_RFWM0_SHIFT)&I2S_FCSR_RFWM0_MASK)
#define I2S_FCSR_TFCNT0_MASK                     0xF00u
#define I2S_FCSR_TFCNT0_SHIFT                    8
#define I2S_FCSR_TFCNT0(x)                       (((x)<<I2S_FCSR_TFCNT0_SHIFT)&I2S_FCSR_TFCNT0_MASK)
#define I2S_FCSR_RFCNT0_MASK                     0xF000u
#define I2S_FCSR_RFCNT0_SHIFT                    12
#define I2S_FCSR_RFCNT0(x)                       (((x)<<I2S_FCSR_RFCNT0_SHIFT)&I2S_FCSR_RFCNT0_MASK)
#define I2S_FCSR_TFWM1_MASK                      0xF0000u
#define I2S_FCSR_TFWM1_SHIFT                     16
#define I2S_FCSR_TFWM1(x)                        (((x)<<I2S_FCSR_TFWM1_SHIFT)&I2S_FCSR_TFWM1_MASK)
#define I2S_FCSR_RFWM1_MASK                      0xF00000u
#define I2S_FCSR_RFWM1_SHIFT                     20
#define I2S_FCSR_RFWM1(x)                        (((x)<<I2S_FCSR_RFWM1_SHIFT)&I2S_FCSR_RFWM1_MASK)
#define I2S_FCSR_TFCNT1_MASK                     0xF000000u
#define I2S_FCSR_TFCNT1_SHIFT                    24
#define I2S_FCSR_TFCNT1(x)                       (((x)<<I2S_FCSR_TFCNT1_SHIFT)&I2S_FCSR_TFCNT1_MASK)
#define I2S_FCSR_RFCNT1_MASK                     0xF0000000u
#define I2S_FCSR_RFCNT1_SHIFT                    28
#define I2S_FCSR_RFCNT1(x)                       (((x)<<I2S_FCSR_RFCNT1_SHIFT)&I2S_FCSR_RFCNT1_MASK)
/* ACNT Bit Fields */
#define I2S_ACNT_AC97EN_MASK                     0x1u
#define I2S_ACNT_AC97EN_SHIFT                    0
#define I2S_ACNT_FV_MASK                         0x2u
#define I2S_ACNT_FV_SHIFT                        1
#define I2S_ACNT_TIF_MASK                        0x4u
#define I2S_ACNT_TIF_SHIFT                       2
#define I2S_ACNT_RD_MASK                         0x8u
#define I2S_ACNT_RD_SHIFT                        3
#define I2S_ACNT_WR_MASK                         0x10u
#define I2S_ACNT_WR_SHIFT                        4
#define I2S_ACNT_FRDIV_MASK                      0x7E0u
#define I2S_ACNT_FRDIV_SHIFT                     5
#define I2S_ACNT_FRDIV(x)                        (((x)<<I2S_ACNT_FRDIV_SHIFT)&I2S_ACNT_FRDIV_MASK)
/* ACADD Bit Fields */
#define I2S_ACADD_ACADD_MASK                     0x7FFFFu
#define I2S_ACADD_ACADD_SHIFT                    0
#define I2S_ACADD_ACADD(x)                       (((x)<<I2S_ACADD_ACADD_SHIFT)&I2S_ACADD_ACADD_MASK)
/* ACDAT Bit Fields */
#define I2S_ACDAT_ACDAT_MASK                     0xFFFFFu
#define I2S_ACDAT_ACDAT_SHIFT                    0
#define I2S_ACDAT_ACDAT(x)                       (((x)<<I2S_ACDAT_ACDAT_SHIFT)&I2S_ACDAT_ACDAT_MASK)
/* ATAG Bit Fields */
#define I2S_ATAG_ATAG_MASK                       0xFFFFu
#define I2S_ATAG_ATAG_SHIFT                      0
#define I2S_ATAG_ATAG(x)                         (((x)<<I2S_ATAG_ATAG_SHIFT)&I2S_ATAG_ATAG_MASK)
/* TMSK Bit Fields */
#define I2S_TMSK_TMSK_MASK                       0xFFFFFFFFu
#define I2S_TMSK_TMSK_SHIFT                      0
#define I2S_TMSK_TMSK(x)                         (((x)<<I2S_TMSK_TMSK_SHIFT)&I2S_TMSK_TMSK_MASK)
/* RMSK Bit Fields */
#define I2S_RMSK_RMSK_MASK                       0xFFFFFFFFu
#define I2S_RMSK_RMSK_SHIFT                      0
#define I2S_RMSK_RMSK(x)                         (((x)<<I2S_RMSK_RMSK_SHIFT)&I2S_RMSK_RMSK_MASK)
/* ACCST Bit Fields */
#define I2S_ACCST_ACCST_MASK                     0x3FFu
#define I2S_ACCST_ACCST_SHIFT                    0
#define I2S_ACCST_ACCST(x)                       (((x)<<I2S_ACCST_ACCST_SHIFT)&I2S_ACCST_ACCST_MASK)
/* ACCEN Bit Fields */
#define I2S_ACCEN_ACCEN_MASK                     0x3FFu
#define I2S_ACCEN_ACCEN_SHIFT                    0
#define I2S_ACCEN_ACCEN(x)                       (((x)<<I2S_ACCEN_ACCEN_SHIFT)&I2S_ACCEN_ACCEN_MASK)
/* ACCDIS Bit Fields */
#define I2S_ACCDIS_ACCDIS_MASK                   0x3FFu
#define I2S_ACCDIS_ACCDIS_SHIFT                  0
#define I2S_ACCDIS_ACCDIS(x)                     (((x)<<I2S_ACCDIS_ACCDIS_SHIFT)&I2S_ACCDIS_ACCDIS_MASK)

/*! \} */ /* end of group I2S_Register_Masks */


/* I2S - Peripheral instance base addresses */
/*! Peripheral I2S0 base pointer */
#define I2S0_BASE_PTR                            ((I2S_MemMapPtr)0x4002F000u)

/* ----------------------------------------------------------------------------
   -- I2S - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup I2S_Register_Accessor_Macros I2S - Register accessor macros */
/*! \{ */


/* I2S - Register instance definitions */
/* I2S0 */
#define I2S_TX0                                  I2S_TX0_REG(I2S0_BASE_PTR)
#define I2S_TX1                                  I2S_TX1_REG(I2S0_BASE_PTR)
#define I2S_RX0                                  I2S_RX0_REG(I2S0_BASE_PTR)
#define I2S_RX1                                  I2S_RX1_REG(I2S0_BASE_PTR)
#define I2S_CR                                   I2S_CR_REG(I2S0_BASE_PTR)
#define I2S_ISR                                  I2S_ISR_REG(I2S0_BASE_PTR)
#define I2S_IER                                  I2S_IER_REG(I2S0_BASE_PTR)
#define I2S_TCR                                  I2S_TCR_REG(I2S0_BASE_PTR)
#define I2S_RCR                                  I2S_RCR_REG(I2S0_BASE_PTR)
#define I2S_TCCR                                 I2S_TCCR_REG(I2S0_BASE_PTR)
#define I2S_RCCR                                 I2S_RCCR_REG(I2S0_BASE_PTR)
#define I2S_FCSR                                 I2S_FCSR_REG(I2S0_BASE_PTR)
#define I2S_ACNT                                 I2S_ACNT_REG(I2S0_BASE_PTR)
#define I2S_ACADD                                I2S_ACADD_REG(I2S0_BASE_PTR)
#define I2S_ACDAT                                I2S_ACDAT_REG(I2S0_BASE_PTR)
#define I2S_ATAG                                 I2S_ATAG_REG(I2S0_BASE_PTR)
#define I2S_TMSK                                 I2S_TMSK_REG(I2S0_BASE_PTR)
#define I2S_RMSK                                 I2S_RMSK_REG(I2S0_BASE_PTR)
#define I2S_ACCST                                I2S_ACCST_REG(I2S0_BASE_PTR)
#define I2S_ACCEN                                I2S_ACCEN_REG(I2S0_BASE_PTR)
#define I2S_ACCDIS                               I2S_ACCDIS_REG(I2S0_BASE_PTR)

/*! \} */ /* end of group I2S_Register_Accessor_Macros */


/*! \} */ /* end of group I2S_Peripheral */


/* ----------------------------------------------------------------------------
   -- LLWU
   ---------------------------------------------------------------------------- */

/*! \addtogroup LLWU_Peripheral LLWU */
/*! \{ */

/*! LLWU - Peripheral register structure */
typedef struct LLWU_MemMap {
  uint8_t PE1;                                     /*!< LLWU Pin Enable 1 Register, offset: 0x0 */
  uint8_t PE2;                                     /*!< LLWU Pin Enable 2 Register, offset: 0x1 */
  uint8_t PE3;                                     /*!< LLWU Pin Enable 3 Register, offset: 0x2 */
  uint8_t PE4;                                     /*!< LLWU Pin Enable 4 Register, offset: 0x3 */
  uint8_t ME;                                      /*!< LLWU Module Enable Register, offset: 0x4 */
  uint8_t F1;                                      /*!< LLWU Flag 1 Register, offset: 0x5 */
  uint8_t F2;                                      /*!< LLWU Flag 2 Register, offset: 0x6 */
  uint8_t F3;                                      /*!< LLWU Flag 3 Register, offset: 0x7 */
  uint8_t CS;                                      /*!< LLWU Control and Status Register, offset: 0x8 */
} volatile *LLWU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros */
/*! \{ */


/* LLWU - Register accessors */
#define LLWU_PE1_REG(base)                       ((base)->PE1)
#define LLWU_PE2_REG(base)                       ((base)->PE2)
#define LLWU_PE3_REG(base)                       ((base)->PE3)
#define LLWU_PE4_REG(base)                       ((base)->PE4)
#define LLWU_ME_REG(base)                        ((base)->ME)
#define LLWU_F1_REG(base)                        ((base)->F1)
#define LLWU_F2_REG(base)                        ((base)->F2)
#define LLWU_F3_REG(base)                        ((base)->F3)
#define LLWU_CS_REG(base)                        ((base)->CS)

/*! \} */ /* end of group LLWU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LLWU Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup LLWU_Register_Masks LLWU Register Masks */
/*! \{ */

/* PE1 Bit Fields */
#define LLWU_PE1_WUPE0_MASK                      0x3u
#define LLWU_PE1_WUPE0_SHIFT                     0
#define LLWU_PE1_WUPE0(x)                        (((x)<<LLWU_PE1_WUPE0_SHIFT)&LLWU_PE1_WUPE0_MASK)
#define LLWU_PE1_WUPE1_MASK                      0xCu
#define LLWU_PE1_WUPE1_SHIFT                     2
#define LLWU_PE1_WUPE1(x)                        (((x)<<LLWU_PE1_WUPE1_SHIFT)&LLWU_PE1_WUPE1_MASK)
#define LLWU_PE1_WUPE2_MASK                      0x30u
#define LLWU_PE1_WUPE2_SHIFT                     4
#define LLWU_PE1_WUPE2(x)                        (((x)<<LLWU_PE1_WUPE2_SHIFT)&LLWU_PE1_WUPE2_MASK)
#define LLWU_PE1_WUPE3_MASK                      0xC0u
#define LLWU_PE1_WUPE3_SHIFT                     6
#define LLWU_PE1_WUPE3(x)                        (((x)<<LLWU_PE1_WUPE3_SHIFT)&LLWU_PE1_WUPE3_MASK)
/* PE2 Bit Fields */
#define LLWU_PE2_WUPE4_MASK                      0x3u
#define LLWU_PE2_WUPE4_SHIFT                     0
#define LLWU_PE2_WUPE4(x)                        (((x)<<LLWU_PE2_WUPE4_SHIFT)&LLWU_PE2_WUPE4_MASK)
#define LLWU_PE2_WUPE5_MASK                      0xCu
#define LLWU_PE2_WUPE5_SHIFT                     2
#define LLWU_PE2_WUPE5(x)                        (((x)<<LLWU_PE2_WUPE5_SHIFT)&LLWU_PE2_WUPE5_MASK)
#define LLWU_PE2_WUPE6_MASK                      0x30u
#define LLWU_PE2_WUPE6_SHIFT                     4
#define LLWU_PE2_WUPE6(x)                        (((x)<<LLWU_PE2_WUPE6_SHIFT)&LLWU_PE2_WUPE6_MASK)
#define LLWU_PE2_WUPE7_MASK                      0xC0u
#define LLWU_PE2_WUPE7_SHIFT                     6
#define LLWU_PE2_WUPE7(x)                        (((x)<<LLWU_PE2_WUPE7_SHIFT)&LLWU_PE2_WUPE7_MASK)
/* PE3 Bit Fields */
#define LLWU_PE3_WUPE8_MASK                      0x3u
#define LLWU_PE3_WUPE8_SHIFT                     0
#define LLWU_PE3_WUPE8(x)                        (((x)<<LLWU_PE3_WUPE8_SHIFT)&LLWU_PE3_WUPE8_MASK)
#define LLWU_PE3_WUPE9_MASK                      0xCu
#define LLWU_PE3_WUPE9_SHIFT                     2
#define LLWU_PE3_WUPE9(x)                        (((x)<<LLWU_PE3_WUPE9_SHIFT)&LLWU_PE3_WUPE9_MASK)
#define LLWU_PE3_WUPE10_MASK                     0x30u
#define LLWU_PE3_WUPE10_SHIFT                    4
#define LLWU_PE3_WUPE10(x)                       (((x)<<LLWU_PE3_WUPE10_SHIFT)&LLWU_PE3_WUPE10_MASK)
#define LLWU_PE3_WUPE11_MASK                     0xC0u
#define LLWU_PE3_WUPE11_SHIFT                    6
#define LLWU_PE3_WUPE11(x)                       (((x)<<LLWU_PE3_WUPE11_SHIFT)&LLWU_PE3_WUPE11_MASK)
/* PE4 Bit Fields */
#define LLWU_PE4_WUPE12_MASK                     0x3u
#define LLWU_PE4_WUPE12_SHIFT                    0
#define LLWU_PE4_WUPE12(x)                       (((x)<<LLWU_PE4_WUPE12_SHIFT)&LLWU_PE4_WUPE12_MASK)
#define LLWU_PE4_WUPE13_MASK                     0xCu
#define LLWU_PE4_WUPE13_SHIFT                    2
#define LLWU_PE4_WUPE13(x)                       (((x)<<LLWU_PE4_WUPE13_SHIFT)&LLWU_PE4_WUPE13_MASK)
#define LLWU_PE4_WUPE14_MASK                     0x30u
#define LLWU_PE4_WUPE14_SHIFT                    4
#define LLWU_PE4_WUPE14(x)                       (((x)<<LLWU_PE4_WUPE14_SHIFT)&LLWU_PE4_WUPE14_MASK)
#define LLWU_PE4_WUPE15_MASK                     0xC0u
#define LLWU_PE4_WUPE15_SHIFT                    6
#define LLWU_PE4_WUPE15(x)                       (((x)<<LLWU_PE4_WUPE15_SHIFT)&LLWU_PE4_WUPE15_MASK)
/* ME Bit Fields */
#define LLWU_ME_WUME0_MASK                       0x1u
#define LLWU_ME_WUME0_SHIFT                      0
#define LLWU_ME_WUME1_MASK                       0x2u
#define LLWU_ME_WUME1_SHIFT                      1
#define LLWU_ME_WUME2_MASK                       0x4u
#define LLWU_ME_WUME2_SHIFT                      2
#define LLWU_ME_WUME3_MASK                       0x8u
#define LLWU_ME_WUME3_SHIFT                      3
#define LLWU_ME_WUME4_MASK                       0x10u
#define LLWU_ME_WUME4_SHIFT                      4
#define LLWU_ME_WUME5_MASK                       0x20u
#define LLWU_ME_WUME5_SHIFT                      5
#define LLWU_ME_WUME6_MASK                       0x40u
#define LLWU_ME_WUME6_SHIFT                      6
#define LLWU_ME_WUME7_MASK                       0x80u
#define LLWU_ME_WUME7_SHIFT                      7
/* F1 Bit Fields */
#define LLWU_F1_WUF0_MASK                        0x1u
#define LLWU_F1_WUF0_SHIFT                       0
#define LLWU_F1_WUF1_MASK                        0x2u
#define LLWU_F1_WUF1_SHIFT                       1
#define LLWU_F1_WUF2_MASK                        0x4u
#define LLWU_F1_WUF2_SHIFT                       2
#define LLWU_F1_WUF3_MASK                        0x8u
#define LLWU_F1_WUF3_SHIFT                       3
#define LLWU_F1_WUF4_MASK                        0x10u
#define LLWU_F1_WUF4_SHIFT                       4
#define LLWU_F1_WUF5_MASK                        0x20u
#define LLWU_F1_WUF5_SHIFT                       5
#define LLWU_F1_WUF6_MASK                        0x40u
#define LLWU_F1_WUF6_SHIFT                       6
#define LLWU_F1_WUF7_MASK                        0x80u
#define LLWU_F1_WUF7_SHIFT                       7
/* F2 Bit Fields */
#define LLWU_F2_WUF8_MASK                        0x1u
#define LLWU_F2_WUF8_SHIFT                       0
#define LLWU_F2_WUF9_MASK                        0x2u
#define LLWU_F2_WUF9_SHIFT                       1
#define LLWU_F2_WUF10_MASK                       0x4u
#define LLWU_F2_WUF10_SHIFT                      2
#define LLWU_F2_WUF11_MASK                       0x8u
#define LLWU_F2_WUF11_SHIFT                      3
#define LLWU_F2_WUF12_MASK                       0x10u
#define LLWU_F2_WUF12_SHIFT                      4
#define LLWU_F2_WUF13_MASK                       0x20u
#define LLWU_F2_WUF13_SHIFT                      5
#define LLWU_F2_WUF14_MASK                       0x40u
#define LLWU_F2_WUF14_SHIFT                      6
#define LLWU_F2_WUF15_MASK                       0x80u
#define LLWU_F2_WUF15_SHIFT                      7
/* F3 Bit Fields */
#define LLWU_F3_MWUF0_MASK                       0x1u
#define LLWU_F3_MWUF0_SHIFT                      0
#define LLWU_F3_MWUF1_MASK                       0x2u
#define LLWU_F3_MWUF1_SHIFT                      1
#define LLWU_F3_MWUF2_MASK                       0x4u
#define LLWU_F3_MWUF2_SHIFT                      2
#define LLWU_F3_MWUF3_MASK                       0x8u
#define LLWU_F3_MWUF3_SHIFT                      3
#define LLWU_F3_MWUF4_MASK                       0x10u
#define LLWU_F3_MWUF4_SHIFT                      4
#define LLWU_F3_MWUF5_MASK                       0x20u
#define LLWU_F3_MWUF5_SHIFT                      5
#define LLWU_F3_MWUF6_MASK                       0x40u
#define LLWU_F3_MWUF6_SHIFT                      6
#define LLWU_F3_MWUF7_MASK                       0x80u
#define LLWU_F3_MWUF7_SHIFT                      7
/* CS Bit Fields */
#define LLWU_CS_FLTR_MASK                        0x1u
#define LLWU_CS_FLTR_SHIFT                       0
#define LLWU_CS_FLTEP_MASK                       0x2u
#define LLWU_CS_FLTEP_SHIFT                      1
#define LLWU_CS_LLRSTEN_MASK                     0x4u
#define LLWU_CS_LLRSTEN_SHIFT                    2
#define LLWU_CS_ACKISO_MASK                      0x80u
#define LLWU_CS_ACKISO_SHIFT                     7

/*! \} */ /* end of group LLWU_Register_Masks */


/* LLWU - Peripheral instance base addresses */
/*! Peripheral LLWU base pointer */
#define LLWU_BASE_PTR                            ((LLWU_MemMapPtr)0x4007C000u)

/* ----------------------------------------------------------------------------
   -- LLWU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup LLWU_Register_Accessor_Macros LLWU - Register accessor macros */
/*! \{ */


/* LLWU - Register instance definitions */
/* LLWU */
#define LLWU_PE1                                 LLWU_PE1_REG(LLWU_BASE_PTR)
#define LLWU_PE2                                 LLWU_PE2_REG(LLWU_BASE_PTR)
#define LLWU_PE3                                 LLWU_PE3_REG(LLWU_BASE_PTR)
#define LLWU_PE4                                 LLWU_PE4_REG(LLWU_BASE_PTR)
#define LLWU_ME                                  LLWU_ME_REG(LLWU_BASE_PTR)
#define LLWU_F1                                  LLWU_F1_REG(LLWU_BASE_PTR)
#define LLWU_F2                                  LLWU_F2_REG(LLWU_BASE_PTR)
#define LLWU_F3                                  LLWU_F3_REG(LLWU_BASE_PTR)
#define LLWU_CS                                  LLWU_CS_REG(LLWU_BASE_PTR)

/*! \} */ /* end of group LLWU_Register_Accessor_Macros */


/*! \} */ /* end of group LLWU_Peripheral */


/* ----------------------------------------------------------------------------
   -- LPT
   ---------------------------------------------------------------------------- */

/*! \addtogroup LPT_Peripheral LPT */
/*! \{ */

/*! LPT - Peripheral register structure */
typedef struct LPT_MemMap {
  uint32_t CSR;                                    /*!< Low Power Timer Control Status Register, offset: 0x0 */
  uint32_t PSR;                                    /*!< Low Power Timer Prescale Register, offset: 0x4 */
  uint32_t CMR;                                    /*!< Low Power Timer Compare Register, offset: 0x8 */
  uint32_t CNR;                                    /*!< Low Power Timer Counter Register, offset: 0xC */
} volatile *LPT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LPT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup LPT_Register_Accessor_Macros LPT - Register accessor macros */
/*! \{ */


/* LPT - Register accessors */
#define LPT_CSR_REG(base)                        ((base)->CSR)
#define LPT_PSR_REG(base)                        ((base)->PSR)
#define LPT_CMR_REG(base)                        ((base)->CMR)
#define LPT_CNR_REG(base)                        ((base)->CNR)

/*! \} */ /* end of group LPT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LPT Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup LPT_Register_Masks LPT Register Masks */
/*! \{ */

/* CSR Bit Fields */
#define LPT_CSR_TEN_MASK                         0x1u
#define LPT_CSR_TEN_SHIFT                        0
#define LPT_CSR_TMS_MASK                         0x2u
#define LPT_CSR_TMS_SHIFT                        1
#define LPT_CSR_TFC_MASK                         0x4u
#define LPT_CSR_TFC_SHIFT                        2
#define LPT_CSR_TPP_MASK                         0x8u
#define LPT_CSR_TPP_SHIFT                        3
#define LPT_CSR_TPS_MASK                         0x30u
#define LPT_CSR_TPS_SHIFT                        4
#define LPT_CSR_TPS(x)                           (((x)<<LPT_CSR_TPS_SHIFT)&LPT_CSR_TPS_MASK)
#define LPT_CSR_TIE_MASK                         0x40u
#define LPT_CSR_TIE_SHIFT                        6
#define LPT_CSR_TCF_MASK                         0x80u
#define LPT_CSR_TCF_SHIFT                        7
/* PSR Bit Fields */
#define LPT_PSR_PCS_MASK                         0x3u
#define LPT_PSR_PCS_SHIFT                        0
#define LPT_PSR_PCS(x)                           (((x)<<LPT_PSR_PCS_SHIFT)&LPT_PSR_PCS_MASK)
#define LPT_PSR_PBYP_MASK                        0x4u
#define LPT_PSR_PBYP_SHIFT                       2
#define LPT_PSR_PRESCALE_MASK                    0x78u
#define LPT_PSR_PRESCALE_SHIFT                   3
#define LPT_PSR_PRESCALE(x)                      (((x)<<LPT_PSR_PRESCALE_SHIFT)&LPT_PSR_PRESCALE_MASK)
/* CMR Bit Fields */
#define LPT_CMR_COMPARE_MASK                     0xFFFFu
#define LPT_CMR_COMPARE_SHIFT                    0
#define LPT_CMR_COMPARE(x)                       (((x)<<LPT_CMR_COMPARE_SHIFT)&LPT_CMR_COMPARE_MASK)
/* CNR Bit Fields */
#define LPT_CNR_COUNTER_MASK                     0xFFFFu
#define LPT_CNR_COUNTER_SHIFT                    0
#define LPT_CNR_COUNTER(x)                       (((x)<<LPT_CNR_COUNTER_SHIFT)&LPT_CNR_COUNTER_MASK)

/*! \} */ /* end of group LPT_Register_Masks */


/* LPT - Peripheral instance base addresses */
/*! Peripheral LPT0 base pointer */
#define LPT0_BASE_PTR                            ((LPT_MemMapPtr)0x40040000u)

/* ----------------------------------------------------------------------------
   -- LPT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup LPT_Register_Accessor_Macros LPT - Register accessor macros */
/*! \{ */


/* LPT - Register instance definitions */
/* LPT0 */
#define LPT0_CSR                                 LPT_CSR_REG(LPT0_BASE_PTR)
#define LPT0_PSR                                 LPT_PSR_REG(LPT0_BASE_PTR)
#define LPT0_CMR                                 LPT_CMR_REG(LPT0_BASE_PTR)
#define LPT0_CNR                                 LPT_CNR_REG(LPT0_BASE_PTR)

/*! \} */ /* end of group LPT_Register_Accessor_Macros */


/*! \} */ /* end of group LPT_Peripheral */


/* ----------------------------------------------------------------------------
   -- MC
   ---------------------------------------------------------------------------- */

/*! \addtogroup MC_Peripheral MC */
/*! \{ */

/*! MC - Peripheral register structure */
typedef struct MC_MemMap {
  uint8_t SRSH;                                    /*!< System Reset Status Register High, offset: 0x0 */
  uint8_t SRSL;                                    /*!< System Reset Status Register Low, offset: 0x1 */
  uint8_t PMPROT;                                  /*!< Power Mode Protection Register, offset: 0x2 */
  uint8_t PMCTRL;                                  /*!< Power Mode Control Register, offset: 0x3 */
} volatile *MC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MC_Register_Accessor_Macros MC - Register accessor macros */
/*! \{ */


/* MC - Register accessors */
#define MC_SRSH_REG(base)                        ((base)->SRSH)
#define MC_SRSL_REG(base)                        ((base)->SRSL)
#define MC_PMPROT_REG(base)                      ((base)->PMPROT)
#define MC_PMCTRL_REG(base)                      ((base)->PMCTRL)

/*! \} */ /* end of group MC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup MC_Register_Masks MC Register Masks */
/*! \{ */

/* SRSH Bit Fields */
#define MC_SRSH_JTAG_MASK                        0x1u
#define MC_SRSH_JTAG_SHIFT                       0
#define MC_SRSH_LOCKUP_MASK                      0x2u
#define MC_SRSH_LOCKUP_SHIFT                     1
#define MC_SRSH_SW_MASK                          0x4u
#define MC_SRSH_SW_SHIFT                         2
/* SRSL Bit Fields */
#define MC_SRSL_WAKEUP_MASK                      0x1u
#define MC_SRSL_WAKEUP_SHIFT                     0
#define MC_SRSL_LVD_MASK                         0x2u
#define MC_SRSL_LVD_SHIFT                        1
#define MC_SRSL_LOC_MASK                         0x4u
#define MC_SRSL_LOC_SHIFT                        2
#define MC_SRSL_COP_MASK                         0x20u
#define MC_SRSL_COP_SHIFT                        5
#define MC_SRSL_PIN_MASK                         0x40u
#define MC_SRSL_PIN_SHIFT                        6
#define MC_SRSL_POR_MASK                         0x80u
#define MC_SRSL_POR_SHIFT                        7
/* PMPROT Bit Fields */
#define MC_PMPROT_AVLLS1_MASK                    0x1u
#define MC_PMPROT_AVLLS1_SHIFT                   0
#define MC_PMPROT_AVLLS2_MASK                    0x2u
#define MC_PMPROT_AVLLS2_SHIFT                   1
#define MC_PMPROT_AVLLS3_MASK                    0x4u
#define MC_PMPROT_AVLLS3_SHIFT                   2
#define MC_PMPROT_ALLS_MASK                      0x10u
#define MC_PMPROT_ALLS_SHIFT                     4
#define MC_PMPROT_AVLP_MASK                      0x20u
#define MC_PMPROT_AVLP_SHIFT                     5
/* PMCTRL Bit Fields */
#define MC_PMCTRL_LPLLSM_MASK                    0x7u
#define MC_PMCTRL_LPLLSM_SHIFT                   0
#define MC_PMCTRL_LPLLSM(x)                      (((x)<<MC_PMCTRL_LPLLSM_SHIFT)&MC_PMCTRL_LPLLSM_MASK)
#define MC_PMCTRL_RUNM_MASK                      0x60u
#define MC_PMCTRL_RUNM_SHIFT                     5
#define MC_PMCTRL_RUNM(x)                        (((x)<<MC_PMCTRL_RUNM_SHIFT)&MC_PMCTRL_RUNM_MASK)
#define MC_PMCTRL_LPWUI_MASK                     0x80u
#define MC_PMCTRL_LPWUI_SHIFT                    7

/*! \} */ /* end of group MC_Register_Masks */


/* MC - Peripheral instance base addresses */
/*! Peripheral MC base pointer */
#define MC_BASE_PTR                              ((MC_MemMapPtr)0x4007E000u)

/* ----------------------------------------------------------------------------
   -- MC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MC_Register_Accessor_Macros MC - Register accessor macros */
/*! \{ */


/* MC - Register instance definitions */
/* MC */
#define MC_SRSH                                  MC_SRSH_REG(MC_BASE_PTR)
#define MC_SRSL                                  MC_SRSL_REG(MC_BASE_PTR)
#define MC_PMPROT                                MC_PMPROT_REG(MC_BASE_PTR)
#define MC_PMCTRL                                MC_PMCTRL_REG(MC_BASE_PTR)

/*! \} */ /* end of group MC_Register_Accessor_Macros */


/*! \} */ /* end of group MC_Peripheral */


/* ----------------------------------------------------------------------------
   -- MCG
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCG_Peripheral MCG */
/*! \{ */

/*! MCG - Peripheral register structure */
typedef struct MCG_MemMap {
  uint8_t C1;                                      /*!< MCG Control 1 Register, offset: 0x0 */
  uint8_t C2;                                      /*!< MCG Control 2 Register, offset: 0x1 */
  uint8_t C3;                                      /*!< MCG Control 3 Register, offset: 0x2 */
  uint8_t C4;                                      /*!< MCG Control 4 Register, offset: 0x3 */
  uint8_t C5;                                      /*!< MCG Control 5 Register, offset: 0x4 */
  uint8_t C6;                                      /*!< MCG Control 6 Register, offset: 0x5 */
  uint8_t S;                                       /*!< MCG Status Register, offset: 0x6 */
  uint8_t RESERVED_0[1];
  uint8_t ATC;                                     /*!< MCG Auto Trim Control Register, offset: 0x8 */
  uint8_t RESERVED_1[1];
  uint8_t ATCVH;                                   /*!< MCG Auto Trim Compare Value High Register, offset: 0xA */
  uint8_t ATCVL;                                   /*!< MCG Auto Trim Compare Value Low Register, offset: 0xB */
} volatile *MCG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros */
/*! \{ */


/* MCG - Register accessors */
#define MCG_C1_REG(base)                         ((base)->C1)
#define MCG_C2_REG(base)                         ((base)->C2)
#define MCG_C3_REG(base)                         ((base)->C3)
#define MCG_C4_REG(base)                         ((base)->C4)
#define MCG_C5_REG(base)                         ((base)->C5)
#define MCG_C6_REG(base)                         ((base)->C6)
#define MCG_S_REG(base)                          ((base)->S)
#define MCG_ATC_REG(base)                        ((base)->ATC)
#define MCG_ATCVH_REG(base)                      ((base)->ATCVH)
#define MCG_ATCVL_REG(base)                      ((base)->ATCVL)

/*! \} */ /* end of group MCG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCG Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCG_Register_Masks MCG Register Masks */
/*! \{ */

/* C1 Bit Fields */
#define MCG_C1_IREFSTEN_MASK                     0x1u
#define MCG_C1_IREFSTEN_SHIFT                    0
#define MCG_C1_IRCLKEN_MASK                      0x2u
#define MCG_C1_IRCLKEN_SHIFT                     1
#define MCG_C1_IREFS_MASK                        0x4u
#define MCG_C1_IREFS_SHIFT                       2
#define MCG_C1_FRDIV_MASK                        0x38u
#define MCG_C1_FRDIV_SHIFT                       3
#define MCG_C1_FRDIV(x)                          (((x)<<MCG_C1_FRDIV_SHIFT)&MCG_C1_FRDIV_MASK)
#define MCG_C1_CLKS_MASK                         0xC0u
#define MCG_C1_CLKS_SHIFT                        6
#define MCG_C1_CLKS(x)                           (((x)<<MCG_C1_CLKS_SHIFT)&MCG_C1_CLKS_MASK)
/* C2 Bit Fields */
#define MCG_C2_IRCS_MASK                         0x1u
#define MCG_C2_IRCS_SHIFT                        0
#define MCG_C2_LP_MASK                           0x2u
#define MCG_C2_LP_SHIFT                          1
#define MCG_C2_EREFS_MASK                        0x4u
#define MCG_C2_EREFS_SHIFT                       2
#define MCG_C2_HGO_MASK                          0x8u
#define MCG_C2_HGO_SHIFT                         3
#define MCG_C2_RANGE_MASK                        0x30u
#define MCG_C2_RANGE_SHIFT                       4
#define MCG_C2_RANGE(x)                          (((x)<<MCG_C2_RANGE_SHIFT)&MCG_C2_RANGE_MASK)
/* C3 Bit Fields */
#define MCG_C3_SCTRIM_MASK                       0xFFu
#define MCG_C3_SCTRIM_SHIFT                      0
#define MCG_C3_SCTRIM(x)                         (((x)<<MCG_C3_SCTRIM_SHIFT)&MCG_C3_SCTRIM_MASK)
/* C4 Bit Fields */
#define MCG_C4_SCFTRIM_MASK                      0x1u
#define MCG_C4_SCFTRIM_SHIFT                     0
#define MCG_C4_FCTRIM_MASK                       0x1Eu
#define MCG_C4_FCTRIM_SHIFT                      1
#define MCG_C4_FCTRIM(x)                         (((x)<<MCG_C4_FCTRIM_SHIFT)&MCG_C4_FCTRIM_MASK)
#define MCG_C4_DRST_DRS_MASK                     0x60u
#define MCG_C4_DRST_DRS_SHIFT                    5
#define MCG_C4_DRST_DRS(x)                       (((x)<<MCG_C4_DRST_DRS_SHIFT)&MCG_C4_DRST_DRS_MASK)
#define MCG_C4_DMX32_MASK                        0x80u
#define MCG_C4_DMX32_SHIFT                       7
/* C5 Bit Fields */
#define MCG_C5_PRDIV_MASK                        0x1Fu
#define MCG_C5_PRDIV_SHIFT                       0
#define MCG_C5_PRDIV(x)                          (((x)<<MCG_C5_PRDIV_SHIFT)&MCG_C5_PRDIV_MASK)
#define MCG_C5_PLLSTEN_MASK                      0x20u
#define MCG_C5_PLLSTEN_SHIFT                     5
#define MCG_C5_PLLCLKEN_MASK                     0x40u
#define MCG_C5_PLLCLKEN_SHIFT                    6
/* C6 Bit Fields */
#define MCG_C6_VDIV_MASK                         0x1Fu
#define MCG_C6_VDIV_SHIFT                        0
#define MCG_C6_VDIV(x)                           (((x)<<MCG_C6_VDIV_SHIFT)&MCG_C6_VDIV_MASK)
#define MCG_C6_CME_MASK                          0x20u
#define MCG_C6_CME_SHIFT                         5
#define MCG_C6_PLLS_MASK                         0x40u
#define MCG_C6_PLLS_SHIFT                        6
#define MCG_C6_LOLIE_MASK                        0x80u
#define MCG_C6_LOLIE_SHIFT                       7
/* S Bit Fields */
#define MCG_S_IRCST_MASK                         0x1u
#define MCG_S_IRCST_SHIFT                        0
#define MCG_S_OSCINIT_MASK                       0x2u
#define MCG_S_OSCINIT_SHIFT                      1
#define MCG_S_CLKST_MASK                         0xCu
#define MCG_S_CLKST_SHIFT                        2
#define MCG_S_CLKST(x)                           (((x)<<MCG_S_CLKST_SHIFT)&MCG_S_CLKST_MASK)
#define MCG_S_IREFST_MASK                        0x10u
#define MCG_S_IREFST_SHIFT                       4
#define MCG_S_PLLST_MASK                         0x20u
#define MCG_S_PLLST_SHIFT                        5
#define MCG_S_LOCK_MASK                          0x40u
#define MCG_S_LOCK_SHIFT                         6
#define MCG_S_LOLS_MASK                          0x80u
#define MCG_S_LOLS_SHIFT                         7
/* ATC Bit Fields */
#define MCG_ATC_ATMF_MASK                        0x20u
#define MCG_ATC_ATMF_SHIFT                       5
#define MCG_ATC_ATMS_MASK                        0x40u
#define MCG_ATC_ATMS_SHIFT                       6
#define MCG_ATC_ATME_MASK                        0x80u
#define MCG_ATC_ATME_SHIFT                       7
/* ATCVH Bit Fields */
#define MCG_ATCVH_ATCVH_MASK                     0xFFu
#define MCG_ATCVH_ATCVH_SHIFT                    0
#define MCG_ATCVH_ATCVH(x)                       (((x)<<MCG_ATCVH_ATCVH_SHIFT)&MCG_ATCVH_ATCVH_MASK)
/* ATCVL Bit Fields */
#define MCG_ATCVL_ATCVL_MASK                     0xFFu
#define MCG_ATCVL_ATCVL_SHIFT                    0
#define MCG_ATCVL_ATCVL(x)                       (((x)<<MCG_ATCVL_ATCVL_SHIFT)&MCG_ATCVL_ATCVL_MASK)

/*! \} */ /* end of group MCG_Register_Masks */


/* MCG - Peripheral instance base addresses */
/*! Peripheral MCG base pointer */
#define MCG_BASE_PTR                             ((MCG_MemMapPtr)0x40064000u)

/* ----------------------------------------------------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros */
/*! \{ */


/* MCG - Register instance definitions */
/* MCG */
#define MCG_C1                                   MCG_C1_REG(MCG_BASE_PTR)
#define MCG_C2                                   MCG_C2_REG(MCG_BASE_PTR)
#define MCG_C3                                   MCG_C3_REG(MCG_BASE_PTR)
#define MCG_C4                                   MCG_C4_REG(MCG_BASE_PTR)
#define MCG_C5                                   MCG_C5_REG(MCG_BASE_PTR)
#define MCG_C6                                   MCG_C6_REG(MCG_BASE_PTR)
#define MCG_S                                    MCG_S_REG(MCG_BASE_PTR)
#define MCG_ATC                                  MCG_ATC_REG(MCG_BASE_PTR)
#define MCG_ATCVH                                MCG_ATCVH_REG(MCG_BASE_PTR)
#define MCG_ATCVL                                MCG_ATCVL_REG(MCG_BASE_PTR)

/*! \} */ /* end of group MCG_Register_Accessor_Macros */


/*! \} */ /* end of group MCG_Peripheral */


/* ----------------------------------------------------------------------------
   -- MCM
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCM_Peripheral MCM */
/*! \{ */

/*! MCM - Peripheral register structure */
typedef struct MCM_MemMap {
  uint8_t RESERVED_0[8];
  uint16_t PLASC;                                  /*!< Crossbar switch (AXBS) slave configuration, offset: 0x8 */
  uint16_t PLAMC;                                  /*!< Crossbar switch (AXBS) master configuration, offset: 0xA */
  uint32_t SRAMAP;                                 /*!< SRAM arbitration and protection, offset: 0xC */
  uint32_t ISR;                                    /*!< Interrupt status register, offset: 0x10 */
  uint32_t ETBCC;                                  /*!< ETB counter control register, offset: 0x14 */
  uint32_t ETBRL;                                  /*!< ETB reload register, offset: 0x18 */
  uint32_t ETBCNT;                                 /*!< ETB counter value register, offset: 0x1C */
} volatile *MCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros */
/*! \{ */


/* MCM - Register accessors */
#define MCM_PLASC_REG(base)                      ((base)->PLASC)
#define MCM_PLAMC_REG(base)                      ((base)->PLAMC)
#define MCM_SRAMAP_REG(base)                     ((base)->SRAMAP)
#define MCM_ISR_REG(base)                        ((base)->ISR)
#define MCM_ETBCC_REG(base)                      ((base)->ETBCC)
#define MCM_ETBRL_REG(base)                      ((base)->ETBRL)
#define MCM_ETBCNT_REG(base)                     ((base)->ETBCNT)

/*! \} */ /* end of group MCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCM_Register_Masks MCM Register Masks */
/*! \{ */

/* PLASC Bit Fields */
#define MCM_PLASC_ASC_MASK                       0xFFu
#define MCM_PLASC_ASC_SHIFT                      0
#define MCM_PLASC_ASC(x)                         (((x)<<MCM_PLASC_ASC_SHIFT)&MCM_PLASC_ASC_MASK)
/* PLAMC Bit Fields */
#define MCM_PLAMC_AMC_MASK                       0xFFu
#define MCM_PLAMC_AMC_SHIFT                      0
#define MCM_PLAMC_AMC(x)                         (((x)<<MCM_PLAMC_AMC_SHIFT)&MCM_PLAMC_AMC_MASK)
/* SRAMAP Bit Fields */
#define MCM_SRAMAP_SRAMUAP_MASK                  0x3000000u
#define MCM_SRAMAP_SRAMUAP_SHIFT                 24
#define MCM_SRAMAP_SRAMUAP(x)                    (((x)<<MCM_SRAMAP_SRAMUAP_SHIFT)&MCM_SRAMAP_SRAMUAP_MASK)
#define MCM_SRAMAP_SRAMUWP_MASK                  0x4000000u
#define MCM_SRAMAP_SRAMUWP_SHIFT                 26
#define MCM_SRAMAP_SRAMLAP_MASK                  0x30000000u
#define MCM_SRAMAP_SRAMLAP_SHIFT                 28
#define MCM_SRAMAP_SRAMLAP(x)                    (((x)<<MCM_SRAMAP_SRAMLAP_SHIFT)&MCM_SRAMAP_SRAMLAP_MASK)
#define MCM_SRAMAP_SRAMLWP_MASK                  0x40000000u
#define MCM_SRAMAP_SRAMLWP_SHIFT                 30
/* ISR Bit Fields */
#define MCM_ISR_IRQ_MASK                         0x2u
#define MCM_ISR_IRQ_SHIFT                        1
#define MCM_ISR_NMI_MASK                         0x4u
#define MCM_ISR_NMI_SHIFT                        2
/* ETBCC Bit Fields */
#define MCM_ETBCC_CNTEN_MASK                     0x1u
#define MCM_ETBCC_CNTEN_SHIFT                    0
#define MCM_ETBCC_RSPT_MASK                      0x6u
#define MCM_ETBCC_RSPT_SHIFT                     1
#define MCM_ETBCC_RSPT(x)                        (((x)<<MCM_ETBCC_RSPT_SHIFT)&MCM_ETBCC_RSPT_MASK)
#define MCM_ETBCC_RLRQ_MASK                      0x8u
#define MCM_ETBCC_RLRQ_SHIFT                     3
#define MCM_ETBCC_ETDIS_MASK                     0x10u
#define MCM_ETBCC_ETDIS_SHIFT                    4
#define MCM_ETBCC_ITDIS_MASK                     0x20u
#define MCM_ETBCC_ITDIS_SHIFT                    5
/* ETBRL Bit Fields */
#define MCM_ETBRL_RELOAD_MASK                    0x7FFu
#define MCM_ETBRL_RELOAD_SHIFT                   0
#define MCM_ETBRL_RELOAD(x)                      (((x)<<MCM_ETBRL_RELOAD_SHIFT)&MCM_ETBRL_RELOAD_MASK)
/* ETBCNT Bit Fields */
#define MCM_ETBCNT_COUNTER_MASK                  0x7FFu
#define MCM_ETBCNT_COUNTER_SHIFT                 0
#define MCM_ETBCNT_COUNTER(x)                    (((x)<<MCM_ETBCNT_COUNTER_SHIFT)&MCM_ETBCNT_COUNTER_MASK)

/*! \} */ /* end of group MCM_Register_Masks */


/* MCM - Peripheral instance base addresses */
/*! Peripheral MCM base pointer */
#define MCM_BASE_PTR                             ((MCM_MemMapPtr)0xE0080000u)

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros */
/*! \{ */


/* MCM - Register instance definitions */
/* MCM */
#define MCM_PLASC                                MCM_PLASC_REG(MCM_BASE_PTR)
#define MCM_PLAMC                                MCM_PLAMC_REG(MCM_BASE_PTR)
#define MCM_SRAMAP                               MCM_SRAMAP_REG(MCM_BASE_PTR)
#define MCM_ISR                                  MCM_ISR_REG(MCM_BASE_PTR)
#define MCM_ETBCC                                MCM_ETBCC_REG(MCM_BASE_PTR)
#define MCM_ETBRL                                MCM_ETBRL_REG(MCM_BASE_PTR)
#define MCM_ETBCNT                               MCM_ETBCNT_REG(MCM_BASE_PTR)

/*! \} */ /* end of group MCM_Register_Accessor_Macros */


/*! \} */ /* end of group MCM_Peripheral */


/* ----------------------------------------------------------------------------
   -- MPU
   ---------------------------------------------------------------------------- */

/*! \addtogroup MPU_Peripheral MPU */
/*! \{ */

/*! MPU - Peripheral register structure */
typedef struct MPU_MemMap {
  uint32_t CESR;                                   /*!< Control/Error Status Register, offset: 0x0 */
  uint8_t RESERVED_0[12];
  struct {                                         /* offset: 0x10, array step: 0x8 */
    uint32_t EAR;                                    /*!< Error Address Register, Slave Port n, array offset: 0x10, array step: 0x8 */
    uint32_t EDR;                                    /*!< Error Detail Register, Slave Port n, array offset: 0x14, array step: 0x8 */
  } SP[5];
  uint8_t RESERVED_1[968];
  uint32_t WORD[12][4];                            /*!< Region Descriptor n, Word 0..Region Descriptor n, Word 3, array offset: 0x400, array step: index*0x10, index2*0x4 */
  uint8_t RESERVED_2[832];
  uint32_t RGDAAC[12];                             /*!< Region Descriptor Alternate Access Control n, array offset: 0x800, array step: 0x4 */
} volatile *MPU_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MPU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MPU_Register_Accessor_Macros MPU - Register accessor macros */
/*! \{ */


/* MPU - Register accessors */
#define MPU_CESR_REG(base)                       ((base)->CESR)
#define MPU_EAR_REG(base,index)                  ((base)->SP[index].EAR)
#define MPU_EDR_REG(base,index)                  ((base)->SP[index].EDR)
#define MPU_WORD_REG(base,index,index2)          ((base)->WORD[index][index2])
#define MPU_RGDAAC_REG(base,index)               ((base)->RGDAAC[index])

/*! \} */ /* end of group MPU_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MPU Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup MPU_Register_Masks MPU Register Masks */
/*! \{ */

/* CESR Bit Fields */
#define MPU_CESR_VLD_MASK                        0x1u
#define MPU_CESR_VLD_SHIFT                       0
#define MPU_CESR_NRGD_MASK                       0xF00u
#define MPU_CESR_NRGD_SHIFT                      8
#define MPU_CESR_NRGD(x)                         (((x)<<MPU_CESR_NRGD_SHIFT)&MPU_CESR_NRGD_MASK)
#define MPU_CESR_NSP_MASK                        0xF000u
#define MPU_CESR_NSP_SHIFT                       12
#define MPU_CESR_NSP(x)                          (((x)<<MPU_CESR_NSP_SHIFT)&MPU_CESR_NSP_MASK)
#define MPU_CESR_HRL_MASK                        0xF0000u
#define MPU_CESR_HRL_SHIFT                       16
#define MPU_CESR_HRL(x)                          (((x)<<MPU_CESR_HRL_SHIFT)&MPU_CESR_HRL_MASK)
#define MPU_CESR_SPERR_MASK                      0xF8000000u
#define MPU_CESR_SPERR_SHIFT                     27
#define MPU_CESR_SPERR(x)                        (((x)<<MPU_CESR_SPERR_SHIFT)&MPU_CESR_SPERR_MASK)
/* EAR Bit Fields */
#define MPU_EAR_EADDR_MASK                       0xFFFFFFFFu
#define MPU_EAR_EADDR_SHIFT                      0
#define MPU_EAR_EADDR(x)                         (((x)<<MPU_EAR_EADDR_SHIFT)&MPU_EAR_EADDR_MASK)
/* EDR Bit Fields */
#define MPU_EDR_ERW_MASK                         0x1u
#define MPU_EDR_ERW_SHIFT                        0
#define MPU_EDR_EATTR_MASK                       0xEu
#define MPU_EDR_EATTR_SHIFT                      1
#define MPU_EDR_EATTR(x)                         (((x)<<MPU_EDR_EATTR_SHIFT)&MPU_EDR_EATTR_MASK)
#define MPU_EDR_EMN_MASK                         0xF0u
#define MPU_EDR_EMN_SHIFT                        4
#define MPU_EDR_EMN(x)                           (((x)<<MPU_EDR_EMN_SHIFT)&MPU_EDR_EMN_MASK)
#define MPU_EDR_EACD_MASK                        0xFFFF0000u
#define MPU_EDR_EACD_SHIFT                       16
#define MPU_EDR_EACD(x)                          (((x)<<MPU_EDR_EACD_SHIFT)&MPU_EDR_EACD_MASK)
/* WORD Bit Fields */
#define MPU_WORD_M0UM_MASK                       0x7u
#define MPU_WORD_M0UM_SHIFT                      0
#define MPU_WORD_M0UM(x)                         (((x)<<MPU_WORD_M0UM_SHIFT)&MPU_WORD_M0UM_MASK)
#define MPU_WORD_VLD_MASK                        0x1u
#define MPU_WORD_VLD_SHIFT                       0
#define MPU_WORD_M0SM_MASK                       0x18u
#define MPU_WORD_M0SM_SHIFT                      3
#define MPU_WORD_M0SM(x)                         (((x)<<MPU_WORD_M0SM_SHIFT)&MPU_WORD_M0SM_MASK)
#define MPU_WORD_ENDADDR_MASK                    0xFFFFFFE0u
#define MPU_WORD_ENDADDR_SHIFT                   5
#define MPU_WORD_ENDADDR(x)                      (((x)<<MPU_WORD_ENDADDR_SHIFT)&MPU_WORD_ENDADDR_MASK)
#define MPU_WORD_SRTADDR_MASK                    0xFFFFFFE0u
#define MPU_WORD_SRTADDR_SHIFT                   5
#define MPU_WORD_SRTADDR(x)                      (((x)<<MPU_WORD_SRTADDR_SHIFT)&MPU_WORD_SRTADDR_MASK)
#define MPU_WORD_M1UM_MASK                       0x1C0u
#define MPU_WORD_M1UM_SHIFT                      6
#define MPU_WORD_M1UM(x)                         (((x)<<MPU_WORD_M1UM_SHIFT)&MPU_WORD_M1UM_MASK)
#define MPU_WORD_M1SM_MASK                       0x600u
#define MPU_WORD_M1SM_SHIFT                      9
#define MPU_WORD_M1SM(x)                         (((x)<<MPU_WORD_M1SM_SHIFT)&MPU_WORD_M1SM_MASK)
#define MPU_WORD_M2UM_MASK                       0x7000u
#define MPU_WORD_M2UM_SHIFT                      12
#define MPU_WORD_M2UM(x)                         (((x)<<MPU_WORD_M2UM_SHIFT)&MPU_WORD_M2UM_MASK)
#define MPU_WORD_M2SM_MASK                       0x18000u
#define MPU_WORD_M2SM_SHIFT                      15
#define MPU_WORD_M2SM(x)                         (((x)<<MPU_WORD_M2SM_SHIFT)&MPU_WORD_M2SM_MASK)
#define MPU_WORD_M3UM_MASK                       0x1C0000u
#define MPU_WORD_M3UM_SHIFT                      18
#define MPU_WORD_M3UM(x)                         (((x)<<MPU_WORD_M3UM_SHIFT)&MPU_WORD_M3UM_MASK)
#define MPU_WORD_M3SM_MASK                       0x600000u
#define MPU_WORD_M3SM_SHIFT                      21
#define MPU_WORD_M3SM(x)                         (((x)<<MPU_WORD_M3SM_SHIFT)&MPU_WORD_M3SM_MASK)
#define MPU_WORD_M4WE_MASK                       0x1000000u
#define MPU_WORD_M4WE_SHIFT                      24
#define MPU_WORD_M4RE_MASK                       0x2000000u
#define MPU_WORD_M4RE_SHIFT                      25
#define MPU_WORD_M5WE_MASK                       0x4000000u
#define MPU_WORD_M5WE_SHIFT                      26
#define MPU_WORD_M5RE_MASK                       0x8000000u
#define MPU_WORD_M5RE_SHIFT                      27
#define MPU_WORD_M6WE_MASK                       0x10000000u
#define MPU_WORD_M6WE_SHIFT                      28
#define MPU_WORD_M6RE_MASK                       0x20000000u
#define MPU_WORD_M6RE_SHIFT                      29
#define MPU_WORD_M7WE_MASK                       0x40000000u
#define MPU_WORD_M7WE_SHIFT                      30
#define MPU_WORD_M7RE_MASK                       0x80000000u
#define MPU_WORD_M7RE_SHIFT                      31
/* RGDAAC Bit Fields */
#define MPU_RGDAAC_M0UM_MASK                     0x7u
#define MPU_RGDAAC_M0UM_SHIFT                    0
#define MPU_RGDAAC_M0UM(x)                       (((x)<<MPU_RGDAAC_M0UM_SHIFT)&MPU_RGDAAC_M0UM_MASK)
#define MPU_RGDAAC_M0SM_MASK                     0x18u
#define MPU_RGDAAC_M0SM_SHIFT                    3
#define MPU_RGDAAC_M0SM(x)                       (((x)<<MPU_RGDAAC_M0SM_SHIFT)&MPU_RGDAAC_M0SM_MASK)
#define MPU_RGDAAC_M1UM_MASK                     0x1C0u
#define MPU_RGDAAC_M1UM_SHIFT                    6
#define MPU_RGDAAC_M1UM(x)                       (((x)<<MPU_RGDAAC_M1UM_SHIFT)&MPU_RGDAAC_M1UM_MASK)
#define MPU_RGDAAC_M1SM_MASK                     0x600u
#define MPU_RGDAAC_M1SM_SHIFT                    9
#define MPU_RGDAAC_M1SM(x)                       (((x)<<MPU_RGDAAC_M1SM_SHIFT)&MPU_RGDAAC_M1SM_MASK)
#define MPU_RGDAAC_M2UM_MASK                     0x7000u
#define MPU_RGDAAC_M2UM_SHIFT                    12
#define MPU_RGDAAC_M2UM(x)                       (((x)<<MPU_RGDAAC_M2UM_SHIFT)&MPU_RGDAAC_M2UM_MASK)
#define MPU_RGDAAC_M2SM_MASK                     0x18000u
#define MPU_RGDAAC_M2SM_SHIFT                    15
#define MPU_RGDAAC_M2SM(x)                       (((x)<<MPU_RGDAAC_M2SM_SHIFT)&MPU_RGDAAC_M2SM_MASK)
#define MPU_RGDAAC_M3UM_MASK                     0x1C0000u
#define MPU_RGDAAC_M3UM_SHIFT                    18
#define MPU_RGDAAC_M3UM(x)                       (((x)<<MPU_RGDAAC_M3UM_SHIFT)&MPU_RGDAAC_M3UM_MASK)
#define MPU_RGDAAC_M3SM_MASK                     0x600000u
#define MPU_RGDAAC_M3SM_SHIFT                    21
#define MPU_RGDAAC_M3SM(x)                       (((x)<<MPU_RGDAAC_M3SM_SHIFT)&MPU_RGDAAC_M3SM_MASK)
#define MPU_RGDAAC_M4WE_MASK                     0x1000000u
#define MPU_RGDAAC_M4WE_SHIFT                    24
#define MPU_RGDAAC_M4RE_MASK                     0x2000000u
#define MPU_RGDAAC_M4RE_SHIFT                    25
#define MPU_RGDAAC_M5WE_MASK                     0x4000000u
#define MPU_RGDAAC_M5WE_SHIFT                    26
#define MPU_RGDAAC_M5RE_MASK                     0x8000000u
#define MPU_RGDAAC_M5RE_SHIFT                    27
#define MPU_RGDAAC_M6WE_MASK                     0x10000000u
#define MPU_RGDAAC_M6WE_SHIFT                    28
#define MPU_RGDAAC_M6RE_MASK                     0x20000000u
#define MPU_RGDAAC_M6RE_SHIFT                    29
#define MPU_RGDAAC_M7WE_MASK                     0x40000000u
#define MPU_RGDAAC_M7WE_SHIFT                    30
#define MPU_RGDAAC_M7RE_MASK                     0x80000000u
#define MPU_RGDAAC_M7RE_SHIFT                    31

/*! \} */ /* end of group MPU_Register_Masks */


/* MPU - Peripheral instance base addresses */
/*! Peripheral MPU base pointer */
#define MPU_BASE_PTR                             ((MPU_MemMapPtr)0x4000D000u)

/* ----------------------------------------------------------------------------
   -- MPU - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup MPU_Register_Accessor_Macros MPU - Register accessor macros */
/*! \{ */


/* MPU - Register instance definitions */
/* MPU */
#define MPU_CESR                                 MPU_CESR_REG(MPU_BASE_PTR)
#define MPU_EAR0                                 MPU_EAR_REG(MPU_BASE_PTR,0)
#define MPU_EDR0                                 MPU_EDR_REG(MPU_BASE_PTR,0)
#define MPU_EAR1                                 MPU_EAR_REG(MPU_BASE_PTR,1)
#define MPU_EDR1                                 MPU_EDR_REG(MPU_BASE_PTR,1)
#define MPU_EAR2                                 MPU_EAR_REG(MPU_BASE_PTR,2)
#define MPU_EDR2                                 MPU_EDR_REG(MPU_BASE_PTR,2)
#define MPU_EAR3                                 MPU_EAR_REG(MPU_BASE_PTR,3)
#define MPU_EDR3                                 MPU_EDR_REG(MPU_BASE_PTR,3)
#define MPU_EAR4                                 MPU_EAR_REG(MPU_BASE_PTR,4)
#define MPU_EDR4                                 MPU_EDR_REG(MPU_BASE_PTR,4)
#define MPU_RGD0_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,0,0)
#define MPU_RGD0_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,0,1)
#define MPU_RGD0_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,0,2)
#define MPU_RGD0_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,0,3)
#define MPU_RGD1_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,1,0)
#define MPU_RGD1_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,1,1)
#define MPU_RGD1_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,1,2)
#define MPU_RGD1_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,1,3)
#define MPU_RGD2_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,2,0)
#define MPU_RGD2_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,2,1)
#define MPU_RGD2_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,2,2)
#define MPU_RGD2_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,2,3)
#define MPU_RGD3_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,3,0)
#define MPU_RGD3_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,3,1)
#define MPU_RGD3_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,3,2)
#define MPU_RGD3_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,3,3)
#define MPU_RGD4_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,4,0)
#define MPU_RGD4_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,4,1)
#define MPU_RGD4_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,4,2)
#define MPU_RGD4_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,4,3)
#define MPU_RGD5_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,5,0)
#define MPU_RGD5_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,5,1)
#define MPU_RGD5_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,5,2)
#define MPU_RGD5_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,5,3)
#define MPU_RGD6_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,6,0)
#define MPU_RGD6_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,6,1)
#define MPU_RGD6_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,6,2)
#define MPU_RGD6_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,6,3)
#define MPU_RGD7_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,7,0)
#define MPU_RGD7_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,7,1)
#define MPU_RGD7_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,7,2)
#define MPU_RGD7_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,7,3)
#define MPU_RGD8_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,8,0)
#define MPU_RGD8_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,8,1)
#define MPU_RGD8_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,8,2)
#define MPU_RGD8_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,8,3)
#define MPU_RGD9_WORD0                           MPU_WORD_REG(MPU_BASE_PTR,9,0)
#define MPU_RGD9_WORD1                           MPU_WORD_REG(MPU_BASE_PTR,9,1)
#define MPU_RGD9_WORD2                           MPU_WORD_REG(MPU_BASE_PTR,9,2)
#define MPU_RGD9_WORD3                           MPU_WORD_REG(MPU_BASE_PTR,9,3)
#define MPU_RGD10_WORD0                          MPU_WORD_REG(MPU_BASE_PTR,10,0)
#define MPU_RGD10_WORD1                          MPU_WORD_REG(MPU_BASE_PTR,10,1)
#define MPU_RGD10_WORD2                          MPU_WORD_REG(MPU_BASE_PTR,10,2)
#define MPU_RGD10_WORD3                          MPU_WORD_REG(MPU_BASE_PTR,10,3)
#define MPU_RGD11_WORD0                          MPU_WORD_REG(MPU_BASE_PTR,11,0)
#define MPU_RGD11_WORD1                          MPU_WORD_REG(MPU_BASE_PTR,11,1)
#define MPU_RGD11_WORD2                          MPU_WORD_REG(MPU_BASE_PTR,11,2)
#define MPU_RGD11_WORD3                          MPU_WORD_REG(MPU_BASE_PTR,11,3)
#define MPU_RGDAAC0                              MPU_RGDAAC_REG(MPU_BASE_PTR,0)
#define MPU_RGDAAC1                              MPU_RGDAAC_REG(MPU_BASE_PTR,1)
#define MPU_RGDAAC2                              MPU_RGDAAC_REG(MPU_BASE_PTR,2)
#define MPU_RGDAAC3                              MPU_RGDAAC_REG(MPU_BASE_PTR,3)
#define MPU_RGDAAC4                              MPU_RGDAAC_REG(MPU_BASE_PTR,4)
#define MPU_RGDAAC5                              MPU_RGDAAC_REG(MPU_BASE_PTR,5)
#define MPU_RGDAAC6                              MPU_RGDAAC_REG(MPU_BASE_PTR,6)
#define MPU_RGDAAC7                              MPU_RGDAAC_REG(MPU_BASE_PTR,7)
#define MPU_RGDAAC8                              MPU_RGDAAC_REG(MPU_BASE_PTR,8)
#define MPU_RGDAAC9                              MPU_RGDAAC_REG(MPU_BASE_PTR,9)
#define MPU_RGDAAC10                             MPU_RGDAAC_REG(MPU_BASE_PTR,10)
#define MPU_RGDAAC11                             MPU_RGDAAC_REG(MPU_BASE_PTR,11)

/*! \} */ /* end of group MPU_Register_Accessor_Macros */


/*! \} */ /* end of group MPU_Peripheral */


/* ----------------------------------------------------------------------------
   -- NVIC
   ---------------------------------------------------------------------------- */

/*! \addtogroup NVIC_Peripheral NVIC */
/*! \{ */

/*! NVIC - Peripheral register structure */
typedef struct NVIC_MemMap {
  uint32_t ISER[4];                                /*!< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
  uint8_t RESERVED_0[112];
  uint32_t ICER[4];                                /*!< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
  uint8_t RESERVED_1[112];
  uint32_t ISPR[4];                                /*!< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
  uint8_t RESERVED_2[112];
  uint32_t ICPR[4];                                /*!< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
  uint8_t RESERVED_3[112];
  uint32_t IABR[4];                                /*!< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_4[240];
  uint8_t IP[104];                                 /*!< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
  uint8_t RESERVED_5[2712];
  uint32_t STIR[1];                                /*!< Software Trigger Interrupt Register, array offset: 0xE00, array step: 0x4 */
} volatile *NVIC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NVIC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup NVIC_Register_Accessor_Macros NVIC - Register accessor macros */
/*! \{ */


/* NVIC - Register accessors */
#define NVIC_ISER_REG(base,index)                ((base)->ISER[index])
#define NVIC_ICER_REG(base,index)                ((base)->ICER[index])
#define NVIC_ISPR_REG(base,index)                ((base)->ISPR[index])
#define NVIC_ICPR_REG(base,index)                ((base)->ICPR[index])
#define NVIC_IABR_REG(base,index)                ((base)->IABR[index])
#define NVIC_IP_REG(base,index)                  ((base)->IP[index])
#define NVIC_STIR_REG(base,index)                ((base)->STIR[index])

/*! \} */ /* end of group NVIC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NVIC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup NVIC_Register_Masks NVIC Register Masks */
/*! \{ */

/* ISER Bit Fields */
#define NVIC_ISER_SETENA_MASK                    0xFFFFFFFFu
#define NVIC_ISER_SETENA_SHIFT                   0
#define NVIC_ISER_SETENA(x)                      (((x)<<NVIC_ISER_SETENA_SHIFT)&NVIC_ISER_SETENA_MASK)
/* ICER Bit Fields */
#define NVIC_ICER_CLRENA_MASK                    0xFFFFFFFFu
#define NVIC_ICER_CLRENA_SHIFT                   0
#define NVIC_ICER_CLRENA(x)                      (((x)<<NVIC_ICER_CLRENA_SHIFT)&NVIC_ICER_CLRENA_MASK)
/* ISPR Bit Fields */
#define NVIC_ISPR_SETPEND_MASK                   0xFFFFFFFFu
#define NVIC_ISPR_SETPEND_SHIFT                  0
#define NVIC_ISPR_SETPEND(x)                     (((x)<<NVIC_ISPR_SETPEND_SHIFT)&NVIC_ISPR_SETPEND_MASK)
/* ICPR Bit Fields */
#define NVIC_ICPR_CLRPEND_MASK                   0xFFFFFFFFu
#define NVIC_ICPR_CLRPEND_SHIFT                  0
#define NVIC_ICPR_CLRPEND(x)                     (((x)<<NVIC_ICPR_CLRPEND_SHIFT)&NVIC_ICPR_CLRPEND_MASK)
/* IABR Bit Fields */
#define NVIC_IABR_ACTIVE_MASK                    0xFFFFFFFFu
#define NVIC_IABR_ACTIVE_SHIFT                   0
#define NVIC_IABR_ACTIVE(x)                      (((x)<<NVIC_IABR_ACTIVE_SHIFT)&NVIC_IABR_ACTIVE_MASK)
/* IP Bit Fields */
#define NVIC_IP_PRI0_MASK                        0xFFu
#define NVIC_IP_PRI0_SHIFT                       0
#define NVIC_IP_PRI0(x)                          (((x)<<NVIC_IP_PRI0_SHIFT)&NVIC_IP_PRI0_MASK)
#define NVIC_IP_PRI1_MASK                        0xFFu
#define NVIC_IP_PRI1_SHIFT                       0
#define NVIC_IP_PRI1(x)                          (((x)<<NVIC_IP_PRI1_SHIFT)&NVIC_IP_PRI1_MASK)
#define NVIC_IP_PRI2_MASK                        0xFFu
#define NVIC_IP_PRI2_SHIFT                       0
#define NVIC_IP_PRI2(x)                          (((x)<<NVIC_IP_PRI2_SHIFT)&NVIC_IP_PRI2_MASK)
#define NVIC_IP_PRI3_MASK                        0xFFu
#define NVIC_IP_PRI3_SHIFT                       0
#define NVIC_IP_PRI3(x)                          (((x)<<NVIC_IP_PRI3_SHIFT)&NVIC_IP_PRI3_MASK)
#define NVIC_IP_PRI4_MASK                        0xFFu
#define NVIC_IP_PRI4_SHIFT                       0
#define NVIC_IP_PRI4(x)                          (((x)<<NVIC_IP_PRI4_SHIFT)&NVIC_IP_PRI4_MASK)
#define NVIC_IP_PRI5_MASK                        0xFFu
#define NVIC_IP_PRI5_SHIFT                       0
#define NVIC_IP_PRI5(x)                          (((x)<<NVIC_IP_PRI5_SHIFT)&NVIC_IP_PRI5_MASK)
#define NVIC_IP_PRI6_MASK                        0xFFu
#define NVIC_IP_PRI6_SHIFT                       0
#define NVIC_IP_PRI6(x)                          (((x)<<NVIC_IP_PRI6_SHIFT)&NVIC_IP_PRI6_MASK)
#define NVIC_IP_PRI7_MASK                        0xFFu
#define NVIC_IP_PRI7_SHIFT                       0
#define NVIC_IP_PRI7(x)                          (((x)<<NVIC_IP_PRI7_SHIFT)&NVIC_IP_PRI7_MASK)
#define NVIC_IP_PRI8_MASK                        0xFFu
#define NVIC_IP_PRI8_SHIFT                       0
#define NVIC_IP_PRI8(x)                          (((x)<<NVIC_IP_PRI8_SHIFT)&NVIC_IP_PRI8_MASK)
#define NVIC_IP_PRI9_MASK                        0xFFu
#define NVIC_IP_PRI9_SHIFT                       0
#define NVIC_IP_PRI9(x)                          (((x)<<NVIC_IP_PRI9_SHIFT)&NVIC_IP_PRI9_MASK)
#define NVIC_IP_PRI10_MASK                       0xFFu
#define NVIC_IP_PRI10_SHIFT                      0
#define NVIC_IP_PRI10(x)                         (((x)<<NVIC_IP_PRI10_SHIFT)&NVIC_IP_PRI10_MASK)
#define NVIC_IP_PRI11_MASK                       0xFFu
#define NVIC_IP_PRI11_SHIFT                      0
#define NVIC_IP_PRI11(x)                         (((x)<<NVIC_IP_PRI11_SHIFT)&NVIC_IP_PRI11_MASK)
#define NVIC_IP_PRI12_MASK                       0xFFu
#define NVIC_IP_PRI12_SHIFT                      0
#define NVIC_IP_PRI12(x)                         (((x)<<NVIC_IP_PRI12_SHIFT)&NVIC_IP_PRI12_MASK)
#define NVIC_IP_PRI13_MASK                       0xFFu
#define NVIC_IP_PRI13_SHIFT                      0
#define NVIC_IP_PRI13(x)                         (((x)<<NVIC_IP_PRI13_SHIFT)&NVIC_IP_PRI13_MASK)
#define NVIC_IP_PRI14_MASK                       0xFFu
#define NVIC_IP_PRI14_SHIFT                      0
#define NVIC_IP_PRI14(x)                         (((x)<<NVIC_IP_PRI14_SHIFT)&NVIC_IP_PRI14_MASK)
#define NVIC_IP_PRI15_MASK                       0xFFu
#define NVIC_IP_PRI15_SHIFT                      0
#define NVIC_IP_PRI15(x)                         (((x)<<NVIC_IP_PRI15_SHIFT)&NVIC_IP_PRI15_MASK)
#define NVIC_IP_PRI16_MASK                       0xFFu
#define NVIC_IP_PRI16_SHIFT                      0
#define NVIC_IP_PRI16(x)                         (((x)<<NVIC_IP_PRI16_SHIFT)&NVIC_IP_PRI16_MASK)
#define NVIC_IP_PRI17_MASK                       0xFFu
#define NVIC_IP_PRI17_SHIFT                      0
#define NVIC_IP_PRI17(x)                         (((x)<<NVIC_IP_PRI17_SHIFT)&NVIC_IP_PRI17_MASK)
#define NVIC_IP_PRI18_MASK                       0xFFu
#define NVIC_IP_PRI18_SHIFT                      0
#define NVIC_IP_PRI18(x)                         (((x)<<NVIC_IP_PRI18_SHIFT)&NVIC_IP_PRI18_MASK)
#define NVIC_IP_PRI19_MASK                       0xFFu
#define NVIC_IP_PRI19_SHIFT                      0
#define NVIC_IP_PRI19(x)                         (((x)<<NVIC_IP_PRI19_SHIFT)&NVIC_IP_PRI19_MASK)
#define NVIC_IP_PRI20_MASK                       0xFFu
#define NVIC_IP_PRI20_SHIFT                      0
#define NVIC_IP_PRI20(x)                         (((x)<<NVIC_IP_PRI20_SHIFT)&NVIC_IP_PRI20_MASK)
#define NVIC_IP_PRI21_MASK                       0xFFu
#define NVIC_IP_PRI21_SHIFT                      0
#define NVIC_IP_PRI21(x)                         (((x)<<NVIC_IP_PRI21_SHIFT)&NVIC_IP_PRI21_MASK)
#define NVIC_IP_PRI22_MASK                       0xFFu
#define NVIC_IP_PRI22_SHIFT                      0
#define NVIC_IP_PRI22(x)                         (((x)<<NVIC_IP_PRI22_SHIFT)&NVIC_IP_PRI22_MASK)
#define NVIC_IP_PRI23_MASK                       0xFFu
#define NVIC_IP_PRI23_SHIFT                      0
#define NVIC_IP_PRI23(x)                         (((x)<<NVIC_IP_PRI23_SHIFT)&NVIC_IP_PRI23_MASK)
#define NVIC_IP_PRI24_MASK                       0xFFu
#define NVIC_IP_PRI24_SHIFT                      0
#define NVIC_IP_PRI24(x)                         (((x)<<NVIC_IP_PRI24_SHIFT)&NVIC_IP_PRI24_MASK)
#define NVIC_IP_PRI25_MASK                       0xFFu
#define NVIC_IP_PRI25_SHIFT                      0
#define NVIC_IP_PRI25(x)                         (((x)<<NVIC_IP_PRI25_SHIFT)&NVIC_IP_PRI25_MASK)
#define NVIC_IP_PRI26_MASK                       0xFFu
#define NVIC_IP_PRI26_SHIFT                      0
#define NVIC_IP_PRI26(x)                         (((x)<<NVIC_IP_PRI26_SHIFT)&NVIC_IP_PRI26_MASK)
#define NVIC_IP_PRI27_MASK                       0xFFu
#define NVIC_IP_PRI27_SHIFT                      0
#define NVIC_IP_PRI27(x)                         (((x)<<NVIC_IP_PRI27_SHIFT)&NVIC_IP_PRI27_MASK)
#define NVIC_IP_PRI28_MASK                       0xFFu
#define NVIC_IP_PRI28_SHIFT                      0
#define NVIC_IP_PRI28(x)                         (((x)<<NVIC_IP_PRI28_SHIFT)&NVIC_IP_PRI28_MASK)
#define NVIC_IP_PRI29_MASK                       0xFFu
#define NVIC_IP_PRI29_SHIFT                      0
#define NVIC_IP_PRI29(x)                         (((x)<<NVIC_IP_PRI29_SHIFT)&NVIC_IP_PRI29_MASK)
#define NVIC_IP_PRI30_MASK                       0xFFu
#define NVIC_IP_PRI30_SHIFT                      0
#define NVIC_IP_PRI30(x)                         (((x)<<NVIC_IP_PRI30_SHIFT)&NVIC_IP_PRI30_MASK)
#define NVIC_IP_PRI31_MASK                       0xFFu
#define NVIC_IP_PRI31_SHIFT                      0
#define NVIC_IP_PRI31(x)                         (((x)<<NVIC_IP_PRI31_SHIFT)&NVIC_IP_PRI31_MASK)
#define NVIC_IP_PRI32_MASK                       0xFFu
#define NVIC_IP_PRI32_SHIFT                      0
#define NVIC_IP_PRI32(x)                         (((x)<<NVIC_IP_PRI32_SHIFT)&NVIC_IP_PRI32_MASK)
#define NVIC_IP_PRI33_MASK                       0xFFu
#define NVIC_IP_PRI33_SHIFT                      0
#define NVIC_IP_PRI33(x)                         (((x)<<NVIC_IP_PRI33_SHIFT)&NVIC_IP_PRI33_MASK)
#define NVIC_IP_PRI34_MASK                       0xFFu
#define NVIC_IP_PRI34_SHIFT                      0
#define NVIC_IP_PRI34(x)                         (((x)<<NVIC_IP_PRI34_SHIFT)&NVIC_IP_PRI34_MASK)
#define NVIC_IP_PRI35_MASK                       0xFFu
#define NVIC_IP_PRI35_SHIFT                      0
#define NVIC_IP_PRI35(x)                         (((x)<<NVIC_IP_PRI35_SHIFT)&NVIC_IP_PRI35_MASK)
#define NVIC_IP_PRI36_MASK                       0xFFu
#define NVIC_IP_PRI36_SHIFT                      0
#define NVIC_IP_PRI36(x)                         (((x)<<NVIC_IP_PRI36_SHIFT)&NVIC_IP_PRI36_MASK)
#define NVIC_IP_PRI37_MASK                       0xFFu
#define NVIC_IP_PRI37_SHIFT                      0
#define NVIC_IP_PRI37(x)                         (((x)<<NVIC_IP_PRI37_SHIFT)&NVIC_IP_PRI37_MASK)
#define NVIC_IP_PRI38_MASK                       0xFFu
#define NVIC_IP_PRI38_SHIFT                      0
#define NVIC_IP_PRI38(x)                         (((x)<<NVIC_IP_PRI38_SHIFT)&NVIC_IP_PRI38_MASK)
#define NVIC_IP_PRI39_MASK                       0xFFu
#define NVIC_IP_PRI39_SHIFT                      0
#define NVIC_IP_PRI39(x)                         (((x)<<NVIC_IP_PRI39_SHIFT)&NVIC_IP_PRI39_MASK)
#define NVIC_IP_PRI40_MASK                       0xFFu
#define NVIC_IP_PRI40_SHIFT                      0
#define NVIC_IP_PRI40(x)                         (((x)<<NVIC_IP_PRI40_SHIFT)&NVIC_IP_PRI40_MASK)
#define NVIC_IP_PRI41_MASK                       0xFFu
#define NVIC_IP_PRI41_SHIFT                      0
#define NVIC_IP_PRI41(x)                         (((x)<<NVIC_IP_PRI41_SHIFT)&NVIC_IP_PRI41_MASK)
#define NVIC_IP_PRI42_MASK                       0xFFu
#define NVIC_IP_PRI42_SHIFT                      0
#define NVIC_IP_PRI42(x)                         (((x)<<NVIC_IP_PRI42_SHIFT)&NVIC_IP_PRI42_MASK)
#define NVIC_IP_PRI43_MASK                       0xFFu
#define NVIC_IP_PRI43_SHIFT                      0
#define NVIC_IP_PRI43(x)                         (((x)<<NVIC_IP_PRI43_SHIFT)&NVIC_IP_PRI43_MASK)
#define NVIC_IP_PRI44_MASK                       0xFFu
#define NVIC_IP_PRI44_SHIFT                      0
#define NVIC_IP_PRI44(x)                         (((x)<<NVIC_IP_PRI44_SHIFT)&NVIC_IP_PRI44_MASK)
#define NVIC_IP_PRI45_MASK                       0xFFu
#define NVIC_IP_PRI45_SHIFT                      0
#define NVIC_IP_PRI45(x)                         (((x)<<NVIC_IP_PRI45_SHIFT)&NVIC_IP_PRI45_MASK)
#define NVIC_IP_PRI46_MASK                       0xFFu
#define NVIC_IP_PRI46_SHIFT                      0
#define NVIC_IP_PRI46(x)                         (((x)<<NVIC_IP_PRI46_SHIFT)&NVIC_IP_PRI46_MASK)
#define NVIC_IP_PRI47_MASK                       0xFFu
#define NVIC_IP_PRI47_SHIFT                      0
#define NVIC_IP_PRI47(x)                         (((x)<<NVIC_IP_PRI47_SHIFT)&NVIC_IP_PRI47_MASK)
#define NVIC_IP_PRI48_MASK                       0xFFu
#define NVIC_IP_PRI48_SHIFT                      0
#define NVIC_IP_PRI48(x)                         (((x)<<NVIC_IP_PRI48_SHIFT)&NVIC_IP_PRI48_MASK)
#define NVIC_IP_PRI49_MASK                       0xFFu
#define NVIC_IP_PRI49_SHIFT                      0
#define NVIC_IP_PRI49(x)                         (((x)<<NVIC_IP_PRI49_SHIFT)&NVIC_IP_PRI49_MASK)
#define NVIC_IP_PRI50_MASK                       0xFFu
#define NVIC_IP_PRI50_SHIFT                      0
#define NVIC_IP_PRI50(x)                         (((x)<<NVIC_IP_PRI50_SHIFT)&NVIC_IP_PRI50_MASK)
#define NVIC_IP_PRI51_MASK                       0xFFu
#define NVIC_IP_PRI51_SHIFT                      0
#define NVIC_IP_PRI51(x)                         (((x)<<NVIC_IP_PRI51_SHIFT)&NVIC_IP_PRI51_MASK)
#define NVIC_IP_PRI52_MASK                       0xFFu
#define NVIC_IP_PRI52_SHIFT                      0
#define NVIC_IP_PRI52(x)                         (((x)<<NVIC_IP_PRI52_SHIFT)&NVIC_IP_PRI52_MASK)
#define NVIC_IP_PRI53_MASK                       0xFFu
#define NVIC_IP_PRI53_SHIFT                      0
#define NVIC_IP_PRI53(x)                         (((x)<<NVIC_IP_PRI53_SHIFT)&NVIC_IP_PRI53_MASK)
#define NVIC_IP_PRI54_MASK                       0xFFu
#define NVIC_IP_PRI54_SHIFT                      0
#define NVIC_IP_PRI54(x)                         (((x)<<NVIC_IP_PRI54_SHIFT)&NVIC_IP_PRI54_MASK)
#define NVIC_IP_PRI55_MASK                       0xFFu
#define NVIC_IP_PRI55_SHIFT                      0
#define NVIC_IP_PRI55(x)                         (((x)<<NVIC_IP_PRI55_SHIFT)&NVIC_IP_PRI55_MASK)
#define NVIC_IP_PRI56_MASK                       0xFFu
#define NVIC_IP_PRI56_SHIFT                      0
#define NVIC_IP_PRI56(x)                         (((x)<<NVIC_IP_PRI56_SHIFT)&NVIC_IP_PRI56_MASK)
#define NVIC_IP_PRI57_MASK                       0xFFu
#define NVIC_IP_PRI57_SHIFT                      0
#define NVIC_IP_PRI57(x)                         (((x)<<NVIC_IP_PRI57_SHIFT)&NVIC_IP_PRI57_MASK)
#define NVIC_IP_PRI58_MASK                       0xFFu
#define NVIC_IP_PRI58_SHIFT                      0
#define NVIC_IP_PRI58(x)                         (((x)<<NVIC_IP_PRI58_SHIFT)&NVIC_IP_PRI58_MASK)
#define NVIC_IP_PRI59_MASK                       0xFFu
#define NVIC_IP_PRI59_SHIFT                      0
#define NVIC_IP_PRI59(x)                         (((x)<<NVIC_IP_PRI59_SHIFT)&NVIC_IP_PRI59_MASK)
#define NVIC_IP_PRI60_MASK                       0xFFu
#define NVIC_IP_PRI60_SHIFT                      0
#define NVIC_IP_PRI60(x)                         (((x)<<NVIC_IP_PRI60_SHIFT)&NVIC_IP_PRI60_MASK)
#define NVIC_IP_PRI61_MASK                       0xFFu
#define NVIC_IP_PRI61_SHIFT                      0
#define NVIC_IP_PRI61(x)                         (((x)<<NVIC_IP_PRI61_SHIFT)&NVIC_IP_PRI61_MASK)
#define NVIC_IP_PRI62_MASK                       0xFFu
#define NVIC_IP_PRI62_SHIFT                      0
#define NVIC_IP_PRI62(x)                         (((x)<<NVIC_IP_PRI62_SHIFT)&NVIC_IP_PRI62_MASK)
#define NVIC_IP_PRI63_MASK                       0xFFu
#define NVIC_IP_PRI63_SHIFT                      0
#define NVIC_IP_PRI63(x)                         (((x)<<NVIC_IP_PRI63_SHIFT)&NVIC_IP_PRI63_MASK)
#define NVIC_IP_PRI64_MASK                       0xFFu
#define NVIC_IP_PRI64_SHIFT                      0
#define NVIC_IP_PRI64(x)                         (((x)<<NVIC_IP_PRI64_SHIFT)&NVIC_IP_PRI64_MASK)
#define NVIC_IP_PRI65_MASK                       0xFFu
#define NVIC_IP_PRI65_SHIFT                      0
#define NVIC_IP_PRI65(x)                         (((x)<<NVIC_IP_PRI65_SHIFT)&NVIC_IP_PRI65_MASK)
#define NVIC_IP_PRI66_MASK                       0xFFu
#define NVIC_IP_PRI66_SHIFT                      0
#define NVIC_IP_PRI66(x)                         (((x)<<NVIC_IP_PRI66_SHIFT)&NVIC_IP_PRI66_MASK)
#define NVIC_IP_PRI67_MASK                       0xFFu
#define NVIC_IP_PRI67_SHIFT                      0
#define NVIC_IP_PRI67(x)                         (((x)<<NVIC_IP_PRI67_SHIFT)&NVIC_IP_PRI67_MASK)
#define NVIC_IP_PRI68_MASK                       0xFFu
#define NVIC_IP_PRI68_SHIFT                      0
#define NVIC_IP_PRI68(x)                         (((x)<<NVIC_IP_PRI68_SHIFT)&NVIC_IP_PRI68_MASK)
#define NVIC_IP_PRI69_MASK                       0xFFu
#define NVIC_IP_PRI69_SHIFT                      0
#define NVIC_IP_PRI69(x)                         (((x)<<NVIC_IP_PRI69_SHIFT)&NVIC_IP_PRI69_MASK)
#define NVIC_IP_PRI70_MASK                       0xFFu
#define NVIC_IP_PRI70_SHIFT                      0
#define NVIC_IP_PRI70(x)                         (((x)<<NVIC_IP_PRI70_SHIFT)&NVIC_IP_PRI70_MASK)
#define NVIC_IP_PRI71_MASK                       0xFFu
#define NVIC_IP_PRI71_SHIFT                      0
#define NVIC_IP_PRI71(x)                         (((x)<<NVIC_IP_PRI71_SHIFT)&NVIC_IP_PRI71_MASK)
#define NVIC_IP_PRI72_MASK                       0xFFu
#define NVIC_IP_PRI72_SHIFT                      0
#define NVIC_IP_PRI72(x)                         (((x)<<NVIC_IP_PRI72_SHIFT)&NVIC_IP_PRI72_MASK)
#define NVIC_IP_PRI73_MASK                       0xFFu
#define NVIC_IP_PRI73_SHIFT                      0
#define NVIC_IP_PRI73(x)                         (((x)<<NVIC_IP_PRI73_SHIFT)&NVIC_IP_PRI73_MASK)
#define NVIC_IP_PRI74_MASK                       0xFFu
#define NVIC_IP_PRI74_SHIFT                      0
#define NVIC_IP_PRI74(x)                         (((x)<<NVIC_IP_PRI74_SHIFT)&NVIC_IP_PRI74_MASK)
#define NVIC_IP_PRI75_MASK                       0xFFu
#define NVIC_IP_PRI75_SHIFT                      0
#define NVIC_IP_PRI75(x)                         (((x)<<NVIC_IP_PRI75_SHIFT)&NVIC_IP_PRI75_MASK)
#define NVIC_IP_PRI76_MASK                       0xFFu
#define NVIC_IP_PRI76_SHIFT                      0
#define NVIC_IP_PRI76(x)                         (((x)<<NVIC_IP_PRI76_SHIFT)&NVIC_IP_PRI76_MASK)
#define NVIC_IP_PRI77_MASK                       0xFFu
#define NVIC_IP_PRI77_SHIFT                      0
#define NVIC_IP_PRI77(x)                         (((x)<<NVIC_IP_PRI77_SHIFT)&NVIC_IP_PRI77_MASK)
#define NVIC_IP_PRI78_MASK                       0xFFu
#define NVIC_IP_PRI78_SHIFT                      0
#define NVIC_IP_PRI78(x)                         (((x)<<NVIC_IP_PRI78_SHIFT)&NVIC_IP_PRI78_MASK)
#define NVIC_IP_PRI79_MASK                       0xFFu
#define NVIC_IP_PRI79_SHIFT                      0
#define NVIC_IP_PRI79(x)                         (((x)<<NVIC_IP_PRI79_SHIFT)&NVIC_IP_PRI79_MASK)
#define NVIC_IP_PRI80_MASK                       0xFFu
#define NVIC_IP_PRI80_SHIFT                      0
#define NVIC_IP_PRI80(x)                         (((x)<<NVIC_IP_PRI80_SHIFT)&NVIC_IP_PRI80_MASK)
#define NVIC_IP_PRI81_MASK                       0xFFu
#define NVIC_IP_PRI81_SHIFT                      0
#define NVIC_IP_PRI81(x)                         (((x)<<NVIC_IP_PRI81_SHIFT)&NVIC_IP_PRI81_MASK)
#define NVIC_IP_PRI82_MASK                       0xFFu
#define NVIC_IP_PRI82_SHIFT                      0
#define NVIC_IP_PRI82(x)                         (((x)<<NVIC_IP_PRI82_SHIFT)&NVIC_IP_PRI82_MASK)
#define NVIC_IP_PRI83_MASK                       0xFFu
#define NVIC_IP_PRI83_SHIFT                      0
#define NVIC_IP_PRI83(x)                         (((x)<<NVIC_IP_PRI83_SHIFT)&NVIC_IP_PRI83_MASK)
#define NVIC_IP_PRI84_MASK                       0xFFu
#define NVIC_IP_PRI84_SHIFT                      0
#define NVIC_IP_PRI84(x)                         (((x)<<NVIC_IP_PRI84_SHIFT)&NVIC_IP_PRI84_MASK)
#define NVIC_IP_PRI85_MASK                       0xFFu
#define NVIC_IP_PRI85_SHIFT                      0
#define NVIC_IP_PRI85(x)                         (((x)<<NVIC_IP_PRI85_SHIFT)&NVIC_IP_PRI85_MASK)
#define NVIC_IP_PRI86_MASK                       0xFFu
#define NVIC_IP_PRI86_SHIFT                      0
#define NVIC_IP_PRI86(x)                         (((x)<<NVIC_IP_PRI86_SHIFT)&NVIC_IP_PRI86_MASK)
#define NVIC_IP_PRI87_MASK                       0xFFu
#define NVIC_IP_PRI87_SHIFT                      0
#define NVIC_IP_PRI87(x)                         (((x)<<NVIC_IP_PRI87_SHIFT)&NVIC_IP_PRI87_MASK)
#define NVIC_IP_PRI88_MASK                       0xFFu
#define NVIC_IP_PRI88_SHIFT                      0
#define NVIC_IP_PRI88(x)                         (((x)<<NVIC_IP_PRI88_SHIFT)&NVIC_IP_PRI88_MASK)
#define NVIC_IP_PRI89_MASK                       0xFFu
#define NVIC_IP_PRI89_SHIFT                      0
#define NVIC_IP_PRI89(x)                         (((x)<<NVIC_IP_PRI89_SHIFT)&NVIC_IP_PRI89_MASK)
#define NVIC_IP_PRI90_MASK                       0xFFu
#define NVIC_IP_PRI90_SHIFT                      0
#define NVIC_IP_PRI90(x)                         (((x)<<NVIC_IP_PRI90_SHIFT)&NVIC_IP_PRI90_MASK)
#define NVIC_IP_PRI91_MASK                       0xFFu
#define NVIC_IP_PRI91_SHIFT                      0
#define NVIC_IP_PRI91(x)                         (((x)<<NVIC_IP_PRI91_SHIFT)&NVIC_IP_PRI91_MASK)
#define NVIC_IP_PRI92_MASK                       0xFFu
#define NVIC_IP_PRI92_SHIFT                      0
#define NVIC_IP_PRI92(x)                         (((x)<<NVIC_IP_PRI92_SHIFT)&NVIC_IP_PRI92_MASK)
#define NVIC_IP_PRI93_MASK                       0xFFu
#define NVIC_IP_PRI93_SHIFT                      0
#define NVIC_IP_PRI93(x)                         (((x)<<NVIC_IP_PRI93_SHIFT)&NVIC_IP_PRI93_MASK)
#define NVIC_IP_PRI94_MASK                       0xFFu
#define NVIC_IP_PRI94_SHIFT                      0
#define NVIC_IP_PRI94(x)                         (((x)<<NVIC_IP_PRI94_SHIFT)&NVIC_IP_PRI94_MASK)
#define NVIC_IP_PRI95_MASK                       0xFFu
#define NVIC_IP_PRI95_SHIFT                      0
#define NVIC_IP_PRI95(x)                         (((x)<<NVIC_IP_PRI95_SHIFT)&NVIC_IP_PRI95_MASK)
#define NVIC_IP_PRI96_MASK                       0xFFu
#define NVIC_IP_PRI96_SHIFT                      0
#define NVIC_IP_PRI96(x)                         (((x)<<NVIC_IP_PRI96_SHIFT)&NVIC_IP_PRI96_MASK)
#define NVIC_IP_PRI97_MASK                       0xFFu
#define NVIC_IP_PRI97_SHIFT                      0
#define NVIC_IP_PRI97(x)                         (((x)<<NVIC_IP_PRI97_SHIFT)&NVIC_IP_PRI97_MASK)
#define NVIC_IP_PRI98_MASK                       0xFFu
#define NVIC_IP_PRI98_SHIFT                      0
#define NVIC_IP_PRI98(x)                         (((x)<<NVIC_IP_PRI98_SHIFT)&NVIC_IP_PRI98_MASK)
#define NVIC_IP_PRI99_MASK                       0xFFu
#define NVIC_IP_PRI99_SHIFT                      0
#define NVIC_IP_PRI99(x)                         (((x)<<NVIC_IP_PRI99_SHIFT)&NVIC_IP_PRI99_MASK)
#define NVIC_IP_PRI100_MASK                      0xFFu
#define NVIC_IP_PRI100_SHIFT                     0
#define NVIC_IP_PRI100(x)                        (((x)<<NVIC_IP_PRI100_SHIFT)&NVIC_IP_PRI100_MASK)
#define NVIC_IP_PRI101_MASK                      0xFFu
#define NVIC_IP_PRI101_SHIFT                     0
#define NVIC_IP_PRI101(x)                        (((x)<<NVIC_IP_PRI101_SHIFT)&NVIC_IP_PRI101_MASK)
#define NVIC_IP_PRI102_MASK                      0xFFu
#define NVIC_IP_PRI102_SHIFT                     0
#define NVIC_IP_PRI102(x)                        (((x)<<NVIC_IP_PRI102_SHIFT)&NVIC_IP_PRI102_MASK)
#define NVIC_IP_PRI103_MASK                      0xFFu
#define NVIC_IP_PRI103_SHIFT                     0
#define NVIC_IP_PRI103(x)                        (((x)<<NVIC_IP_PRI103_SHIFT)&NVIC_IP_PRI103_MASK)
/* STIR Bit Fields */
#define NVIC_STIR_INTID_MASK                     0x1FFu
#define NVIC_STIR_INTID_SHIFT                    0
#define NVIC_STIR_INTID(x)                       (((x)<<NVIC_STIR_INTID_SHIFT)&NVIC_STIR_INTID_MASK)

/*! \} */ /* end of group NVIC_Register_Masks */


/* NVIC - Peripheral instance base addresses */
/*! Peripheral NVIC base pointer */
#define NVIC_BASE_PTR                            ((NVIC_MemMapPtr)0xE000E100u)

/* ----------------------------------------------------------------------------
   -- NVIC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup NVIC_Register_Accessor_Macros NVIC - Register accessor macros */
/*! \{ */


/* NVIC - Register instance definitions */
/* NVIC */
#define NVICISER0                                NVIC_ISER_REG(NVIC_BASE_PTR,0)
#define NVICISER1                                NVIC_ISER_REG(NVIC_BASE_PTR,1)
#define NVICISER2                                NVIC_ISER_REG(NVIC_BASE_PTR,2)
#define NVICISER3                                NVIC_ISER_REG(NVIC_BASE_PTR,3)
#define NVICICER0                                NVIC_ICER_REG(NVIC_BASE_PTR,0)
#define NVICICER1                                NVIC_ICER_REG(NVIC_BASE_PTR,1)
#define NVICICER2                                NVIC_ICER_REG(NVIC_BASE_PTR,2)
#define NVICICER3                                NVIC_ICER_REG(NVIC_BASE_PTR,3)
#define NVICISPR0                                NVIC_ISPR_REG(NVIC_BASE_PTR,0)
#define NVICISPR1                                NVIC_ISPR_REG(NVIC_BASE_PTR,1)
#define NVICISPR2                                NVIC_ISPR_REG(NVIC_BASE_PTR,2)
#define NVICISPR3                                NVIC_ISPR_REG(NVIC_BASE_PTR,3)
#define NVICICPR0                                NVIC_ICPR_REG(NVIC_BASE_PTR,0)
#define NVICICPR1                                NVIC_ICPR_REG(NVIC_BASE_PTR,1)
#define NVICICPR2                                NVIC_ICPR_REG(NVIC_BASE_PTR,2)
#define NVICICPR3                                NVIC_ICPR_REG(NVIC_BASE_PTR,3)
#define NVICIABR0                                NVIC_IABR_REG(NVIC_BASE_PTR,0)
#define NVICIABR1                                NVIC_IABR_REG(NVIC_BASE_PTR,1)
#define NVICIABR2                                NVIC_IABR_REG(NVIC_BASE_PTR,2)
#define NVICIABR3                                NVIC_IABR_REG(NVIC_BASE_PTR,3)
#define NVICIP0                                  NVIC_IP_REG(NVIC_BASE_PTR,0)
#define NVICIP1                                  NVIC_IP_REG(NVIC_BASE_PTR,1)
#define NVICIP2                                  NVIC_IP_REG(NVIC_BASE_PTR,2)
#define NVICIP3                                  NVIC_IP_REG(NVIC_BASE_PTR,3)
#define NVICIP4                                  NVIC_IP_REG(NVIC_BASE_PTR,4)
#define NVICIP5                                  NVIC_IP_REG(NVIC_BASE_PTR,5)
#define NVICIP6                                  NVIC_IP_REG(NVIC_BASE_PTR,6)
#define NVICIP7                                  NVIC_IP_REG(NVIC_BASE_PTR,7)
#define NVICIP8                                  NVIC_IP_REG(NVIC_BASE_PTR,8)
#define NVICIP9                                  NVIC_IP_REG(NVIC_BASE_PTR,9)
#define NVICIP10                                 NVIC_IP_REG(NVIC_BASE_PTR,10)
#define NVICIP11                                 NVIC_IP_REG(NVIC_BASE_PTR,11)
#define NVICIP12                                 NVIC_IP_REG(NVIC_BASE_PTR,12)
#define NVICIP13                                 NVIC_IP_REG(NVIC_BASE_PTR,13)
#define NVICIP14                                 NVIC_IP_REG(NVIC_BASE_PTR,14)
#define NVICIP15                                 NVIC_IP_REG(NVIC_BASE_PTR,15)
#define NVICIP16                                 NVIC_IP_REG(NVIC_BASE_PTR,16)
#define NVICIP17                                 NVIC_IP_REG(NVIC_BASE_PTR,17)
#define NVICIP18                                 NVIC_IP_REG(NVIC_BASE_PTR,18)
#define NVICIP19                                 NVIC_IP_REG(NVIC_BASE_PTR,19)
#define NVICIP20                                 NVIC_IP_REG(NVIC_BASE_PTR,20)
#define NVICIP21                                 NVIC_IP_REG(NVIC_BASE_PTR,21)
#define NVICIP22                                 NVIC_IP_REG(NVIC_BASE_PTR,22)
#define NVICIP23                                 NVIC_IP_REG(NVIC_BASE_PTR,23)
#define NVICIP24                                 NVIC_IP_REG(NVIC_BASE_PTR,24)
#define NVICIP25                                 NVIC_IP_REG(NVIC_BASE_PTR,25)
#define NVICIP26                                 NVIC_IP_REG(NVIC_BASE_PTR,26)
#define NVICIP27                                 NVIC_IP_REG(NVIC_BASE_PTR,27)
#define NVICIP28                                 NVIC_IP_REG(NVIC_BASE_PTR,28)
#define NVICIP29                                 NVIC_IP_REG(NVIC_BASE_PTR,29)
#define NVICIP30                                 NVIC_IP_REG(NVIC_BASE_PTR,30)
#define NVICIP31                                 NVIC_IP_REG(NVIC_BASE_PTR,31)
#define NVICIP32                                 NVIC_IP_REG(NVIC_BASE_PTR,32)
#define NVICIP33                                 NVIC_IP_REG(NVIC_BASE_PTR,33)
#define NVICIP34                                 NVIC_IP_REG(NVIC_BASE_PTR,34)
#define NVICIP35                                 NVIC_IP_REG(NVIC_BASE_PTR,35)
#define NVICIP36                                 NVIC_IP_REG(NVIC_BASE_PTR,36)
#define NVICIP37                                 NVIC_IP_REG(NVIC_BASE_PTR,37)
#define NVICIP38                                 NVIC_IP_REG(NVIC_BASE_PTR,38)
#define NVICIP39                                 NVIC_IP_REG(NVIC_BASE_PTR,39)
#define NVICIP40                                 NVIC_IP_REG(NVIC_BASE_PTR,40)
#define NVICIP41                                 NVIC_IP_REG(NVIC_BASE_PTR,41)
#define NVICIP42                                 NVIC_IP_REG(NVIC_BASE_PTR,42)
#define NVICIP43                                 NVIC_IP_REG(NVIC_BASE_PTR,43)
#define NVICIP44                                 NVIC_IP_REG(NVIC_BASE_PTR,44)
#define NVICIP45                                 NVIC_IP_REG(NVIC_BASE_PTR,45)
#define NVICIP46                                 NVIC_IP_REG(NVIC_BASE_PTR,46)
#define NVICIP47                                 NVIC_IP_REG(NVIC_BASE_PTR,47)
#define NVICIP48                                 NVIC_IP_REG(NVIC_BASE_PTR,48)
#define NVICIP49                                 NVIC_IP_REG(NVIC_BASE_PTR,49)
#define NVICIP50                                 NVIC_IP_REG(NVIC_BASE_PTR,50)
#define NVICIP51                                 NVIC_IP_REG(NVIC_BASE_PTR,51)
#define NVICIP52                                 NVIC_IP_REG(NVIC_BASE_PTR,52)
#define NVICIP53                                 NVIC_IP_REG(NVIC_BASE_PTR,53)
#define NVICIP54                                 NVIC_IP_REG(NVIC_BASE_PTR,54)
#define NVICIP55                                 NVIC_IP_REG(NVIC_BASE_PTR,55)
#define NVICIP56                                 NVIC_IP_REG(NVIC_BASE_PTR,56)
#define NVICIP57                                 NVIC_IP_REG(NVIC_BASE_PTR,57)
#define NVICIP58                                 NVIC_IP_REG(NVIC_BASE_PTR,58)
#define NVICIP59                                 NVIC_IP_REG(NVIC_BASE_PTR,59)
#define NVICIP60                                 NVIC_IP_REG(NVIC_BASE_PTR,60)
#define NVICIP61                                 NVIC_IP_REG(NVIC_BASE_PTR,61)
#define NVICIP62                                 NVIC_IP_REG(NVIC_BASE_PTR,62)
#define NVICIP63                                 NVIC_IP_REG(NVIC_BASE_PTR,63)
#define NVICIP64                                 NVIC_IP_REG(NVIC_BASE_PTR,64)
#define NVICIP65                                 NVIC_IP_REG(NVIC_BASE_PTR,65)
#define NVICIP66                                 NVIC_IP_REG(NVIC_BASE_PTR,66)
#define NVICIP67                                 NVIC_IP_REG(NVIC_BASE_PTR,67)
#define NVICIP68                                 NVIC_IP_REG(NVIC_BASE_PTR,68)
#define NVICIP69                                 NVIC_IP_REG(NVIC_BASE_PTR,69)
#define NVICIP70                                 NVIC_IP_REG(NVIC_BASE_PTR,70)
#define NVICIP71                                 NVIC_IP_REG(NVIC_BASE_PTR,71)
#define NVICIP72                                 NVIC_IP_REG(NVIC_BASE_PTR,72)
#define NVICIP73                                 NVIC_IP_REG(NVIC_BASE_PTR,73)
#define NVICIP74                                 NVIC_IP_REG(NVIC_BASE_PTR,74)
#define NVICIP75                                 NVIC_IP_REG(NVIC_BASE_PTR,75)
#define NVICIP76                                 NVIC_IP_REG(NVIC_BASE_PTR,76)
#define NVICIP77                                 NVIC_IP_REG(NVIC_BASE_PTR,77)
#define NVICIP78                                 NVIC_IP_REG(NVIC_BASE_PTR,78)
#define NVICIP79                                 NVIC_IP_REG(NVIC_BASE_PTR,79)
#define NVICIP80                                 NVIC_IP_REG(NVIC_BASE_PTR,80)
#define NVICIP81                                 NVIC_IP_REG(NVIC_BASE_PTR,81)
#define NVICIP82                                 NVIC_IP_REG(NVIC_BASE_PTR,82)
#define NVICIP83                                 NVIC_IP_REG(NVIC_BASE_PTR,83)
#define NVICIP84                                 NVIC_IP_REG(NVIC_BASE_PTR,84)
#define NVICIP85                                 NVIC_IP_REG(NVIC_BASE_PTR,85)
#define NVICIP86                                 NVIC_IP_REG(NVIC_BASE_PTR,86)
#define NVICIP87                                 NVIC_IP_REG(NVIC_BASE_PTR,87)
#define NVICIP88                                 NVIC_IP_REG(NVIC_BASE_PTR,88)
#define NVICIP89                                 NVIC_IP_REG(NVIC_BASE_PTR,89)
#define NVICIP90                                 NVIC_IP_REG(NVIC_BASE_PTR,90)
#define NVICIP91                                 NVIC_IP_REG(NVIC_BASE_PTR,91)
#define NVICIP92                                 NVIC_IP_REG(NVIC_BASE_PTR,92)
#define NVICIP93                                 NVIC_IP_REG(NVIC_BASE_PTR,93)
#define NVICIP94                                 NVIC_IP_REG(NVIC_BASE_PTR,94)
#define NVICIP95                                 NVIC_IP_REG(NVIC_BASE_PTR,95)
#define NVICIP96                                 NVIC_IP_REG(NVIC_BASE_PTR,96)
#define NVICIP97                                 NVIC_IP_REG(NVIC_BASE_PTR,97)
#define NVICIP98                                 NVIC_IP_REG(NVIC_BASE_PTR,98)
#define NVICIP99                                 NVIC_IP_REG(NVIC_BASE_PTR,99)
#define NVICIP100                                NVIC_IP_REG(NVIC_BASE_PTR,100)
#define NVICIP101                                NVIC_IP_REG(NVIC_BASE_PTR,101)
#define NVICIP102                                NVIC_IP_REG(NVIC_BASE_PTR,102)
#define NVICIP103                                NVIC_IP_REG(NVIC_BASE_PTR,103)
#define NVICSTIR                                 NVIC_STIR_REG(NVIC_BASE_PTR,0)

/*! \} */ /* end of group NVIC_Register_Accessor_Macros */


/*! \} */ /* end of group NVIC_Peripheral */


/* ----------------------------------------------------------------------------
   -- OSC
   ---------------------------------------------------------------------------- */

/*! \addtogroup OSC_Peripheral OSC */
/*! \{ */

/*! OSC - Peripheral register structure */
typedef struct OSC_MemMap {
  uint8_t CR;                                      /*!< OSC Control Register, offset: 0x0 */
} volatile *OSC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros */
/*! \{ */


/* OSC - Register accessors */
#define OSC_CR_REG(base)                         ((base)->CR)

/*! \} */ /* end of group OSC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- OSC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup OSC_Register_Masks OSC Register Masks */
/*! \{ */

/* CR Bit Fields */
#define OSC_CR_SC16P_MASK                        0x1u
#define OSC_CR_SC16P_SHIFT                       0
#define OSC_CR_SC8P_MASK                         0x2u
#define OSC_CR_SC8P_SHIFT                        1
#define OSC_CR_SC4P_MASK                         0x4u
#define OSC_CR_SC4P_SHIFT                        2
#define OSC_CR_SC2P_MASK                         0x8u
#define OSC_CR_SC2P_SHIFT                        3
#define OSC_CR_EREFSTEN_MASK                     0x20u
#define OSC_CR_EREFSTEN_SHIFT                    5
#define OSC_CR_ERCLKEN_MASK                      0x80u
#define OSC_CR_ERCLKEN_SHIFT                     7

/*! \} */ /* end of group OSC_Register_Masks */


/* OSC - Peripheral instance base addresses */
/*! Peripheral OSC base pointer */
#define OSC_BASE_PTR                             ((OSC_MemMapPtr)0x40065000u)

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros */
/*! \{ */


/* OSC - Register instance definitions */
/* OSC */
#define OSC_CR                                   OSC_CR_REG(OSC_BASE_PTR)

/*! \} */ /* end of group OSC_Register_Accessor_Macros */


/*! \} */ /* end of group OSC_Peripheral */


/* ----------------------------------------------------------------------------
   -- PDB
   ---------------------------------------------------------------------------- */

/*! \addtogroup PDB_Peripheral PDB */
/*! \{ */

/*! PDB - Peripheral register structure */
typedef struct PDB_MemMap {
  uint32_t SC;                                     /*!< Status and Control Register, offset: 0x0 */
  uint32_t MOD;                                    /*!< Modulus Register, offset: 0x4 */
  uint32_t CNT;                                    /*!< Counter Register, offset: 0x8 */
  uint32_t IDLY;                                   /*!< Interrupt Delay Register, offset: 0xC */
  uint32_t CH0C1;                                  /*!< Channel n Control Register 1, offset: 0x10 */
  uint32_t CH0S;                                   /*!< Channel n Status Register, offset: 0x14 */
  uint32_t CH0DLY0;                                /*!< Channel n Delay 0 Register, offset: 0x18 */
  uint32_t CH0DLY1;                                /*!< Channel n Delay 1 Register, offset: 0x1C */
  uint8_t RESERVED_0[24];
  uint32_t CH1C1;                                  /*!< Channel n Control Register 1, offset: 0x38 */
  uint32_t CH1S;                                   /*!< Channel n Status Register, offset: 0x3C */
  uint32_t CH1DLY0;                                /*!< Channel n Delay 0 Register, offset: 0x40 */
  uint32_t CH1DLY1;                                /*!< Channel n Delay 1 Register, offset: 0x44 */
  uint8_t RESERVED_1[264];
  uint32_t DACINTC0;                               /*!< DAC Interval Trigger n Control Register, offset: 0x150 */
  uint32_t DACINT0;                                /*!< DAC Interval n Register, offset: 0x154 */
  uint32_t DACINTC1;                               /*!< DAC Interval Trigger n Control Register, offset: 0x158 */
  uint32_t DACINT1;                                /*!< DAC Interval n Register, offset: 0x15C */
  uint8_t RESERVED_2[48];
  uint32_t POEN;                                   /*!< Pulse-Out n Enable Register, offset: 0x190 */
  uint32_t PODLY;                                  /*!< Pulse-Out n Delay Register, offset: 0x194 */
} volatile *PDB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PDB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PDB_Register_Accessor_Macros PDB - Register accessor macros */
/*! \{ */


/* PDB - Register accessors */
#define PDB_SC_REG(base)                         ((base)->SC)
#define PDB_MOD_REG(base)                        ((base)->MOD)
#define PDB_CNT_REG(base)                        ((base)->CNT)
#define PDB_IDLY_REG(base)                       ((base)->IDLY)
#define PDB_CH0C1_REG(base)                      ((base)->CH0C1)
#define PDB_CH0S_REG(base)                       ((base)->CH0S)
#define PDB_CH0DLY0_REG(base)                    ((base)->CH0DLY0)
#define PDB_CH0DLY1_REG(base)                    ((base)->CH0DLY1)
#define PDB_CH1C1_REG(base)                      ((base)->CH1C1)
#define PDB_CH1S_REG(base)                       ((base)->CH1S)
#define PDB_CH1DLY0_REG(base)                    ((base)->CH1DLY0)
#define PDB_CH1DLY1_REG(base)                    ((base)->CH1DLY1)
#define PDB_DACINTC0_REG(base)                   ((base)->DACINTC0)
#define PDB_DACINT0_REG(base)                    ((base)->DACINT0)
#define PDB_DACINTC1_REG(base)                   ((base)->DACINTC1)
#define PDB_DACINT1_REG(base)                    ((base)->DACINT1)
#define PDB_POEN_REG(base)                       ((base)->POEN)
#define PDB_PODLY_REG(base)                      ((base)->PODLY)

/*! \} */ /* end of group PDB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PDB Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup PDB_Register_Masks PDB Register Masks */
/*! \{ */

/* SC Bit Fields */
#define PDB_SC_LDOK_MASK                         0x1u
#define PDB_SC_LDOK_SHIFT                        0
#define PDB_SC_CONT_MASK                         0x2u
#define PDB_SC_CONT_SHIFT                        1
#define PDB_SC_MULT_MASK                         0xCu
#define PDB_SC_MULT_SHIFT                        2
#define PDB_SC_MULT(x)                           (((x)<<PDB_SC_MULT_SHIFT)&PDB_SC_MULT_MASK)
#define PDB_SC_PDBIE_MASK                        0x20u
#define PDB_SC_PDBIE_SHIFT                       5
#define PDB_SC_PDBIF_MASK                        0x40u
#define PDB_SC_PDBIF_SHIFT                       6
#define PDB_SC_PDBEN_MASK                        0x80u
#define PDB_SC_PDBEN_SHIFT                       7
#define PDB_SC_TRGSEL_MASK                       0xF00u
#define PDB_SC_TRGSEL_SHIFT                      8
#define PDB_SC_TRGSEL(x)                         (((x)<<PDB_SC_TRGSEL_SHIFT)&PDB_SC_TRGSEL_MASK)
#define PDB_SC_PRESCALER_MASK                    0x7000u
#define PDB_SC_PRESCALER_SHIFT                   12
#define PDB_SC_PRESCALER(x)                      (((x)<<PDB_SC_PRESCALER_SHIFT)&PDB_SC_PRESCALER_MASK)
#define PDB_SC_DMAEN_MASK                        0x8000u
#define PDB_SC_DMAEN_SHIFT                       15
#define PDB_SC_SWTRIG_MASK                       0x10000u
#define PDB_SC_SWTRIG_SHIFT                      16
#define PDB_SC_PDBEIE_MASK                       0x20000u
#define PDB_SC_PDBEIE_SHIFT                      17
#define PDB_SC_LDMOD_MASK                        0xC0000u
#define PDB_SC_LDMOD_SHIFT                       18
#define PDB_SC_LDMOD(x)                          (((x)<<PDB_SC_LDMOD_SHIFT)&PDB_SC_LDMOD_MASK)
/* MOD Bit Fields */
#define PDB_MOD_MOD_MASK                         0xFFFFu
#define PDB_MOD_MOD_SHIFT                        0
#define PDB_MOD_MOD(x)                           (((x)<<PDB_MOD_MOD_SHIFT)&PDB_MOD_MOD_MASK)
/* CNT Bit Fields */
#define PDB_CNT_CNT_MASK                         0xFFFFu
#define PDB_CNT_CNT_SHIFT                        0
#define PDB_CNT_CNT(x)                           (((x)<<PDB_CNT_CNT_SHIFT)&PDB_CNT_CNT_MASK)
/* IDLY Bit Fields */
#define PDB_IDLY_IDLY_MASK                       0xFFFFu
#define PDB_IDLY_IDLY_SHIFT                      0
#define PDB_IDLY_IDLY(x)                         (((x)<<PDB_IDLY_IDLY_SHIFT)&PDB_IDLY_IDLY_MASK)
/* CH0C1 Bit Fields */
#define PDB_CH0C1_EN_MASK                        0xFFu
#define PDB_CH0C1_EN_SHIFT                       0
#define PDB_CH0C1_EN(x)                          (((x)<<PDB_CH0C1_EN_SHIFT)&PDB_CH0C1_EN_MASK)
#define PDB_CH0C1_TOS_MASK                       0xFF00u
#define PDB_CH0C1_TOS_SHIFT                      8
#define PDB_CH0C1_TOS(x)                         (((x)<<PDB_CH0C1_TOS_SHIFT)&PDB_CH0C1_TOS_MASK)
#define PDB_CH0C1_BB_MASK                        0xFF0000u
#define PDB_CH0C1_BB_SHIFT                       16
#define PDB_CH0C1_BB(x)                          (((x)<<PDB_CH0C1_BB_SHIFT)&PDB_CH0C1_BB_MASK)
/* CH0S Bit Fields */
#define PDB_CH0S_ERR_MASK                        0xFFu
#define PDB_CH0S_ERR_SHIFT                       0
#define PDB_CH0S_ERR(x)                          (((x)<<PDB_CH0S_ERR_SHIFT)&PDB_CH0S_ERR_MASK)
#define PDB_CH0S_CF_MASK                         0xFF0000u
#define PDB_CH0S_CF_SHIFT                        16
#define PDB_CH0S_CF(x)                           (((x)<<PDB_CH0S_CF_SHIFT)&PDB_CH0S_CF_MASK)
/* CH0DLY0 Bit Fields */
#define PDB_CH0DLY0_DLY_MASK                     0xFFFFu
#define PDB_CH0DLY0_DLY_SHIFT                    0
#define PDB_CH0DLY0_DLY(x)                       (((x)<<PDB_CH0DLY0_DLY_SHIFT)&PDB_CH0DLY0_DLY_MASK)
/* CH0DLY1 Bit Fields */
#define PDB_CH0DLY1_DLY_MASK                     0xFFFFu
#define PDB_CH0DLY1_DLY_SHIFT                    0
#define PDB_CH0DLY1_DLY(x)                       (((x)<<PDB_CH0DLY1_DLY_SHIFT)&PDB_CH0DLY1_DLY_MASK)
/* CH1C1 Bit Fields */
#define PDB_CH1C1_EN_MASK                        0xFFu
#define PDB_CH1C1_EN_SHIFT                       0
#define PDB_CH1C1_EN(x)                          (((x)<<PDB_CH1C1_EN_SHIFT)&PDB_CH1C1_EN_MASK)
#define PDB_CH1C1_TOS_MASK                       0xFF00u
#define PDB_CH1C1_TOS_SHIFT                      8
#define PDB_CH1C1_TOS(x)                         (((x)<<PDB_CH1C1_TOS_SHIFT)&PDB_CH1C1_TOS_MASK)
#define PDB_CH1C1_BB_MASK                        0xFF0000u
#define PDB_CH1C1_BB_SHIFT                       16
#define PDB_CH1C1_BB(x)                          (((x)<<PDB_CH1C1_BB_SHIFT)&PDB_CH1C1_BB_MASK)
/* CH1S Bit Fields */
#define PDB_CH1S_ERR_MASK                        0xFFu
#define PDB_CH1S_ERR_SHIFT                       0
#define PDB_CH1S_ERR(x)                          (((x)<<PDB_CH1S_ERR_SHIFT)&PDB_CH1S_ERR_MASK)
#define PDB_CH1S_CF_MASK                         0xFF0000u
#define PDB_CH1S_CF_SHIFT                        16
#define PDB_CH1S_CF(x)                           (((x)<<PDB_CH1S_CF_SHIFT)&PDB_CH1S_CF_MASK)
/* CH1DLY0 Bit Fields */
#define PDB_CH1DLY0_DLY_MASK                     0xFFFFu
#define PDB_CH1DLY0_DLY_SHIFT                    0
#define PDB_CH1DLY0_DLY(x)                       (((x)<<PDB_CH1DLY0_DLY_SHIFT)&PDB_CH1DLY0_DLY_MASK)
/* CH1DLY1 Bit Fields */
#define PDB_CH1DLY1_DLY_MASK                     0xFFFFu
#define PDB_CH1DLY1_DLY_SHIFT                    0
#define PDB_CH1DLY1_DLY(x)                       (((x)<<PDB_CH1DLY1_DLY_SHIFT)&PDB_CH1DLY1_DLY_MASK)
/* DACINTC0 Bit Fields */
#define PDB_DACINTC0_TOE_MASK                    0x1u
#define PDB_DACINTC0_TOE_SHIFT                   0
#define PDB_DACINTC0_EXT_MASK                    0x2u
#define PDB_DACINTC0_EXT_SHIFT                   1
/* DACINT0 Bit Fields */
#define PDB_DACINT0_INT_MASK                     0xFFFFu
#define PDB_DACINT0_INT_SHIFT                    0
#define PDB_DACINT0_INT(x)                       (((x)<<PDB_DACINT0_INT_SHIFT)&PDB_DACINT0_INT_MASK)
/* DACINTC1 Bit Fields */
#define PDB_DACINTC1_TOE_MASK                    0x1u
#define PDB_DACINTC1_TOE_SHIFT                   0
#define PDB_DACINTC1_EXT_MASK                    0x2u
#define PDB_DACINTC1_EXT_SHIFT                   1
/* DACINT1 Bit Fields */
#define PDB_DACINT1_INT_MASK                     0xFFFFu
#define PDB_DACINT1_INT_SHIFT                    0
#define PDB_DACINT1_INT(x)                       (((x)<<PDB_DACINT1_INT_SHIFT)&PDB_DACINT1_INT_MASK)
/* POEN Bit Fields */
#define PDB_POEN_POEN_MASK                       0xFFu
#define PDB_POEN_POEN_SHIFT                      0
#define PDB_POEN_POEN(x)                         (((x)<<PDB_POEN_POEN_SHIFT)&PDB_POEN_POEN_MASK)
/* PODLY Bit Fields */
#define PDB_PODLY_DLY2_MASK                      0xFFFFu
#define PDB_PODLY_DLY2_SHIFT                     0
#define PDB_PODLY_DLY2(x)                        (((x)<<PDB_PODLY_DLY2_SHIFT)&PDB_PODLY_DLY2_MASK)
#define PDB_PODLY_DLY1_MASK                      0xFFFF0000u
#define PDB_PODLY_DLY1_SHIFT                     16
#define PDB_PODLY_DLY1(x)                        (((x)<<PDB_PODLY_DLY1_SHIFT)&PDB_PODLY_DLY1_MASK)

/*! \} */ /* end of group PDB_Register_Masks */


/* PDB - Peripheral instance base addresses */
/*! Peripheral PDB0 base pointer */
#define PDB0_BASE_PTR                            ((PDB_MemMapPtr)0x40036000u)

/* ----------------------------------------------------------------------------
   -- PDB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PDB_Register_Accessor_Macros PDB - Register accessor macros */
/*! \{ */


/* PDB - Register instance definitions */
/* PDB0 */
#define PDB_SC                                   PDB_SC_REG(PDB0_BASE_PTR)
#define PDB_MOD                                  PDB_MOD_REG(PDB0_BASE_PTR)
#define PDB_CNT                                  PDB_CNT_REG(PDB0_BASE_PTR)
#define PDB_IDLY                                 PDB_IDLY_REG(PDB0_BASE_PTR)
#define PDB_CH0C1                                PDB_CH0C1_REG(PDB0_BASE_PTR)
#define PDB_CH0S                                 PDB_CH0S_REG(PDB0_BASE_PTR)
#define PDB_CH0DLY0                              PDB_CH0DLY0_REG(PDB0_BASE_PTR)
#define PDB_CH0DLY1                              PDB_CH0DLY1_REG(PDB0_BASE_PTR)
#define PDB_CH1C1                                PDB_CH1C1_REG(PDB0_BASE_PTR)
#define PDB_CH1S                                 PDB_CH1S_REG(PDB0_BASE_PTR)
#define PDB_CH1DLY0                              PDB_CH1DLY0_REG(PDB0_BASE_PTR)
#define PDB_CH1DLY1                              PDB_CH1DLY1_REG(PDB0_BASE_PTR)
#define PDB_DACINTC0                             PDB_DACINTC0_REG(PDB0_BASE_PTR)
#define PDB_DACINT0                              PDB_DACINT0_REG(PDB0_BASE_PTR)
#define PDB_DACINTC1                             PDB_DACINTC1_REG(PDB0_BASE_PTR)
#define PDB_DACINT1                              PDB_DACINT1_REG(PDB0_BASE_PTR)
#define PDB_PO0EN                                PDB_POEN_REG(PDB0_BASE_PTR)
#define PDB_PO0DLY                               PDB_PODLY_REG(PDB0_BASE_PTR)

/*! \} */ /* end of group PDB_Register_Accessor_Macros */


/*! \} */ /* end of group PDB_Peripheral */


/* ----------------------------------------------------------------------------
   -- PIT
   ---------------------------------------------------------------------------- */

/*! \addtogroup PIT_Peripheral PIT */
/*! \{ */

/*! PIT - Peripheral register structure */
typedef struct PIT_MemMap {
  uint32_t MCR;                                    /*!< PIT Module Control Register, offset: 0x0 */
  uint8_t RESERVED_0[252];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    uint32_t LDVAL;                                  /*!< Timer Load Value Register, array offset: 0x100, array step: 0x10 */
    uint32_t CVAL;                                   /*!< Current Timer Value Register, array offset: 0x104, array step: 0x10 */
    uint32_t TCTRL;                                  /*!< Timer Control Register, array offset: 0x108, array step: 0x10 */
    uint32_t TFLG;                                   /*!< Timer Flag Register, array offset: 0x10C, array step: 0x10 */
  } CHANNEL[4];
} volatile *PIT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros */
/*! \{ */


/* PIT - Register accessors */
#define PIT_MCR_REG(base)                        ((base)->MCR)
#define PIT_LDVAL_REG(base,index)                ((base)->CHANNEL[index].LDVAL)
#define PIT_CVAL_REG(base,index)                 ((base)->CHANNEL[index].CVAL)
#define PIT_TCTRL_REG(base,index)                ((base)->CHANNEL[index].TCTRL)
#define PIT_TFLG_REG(base,index)                 ((base)->CHANNEL[index].TFLG)

/*! \} */ /* end of group PIT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup PIT_Register_Masks PIT Register Masks */
/*! \{ */

/* MCR Bit Fields */
#define PIT_MCR_FRZ_MASK                         0x1u
#define PIT_MCR_FRZ_SHIFT                        0
#define PIT_MCR_MDIS_MASK                        0x2u
#define PIT_MCR_MDIS_SHIFT                       1
/* LDVAL Bit Fields */
#define PIT_LDVAL_TSV_MASK                       0xFFFFFFFFu
#define PIT_LDVAL_TSV_SHIFT                      0
#define PIT_LDVAL_TSV(x)                         (((x)<<PIT_LDVAL_TSV_SHIFT)&PIT_LDVAL_TSV_MASK)
/* CVAL Bit Fields */
#define PIT_CVAL_TVL_MASK                        0xFFFFFFFFu
#define PIT_CVAL_TVL_SHIFT                       0
#define PIT_CVAL_TVL(x)                          (((x)<<PIT_CVAL_TVL_SHIFT)&PIT_CVAL_TVL_MASK)
/* TCTRL Bit Fields */
#define PIT_TCTRL_TEN_MASK                       0x1u
#define PIT_TCTRL_TEN_SHIFT                      0
#define PIT_TCTRL_TIE_MASK                       0x2u
#define PIT_TCTRL_TIE_SHIFT                      1
/* TFLG Bit Fields */
#define PIT_TFLG_TIF_MASK                        0x1u
#define PIT_TFLG_TIF_SHIFT                       0

/*! \} */ /* end of group PIT_Register_Masks */


/* PIT - Peripheral instance base addresses */
/*! Peripheral PIT base pointer */
#define PIT_BASE_PTR                             ((PIT_MemMapPtr)0x40037000u)

/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros */
/*! \{ */


/* PIT - Register instance definitions */
/* PIT */
#define PIT_MCR                                  PIT_MCR_REG(PIT_BASE_PTR)
#define PIT_LDVAL0                               PIT_LDVAL_REG(PIT_BASE_PTR,0)
#define PIT_CVAL0                                PIT_CVAL_REG(PIT_BASE_PTR,0)
#define PIT_TCTRL0                               PIT_TCTRL_REG(PIT_BASE_PTR,0)
#define PIT_TFLG0                                PIT_TFLG_REG(PIT_BASE_PTR,0)
#define PIT_LDVAL1                               PIT_LDVAL_REG(PIT_BASE_PTR,1)
#define PIT_CVAL1                                PIT_CVAL_REG(PIT_BASE_PTR,1)
#define PIT_TCTRL1                               PIT_TCTRL_REG(PIT_BASE_PTR,1)
#define PIT_TFLG1                                PIT_TFLG_REG(PIT_BASE_PTR,1)
#define PIT_LDVAL2                               PIT_LDVAL_REG(PIT_BASE_PTR,2)
#define PIT_CVAL2                                PIT_CVAL_REG(PIT_BASE_PTR,2)
#define PIT_TCTRL2                               PIT_TCTRL_REG(PIT_BASE_PTR,2)
#define PIT_TFLG2                                PIT_TFLG_REG(PIT_BASE_PTR,2)
#define PIT_LDVAL3                               PIT_LDVAL_REG(PIT_BASE_PTR,3)
#define PIT_CVAL3                                PIT_CVAL_REG(PIT_BASE_PTR,3)
#define PIT_TCTRL3                               PIT_TCTRL_REG(PIT_BASE_PTR,3)
#define PIT_TFLG3                                PIT_TFLG_REG(PIT_BASE_PTR,3)

/*! \} */ /* end of group PIT_Register_Accessor_Macros */


/*! \} */ /* end of group PIT_Peripheral */


/* ----------------------------------------------------------------------------
   -- PMC
   ---------------------------------------------------------------------------- */

/*! \addtogroup PMC_Peripheral PMC */
/*! \{ */

/*! PMC - Peripheral register structure */
typedef struct PMC_MemMap {
  uint8_t LVDSC1;                                  /*!< Low Voltage Detect Status and Control 1 Register, offset: 0x0 */
  uint8_t LVDSC2;                                  /*!< Low Voltage Detect Status and Control 2 Register, offset: 0x1 */
  uint8_t REGSC;                                   /*!< Regulator Status and Control Register, offset: 0x2 */
} volatile *PMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros */
/*! \{ */


/* PMC - Register accessors */
#define PMC_LVDSC1_REG(base)                     ((base)->LVDSC1)
#define PMC_LVDSC2_REG(base)                     ((base)->LVDSC2)
#define PMC_REGSC_REG(base)                      ((base)->REGSC)

/*! \} */ /* end of group PMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup PMC_Register_Masks PMC Register Masks */
/*! \{ */

/* LVDSC1 Bit Fields */
#define PMC_LVDSC1_LVDV_MASK                     0x3u
#define PMC_LVDSC1_LVDV_SHIFT                    0
#define PMC_LVDSC1_LVDV(x)                       (((x)<<PMC_LVDSC1_LVDV_SHIFT)&PMC_LVDSC1_LVDV_MASK)
#define PMC_LVDSC1_LVDRE_MASK                    0x10u
#define PMC_LVDSC1_LVDRE_SHIFT                   4
#define PMC_LVDSC1_LVDIE_MASK                    0x20u
#define PMC_LVDSC1_LVDIE_SHIFT                   5
#define PMC_LVDSC1_LVDACK_MASK                   0x40u
#define PMC_LVDSC1_LVDACK_SHIFT                  6
#define PMC_LVDSC1_LVDF_MASK                     0x80u
#define PMC_LVDSC1_LVDF_SHIFT                    7
/* LVDSC2 Bit Fields */
#define PMC_LVDSC2_LVWV_MASK                     0x3u
#define PMC_LVDSC2_LVWV_SHIFT                    0
#define PMC_LVDSC2_LVWV(x)                       (((x)<<PMC_LVDSC2_LVWV_SHIFT)&PMC_LVDSC2_LVWV_MASK)
#define PMC_LVDSC2_LVWIE_MASK                    0x20u
#define PMC_LVDSC2_LVWIE_SHIFT                   5
#define PMC_LVDSC2_LVWACK_MASK                   0x40u
#define PMC_LVDSC2_LVWACK_SHIFT                  6
#define PMC_LVDSC2_LVWF_MASK                     0x80u
#define PMC_LVDSC2_LVWF_SHIFT                    7
/* REGSC Bit Fields */
#define PMC_REGSC_BGBE_MASK                      0x1u
#define PMC_REGSC_BGBE_SHIFT                     0
#define PMC_REGSC_REGONS_MASK                    0x4u
#define PMC_REGSC_REGONS_SHIFT                   2
#define PMC_REGSC_VLPRS_MASK                     0x8u
#define PMC_REGSC_VLPRS_SHIFT                    3
#define PMC_REGSC_TRAMPO_MASK                    0x10u
#define PMC_REGSC_TRAMPO_SHIFT                   4

/*! \} */ /* end of group PMC_Register_Masks */


/* PMC - Peripheral instance base addresses */
/*! Peripheral PMC base pointer */
#define PMC_BASE_PTR                             ((PMC_MemMapPtr)0x4007D000u)

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros */
/*! \{ */


/* PMC - Register instance definitions */
/* PMC */
#define PMC_LVDSC1                               PMC_LVDSC1_REG(PMC_BASE_PTR)
#define PMC_LVDSC2                               PMC_LVDSC2_REG(PMC_BASE_PTR)
#define PMC_REGSC                                PMC_REGSC_REG(PMC_BASE_PTR)

/*! \} */ /* end of group PMC_Register_Accessor_Macros */


/*! \} */ /* end of group PMC_Peripheral */


/* ----------------------------------------------------------------------------
   -- PORT
   ---------------------------------------------------------------------------- */

/*! \addtogroup PORT_Peripheral PORT */
/*! \{ */

/*! PORT - Peripheral register structure */
typedef struct PORT_MemMap {
  uint32_t PCR[32];                                /*!< Pin Control Register n, array offset: 0x0, array step: 0x4 */
  uint32_t GPCLR;                                  /*!< Global Pin Control Low Register, offset: 0x80 */
  uint32_t GPCHR;                                  /*!< Global Pin Control High Register, offset: 0x84 */
  uint8_t RESERVED_0[24];
  uint32_t ISFR;                                   /*!< Interrupt Status Flag Register, offset: 0xA0 */
  uint8_t RESERVED_1[28];
  uint32_t DFER;                                   /*!< Digital Filter Enable Register, offset: 0xC0 */
  uint32_t DFCR;                                   /*!< Digital Filter Clock Register, offset: 0xC4 */
  uint32_t DFWR;                                   /*!< Digital Filter Width Register, offset: 0xC8 */
} volatile *PORT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros */
/*! \{ */


/* PORT - Register accessors */
#define PORT_PCR_REG(base,index)                 ((base)->PCR[index])
#define PORT_GPCLR_REG(base)                     ((base)->GPCLR)
#define PORT_GPCHR_REG(base)                     ((base)->GPCHR)
#define PORT_ISFR_REG(base)                      ((base)->ISFR)
#define PORT_DFER_REG(base)                      ((base)->DFER)
#define PORT_DFCR_REG(base)                      ((base)->DFCR)
#define PORT_DFWR_REG(base)                      ((base)->DFWR)

/*! \} */ /* end of group PORT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup PORT_Register_Masks PORT Register Masks */
/*! \{ */

/* PCR Bit Fields */
#define PORT_PCR_PS_MASK                         0x1u
#define PORT_PCR_PS_SHIFT                        0
#define PORT_PCR_PE_MASK                         0x2u
#define PORT_PCR_PE_SHIFT                        1
#define PORT_PCR_SRE_MASK                        0x4u
#define PORT_PCR_SRE_SHIFT                       2
#define PORT_PCR_PFE_MASK                        0x10u
#define PORT_PCR_PFE_SHIFT                       4
#define PORT_PCR_ODE_MASK                        0x20u
#define PORT_PCR_ODE_SHIFT                       5
#define PORT_PCR_DSE_MASK                        0x40u
#define PORT_PCR_DSE_SHIFT                       6
#define PORT_PCR_MUX_MASK                        0x700u
#define PORT_PCR_MUX_SHIFT                       8
#define PORT_PCR_MUX(x)                          (((x)<<PORT_PCR_MUX_SHIFT)&PORT_PCR_MUX_MASK)
#define PORT_PCR_LK_MASK                         0x8000u
#define PORT_PCR_LK_SHIFT                        15
#define PORT_PCR_IRQC_MASK                       0xF0000u
#define PORT_PCR_IRQC_SHIFT                      16
#define PORT_PCR_IRQC(x)                         (((x)<<PORT_PCR_IRQC_SHIFT)&PORT_PCR_IRQC_MASK)
#define PORT_PCR_ISF_MASK                        0x1000000u
#define PORT_PCR_ISF_SHIFT                       24
/* GPCLR Bit Fields */
#define PORT_GPCLR_GPWD_MASK                     0xFFFFu
#define PORT_GPCLR_GPWD_SHIFT                    0
#define PORT_GPCLR_GPWD(x)                       (((x)<<PORT_GPCLR_GPWD_SHIFT)&PORT_GPCLR_GPWD_MASK)
#define PORT_GPCLR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCLR_GPWE_SHIFT                    16
#define PORT_GPCLR_GPWE(x)                       (((x)<<PORT_GPCLR_GPWE_SHIFT)&PORT_GPCLR_GPWE_MASK)
/* GPCHR Bit Fields */
#define PORT_GPCHR_GPWD_MASK                     0xFFFFu
#define PORT_GPCHR_GPWD_SHIFT                    0
#define PORT_GPCHR_GPWD(x)                       (((x)<<PORT_GPCHR_GPWD_SHIFT)&PORT_GPCHR_GPWD_MASK)
#define PORT_GPCHR_GPWE_MASK                     0xFFFF0000u
#define PORT_GPCHR_GPWE_SHIFT                    16
#define PORT_GPCHR_GPWE(x)                       (((x)<<PORT_GPCHR_GPWE_SHIFT)&PORT_GPCHR_GPWE_MASK)
/* ISFR Bit Fields */
#define PORT_ISFR_ISF_MASK                       0xFFFFFFFFu
#define PORT_ISFR_ISF_SHIFT                      0
#define PORT_ISFR_ISF(x)                         (((x)<<PORT_ISFR_ISF_SHIFT)&PORT_ISFR_ISF_MASK)
/* DFER Bit Fields */
#define PORT_DFER_DFE_MASK                       0xFFFFFFFFu
#define PORT_DFER_DFE_SHIFT                      0
#define PORT_DFER_DFE(x)                         (((x)<<PORT_DFER_DFE_SHIFT)&PORT_DFER_DFE_MASK)
/* DFCR Bit Fields */
#define PORT_DFCR_CS_MASK                        0x1u
#define PORT_DFCR_CS_SHIFT                       0
/* DFWR Bit Fields */
#define PORT_DFWR_FILT_MASK                      0x1Fu
#define PORT_DFWR_FILT_SHIFT                     0
#define PORT_DFWR_FILT(x)                        (((x)<<PORT_DFWR_FILT_SHIFT)&PORT_DFWR_FILT_MASK)

/*! \} */ /* end of group PORT_Register_Masks */


/* PORT - Peripheral instance base addresses */
/*! Peripheral PORTA base pointer */
#define PORTA_BASE_PTR                           ((PORT_MemMapPtr)0x40049000u)
/*! Peripheral PORTB base pointer */
#define PORTB_BASE_PTR                           ((PORT_MemMapPtr)0x4004A000u)
/*! Peripheral PORTC base pointer */
#define PORTC_BASE_PTR                           ((PORT_MemMapPtr)0x4004B000u)
/*! Peripheral PORTD base pointer */
#define PORTD_BASE_PTR                           ((PORT_MemMapPtr)0x4004C000u)
/*! Peripheral PORTE base pointer */
#define PORTE_BASE_PTR                           ((PORT_MemMapPtr)0x4004D000u)

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros */
/*! \{ */


/* PORT - Register instance definitions */
/* PORTA */
#define PORTA_PCR0                               PORT_PCR_REG(PORTA_BASE_PTR,0)
#define PORTA_PCR1                               PORT_PCR_REG(PORTA_BASE_PTR,1)
#define PORTA_PCR2                               PORT_PCR_REG(PORTA_BASE_PTR,2)
#define PORTA_PCR3                               PORT_PCR_REG(PORTA_BASE_PTR,3)
#define PORTA_PCR4                               PORT_PCR_REG(PORTA_BASE_PTR,4)
#define PORTA_PCR5                               PORT_PCR_REG(PORTA_BASE_PTR,5)
#define PORTA_PCR6                               PORT_PCR_REG(PORTA_BASE_PTR,6)
#define PORTA_PCR7                               PORT_PCR_REG(PORTA_BASE_PTR,7)
#define PORTA_PCR8                               PORT_PCR_REG(PORTA_BASE_PTR,8)
#define PORTA_PCR9                               PORT_PCR_REG(PORTA_BASE_PTR,9)
#define PORTA_PCR10                              PORT_PCR_REG(PORTA_BASE_PTR,10)
#define PORTA_PCR11                              PORT_PCR_REG(PORTA_BASE_PTR,11)
#define PORTA_PCR12                              PORT_PCR_REG(PORTA_BASE_PTR,12)
#define PORTA_PCR13                              PORT_PCR_REG(PORTA_BASE_PTR,13)
#define PORTA_PCR14                              PORT_PCR_REG(PORTA_BASE_PTR,14)
#define PORTA_PCR15                              PORT_PCR_REG(PORTA_BASE_PTR,15)
#define PORTA_PCR16                              PORT_PCR_REG(PORTA_BASE_PTR,16)
#define PORTA_PCR17                              PORT_PCR_REG(PORTA_BASE_PTR,17)
#define PORTA_PCR18                              PORT_PCR_REG(PORTA_BASE_PTR,18)
#define PORTA_PCR19                              PORT_PCR_REG(PORTA_BASE_PTR,19)
#define PORTA_PCR20                              PORT_PCR_REG(PORTA_BASE_PTR,20)
#define PORTA_PCR21                              PORT_PCR_REG(PORTA_BASE_PTR,21)
#define PORTA_PCR22                              PORT_PCR_REG(PORTA_BASE_PTR,22)
#define PORTA_PCR23                              PORT_PCR_REG(PORTA_BASE_PTR,23)
#define PORTA_PCR24                              PORT_PCR_REG(PORTA_BASE_PTR,24)
#define PORTA_PCR25                              PORT_PCR_REG(PORTA_BASE_PTR,25)
#define PORTA_PCR26                              PORT_PCR_REG(PORTA_BASE_PTR,26)
#define PORTA_PCR27                              PORT_PCR_REG(PORTA_BASE_PTR,27)
#define PORTA_PCR28                              PORT_PCR_REG(PORTA_BASE_PTR,28)
#define PORTA_PCR29                              PORT_PCR_REG(PORTA_BASE_PTR,29)
#define PORTA_PCR30                              PORT_PCR_REG(PORTA_BASE_PTR,30)
#define PORTA_PCR31                              PORT_PCR_REG(PORTA_BASE_PTR,31)
#define PORTA_GPCLR                              PORT_GPCLR_REG(PORTA_BASE_PTR)
#define PORTA_GPCHR                              PORT_GPCHR_REG(PORTA_BASE_PTR)
#define PORTA_ISFR                               PORT_ISFR_REG(PORTA_BASE_PTR)
#define PORTA_DFER                               PORT_DFER_REG(PORTA_BASE_PTR)
#define PORTA_DFCR                               PORT_DFCR_REG(PORTA_BASE_PTR)
#define PORTA_DFWR                               PORT_DFWR_REG(PORTA_BASE_PTR)
/* PORTB */
#define PORTB_PCR0                               PORT_PCR_REG(PORTB_BASE_PTR,0)
#define PORTB_PCR1                               PORT_PCR_REG(PORTB_BASE_PTR,1)
#define PORTB_PCR2                               PORT_PCR_REG(PORTB_BASE_PTR,2)
#define PORTB_PCR3                               PORT_PCR_REG(PORTB_BASE_PTR,3)
#define PORTB_PCR4                               PORT_PCR_REG(PORTB_BASE_PTR,4)
#define PORTB_PCR5                               PORT_PCR_REG(PORTB_BASE_PTR,5)
#define PORTB_PCR6                               PORT_PCR_REG(PORTB_BASE_PTR,6)
#define PORTB_PCR7                               PORT_PCR_REG(PORTB_BASE_PTR,7)
#define PORTB_PCR8                               PORT_PCR_REG(PORTB_BASE_PTR,8)
#define PORTB_PCR9                               PORT_PCR_REG(PORTB_BASE_PTR,9)
#define PORTB_PCR10                              PORT_PCR_REG(PORTB_BASE_PTR,10)
#define PORTB_PCR11                              PORT_PCR_REG(PORTB_BASE_PTR,11)
#define PORTB_PCR12                              PORT_PCR_REG(PORTB_BASE_PTR,12)
#define PORTB_PCR13                              PORT_PCR_REG(PORTB_BASE_PTR,13)
#define PORTB_PCR14                              PORT_PCR_REG(PORTB_BASE_PTR,14)
#define PORTB_PCR15                              PORT_PCR_REG(PORTB_BASE_PTR,15)
#define PORTB_PCR16                              PORT_PCR_REG(PORTB_BASE_PTR,16)
#define PORTB_PCR17                              PORT_PCR_REG(PORTB_BASE_PTR,17)
#define PORTB_PCR18                              PORT_PCR_REG(PORTB_BASE_PTR,18)
#define PORTB_PCR19                              PORT_PCR_REG(PORTB_BASE_PTR,19)
#define PORTB_PCR20                              PORT_PCR_REG(PORTB_BASE_PTR,20)
#define PORTB_PCR21                              PORT_PCR_REG(PORTB_BASE_PTR,21)
#define PORTB_PCR22                              PORT_PCR_REG(PORTB_BASE_PTR,22)
#define PORTB_PCR23                              PORT_PCR_REG(PORTB_BASE_PTR,23)
#define PORTB_PCR24                              PORT_PCR_REG(PORTB_BASE_PTR,24)
#define PORTB_PCR25                              PORT_PCR_REG(PORTB_BASE_PTR,25)
#define PORTB_PCR26                              PORT_PCR_REG(PORTB_BASE_PTR,26)
#define PORTB_PCR27                              PORT_PCR_REG(PORTB_BASE_PTR,27)
#define PORTB_PCR28                              PORT_PCR_REG(PORTB_BASE_PTR,28)
#define PORTB_PCR29                              PORT_PCR_REG(PORTB_BASE_PTR,29)
#define PORTB_PCR30                              PORT_PCR_REG(PORTB_BASE_PTR,30)
#define PORTB_PCR31                              PORT_PCR_REG(PORTB_BASE_PTR,31)
#define PORTB_GPCLR                              PORT_GPCLR_REG(PORTB_BASE_PTR)
#define PORTB_GPCHR                              PORT_GPCHR_REG(PORTB_BASE_PTR)
#define PORTB_ISFR                               PORT_ISFR_REG(PORTB_BASE_PTR)
#define PORTB_DFER                               PORT_DFER_REG(PORTB_BASE_PTR)
#define PORTB_DFCR                               PORT_DFCR_REG(PORTB_BASE_PTR)
#define PORTB_DFWR                               PORT_DFWR_REG(PORTB_BASE_PTR)
/* PORTC */
#define PORTC_PCR0                               PORT_PCR_REG(PORTC_BASE_PTR,0)
#define PORTC_PCR1                               PORT_PCR_REG(PORTC_BASE_PTR,1)
#define PORTC_PCR2                               PORT_PCR_REG(PORTC_BASE_PTR,2)
#define PORTC_PCR3                               PORT_PCR_REG(PORTC_BASE_PTR,3)
#define PORTC_PCR4                               PORT_PCR_REG(PORTC_BASE_PTR,4)
#define PORTC_PCR5                               PORT_PCR_REG(PORTC_BASE_PTR,5)
#define PORTC_PCR6                               PORT_PCR_REG(PORTC_BASE_PTR,6)
#define PORTC_PCR7                               PORT_PCR_REG(PORTC_BASE_PTR,7)
#define PORTC_PCR8                               PORT_PCR_REG(PORTC_BASE_PTR,8)
#define PORTC_PCR9                               PORT_PCR_REG(PORTC_BASE_PTR,9)
#define PORTC_PCR10                              PORT_PCR_REG(PORTC_BASE_PTR,10)
#define PORTC_PCR11                              PORT_PCR_REG(PORTC_BASE_PTR,11)
#define PORTC_PCR12                              PORT_PCR_REG(PORTC_BASE_PTR,12)
#define PORTC_PCR13                              PORT_PCR_REG(PORTC_BASE_PTR,13)
#define PORTC_PCR14                              PORT_PCR_REG(PORTC_BASE_PTR,14)
#define PORTC_PCR15                              PORT_PCR_REG(PORTC_BASE_PTR,15)
#define PORTC_PCR16                              PORT_PCR_REG(PORTC_BASE_PTR,16)
#define PORTC_PCR17                              PORT_PCR_REG(PORTC_BASE_PTR,17)
#define PORTC_PCR18                              PORT_PCR_REG(PORTC_BASE_PTR,18)
#define PORTC_PCR19                              PORT_PCR_REG(PORTC_BASE_PTR,19)
#define PORTC_PCR20                              PORT_PCR_REG(PORTC_BASE_PTR,20)
#define PORTC_PCR21                              PORT_PCR_REG(PORTC_BASE_PTR,21)
#define PORTC_PCR22                              PORT_PCR_REG(PORTC_BASE_PTR,22)
#define PORTC_PCR23                              PORT_PCR_REG(PORTC_BASE_PTR,23)
#define PORTC_PCR24                              PORT_PCR_REG(PORTC_BASE_PTR,24)
#define PORTC_PCR25                              PORT_PCR_REG(PORTC_BASE_PTR,25)
#define PORTC_PCR26                              PORT_PCR_REG(PORTC_BASE_PTR,26)
#define PORTC_PCR27                              PORT_PCR_REG(PORTC_BASE_PTR,27)
#define PORTC_PCR28                              PORT_PCR_REG(PORTC_BASE_PTR,28)
#define PORTC_PCR29                              PORT_PCR_REG(PORTC_BASE_PTR,29)
#define PORTC_PCR30                              PORT_PCR_REG(PORTC_BASE_PTR,30)
#define PORTC_PCR31                              PORT_PCR_REG(PORTC_BASE_PTR,31)
#define PORTC_GPCLR                              PORT_GPCLR_REG(PORTC_BASE_PTR)
#define PORTC_GPCHR                              PORT_GPCHR_REG(PORTC_BASE_PTR)
#define PORTC_ISFR                               PORT_ISFR_REG(PORTC_BASE_PTR)
#define PORTC_DFER                               PORT_DFER_REG(PORTC_BASE_PTR)
#define PORTC_DFCR                               PORT_DFCR_REG(PORTC_BASE_PTR)
#define PORTC_DFWR                               PORT_DFWR_REG(PORTC_BASE_PTR)
/* PORTD */
#define PORTD_PCR0                               PORT_PCR_REG(PORTD_BASE_PTR,0)
#define PORTD_PCR1                               PORT_PCR_REG(PORTD_BASE_PTR,1)
#define PORTD_PCR2                               PORT_PCR_REG(PORTD_BASE_PTR,2)
#define PORTD_PCR3                               PORT_PCR_REG(PORTD_BASE_PTR,3)
#define PORTD_PCR4                               PORT_PCR_REG(PORTD_BASE_PTR,4)
#define PORTD_PCR5                               PORT_PCR_REG(PORTD_BASE_PTR,5)
#define PORTD_PCR6                               PORT_PCR_REG(PORTD_BASE_PTR,6)
#define PORTD_PCR7                               PORT_PCR_REG(PORTD_BASE_PTR,7)
#define PORTD_PCR8                               PORT_PCR_REG(PORTD_BASE_PTR,8)
#define PORTD_PCR9                               PORT_PCR_REG(PORTD_BASE_PTR,9)
#define PORTD_PCR10                              PORT_PCR_REG(PORTD_BASE_PTR,10)
#define PORTD_PCR11                              PORT_PCR_REG(PORTD_BASE_PTR,11)
#define PORTD_PCR12                              PORT_PCR_REG(PORTD_BASE_PTR,12)
#define PORTD_PCR13                              PORT_PCR_REG(PORTD_BASE_PTR,13)
#define PORTD_PCR14                              PORT_PCR_REG(PORTD_BASE_PTR,14)
#define PORTD_PCR15                              PORT_PCR_REG(PORTD_BASE_PTR,15)
#define PORTD_PCR16                              PORT_PCR_REG(PORTD_BASE_PTR,16)
#define PORTD_PCR17                              PORT_PCR_REG(PORTD_BASE_PTR,17)
#define PORTD_PCR18                              PORT_PCR_REG(PORTD_BASE_PTR,18)
#define PORTD_PCR19                              PORT_PCR_REG(PORTD_BASE_PTR,19)
#define PORTD_PCR20                              PORT_PCR_REG(PORTD_BASE_PTR,20)
#define PORTD_PCR21                              PORT_PCR_REG(PORTD_BASE_PTR,21)
#define PORTD_PCR22                              PORT_PCR_REG(PORTD_BASE_PTR,22)
#define PORTD_PCR23                              PORT_PCR_REG(PORTD_BASE_PTR,23)
#define PORTD_PCR24                              PORT_PCR_REG(PORTD_BASE_PTR,24)
#define PORTD_PCR25                              PORT_PCR_REG(PORTD_BASE_PTR,25)
#define PORTD_PCR26                              PORT_PCR_REG(PORTD_BASE_PTR,26)
#define PORTD_PCR27                              PORT_PCR_REG(PORTD_BASE_PTR,27)
#define PORTD_PCR28                              PORT_PCR_REG(PORTD_BASE_PTR,28)
#define PORTD_PCR29                              PORT_PCR_REG(PORTD_BASE_PTR,29)
#define PORTD_PCR30                              PORT_PCR_REG(PORTD_BASE_PTR,30)
#define PORTD_PCR31                              PORT_PCR_REG(PORTD_BASE_PTR,31)
#define PORTD_GPCLR                              PORT_GPCLR_REG(PORTD_BASE_PTR)
#define PORTD_GPCHR                              PORT_GPCHR_REG(PORTD_BASE_PTR)
#define PORTD_ISFR                               PORT_ISFR_REG(PORTD_BASE_PTR)
#define PORTD_DFER                               PORT_DFER_REG(PORTD_BASE_PTR)
#define PORTD_DFCR                               PORT_DFCR_REG(PORTD_BASE_PTR)
#define PORTD_DFWR                               PORT_DFWR_REG(PORTD_BASE_PTR)
/* PORTE */
#define PORTE_PCR0                               PORT_PCR_REG(PORTE_BASE_PTR,0)
#define PORTE_PCR1                               PORT_PCR_REG(PORTE_BASE_PTR,1)
#define PORTE_PCR2                               PORT_PCR_REG(PORTE_BASE_PTR,2)
#define PORTE_PCR3                               PORT_PCR_REG(PORTE_BASE_PTR,3)
#define PORTE_PCR4                               PORT_PCR_REG(PORTE_BASE_PTR,4)
#define PORTE_PCR5                               PORT_PCR_REG(PORTE_BASE_PTR,5)
#define PORTE_PCR6                               PORT_PCR_REG(PORTE_BASE_PTR,6)
#define PORTE_PCR7                               PORT_PCR_REG(PORTE_BASE_PTR,7)
#define PORTE_PCR8                               PORT_PCR_REG(PORTE_BASE_PTR,8)
#define PORTE_PCR9                               PORT_PCR_REG(PORTE_BASE_PTR,9)
#define PORTE_PCR10                              PORT_PCR_REG(PORTE_BASE_PTR,10)
#define PORTE_PCR11                              PORT_PCR_REG(PORTE_BASE_PTR,11)
#define PORTE_PCR12                              PORT_PCR_REG(PORTE_BASE_PTR,12)
#define PORTE_PCR13                              PORT_PCR_REG(PORTE_BASE_PTR,13)
#define PORTE_PCR14                              PORT_PCR_REG(PORTE_BASE_PTR,14)
#define PORTE_PCR15                              PORT_PCR_REG(PORTE_BASE_PTR,15)
#define PORTE_PCR16                              PORT_PCR_REG(PORTE_BASE_PTR,16)
#define PORTE_PCR17                              PORT_PCR_REG(PORTE_BASE_PTR,17)
#define PORTE_PCR18                              PORT_PCR_REG(PORTE_BASE_PTR,18)
#define PORTE_PCR19                              PORT_PCR_REG(PORTE_BASE_PTR,19)
#define PORTE_PCR20                              PORT_PCR_REG(PORTE_BASE_PTR,20)
#define PORTE_PCR21                              PORT_PCR_REG(PORTE_BASE_PTR,21)
#define PORTE_PCR22                              PORT_PCR_REG(PORTE_BASE_PTR,22)
#define PORTE_PCR23                              PORT_PCR_REG(PORTE_BASE_PTR,23)
#define PORTE_PCR24                              PORT_PCR_REG(PORTE_BASE_PTR,24)
#define PORTE_PCR25                              PORT_PCR_REG(PORTE_BASE_PTR,25)
#define PORTE_PCR26                              PORT_PCR_REG(PORTE_BASE_PTR,26)
#define PORTE_PCR27                              PORT_PCR_REG(PORTE_BASE_PTR,27)
#define PORTE_PCR28                              PORT_PCR_REG(PORTE_BASE_PTR,28)
#define PORTE_PCR29                              PORT_PCR_REG(PORTE_BASE_PTR,29)
#define PORTE_PCR30                              PORT_PCR_REG(PORTE_BASE_PTR,30)
#define PORTE_PCR31                              PORT_PCR_REG(PORTE_BASE_PTR,31)
#define PORTE_GPCLR                              PORT_GPCLR_REG(PORTE_BASE_PTR)
#define PORTE_GPCHR                              PORT_GPCHR_REG(PORTE_BASE_PTR)
#define PORTE_ISFR                               PORT_ISFR_REG(PORTE_BASE_PTR)
#define PORTE_DFER                               PORT_DFER_REG(PORTE_BASE_PTR)
#define PORTE_DFCR                               PORT_DFCR_REG(PORTE_BASE_PTR)
#define PORTE_DFWR                               PORT_DFWR_REG(PORTE_BASE_PTR)

/*! \} */ /* end of group PORT_Register_Accessor_Macros */


/*! \} */ /* end of group PORT_Peripheral */


/* ----------------------------------------------------------------------------
   -- GPIO
   ---------------------------------------------------------------------------- */

/*! \addtogroup GPIO_Peripheral GPIO */
/*! \{ */

/*! GPIO - Peripheral register structure */
typedef struct GPIO_MemMap {
  uint32_t PDOR;                                   /*!< Port Data Output Register n, offset: 0x0 */
  uint32_t PSOR;                                   /*!< Port Set Output Register n, offset: 0x4 */
  uint32_t PCOR;                                   /*!< Port Clear Output Register n, offset: 0x8 */
  uint32_t PTOR;                                   /*!< Port Toggle Output Register n, offset: 0xC */
  uint32_t PDIR;                                   /*!< Port Data Input Register n, offset: 0x10 */
  uint32_t POER;                                   /*!< Port Output Enable Register n, offset: 0x14 */
} volatile *GPIO_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros */
/*! \{ */


/* GPIO - Register accessors */
#define GPIO_PDOR_REG(base)                      ((base)->PDOR)
#define GPIO_PSOR_REG(base)                      ((base)->PSOR)
#define GPIO_PCOR_REG(base)                      ((base)->PCOR)
#define GPIO_PTOR_REG(base)                      ((base)->PTOR)
#define GPIO_PDIR_REG(base)                      ((base)->PDIR)
#define GPIO_POER_REG(base)                      ((base)->POER)

/*! \} */ /* end of group GPIO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup GPIO_Register_Masks GPIO Register Masks */
/*! \{ */

/* PDOR Bit Fields */
#define GPIO_PDOR_PDO_MASK                       0xFFFFFFFFu
#define GPIO_PDOR_PDO_SHIFT                      0
#define GPIO_PDOR_PDO(x)                         (((x)<<GPIO_PDOR_PDO_SHIFT)&GPIO_PDOR_PDO_MASK)
/* PSOR Bit Fields */
#define GPIO_PSOR_PTSO_MASK                      0xFFFFFFFFu
#define GPIO_PSOR_PTSO_SHIFT                     0
#define GPIO_PSOR_PTSO(x)                        (((x)<<GPIO_PSOR_PTSO_SHIFT)&GPIO_PSOR_PTSO_MASK)
/* PCOR Bit Fields */
#define GPIO_PCOR_PTCO_MASK                      0xFFFFFFFFu
#define GPIO_PCOR_PTCO_SHIFT                     0
#define GPIO_PCOR_PTCO(x)                        (((x)<<GPIO_PCOR_PTCO_SHIFT)&GPIO_PCOR_PTCO_MASK)
/* PTOR Bit Fields */
#define GPIO_PTOR_PTTO_MASK                      0xFFFFFFFFu
#define GPIO_PTOR_PTTO_SHIFT                     0
#define GPIO_PTOR_PTTO(x)                        (((x)<<GPIO_PTOR_PTTO_SHIFT)&GPIO_PTOR_PTTO_MASK)
/* PDIR Bit Fields */
#define GPIO_PDIR_PDI_MASK                       0xFFFFFFFFu
#define GPIO_PDIR_PDI_SHIFT                      0
#define GPIO_PDIR_PDI(x)                         (((x)<<GPIO_PDIR_PDI_SHIFT)&GPIO_PDIR_PDI_MASK)
/* POER Bit Fields */
#define GPIO_POER_POE_MASK                       0xFFFFFFFFu
#define GPIO_POER_POE_SHIFT                      0
#define GPIO_POER_POE(x)                         (((x)<<GPIO_POER_POE_SHIFT)&GPIO_POER_POE_MASK)

/*! \} */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/*! Peripheral PTA base pointer */
#define PTA_BASE_PTR                             ((GPIO_MemMapPtr)0x400FF000u)
/*! Peripheral PTB base pointer */
#define PTB_BASE_PTR                             ((GPIO_MemMapPtr)0x400FF040u)
/*! Peripheral PTC base pointer */
#define PTC_BASE_PTR                             ((GPIO_MemMapPtr)0x400FF080u)
/*! Peripheral PTD base pointer */
#define PTD_BASE_PTR                             ((GPIO_MemMapPtr)0x400FF0C0u)
/*! Peripheral PTE base pointer */
#define PTE_BASE_PTR                             ((GPIO_MemMapPtr)0x400FF100u)

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros */
/*! \{ */


/* GPIO - Register instance definitions */
/* PTA */
#define GPIOA_PDOR                               GPIO_PDOR_REG(PTA_BASE_PTR)
#define GPIOA_PSOR                               GPIO_PSOR_REG(PTA_BASE_PTR)
#define GPIOA_PCOR                               GPIO_PCOR_REG(PTA_BASE_PTR)
#define GPIOA_PTOR                               GPIO_PTOR_REG(PTA_BASE_PTR)
#define GPIOA_PDIR                               GPIO_PDIR_REG(PTA_BASE_PTR)
#define GPIOA_POER                               GPIO_POER_REG(PTA_BASE_PTR)
/* PTB */
#define GPIOB_PDOR                               GPIO_PDOR_REG(PTB_BASE_PTR)
#define GPIOB_PSOR                               GPIO_PSOR_REG(PTB_BASE_PTR)
#define GPIOB_PCOR                               GPIO_PCOR_REG(PTB_BASE_PTR)
#define GPIOB_PTOR                               GPIO_PTOR_REG(PTB_BASE_PTR)
#define GPIOB_PDIR                               GPIO_PDIR_REG(PTB_BASE_PTR)
#define GPIOB_POER                               GPIO_POER_REG(PTB_BASE_PTR)
/* PTC */
#define GPIOC_PDOR                               GPIO_PDOR_REG(PTC_BASE_PTR)
#define GPIOC_PSOR                               GPIO_PSOR_REG(PTC_BASE_PTR)
#define GPIOC_PCOR                               GPIO_PCOR_REG(PTC_BASE_PTR)
#define GPIOC_PTOR                               GPIO_PTOR_REG(PTC_BASE_PTR)
#define GPIOC_PDIR                               GPIO_PDIR_REG(PTC_BASE_PTR)
#define GPIOC_POER                               GPIO_POER_REG(PTC_BASE_PTR)
/* PTD */
#define GPIOD_PDOR                               GPIO_PDOR_REG(PTD_BASE_PTR)
#define GPIOD_PSOR                               GPIO_PSOR_REG(PTD_BASE_PTR)
#define GPIOD_PCOR                               GPIO_PCOR_REG(PTD_BASE_PTR)
#define GPIOD_PTOR                               GPIO_PTOR_REG(PTD_BASE_PTR)
#define GPIOD_PDIR                               GPIO_PDIR_REG(PTD_BASE_PTR)
#define GPIOD_POER                               GPIO_POER_REG(PTD_BASE_PTR)
/* PTE */
#define GPIOE_PDOR                               GPIO_PDOR_REG(PTE_BASE_PTR)
#define GPIOE_PSOR                               GPIO_PSOR_REG(PTE_BASE_PTR)
#define GPIOE_PCOR                               GPIO_PCOR_REG(PTE_BASE_PTR)
#define GPIOE_PTOR                               GPIO_PTOR_REG(PTE_BASE_PTR)
#define GPIOE_PDIR                               GPIO_PDIR_REG(PTE_BASE_PTR)
#define GPIOE_POER                               GPIO_POER_REG(PTE_BASE_PTR)

/*! \} */ /* end of group GPIO_Register_Accessor_Macros */


/*! \} */ /* end of group GPIO_Peripheral */


/* ----------------------------------------------------------------------------
   -- SDHC
   ---------------------------------------------------------------------------- */

/*! \addtogroup SDHC_Peripheral SDHC */
/*! \{ */

/*! SDHC - Peripheral register structure */
typedef struct SDHC_MemMap {
  uint32_t DSADDR;                                 /*!< DMA System Address Register, offset: 0x0 */
  uint32_t BLKATTR;                                /*!< Block Attributes Register, offset: 0x4 */
  uint32_t CMDARG;                                 /*!< Command Argument Register, offset: 0x8 */
  uint32_t XFERTYP;                                /*!< Transfer Type Register, offset: 0xC */
  uint32_t CMDRSP[4];                              /*!< Command Response 0..Command Response 3, array offset: 0x10, array step: 0x4 */
  uint32_t DATPORT;                                /*!< Buffer Data Port Register, offset: 0x20 */
  uint32_t PRSSTAT;                                /*!< Present State Register, offset: 0x24 */
  uint32_t PROCTL;                                 /*!< Protocol Control Register, offset: 0x28 */
  uint32_t SYSCTL;                                 /*!< System Control Register, offset: 0x2C */
  uint32_t IRQSTAT;                                /*!< Interrupt Status Register, offset: 0x30 */
  uint32_t IRQSTATEN;                              /*!< Interrupt Status Enable Register, offset: 0x34 */
  uint32_t IRQSIGEN;                               /*!< Interrupt Signal Enable Register, offset: 0x38 */
  uint32_t AC12ERR;                                /*!< Auto CMD12 Error Status Register, offset: 0x3C */
  uint32_t HTCAPBLT;                               /*!< Host Controller Capabilities, offset: 0x40 */
  uint32_t WML;                                    /*!< Watermark Level Register, offset: 0x44 */
  uint8_t RESERVED_0[8];
  uint32_t FEVT;                                   /*!< Force Event Register, offset: 0x50 */
  uint32_t ADMAES;                                 /*!< ADMA Error Status Register, offset: 0x54 */
  uint32_t ADSADDR;                                /*!< ADMA System Address Register, offset: 0x58 */
  uint8_t RESERVED_1[100];
  uint32_t VENDOR;                                 /*!< Vendor Specific Register, offset: 0xC0 */
  uint32_t MMCBOOT;                                /*!< MMC Boot Register, offset: 0xC4 */
  uint8_t RESERVED_2[52];
  uint32_t HOSTVER;                                /*!< Host Controller Version, offset: 0xFC */
} volatile *SDHC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SDHC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SDHC_Register_Accessor_Macros SDHC - Register accessor macros */
/*! \{ */


/* SDHC - Register accessors */
#define SDHC_DSADDR_REG(base)                    ((base)->DSADDR)
#define SDHC_BLKATTR_REG(base)                   ((base)->BLKATTR)
#define SDHC_CMDARG_REG(base)                    ((base)->CMDARG)
#define SDHC_XFERTYP_REG(base)                   ((base)->XFERTYP)
#define SDHC_CMDRSP_REG(base,index)              ((base)->CMDRSP[index])
#define SDHC_DATPORT_REG(base)                   ((base)->DATPORT)
#define SDHC_PRSSTAT_REG(base)                   ((base)->PRSSTAT)
#define SDHC_PROCTL_REG(base)                    ((base)->PROCTL)
#define SDHC_SYSCTL_REG(base)                    ((base)->SYSCTL)
#define SDHC_IRQSTAT_REG(base)                   ((base)->IRQSTAT)
#define SDHC_IRQSTATEN_REG(base)                 ((base)->IRQSTATEN)
#define SDHC_IRQSIGEN_REG(base)                  ((base)->IRQSIGEN)
#define SDHC_AC12ERR_REG(base)                   ((base)->AC12ERR)
#define SDHC_HTCAPBLT_REG(base)                  ((base)->HTCAPBLT)
#define SDHC_WML_REG(base)                       ((base)->WML)
#define SDHC_FEVT_REG(base)                      ((base)->FEVT)
#define SDHC_ADMAES_REG(base)                    ((base)->ADMAES)
#define SDHC_ADSADDR_REG(base)                   ((base)->ADSADDR)
#define SDHC_VENDOR_REG(base)                    ((base)->VENDOR)
#define SDHC_MMCBOOT_REG(base)                   ((base)->MMCBOOT)
#define SDHC_HOSTVER_REG(base)                   ((base)->HOSTVER)

/*! \} */ /* end of group SDHC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SDHC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup SDHC_Register_Masks SDHC Register Masks */
/*! \{ */

/* DSADDR Bit Fields */
#define SDHC_DSADDR_DSADDR_MASK                  0xFFFFFFFCu
#define SDHC_DSADDR_DSADDR_SHIFT                 2
#define SDHC_DSADDR_DSADDR(x)                    (((x)<<SDHC_DSADDR_DSADDR_SHIFT)&SDHC_DSADDR_DSADDR_MASK)
/* BLKATTR Bit Fields */
#define SDHC_BLKATTR_BLKSIZE_MASK                0x1FFFu
#define SDHC_BLKATTR_BLKSIZE_SHIFT               0
#define SDHC_BLKATTR_BLKSIZE(x)                  (((x)<<SDHC_BLKATTR_BLKSIZE_SHIFT)&SDHC_BLKATTR_BLKSIZE_MASK)
#define SDHC_BLKATTR_BLKCNT_MASK                 0xFFFF0000u
#define SDHC_BLKATTR_BLKCNT_SHIFT                16
#define SDHC_BLKATTR_BLKCNT(x)                   (((x)<<SDHC_BLKATTR_BLKCNT_SHIFT)&SDHC_BLKATTR_BLKCNT_MASK)
/* CMDARG Bit Fields */
#define SDHC_CMDARG_CMDARG_MASK                  0xFFFFFFFFu
#define SDHC_CMDARG_CMDARG_SHIFT                 0
#define SDHC_CMDARG_CMDARG(x)                    (((x)<<SDHC_CMDARG_CMDARG_SHIFT)&SDHC_CMDARG_CMDARG_MASK)
/* XFERTYP Bit Fields */
#define SDHC_XFERTYP_DMAEN_MASK                  0x1u
#define SDHC_XFERTYP_DMAEN_SHIFT                 0
#define SDHC_XFERTYP_BCEN_MASK                   0x2u
#define SDHC_XFERTYP_BCEN_SHIFT                  1
#define SDHC_XFERTYP_AC12EN_MASK                 0x4u
#define SDHC_XFERTYP_AC12EN_SHIFT                2
#define SDHC_XFERTYP_DTDSEL_MASK                 0x10u
#define SDHC_XFERTYP_DTDSEL_SHIFT                4
#define SDHC_XFERTYP_MSBSEL_MASK                 0x20u
#define SDHC_XFERTYP_MSBSEL_SHIFT                5
#define SDHC_XFERTYP_RSPTYP_MASK                 0x30000u
#define SDHC_XFERTYP_RSPTYP_SHIFT                16
#define SDHC_XFERTYP_RSPTYP(x)                   (((x)<<SDHC_XFERTYP_RSPTYP_SHIFT)&SDHC_XFERTYP_RSPTYP_MASK)
#define SDHC_XFERTYP_CCCEN_MASK                  0x80000u
#define SDHC_XFERTYP_CCCEN_SHIFT                 19
#define SDHC_XFERTYP_CICEN_MASK                  0x100000u
#define SDHC_XFERTYP_CICEN_SHIFT                 20
#define SDHC_XFERTYP_DPSEL_MASK                  0x200000u
#define SDHC_XFERTYP_DPSEL_SHIFT                 21
#define SDHC_XFERTYP_CMDTYP_MASK                 0xC00000u
#define SDHC_XFERTYP_CMDTYP_SHIFT                22
#define SDHC_XFERTYP_CMDTYP(x)                   (((x)<<SDHC_XFERTYP_CMDTYP_SHIFT)&SDHC_XFERTYP_CMDTYP_MASK)
#define SDHC_XFERTYP_CMDINX_MASK                 0x3F000000u
#define SDHC_XFERTYP_CMDINX_SHIFT                24
#define SDHC_XFERTYP_CMDINX(x)                   (((x)<<SDHC_XFERTYP_CMDINX_SHIFT)&SDHC_XFERTYP_CMDINX_MASK)
/* CMDRSP Bit Fields */
#define SDHC_CMDRSP_CMDRSP0_MASK                 0xFFFFFFFFu
#define SDHC_CMDRSP_CMDRSP0_SHIFT                0
#define SDHC_CMDRSP_CMDRSP0(x)                   (((x)<<SDHC_CMDRSP_CMDRSP0_SHIFT)&SDHC_CMDRSP_CMDRSP0_MASK)
#define SDHC_CMDRSP_CMDRSP1_MASK                 0xFFFFFFFFu
#define SDHC_CMDRSP_CMDRSP1_SHIFT                0
#define SDHC_CMDRSP_CMDRSP1(x)                   (((x)<<SDHC_CMDRSP_CMDRSP1_SHIFT)&SDHC_CMDRSP_CMDRSP1_MASK)
#define SDHC_CMDRSP_CMDRSP2_MASK                 0xFFFFFFFFu
#define SDHC_CMDRSP_CMDRSP2_SHIFT                0
#define SDHC_CMDRSP_CMDRSP2(x)                   (((x)<<SDHC_CMDRSP_CMDRSP2_SHIFT)&SDHC_CMDRSP_CMDRSP2_MASK)
#define SDHC_CMDRSP_CMDRSP3_MASK                 0xFFFFFFFFu
#define SDHC_CMDRSP_CMDRSP3_SHIFT                0
#define SDHC_CMDRSP_CMDRSP3(x)                   (((x)<<SDHC_CMDRSP_CMDRSP3_SHIFT)&SDHC_CMDRSP_CMDRSP3_MASK)
/* DATPORT Bit Fields */
#define SDHC_DATPORT_DATCONT_MASK                0xFFFFFFFFu
#define SDHC_DATPORT_DATCONT_SHIFT               0
#define SDHC_DATPORT_DATCONT(x)                  (((x)<<SDHC_DATPORT_DATCONT_SHIFT)&SDHC_DATPORT_DATCONT_MASK)
/* PRSSTAT Bit Fields */
#define SDHC_PRSSTAT_CIHB_MASK                   0x1u
#define SDHC_PRSSTAT_CIHB_SHIFT                  0
#define SDHC_PRSSTAT_CDIHB_MASK                  0x2u
#define SDHC_PRSSTAT_CDIHB_SHIFT                 1
#define SDHC_PRSSTAT_DLA_MASK                    0x4u
#define SDHC_PRSSTAT_DLA_SHIFT                   2
#define SDHC_PRSSTAT_SDSTB_MASK                  0x8u
#define SDHC_PRSSTAT_SDSTB_SHIFT                 3
#define SDHC_PRSSTAT_IPGOFF_MASK                 0x10u
#define SDHC_PRSSTAT_IPGOFF_SHIFT                4
#define SDHC_PRSSTAT_HCKOFF_MASK                 0x20u
#define SDHC_PRSSTAT_HCKOFF_SHIFT                5
#define SDHC_PRSSTAT_PEROFF_MASK                 0x40u
#define SDHC_PRSSTAT_PEROFF_SHIFT                6
#define SDHC_PRSSTAT_SDOFF_MASK                  0x80u
#define SDHC_PRSSTAT_SDOFF_SHIFT                 7
#define SDHC_PRSSTAT_WTA_MASK                    0x100u
#define SDHC_PRSSTAT_WTA_SHIFT                   8
#define SDHC_PRSSTAT_RTA_MASK                    0x200u
#define SDHC_PRSSTAT_RTA_SHIFT                   9
#define SDHC_PRSSTAT_BWEN_MASK                   0x400u
#define SDHC_PRSSTAT_BWEN_SHIFT                  10
#define SDHC_PRSSTAT_BREN_MASK                   0x800u
#define SDHC_PRSSTAT_BREN_SHIFT                  11
#define SDHC_PRSSTAT_CINS_MASK                   0x10000u
#define SDHC_PRSSTAT_CINS_SHIFT                  16
#define SDHC_PRSSTAT_CLSL_MASK                   0x800000u
#define SDHC_PRSSTAT_CLSL_SHIFT                  23
#define SDHC_PRSSTAT_DLSL_MASK                   0xFF000000u
#define SDHC_PRSSTAT_DLSL_SHIFT                  24
#define SDHC_PRSSTAT_DLSL(x)                     (((x)<<SDHC_PRSSTAT_DLSL_SHIFT)&SDHC_PRSSTAT_DLSL_MASK)
/* PROCTL Bit Fields */
#define SDHC_PROCTL_LCTL_MASK                    0x1u
#define SDHC_PROCTL_LCTL_SHIFT                   0
#define SDHC_PROCTL_DTW_MASK                     0x6u
#define SDHC_PROCTL_DTW_SHIFT                    1
#define SDHC_PROCTL_DTW(x)                       (((x)<<SDHC_PROCTL_DTW_SHIFT)&SDHC_PROCTL_DTW_MASK)
#define SDHC_PROCTL_D3CD_MASK                    0x8u
#define SDHC_PROCTL_D3CD_SHIFT                   3
#define SDHC_PROCTL_EMODE_MASK                   0x30u
#define SDHC_PROCTL_EMODE_SHIFT                  4
#define SDHC_PROCTL_EMODE(x)                     (((x)<<SDHC_PROCTL_EMODE_SHIFT)&SDHC_PROCTL_EMODE_MASK)
#define SDHC_PROCTL_CDTL_MASK                    0x40u
#define SDHC_PROCTL_CDTL_SHIFT                   6
#define SDHC_PROCTL_CDSS_MASK                    0x80u
#define SDHC_PROCTL_CDSS_SHIFT                   7
#define SDHC_PROCTL_DMAS_MASK                    0x300u
#define SDHC_PROCTL_DMAS_SHIFT                   8
#define SDHC_PROCTL_DMAS(x)                      (((x)<<SDHC_PROCTL_DMAS_SHIFT)&SDHC_PROCTL_DMAS_MASK)
#define SDHC_PROCTL_SABGREQ_MASK                 0x10000u
#define SDHC_PROCTL_SABGREQ_SHIFT                16
#define SDHC_PROCTL_CREQ_MASK                    0x20000u
#define SDHC_PROCTL_CREQ_SHIFT                   17
#define SDHC_PROCTL_RWCTL_MASK                   0x40000u
#define SDHC_PROCTL_RWCTL_SHIFT                  18
#define SDHC_PROCTL_IABG_MASK                    0x80000u
#define SDHC_PROCTL_IABG_SHIFT                   19
#define SDHC_PROCTL_WECINT_MASK                  0x1000000u
#define SDHC_PROCTL_WECINT_SHIFT                 24
#define SDHC_PROCTL_WECINS_MASK                  0x2000000u
#define SDHC_PROCTL_WECINS_SHIFT                 25
#define SDHC_PROCTL_WECRM_MASK                   0x4000000u
#define SDHC_PROCTL_WECRM_SHIFT                  26
/* SYSCTL Bit Fields */
#define SDHC_SYSCTL_IPGEN_MASK                   0x1u
#define SDHC_SYSCTL_IPGEN_SHIFT                  0
#define SDHC_SYSCTL_HCKEN_MASK                   0x2u
#define SDHC_SYSCTL_HCKEN_SHIFT                  1
#define SDHC_SYSCTL_PEREN_MASK                   0x4u
#define SDHC_SYSCTL_PEREN_SHIFT                  2
#define SDHC_SYSCTL_SDCLKEN_MASK                 0x8u
#define SDHC_SYSCTL_SDCLKEN_SHIFT                3
#define SDHC_SYSCTL_DVS_MASK                     0xF0u
#define SDHC_SYSCTL_DVS_SHIFT                    4
#define SDHC_SYSCTL_DVS(x)                       (((x)<<SDHC_SYSCTL_DVS_SHIFT)&SDHC_SYSCTL_DVS_MASK)
#define SDHC_SYSCTL_SDCLKFS_MASK                 0xFF00u
#define SDHC_SYSCTL_SDCLKFS_SHIFT                8
#define SDHC_SYSCTL_SDCLKFS(x)                   (((x)<<SDHC_SYSCTL_SDCLKFS_SHIFT)&SDHC_SYSCTL_SDCLKFS_MASK)
#define SDHC_SYSCTL_DTOCV_MASK                   0xF0000u
#define SDHC_SYSCTL_DTOCV_SHIFT                  16
#define SDHC_SYSCTL_DTOCV(x)                     (((x)<<SDHC_SYSCTL_DTOCV_SHIFT)&SDHC_SYSCTL_DTOCV_MASK)
#define SDHC_SYSCTL_RSTA_MASK                    0x1000000u
#define SDHC_SYSCTL_RSTA_SHIFT                   24
#define SDHC_SYSCTL_RSTC_MASK                    0x2000000u
#define SDHC_SYSCTL_RSTC_SHIFT                   25
#define SDHC_SYSCTL_RSTD_MASK                    0x4000000u
#define SDHC_SYSCTL_RSTD_SHIFT                   26
#define SDHC_SYSCTL_INITA_MASK                   0x8000000u
#define SDHC_SYSCTL_INITA_SHIFT                  27
/* IRQSTAT Bit Fields */
#define SDHC_IRQSTAT_CC_MASK                     0x1u
#define SDHC_IRQSTAT_CC_SHIFT                    0
#define SDHC_IRQSTAT_TC_MASK                     0x2u
#define SDHC_IRQSTAT_TC_SHIFT                    1
#define SDHC_IRQSTAT_BGE_MASK                    0x4u
#define SDHC_IRQSTAT_BGE_SHIFT                   2
#define SDHC_IRQSTAT_DINT_MASK                   0x8u
#define SDHC_IRQSTAT_DINT_SHIFT                  3
#define SDHC_IRQSTAT_BWR_MASK                    0x10u
#define SDHC_IRQSTAT_BWR_SHIFT                   4
#define SDHC_IRQSTAT_BRR_MASK                    0x20u
#define SDHC_IRQSTAT_BRR_SHIFT                   5
#define SDHC_IRQSTAT_CINS_MASK                   0x40u
#define SDHC_IRQSTAT_CINS_SHIFT                  6
#define SDHC_IRQSTAT_CRM_MASK                    0x80u
#define SDHC_IRQSTAT_CRM_SHIFT                   7
#define SDHC_IRQSTAT_CINT_MASK                   0x100u
#define SDHC_IRQSTAT_CINT_SHIFT                  8
#define SDHC_IRQSTAT_CTOE_MASK                   0x10000u
#define SDHC_IRQSTAT_CTOE_SHIFT                  16
#define SDHC_IRQSTAT_CCE_MASK                    0x20000u
#define SDHC_IRQSTAT_CCE_SHIFT                   17
#define SDHC_IRQSTAT_CEBE_MASK                   0x40000u
#define SDHC_IRQSTAT_CEBE_SHIFT                  18
#define SDHC_IRQSTAT_CIE_MASK                    0x80000u
#define SDHC_IRQSTAT_CIE_SHIFT                   19
#define SDHC_IRQSTAT_DTOE_MASK                   0x100000u
#define SDHC_IRQSTAT_DTOE_SHIFT                  20
#define SDHC_IRQSTAT_DCE_MASK                    0x200000u
#define SDHC_IRQSTAT_DCE_SHIFT                   21
#define SDHC_IRQSTAT_DEBE_MASK                   0x400000u
#define SDHC_IRQSTAT_DEBE_SHIFT                  22
#define SDHC_IRQSTAT_AC12E_MASK                  0x1000000u
#define SDHC_IRQSTAT_AC12E_SHIFT                 24
#define SDHC_IRQSTAT_DMAE_MASK                   0x10000000u
#define SDHC_IRQSTAT_DMAE_SHIFT                  28
/* IRQSTATEN Bit Fields */
#define SDHC_IRQSTATEN_CCSEN_MASK                0x1u
#define SDHC_IRQSTATEN_CCSEN_SHIFT               0
#define SDHC_IRQSTATEN_TCSEN_MASK                0x2u
#define SDHC_IRQSTATEN_TCSEN_SHIFT               1
#define SDHC_IRQSTATEN_BGESEN_MASK               0x4u
#define SDHC_IRQSTATEN_BGESEN_SHIFT              2
#define SDHC_IRQSTATEN_DINTSEN_MASK              0x8u
#define SDHC_IRQSTATEN_DINTSEN_SHIFT             3
#define SDHC_IRQSTATEN_BWRSEN_MASK               0x10u
#define SDHC_IRQSTATEN_BWRSEN_SHIFT              4
#define SDHC_IRQSTATEN_BRRSEN_MASK               0x20u
#define SDHC_IRQSTATEN_BRRSEN_SHIFT              5
#define SDHC_IRQSTATEN_CINSEN_MASK               0x40u
#define SDHC_IRQSTATEN_CINSEN_SHIFT              6
#define SDHC_IRQSTATEN_CRMSEN_MASK               0x80u
#define SDHC_IRQSTATEN_CRMSEN_SHIFT              7
#define SDHC_IRQSTATEN_CINTSEN_MASK              0x100u
#define SDHC_IRQSTATEN_CINTSEN_SHIFT             8
#define SDHC_IRQSTATEN_CTOESEN_MASK              0x10000u
#define SDHC_IRQSTATEN_CTOESEN_SHIFT             16
#define SDHC_IRQSTATEN_CCESEN_MASK               0x20000u
#define SDHC_IRQSTATEN_CCESEN_SHIFT              17
#define SDHC_IRQSTATEN_CEBESEN_MASK              0x40000u
#define SDHC_IRQSTATEN_CEBESEN_SHIFT             18
#define SDHC_IRQSTATEN_CIESEN_MASK               0x80000u
#define SDHC_IRQSTATEN_CIESEN_SHIFT              19
#define SDHC_IRQSTATEN_DTOESEN_MASK              0x100000u
#define SDHC_IRQSTATEN_DTOESEN_SHIFT             20
#define SDHC_IRQSTATEN_DCESEN_MASK               0x200000u
#define SDHC_IRQSTATEN_DCESEN_SHIFT              21
#define SDHC_IRQSTATEN_DEBESEN_MASK              0x400000u
#define SDHC_IRQSTATEN_DEBESEN_SHIFT             22
#define SDHC_IRQSTATEN_AC12ESEN_MASK             0x1000000u
#define SDHC_IRQSTATEN_AC12ESEN_SHIFT            24
#define SDHC_IRQSTATEN_DMAESEN_MASK              0x10000000u
#define SDHC_IRQSTATEN_DMAESEN_SHIFT             28
/* IRQSIGEN Bit Fields */
#define SDHC_IRQSIGEN_CCIEN_MASK                 0x1u
#define SDHC_IRQSIGEN_CCIEN_SHIFT                0
#define SDHC_IRQSIGEN_TCIEN_MASK                 0x2u
#define SDHC_IRQSIGEN_TCIEN_SHIFT                1
#define SDHC_IRQSIGEN_BGEIEN_MASK                0x4u
#define SDHC_IRQSIGEN_BGEIEN_SHIFT               2
#define SDHC_IRQSIGEN_DINTIEN_MASK               0x8u
#define SDHC_IRQSIGEN_DINTIEN_SHIFT              3
#define SDHC_IRQSIGEN_BWRIEN_MASK                0x10u
#define SDHC_IRQSIGEN_BWRIEN_SHIFT               4
#define SDHC_IRQSIGEN_BRRIEN_MASK                0x20u
#define SDHC_IRQSIGEN_BRRIEN_SHIFT               5
#define SDHC_IRQSIGEN_CINSIEN_MASK               0x40u
#define SDHC_IRQSIGEN_CINSIEN_SHIFT              6
#define SDHC_IRQSIGEN_CRMIEN_MASK                0x80u
#define SDHC_IRQSIGEN_CRMIEN_SHIFT               7
#define SDHC_IRQSIGEN_CINTIEN_MASK               0x100u
#define SDHC_IRQSIGEN_CINTIEN_SHIFT              8
#define SDHC_IRQSIGEN_CTOEIEN_MASK               0x10000u
#define SDHC_IRQSIGEN_CTOEIEN_SHIFT              16
#define SDHC_IRQSIGEN_CCEIEN_MASK                0x20000u
#define SDHC_IRQSIGEN_CCEIEN_SHIFT               17
#define SDHC_IRQSIGEN_CEBEIEN_MASK               0x40000u
#define SDHC_IRQSIGEN_CEBEIEN_SHIFT              18
#define SDHC_IRQSIGEN_CIEIEN_MASK                0x80000u
#define SDHC_IRQSIGEN_CIEIEN_SHIFT               19
#define SDHC_IRQSIGEN_DTOEIEN_MASK               0x100000u
#define SDHC_IRQSIGEN_DTOEIEN_SHIFT              20
#define SDHC_IRQSIGEN_DCEIEN_MASK                0x200000u
#define SDHC_IRQSIGEN_DCEIEN_SHIFT               21
#define SDHC_IRQSIGEN_DEBEIEN_MASK               0x400000u
#define SDHC_IRQSIGEN_DEBEIEN_SHIFT              22
#define SDHC_IRQSIGEN_AC12EIEN_MASK              0x1000000u
#define SDHC_IRQSIGEN_AC12EIEN_SHIFT             24
#define SDHC_IRQSIGEN_DMAEIEN_MASK               0x10000000u
#define SDHC_IRQSIGEN_DMAEIEN_SHIFT              28
/* AC12ERR Bit Fields */
#define SDHC_AC12ERR_AC12NE_MASK                 0x1u
#define SDHC_AC12ERR_AC12NE_SHIFT                0
#define SDHC_AC12ERR_AC12TOE_MASK                0x2u
#define SDHC_AC12ERR_AC12TOE_SHIFT               1
#define SDHC_AC12ERR_AC12EBE_MASK                0x4u
#define SDHC_AC12ERR_AC12EBE_SHIFT               2
#define SDHC_AC12ERR_AC12CE_MASK                 0x8u
#define SDHC_AC12ERR_AC12CE_SHIFT                3
#define SDHC_AC12ERR_AC12IE_MASK                 0x10u
#define SDHC_AC12ERR_AC12IE_SHIFT                4
#define SDHC_AC12ERR_CNIBAC12E_MASK              0x80u
#define SDHC_AC12ERR_CNIBAC12E_SHIFT             7
/* HTCAPBLT Bit Fields */
#define SDHC_HTCAPBLT_MBL_MASK                   0x70000u
#define SDHC_HTCAPBLT_MBL_SHIFT                  16
#define SDHC_HTCAPBLT_MBL(x)                     (((x)<<SDHC_HTCAPBLT_MBL_SHIFT)&SDHC_HTCAPBLT_MBL_MASK)
#define SDHC_HTCAPBLT_ADMAS_MASK                 0x100000u
#define SDHC_HTCAPBLT_ADMAS_SHIFT                20
#define SDHC_HTCAPBLT_HSS_MASK                   0x200000u
#define SDHC_HTCAPBLT_HSS_SHIFT                  21
#define SDHC_HTCAPBLT_DMAS_MASK                  0x400000u
#define SDHC_HTCAPBLT_DMAS_SHIFT                 22
#define SDHC_HTCAPBLT_SRS_MASK                   0x800000u
#define SDHC_HTCAPBLT_SRS_SHIFT                  23
#define SDHC_HTCAPBLT_VS33_MASK                  0x1000000u
#define SDHC_HTCAPBLT_VS33_SHIFT                 24
#define SDHC_HTCAPBLT_VS30_MASK                  0x2000000u
#define SDHC_HTCAPBLT_VS30_SHIFT                 25
#define SDHC_HTCAPBLT_VS18_MASK                  0x4000000u
#define SDHC_HTCAPBLT_VS18_SHIFT                 26
/* WML Bit Fields */
#define SDHC_WML_RDWML_MASK                      0xFFu
#define SDHC_WML_RDWML_SHIFT                     0
#define SDHC_WML_RDWML(x)                        (((x)<<SDHC_WML_RDWML_SHIFT)&SDHC_WML_RDWML_MASK)
#define SDHC_WML_WRWML_MASK                      0xFF0000u
#define SDHC_WML_WRWML_SHIFT                     16
#define SDHC_WML_WRWML(x)                        (((x)<<SDHC_WML_WRWML_SHIFT)&SDHC_WML_WRWML_MASK)
#define SDHC_WML_WRBRSTLEN_MASK                  0x1F000000u
#define SDHC_WML_WRBRSTLEN_SHIFT                 24
#define SDHC_WML_WRBRSTLEN(x)                    (((x)<<SDHC_WML_WRBRSTLEN_SHIFT)&SDHC_WML_WRBRSTLEN_MASK)
/* FEVT Bit Fields */
#define SDHC_FEVT_AC12NE_MASK                    0x1u
#define SDHC_FEVT_AC12NE_SHIFT                   0
#define SDHC_FEVT_AC12TOE_MASK                   0x2u
#define SDHC_FEVT_AC12TOE_SHIFT                  1
#define SDHC_FEVT_AC12CE_MASK                    0x4u
#define SDHC_FEVT_AC12CE_SHIFT                   2
#define SDHC_FEVT_AC12EBE_MASK                   0x8u
#define SDHC_FEVT_AC12EBE_SHIFT                  3
#define SDHC_FEVT_AC12IE_MASK                    0x10u
#define SDHC_FEVT_AC12IE_SHIFT                   4
#define SDHC_FEVT_CNIBAC12E_MASK                 0x80u
#define SDHC_FEVT_CNIBAC12E_SHIFT                7
#define SDHC_FEVT_CTOE_MASK                      0x10000u
#define SDHC_FEVT_CTOE_SHIFT                     16
#define SDHC_FEVT_CCE_MASK                       0x20000u
#define SDHC_FEVT_CCE_SHIFT                      17
#define SDHC_FEVT_CEBE_MASK                      0x40000u
#define SDHC_FEVT_CEBE_SHIFT                     18
#define SDHC_FEVT_CIE_MASK                       0x80000u
#define SDHC_FEVT_CIE_SHIFT                      19
#define SDHC_FEVT_DTOE_MASK                      0x100000u
#define SDHC_FEVT_DTOE_SHIFT                     20
#define SDHC_FEVT_DCE_MASK                       0x200000u
#define SDHC_FEVT_DCE_SHIFT                      21
#define SDHC_FEVT_DEBE_MASK                      0x400000u
#define SDHC_FEVT_DEBE_SHIFT                     22
#define SDHC_FEVT_AC12E_MASK                     0x1000000u
#define SDHC_FEVT_AC12E_SHIFT                    24
#define SDHC_FEVT_DMAE_MASK                      0x10000000u
#define SDHC_FEVT_DMAE_SHIFT                     28
#define SDHC_FEVT_CINT_MASK                      0x80000000u
#define SDHC_FEVT_CINT_SHIFT                     31
/* ADMAES Bit Fields */
#define SDHC_ADMAES_ADMAES_MASK                  0x3u
#define SDHC_ADMAES_ADMAES_SHIFT                 0
#define SDHC_ADMAES_ADMAES(x)                    (((x)<<SDHC_ADMAES_ADMAES_SHIFT)&SDHC_ADMAES_ADMAES_MASK)
#define SDHC_ADMAES_ADMALME_MASK                 0x4u
#define SDHC_ADMAES_ADMALME_SHIFT                2
#define SDHC_ADMAES_ADMADCE_MASK                 0x8u
#define SDHC_ADMAES_ADMADCE_SHIFT                3
/* ADSADDR Bit Fields */
#define SDHC_ADSADDR_ADSADDR_MASK                0xFFFFFFFCu
#define SDHC_ADSADDR_ADSADDR_SHIFT               2
#define SDHC_ADSADDR_ADSADDR(x)                  (((x)<<SDHC_ADSADDR_ADSADDR_SHIFT)&SDHC_ADSADDR_ADSADDR_MASK)
/* VENDOR Bit Fields */
#define SDHC_VENDOR_EXTDMAEN_MASK                0x1u
#define SDHC_VENDOR_EXTDMAEN_SHIFT               0
#define SDHC_VENDOR_VOLTSEL_MASK                 0x2u
#define SDHC_VENDOR_VOLTSEL_SHIFT                1
#define SDHC_VENDOR_INTSTVAL_MASK                0xFF0000u
#define SDHC_VENDOR_INTSTVAL_SHIFT               16
#define SDHC_VENDOR_INTSTVAL(x)                  (((x)<<SDHC_VENDOR_INTSTVAL_SHIFT)&SDHC_VENDOR_INTSTVAL_MASK)
/* MMCBOOT Bit Fields */
#define SDHC_MMCBOOT_DTOCVACK_MASK               0xFu
#define SDHC_MMCBOOT_DTOCVACK_SHIFT              0
#define SDHC_MMCBOOT_DTOCVACK(x)                 (((x)<<SDHC_MMCBOOT_DTOCVACK_SHIFT)&SDHC_MMCBOOT_DTOCVACK_MASK)
#define SDHC_MMCBOOT_BOOTACK_MASK                0x10u
#define SDHC_MMCBOOT_BOOTACK_SHIFT               4
#define SDHC_MMCBOOT_BOOTMODE_MASK               0x20u
#define SDHC_MMCBOOT_BOOTMODE_SHIFT              5
#define SDHC_MMCBOOT_BOOTEN_MASK                 0x40u
#define SDHC_MMCBOOT_BOOTEN_SHIFT                6
#define SDHC_MMCBOOT_AUTOSABGEN_MASK             0x80u
#define SDHC_MMCBOOT_AUTOSABGEN_SHIFT            7
#define SDHC_MMCBOOT_BOOTBLKCNT_MASK             0xFFFF0000u
#define SDHC_MMCBOOT_BOOTBLKCNT_SHIFT            16
#define SDHC_MMCBOOT_BOOTBLKCNT(x)               (((x)<<SDHC_MMCBOOT_BOOTBLKCNT_SHIFT)&SDHC_MMCBOOT_BOOTBLKCNT_MASK)
/* HOSTVER Bit Fields */
#define SDHC_HOSTVER_SVN_MASK                    0xFFu
#define SDHC_HOSTVER_SVN_SHIFT                   0
#define SDHC_HOSTVER_SVN(x)                      (((x)<<SDHC_HOSTVER_SVN_SHIFT)&SDHC_HOSTVER_SVN_MASK)
#define SDHC_HOSTVER_VVN_MASK                    0xFF00u
#define SDHC_HOSTVER_VVN_SHIFT                   8
#define SDHC_HOSTVER_VVN(x)                      (((x)<<SDHC_HOSTVER_VVN_SHIFT)&SDHC_HOSTVER_VVN_MASK)

/*! \} */ /* end of group SDHC_Register_Masks */


/* SDHC - Peripheral instance base addresses */
/*! Peripheral SDHC base pointer */
#define SDHC_BASE_PTR                            ((SDHC_MemMapPtr)0x400B1000u)

/* ----------------------------------------------------------------------------
   -- SDHC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SDHC_Register_Accessor_Macros SDHC - Register accessor macros */
/*! \{ */


/* SDHC - Register instance definitions */
/* SDHC */
#define SDHC_DSADDR                              SDHC_DSADDR_REG(SDHC_BASE_PTR)
#define SDHC_BLKATTR                             SDHC_BLKATTR_REG(SDHC_BASE_PTR)
#define SDHC_CMDARG                              SDHC_CMDARG_REG(SDHC_BASE_PTR)
#define SDHC_XFERTYP                             SDHC_XFERTYP_REG(SDHC_BASE_PTR)
#define SDHC_CMDRSP0                             SDHC_CMDRSP_REG(SDHC_BASE_PTR,0)
#define SDHC_CMDRSP1                             SDHC_CMDRSP_REG(SDHC_BASE_PTR,1)
#define SDHC_CMDRSP2                             SDHC_CMDRSP_REG(SDHC_BASE_PTR,2)
#define SDHC_CMDRSP3                             SDHC_CMDRSP_REG(SDHC_BASE_PTR,3)
#define SDHC_DATPORT                             SDHC_DATPORT_REG(SDHC_BASE_PTR)
#define SDHC_PRSSTAT                             SDHC_PRSSTAT_REG(SDHC_BASE_PTR)
#define SDHC_PROCTL                              SDHC_PROCTL_REG(SDHC_BASE_PTR)
#define SDHC_SYSCTL                              SDHC_SYSCTL_REG(SDHC_BASE_PTR)
#define SDHC_IRQSTAT                             SDHC_IRQSTAT_REG(SDHC_BASE_PTR)
#define SDHC_IRQSTATEN                           SDHC_IRQSTATEN_REG(SDHC_BASE_PTR)
#define SDHC_IRQSIGEN                            SDHC_IRQSIGEN_REG(SDHC_BASE_PTR)
#define SDHC_AC12ERR                             SDHC_AC12ERR_REG(SDHC_BASE_PTR)
#define SDHC_HTCAPBLT                            SDHC_HTCAPBLT_REG(SDHC_BASE_PTR)
#define SDHC_WML                                 SDHC_WML_REG(SDHC_BASE_PTR)
#define SDHC_FEVT                                SDHC_FEVT_REG(SDHC_BASE_PTR)
#define SDHC_ADMAES                              SDHC_ADMAES_REG(SDHC_BASE_PTR)
#define SDHC_ADSADDR                             SDHC_ADSADDR_REG(SDHC_BASE_PTR)
#define SDHC_VENDOR                              SDHC_VENDOR_REG(SDHC_BASE_PTR)
#define SDHC_MMCBOOT                             SDHC_MMCBOOT_REG(SDHC_BASE_PTR)
#define SDHC_HOSTVER                             SDHC_HOSTVER_REG(SDHC_BASE_PTR)

/*! \} */ /* end of group SDHC_Register_Accessor_Macros */


/*! \} */ /* end of group SDHC_Peripheral */


/* ----------------------------------------------------------------------------
   -- SIM
   ---------------------------------------------------------------------------- */

/*! \addtogroup SIM_Peripheral SIM */
/*! \{ */

/*! SIM - Peripheral register structure */
typedef struct SIM_MemMap {
  uint32_t SOPT1;                                  /*!< System Options Register 1, offset: 0x0 */
  uint8_t RESERVED_0[4096];
  uint32_t SOPT2;                                  /*!< System Options Register 2, offset: 0x1004 */
  uint8_t RESERVED_1[4];
  uint32_t SOPT4;                                  /*!< System Options Register 4, offset: 0x100C */
  uint32_t SOPT5;                                  /*!< System Options Register 5, offset: 0x1010 */
  uint32_t SOPT6;                                  /*!< System Options Register 6, offset: 0x1014 */
  uint32_t SOPT7;                                  /*!< System Options Register 7, offset: 0x1018 */
  uint8_t RESERVED_2[8];
  uint32_t SDID;                                   /*!< System Device Identification Register, offset: 0x1024 */
  uint32_t SCGC1;                                  /*!< System Clock Gating Control Register 1, offset: 0x1028 */
  uint32_t SCGC2;                                  /*!< System Clock Gating Control Register 2, offset: 0x102C */
  uint32_t SCGC3;                                  /*!< System Clock Gating Control Register 3, offset: 0x1030 */
  uint32_t SCGC4;                                  /*!< System Clock Gating Control Register 4, offset: 0x1034 */
  uint32_t SCGC5;                                  /*!< System Clock Gating Control Register 5, offset: 0x1038 */
  uint32_t SCGC6;                                  /*!< System Clock Gating Control Register 6, offset: 0x103C */
  uint32_t SCGC7;                                  /*!< System Clock Gating Control Register 7, offset: 0x1040 */
  uint32_t CLKDIV1;                                /*!< System Clock Divider Register 1, offset: 0x1044 */
  uint32_t CLKDIV2;                                /*!< System Clock Divider Register 2, offset: 0x1048 */
  uint32_t FCFG1;                                  /*!< Flash Configuration Register 1, offset: 0x104C */
  uint32_t FCFG2;                                  /*!< Flash Configuration Register 2, offset: 0x1050 */
  uint32_t UIDH;                                   /*!< Unique Identification Register High, offset: 0x1054 */
  uint32_t UIDMH;                                  /*!< Unique Identification Register Mid-High, offset: 0x1058 */
  uint32_t UIDML;                                  /*!< Unique Identification Register Mid Low, offset: 0x105C */
  uint32_t UIDL;                                   /*!< Unique Identification Register Low, offset: 0x1060 */
} volatile *SIM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros */
/*! \{ */


/* SIM - Register accessors */
#define SIM_SOPT1_REG(base)                      ((base)->SOPT1)
#define SIM_SOPT2_REG(base)                      ((base)->SOPT2)
#define SIM_SOPT4_REG(base)                      ((base)->SOPT4)
#define SIM_SOPT5_REG(base)                      ((base)->SOPT5)
#define SIM_SOPT6_REG(base)                      ((base)->SOPT6)
#define SIM_SOPT7_REG(base)                      ((base)->SOPT7)
#define SIM_SDID_REG(base)                       ((base)->SDID)
#define SIM_SCGC1_REG(base)                      ((base)->SCGC1)
#define SIM_SCGC2_REG(base)                      ((base)->SCGC2)
#define SIM_SCGC3_REG(base)                      ((base)->SCGC3)
#define SIM_SCGC4_REG(base)                      ((base)->SCGC4)
#define SIM_SCGC5_REG(base)                      ((base)->SCGC5)
#define SIM_SCGC6_REG(base)                      ((base)->SCGC6)
#define SIM_SCGC7_REG(base)                      ((base)->SCGC7)
#define SIM_CLKDIV1_REG(base)                    ((base)->CLKDIV1)
#define SIM_CLKDIV2_REG(base)                    ((base)->CLKDIV2)
#define SIM_FCFG1_REG(base)                      ((base)->FCFG1)
#define SIM_FCFG2_REG(base)                      ((base)->FCFG2)
#define SIM_UIDH_REG(base)                       ((base)->UIDH)
#define SIM_UIDMH_REG(base)                      ((base)->UIDMH)
#define SIM_UIDML_REG(base)                      ((base)->UIDML)
#define SIM_UIDL_REG(base)                       ((base)->UIDL)

/*! \} */ /* end of group SIM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup SIM_Register_Masks SIM Register Masks */
/*! \{ */

/* SOPT1 Bit Fields */
#define SIM_SOPT1_RAMSIZE_MASK                   0xF000u
#define SIM_SOPT1_RAMSIZE_SHIFT                  12
#define SIM_SOPT1_RAMSIZE(x)                     (((x)<<SIM_SOPT1_RAMSIZE_SHIFT)&SIM_SOPT1_RAMSIZE_MASK)
#define SIM_SOPT1_OSC32KSEL_MASK                 0x80000u
#define SIM_SOPT1_OSC32KSEL_SHIFT                19
#define SIM_SOPT1_MS_MASK                        0x800000u
#define SIM_SOPT1_MS_SHIFT                       23
#define SIM_SOPT1_USBSTBY_MASK                   0x40000000u
#define SIM_SOPT1_USBSTBY_SHIFT                  30
#define SIM_SOPT1_USBREGEN_MASK                  0x80000000u
#define SIM_SOPT1_USBREGEN_SHIFT                 31
/* SOPT2 Bit Fields */
#define SIM_SOPT2_MCGCLKSEL_MASK                 0x1u
#define SIM_SOPT2_MCGCLKSEL_SHIFT                0
#define SIM_SOPT2_FBSL_MASK                      0x300u
#define SIM_SOPT2_FBSL_SHIFT                     8
#define SIM_SOPT2_FBSL(x)                        (((x)<<SIM_SOPT2_FBSL_SHIFT)&SIM_SOPT2_FBSL_MASK)
#define SIM_SOPT2_CMTUARTPAD_MASK                0x800u
#define SIM_SOPT2_CMTUARTPAD_SHIFT               11
#define SIM_SOPT2_TRACECLKSEL_MASK               0x1000u
#define SIM_SOPT2_TRACECLKSEL_SHIFT              12
#define SIM_SOPT2_PLLFLLSEL_MASK                 0x10000u
#define SIM_SOPT2_PLLFLLSEL_SHIFT                16
#define SIM_SOPT2_USBSRC_MASK                    0x40000u
#define SIM_SOPT2_USBSRC_SHIFT                   18
#define SIM_SOPT2_I2SSRC_MASK                    0x3000000u
#define SIM_SOPT2_I2SSRC_SHIFT                   24
#define SIM_SOPT2_I2SSRC(x)                      (((x)<<SIM_SOPT2_I2SSRC_SHIFT)&SIM_SOPT2_I2SSRC_MASK)
#define SIM_SOPT2_SDHCSRC_MASK                   0x30000000u
#define SIM_SOPT2_SDHCSRC_SHIFT                  28
#define SIM_SOPT2_SDHCSRC(x)                     (((x)<<SIM_SOPT2_SDHCSRC_SHIFT)&SIM_SOPT2_SDHCSRC_MASK)
/* SOPT4 Bit Fields */
#define SIM_SOPT4_FTM0FLT0_MASK                  0x1u
#define SIM_SOPT4_FTM0FLT0_SHIFT                 0
#define SIM_SOPT4_FTM0FLT1_MASK                  0x2u
#define SIM_SOPT4_FTM0FLT1_SHIFT                 1
#define SIM_SOPT4_FTM0FLT2_MASK                  0x4u
#define SIM_SOPT4_FTM0FLT2_SHIFT                 2
#define SIM_SOPT4_FTM1FLT0_MASK                  0x10u
#define SIM_SOPT4_FTM1FLT0_SHIFT                 4
#define SIM_SOPT4_FTM2FLT0_MASK                  0x100u
#define SIM_SOPT4_FTM2FLT0_SHIFT                 8
#define SIM_SOPT4_FTM1CH0SRC_MASK                0xC0000u
#define SIM_SOPT4_FTM1CH0SRC_SHIFT               18
#define SIM_SOPT4_FTM1CH0SRC(x)                  (((x)<<SIM_SOPT4_FTM1CH0SRC_SHIFT)&SIM_SOPT4_FTM1CH0SRC_MASK)
#define SIM_SOPT4_FTM2CH0SRC_MASK                0x300000u
#define SIM_SOPT4_FTM2CH0SRC_SHIFT               20
#define SIM_SOPT4_FTM2CH0SRC(x)                  (((x)<<SIM_SOPT4_FTM2CH0SRC_SHIFT)&SIM_SOPT4_FTM2CH0SRC_MASK)
#define SIM_SOPT4_FTM0CLKSEL_MASK                0x1000000u
#define SIM_SOPT4_FTM0CLKSEL_SHIFT               24
#define SIM_SOPT4_FTM1CLKSEL_MASK                0x2000000u
#define SIM_SOPT4_FTM1CLKSEL_SHIFT               25
#define SIM_SOPT4_FTM2CLKSEL_MASK                0x4000000u
#define SIM_SOPT4_FTM2CLKSEL_SHIFT               26
/* SOPT5 Bit Fields */
#define SIM_SOPT5_UART0TXSRC_MASK                0x3u
#define SIM_SOPT5_UART0TXSRC_SHIFT               0
#define SIM_SOPT5_UART0TXSRC(x)                  (((x)<<SIM_SOPT5_UART0TXSRC_SHIFT)&SIM_SOPT5_UART0TXSRC_MASK)
#define SIM_SOPT5_UART0RXSRC_MASK                0xCu
#define SIM_SOPT5_UART0RXSRC_SHIFT               2
#define SIM_SOPT5_UART0RXSRC(x)                  (((x)<<SIM_SOPT5_UART0RXSRC_SHIFT)&SIM_SOPT5_UART0RXSRC_MASK)
#define SIM_SOPT5_UARTTXSRC_MASK                 0x30u
#define SIM_SOPT5_UARTTXSRC_SHIFT                4
#define SIM_SOPT5_UARTTXSRC(x)                   (((x)<<SIM_SOPT5_UARTTXSRC_SHIFT)&SIM_SOPT5_UARTTXSRC_MASK)
#define SIM_SOPT5_UART1RXSRC_MASK                0xC0u
#define SIM_SOPT5_UART1RXSRC_SHIFT               6
#define SIM_SOPT5_UART1RXSRC(x)                  (((x)<<SIM_SOPT5_UART1RXSRC_SHIFT)&SIM_SOPT5_UART1RXSRC_MASK)
/* SOPT6 Bit Fields */
#define SIM_SOPT6_RSTFLTSEL_MASK                 0x1F000000u
#define SIM_SOPT6_RSTFLTSEL_SHIFT                24
#define SIM_SOPT6_RSTFLTSEL(x)                   (((x)<<SIM_SOPT6_RSTFLTSEL_SHIFT)&SIM_SOPT6_RSTFLTSEL_MASK)
#define SIM_SOPT6_RSTFLTEN_MASK                  0xE0000000u
#define SIM_SOPT6_RSTFLTEN_SHIFT                 29
#define SIM_SOPT6_RSTFLTEN(x)                    (((x)<<SIM_SOPT6_RSTFLTEN_SHIFT)&SIM_SOPT6_RSTFLTEN_MASK)
/* SOPT7 Bit Fields */
#define SIM_SOPT7_ADC0TRGSEL_MASK                0xFu
#define SIM_SOPT7_ADC0TRGSEL_SHIFT               0
#define SIM_SOPT7_ADC0TRGSEL(x)                  (((x)<<SIM_SOPT7_ADC0TRGSEL_SHIFT)&SIM_SOPT7_ADC0TRGSEL_MASK)
#define SIM_SOPT7_ADC0PRETRGSEL_MASK             0x10u
#define SIM_SOPT7_ADC0PRETRGSEL_SHIFT            4
#define SIM_SOPT7_ADC0ALTTRGEN_MASK              0x80u
#define SIM_SOPT7_ADC0ALTTRGEN_SHIFT             7
#define SIM_SOPT7_ADC1TRGSEL_MASK                0xF00u
#define SIM_SOPT7_ADC1TRGSEL_SHIFT               8
#define SIM_SOPT7_ADC1TRGSEL(x)                  (((x)<<SIM_SOPT7_ADC1TRGSEL_SHIFT)&SIM_SOPT7_ADC1TRGSEL_MASK)
#define SIM_SOPT7_ADC1PRETRGSEL_MASK             0x1000u
#define SIM_SOPT7_ADC1PRETRGSEL_SHIFT            12
#define SIM_SOPT7_ADC1ALTTRGEN_MASK              0x8000u
#define SIM_SOPT7_ADC1ALTTRGEN_SHIFT             15
/* SDID Bit Fields */
#define SIM_SDID_PINID_MASK                      0xFu
#define SIM_SDID_PINID_SHIFT                     0
#define SIM_SDID_PINID(x)                        (((x)<<SIM_SDID_PINID_SHIFT)&SIM_SDID_PINID_MASK)
#define SIM_SDID_FAMID_MASK                      0x70u
#define SIM_SDID_FAMID_SHIFT                     4
#define SIM_SDID_FAMID(x)                        (((x)<<SIM_SDID_FAMID_SHIFT)&SIM_SDID_FAMID_MASK)
#define SIM_SDID_REVID_MASK                      0xF000u
#define SIM_SDID_REVID_SHIFT                     12
#define SIM_SDID_REVID(x)                        (((x)<<SIM_SDID_REVID_SHIFT)&SIM_SDID_REVID_MASK)
/* SCGC1 Bit Fields */
#define SIM_SCGC1_UART4_MASK                     0x400u
#define SIM_SCGC1_UART4_SHIFT                    10
#define SIM_SCGC1_UART5_MASK                     0x800u
#define SIM_SCGC1_UART5_SHIFT                    11
/* SCGC2 Bit Fields */
#define SIM_SCGC2_CGC12BDAC0_MASK                0x1000u
#define SIM_SCGC2_CGC12BDAC0_SHIFT               12
#define SIM_SCGC2_CGC12BDAC1_MASK                0x2000u
#define SIM_SCGC2_CGC12BDAC1_SHIFT               13
/* SCGC3 Bit Fields */
#define SIM_SCGC3_FLEXCAN1_MASK                  0x10u
#define SIM_SCGC3_FLEXCAN1_SHIFT                 4
#define SIM_SCGC3_SPI2_MASK                      0x1000u
#define SIM_SCGC3_SPI2_SHIFT                     12
#define SIM_SCGC3_SDHC_MASK                      0x20000u
#define SIM_SCGC3_SDHC_SHIFT                     17
#define SIM_SCGC3_FTM2_MASK                      0x1000000u
#define SIM_SCGC3_FTM2_SHIFT                     24
#define SIM_SCGC3_ADC1_MASK                      0x8000000u
#define SIM_SCGC3_ADC1_SHIFT                     27
#define SIM_SCGC3_SLCD_MASK                      0x40000000u
#define SIM_SCGC3_SLCD_SHIFT                     30
/* SCGC4 Bit Fields */
#define SIM_SCGC4_EWM_MASK                       0x2u
#define SIM_SCGC4_EWM_SHIFT                      1
#define SIM_SCGC4_CMT_MASK                       0x4u
#define SIM_SCGC4_CMT_SHIFT                      2
#define SIM_SCGC4_I2C0_MASK                      0x40u
#define SIM_SCGC4_I2C0_SHIFT                     6
#define SIM_SCGC4_I2C1_MASK                      0x80u
#define SIM_SCGC4_I2C1_SHIFT                     7
#define SIM_SCGC4_UART0_MASK                     0x400u
#define SIM_SCGC4_UART0_SHIFT                    10
#define SIM_SCGC4_UART1_MASK                     0x800u
#define SIM_SCGC4_UART1_SHIFT                    11
#define SIM_SCGC4_UART2_MASK                     0x1000u
#define SIM_SCGC4_UART2_SHIFT                    12
#define SIM_SCGC4_UART3_MASK                     0x2000u
#define SIM_SCGC4_UART3_SHIFT                    13
#define SIM_SCGC4_USBOTG_MASK                    0x40000u
#define SIM_SCGC4_USBOTG_SHIFT                   18
#define SIM_SCGC4_CMP_MASK                       0x80000u
#define SIM_SCGC4_CMP_SHIFT                      19
#define SIM_SCGC4_VREF_MASK                      0x100000u
#define SIM_SCGC4_VREF_SHIFT                     20
#define SIM_SCGC4_LLWU_MASK                      0x10000000u
#define SIM_SCGC4_LLWU_SHIFT                     28
/* SCGC5 Bit Fields */
#define SIM_SCGC5_LPTIMER_MASK                   0x1u
#define SIM_SCGC5_LPTIMER_SHIFT                  0
#define SIM_SCGC5_REGFILE_MASK                   0x2u
#define SIM_SCGC5_REGFILE_SHIFT                  1
#define SIM_SCGC5_TSI_MASK                       0x20u
#define SIM_SCGC5_TSI_SHIFT                      5
#define SIM_SCGC5_PORTA_MASK                     0x200u
#define SIM_SCGC5_PORTA_SHIFT                    9
#define SIM_SCGC5_PORTB_MASK                     0x400u
#define SIM_SCGC5_PORTB_SHIFT                    10
#define SIM_SCGC5_PORTC_MASK                     0x800u
#define SIM_SCGC5_PORTC_SHIFT                    11
#define SIM_SCGC5_PORTD_MASK                     0x1000u
#define SIM_SCGC5_PORTD_SHIFT                    12
#define SIM_SCGC5_PORTE_MASK                     0x2000u
#define SIM_SCGC5_PORTE_SHIFT                    13
/* SCGC6 Bit Fields */
#define SIM_SCGC6_FTFL_MASK                      0x1u
#define SIM_SCGC6_FTFL_SHIFT                     0
#define SIM_SCGC6_DMAMUX_MASK                    0x2u
#define SIM_SCGC6_DMAMUX_SHIFT                   1
#define SIM_SCGC6_FLEXCAN0_MASK                  0x10u
#define SIM_SCGC6_FLEXCAN0_SHIFT                 4
#define SIM_SCGC6_DSPI0_MASK                     0x1000u
#define SIM_SCGC6_DSPI0_SHIFT                    12
#define SIM_SCGC6_SPI1_MASK                      0x2000u
#define SIM_SCGC6_SPI1_SHIFT                     13
#define SIM_SCGC6_I2S_MASK                       0x8000u
#define SIM_SCGC6_I2S_SHIFT                      15
#define SIM_SCGC6_CRC_MASK                       0x40000u
#define SIM_SCGC6_CRC_SHIFT                      18
#define SIM_SCGC6_USBDCD_MASK                    0x200000u
#define SIM_SCGC6_USBDCD_SHIFT                   21
#define SIM_SCGC6_PDB_MASK                       0x400000u
#define SIM_SCGC6_PDB_SHIFT                      22
#define SIM_SCGC6_PIT_MASK                       0x800000u
#define SIM_SCGC6_PIT_SHIFT                      23
#define SIM_SCGC6_FTM0_MASK                      0x1000000u
#define SIM_SCGC6_FTM0_SHIFT                     24
#define SIM_SCGC6_FTM1_MASK                      0x2000000u
#define SIM_SCGC6_FTM1_SHIFT                     25
#define SIM_SCGC6_ADC0_MASK                      0x8000000u
#define SIM_SCGC6_ADC0_SHIFT                     27
#define SIM_SCGC6_RTC_MASK                       0x20000000u
#define SIM_SCGC6_RTC_SHIFT                      29
/* SCGC7 Bit Fields */
#define SIM_SCGC7_FLEXBUS_MASK                   0x1u
#define SIM_SCGC7_FLEXBUS_SHIFT                  0
#define SIM_SCGC7_DMA_MASK                       0x2u
#define SIM_SCGC7_DMA_SHIFT                      1
#define SIM_SCGC7_MPU_MASK                       0x4u
#define SIM_SCGC7_MPU_SHIFT                      2
/* CLKDIV1 Bit Fields */
#define SIM_CLKDIV1_OUTDIV4_MASK                 0xF0000u
#define SIM_CLKDIV1_OUTDIV4_SHIFT                16
#define SIM_CLKDIV1_OUTDIV4(x)                   (((x)<<SIM_CLKDIV1_OUTDIV4_SHIFT)&SIM_CLKDIV1_OUTDIV4_MASK)
#define SIM_CLKDIV1_OUTDIV3_MASK                 0xF00000u
#define SIM_CLKDIV1_OUTDIV3_SHIFT                20
#define SIM_CLKDIV1_OUTDIV3(x)                   (((x)<<SIM_CLKDIV1_OUTDIV3_SHIFT)&SIM_CLKDIV1_OUTDIV3_MASK)
#define SIM_CLKDIV1_OUTDIV2_MASK                 0xF000000u
#define SIM_CLKDIV1_OUTDIV2_SHIFT                24
#define SIM_CLKDIV1_OUTDIV2(x)                   (((x)<<SIM_CLKDIV1_OUTDIV2_SHIFT)&SIM_CLKDIV1_OUTDIV2_MASK)
#define SIM_CLKDIV1_OUTDIV1_MASK                 0xF0000000u
#define SIM_CLKDIV1_OUTDIV1_SHIFT                28
#define SIM_CLKDIV1_OUTDIV1(x)                   (((x)<<SIM_CLKDIV1_OUTDIV1_SHIFT)&SIM_CLKDIV1_OUTDIV1_MASK)
/* CLKDIV2 Bit Fields */
#define SIM_CLKDIV2_USBFRAC_MASK                 0x1u
#define SIM_CLKDIV2_USBFRAC_SHIFT                0
#define SIM_CLKDIV2_USBDIV_MASK                  0xEu
#define SIM_CLKDIV2_USBDIV_SHIFT                 1
#define SIM_CLKDIV2_USBDIV(x)                    (((x)<<SIM_CLKDIV2_USBDIV_SHIFT)&SIM_CLKDIV2_USBDIV_MASK)
#define SIM_CLKDIV2_I2SFRAC_MASK                 0xFF00u
#define SIM_CLKDIV2_I2SFRAC_SHIFT                8
#define SIM_CLKDIV2_I2SFRAC(x)                   (((x)<<SIM_CLKDIV2_I2SFRAC_SHIFT)&SIM_CLKDIV2_I2SFRAC_MASK)
#define SIM_CLKDIV2_I2SDIV_MASK                  0xFFF00000u
#define SIM_CLKDIV2_I2SDIV_SHIFT                 20
#define SIM_CLKDIV2_I2SDIV(x)                    (((x)<<SIM_CLKDIV2_I2SDIV_SHIFT)&SIM_CLKDIV2_I2SDIV_MASK)
/* FCFG1 Bit Fields */
#define SIM_FCFG1_DEPART_MASK                    0xF00u
#define SIM_FCFG1_DEPART_SHIFT                   8
#define SIM_FCFG1_DEPART(x)                      (((x)<<SIM_FCFG1_DEPART_SHIFT)&SIM_FCFG1_DEPART_MASK)
#define SIM_FCFG1_EESIZE_MASK                    0xF0000u
#define SIM_FCFG1_EESIZE_SHIFT                   16
#define SIM_FCFG1_EESIZE(x)                      (((x)<<SIM_FCFG1_EESIZE_SHIFT)&SIM_FCFG1_EESIZE_MASK)
#define SIM_FCFG1_FSIZE_MASK                     0xFF000000u
#define SIM_FCFG1_FSIZE_SHIFT                    24
#define SIM_FCFG1_FSIZE(x)                       (((x)<<SIM_FCFG1_FSIZE_SHIFT)&SIM_FCFG1_FSIZE_MASK)
/* FCFG2 Bit Fields */
#define SIM_FCFG2_MAXADDR1_MASK                  0x3F0000u
#define SIM_FCFG2_MAXADDR1_SHIFT                 16
#define SIM_FCFG2_MAXADDR1(x)                    (((x)<<SIM_FCFG2_MAXADDR1_SHIFT)&SIM_FCFG2_MAXADDR1_MASK)
#define SIM_FCFG2_PFLSH_MASK                     0x800000u
#define SIM_FCFG2_PFLSH_SHIFT                    23
#define SIM_FCFG2_MAXADDR0_MASK                  0x3F000000u
#define SIM_FCFG2_MAXADDR0_SHIFT                 24
#define SIM_FCFG2_MAXADDR0(x)                    (((x)<<SIM_FCFG2_MAXADDR0_SHIFT)&SIM_FCFG2_MAXADDR0_MASK)
#define SIM_FCFG2_SWAPPFLSH_MASK                 0x80000000u
#define SIM_FCFG2_SWAPPFLSH_SHIFT                31
/* UIDH Bit Fields */
#define SIM_UIDH_UID_MASK                        0xFFFFFFFFu
#define SIM_UIDH_UID_SHIFT                       0
#define SIM_UIDH_UID(x)                          (((x)<<SIM_UIDH_UID_SHIFT)&SIM_UIDH_UID_MASK)
/* UIDMH Bit Fields */
#define SIM_UIDMH_UID_MASK                       0xFFFFFFFFu
#define SIM_UIDMH_UID_SHIFT                      0
#define SIM_UIDMH_UID(x)                         (((x)<<SIM_UIDMH_UID_SHIFT)&SIM_UIDMH_UID_MASK)
/* UIDML Bit Fields */
#define SIM_UIDML_UID_MASK                       0xFFFFFFFFu
#define SIM_UIDML_UID_SHIFT                      0
#define SIM_UIDML_UID(x)                         (((x)<<SIM_UIDML_UID_SHIFT)&SIM_UIDML_UID_MASK)
/* UIDL Bit Fields */
#define SIM_UIDL_UID_MASK                        0xFFFFFFFFu
#define SIM_UIDL_UID_SHIFT                       0
#define SIM_UIDL_UID(x)                          (((x)<<SIM_UIDL_UID_SHIFT)&SIM_UIDL_UID_MASK)

/*! \} */ /* end of group SIM_Register_Masks */


/* SIM - Peripheral instance base addresses */
/*! Peripheral SIM base pointer */
#define SIM_BASE_PTR                             ((SIM_MemMapPtr)0x40047000u)

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros */
/*! \{ */


/* SIM - Register instance definitions */
/* SIM */
#define SIM_SOPT1                                SIM_SOPT1_REG(SIM_BASE_PTR)
#define SIM_SOPT2                                SIM_SOPT2_REG(SIM_BASE_PTR)
#define SIM_SOPT4                                SIM_SOPT4_REG(SIM_BASE_PTR)
#define SIM_SOPT5                                SIM_SOPT5_REG(SIM_BASE_PTR)
#define SIM_SOPT6                                SIM_SOPT6_REG(SIM_BASE_PTR)
#define SIM_SOPT7                                SIM_SOPT7_REG(SIM_BASE_PTR)
#define SIM_SDID                                 SIM_SDID_REG(SIM_BASE_PTR)
#define SIM_SCGC1                                SIM_SCGC1_REG(SIM_BASE_PTR)
#define SIM_SCGC2                                SIM_SCGC2_REG(SIM_BASE_PTR)
#define SIM_SCGC3                                SIM_SCGC3_REG(SIM_BASE_PTR)
#define SIM_SCGC4                                SIM_SCGC4_REG(SIM_BASE_PTR)
#define SIM_SCGC5                                SIM_SCGC5_REG(SIM_BASE_PTR)
#define SIM_SCGC6                                SIM_SCGC6_REG(SIM_BASE_PTR)
#define SIM_SCGC7                                SIM_SCGC7_REG(SIM_BASE_PTR)
#define SIM_CLKDIV1                              SIM_CLKDIV1_REG(SIM_BASE_PTR)
#define SIM_CLKDIV2                              SIM_CLKDIV2_REG(SIM_BASE_PTR)
#define SIM_FCFG1                                SIM_FCFG1_REG(SIM_BASE_PTR)
#define SIM_FCFG2                                SIM_FCFG2_REG(SIM_BASE_PTR)
#define SIM_UIDH                                 SIM_UIDH_REG(SIM_BASE_PTR)
#define SIM_UIDMH                                SIM_UIDMH_REG(SIM_BASE_PTR)
#define SIM_UIDML                                SIM_UIDML_REG(SIM_BASE_PTR)
#define SIM_UIDL                                 SIM_UIDL_REG(SIM_BASE_PTR)

/*! \} */ /* end of group SIM_Register_Accessor_Macros */


/*! \} */ /* end of group SIM_Peripheral */


/* ----------------------------------------------------------------------------
   -- LCD
   ---------------------------------------------------------------------------- */

/*! \addtogroup LCD_Peripheral LCD */
/*! \{ */

/*! LCD - Peripheral register structure */
typedef struct LCD_MemMap {
  uint32_t GCR;                                    /*!< LCD general control register, offset: 0x0 */
  uint32_t AR;                                     /*!< LCD auxiliary register, offset: 0x4 */
  uint32_t FDCR;                                   /*!< LCD fault detect control register, offset: 0x8 */
  uint32_t FDSR;                                   /*!< LCD fault detect status register, offset: 0xC */
  uint32_t PEN[2];                                 /*!< LCD pin enable register, array offset: 0x10, array step: 0x4 */
  uint32_t BPEN[2];                                /*!< LCD backplane enable register, array offset: 0x18, array step: 0x4 */
  uint32_t WF[16];                                 /*!< LCD waveform register, array offset: 0x20, array step: 0x4 */
} volatile *LCD_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LCD - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup LCD_Register_Accessor_Macros LCD - Register accessor macros */
/*! \{ */


/* LCD - Register accessors */
#define LCD_GCR_REG(base)                        ((base)->GCR)
#define LCD_AR_REG(base)                         ((base)->AR)
#define LCD_FDCR_REG(base)                       ((base)->FDCR)
#define LCD_FDSR_REG(base)                       ((base)->FDSR)
#define LCD_PEN_REG(base,index)                  ((base)->PEN[index])
#define LCD_BPEN_REG(base,index)                 ((base)->BPEN[index])
#define LCD_WF_REG(base,index)                   ((base)->WF[index])

/*! \} */ /* end of group LCD_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LCD Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup LCD_Register_Masks LCD Register Masks */
/*! \{ */

/* GCR Bit Fields */
#define LCD_GCR_DUTY_MASK                        0x7u
#define LCD_GCR_DUTY_SHIFT                       0
#define LCD_GCR_DUTY(x)                          (((x)<<LCD_GCR_DUTY_SHIFT)&LCD_GCR_DUTY_MASK)
#define LCD_GCR_LCLK_MASK                        0x38u
#define LCD_GCR_LCLK_SHIFT                       3
#define LCD_GCR_LCLK(x)                          (((x)<<LCD_GCR_LCLK_SHIFT)&LCD_GCR_LCLK_MASK)
#define LCD_GCR_SOURCE_MASK                      0x40u
#define LCD_GCR_SOURCE_SHIFT                     6
#define LCD_GCR_LCDEN_MASK                       0x80u
#define LCD_GCR_LCDEN_SHIFT                      7
#define LCD_GCR_LCDSTP_MASK                      0x100u
#define LCD_GCR_LCDSTP_SHIFT                     8
#define LCD_GCR_LCDWAIT_MASK                     0x200u
#define LCD_GCR_LCDWAIT_SHIFT                    9
#define LCD_GCR_ALTDIV_MASK                      0x3000u
#define LCD_GCR_ALTDIV_SHIFT                     12
#define LCD_GCR_ALTDIV(x)                        (((x)<<LCD_GCR_ALTDIV_SHIFT)&LCD_GCR_ALTDIV_MASK)
#define LCD_GCR_FDCIEN_MASK                      0x4000u
#define LCD_GCR_FDCIEN_SHIFT                     14
#define LCD_GCR_LCDIEN_MASK                      0x8000u
#define LCD_GCR_LCDIEN_SHIFT                     15
#define LCD_GCR_VSUPPLY_MASK                     0x30000u
#define LCD_GCR_VSUPPLY_SHIFT                    16
#define LCD_GCR_VSUPPLY(x)                       (((x)<<LCD_GCR_VSUPPLY_SHIFT)&LCD_GCR_VSUPPLY_MASK)
#define LCD_GCR_LADJ_MASK                        0x300000u
#define LCD_GCR_LADJ_SHIFT                       20
#define LCD_GCR_LADJ(x)                          (((x)<<LCD_GCR_LADJ_SHIFT)&LCD_GCR_LADJ_MASK)
#define LCD_GCR_HREFSEL_MASK                     0x400000u
#define LCD_GCR_HREFSEL_SHIFT                    22
#define LCD_GCR_CPSEL_MASK                       0x800000u
#define LCD_GCR_CPSEL_SHIFT                      23
#define LCD_GCR_RVTRIM_MASK                      0xF000000u
#define LCD_GCR_RVTRIM_SHIFT                     24
#define LCD_GCR_RVTRIM(x)                        (((x)<<LCD_GCR_RVTRIM_SHIFT)&LCD_GCR_RVTRIM_MASK)
#define LCD_GCR_RVEN_MASK                        0x80000000u
#define LCD_GCR_RVEN_SHIFT                       31
/* AR Bit Fields */
#define LCD_AR_BRATE_MASK                        0x7u
#define LCD_AR_BRATE_SHIFT                       0
#define LCD_AR_BRATE(x)                          (((x)<<LCD_AR_BRATE_SHIFT)&LCD_AR_BRATE_MASK)
#define LCD_AR_BMODE_MASK                        0x8u
#define LCD_AR_BMODE_SHIFT                       3
#define LCD_AR_BLANK_MASK                        0x20u
#define LCD_AR_BLANK_SHIFT                       5
#define LCD_AR_ALT_MASK                          0x40u
#define LCD_AR_ALT_SHIFT                         6
#define LCD_AR_BLINK_MASK                        0x80u
#define LCD_AR_BLINK_SHIFT                       7
#define LCD_AR_LCDIF_MASK                        0x8000u
#define LCD_AR_LCDIF_SHIFT                       15
/* FDCR Bit Fields */
#define LCD_FDCR_FDPINID_MASK                    0x3Fu
#define LCD_FDCR_FDPINID_SHIFT                   0
#define LCD_FDCR_FDPINID(x)                      (((x)<<LCD_FDCR_FDPINID_SHIFT)&LCD_FDCR_FDPINID_MASK)
#define LCD_FDCR_FDBPEN_MASK                     0x40u
#define LCD_FDCR_FDBPEN_SHIFT                    6
#define LCD_FDCR_FDEN_MASK                       0x80u
#define LCD_FDCR_FDEN_SHIFT                      7
#define LCD_FDCR_FDSWW_MASK                      0xE00u
#define LCD_FDCR_FDSWW_SHIFT                     9
#define LCD_FDCR_FDSWW(x)                        (((x)<<LCD_FDCR_FDSWW_SHIFT)&LCD_FDCR_FDSWW_MASK)
#define LCD_FDCR_FDPRS_MASK                      0x7000u
#define LCD_FDCR_FDPRS_SHIFT                     12
#define LCD_FDCR_FDPRS(x)                        (((x)<<LCD_FDCR_FDPRS_SHIFT)&LCD_FDCR_FDPRS_MASK)
/* FDSR Bit Fields */
#define LCD_FDSR_FDCNT_MASK                      0xFFu
#define LCD_FDSR_FDCNT_SHIFT                     0
#define LCD_FDSR_FDCNT(x)                        (((x)<<LCD_FDSR_FDCNT_SHIFT)&LCD_FDSR_FDCNT_MASK)
#define LCD_FDSR_FDCF_MASK                       0x8000u
#define LCD_FDSR_FDCF_SHIFT                      15
/* PEN Bit Fields */
#define LCD_PEN_PEN_MASK                         0xFFFFFFFFu
#define LCD_PEN_PEN_SHIFT                        0
#define LCD_PEN_PEN(x)                           (((x)<<LCD_PEN_PEN_SHIFT)&LCD_PEN_PEN_MASK)
/* BPEN Bit Fields */
#define LCD_BPEN_BPEN_MASK                       0xFFFFFFFFu
#define LCD_BPEN_BPEN_SHIFT                      0
#define LCD_BPEN_BPEN(x)                         (((x)<<LCD_BPEN_BPEN_SHIFT)&LCD_BPEN_BPEN_MASK)
/* WF Bit Fields */
#define LCD_WF_WF0_MASK                          0xFFu
#define LCD_WF_WF0_SHIFT                         0
#define LCD_WF_WF0(x)                            (((x)<<LCD_WF_WF0_SHIFT)&LCD_WF_WF0_MASK)
#define LCD_WF_WF60_MASK                         0xFFu
#define LCD_WF_WF60_SHIFT                        0
#define LCD_WF_WF60(x)                           (((x)<<LCD_WF_WF60_SHIFT)&LCD_WF_WF60_MASK)
#define LCD_WF_WF56_MASK                         0xFFu
#define LCD_WF_WF56_SHIFT                        0
#define LCD_WF_WF56(x)                           (((x)<<LCD_WF_WF56_SHIFT)&LCD_WF_WF56_MASK)
#define LCD_WF_WF52_MASK                         0xFFu
#define LCD_WF_WF52_SHIFT                        0
#define LCD_WF_WF52(x)                           (((x)<<LCD_WF_WF52_SHIFT)&LCD_WF_WF52_MASK)
#define LCD_WF_WF4_MASK                          0xFFu
#define LCD_WF_WF4_SHIFT                         0
#define LCD_WF_WF4(x)                            (((x)<<LCD_WF_WF4_SHIFT)&LCD_WF_WF4_MASK)
#define LCD_WF_WF48_MASK                         0xFFu
#define LCD_WF_WF48_SHIFT                        0
#define LCD_WF_WF48(x)                           (((x)<<LCD_WF_WF48_SHIFT)&LCD_WF_WF48_MASK)
#define LCD_WF_WF44_MASK                         0xFFu
#define LCD_WF_WF44_SHIFT                        0
#define LCD_WF_WF44(x)                           (((x)<<LCD_WF_WF44_SHIFT)&LCD_WF_WF44_MASK)
#define LCD_WF_WF40_MASK                         0xFFu
#define LCD_WF_WF40_SHIFT                        0
#define LCD_WF_WF40(x)                           (((x)<<LCD_WF_WF40_SHIFT)&LCD_WF_WF40_MASK)
#define LCD_WF_WF8_MASK                          0xFFu
#define LCD_WF_WF8_SHIFT                         0
#define LCD_WF_WF8(x)                            (((x)<<LCD_WF_WF8_SHIFT)&LCD_WF_WF8_MASK)
#define LCD_WF_WF36_MASK                         0xFFu
#define LCD_WF_WF36_SHIFT                        0
#define LCD_WF_WF36(x)                           (((x)<<LCD_WF_WF36_SHIFT)&LCD_WF_WF36_MASK)
#define LCD_WF_WF32_MASK                         0xFFu
#define LCD_WF_WF32_SHIFT                        0
#define LCD_WF_WF32(x)                           (((x)<<LCD_WF_WF32_SHIFT)&LCD_WF_WF32_MASK)
#define LCD_WF_WF28_MASK                         0xFFu
#define LCD_WF_WF28_SHIFT                        0
#define LCD_WF_WF28(x)                           (((x)<<LCD_WF_WF28_SHIFT)&LCD_WF_WF28_MASK)
#define LCD_WF_WF12_MASK                         0xFFu
#define LCD_WF_WF12_SHIFT                        0
#define LCD_WF_WF12(x)                           (((x)<<LCD_WF_WF12_SHIFT)&LCD_WF_WF12_MASK)
#define LCD_WF_WF24_MASK                         0xFFu
#define LCD_WF_WF24_SHIFT                        0
#define LCD_WF_WF24(x)                           (((x)<<LCD_WF_WF24_SHIFT)&LCD_WF_WF24_MASK)
#define LCD_WF_WF20_MASK                         0xFFu
#define LCD_WF_WF20_SHIFT                        0
#define LCD_WF_WF20(x)                           (((x)<<LCD_WF_WF20_SHIFT)&LCD_WF_WF20_MASK)
#define LCD_WF_WF16_MASK                         0xFFu
#define LCD_WF_WF16_SHIFT                        0
#define LCD_WF_WF16(x)                           (((x)<<LCD_WF_WF16_SHIFT)&LCD_WF_WF16_MASK)
#define LCD_WF_WF5_MASK                          0xFF00u
#define LCD_WF_WF5_SHIFT                         8
#define LCD_WF_WF5(x)                            (((x)<<LCD_WF_WF5_SHIFT)&LCD_WF_WF5_MASK)
#define LCD_WF_WF49_MASK                         0xFF00u
#define LCD_WF_WF49_SHIFT                        8
#define LCD_WF_WF49(x)                           (((x)<<LCD_WF_WF49_SHIFT)&LCD_WF_WF49_MASK)
#define LCD_WF_WF45_MASK                         0xFF00u
#define LCD_WF_WF45_SHIFT                        8
#define LCD_WF_WF45(x)                           (((x)<<LCD_WF_WF45_SHIFT)&LCD_WF_WF45_MASK)
#define LCD_WF_WF61_MASK                         0xFF00u
#define LCD_WF_WF61_SHIFT                        8
#define LCD_WF_WF61(x)                           (((x)<<LCD_WF_WF61_SHIFT)&LCD_WF_WF61_MASK)
#define LCD_WF_WF25_MASK                         0xFF00u
#define LCD_WF_WF25_SHIFT                        8
#define LCD_WF_WF25(x)                           (((x)<<LCD_WF_WF25_SHIFT)&LCD_WF_WF25_MASK)
#define LCD_WF_WF17_MASK                         0xFF00u
#define LCD_WF_WF17_SHIFT                        8
#define LCD_WF_WF17(x)                           (((x)<<LCD_WF_WF17_SHIFT)&LCD_WF_WF17_MASK)
#define LCD_WF_WF41_MASK                         0xFF00u
#define LCD_WF_WF41_SHIFT                        8
#define LCD_WF_WF41(x)                           (((x)<<LCD_WF_WF41_SHIFT)&LCD_WF_WF41_MASK)
#define LCD_WF_WF13_MASK                         0xFF00u
#define LCD_WF_WF13_SHIFT                        8
#define LCD_WF_WF13(x)                           (((x)<<LCD_WF_WF13_SHIFT)&LCD_WF_WF13_MASK)
#define LCD_WF_WF57_MASK                         0xFF00u
#define LCD_WF_WF57_SHIFT                        8
#define LCD_WF_WF57(x)                           (((x)<<LCD_WF_WF57_SHIFT)&LCD_WF_WF57_MASK)
#define LCD_WF_WF53_MASK                         0xFF00u
#define LCD_WF_WF53_SHIFT                        8
#define LCD_WF_WF53(x)                           (((x)<<LCD_WF_WF53_SHIFT)&LCD_WF_WF53_MASK)
#define LCD_WF_WF37_MASK                         0xFF00u
#define LCD_WF_WF37_SHIFT                        8
#define LCD_WF_WF37(x)                           (((x)<<LCD_WF_WF37_SHIFT)&LCD_WF_WF37_MASK)
#define LCD_WF_WF9_MASK                          0xFF00u
#define LCD_WF_WF9_SHIFT                         8
#define LCD_WF_WF9(x)                            (((x)<<LCD_WF_WF9_SHIFT)&LCD_WF_WF9_MASK)
#define LCD_WF_WF1_MASK                          0xFF00u
#define LCD_WF_WF1_SHIFT                         8
#define LCD_WF_WF1(x)                            (((x)<<LCD_WF_WF1_SHIFT)&LCD_WF_WF1_MASK)
#define LCD_WF_WF29_MASK                         0xFF00u
#define LCD_WF_WF29_SHIFT                        8
#define LCD_WF_WF29(x)                           (((x)<<LCD_WF_WF29_SHIFT)&LCD_WF_WF29_MASK)
#define LCD_WF_WF33_MASK                         0xFF00u
#define LCD_WF_WF33_SHIFT                        8
#define LCD_WF_WF33(x)                           (((x)<<LCD_WF_WF33_SHIFT)&LCD_WF_WF33_MASK)
#define LCD_WF_WF21_MASK                         0xFF00u
#define LCD_WF_WF21_SHIFT                        8
#define LCD_WF_WF21(x)                           (((x)<<LCD_WF_WF21_SHIFT)&LCD_WF_WF21_MASK)
#define LCD_WF_WF26_MASK                         0xFF0000u
#define LCD_WF_WF26_SHIFT                        16
#define LCD_WF_WF26(x)                           (((x)<<LCD_WF_WF26_SHIFT)&LCD_WF_WF26_MASK)
#define LCD_WF_WF46_MASK                         0xFF0000u
#define LCD_WF_WF46_SHIFT                        16
#define LCD_WF_WF46(x)                           (((x)<<LCD_WF_WF46_SHIFT)&LCD_WF_WF46_MASK)
#define LCD_WF_WF6_MASK                          0xFF0000u
#define LCD_WF_WF6_SHIFT                         16
#define LCD_WF_WF6(x)                            (((x)<<LCD_WF_WF6_SHIFT)&LCD_WF_WF6_MASK)
#define LCD_WF_WF42_MASK                         0xFF0000u
#define LCD_WF_WF42_SHIFT                        16
#define LCD_WF_WF42(x)                           (((x)<<LCD_WF_WF42_SHIFT)&LCD_WF_WF42_MASK)
#define LCD_WF_WF18_MASK                         0xFF0000u
#define LCD_WF_WF18_SHIFT                        16
#define LCD_WF_WF18(x)                           (((x)<<LCD_WF_WF18_SHIFT)&LCD_WF_WF18_MASK)
#define LCD_WF_WF38_MASK                         0xFF0000u
#define LCD_WF_WF38_SHIFT                        16
#define LCD_WF_WF38(x)                           (((x)<<LCD_WF_WF38_SHIFT)&LCD_WF_WF38_MASK)
#define LCD_WF_WF22_MASK                         0xFF0000u
#define LCD_WF_WF22_SHIFT                        16
#define LCD_WF_WF22(x)                           (((x)<<LCD_WF_WF22_SHIFT)&LCD_WF_WF22_MASK)
#define LCD_WF_WF34_MASK                         0xFF0000u
#define LCD_WF_WF34_SHIFT                        16
#define LCD_WF_WF34(x)                           (((x)<<LCD_WF_WF34_SHIFT)&LCD_WF_WF34_MASK)
#define LCD_WF_WF50_MASK                         0xFF0000u
#define LCD_WF_WF50_SHIFT                        16
#define LCD_WF_WF50(x)                           (((x)<<LCD_WF_WF50_SHIFT)&LCD_WF_WF50_MASK)
#define LCD_WF_WF14_MASK                         0xFF0000u
#define LCD_WF_WF14_SHIFT                        16
#define LCD_WF_WF14(x)                           (((x)<<LCD_WF_WF14_SHIFT)&LCD_WF_WF14_MASK)
#define LCD_WF_WF54_MASK                         0xFF0000u
#define LCD_WF_WF54_SHIFT                        16
#define LCD_WF_WF54(x)                           (((x)<<LCD_WF_WF54_SHIFT)&LCD_WF_WF54_MASK)
#define LCD_WF_WF2_MASK                          0xFF0000u
#define LCD_WF_WF2_SHIFT                         16
#define LCD_WF_WF2(x)                            (((x)<<LCD_WF_WF2_SHIFT)&LCD_WF_WF2_MASK)
#define LCD_WF_WF58_MASK                         0xFF0000u
#define LCD_WF_WF58_SHIFT                        16
#define LCD_WF_WF58(x)                           (((x)<<LCD_WF_WF58_SHIFT)&LCD_WF_WF58_MASK)
#define LCD_WF_WF30_MASK                         0xFF0000u
#define LCD_WF_WF30_SHIFT                        16
#define LCD_WF_WF30(x)                           (((x)<<LCD_WF_WF30_SHIFT)&LCD_WF_WF30_MASK)
#define LCD_WF_WF62_MASK                         0xFF0000u
#define LCD_WF_WF62_SHIFT                        16
#define LCD_WF_WF62(x)                           (((x)<<LCD_WF_WF62_SHIFT)&LCD_WF_WF62_MASK)
#define LCD_WF_WF10_MASK                         0xFF0000u
#define LCD_WF_WF10_SHIFT                        16
#define LCD_WF_WF10(x)                           (((x)<<LCD_WF_WF10_SHIFT)&LCD_WF_WF10_MASK)
#define LCD_WF_WF63_MASK                         0xFF000000u
#define LCD_WF_WF63_SHIFT                        24
#define LCD_WF_WF63(x)                           (((x)<<LCD_WF_WF63_SHIFT)&LCD_WF_WF63_MASK)
#define LCD_WF_WF59_MASK                         0xFF000000u
#define LCD_WF_WF59_SHIFT                        24
#define LCD_WF_WF59(x)                           (((x)<<LCD_WF_WF59_SHIFT)&LCD_WF_WF59_MASK)
#define LCD_WF_WF55_MASK                         0xFF000000u
#define LCD_WF_WF55_SHIFT                        24
#define LCD_WF_WF55(x)                           (((x)<<LCD_WF_WF55_SHIFT)&LCD_WF_WF55_MASK)
#define LCD_WF_WF3_MASK                          0xFF000000u
#define LCD_WF_WF3_SHIFT                         24
#define LCD_WF_WF3(x)                            (((x)<<LCD_WF_WF3_SHIFT)&LCD_WF_WF3_MASK)
#define LCD_WF_WF51_MASK                         0xFF000000u
#define LCD_WF_WF51_SHIFT                        24
#define LCD_WF_WF51(x)                           (((x)<<LCD_WF_WF51_SHIFT)&LCD_WF_WF51_MASK)
#define LCD_WF_WF47_MASK                         0xFF000000u
#define LCD_WF_WF47_SHIFT                        24
#define LCD_WF_WF47(x)                           (((x)<<LCD_WF_WF47_SHIFT)&LCD_WF_WF47_MASK)
#define LCD_WF_WF43_MASK                         0xFF000000u
#define LCD_WF_WF43_SHIFT                        24
#define LCD_WF_WF43(x)                           (((x)<<LCD_WF_WF43_SHIFT)&LCD_WF_WF43_MASK)
#define LCD_WF_WF7_MASK                          0xFF000000u
#define LCD_WF_WF7_SHIFT                         24
#define LCD_WF_WF7(x)                            (((x)<<LCD_WF_WF7_SHIFT)&LCD_WF_WF7_MASK)
#define LCD_WF_WF39_MASK                         0xFF000000u
#define LCD_WF_WF39_SHIFT                        24
#define LCD_WF_WF39(x)                           (((x)<<LCD_WF_WF39_SHIFT)&LCD_WF_WF39_MASK)
#define LCD_WF_WF35_MASK                         0xFF000000u
#define LCD_WF_WF35_SHIFT                        24
#define LCD_WF_WF35(x)                           (((x)<<LCD_WF_WF35_SHIFT)&LCD_WF_WF35_MASK)
#define LCD_WF_WF31_MASK                         0xFF000000u
#define LCD_WF_WF31_SHIFT                        24
#define LCD_WF_WF31(x)                           (((x)<<LCD_WF_WF31_SHIFT)&LCD_WF_WF31_MASK)
#define LCD_WF_WF11_MASK                         0xFF000000u
#define LCD_WF_WF11_SHIFT                        24
#define LCD_WF_WF11(x)                           (((x)<<LCD_WF_WF11_SHIFT)&LCD_WF_WF11_MASK)
#define LCD_WF_WF27_MASK                         0xFF000000u
#define LCD_WF_WF27_SHIFT                        24
#define LCD_WF_WF27(x)                           (((x)<<LCD_WF_WF27_SHIFT)&LCD_WF_WF27_MASK)
#define LCD_WF_WF23_MASK                         0xFF000000u
#define LCD_WF_WF23_SHIFT                        24
#define LCD_WF_WF23(x)                           (((x)<<LCD_WF_WF23_SHIFT)&LCD_WF_WF23_MASK)
#define LCD_WF_WF19_MASK                         0xFF000000u
#define LCD_WF_WF19_SHIFT                        24
#define LCD_WF_WF19(x)                           (((x)<<LCD_WF_WF19_SHIFT)&LCD_WF_WF19_MASK)
#define LCD_WF_WF15_MASK                         0xFF000000u
#define LCD_WF_WF15_SHIFT                        24
#define LCD_WF_WF15(x)                           (((x)<<LCD_WF_WF15_SHIFT)&LCD_WF_WF15_MASK)

/*! \} */ /* end of group LCD_Register_Masks */


/* LCD - Peripheral instance base addresses */
/*! Peripheral SLCD base pointer */
#define SLCD_BASE_PTR                            ((LCD_MemMapPtr)0x400BE000u)

/* ----------------------------------------------------------------------------
   -- LCD - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup LCD_Register_Accessor_Macros LCD - Register accessor macros */
/*! \{ */


/* LCD - Register instance definitions */
/* SLCD */
#define LCD_GCR                                  LCD_GCR_REG(SLCD_BASE_PTR)
#define LCD_AR                                   LCD_AR_REG(SLCD_BASE_PTR)
#define LCD_FDCR                                 LCD_FDCR_REG(SLCD_BASE_PTR)
#define LCD_FDSR                                 LCD_FDSR_REG(SLCD_BASE_PTR)
#define LCD_PENL                                 LCD_PEN_REG(SLCD_BASE_PTR,0)
#define LCD_PENH                                 LCD_PEN_REG(SLCD_BASE_PTR,1)
#define LCD_BPENL                                LCD_BPEN_REG(SLCD_BASE_PTR,0)
#define LCD_BPENH                                LCD_BPEN_REG(SLCD_BASE_PTR,1)
#define LCD_WF3TO0                               LCD_WF_REG(SLCD_BASE_PTR,0)
#define LCD_WF7TO4                               LCD_WF_REG(SLCD_BASE_PTR,1)
#define LCD_WF11TO8                              LCD_WF_REG(SLCD_BASE_PTR,2)
#define LCD_WF15TO12                             LCD_WF_REG(SLCD_BASE_PTR,3)
#define LCD_WF19TO16                             LCD_WF_REG(SLCD_BASE_PTR,4)
#define LCD_WF23TO20                             LCD_WF_REG(SLCD_BASE_PTR,5)
#define LCD_WF27TO24                             LCD_WF_REG(SLCD_BASE_PTR,6)
#define LCD_WF31TO28                             LCD_WF_REG(SLCD_BASE_PTR,7)
#define LCD_WF35TO32                             LCD_WF_REG(SLCD_BASE_PTR,8)
#define LCD_WF39TO36                             LCD_WF_REG(SLCD_BASE_PTR,9)
#define LCD_WF43TO40                             LCD_WF_REG(SLCD_BASE_PTR,10)
#define LCD_WF47TO44                             LCD_WF_REG(SLCD_BASE_PTR,11)
#define LCD_WF51TO48                             LCD_WF_REG(SLCD_BASE_PTR,12)
#define LCD_WF55TO52                             LCD_WF_REG(SLCD_BASE_PTR,13)
#define LCD_WF59TO56                             LCD_WF_REG(SLCD_BASE_PTR,14)
#define LCD_WF63TO60                             LCD_WF_REG(SLCD_BASE_PTR,15)

/*! \} */ /* end of group LCD_Register_Accessor_Macros */


/*! \} */ /* end of group LCD_Peripheral */


/* ----------------------------------------------------------------------------
   -- SPI
   ---------------------------------------------------------------------------- */

/*! \addtogroup SPI_Peripheral SPI */
/*! \{ */

/*! SPI - Peripheral register structure */
typedef struct SPI_MemMap {
  uint32_t MCR;                                    /*!< DSPI Module Configuration Register, offset: 0x0 */
  uint32_t HCR;                                    /*!< DSPI Hardware Configuration Register, offset: 0x4 */
  uint32_t TCR;                                    /*!< DSPI Transfer Count Register, offset: 0x8 */
  union {                                          /* offset: 0xC */
    uint32_t CTAR[2];                                /*!< DSPI Clock and Transfer Attributes Register (In Master Mode), array offset: 0xC, array step: 0x4 */
    uint32_t CTAR_SLAVE[1];                          /*!< DSPI Clock and Transfer Attributes Register (In Slave Mode), array offset: 0xC, array step: 0x4 */
  };
  uint8_t RESERVED_0[24];
  uint32_t SR;                                     /*!< DSPI Status Register, offset: 0x2C */
  uint32_t RSER;                                   /*!< DSPI DMA/Interrupt Request Select and Enable Register, offset: 0x30 */
  union {                                          /* offset: 0x34 */
    uint32_t PUSHR;                                  /*!< DSPI PUSH TX FIFO Register In Master Mode, offset: 0x34 */
    uint32_t PUSHR_SLAVE;                            /*!< DSPI PUSH TX FIFO Register In Slave Mode, offset: 0x34 */
  };
  uint32_t POPR;                                   /*!< DSPI POP RX FIFO Register, offset: 0x38 */
  uint32_t TXFR0;                                  /*!< DSPI Transmit FIFO Registers, offset: 0x3C */
  uint32_t TXFR1;                                  /*!< DSPI Transmit FIFO Registers, offset: 0x40 */
  uint32_t TXFR2;                                  /*!< DSPI Transmit FIFO Registers, offset: 0x44 */
  uint32_t TXFR3;                                  /*!< DSPI Transmit FIFO Registers, offset: 0x48 */
  uint8_t RESERVED_1[48];
  uint32_t RXFR0;                                  /*!< DSPI Receive FIFO Registers, offset: 0x7C */
  uint32_t RXFR1;                                  /*!< DSPI Receive FIFO Registers, offset: 0x80 */
  uint32_t RXFR2;                                  /*!< DSPI Receive FIFO Registers, offset: 0x84 */
  uint32_t RXFR3;                                  /*!< DSPI Receive FIFO Registers, offset: 0x88 */
} volatile *SPI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros */
/*! \{ */


/* SPI - Register accessors */
#define SPI_MCR_REG(base)                        ((base)->MCR)
#define SPI_HCR_REG(base)                        ((base)->HCR)
#define SPI_TCR_REG(base)                        ((base)->TCR)
#define SPI_CTAR_REG(base,index2)                ((base)->CTAR[index2])
#define SPI_CTAR_SLAVE_REG(base,index2)          ((base)->CTAR_SLAVE[index2])
#define SPI_SR_REG(base)                         ((base)->SR)
#define SPI_RSER_REG(base)                       ((base)->RSER)
#define SPI_PUSHR_REG(base)                      ((base)->PUSHR)
#define SPI_PUSHR_SLAVE_REG(base)                ((base)->PUSHR_SLAVE)
#define SPI_POPR_REG(base)                       ((base)->POPR)
#define SPI_TXFR0_REG(base)                      ((base)->TXFR0)
#define SPI_TXFR1_REG(base)                      ((base)->TXFR1)
#define SPI_TXFR2_REG(base)                      ((base)->TXFR2)
#define SPI_TXFR3_REG(base)                      ((base)->TXFR3)
#define SPI_RXFR0_REG(base)                      ((base)->RXFR0)
#define SPI_RXFR1_REG(base)                      ((base)->RXFR1)
#define SPI_RXFR2_REG(base)                      ((base)->RXFR2)
#define SPI_RXFR3_REG(base)                      ((base)->RXFR3)

/*! \} */ /* end of group SPI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup SPI_Register_Masks SPI Register Masks */
/*! \{ */

/* MCR Bit Fields */
#define SPI_MCR_HALT_MASK                        0x1u
#define SPI_MCR_HALT_SHIFT                       0
#define SPI_MCR_PES_MASK                         0x2u
#define SPI_MCR_PES_SHIFT                        1
#define SPI_MCR_SMPL_PT_MASK                     0x300u
#define SPI_MCR_SMPL_PT_SHIFT                    8
#define SPI_MCR_SMPL_PT(x)                       (((x)<<SPI_MCR_SMPL_PT_SHIFT)&SPI_MCR_SMPL_PT_MASK)
#define SPI_MCR_CLR_RXF_MASK                     0x400u
#define SPI_MCR_CLR_RXF_SHIFT                    10
#define SPI_MCR_CLR_TXF_MASK                     0x800u
#define SPI_MCR_CLR_TXF_SHIFT                    11
#define SPI_MCR_DIS_RXF_MASK                     0x1000u
#define SPI_MCR_DIS_RXF_SHIFT                    12
#define SPI_MCR_DIS_TXF_MASK                     0x2000u
#define SPI_MCR_DIS_TXF_SHIFT                    13
#define SPI_MCR_MDIS_MASK                        0x4000u
#define SPI_MCR_MDIS_SHIFT                       14
#define SPI_MCR_DOZE_MASK                        0x8000u
#define SPI_MCR_DOZE_SHIFT                       15
#define SPI_MCR_PCSIS_MASK                       0xFF0000u
#define SPI_MCR_PCSIS_SHIFT                      16
#define SPI_MCR_PCSIS(x)                         (((x)<<SPI_MCR_PCSIS_SHIFT)&SPI_MCR_PCSIS_MASK)
#define SPI_MCR_ROOE_MASK                        0x1000000u
#define SPI_MCR_ROOE_SHIFT                       24
#define SPI_MCR_PCSSE_MASK                       0x2000000u
#define SPI_MCR_PCSSE_SHIFT                      25
#define SPI_MCR_MTFE_MASK                        0x4000000u
#define SPI_MCR_MTFE_SHIFT                       26
#define SPI_MCR_FRZ_MASK                         0x8000000u
#define SPI_MCR_FRZ_SHIFT                        27
#define SPI_MCR_DCONF_MASK                       0x30000000u
#define SPI_MCR_DCONF_SHIFT                      28
#define SPI_MCR_DCONF(x)                         (((x)<<SPI_MCR_DCONF_SHIFT)&SPI_MCR_DCONF_MASK)
#define SPI_MCR_CONT_SCKE_MASK                   0x40000000u
#define SPI_MCR_CONT_SCKE_SHIFT                  30
#define SPI_MCR_MSTR_MASK                        0x80000000u
#define SPI_MCR_MSTR_SHIFT                       31
/* HCR Bit Fields */
#define SPI_HCR_RXFR_MASK                        0xF0000u
#define SPI_HCR_RXFR_SHIFT                       16
#define SPI_HCR_RXFR(x)                          (((x)<<SPI_HCR_RXFR_SHIFT)&SPI_HCR_RXFR_MASK)
#define SPI_HCR_TXFR_MASK                        0xF00000u
#define SPI_HCR_TXFR_SHIFT                       20
#define SPI_HCR_TXFR(x)                          (((x)<<SPI_HCR_TXFR_SHIFT)&SPI_HCR_TXFR_MASK)
#define SPI_HCR_CTAR_MASK                        0x7000000u
#define SPI_HCR_CTAR_SHIFT                       24
#define SPI_HCR_CTAR(x)                          (((x)<<SPI_HCR_CTAR_SHIFT)&SPI_HCR_CTAR_MASK)
#define SPI_HCR_PISR_MASK                        0x40000000u
#define SPI_HCR_PISR_SHIFT                       30
#define SPI_HCR_DSI_MASK                         0x80000000u
#define SPI_HCR_DSI_SHIFT                        31
/* TCR Bit Fields */
#define SPI_TCR_SPI_TCNT_MASK                    0xFFFF0000u
#define SPI_TCR_SPI_TCNT_SHIFT                   16
#define SPI_TCR_SPI_TCNT(x)                      (((x)<<SPI_TCR_SPI_TCNT_SHIFT)&SPI_TCR_SPI_TCNT_MASK)
/* CTAR Bit Fields */
#define SPI_CTAR_BR_MASK                         0xFu
#define SPI_CTAR_BR_SHIFT                        0
#define SPI_CTAR_BR(x)                           (((x)<<SPI_CTAR_BR_SHIFT)&SPI_CTAR_BR_MASK)
#define SPI_CTAR_DT_MASK                         0xF0u
#define SPI_CTAR_DT_SHIFT                        4
#define SPI_CTAR_DT(x)                           (((x)<<SPI_CTAR_DT_SHIFT)&SPI_CTAR_DT_MASK)
#define SPI_CTAR_ASC_MASK                        0xF00u
#define SPI_CTAR_ASC_SHIFT                       8
#define SPI_CTAR_ASC(x)                          (((x)<<SPI_CTAR_ASC_SHIFT)&SPI_CTAR_ASC_MASK)
#define SPI_CTAR_CSSCK_MASK                      0xF000u
#define SPI_CTAR_CSSCK_SHIFT                     12
#define SPI_CTAR_CSSCK(x)                        (((x)<<SPI_CTAR_CSSCK_SHIFT)&SPI_CTAR_CSSCK_MASK)
#define SPI_CTAR_PBR_MASK                        0x30000u
#define SPI_CTAR_PBR_SHIFT                       16
#define SPI_CTAR_PBR(x)                          (((x)<<SPI_CTAR_PBR_SHIFT)&SPI_CTAR_PBR_MASK)
#define SPI_CTAR_PDT_MASK                        0xC0000u
#define SPI_CTAR_PDT_SHIFT                       18
#define SPI_CTAR_PDT(x)                          (((x)<<SPI_CTAR_PDT_SHIFT)&SPI_CTAR_PDT_MASK)
#define SPI_CTAR_PASC_MASK                       0x300000u
#define SPI_CTAR_PASC_SHIFT                      20
#define SPI_CTAR_PASC(x)                         (((x)<<SPI_CTAR_PASC_SHIFT)&SPI_CTAR_PASC_MASK)
#define SPI_CTAR_PCSSCK_MASK                     0xC00000u
#define SPI_CTAR_PCSSCK_SHIFT                    22
#define SPI_CTAR_PCSSCK(x)                       (((x)<<SPI_CTAR_PCSSCK_SHIFT)&SPI_CTAR_PCSSCK_MASK)
#define SPI_CTAR_LSBFE_MASK                      0x1000000u
#define SPI_CTAR_LSBFE_SHIFT                     24
#define SPI_CTAR_CPHA_MASK                       0x2000000u
#define SPI_CTAR_CPHA_SHIFT                      25
#define SPI_CTAR_CPOL_MASK                       0x4000000u
#define SPI_CTAR_CPOL_SHIFT                      26
#define SPI_CTAR_FMSZ_MASK                       0x78000000u
#define SPI_CTAR_FMSZ_SHIFT                      27
#define SPI_CTAR_FMSZ(x)                         (((x)<<SPI_CTAR_FMSZ_SHIFT)&SPI_CTAR_FMSZ_MASK)
#define SPI_CTAR_DBR_MASK                        0x80000000u
#define SPI_CTAR_DBR_SHIFT                       31
/* CTAR_SLAVE Bit Fields */
#define SPI_CTAR_SLAVE_PP_MASK                   0x800000u
#define SPI_CTAR_SLAVE_PP_SHIFT                  23
#define SPI_CTAR_SLAVE_PE_MASK                   0x1000000u
#define SPI_CTAR_SLAVE_PE_SHIFT                  24
#define SPI_CTAR_SLAVE_CPHA_MASK                 0x2000000u
#define SPI_CTAR_SLAVE_CPHA_SHIFT                25
#define SPI_CTAR_SLAVE_CPOL_MASK                 0x4000000u
#define SPI_CTAR_SLAVE_CPOL_SHIFT                26
#define SPI_CTAR_SLAVE_FMSZ_MASK                 0xF8000000u
#define SPI_CTAR_SLAVE_FMSZ_SHIFT                27
#define SPI_CTAR_SLAVE_FMSZ(x)                   (((x)<<SPI_CTAR_SLAVE_FMSZ_SHIFT)&SPI_CTAR_SLAVE_FMSZ_MASK)
/* SR Bit Fields */
#define SPI_SR_POPNXTPTR_MASK                    0xFu
#define SPI_SR_POPNXTPTR_SHIFT                   0
#define SPI_SR_POPNXTPTR(x)                      (((x)<<SPI_SR_POPNXTPTR_SHIFT)&SPI_SR_POPNXTPTR_MASK)
#define SPI_SR_RXCTR_MASK                        0xF0u
#define SPI_SR_RXCTR_SHIFT                       4
#define SPI_SR_RXCTR(x)                          (((x)<<SPI_SR_RXCTR_SHIFT)&SPI_SR_RXCTR_MASK)
#define SPI_SR_TXNXTPTR_MASK                     0xF00u
#define SPI_SR_TXNXTPTR_SHIFT                    8
#define SPI_SR_TXNXTPTR(x)                       (((x)<<SPI_SR_TXNXTPTR_SHIFT)&SPI_SR_TXNXTPTR_MASK)
#define SPI_SR_TXCTR_MASK                        0xF000u
#define SPI_SR_TXCTR_SHIFT                       12
#define SPI_SR_TXCTR(x)                          (((x)<<SPI_SR_TXCTR_SHIFT)&SPI_SR_TXCTR_MASK)
#define SPI_SR_RFDF_MASK                         0x20000u
#define SPI_SR_RFDF_SHIFT                        17
#define SPI_SR_RFOF_MASK                         0x80000u
#define SPI_SR_RFOF_SHIFT                        19
#define SPI_SR_SPEF_MASK                         0x200000u
#define SPI_SR_SPEF_SHIFT                        21
#define SPI_SR_TFFF_MASK                         0x2000000u
#define SPI_SR_TFFF_SHIFT                        25
#define SPI_SR_TFUF_MASK                         0x8000000u
#define SPI_SR_TFUF_SHIFT                        27
#define SPI_SR_EOQF_MASK                         0x10000000u
#define SPI_SR_EOQF_SHIFT                        28
#define SPI_SR_TXRXS_MASK                        0x40000000u
#define SPI_SR_TXRXS_SHIFT                       30
#define SPI_SR_TCF_MASK                          0x80000000u
#define SPI_SR_TCF_SHIFT                         31
/* RSER Bit Fields */
#define SPI_RSER_RFDF_DIRS_MASK                  0x10000u
#define SPI_RSER_RFDF_DIRS_SHIFT                 16
#define SPI_RSER_RFDF_RE_MASK                    0x20000u
#define SPI_RSER_RFDF_RE_SHIFT                   17
#define SPI_RSER_RFOF_RE_MASK                    0x80000u
#define SPI_RSER_RFOF_RE_SHIFT                   19
#define SPI_RSER_SPEF_RE_MASK                    0x200000u
#define SPI_RSER_SPEF_RE_SHIFT                   21
#define SPI_RSER_TFFF_DIRS_MASK                  0x1000000u
#define SPI_RSER_TFFF_DIRS_SHIFT                 24
#define SPI_RSER_TFFF_RE_MASK                    0x2000000u
#define SPI_RSER_TFFF_RE_SHIFT                   25
#define SPI_RSER_TFUF_RE_MASK                    0x8000000u
#define SPI_RSER_TFUF_RE_SHIFT                   27
#define SPI_RSER_EOQF_RE_MASK                    0x10000000u
#define SPI_RSER_EOQF_RE_SHIFT                   28
#define SPI_RSER_TCF_RE_MASK                     0x80000000u
#define SPI_RSER_TCF_RE_SHIFT                    31
/* PUSHR Bit Fields */
#define SPI_PUSHR_TXDATA_MASK                    0xFFFFu
#define SPI_PUSHR_TXDATA_SHIFT                   0
#define SPI_PUSHR_TXDATA(x)                      (((x)<<SPI_PUSHR_TXDATA_SHIFT)&SPI_PUSHR_TXDATA_MASK)
#define SPI_PUSHR_PCS_MASK                       0xFF0000u
#define SPI_PUSHR_PCS_SHIFT                      16
#define SPI_PUSHR_PCS(x)                         (((x)<<SPI_PUSHR_PCS_SHIFT)&SPI_PUSHR_PCS_MASK)
#define SPI_PUSHR_PP_MASK                        0x1000000u
#define SPI_PUSHR_PP_SHIFT                       24
#define SPI_PUSHR_PE_MASK                        0x2000000u
#define SPI_PUSHR_PE_SHIFT                       25
#define SPI_PUSHR_CTCNT_MASK                     0x4000000u
#define SPI_PUSHR_CTCNT_SHIFT                    26
#define SPI_PUSHR_EOQ_MASK                       0x8000000u
#define SPI_PUSHR_EOQ_SHIFT                      27
#define SPI_PUSHR_CTAS_MASK                      0x70000000u
#define SPI_PUSHR_CTAS_SHIFT                     28
#define SPI_PUSHR_CTAS(x)                        (((x)<<SPI_PUSHR_CTAS_SHIFT)&SPI_PUSHR_CTAS_MASK)
#define SPI_PUSHR_CONT_MASK                      0x80000000u
#define SPI_PUSHR_CONT_SHIFT                     31
/* PUSHR_SLAVE Bit Fields */
#define SPI_PUSHR_SLAVE_TXDATA_MASK              0xFFFFFFFFu
#define SPI_PUSHR_SLAVE_TXDATA_SHIFT             0
#define SPI_PUSHR_SLAVE_TXDATA(x)                (((x)<<SPI_PUSHR_SLAVE_TXDATA_SHIFT)&SPI_PUSHR_SLAVE_TXDATA_MASK)
/* POPR Bit Fields */
#define SPI_POPR_RXDATA_MASK                     0xFFFFFFFFu
#define SPI_POPR_RXDATA_SHIFT                    0
#define SPI_POPR_RXDATA(x)                       (((x)<<SPI_POPR_RXDATA_SHIFT)&SPI_POPR_RXDATA_MASK)
/* TXFR0 Bit Fields */
#define SPI_TXFR0_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR0_TXDATA_SHIFT                   0
#define SPI_TXFR0_TXDATA(x)                      (((x)<<SPI_TXFR0_TXDATA_SHIFT)&SPI_TXFR0_TXDATA_MASK)
#define SPI_TXFR0_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR0_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR0_TXCMD_TXDATA(x)                (((x)<<SPI_TXFR0_TXCMD_TXDATA_SHIFT)&SPI_TXFR0_TXCMD_TXDATA_MASK)
/* TXFR1 Bit Fields */
#define SPI_TXFR1_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR1_TXDATA_SHIFT                   0
#define SPI_TXFR1_TXDATA(x)                      (((x)<<SPI_TXFR1_TXDATA_SHIFT)&SPI_TXFR1_TXDATA_MASK)
#define SPI_TXFR1_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR1_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR1_TXCMD_TXDATA(x)                (((x)<<SPI_TXFR1_TXCMD_TXDATA_SHIFT)&SPI_TXFR1_TXCMD_TXDATA_MASK)
/* TXFR2 Bit Fields */
#define SPI_TXFR2_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR2_TXDATA_SHIFT                   0
#define SPI_TXFR2_TXDATA(x)                      (((x)<<SPI_TXFR2_TXDATA_SHIFT)&SPI_TXFR2_TXDATA_MASK)
#define SPI_TXFR2_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR2_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR2_TXCMD_TXDATA(x)                (((x)<<SPI_TXFR2_TXCMD_TXDATA_SHIFT)&SPI_TXFR2_TXCMD_TXDATA_MASK)
/* TXFR3 Bit Fields */
#define SPI_TXFR3_TXDATA_MASK                    0xFFFFu
#define SPI_TXFR3_TXDATA_SHIFT                   0
#define SPI_TXFR3_TXDATA(x)                      (((x)<<SPI_TXFR3_TXDATA_SHIFT)&SPI_TXFR3_TXDATA_MASK)
#define SPI_TXFR3_TXCMD_TXDATA_MASK              0xFFFF0000u
#define SPI_TXFR3_TXCMD_TXDATA_SHIFT             16
#define SPI_TXFR3_TXCMD_TXDATA(x)                (((x)<<SPI_TXFR3_TXCMD_TXDATA_SHIFT)&SPI_TXFR3_TXCMD_TXDATA_MASK)
/* RXFR0 Bit Fields */
#define SPI_RXFR0_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR0_RXDATA_SHIFT                   0
#define SPI_RXFR0_RXDATA(x)                      (((x)<<SPI_RXFR0_RXDATA_SHIFT)&SPI_RXFR0_RXDATA_MASK)
/* RXFR1 Bit Fields */
#define SPI_RXFR1_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR1_RXDATA_SHIFT                   0
#define SPI_RXFR1_RXDATA(x)                      (((x)<<SPI_RXFR1_RXDATA_SHIFT)&SPI_RXFR1_RXDATA_MASK)
/* RXFR2 Bit Fields */
#define SPI_RXFR2_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR2_RXDATA_SHIFT                   0
#define SPI_RXFR2_RXDATA(x)                      (((x)<<SPI_RXFR2_RXDATA_SHIFT)&SPI_RXFR2_RXDATA_MASK)
/* RXFR3 Bit Fields */
#define SPI_RXFR3_RXDATA_MASK                    0xFFFFFFFFu
#define SPI_RXFR3_RXDATA_SHIFT                   0
#define SPI_RXFR3_RXDATA(x)                      (((x)<<SPI_RXFR3_RXDATA_SHIFT)&SPI_RXFR3_RXDATA_MASK)

/*! \} */ /* end of group SPI_Register_Masks */


/* SPI - Peripheral instance base addresses */
/*! Peripheral SPI0 base pointer */
#define SPI0_BASE_PTR                            ((SPI_MemMapPtr)0x4002C000u)
/*! Peripheral SPI1 base pointer */
#define SPI1_BASE_PTR                            ((SPI_MemMapPtr)0x4002D000u)
/*! Peripheral SPI2 base pointer */
#define SPI2_BASE_PTR                            ((SPI_MemMapPtr)0x400AC000u)

/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros */
/*! \{ */


/* SPI - Register instance definitions */
/* SPI0 */
#define SPI0_MCR                                 SPI_MCR_REG(SPI0_BASE_PTR)
#define SPI0_HCR                                 SPI_HCR_REG(SPI0_BASE_PTR)
#define SPI0_TCR                                 SPI_TCR_REG(SPI0_BASE_PTR)
#define SPI0_CTAR0                               SPI_CTAR_REG(SPI0_BASE_PTR,0)
#define SPI0_CTAR0_SLAVE                         SPI_CTAR_SLAVE_REG(SPI0_BASE_PTR,0)
#define SPI0_CTAR1                               SPI_CTAR_REG(SPI0_BASE_PTR,1)
#define SPI0_SR                                  SPI_SR_REG(SPI0_BASE_PTR)
#define SPI0_RSER                                SPI_RSER_REG(SPI0_BASE_PTR)
#define SPI0_PUSHR                               SPI_PUSHR_REG(SPI0_BASE_PTR)
#define SPI0_PUSHR_SLAVE                         SPI_PUSHR_SLAVE_REG(SPI0_BASE_PTR)
#define SPI0_POPR                                SPI_POPR_REG(SPI0_BASE_PTR)
#define SPI0_TXFR0                               SPI_TXFR0_REG(SPI0_BASE_PTR)
#define SPI0_TXFR1                               SPI_TXFR1_REG(SPI0_BASE_PTR)
#define SPI0_TXFR2                               SPI_TXFR2_REG(SPI0_BASE_PTR)
#define SPI0_TXFR3                               SPI_TXFR3_REG(SPI0_BASE_PTR)
#define SPI0_RXFR0                               SPI_RXFR0_REG(SPI0_BASE_PTR)
#define SPI0_RXFR1                               SPI_RXFR1_REG(SPI0_BASE_PTR)
#define SPI0_RXFR2                               SPI_RXFR2_REG(SPI0_BASE_PTR)
#define SPI0_RXFR3                               SPI_RXFR3_REG(SPI0_BASE_PTR)
/* SPI1 */
#define SPI1_MCR                                 SPI_MCR_REG(SPI1_BASE_PTR)
#define SPI1_HCR                                 SPI_HCR_REG(SPI1_BASE_PTR)
#define SPI1_TCR                                 SPI_TCR_REG(SPI1_BASE_PTR)
#define SPI1_CTAR0                               SPI_CTAR_REG(SPI1_BASE_PTR,0)
#define SPI1_CTAR0_SLAVE                         SPI_CTAR_SLAVE_REG(SPI1_BASE_PTR,0)
#define SPI1_CTAR1                               SPI_CTAR_REG(SPI1_BASE_PTR,1)
#define SPI1_SR                                  SPI_SR_REG(SPI1_BASE_PTR)
#define SPI1_RSER                                SPI_RSER_REG(SPI1_BASE_PTR)
#define SPI1_PUSHR                               SPI_PUSHR_REG(SPI1_BASE_PTR)
#define SPI1_PUSHR_SLAVE                         SPI_PUSHR_SLAVE_REG(SPI1_BASE_PTR)
#define SPI1_POPR                                SPI_POPR_REG(SPI1_BASE_PTR)
#define SPI1_TXFR0                               SPI_TXFR0_REG(SPI1_BASE_PTR)
#define SPI1_TXFR1                               SPI_TXFR1_REG(SPI1_BASE_PTR)
#define SPI1_TXFR2                               SPI_TXFR2_REG(SPI1_BASE_PTR)
#define SPI1_TXFR3                               SPI_TXFR3_REG(SPI1_BASE_PTR)
#define SPI1_RXFR0                               SPI_RXFR0_REG(SPI1_BASE_PTR)
#define SPI1_RXFR1                               SPI_RXFR1_REG(SPI1_BASE_PTR)
#define SPI1_RXFR2                               SPI_RXFR2_REG(SPI1_BASE_PTR)
#define SPI1_RXFR3                               SPI_RXFR3_REG(SPI1_BASE_PTR)
/* SPI2 */
#define SPI2_MCR                                 SPI_MCR_REG(SPI2_BASE_PTR)
#define SPI2_HCR                                 SPI_HCR_REG(SPI2_BASE_PTR)
#define SPI2_TCR                                 SPI_TCR_REG(SPI2_BASE_PTR)
#define SPI2_CTAR0                               SPI_CTAR_REG(SPI2_BASE_PTR,0)
#define SPI2_CTAR0_SLAVE                         SPI_CTAR_SLAVE_REG(SPI2_BASE_PTR,0)
#define SPI2_CTAR1                               SPI_CTAR_REG(SPI2_BASE_PTR,1)
#define SPI2_SR                                  SPI_SR_REG(SPI2_BASE_PTR)
#define SPI2_RSER                                SPI_RSER_REG(SPI2_BASE_PTR)
#define SPI2_PUSHR                               SPI_PUSHR_REG(SPI2_BASE_PTR)
#define SPI2_PUSHR_SLAVE                         SPI_PUSHR_SLAVE_REG(SPI2_BASE_PTR)
#define SPI2_POPR                                SPI_POPR_REG(SPI2_BASE_PTR)
#define SPI2_TXFR0                               SPI_TXFR0_REG(SPI2_BASE_PTR)
#define SPI2_TXFR1                               SPI_TXFR1_REG(SPI2_BASE_PTR)
#define SPI2_TXFR2                               SPI_TXFR2_REG(SPI2_BASE_PTR)
#define SPI2_TXFR3                               SPI_TXFR3_REG(SPI2_BASE_PTR)
#define SPI2_RXFR0                               SPI_RXFR0_REG(SPI2_BASE_PTR)
#define SPI2_RXFR1                               SPI_RXFR1_REG(SPI2_BASE_PTR)
#define SPI2_RXFR2                               SPI_RXFR2_REG(SPI2_BASE_PTR)
#define SPI2_RXFR3                               SPI_RXFR3_REG(SPI2_BASE_PTR)

/*! \} */ /* end of group SPI_Register_Accessor_Macros */


/*! \} */ /* end of group SPI_Peripheral */


/* ----------------------------------------------------------------------------
   -- RTC
   ---------------------------------------------------------------------------- */

/*! \addtogroup RTC_Peripheral RTC */
/*! \{ */

/*! RTC - Peripheral register structure */
typedef struct RTC_MemMap {
  uint32_t TSR;                                    /*!< RTC Time Seconds Register, offset: 0x0 */
  uint32_t TPR;                                    /*!< RTC Time Prescaler Register, offset: 0x4 */
  uint32_t TAR;                                    /*!< RTC Time Alarm Register, offset: 0x8 */
  uint32_t TCR;                                    /*!< RTC Time Compensation Register, offset: 0xC */
  uint32_t CR;                                     /*!< RTC Control Register, offset: 0x10 */
  uint32_t SR;                                     /*!< RTC Status Register, offset: 0x14 */
  uint32_t LR;                                     /*!< RTC Lock Register, offset: 0x18 */
  uint32_t CCR;                                    /*!< RTC Chip Configuration Register, offset: 0x1C */
  uint8_t RESERVED_0[2016];
  uint32_t WAR;                                    /*!< RTC Write Access Register, offset: 0x800 */
  uint32_t RAR;                                    /*!< RTC Read Access Register, offset: 0x804 */
} volatile *RTC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup RTC_Register_Accessor_Macros RTC - Register accessor macros */
/*! \{ */


/* RTC - Register accessors */
#define RTC_TSR_REG(base)                        ((base)->TSR)
#define RTC_TPR_REG(base)                        ((base)->TPR)
#define RTC_TAR_REG(base)                        ((base)->TAR)
#define RTC_TCR_REG(base)                        ((base)->TCR)
#define RTC_CR_REG(base)                         ((base)->CR)
#define RTC_SR_REG(base)                         ((base)->SR)
#define RTC_LR_REG(base)                         ((base)->LR)
#define RTC_CCR_REG(base)                        ((base)->CCR)
#define RTC_WAR_REG(base)                        ((base)->WAR)
#define RTC_RAR_REG(base)                        ((base)->RAR)

/*! \} */ /* end of group RTC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup RTC_Register_Masks RTC Register Masks */
/*! \{ */

/* TSR Bit Fields */
#define RTC_TSR_TSR_MASK                         0xFFFFFFFFu
#define RTC_TSR_TSR_SHIFT                        0
#define RTC_TSR_TSR(x)                           (((x)<<RTC_TSR_TSR_SHIFT)&RTC_TSR_TSR_MASK)
/* TPR Bit Fields */
#define RTC_TPR_TPR_MASK                         0xFFFFu
#define RTC_TPR_TPR_SHIFT                        0
#define RTC_TPR_TPR(x)                           (((x)<<RTC_TPR_TPR_SHIFT)&RTC_TPR_TPR_MASK)
/* TAR Bit Fields */
#define RTC_TAR_TAR_MASK                         0xFFFFFFFFu
#define RTC_TAR_TAR_SHIFT                        0
#define RTC_TAR_TAR(x)                           (((x)<<RTC_TAR_TAR_SHIFT)&RTC_TAR_TAR_MASK)
/* TCR Bit Fields */
#define RTC_TCR_TCR_MASK                         0xFFu
#define RTC_TCR_TCR_SHIFT                        0
#define RTC_TCR_TCR(x)                           (((x)<<RTC_TCR_TCR_SHIFT)&RTC_TCR_TCR_MASK)
#define RTC_TCR_CIR_MASK                         0xFF00u
#define RTC_TCR_CIR_SHIFT                        8
#define RTC_TCR_CIR(x)                           (((x)<<RTC_TCR_CIR_SHIFT)&RTC_TCR_CIR_MASK)
#define RTC_TCR_TCV_MASK                         0xFF0000u
#define RTC_TCR_TCV_SHIFT                        16
#define RTC_TCR_TCV(x)                           (((x)<<RTC_TCR_TCV_SHIFT)&RTC_TCR_TCV_MASK)
#define RTC_TCR_CIC_MASK                         0xFF000000u
#define RTC_TCR_CIC_SHIFT                        24
#define RTC_TCR_CIC(x)                           (((x)<<RTC_TCR_CIC_SHIFT)&RTC_TCR_CIC_MASK)
/* CR Bit Fields */
#define RTC_CR_SWR_MASK                          0x1u
#define RTC_CR_SWR_SHIFT                         0
#define RTC_CR_WPE_MASK                          0x2u
#define RTC_CR_WPE_SHIFT                         1
#define RTC_CR_SUP_MASK                          0x4u
#define RTC_CR_SUP_SHIFT                         2
#define RTC_CR_SM_MASK                           0x8u
#define RTC_CR_SM_SHIFT                          3
#define RTC_CR_OSCE_MASK                         0x100u
#define RTC_CR_OSCE_SHIFT                        8
#define RTC_CR_SC16P_MASK                        0x400u
#define RTC_CR_SC16P_SHIFT                       10
#define RTC_CR_SC8P_MASK                         0x800u
#define RTC_CR_SC8P_SHIFT                        11
#define RTC_CR_SC4P_MASK                         0x1000u
#define RTC_CR_SC4P_SHIFT                        12
#define RTC_CR_SC2P_MASK                         0x2000u
#define RTC_CR_SC2P_SHIFT                        13
#define RTC_CR_OTE_MASK                          0x4000u
#define RTC_CR_OTE_SHIFT                         14
/* SR Bit Fields */
#define RTC_SR_TIF_MASK                          0x1u
#define RTC_SR_TIF_SHIFT                         0
#define RTC_SR_TOF_MASK                          0x2u
#define RTC_SR_TOF_SHIFT                         1
#define RTC_SR_TAF_MASK                          0x4u
#define RTC_SR_TAF_SHIFT                         2
#define RTC_SR_TCE_MASK                          0x10u
#define RTC_SR_TCE_SHIFT                         4
/* LR Bit Fields */
#define RTC_LR_TCL_MASK                          0x8u
#define RTC_LR_TCL_SHIFT                         3
#define RTC_LR_CRL_MASK                          0x10u
#define RTC_LR_CRL_SHIFT                         4
#define RTC_LR_SRL_MASK                          0x20u
#define RTC_LR_SRL_SHIFT                         5
/* CCR Bit Fields */
#define RTC_CCR_CONFIG_MASK                      0xFFu
#define RTC_CCR_CONFIG_SHIFT                     0
#define RTC_CCR_CONFIG(x)                        (((x)<<RTC_CCR_CONFIG_SHIFT)&RTC_CCR_CONFIG_MASK)
/* WAR Bit Fields */
#define RTC_WAR_TSRW_MASK                        0x1u
#define RTC_WAR_TSRW_SHIFT                       0
#define RTC_WAR_TPRW_MASK                        0x2u
#define RTC_WAR_TPRW_SHIFT                       1
#define RTC_WAR_TARW_MASK                        0x4u
#define RTC_WAR_TARW_SHIFT                       2
#define RTC_WAR_TCRW_MASK                        0x8u
#define RTC_WAR_TCRW_SHIFT                       3
#define RTC_WAR_CRW_MASK                         0x10u
#define RTC_WAR_CRW_SHIFT                        4
#define RTC_WAR_SRW_MASK                         0x20u
#define RTC_WAR_SRW_SHIFT                        5
#define RTC_WAR_LRW_MASK                         0x40u
#define RTC_WAR_LRW_SHIFT                        6
#define RTC_WAR_CCRW_MASK                        0x80u
#define RTC_WAR_CCRW_SHIFT                       7
/* RAR Bit Fields */
#define RTC_RAR_TSRR_MASK                        0x1u
#define RTC_RAR_TSRR_SHIFT                       0
#define RTC_RAR_TPRR_MASK                        0x2u
#define RTC_RAR_TPRR_SHIFT                       1
#define RTC_RAR_TARR_MASK                        0x4u
#define RTC_RAR_TARR_SHIFT                       2
#define RTC_RAR_TCRR_MASK                        0x8u
#define RTC_RAR_TCRR_SHIFT                       3
#define RTC_RAR_CRR_MASK                         0x10u
#define RTC_RAR_CRR_SHIFT                        4
#define RTC_RAR_SRR_MASK                         0x20u
#define RTC_RAR_SRR_SHIFT                        5
#define RTC_RAR_LRR_MASK                         0x40u
#define RTC_RAR_LRR_SHIFT                        6
#define RTC_RAR_CCRR_MASK                        0x80u
#define RTC_RAR_CCRR_SHIFT                       7

/*! \} */ /* end of group RTC_Register_Masks */


/* RTC - Peripheral instance base addresses */
/*! Peripheral SRTC base pointer */
#define SRTC_BASE_PTR                            ((RTC_MemMapPtr)0x4003D000u)

/* ----------------------------------------------------------------------------
   -- RTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup RTC_Register_Accessor_Macros RTC - Register accessor macros */
/*! \{ */


/* RTC - Register instance definitions */
/* SRTC */
#define RTC_TSR                                  RTC_TSR_REG(SRTC_BASE_PTR)
#define RTC_TPR                                  RTC_TPR_REG(SRTC_BASE_PTR)
#define RTC_TAR                                  RTC_TAR_REG(SRTC_BASE_PTR)
#define RTC_TCR                                  RTC_TCR_REG(SRTC_BASE_PTR)
#define RTC_CR                                   RTC_CR_REG(SRTC_BASE_PTR)
#define RTC_SR                                   RTC_SR_REG(SRTC_BASE_PTR)
#define RTC_LR                                   RTC_LR_REG(SRTC_BASE_PTR)
#define RTC_CCR                                  RTC_CCR_REG(SRTC_BASE_PTR)
#define RTC_WAR                                  RTC_WAR_REG(SRTC_BASE_PTR)
#define RTC_RAR                                  RTC_RAR_REG(SRTC_BASE_PTR)

/*! \} */ /* end of group RTC_Register_Accessor_Macros */


/*! \} */ /* end of group RTC_Peripheral */


/* ----------------------------------------------------------------------------
   -- SysTick
   ---------------------------------------------------------------------------- */

/*! \addtogroup SysTick_Peripheral SysTick */
/*! \{ */

/*! SysTick - Peripheral register structure */
typedef struct SysTick_MemMap {
  uint32_t CSR;                                    /*!< SysTick Control and Status Register, offset: 0x0 */
  uint32_t RVR;                                    /*!< SysTick Reload Value Register, offset: 0x4 */
  uint32_t CVR;                                    /*!< SysTick Current Value Register, offset: 0x8 */
  uint32_t CALIB;                                  /*!< SysTick Calibration Value Register, offset: 0xC */
} volatile *SysTick_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SysTick - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SysTick_Register_Accessor_Macros SysTick - Register accessor macros */
/*! \{ */


/* SysTick - Register accessors */
#define SysTick_CSR_REG(base)                    ((base)->CSR)
#define SysTick_RVR_REG(base)                    ((base)->RVR)
#define SysTick_CVR_REG(base)                    ((base)->CVR)
#define SysTick_CALIB_REG(base)                  ((base)->CALIB)

/*! \} */ /* end of group SysTick_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SysTick Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup SysTick_Register_Masks SysTick Register Masks */
/*! \{ */

/* CSR Bit Fields */
#define SysTick_CSR_ENABLE_MASK                  0x1u
#define SysTick_CSR_ENABLE_SHIFT                 0
#define SysTick_CSR_TICKINT_MASK                 0x2u
#define SysTick_CSR_TICKINT_SHIFT                1
#define SysTick_CSR_CLKSOURCE_MASK               0x4u
#define SysTick_CSR_CLKSOURCE_SHIFT              2
#define SysTick_CSR_COUNTFLAG_MASK               0x10000u
#define SysTick_CSR_COUNTFLAG_SHIFT              16
/* RVR Bit Fields */
#define SysTick_RVR_RELOAD_MASK                  0xFFFFFFu
#define SysTick_RVR_RELOAD_SHIFT                 0
#define SysTick_RVR_RELOAD(x)                    (((x)<<SysTick_RVR_RELOAD_SHIFT)&SysTick_RVR_RELOAD_MASK)
/* CVR Bit Fields */
#define SysTick_CVR_CURRENT_MASK                 0xFFFFFFu
#define SysTick_CVR_CURRENT_SHIFT                0
#define SysTick_CVR_CURRENT(x)                   (((x)<<SysTick_CVR_CURRENT_SHIFT)&SysTick_CVR_CURRENT_MASK)
/* CALIB Bit Fields */
#define SysTick_CALIB_TENMS_MASK                 0xFFFFFFu
#define SysTick_CALIB_TENMS_SHIFT                0
#define SysTick_CALIB_TENMS(x)                   (((x)<<SysTick_CALIB_TENMS_SHIFT)&SysTick_CALIB_TENMS_MASK)
#define SysTick_CALIB_SKEW_MASK                  0x40000000u
#define SysTick_CALIB_SKEW_SHIFT                 30
#define SysTick_CALIB_NOREF_MASK                 0x80000000u
#define SysTick_CALIB_NOREF_SHIFT                31

/*! \} */ /* end of group SysTick_Register_Masks */


/* SysTick - Peripheral instance base addresses */
/*! Peripheral SysTick base pointer */
#define SysTick_BASE_PTR                         ((SysTick_MemMapPtr)0xE000E010u)

/* ----------------------------------------------------------------------------
   -- SysTick - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SysTick_Register_Accessor_Macros SysTick - Register accessor macros */
/*! \{ */


/* SysTick - Register instance definitions */
/* SysTick */
#define SYST_CSR                                 SysTick_CSR_REG(SysTick_BASE_PTR)
#define SYST_RVR                                 SysTick_RVR_REG(SysTick_BASE_PTR)
#define SYST_CVR                                 SysTick_CVR_REG(SysTick_BASE_PTR)
#define SYST_CALIB                               SysTick_CALIB_REG(SysTick_BASE_PTR)

/*! \} */ /* end of group SysTick_Register_Accessor_Macros */


/*! \} */ /* end of group SysTick_Peripheral */


/* ----------------------------------------------------------------------------
   -- SCB
   ---------------------------------------------------------------------------- */

/*! \addtogroup SCB_Peripheral SCB */
/*! \{ */

/*! SCB - Peripheral register structure */
typedef struct SCB_MemMap {
  uint8_t RESERVED_0[8];
  uint32_t ACTLR;                                  /*!< Auxiliary Control Register,, offset: 0x8 */
  uint8_t RESERVED_1[3316];
  uint32_t CPUID;                                  /*!< CPUID Base Register, offset: 0xD00 */
  uint32_t ICSR;                                   /*!< Interrupt Control and State Register, offset: 0xD04 */
  uint32_t VTOR;                                   /*!< Vector Table Offset Register, offset: 0xD08 */
  uint32_t AIRCR;                                  /*!< Application Interrupt and Reset Control Register, offset: 0xD0C */
  uint32_t SCR;                                    /*!< System Control Register, offset: 0xD10 */
  uint32_t CCR;                                    /*!< Configuration and Control Register, offset: 0xD14 */
  uint32_t SHPR1;                                  /*!< System Handler Priority Register 1, offset: 0xD18 */
  uint32_t SHPR2;                                  /*!< System Handler Priority Register 2, offset: 0xD1C */
  uint32_t SHPR3;                                  /*!< System Handler Priority Register 3, offset: 0xD20 */
  uint32_t SHCSR;                                  /*!< System Handler Control and State Register, offset: 0xD24 */
  uint32_t CFSR;                                   /*!< Configurable Fault Status Registers, offset: 0xD28 */
  uint32_t HFSR;                                   /*!< HardFault Status register, offset: 0xD2C */
  uint32_t DFSR;                                   /*!< Debug Fault Status Register, offset: 0xD30 */
  uint32_t MMFAR;                                  /*!< MemManage Address Register, offset: 0xD34 */
  uint32_t BFAR;                                   /*!< BusFault Address Register, offset: 0xD38 */
  uint32_t AFSR;                                   /*!< Auxiliary Fault Status Register, offset: 0xD3C */
} volatile *SCB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SCB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SCB_Register_Accessor_Macros SCB - Register accessor macros */
/*! \{ */


/* SCB - Register accessors */
#define SCB_ACTLR_REG(base)                      ((base)->ACTLR)
#define SCB_CPUID_REG(base)                      ((base)->CPUID)
#define SCB_ICSR_REG(base)                       ((base)->ICSR)
#define SCB_VTOR_REG(base)                       ((base)->VTOR)
#define SCB_AIRCR_REG(base)                      ((base)->AIRCR)
#define SCB_SCR_REG(base)                        ((base)->SCR)
#define SCB_CCR_REG(base)                        ((base)->CCR)
#define SCB_SHPR1_REG(base)                      ((base)->SHPR1)
#define SCB_SHPR2_REG(base)                      ((base)->SHPR2)
#define SCB_SHPR3_REG(base)                      ((base)->SHPR3)
#define SCB_SHCSR_REG(base)                      ((base)->SHCSR)
#define SCB_CFSR_REG(base)                       ((base)->CFSR)
#define SCB_HFSR_REG(base)                       ((base)->HFSR)
#define SCB_DFSR_REG(base)                       ((base)->DFSR)
#define SCB_MMFAR_REG(base)                      ((base)->MMFAR)
#define SCB_BFAR_REG(base)                       ((base)->BFAR)
#define SCB_AFSR_REG(base)                       ((base)->AFSR)

/*! \} */ /* end of group SCB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SCB Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup SCB_Register_Masks SCB Register Masks */
/*! \{ */

/* ACTLR Bit Fields */
#define SCB_ACTLR_DISMCYCINT_MASK                0x1u
#define SCB_ACTLR_DISMCYCINT_SHIFT               0
#define SCB_ACTLR_DISDEFWBUF_MASK                0x2u
#define SCB_ACTLR_DISDEFWBUF_SHIFT               1
#define SCB_ACTLR_DISFOLD_MASK                   0x4u
#define SCB_ACTLR_DISFOLD_SHIFT                  2
/* CPUID Bit Fields */
#define SCB_CPUID_REVISION_MASK                  0xFu
#define SCB_CPUID_REVISION_SHIFT                 0
#define SCB_CPUID_REVISION(x)                    (((x)<<SCB_CPUID_REVISION_SHIFT)&SCB_CPUID_REVISION_MASK)
#define SCB_CPUID_PARTNO_MASK                    0xFFF0u
#define SCB_CPUID_PARTNO_SHIFT                   4
#define SCB_CPUID_PARTNO(x)                      (((x)<<SCB_CPUID_PARTNO_SHIFT)&SCB_CPUID_PARTNO_MASK)
#define SCB_CPUID_VARIANT_MASK                   0xF00000u
#define SCB_CPUID_VARIANT_SHIFT                  20
#define SCB_CPUID_VARIANT(x)                     (((x)<<SCB_CPUID_VARIANT_SHIFT)&SCB_CPUID_VARIANT_MASK)
#define SCB_CPUID_IMPLEMENTER_MASK               0xFF000000u
#define SCB_CPUID_IMPLEMENTER_SHIFT              24
#define SCB_CPUID_IMPLEMENTER(x)                 (((x)<<SCB_CPUID_IMPLEMENTER_SHIFT)&SCB_CPUID_IMPLEMENTER_MASK)
/* ICSR Bit Fields */
#define SCB_ICSR_VECTACTIVE_MASK                 0x1FFu
#define SCB_ICSR_VECTACTIVE_SHIFT                0
#define SCB_ICSR_VECTACTIVE(x)                   (((x)<<SCB_ICSR_VECTACTIVE_SHIFT)&SCB_ICSR_VECTACTIVE_MASK)
#define SCB_ICSR_RETTOBASE_MASK                  0x800u
#define SCB_ICSR_RETTOBASE_SHIFT                 11
#define SCB_ICSR_VECTPENDING_MASK                0x3F000u
#define SCB_ICSR_VECTPENDING_SHIFT               12
#define SCB_ICSR_VECTPENDING(x)                  (((x)<<SCB_ICSR_VECTPENDING_SHIFT)&SCB_ICSR_VECTPENDING_MASK)
#define SCB_ICSR_ISRPENDING_MASK                 0x400000u
#define SCB_ICSR_ISRPENDING_SHIFT                22
#define SCB_ICSR_ISRPREEMPT_MASK                 0x800000u
#define SCB_ICSR_ISRPREEMPT_SHIFT                23
#define SCB_ICSR_PENDSTCLR_MASK                  0x2000000u
#define SCB_ICSR_PENDSTCLR_SHIFT                 25
#define SCB_ICSR_PENDSTSET_MASK                  0x4000000u
#define SCB_ICSR_PENDSTSET_SHIFT                 26
#define SCB_ICSR_PENDSVCLR_MASK                  0x8000000u
#define SCB_ICSR_PENDSVCLR_SHIFT                 27
#define SCB_ICSR_PENDSVSET_MASK                  0x10000000u
#define SCB_ICSR_PENDSVSET_SHIFT                 28
#define SCB_ICSR_NMIPENDSET_MASK                 0x80000000u
#define SCB_ICSR_NMIPENDSET_SHIFT                31
/* VTOR Bit Fields */
#define SCB_VTOR_TBLOFF_MASK                     0xFFFFFF80u
#define SCB_VTOR_TBLOFF_SHIFT                    7
#define SCB_VTOR_TBLOFF(x)                       (((x)<<SCB_VTOR_TBLOFF_SHIFT)&SCB_VTOR_TBLOFF_MASK)
/* AIRCR Bit Fields */
#define SCB_AIRCR_VECTRESET_MASK                 0x1u
#define SCB_AIRCR_VECTRESET_SHIFT                0
#define SCB_AIRCR_VECTCLRACTIVE_MASK             0x2u
#define SCB_AIRCR_VECTCLRACTIVE_SHIFT            1
#define SCB_AIRCR_SYSRESETREQ_MASK               0x4u
#define SCB_AIRCR_SYSRESETREQ_SHIFT              2
#define SCB_AIRCR_PRIGROUP_MASK                  0x700u
#define SCB_AIRCR_PRIGROUP_SHIFT                 8
#define SCB_AIRCR_PRIGROUP(x)                    (((x)<<SCB_AIRCR_PRIGROUP_SHIFT)&SCB_AIRCR_PRIGROUP_MASK)
#define SCB_AIRCR_ENDIANNESS_MASK                0x8000u
#define SCB_AIRCR_ENDIANNESS_SHIFT               15
#define SCB_AIRCR_VECTKEY_MASK                   0xFFFF0000u
#define SCB_AIRCR_VECTKEY_SHIFT                  16
#define SCB_AIRCR_VECTKEY(x)                     (((x)<<SCB_AIRCR_VECTKEY_SHIFT)&SCB_AIRCR_VECTKEY_MASK)
/* SCR Bit Fields */
#define SCB_SCR_SLEEPONEXIT_MASK                 0x2u
#define SCB_SCR_SLEEPONEXIT_SHIFT                1
#define SCB_SCR_SLEEPDEEP_MASK                   0x4u
#define SCB_SCR_SLEEPDEEP_SHIFT                  2
#define SCB_SCR_SEVONPEND_MASK                   0x10u
#define SCB_SCR_SEVONPEND_SHIFT                  4
/* CCR Bit Fields */
#define SCB_CCR_NONBASETHRDENA_MASK              0x1u
#define SCB_CCR_NONBASETHRDENA_SHIFT             0
#define SCB_CCR_USERSETMPEND_MASK                0x2u
#define SCB_CCR_USERSETMPEND_SHIFT               1
#define SCB_CCR_UNALIGN_TRP_MASK                 0x8u
#define SCB_CCR_UNALIGN_TRP_SHIFT                3
#define SCB_CCR_DIV_0_TRP_MASK                   0x10u
#define SCB_CCR_DIV_0_TRP_SHIFT                  4
#define SCB_CCR_BFHFNMIGN_MASK                   0x100u
#define SCB_CCR_BFHFNMIGN_SHIFT                  8
#define SCB_CCR_STKALIGN_MASK                    0x200u
#define SCB_CCR_STKALIGN_SHIFT                   9
/* SHPR1 Bit Fields */
#define SCB_SHPR1_PRI_4_MASK                     0xFFu
#define SCB_SHPR1_PRI_4_SHIFT                    0
#define SCB_SHPR1_PRI_4(x)                       (((x)<<SCB_SHPR1_PRI_4_SHIFT)&SCB_SHPR1_PRI_4_MASK)
#define SCB_SHPR1_PRI_5_MASK                     0xFF00u
#define SCB_SHPR1_PRI_5_SHIFT                    8
#define SCB_SHPR1_PRI_5(x)                       (((x)<<SCB_SHPR1_PRI_5_SHIFT)&SCB_SHPR1_PRI_5_MASK)
#define SCB_SHPR1_PRI_6_MASK                     0xFF0000u
#define SCB_SHPR1_PRI_6_SHIFT                    16
#define SCB_SHPR1_PRI_6(x)                       (((x)<<SCB_SHPR1_PRI_6_SHIFT)&SCB_SHPR1_PRI_6_MASK)
/* SHPR2 Bit Fields */
#define SCB_SHPR2_PRI_11_MASK                    0xFF000000u
#define SCB_SHPR2_PRI_11_SHIFT                   24
#define SCB_SHPR2_PRI_11(x)                      (((x)<<SCB_SHPR2_PRI_11_SHIFT)&SCB_SHPR2_PRI_11_MASK)
/* SHPR3 Bit Fields */
#define SCB_SHPR3_PRI_14_MASK                    0xFF0000u
#define SCB_SHPR3_PRI_14_SHIFT                   16
#define SCB_SHPR3_PRI_14(x)                      (((x)<<SCB_SHPR3_PRI_14_SHIFT)&SCB_SHPR3_PRI_14_MASK)
#define SCB_SHPR3_PRI_15_MASK                    0xFF000000u
#define SCB_SHPR3_PRI_15_SHIFT                   24
#define SCB_SHPR3_PRI_15(x)                      (((x)<<SCB_SHPR3_PRI_15_SHIFT)&SCB_SHPR3_PRI_15_MASK)
/* SHCSR Bit Fields */
#define SCB_SHCSR_MEMFAULTACT_MASK               0x1u
#define SCB_SHCSR_MEMFAULTACT_SHIFT              0
#define SCB_SHCSR_BUSFAULTACT_MASK               0x2u
#define SCB_SHCSR_BUSFAULTACT_SHIFT              1
#define SCB_SHCSR_USGFAULTACT_MASK               0x8u
#define SCB_SHCSR_USGFAULTACT_SHIFT              3
#define SCB_SHCSR_SVCALLACT_MASK                 0x80u
#define SCB_SHCSR_SVCALLACT_SHIFT                7
#define SCB_SHCSR_MONITORACT_MASK                0x100u
#define SCB_SHCSR_MONITORACT_SHIFT               8
#define SCB_SHCSR_PENDSVACT_MASK                 0x400u
#define SCB_SHCSR_PENDSVACT_SHIFT                10
#define SCB_SHCSR_SYSTICKACT_MASK                0x800u
#define SCB_SHCSR_SYSTICKACT_SHIFT               11
#define SCB_SHCSR_USGFAULTPENDED_MASK            0x1000u
#define SCB_SHCSR_USGFAULTPENDED_SHIFT           12
#define SCB_SHCSR_MEMFAULTPENDED_MASK            0x2000u
#define SCB_SHCSR_MEMFAULTPENDED_SHIFT           13
#define SCB_SHCSR_BUSFAULTPENDED_MASK            0x4000u
#define SCB_SHCSR_BUSFAULTPENDED_SHIFT           14
#define SCB_SHCSR_SVCALLPENDED_MASK              0x8000u
#define SCB_SHCSR_SVCALLPENDED_SHIFT             15
#define SCB_SHCSR_MEMFAULTENA_MASK               0x10000u
#define SCB_SHCSR_MEMFAULTENA_SHIFT              16
#define SCB_SHCSR_BUSFAULTENA_MASK               0x20000u
#define SCB_SHCSR_BUSFAULTENA_SHIFT              17
#define SCB_SHCSR_USGFAULTENA_MASK               0x40000u
#define SCB_SHCSR_USGFAULTENA_SHIFT              18
/* CFSR Bit Fields */
#define SCB_CFSR_IACCVIOL_MASK                   0x1u
#define SCB_CFSR_IACCVIOL_SHIFT                  0
#define SCB_CFSR_DACCVIOL_MASK                   0x2u
#define SCB_CFSR_DACCVIOL_SHIFT                  1
#define SCB_CFSR_MUNSTKERR_MASK                  0x8u
#define SCB_CFSR_MUNSTKERR_SHIFT                 3
#define SCB_CFSR_MSTKERR_MASK                    0x10u
#define SCB_CFSR_MSTKERR_SHIFT                   4
#define SCB_CFSR_MLSPERR_MASK                    0x20u
#define SCB_CFSR_MLSPERR_SHIFT                   5
#define SCB_CFSR_MMARVALID_MASK                  0x80u
#define SCB_CFSR_MMARVALID_SHIFT                 7
#define SCB_CFSR_IBUSERR_MASK                    0x100u
#define SCB_CFSR_IBUSERR_SHIFT                   8
#define SCB_CFSR_PRECISERR_MASK                  0x200u
#define SCB_CFSR_PRECISERR_SHIFT                 9
#define SCB_CFSR_IMPRECISERR_MASK                0x400u
#define SCB_CFSR_IMPRECISERR_SHIFT               10
#define SCB_CFSR_UNSTKERR_MASK                   0x800u
#define SCB_CFSR_UNSTKERR_SHIFT                  11
#define SCB_CFSR_STKERR_MASK                     0x1000u
#define SCB_CFSR_STKERR_SHIFT                    12
#define SCB_CFSR_LSPERR_MASK                     0x2000u
#define SCB_CFSR_LSPERR_SHIFT                    13
#define SCB_CFSR_BFARVALID_MASK                  0x8000u
#define SCB_CFSR_BFARVALID_SHIFT                 15
#define SCB_CFSR_UNDEFINSTR_MASK                 0x10000u
#define SCB_CFSR_UNDEFINSTR_SHIFT                16
#define SCB_CFSR_INVSTATE_MASK                   0x20000u
#define SCB_CFSR_INVSTATE_SHIFT                  17
#define SCB_CFSR_INVPC_MASK                      0x40000u
#define SCB_CFSR_INVPC_SHIFT                     18
#define SCB_CFSR_NOCP_MASK                       0x80000u
#define SCB_CFSR_NOCP_SHIFT                      19
#define SCB_CFSR_UNALIGNED_MASK                  0x1000000u
#define SCB_CFSR_UNALIGNED_SHIFT                 24
#define SCB_CFSR_DIVBYZERO_MASK                  0x2000000u
#define SCB_CFSR_DIVBYZERO_SHIFT                 25
/* HFSR Bit Fields */
#define SCB_HFSR_VECTTBL_MASK                    0x2u
#define SCB_HFSR_VECTTBL_SHIFT                   1
#define SCB_HFSR_FORCED_MASK                     0x40000000u
#define SCB_HFSR_FORCED_SHIFT                    30
#define SCB_HFSR_DEBUGEVT_MASK                   0x80000000u
#define SCB_HFSR_DEBUGEVT_SHIFT                  31
/* DFSR Bit Fields */
#define SCB_DFSR_HALTED_MASK                     0x1u
#define SCB_DFSR_HALTED_SHIFT                    0
#define SCB_DFSR_BKPT_MASK                       0x2u
#define SCB_DFSR_BKPT_SHIFT                      1
#define SCB_DFSR_DWTTRAP_MASK                    0x4u
#define SCB_DFSR_DWTTRAP_SHIFT                   2
#define SCB_DFSR_VCATCH_MASK                     0x8u
#define SCB_DFSR_VCATCH_SHIFT                    3
#define SCB_DFSR_EXTERNAL_MASK                   0x10u
#define SCB_DFSR_EXTERNAL_SHIFT                  4
/* MMFAR Bit Fields */
#define SCB_MMFAR_ADDRESS_MASK                   0xFFFFFFFFu
#define SCB_MMFAR_ADDRESS_SHIFT                  0
#define SCB_MMFAR_ADDRESS(x)                     (((x)<<SCB_MMFAR_ADDRESS_SHIFT)&SCB_MMFAR_ADDRESS_MASK)
/* BFAR Bit Fields */
#define SCB_BFAR_ADDRESS_MASK                    0xFFFFFFFFu
#define SCB_BFAR_ADDRESS_SHIFT                   0
#define SCB_BFAR_ADDRESS(x)                      (((x)<<SCB_BFAR_ADDRESS_SHIFT)&SCB_BFAR_ADDRESS_MASK)
/* AFSR Bit Fields */
#define SCB_AFSR_AUXFAULT_MASK                   0xFFFFFFFFu
#define SCB_AFSR_AUXFAULT_SHIFT                  0
#define SCB_AFSR_AUXFAULT(x)                     (((x)<<SCB_AFSR_AUXFAULT_SHIFT)&SCB_AFSR_AUXFAULT_MASK)

/*! \} */ /* end of group SCB_Register_Masks */


/* SCB - Peripheral instance base addresses */
/*! Peripheral SystemControl base pointer */
#define SystemControl_BASE_PTR                   ((SCB_MemMapPtr)0xE000E000u)

/* ----------------------------------------------------------------------------
   -- SCB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup SCB_Register_Accessor_Macros SCB - Register accessor macros */
/*! \{ */


/* SCB - Register instance definitions */
/* SystemControl */
#define SCB_ACTLR                                SCB_ACTLR_REG(SystemControl_BASE_PTR)
#define SCB_CPUID                                SCB_CPUID_REG(SystemControl_BASE_PTR)
#define SCB_ICSR                                 SCB_ICSR_REG(SystemControl_BASE_PTR)
#define SCB_AIRCR                                SCB_AIRCR_REG(SystemControl_BASE_PTR)
#define SCB_VTOR                                 SCB_VTOR_REG(SystemControl_BASE_PTR)
#define SCB_SCR                                  SCB_SCR_REG(SystemControl_BASE_PTR)
#define SCB_CCR                                  SCB_CCR_REG(SystemControl_BASE_PTR)
#define SCB_SHPR1                                SCB_SHPR1_REG(SystemControl_BASE_PTR)
#define SCB_SHPR2                                SCB_SHPR2_REG(SystemControl_BASE_PTR)
#define SCB_SHPR3                                SCB_SHPR3_REG(SystemControl_BASE_PTR)
#define SCB_SHCSR                                SCB_SHCSR_REG(SystemControl_BASE_PTR)
#define SCB_CFSR                                 SCB_CFSR_REG(SystemControl_BASE_PTR)
#define SCB_HFSR                                 SCB_HFSR_REG(SystemControl_BASE_PTR)
#define SCB_DFSR                                 SCB_DFSR_REG(SystemControl_BASE_PTR)
#define SCB_MMFAR                                SCB_MMFAR_REG(SystemControl_BASE_PTR)
#define SCB_BFAR                                 SCB_BFAR_REG(SystemControl_BASE_PTR)
#define SCB_AFSR                                 SCB_AFSR_REG(SystemControl_BASE_PTR)

/*! \} */ /* end of group SCB_Register_Accessor_Macros */


/*! \} */ /* end of group SCB_Peripheral */


/* ----------------------------------------------------------------------------
   -- TSI
   ---------------------------------------------------------------------------- */

/*! \addtogroup TSI_Peripheral TSI */
/*! \{ */

/*! TSI - Peripheral register structure */
typedef struct TSI_MemMap {
  uint32_t GENCS;                                  /*!< General Control and Status Register, offset: 0x0 */
  uint32_t SCANC;                                  /*!< SCAN Control Register, offset: 0x4 */
  uint32_t PEN;                                    /*!< Pin Enable Register, offset: 0x8 */
  uint32_t STATUS;                                 /*!< Status Register, offset: 0xC */
  uint32_t WUCNTR;                                 /*!< Wake-Up Channel Counter Register, offset: 0x10 */
  uint8_t RESERVED_0[236];
  uint32_t CNTR1;                                  /*!< Counter Register, offset: 0x100 */
  uint32_t CNTR3;                                  /*!< Counter Register, offset: 0x104 */
  uint32_t CNTR5;                                  /*!< Counter Register, offset: 0x108 */
  uint32_t CNTR7;                                  /*!< Counter Register, offset: 0x10C */
  uint32_t CNTR9;                                  /*!< Counter Register, offset: 0x110 */
  uint32_t CNTR11;                                 /*!< Counter Register, offset: 0x114 */
  uint32_t CNTR13;                                 /*!< Counter Register, offset: 0x118 */
  uint32_t CNTR15;                                 /*!< Counter Register, offset: 0x11C */
  uint32_t THRESHLD[16];                           /*!< Channel N Threshold Register, array offset: 0x120, array step: 0x4 */
} volatile *TSI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- TSI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup TSI_Register_Accessor_Macros TSI - Register accessor macros */
/*! \{ */


/* TSI - Register accessors */
#define TSI_GENCS_REG(base)                      ((base)->GENCS)
#define TSI_SCANC_REG(base)                      ((base)->SCANC)
#define TSI_PEN_REG(base)                        ((base)->PEN)
#define TSI_STATUS_REG(base)                     ((base)->STATUS)
#define TSI_WUCNTR_REG(base)                     ((base)->WUCNTR)
#define TSI_CNTR1_REG(base)                      ((base)->CNTR1)
#define TSI_CNTR3_REG(base)                      ((base)->CNTR3)
#define TSI_CNTR5_REG(base)                      ((base)->CNTR5)
#define TSI_CNTR7_REG(base)                      ((base)->CNTR7)
#define TSI_CNTR9_REG(base)                      ((base)->CNTR9)
#define TSI_CNTR11_REG(base)                     ((base)->CNTR11)
#define TSI_CNTR13_REG(base)                     ((base)->CNTR13)
#define TSI_CNTR15_REG(base)                     ((base)->CNTR15)
#define TSI_THRESHLD_REG(base,index)             ((base)->THRESHLD[index])

/*! \} */ /* end of group TSI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- TSI Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup TSI_Register_Masks TSI Register Masks */
/*! \{ */

/* GENCS Bit Fields */
#define TSI_GENCS_STPE_MASK                      0x1u
#define TSI_GENCS_STPE_SHIFT                     0
#define TSI_GENCS_STM_MASK                       0x2u
#define TSI_GENCS_STM_SHIFT                      1
#define TSI_GENCS_ESOR_MASK                      0x10u
#define TSI_GENCS_ESOR_SHIFT                     4
#define TSI_GENCS_ERIE_MASK                      0x20u
#define TSI_GENCS_ERIE_SHIFT                     5
#define TSI_GENCS_TSIIE_MASK                     0x40u
#define TSI_GENCS_TSIIE_SHIFT                    6
#define TSI_GENCS_TSIEN_MASK                     0x80u
#define TSI_GENCS_TSIEN_SHIFT                    7
#define TSI_GENCS_SWTS_MASK                      0x100u
#define TSI_GENCS_SWTS_SHIFT                     8
#define TSI_GENCS_SCNIP_MASK                     0x200u
#define TSI_GENCS_SCNIP_SHIFT                    9
#define TSI_GENCS_OVRF_MASK                      0x1000u
#define TSI_GENCS_OVRF_SHIFT                     12
#define TSI_GENCS_EXTERF_MASK                    0x2000u
#define TSI_GENCS_EXTERF_SHIFT                   13
#define TSI_GENCS_OUTRGF_MASK                    0x4000u
#define TSI_GENCS_OUTRGF_SHIFT                   14
#define TSI_GENCS_EOSF_MASK                      0x8000u
#define TSI_GENCS_EOSF_SHIFT                     15
#define TSI_GENCS_PS_MASK                        0x70000u
#define TSI_GENCS_PS_SHIFT                       16
#define TSI_GENCS_PS(x)                          (((x)<<TSI_GENCS_PS_SHIFT)&TSI_GENCS_PS_MASK)
#define TSI_GENCS_NSCN_MASK                      0xF80000u
#define TSI_GENCS_NSCN_SHIFT                     19
#define TSI_GENCS_NSCN(x)                        (((x)<<TSI_GENCS_NSCN_SHIFT)&TSI_GENCS_NSCN_MASK)
#define TSI_GENCS_LPSCNITV_MASK                  0xF000000u
#define TSI_GENCS_LPSCNITV_SHIFT                 24
#define TSI_GENCS_LPSCNITV(x)                    (((x)<<TSI_GENCS_LPSCNITV_SHIFT)&TSI_GENCS_LPSCNITV_MASK)
#define TSI_GENCS_LPCLKS_MASK                    0x10000000u
#define TSI_GENCS_LPCLKS_SHIFT                   28
/* SCANC Bit Fields */
#define TSI_SCANC_AMPSC_MASK                     0x7u
#define TSI_SCANC_AMPSC_SHIFT                    0
#define TSI_SCANC_AMPSC(x)                       (((x)<<TSI_SCANC_AMPSC_SHIFT)&TSI_SCANC_AMPSC_MASK)
#define TSI_SCANC_AMCLKS_MASK                    0x18u
#define TSI_SCANC_AMCLKS_SHIFT                   3
#define TSI_SCANC_AMCLKS(x)                      (((x)<<TSI_SCANC_AMCLKS_SHIFT)&TSI_SCANC_AMCLKS_MASK)
#define TSI_SCANC_AMCLKDIV_MASK                  0x20u
#define TSI_SCANC_AMCLKDIV_SHIFT                 5
#define TSI_SCANC_SMOD_MASK                      0xFF00u
#define TSI_SCANC_SMOD_SHIFT                     8
#define TSI_SCANC_SMOD(x)                        (((x)<<TSI_SCANC_SMOD_SHIFT)&TSI_SCANC_SMOD_MASK)
#define TSI_SCANC_DELVOL_MASK                    0x70000u
#define TSI_SCANC_DELVOL_SHIFT                   16
#define TSI_SCANC_DELVOL(x)                      (((x)<<TSI_SCANC_DELVOL_SHIFT)&TSI_SCANC_DELVOL_MASK)
#define TSI_SCANC_EXTCHRG_MASK                   0xF80000u
#define TSI_SCANC_EXTCHRG_SHIFT                  19
#define TSI_SCANC_EXTCHRG(x)                     (((x)<<TSI_SCANC_EXTCHRG_SHIFT)&TSI_SCANC_EXTCHRG_MASK)
#define TSI_SCANC_CAPTRM_MASK                    0x7000000u
#define TSI_SCANC_CAPTRM_SHIFT                   24
#define TSI_SCANC_CAPTRM(x)                      (((x)<<TSI_SCANC_CAPTRM_SHIFT)&TSI_SCANC_CAPTRM_MASK)
#define TSI_SCANC_REFCHRG_MASK                   0xF8000000u
#define TSI_SCANC_REFCHRG_SHIFT                  27
#define TSI_SCANC_REFCHRG(x)                     (((x)<<TSI_SCANC_REFCHRG_SHIFT)&TSI_SCANC_REFCHRG_MASK)
/* PEN Bit Fields */
#define TSI_PEN_PEN0_MASK                        0x1u
#define TSI_PEN_PEN0_SHIFT                       0
#define TSI_PEN_PEN1_MASK                        0x2u
#define TSI_PEN_PEN1_SHIFT                       1
#define TSI_PEN_PEN2_MASK                        0x4u
#define TSI_PEN_PEN2_SHIFT                       2
#define TSI_PEN_PEN3_MASK                        0x8u
#define TSI_PEN_PEN3_SHIFT                       3
#define TSI_PEN_PEN4_MASK                        0x10u
#define TSI_PEN_PEN4_SHIFT                       4
#define TSI_PEN_PEN5_MASK                        0x20u
#define TSI_PEN_PEN5_SHIFT                       5
#define TSI_PEN_PEN6_MASK                        0x40u
#define TSI_PEN_PEN6_SHIFT                       6
#define TSI_PEN_PEN7_MASK                        0x80u
#define TSI_PEN_PEN7_SHIFT                       7
#define TSI_PEN_PEN8_MASK                        0x100u
#define TSI_PEN_PEN8_SHIFT                       8
#define TSI_PEN_PEN9_MASK                        0x200u
#define TSI_PEN_PEN9_SHIFT                       9
#define TSI_PEN_PEN10_MASK                       0x400u
#define TSI_PEN_PEN10_SHIFT                      10
#define TSI_PEN_PEN11_MASK                       0x800u
#define TSI_PEN_PEN11_SHIFT                      11
#define TSI_PEN_PEN12_MASK                       0x1000u
#define TSI_PEN_PEN12_SHIFT                      12
#define TSI_PEN_PEN13_MASK                       0x2000u
#define TSI_PEN_PEN13_SHIFT                      13
#define TSI_PEN_PEN14_MASK                       0x4000u
#define TSI_PEN_PEN14_SHIFT                      14
#define TSI_PEN_PEN15_MASK                       0x8000u
#define TSI_PEN_PEN15_SHIFT                      15
#define TSI_PEN_LPSP_MASK                        0xF0000u
#define TSI_PEN_LPSP_SHIFT                       16
#define TSI_PEN_LPSP(x)                          (((x)<<TSI_PEN_LPSP_SHIFT)&TSI_PEN_LPSP_MASK)
/* STATUS Bit Fields */
#define TSI_STATUS_ORNGF0_MASK                   0x1u
#define TSI_STATUS_ORNGF0_SHIFT                  0
#define TSI_STATUS_ORNGF1_MASK                   0x2u
#define TSI_STATUS_ORNGF1_SHIFT                  1
#define TSI_STATUS_ORNGF2_MASK                   0x4u
#define TSI_STATUS_ORNGF2_SHIFT                  2
#define TSI_STATUS_ORNGF3_MASK                   0x8u
#define TSI_STATUS_ORNGF3_SHIFT                  3
#define TSI_STATUS_ORNGF4_MASK                   0x10u
#define TSI_STATUS_ORNGF4_SHIFT                  4
#define TSI_STATUS_ORNGF5_MASK                   0x20u
#define TSI_STATUS_ORNGF5_SHIFT                  5
#define TSI_STATUS_ORNGF6_MASK                   0x40u
#define TSI_STATUS_ORNGF6_SHIFT                  6
#define TSI_STATUS_ORNGF7_MASK                   0x80u
#define TSI_STATUS_ORNGF7_SHIFT                  7
#define TSI_STATUS_ORNGF8_MASK                   0x100u
#define TSI_STATUS_ORNGF8_SHIFT                  8
#define TSI_STATUS_ORNGF9_MASK                   0x200u
#define TSI_STATUS_ORNGF9_SHIFT                  9
#define TSI_STATUS_ORNGF10_MASK                  0x400u
#define TSI_STATUS_ORNGF10_SHIFT                 10
#define TSI_STATUS_ORNGF11_MASK                  0x800u
#define TSI_STATUS_ORNGF11_SHIFT                 11
#define TSI_STATUS_ORNGF12_MASK                  0x1000u
#define TSI_STATUS_ORNGF12_SHIFT                 12
#define TSI_STATUS_ORNGF13_MASK                  0x2000u
#define TSI_STATUS_ORNGF13_SHIFT                 13
#define TSI_STATUS_ORNGF14_MASK                  0x4000u
#define TSI_STATUS_ORNGF14_SHIFT                 14
#define TSI_STATUS_ORNGF15_MASK                  0x8000u
#define TSI_STATUS_ORNGF15_SHIFT                 15
#define TSI_STATUS_ERROF0_MASK                   0x10000u
#define TSI_STATUS_ERROF0_SHIFT                  16
#define TSI_STATUS_ERROF1_MASK                   0x20000u
#define TSI_STATUS_ERROF1_SHIFT                  17
#define TSI_STATUS_ERROF2_MASK                   0x40000u
#define TSI_STATUS_ERROF2_SHIFT                  18
#define TSI_STATUS_ERROF3_MASK                   0x80000u
#define TSI_STATUS_ERROF3_SHIFT                  19
#define TSI_STATUS_ERROF4_MASK                   0x100000u
#define TSI_STATUS_ERROF4_SHIFT                  20
#define TSI_STATUS_ERROF5_MASK                   0x200000u
#define TSI_STATUS_ERROF5_SHIFT                  21
#define TSI_STATUS_ERROF6_MASK                   0x400000u
#define TSI_STATUS_ERROF6_SHIFT                  22
#define TSI_STATUS_ERROF7_MASK                   0x800000u
#define TSI_STATUS_ERROF7_SHIFT                  23
#define TSI_STATUS_ERROF8_MASK                   0x1000000u
#define TSI_STATUS_ERROF8_SHIFT                  24
#define TSI_STATUS_ERROF9_MASK                   0x2000000u
#define TSI_STATUS_ERROF9_SHIFT                  25
#define TSI_STATUS_ERROF10_MASK                  0x4000000u
#define TSI_STATUS_ERROF10_SHIFT                 26
#define TSI_STATUS_ERROF11_MASK                  0x8000000u
#define TSI_STATUS_ERROF11_SHIFT                 27
#define TSI_STATUS_ERROF12_MASK                  0x10000000u
#define TSI_STATUS_ERROF12_SHIFT                 28
#define TSI_STATUS_ERROF13_MASK                  0x20000000u
#define TSI_STATUS_ERROF13_SHIFT                 29
#define TSI_STATUS_ERROF14_MASK                  0x40000000u
#define TSI_STATUS_ERROF14_SHIFT                 30
#define TSI_STATUS_ERROF15_MASK                  0x80000000u
#define TSI_STATUS_ERROF15_SHIFT                 31
/* WUCNTR Bit Fields */
#define TSI_WUCNTR_WUCNT_MASK                    0xFFFFu
#define TSI_WUCNTR_WUCNT_SHIFT                   0
#define TSI_WUCNTR_WUCNT(x)                      (((x)<<TSI_WUCNTR_WUCNT_SHIFT)&TSI_WUCNTR_WUCNT_MASK)
/* CNTR1 Bit Fields */
#define TSI_CNTR1_CNT_MASK                       0xFFFFFFFFu
#define TSI_CNTR1_CNT_SHIFT                      0
#define TSI_CNTR1_CNT(x)                         (((x)<<TSI_CNTR1_CNT_SHIFT)&TSI_CNTR1_CNT_MASK)
/* CNTR3 Bit Fields */
#define TSI_CNTR3_CNT_MASK                       0xFFFFFFFFu
#define TSI_CNTR3_CNT_SHIFT                      0
#define TSI_CNTR3_CNT(x)                         (((x)<<TSI_CNTR3_CNT_SHIFT)&TSI_CNTR3_CNT_MASK)
/* CNTR5 Bit Fields */
#define TSI_CNTR5_CNT_MASK                       0xFFFFFFFFu
#define TSI_CNTR5_CNT_SHIFT                      0
#define TSI_CNTR5_CNT(x)                         (((x)<<TSI_CNTR5_CNT_SHIFT)&TSI_CNTR5_CNT_MASK)
/* CNTR7 Bit Fields */
#define TSI_CNTR7_CNT_MASK                       0xFFFFFFFFu
#define TSI_CNTR7_CNT_SHIFT                      0
#define TSI_CNTR7_CNT(x)                         (((x)<<TSI_CNTR7_CNT_SHIFT)&TSI_CNTR7_CNT_MASK)
/* CNTR9 Bit Fields */
#define TSI_CNTR9_CNT_MASK                       0xFFFFFFFFu
#define TSI_CNTR9_CNT_SHIFT                      0
#define TSI_CNTR9_CNT(x)                         (((x)<<TSI_CNTR9_CNT_SHIFT)&TSI_CNTR9_CNT_MASK)
/* CNTR11 Bit Fields */
#define TSI_CNTR11_CNT_MASK                      0xFFFFFFFFu
#define TSI_CNTR11_CNT_SHIFT                     0
#define TSI_CNTR11_CNT(x)                        (((x)<<TSI_CNTR11_CNT_SHIFT)&TSI_CNTR11_CNT_MASK)
/* CNTR13 Bit Fields */
#define TSI_CNTR13_CNT_MASK                      0xFFFFFFFFu
#define TSI_CNTR13_CNT_SHIFT                     0
#define TSI_CNTR13_CNT(x)                        (((x)<<TSI_CNTR13_CNT_SHIFT)&TSI_CNTR13_CNT_MASK)
/* CNTR15 Bit Fields */
#define TSI_CNTR15_CNT_MASK                      0xFFFFFFFFu
#define TSI_CNTR15_CNT_SHIFT                     0
#define TSI_CNTR15_CNT(x)                        (((x)<<TSI_CNTR15_CNT_SHIFT)&TSI_CNTR15_CNT_MASK)
/* THRESHLD Bit Fields */
#define TSI_THRESHLD_HTHH_MASK                   0xFFFFu
#define TSI_THRESHLD_HTHH_SHIFT                  0
#define TSI_THRESHLD_HTHH(x)                     (((x)<<TSI_THRESHLD_HTHH_SHIFT)&TSI_THRESHLD_HTHH_MASK)
#define TSI_THRESHLD_LTHH_MASK                   0xFFFF0000u
#define TSI_THRESHLD_LTHH_SHIFT                  16
#define TSI_THRESHLD_LTHH(x)                     (((x)<<TSI_THRESHLD_LTHH_SHIFT)&TSI_THRESHLD_LTHH_MASK)

/*! \} */ /* end of group TSI_Register_Masks */


/* TSI - Peripheral instance base addresses */
/*! Peripheral TSI0 base pointer */
#define TSI0_BASE_PTR                            ((TSI_MemMapPtr)0x40045000u)

/* ----------------------------------------------------------------------------
   -- TSI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup TSI_Register_Accessor_Macros TSI - Register accessor macros */
/*! \{ */


/* TSI - Register instance definitions */
/* TSI0 */
#define TSI_GENCS                                TSI_GENCS_REG(TSI0_BASE_PTR)
#define TSI_SCANC                                TSI_SCANC_REG(TSI0_BASE_PTR)
#define TSI_PEN                                  TSI_PEN_REG(TSI0_BASE_PTR)
#define TSI_STATUS                               TSI_STATUS_REG(TSI0_BASE_PTR)
#define TSI_WUCNTR                               TSI_WUCNTR_REG(TSI0_BASE_PTR)
#define TSI_CNTR1                                TSI_CNTR1_REG(TSI0_BASE_PTR)
#define TSI_CNTR3                                TSI_CNTR3_REG(TSI0_BASE_PTR)
#define TSI_CNTR5                                TSI_CNTR5_REG(TSI0_BASE_PTR)
#define TSI_CNTR7                                TSI_CNTR7_REG(TSI0_BASE_PTR)
#define TSI_CNTR9                                TSI_CNTR9_REG(TSI0_BASE_PTR)
#define TSI_CNTR11                               TSI_CNTR11_REG(TSI0_BASE_PTR)
#define TSI_CNTR13                               TSI_CNTR13_REG(TSI0_BASE_PTR)
#define TSI_CNTR15                               TSI_CNTR15_REG(TSI0_BASE_PTR)
#define TSI_THRESHLD0                            TSI_THRESHLD_REG(TSI0_BASE_PTR,0)
#define TSI_THRESHLD1                            TSI_THRESHLD_REG(TSI0_BASE_PTR,1)
#define TSI_THRESHLD2                            TSI_THRESHLD_REG(TSI0_BASE_PTR,2)
#define TSI_THRESHLD3                            TSI_THRESHLD_REG(TSI0_BASE_PTR,3)
#define TSI_THRESHLD4                            TSI_THRESHLD_REG(TSI0_BASE_PTR,4)
#define TSI_THRESHLD5                            TSI_THRESHLD_REG(TSI0_BASE_PTR,5)
#define TSI_THRESHLD6                            TSI_THRESHLD_REG(TSI0_BASE_PTR,6)
#define TSI_THRESHLD7                            TSI_THRESHLD_REG(TSI0_BASE_PTR,7)
#define TSI_THRESHLD8                            TSI_THRESHLD_REG(TSI0_BASE_PTR,8)
#define TSI_THRESHLD9                            TSI_THRESHLD_REG(TSI0_BASE_PTR,9)
#define TSI_THRESHLD10                           TSI_THRESHLD_REG(TSI0_BASE_PTR,10)
#define TSI_THRESHLD11                           TSI_THRESHLD_REG(TSI0_BASE_PTR,11)
#define TSI_THRESHLD12                           TSI_THRESHLD_REG(TSI0_BASE_PTR,12)
#define TSI_THRESHLD13                           TSI_THRESHLD_REG(TSI0_BASE_PTR,13)
#define TSI_THRESHLD14                           TSI_THRESHLD_REG(TSI0_BASE_PTR,14)
#define TSI_THRESHLD15                           TSI_THRESHLD_REG(TSI0_BASE_PTR,15)

/*! \} */ /* end of group TSI_Register_Accessor_Macros */


/*! \} */ /* end of group TSI_Peripheral */


/* ----------------------------------------------------------------------------
   -- UART
   ---------------------------------------------------------------------------- */

/*! \addtogroup UART_Peripheral UART */
/*! \{ */

/*! UART - Peripheral register structure */
typedef struct UART_MemMap {
  uint8_t BDH;                                     /*!< UART Baud Rate Registers:High, offset: 0x0 */
  uint8_t BDL;                                     /*!< UART Baud Rate Registers: Low, offset: 0x1 */
  uint8_t C1;                                      /*!< UART Control Register 1, offset: 0x2 */
  uint8_t C2;                                      /*!< UART Control Register 2, offset: 0x3 */
  uint8_t S1;                                      /*!< UART Status Register 1, offset: 0x4 */
  uint8_t S2;                                      /*!< UART Status Register 2, offset: 0x5 */
  uint8_t C3;                                      /*!< UART Control Register 3, offset: 0x6 */
  uint8_t D;                                       /*!< UART Data Register, offset: 0x7 */
  uint8_t MA1;                                     /*!< UART Match Address Registers 1, offset: 0x8 */
  uint8_t MA2;                                     /*!< UART Match Address Registers 2, offset: 0x9 */
  uint8_t C4;                                      /*!< UART Control Register 4, offset: 0xA */
  uint8_t C5;                                      /*!< UART Control Register 5, offset: 0xB */
  uint8_t ED;                                      /*!< UART Extended Data Register, offset: 0xC */
  uint8_t MODEM;                                   /*!< UART Modem Register, offset: 0xD */
  uint8_t IR;                                      /*!< UART Infrared Register, offset: 0xE */
  uint8_t RESERVED_0[1];
  uint8_t PFIFO;                                   /*!< UART FIFO Parameters, offset: 0x10 */
  uint8_t CFIFO;                                   /*!< UART FIFO Control Register, offset: 0x11 */
  uint8_t SFIFO;                                   /*!< UART FIFO Status Register, offset: 0x12 */
  uint8_t TWFIFO;                                  /*!< UART FIFO Transmit Watermark, offset: 0x13 */
  uint8_t TCFIFO;                                  /*!< UART FIFO Transmit Count, offset: 0x14 */
  uint8_t RWFIFO;                                  /*!< UART FIFO Receive Watermark, offset: 0x15 */
  uint8_t RCFIFO;                                  /*!< UART FIFO Receive Count, offset: 0x16 */
  uint8_t RESERVED_1[1];
  uint8_t C7816;                                   /*!< UART 7816 Control Register, offset: 0x18 */
  uint8_t IE7816;                                  /*!< UART 7816 Interrupt Enable Register, offset: 0x19 */
  uint8_t IS7816;                                  /*!< UART 7816 Interrupt Status Register, offset: 0x1A */
  union {                                          /* offset: 0x1B */
    uint8_t WP7816_T_TYPE0;                          /*!< UART 7816 Wait Parameter Register, offset: 0x1B */
    uint8_t WP7816_T_TYPE1;                          /*!< UART 7816 Wait Parameter Register, offset: 0x1B */
  };
  uint8_t WN7816;                                  /*!< UART 7816 Wait N Register, offset: 0x1C */
  uint8_t WF7816;                                  /*!< UART 7816 Wait FD Register, offset: 0x1D */
  uint8_t ET7816;                                  /*!< UART 7816 Error Threshold Register, offset: 0x1E */
  uint8_t TL7816;                                  /*!< UART 7816 Transmit Length Register, offset: 0x1F */
} volatile *UART_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup UART_Register_Accessor_Macros UART - Register accessor macros */
/*! \{ */


/* UART - Register accessors */
#define UART_BDH_REG(base)                       ((base)->BDH)
#define UART_BDL_REG(base)                       ((base)->BDL)
#define UART_C1_REG(base)                        ((base)->C1)
#define UART_C2_REG(base)                        ((base)->C2)
#define UART_S1_REG(base)                        ((base)->S1)
#define UART_S2_REG(base)                        ((base)->S2)
#define UART_C3_REG(base)                        ((base)->C3)
#define UART_D_REG(base)                         ((base)->D)
#define UART_MA1_REG(base)                       ((base)->MA1)
#define UART_MA2_REG(base)                       ((base)->MA2)
#define UART_C4_REG(base)                        ((base)->C4)
#define UART_C5_REG(base)                        ((base)->C5)
#define UART_ED_REG(base)                        ((base)->ED)
#define UART_MODEM_REG(base)                     ((base)->MODEM)
#define UART_IR_REG(base)                        ((base)->IR)
#define UART_PFIFO_REG(base)                     ((base)->PFIFO)
#define UART_CFIFO_REG(base)                     ((base)->CFIFO)
#define UART_SFIFO_REG(base)                     ((base)->SFIFO)
#define UART_TWFIFO_REG(base)                    ((base)->TWFIFO)
#define UART_TCFIFO_REG(base)                    ((base)->TCFIFO)
#define UART_RWFIFO_REG(base)                    ((base)->RWFIFO)
#define UART_RCFIFO_REG(base)                    ((base)->RCFIFO)
#define UART_C7816_REG(base)                     ((base)->C7816)
#define UART_IE7816_REG(base)                    ((base)->IE7816)
#define UART_IS7816_REG(base)                    ((base)->IS7816)
#define UART_WP7816_T_TYPE0_REG(base)            ((base)->WP7816_T_TYPE0)
#define UART_WP7816_T_TYPE1_REG(base)            ((base)->WP7816_T_TYPE1)
#define UART_WN7816_REG(base)                    ((base)->WN7816)
#define UART_WF7816_REG(base)                    ((base)->WF7816)
#define UART_ET7816_REG(base)                    ((base)->ET7816)
#define UART_TL7816_REG(base)                    ((base)->TL7816)

/*! \} */ /* end of group UART_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup UART_Register_Masks UART Register Masks */
/*! \{ */

/* BDH Bit Fields */
#define UART_BDH_SBR_MASK                        0x1Fu
#define UART_BDH_SBR_SHIFT                       0
#define UART_BDH_SBR(x)                          (((x)<<UART_BDH_SBR_SHIFT)&UART_BDH_SBR_MASK)
#define UART_BDH_RXEDGIE_MASK                    0x40u
#define UART_BDH_RXEDGIE_SHIFT                   6
#define UART_BDH_LBKDIE_MASK                     0x80u
#define UART_BDH_LBKDIE_SHIFT                    7
/* BDL Bit Fields */
#define UART_BDL_SBR_MASK                        0xFFu
#define UART_BDL_SBR_SHIFT                       0
#define UART_BDL_SBR(x)                          (((x)<<UART_BDL_SBR_SHIFT)&UART_BDL_SBR_MASK)
/* C1 Bit Fields */
#define UART_C1_PT_MASK                          0x1u
#define UART_C1_PT_SHIFT                         0
#define UART_C1_PE_MASK                          0x2u
#define UART_C1_PE_SHIFT                         1
#define UART_C1_ILT_MASK                         0x4u
#define UART_C1_ILT_SHIFT                        2
#define UART_C1_WAKE_MASK                        0x8u
#define UART_C1_WAKE_SHIFT                       3
#define UART_C1_M_MASK                           0x10u
#define UART_C1_M_SHIFT                          4
#define UART_C1_RSRC_MASK                        0x20u
#define UART_C1_RSRC_SHIFT                       5
#define UART_C1_UARTSWAI_MASK                    0x40u
#define UART_C1_UARTSWAI_SHIFT                   6
#define UART_C1_LOOPS_MASK                       0x80u
#define UART_C1_LOOPS_SHIFT                      7
/* C2 Bit Fields */
#define UART_C2_SBK_MASK                         0x1u
#define UART_C2_SBK_SHIFT                        0
#define UART_C2_RWU_MASK                         0x2u
#define UART_C2_RWU_SHIFT                        1
#define UART_C2_RE_MASK                          0x4u
#define UART_C2_RE_SHIFT                         2
#define UART_C2_TE_MASK                          0x8u
#define UART_C2_TE_SHIFT                         3
#define UART_C2_ILIE_MASK                        0x10u
#define UART_C2_ILIE_SHIFT                       4
#define UART_C2_RIE_MASK                         0x20u
#define UART_C2_RIE_SHIFT                        5
#define UART_C2_TCIE_MASK                        0x40u
#define UART_C2_TCIE_SHIFT                       6
#define UART_C2_TIE_MASK                         0x80u
#define UART_C2_TIE_SHIFT                        7
/* S1 Bit Fields */
#define UART_S1_PF_MASK                          0x1u
#define UART_S1_PF_SHIFT                         0
#define UART_S1_FE_MASK                          0x2u
#define UART_S1_FE_SHIFT                         1
#define UART_S1_NF_MASK                          0x4u
#define UART_S1_NF_SHIFT                         2
#define UART_S1_OR_MASK                          0x8u
#define UART_S1_OR_SHIFT                         3
#define UART_S1_IDLE_MASK                        0x10u
#define UART_S1_IDLE_SHIFT                       4
#define UART_S1_RDRF_MASK                        0x20u
#define UART_S1_RDRF_SHIFT                       5
#define UART_S1_TC_MASK                          0x40u
#define UART_S1_TC_SHIFT                         6
#define UART_S1_TDRE_MASK                        0x80u
#define UART_S1_TDRE_SHIFT                       7
/* S2 Bit Fields */
#define UART_S2_RAF_MASK                         0x1u
#define UART_S2_RAF_SHIFT                        0
#define UART_S2_LBKDE_MASK                       0x2u
#define UART_S2_LBKDE_SHIFT                      1
#define UART_S2_BRK13_MASK                       0x4u
#define UART_S2_BRK13_SHIFT                      2
#define UART_S2_RWUID_MASK                       0x8u
#define UART_S2_RWUID_SHIFT                      3
#define UART_S2_RXINV_MASK                       0x10u
#define UART_S2_RXINV_SHIFT                      4
#define UART_S2_MSBF_MASK                        0x20u
#define UART_S2_MSBF_SHIFT                       5
#define UART_S2_RXEDGIF_MASK                     0x40u
#define UART_S2_RXEDGIF_SHIFT                    6
#define UART_S2_LBKDIF_MASK                      0x80u
#define UART_S2_LBKDIF_SHIFT                     7
/* C3 Bit Fields */
#define UART_C3_PEIE_MASK                        0x1u
#define UART_C3_PEIE_SHIFT                       0
#define UART_C3_FEIE_MASK                        0x2u
#define UART_C3_FEIE_SHIFT                       1
#define UART_C3_NEIE_MASK                        0x4u
#define UART_C3_NEIE_SHIFT                       2
#define UART_C3_ORIE_MASK                        0x8u
#define UART_C3_ORIE_SHIFT                       3
#define UART_C3_TXINV_MASK                       0x10u
#define UART_C3_TXINV_SHIFT                      4
#define UART_C3_TXDIR_MASK                       0x20u
#define UART_C3_TXDIR_SHIFT                      5
#define UART_C3_T8_MASK                          0x40u
#define UART_C3_T8_SHIFT                         6
#define UART_C3_R8_MASK                          0x80u
#define UART_C3_R8_SHIFT                         7
/* D Bit Fields */
#define UART_D_RT_MASK                           0xFFu
#define UART_D_RT_SHIFT                          0
#define UART_D_RT(x)                             (((x)<<UART_D_RT_SHIFT)&UART_D_RT_MASK)
/* MA1 Bit Fields */
#define UART_MA1_MA_MASK                         0xFFu
#define UART_MA1_MA_SHIFT                        0
#define UART_MA1_MA(x)                           (((x)<<UART_MA1_MA_SHIFT)&UART_MA1_MA_MASK)
/* MA2 Bit Fields */
#define UART_MA2_MA_MASK                         0xFFu
#define UART_MA2_MA_SHIFT                        0
#define UART_MA2_MA(x)                           (((x)<<UART_MA2_MA_SHIFT)&UART_MA2_MA_MASK)
/* C4 Bit Fields */
#define UART_C4_BRFA_MASK                        0x1Fu
#define UART_C4_BRFA_SHIFT                       0
#define UART_C4_BRFA(x)                          (((x)<<UART_C4_BRFA_SHIFT)&UART_C4_BRFA_MASK)
#define UART_C4_M10_MASK                         0x20u
#define UART_C4_M10_SHIFT                        5
#define UART_C4_MAEN2_MASK                       0x40u
#define UART_C4_MAEN2_SHIFT                      6
#define UART_C4_MAEN1_MASK                       0x80u
#define UART_C4_MAEN1_SHIFT                      7
/* C5 Bit Fields */
#define UART_C5_RDMAS_MASK                       0x20u
#define UART_C5_RDMAS_SHIFT                      5
#define UART_C5_TDMAS_MASK                       0x80u
#define UART_C5_TDMAS_SHIFT                      7
/* ED Bit Fields */
#define UART_ED_PARITYE_MASK                     0x40u
#define UART_ED_PARITYE_SHIFT                    6
#define UART_ED_NOISY_MASK                       0x80u
#define UART_ED_NOISY_SHIFT                      7
/* MODEM Bit Fields */
#define UART_MODEM_TXCTSE_MASK                   0x1u
#define UART_MODEM_TXCTSE_SHIFT                  0
#define UART_MODEM_TXRTSE_MASK                   0x2u
#define UART_MODEM_TXRTSE_SHIFT                  1
#define UART_MODEM_TXRTSPOL_MASK                 0x4u
#define UART_MODEM_TXRTSPOL_SHIFT                2
#define UART_MODEM_RXRTSE_MASK                   0x8u
#define UART_MODEM_RXRTSE_SHIFT                  3
/* IR Bit Fields */
#define UART_IR_TNP_MASK                         0x3u
#define UART_IR_TNP_SHIFT                        0
#define UART_IR_TNP(x)                           (((x)<<UART_IR_TNP_SHIFT)&UART_IR_TNP_MASK)
#define UART_IR_IREN_MASK                        0x4u
#define UART_IR_IREN_SHIFT                       2
/* PFIFO Bit Fields */
#define UART_PFIFO_RXFIFOSIZE_MASK               0x7u
#define UART_PFIFO_RXFIFOSIZE_SHIFT              0
#define UART_PFIFO_RXFIFOSIZE(x)                 (((x)<<UART_PFIFO_RXFIFOSIZE_SHIFT)&UART_PFIFO_RXFIFOSIZE_MASK)
#define UART_PFIFO_RXFE_MASK                     0x8u
#define UART_PFIFO_RXFE_SHIFT                    3
#define UART_PFIFO_TXFIFOSIZE_MASK               0x70u
#define UART_PFIFO_TXFIFOSIZE_SHIFT              4
#define UART_PFIFO_TXFIFOSIZE(x)                 (((x)<<UART_PFIFO_TXFIFOSIZE_SHIFT)&UART_PFIFO_TXFIFOSIZE_MASK)
#define UART_PFIFO_TXFE_MASK                     0x80u
#define UART_PFIFO_TXFE_SHIFT                    7
/* CFIFO Bit Fields */
#define UART_CFIFO_RXUFE_MASK                    0x1u
#define UART_CFIFO_RXUFE_SHIFT                   0
#define UART_CFIFO_TXOFE_MASK                    0x2u
#define UART_CFIFO_TXOFE_SHIFT                   1
#define UART_CFIFO_RXFLUSH_MASK                  0x40u
#define UART_CFIFO_RXFLUSH_SHIFT                 6
#define UART_CFIFO_TXFLUSH_MASK                  0x80u
#define UART_CFIFO_TXFLUSH_SHIFT                 7
/* SFIFO Bit Fields */
#define UART_SFIFO_RXUF_MASK                     0x1u
#define UART_SFIFO_RXUF_SHIFT                    0
#define UART_SFIFO_TXOF_MASK                     0x2u
#define UART_SFIFO_TXOF_SHIFT                    1
#define UART_SFIFO_RXEMPT_MASK                   0x40u
#define UART_SFIFO_RXEMPT_SHIFT                  6
#define UART_SFIFO_TXEMPT_MASK                   0x80u
#define UART_SFIFO_TXEMPT_SHIFT                  7
/* TWFIFO Bit Fields */
#define UART_TWFIFO_TXWATER_MASK                 0xFFu
#define UART_TWFIFO_TXWATER_SHIFT                0
#define UART_TWFIFO_TXWATER(x)                   (((x)<<UART_TWFIFO_TXWATER_SHIFT)&UART_TWFIFO_TXWATER_MASK)
/* TCFIFO Bit Fields */
#define UART_TCFIFO_TXCOUNT_MASK                 0xFFu
#define UART_TCFIFO_TXCOUNT_SHIFT                0
#define UART_TCFIFO_TXCOUNT(x)                   (((x)<<UART_TCFIFO_TXCOUNT_SHIFT)&UART_TCFIFO_TXCOUNT_MASK)
/* RWFIFO Bit Fields */
#define UART_RWFIFO_RXWATER_MASK                 0xFFu
#define UART_RWFIFO_RXWATER_SHIFT                0
#define UART_RWFIFO_RXWATER(x)                   (((x)<<UART_RWFIFO_RXWATER_SHIFT)&UART_RWFIFO_RXWATER_MASK)
/* RCFIFO Bit Fields */
#define UART_RCFIFO_RXCOUNT_MASK                 0xFFu
#define UART_RCFIFO_RXCOUNT_SHIFT                0
#define UART_RCFIFO_RXCOUNT(x)                   (((x)<<UART_RCFIFO_RXCOUNT_SHIFT)&UART_RCFIFO_RXCOUNT_MASK)
/* C7816 Bit Fields */
#define UART_C7816_ISO_7816E_MASK                0x1u
#define UART_C7816_ISO_7816E_SHIFT               0
#define UART_C7816_TTYPE_MASK                    0x2u
#define UART_C7816_TTYPE_SHIFT                   1
#define UART_C7816_INIT_MASK                     0x4u
#define UART_C7816_INIT_SHIFT                    2
#define UART_C7816_ANACK_MASK                    0x8u
#define UART_C7816_ANACK_SHIFT                   3
#define UART_C7816_ONACK_MASK                    0x10u
#define UART_C7816_ONACK_SHIFT                   4
/* IE7816 Bit Fields */
#define UART_IE7816_RXTE_MASK                    0x1u
#define UART_IE7816_RXTE_SHIFT                   0
#define UART_IE7816_TXTE_MASK                    0x2u
#define UART_IE7816_TXTE_SHIFT                   1
#define UART_IE7816_GTVE_MASK                    0x4u
#define UART_IE7816_GTVE_SHIFT                   2
#define UART_IE7816_INITDE_MASK                  0x10u
#define UART_IE7816_INITDE_SHIFT                 4
#define UART_IE7816_BWTE_MASK                    0x20u
#define UART_IE7816_BWTE_SHIFT                   5
#define UART_IE7816_CWTE_MASK                    0x40u
#define UART_IE7816_CWTE_SHIFT                   6
#define UART_IE7816_WTE_MASK                     0x80u
#define UART_IE7816_WTE_SHIFT                    7
/* IS7816 Bit Fields */
#define UART_IS7816_RXT_MASK                     0x1u
#define UART_IS7816_RXT_SHIFT                    0
#define UART_IS7816_TXT_MASK                     0x2u
#define UART_IS7816_TXT_SHIFT                    1
#define UART_IS7816_GTV_MASK                     0x4u
#define UART_IS7816_GTV_SHIFT                    2
#define UART_IS7816_INITD_MASK                   0x10u
#define UART_IS7816_INITD_SHIFT                  4
#define UART_IS7816_BWT_MASK                     0x20u
#define UART_IS7816_BWT_SHIFT                    5
#define UART_IS7816_CWT_MASK                     0x40u
#define UART_IS7816_CWT_SHIFT                    6
#define UART_IS7816_WT_MASK                      0x80u
#define UART_IS7816_WT_SHIFT                     7
/* WP7816_T_TYPE0 Bit Fields */
#define UART_WP7816_T_TYPE0_WI_MASK              0xFFu
#define UART_WP7816_T_TYPE0_WI_SHIFT             0
#define UART_WP7816_T_TYPE0_WI(x)                (((x)<<UART_WP7816_T_TYPE0_WI_SHIFT)&UART_WP7816_T_TYPE0_WI_MASK)
/* WP7816_T_TYPE1 Bit Fields */
#define UART_WP7816_T_TYPE1_BWI_MASK             0xFu
#define UART_WP7816_T_TYPE1_BWI_SHIFT            0
#define UART_WP7816_T_TYPE1_BWI(x)               (((x)<<UART_WP7816_T_TYPE1_BWI_SHIFT)&UART_WP7816_T_TYPE1_BWI_MASK)
#define UART_WP7816_T_TYPE1_CWI_MASK             0xF0u
#define UART_WP7816_T_TYPE1_CWI_SHIFT            4
#define UART_WP7816_T_TYPE1_CWI(x)               (((x)<<UART_WP7816_T_TYPE1_CWI_SHIFT)&UART_WP7816_T_TYPE1_CWI_MASK)
/* WN7816 Bit Fields */
#define UART_WN7816_GTN_MASK                     0xFFu
#define UART_WN7816_GTN_SHIFT                    0
#define UART_WN7816_GTN(x)                       (((x)<<UART_WN7816_GTN_SHIFT)&UART_WN7816_GTN_MASK)
/* WF7816 Bit Fields */
#define UART_WF7816_GTFD_MASK                    0xFFu
#define UART_WF7816_GTFD_SHIFT                   0
#define UART_WF7816_GTFD(x)                      (((x)<<UART_WF7816_GTFD_SHIFT)&UART_WF7816_GTFD_MASK)
/* ET7816 Bit Fields */
#define UART_ET7816_RXTHRESHOLD_MASK             0xFu
#define UART_ET7816_RXTHRESHOLD_SHIFT            0
#define UART_ET7816_RXTHRESHOLD(x)               (((x)<<UART_ET7816_RXTHRESHOLD_SHIFT)&UART_ET7816_RXTHRESHOLD_MASK)
#define UART_ET7816_TXTHRESHOLD_MASK             0xF0u
#define UART_ET7816_TXTHRESHOLD_SHIFT            4
#define UART_ET7816_TXTHRESHOLD(x)               (((x)<<UART_ET7816_TXTHRESHOLD_SHIFT)&UART_ET7816_TXTHRESHOLD_MASK)
/* TL7816 Bit Fields */
#define UART_TL7816_TLEN_MASK                    0xFFu
#define UART_TL7816_TLEN_SHIFT                   0
#define UART_TL7816_TLEN(x)                      (((x)<<UART_TL7816_TLEN_SHIFT)&UART_TL7816_TLEN_MASK)

/*! \} */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/*! Peripheral UART0 base pointer */
#define UART0_BASE_PTR                           ((UART_MemMapPtr)0x4006A000u)
/*! Peripheral UART1 base pointer */
#define UART1_BASE_PTR                           ((UART_MemMapPtr)0x4006B000u)
/*! Peripheral UART2 base pointer */
#define UART2_BASE_PTR                           ((UART_MemMapPtr)0x4006C000u)
/*! Peripheral UART3 base pointer */
#define UART3_BASE_PTR                           ((UART_MemMapPtr)0x4006D000u)
/*! Peripheral UART4 base pointer */
#define UART4_BASE_PTR                           ((UART_MemMapPtr)0x400EA000u)
/*! Peripheral UART5 base pointer */
#define UART5_BASE_PTR                           ((UART_MemMapPtr)0x400EB000u)

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup UART_Register_Accessor_Macros UART - Register accessor macros */
/*! \{ */


/* UART - Register instance definitions */
/* UART0 */
#define UART0_BDH                                UART_BDH_REG(UART0_BASE_PTR)
#define UART0_BDL                                UART_BDL_REG(UART0_BASE_PTR)
#define UART0_C1                                 UART_C1_REG(UART0_BASE_PTR)
#define UART0_C2                                 UART_C2_REG(UART0_BASE_PTR)
#define UART0_S1                                 UART_S1_REG(UART0_BASE_PTR)
#define UART0_S2                                 UART_S2_REG(UART0_BASE_PTR)
#define UART0_C3                                 UART_C3_REG(UART0_BASE_PTR)
#define UART0_D                                  UART_D_REG(UART0_BASE_PTR)
#define UART0_MA1                                UART_MA1_REG(UART0_BASE_PTR)
#define UART0_MA2                                UART_MA2_REG(UART0_BASE_PTR)
#define UART0_C4                                 UART_C4_REG(UART0_BASE_PTR)
#define UART0_C5                                 UART_C5_REG(UART0_BASE_PTR)
#define UART0_ED                                 UART_ED_REG(UART0_BASE_PTR)
#define UART0_MODEM                              UART_MODEM_REG(UART0_BASE_PTR)
#define UART0_IR                                 UART_IR_REG(UART0_BASE_PTR)
#define UART0_PFIFO                              UART_PFIFO_REG(UART0_BASE_PTR)
#define UART0_CFIFO                              UART_CFIFO_REG(UART0_BASE_PTR)
#define UART0_SFIFO                              UART_SFIFO_REG(UART0_BASE_PTR)
#define UART0_TWFIFO                             UART_TWFIFO_REG(UART0_BASE_PTR)
#define UART0_TCFIFO                             UART_TCFIFO_REG(UART0_BASE_PTR)
#define UART0_RWFIFO                             UART_RWFIFO_REG(UART0_BASE_PTR)
#define UART0_RCFIFO                             UART_RCFIFO_REG(UART0_BASE_PTR)
#define UART0_C7816                              UART_C7816_REG(UART0_BASE_PTR)
#define UART0_IE7816                             UART_IE7816_REG(UART0_BASE_PTR)
#define UART0_IS7816                             UART_IS7816_REG(UART0_BASE_PTR)
#define UART0_WP7816T0                           UART_WP7816_T_TYPE0_REG(UART0_BASE_PTR)
#define UART0_WP7816T1                           UART_WP7816_T_TYPE1_REG(UART0_BASE_PTR)
#define UART0_WN7816                             UART_WN7816_REG(UART0_BASE_PTR)
#define UART0_WF7816                             UART_WF7816_REG(UART0_BASE_PTR)
#define UART0_ET7816                             UART_ET7816_REG(UART0_BASE_PTR)
#define UART0_TL7816                             UART_TL7816_REG(UART0_BASE_PTR)
/* UART1 */
#define UART1_BDH                                UART_BDH_REG(UART1_BASE_PTR)
#define UART1_BDL                                UART_BDL_REG(UART1_BASE_PTR)
#define UART1_C1                                 UART_C1_REG(UART1_BASE_PTR)
#define UART1_C2                                 UART_C2_REG(UART1_BASE_PTR)
#define UART1_S1                                 UART_S1_REG(UART1_BASE_PTR)
#define UART1_S2                                 UART_S2_REG(UART1_BASE_PTR)
#define UART1_C3                                 UART_C3_REG(UART1_BASE_PTR)
#define UART1_D                                  UART_D_REG(UART1_BASE_PTR)
#define UART1_MA1                                UART_MA1_REG(UART1_BASE_PTR)
#define UART1_MA2                                UART_MA2_REG(UART1_BASE_PTR)
#define UART1_C4                                 UART_C4_REG(UART1_BASE_PTR)
#define UART1_C5                                 UART_C5_REG(UART1_BASE_PTR)
#define UART1_ED                                 UART_ED_REG(UART1_BASE_PTR)
#define UART1_MODEM                              UART_MODEM_REG(UART1_BASE_PTR)
#define UART1_IR                                 UART_IR_REG(UART1_BASE_PTR)
#define UART1_PFIFO                              UART_PFIFO_REG(UART1_BASE_PTR)
#define UART1_CFIFO                              UART_CFIFO_REG(UART1_BASE_PTR)
#define UART1_SFIFO                              UART_SFIFO_REG(UART1_BASE_PTR)
#define UART1_TWFIFO                             UART_TWFIFO_REG(UART1_BASE_PTR)
#define UART1_TCFIFO                             UART_TCFIFO_REG(UART1_BASE_PTR)
#define UART1_RWFIFO                             UART_RWFIFO_REG(UART1_BASE_PTR)
#define UART1_RCFIFO                             UART_RCFIFO_REG(UART1_BASE_PTR)
/* UART2 */
#define UART2_BDH                                UART_BDH_REG(UART2_BASE_PTR)
#define UART2_BDL                                UART_BDL_REG(UART2_BASE_PTR)
#define UART2_C1                                 UART_C1_REG(UART2_BASE_PTR)
#define UART2_C2                                 UART_C2_REG(UART2_BASE_PTR)
#define UART2_S1                                 UART_S1_REG(UART2_BASE_PTR)
#define UART2_S2                                 UART_S2_REG(UART2_BASE_PTR)
#define UART2_C3                                 UART_C3_REG(UART2_BASE_PTR)
#define UART2_D                                  UART_D_REG(UART2_BASE_PTR)
#define UART2_MA1                                UART_MA1_REG(UART2_BASE_PTR)
#define UART2_MA2                                UART_MA2_REG(UART2_BASE_PTR)
#define UART2_C4                                 UART_C4_REG(UART2_BASE_PTR)
#define UART2_C5                                 UART_C5_REG(UART2_BASE_PTR)
#define UART2_ED                                 UART_ED_REG(UART2_BASE_PTR)
#define UART2_MODEM                              UART_MODEM_REG(UART2_BASE_PTR)
#define UART2_IR                                 UART_IR_REG(UART2_BASE_PTR)
#define UART2_PFIFO                              UART_PFIFO_REG(UART2_BASE_PTR)
#define UART2_CFIFO                              UART_CFIFO_REG(UART2_BASE_PTR)
#define UART2_SFIFO                              UART_SFIFO_REG(UART2_BASE_PTR)
#define UART2_TWFIFO                             UART_TWFIFO_REG(UART2_BASE_PTR)
#define UART2_TCFIFO                             UART_TCFIFO_REG(UART2_BASE_PTR)
#define UART2_RWFIFO                             UART_RWFIFO_REG(UART2_BASE_PTR)
#define UART2_RCFIFO                             UART_RCFIFO_REG(UART2_BASE_PTR)
/* UART3 */
#define UART3_BDH                                UART_BDH_REG(UART3_BASE_PTR)
#define UART3_BDL                                UART_BDL_REG(UART3_BASE_PTR)
#define UART3_C1                                 UART_C1_REG(UART3_BASE_PTR)
#define UART3_C2                                 UART_C2_REG(UART3_BASE_PTR)
#define UART3_S1                                 UART_S1_REG(UART3_BASE_PTR)
#define UART3_S2                                 UART_S2_REG(UART3_BASE_PTR)
#define UART3_C3                                 UART_C3_REG(UART3_BASE_PTR)
#define UART3_D                                  UART_D_REG(UART3_BASE_PTR)
#define UART3_MA1                                UART_MA1_REG(UART3_BASE_PTR)
#define UART3_MA2                                UART_MA2_REG(UART3_BASE_PTR)
#define UART3_C4                                 UART_C4_REG(UART3_BASE_PTR)
#define UART3_C5                                 UART_C5_REG(UART3_BASE_PTR)
#define UART3_ED                                 UART_ED_REG(UART3_BASE_PTR)
#define UART3_MODEM                              UART_MODEM_REG(UART3_BASE_PTR)
#define UART3_IR                                 UART_IR_REG(UART3_BASE_PTR)
#define UART3_PFIFO                              UART_PFIFO_REG(UART3_BASE_PTR)
#define UART3_CFIFO                              UART_CFIFO_REG(UART3_BASE_PTR)
#define UART3_SFIFO                              UART_SFIFO_REG(UART3_BASE_PTR)
#define UART3_TWFIFO                             UART_TWFIFO_REG(UART3_BASE_PTR)
#define UART3_TCFIFO                             UART_TCFIFO_REG(UART3_BASE_PTR)
#define UART3_RWFIFO                             UART_RWFIFO_REG(UART3_BASE_PTR)
#define UART3_RCFIFO                             UART_RCFIFO_REG(UART3_BASE_PTR)
/* UART4 */
#define UART4_BDH                                UART_BDH_REG(UART4_BASE_PTR)
#define UART4_BDL                                UART_BDL_REG(UART4_BASE_PTR)
#define UART4_C1                                 UART_C1_REG(UART4_BASE_PTR)
#define UART4_C2                                 UART_C2_REG(UART4_BASE_PTR)
#define UART4_S1                                 UART_S1_REG(UART4_BASE_PTR)
#define UART4_S2                                 UART_S2_REG(UART4_BASE_PTR)
#define UART4_C3                                 UART_C3_REG(UART4_BASE_PTR)
#define UART4_D                                  UART_D_REG(UART4_BASE_PTR)
#define UART4_MA1                                UART_MA1_REG(UART4_BASE_PTR)
#define UART4_MA2                                UART_MA2_REG(UART4_BASE_PTR)
#define UART4_C4                                 UART_C4_REG(UART4_BASE_PTR)
#define UART4_C5                                 UART_C5_REG(UART4_BASE_PTR)
#define UART4_ED                                 UART_ED_REG(UART4_BASE_PTR)
#define UART4_MODEM                              UART_MODEM_REG(UART4_BASE_PTR)
#define UART4_IR                                 UART_IR_REG(UART4_BASE_PTR)
#define UART4_PFIFO                              UART_PFIFO_REG(UART4_BASE_PTR)
#define UART4_CFIFO                              UART_CFIFO_REG(UART4_BASE_PTR)
#define UART4_SFIFO                              UART_SFIFO_REG(UART4_BASE_PTR)
#define UART4_TWFIFO                             UART_TWFIFO_REG(UART4_BASE_PTR)
#define UART4_TCFIFO                             UART_TCFIFO_REG(UART4_BASE_PTR)
#define UART4_RWFIFO                             UART_RWFIFO_REG(UART4_BASE_PTR)
#define UART4_RCFIFO                             UART_RCFIFO_REG(UART4_BASE_PTR)
/* UART5 */
#define UART5_BDH                                UART_BDH_REG(UART5_BASE_PTR)
#define UART5_BDL                                UART_BDL_REG(UART5_BASE_PTR)
#define UART5_C1                                 UART_C1_REG(UART5_BASE_PTR)
#define UART5_C2                                 UART_C2_REG(UART5_BASE_PTR)
#define UART5_S1                                 UART_S1_REG(UART5_BASE_PTR)
#define UART5_S2                                 UART_S2_REG(UART5_BASE_PTR)
#define UART5_C3                                 UART_C3_REG(UART5_BASE_PTR)
#define UART5_D                                  UART_D_REG(UART5_BASE_PTR)
#define UART5_MA1                                UART_MA1_REG(UART5_BASE_PTR)
#define UART5_MA2                                UART_MA2_REG(UART5_BASE_PTR)
#define UART5_C4                                 UART_C4_REG(UART5_BASE_PTR)
#define UART5_C5                                 UART_C5_REG(UART5_BASE_PTR)
#define UART5_ED                                 UART_ED_REG(UART5_BASE_PTR)
#define UART5_MODEM                              UART_MODEM_REG(UART5_BASE_PTR)
#define UART5_IR                                 UART_IR_REG(UART5_BASE_PTR)
#define UART5_PFIFO                              UART_PFIFO_REG(UART5_BASE_PTR)
#define UART5_CFIFO                              UART_CFIFO_REG(UART5_BASE_PTR)
#define UART5_SFIFO                              UART_SFIFO_REG(UART5_BASE_PTR)
#define UART5_TWFIFO                             UART_TWFIFO_REG(UART5_BASE_PTR)
#define UART5_TCFIFO                             UART_TCFIFO_REG(UART5_BASE_PTR)
#define UART5_RWFIFO                             UART_RWFIFO_REG(UART5_BASE_PTR)
#define UART5_RCFIFO                             UART_RCFIFO_REG(UART5_BASE_PTR)

/*! \} */ /* end of group UART_Register_Accessor_Macros */


/*! \} */ /* end of group UART_Peripheral */


/* ----------------------------------------------------------------------------
   -- USBDCD
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBDCD_Peripheral USBDCD */
/*! \{ */

/*! USBDCD - Peripheral register structure */
typedef struct USBDCD_MemMap {
  uint32_t CONTROL;                                /*!< Control Register, offset: 0x0 */
  uint32_t CLOCK;                                  /*!< Clock Register, offset: 0x4 */
  uint32_t STATUS;                                 /*!< Status Register, offset: 0x8 */
  uint8_t RESERVED_0[4];
  uint32_t TIMER0;                                 /*!< TIMER0 Register, offset: 0x10 */
  uint32_t TIMER1;                                 /*!< , offset: 0x14 */
  uint32_t TIMER2;                                 /*!< , offset: 0x18 */
} volatile *USBDCD_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USBDCD - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBDCD_Register_Accessor_Macros USBDCD - Register accessor macros */
/*! \{ */


/* USBDCD - Register accessors */
#define USBDCD_CONTROL_REG(base)                 ((base)->CONTROL)
#define USBDCD_CLOCK_REG(base)                   ((base)->CLOCK)
#define USBDCD_STATUS_REG(base)                  ((base)->STATUS)
#define USBDCD_TIMER0_REG(base)                  ((base)->TIMER0)
#define USBDCD_TIMER1_REG(base)                  ((base)->TIMER1)
#define USBDCD_TIMER2_REG(base)                  ((base)->TIMER2)

/*! \} */ /* end of group USBDCD_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USBDCD Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBDCD_Register_Masks USBDCD Register Masks */
/*! \{ */

/* CONTROL Bit Fields */
#define USBDCD_CONTROL_IACK_MASK                 0x1u
#define USBDCD_CONTROL_IACK_SHIFT                0
#define USBDCD_CONTROL_IF_MASK                   0x100u
#define USBDCD_CONTROL_IF_SHIFT                  8
#define USBDCD_CONTROL_IE_MASK                   0x10000u
#define USBDCD_CONTROL_IE_SHIFT                  16
#define USBDCD_CONTROL_START_MASK                0x1000000u
#define USBDCD_CONTROL_START_SHIFT               24
#define USBDCD_CONTROL_SR_MASK                   0x2000000u
#define USBDCD_CONTROL_SR_SHIFT                  25
/* CLOCK Bit Fields */
#define USBDCD_CLOCK_CLOCK_UNIT_MASK             0x1u
#define USBDCD_CLOCK_CLOCK_UNIT_SHIFT            0
#define USBDCD_CLOCK_CLOCK_SPEED_MASK            0xFFCu
#define USBDCD_CLOCK_CLOCK_SPEED_SHIFT           2
#define USBDCD_CLOCK_CLOCK_SPEED(x)              (((x)<<USBDCD_CLOCK_CLOCK_SPEED_SHIFT)&USBDCD_CLOCK_CLOCK_SPEED_MASK)
/* STATUS Bit Fields */
#define USBDCD_STATUS_SEQ_RES_MASK               0x30000u
#define USBDCD_STATUS_SEQ_RES_SHIFT              16
#define USBDCD_STATUS_SEQ_RES(x)                 (((x)<<USBDCD_STATUS_SEQ_RES_SHIFT)&USBDCD_STATUS_SEQ_RES_MASK)
#define USBDCD_STATUS_SEQ_STAT_MASK              0xC0000u
#define USBDCD_STATUS_SEQ_STAT_SHIFT             18
#define USBDCD_STATUS_SEQ_STAT(x)                (((x)<<USBDCD_STATUS_SEQ_STAT_SHIFT)&USBDCD_STATUS_SEQ_STAT_MASK)
#define USBDCD_STATUS_ERR_MASK                   0x100000u
#define USBDCD_STATUS_ERR_SHIFT                  20
#define USBDCD_STATUS_TO_MASK                    0x200000u
#define USBDCD_STATUS_TO_SHIFT                   21
#define USBDCD_STATUS_ACTIVE_MASK                0x400000u
#define USBDCD_STATUS_ACTIVE_SHIFT               22
/* TIMER0 Bit Fields */
#define USBDCD_TIMER0_TUNITCON_MASK              0xFFFu
#define USBDCD_TIMER0_TUNITCON_SHIFT             0
#define USBDCD_TIMER0_TUNITCON(x)                (((x)<<USBDCD_TIMER0_TUNITCON_SHIFT)&USBDCD_TIMER0_TUNITCON_MASK)
#define USBDCD_TIMER0_TSEQ_INIT_MASK             0x3FF0000u
#define USBDCD_TIMER0_TSEQ_INIT_SHIFT            16
#define USBDCD_TIMER0_TSEQ_INIT(x)               (((x)<<USBDCD_TIMER0_TSEQ_INIT_SHIFT)&USBDCD_TIMER0_TSEQ_INIT_MASK)
/* TIMER1 Bit Fields */
#define USBDCD_TIMER1_TVDPSRC_ON_MASK            0x3FFu
#define USBDCD_TIMER1_TVDPSRC_ON_SHIFT           0
#define USBDCD_TIMER1_TVDPSRC_ON(x)              (((x)<<USBDCD_TIMER1_TVDPSRC_ON_SHIFT)&USBDCD_TIMER1_TVDPSRC_ON_MASK)
#define USBDCD_TIMER1_TDCD_DBNC_MASK             0x3FF0000u
#define USBDCD_TIMER1_TDCD_DBNC_SHIFT            16
#define USBDCD_TIMER1_TDCD_DBNC(x)               (((x)<<USBDCD_TIMER1_TDCD_DBNC_SHIFT)&USBDCD_TIMER1_TDCD_DBNC_MASK)
/* TIMER2 Bit Fields */
#define USBDCD_TIMER2_CHECK_DM_MASK              0xFu
#define USBDCD_TIMER2_CHECK_DM_SHIFT             0
#define USBDCD_TIMER2_CHECK_DM(x)                (((x)<<USBDCD_TIMER2_CHECK_DM_SHIFT)&USBDCD_TIMER2_CHECK_DM_MASK)
#define USBDCD_TIMER2_TVDPSRC_CON_MASK           0x3FF0000u
#define USBDCD_TIMER2_TVDPSRC_CON_SHIFT          16
#define USBDCD_TIMER2_TVDPSRC_CON(x)             (((x)<<USBDCD_TIMER2_TVDPSRC_CON_SHIFT)&USBDCD_TIMER2_TVDPSRC_CON_MASK)

/*! \} */ /* end of group USBDCD_Register_Masks */


/* USBDCD - Peripheral instance base addresses */
/*! Peripheral USBDCD base pointer */
#define USBDCD_BASE_PTR                          ((USBDCD_MemMapPtr)0x40035000u)

/* ----------------------------------------------------------------------------
   -- USBDCD - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBDCD_Register_Accessor_Macros USBDCD - Register accessor macros */
/*! \{ */


/* USBDCD - Register instance definitions */
/* USBDCD */
#define USBDCD_CONTROL                           USBDCD_CONTROL_REG(USBDCD_BASE_PTR)
#define USBDCD_CLOCK                             USBDCD_CLOCK_REG(USBDCD_BASE_PTR)
#define USBDCD_STATUS                            USBDCD_STATUS_REG(USBDCD_BASE_PTR)
#define USBDCD_TIMER0                            USBDCD_TIMER0_REG(USBDCD_BASE_PTR)
#define USBDCD_TIMER1                            USBDCD_TIMER1_REG(USBDCD_BASE_PTR)
#define USBDCD_TIMER2                            USBDCD_TIMER2_REG(USBDCD_BASE_PTR)

/*! \} */ /* end of group USBDCD_Register_Accessor_Macros */


/*! \} */ /* end of group USBDCD_Peripheral */


/* ----------------------------------------------------------------------------
   -- USBOTG
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBOTG_Peripheral USBOTG */
/*! \{ */

/*! USBOTG - Peripheral register structure */
typedef struct USBOTG_MemMap {
  uint8_t PERID;                                   /*!< Peripheral ID Register, offset: 0x0 */
  uint8_t RESERVED_0[3];
  uint8_t IDCOMP;                                  /*!< Peripheral ID Complement Register, offset: 0x4 */
  uint8_t RESERVED_1[3];
  uint8_t REV;                                     /*!< Peripheral Revision Register, offset: 0x8 */
  uint8_t RESERVED_2[3];
  uint8_t ADDINFO;                                 /*!< Peripheral Additional Info Register, offset: 0xC */
  uint8_t RESERVED_3[3];
  uint8_t OTGISTAT;                                /*!< OTG Interrupt Status Register, offset: 0x10 */
  uint8_t RESERVED_4[3];
  uint8_t OTGICR;                                  /*!< OTG Interrupt Control Register, offset: 0x14 */
  uint8_t RESERVED_5[3];
  uint8_t OTGSTAT;                                 /*!< OTG Status Register, offset: 0x18 */
  uint8_t RESERVED_6[3];
  uint8_t OTGCTL;                                  /*!< OTG Control Register, offset: 0x1C */
  uint8_t RESERVED_7[99];
  uint8_t ISTAT;                                   /*!< Interrupt Status Register, offset: 0x80 */
  uint8_t RESERVED_8[3];
  uint8_t INTEN;                                   /*!< Interrupt Enable Register, offset: 0x84 */
  uint8_t RESERVED_9[3];
  uint8_t ERRSTAT;                                 /*!< Error Interrupt Status Register, offset: 0x88 */
  uint8_t RESERVED_10[3];
  uint8_t ERREN;                                   /*!< Error Interrupt Enable Register, offset: 0x8C */
  uint8_t RESERVED_11[3];
  uint8_t STAT;                                    /*!< Status Register, offset: 0x90 */
  uint8_t RESERVED_12[3];
  uint8_t CTL;                                     /*!< Control Register, offset: 0x94 */
  uint8_t RESERVED_13[3];
  uint8_t ADDR;                                    /*!< Address Register, offset: 0x98 */
  uint8_t RESERVED_14[3];
  uint8_t BDTPAGE1;                                /*!< BDT Page Register 1, offset: 0x9C */
  uint8_t RESERVED_15[3];
  uint8_t FRMNUML;                                 /*!< Frame Number Register Low, offset: 0xA0 */
  uint8_t RESERVED_16[3];
  uint8_t FRMNUMH;                                 /*!< Frame Number Register High, offset: 0xA4 */
  uint8_t RESERVED_17[3];
  uint8_t TOKEN;                                   /*!< Token Register, offset: 0xA8 */
  uint8_t RESERVED_18[3];
  uint8_t SOFTHLD;                                 /*!< SOF Threshold Register, offset: 0xAC */
  uint8_t RESERVED_19[3];
  uint8_t BDTPAGE2;                                /*!< BDT Page Register 2, offset: 0xB0 */
  uint8_t RESERVED_20[3];
  uint8_t BDTPAGE3;                                /*!< BDT Page Register 3, offset: 0xB4 */
  uint8_t RESERVED_21[11];
  struct {                                         /* offset: 0xC0, array step: 0x4 */
    uint8_t ENDPT;                                   /*!< Endpoint Control Register, array offset: 0xC0, array step: 0x4 */
    uint8_t RESERVED_0[3];
  } ENDPOINT[16];
  uint8_t USBCTRL;                                 /*!< USB Control Register, offset: 0x100 */
  uint8_t RESERVED_22[3];
  uint8_t OBSERVE;                                 /*!< USB OTG Observe Register, offset: 0x104 */
  uint8_t RESERVED_23[3];
  uint8_t CONTROL;                                 /*!< USB OTG Control Register, offset: 0x108 */
  uint8_t RESERVED_24[3];
  uint8_t USBTRC0;                                 /*!< USB Transceiver Control Register 0, offset: 0x10C */
} volatile *USBOTG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USBOTG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBOTG_Register_Accessor_Macros USBOTG - Register accessor macros */
/*! \{ */


/* USBOTG - Register accessors */
#define USBOTG_PERID_REG(base)                   ((base)->PERID)
#define USBOTG_IDCOMP_REG(base)                  ((base)->IDCOMP)
#define USBOTG_REV_REG(base)                     ((base)->REV)
#define USBOTG_ADDINFO_REG(base)                 ((base)->ADDINFO)
#define USBOTG_OTGISTAT_REG(base)                ((base)->OTGISTAT)
#define USBOTG_OTGICR_REG(base)                  ((base)->OTGICR)
#define USBOTG_OTGSTAT_REG(base)                 ((base)->OTGSTAT)
#define USBOTG_OTGCTL_REG(base)                  ((base)->OTGCTL)
#define USBOTG_ISTAT_REG(base)                   ((base)->ISTAT)
#define USBOTG_INTEN_REG(base)                   ((base)->INTEN)
#define USBOTG_ERRSTAT_REG(base)                 ((base)->ERRSTAT)
#define USBOTG_ERREN_REG(base)                   ((base)->ERREN)
#define USBOTG_STAT_REG(base)                    ((base)->STAT)
#define USBOTG_CTL_REG(base)                     ((base)->CTL)
#define USBOTG_ADDR_REG(base)                    ((base)->ADDR)
#define USBOTG_BDTPAGE1_REG(base)                ((base)->BDTPAGE1)
#define USBOTG_FRMNUML_REG(base)                 ((base)->FRMNUML)
#define USBOTG_FRMNUMH_REG(base)                 ((base)->FRMNUMH)
#define USBOTG_TOKEN_REG(base)                   ((base)->TOKEN)
#define USBOTG_SOFTHLD_REG(base)                 ((base)->SOFTHLD)
#define USBOTG_BDTPAGE2_REG(base)                ((base)->BDTPAGE2)
#define USBOTG_BDTPAGE3_REG(base)                ((base)->BDTPAGE3)
#define USBOTG_ENDPT_REG(base,index)             ((base)->ENDPOINT[index].ENDPT)
#define USBOTG_USBCTRL_REG(base)                 ((base)->USBCTRL)
#define USBOTG_OBSERVE_REG(base)                 ((base)->OBSERVE)
#define USBOTG_CONTROL_REG(base)                 ((base)->CONTROL)
#define USBOTG_USBTRC0_REG(base)                 ((base)->USBTRC0)

/*! \} */ /* end of group USBOTG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USBOTG Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBOTG_Register_Masks USBOTG Register Masks */
/*! \{ */

/* PERID Bit Fields */
#define USBOTG_PERID_ID_MASK                     0x3Fu
#define USBOTG_PERID_ID_SHIFT                    0
#define USBOTG_PERID_ID(x)                       (((x)<<USBOTG_PERID_ID_SHIFT)&USBOTG_PERID_ID_MASK)
/* IDCOMP Bit Fields */
#define USBOTG_IDCOMP_NID_MASK                   0x3Fu
#define USBOTG_IDCOMP_NID_SHIFT                  0
#define USBOTG_IDCOMP_NID(x)                     (((x)<<USBOTG_IDCOMP_NID_SHIFT)&USBOTG_IDCOMP_NID_MASK)
/* REV Bit Fields */
#define USBOTG_REV_REV_MASK                      0xFFu
#define USBOTG_REV_REV_SHIFT                     0
#define USBOTG_REV_REV(x)                        (((x)<<USBOTG_REV_REV_SHIFT)&USBOTG_REV_REV_MASK)
/* ADDINFO Bit Fields */
#define USBOTG_ADDINFO_IEHOST_MASK               0x1u
#define USBOTG_ADDINFO_IEHOST_SHIFT              0
#define USBOTG_ADDINFO_IRQNUM_MASK               0xF8u
#define USBOTG_ADDINFO_IRQNUM_SHIFT              3
#define USBOTG_ADDINFO_IRQNUM(x)                 (((x)<<USBOTG_ADDINFO_IRQNUM_SHIFT)&USBOTG_ADDINFO_IRQNUM_MASK)
/* OTGISTAT Bit Fields */
#define USBOTG_OTGISTAT_AVBUSCHG_MASK            0x1u
#define USBOTG_OTGISTAT_AVBUSCHG_SHIFT           0
#define USBOTG_OTGISTAT_B_SESS_CHG_MASK          0x4u
#define USBOTG_OTGISTAT_B_SESS_CHG_SHIFT         2
#define USBOTG_OTGISTAT_SESSVLDCHG_MASK          0x8u
#define USBOTG_OTGISTAT_SESSVLDCHG_SHIFT         3
#define USBOTG_OTGISTAT_LINE_STATE_CHG_MASK      0x20u
#define USBOTG_OTGISTAT_LINE_STATE_CHG_SHIFT     5
#define USBOTG_OTGISTAT_ONEMSEC_MASK             0x40u
#define USBOTG_OTGISTAT_ONEMSEC_SHIFT            6
#define USBOTG_OTGISTAT_IDCHG_MASK               0x80u
#define USBOTG_OTGISTAT_IDCHG_SHIFT              7
/* OTGICR Bit Fields */
#define USBOTG_OTGICR_AVBUSEN_MASK               0x1u
#define USBOTG_OTGICR_AVBUSEN_SHIFT              0
#define USBOTG_OTGICR_BSESSEN_MASK               0x4u
#define USBOTG_OTGICR_BSESSEN_SHIFT              2
#define USBOTG_OTGICR_SESSVLDEN_MASK             0x8u
#define USBOTG_OTGICR_SESSVLDEN_SHIFT            3
#define USBOTG_OTGICR_LINESTATEEN_MASK           0x20u
#define USBOTG_OTGICR_LINESTATEEN_SHIFT          5
#define USBOTG_OTGICR_ONEMSECEN_MASK             0x40u
#define USBOTG_OTGICR_ONEMSECEN_SHIFT            6
#define USBOTG_OTGICR_IDEN_MASK                  0x80u
#define USBOTG_OTGICR_IDEN_SHIFT                 7
/* OTGSTAT Bit Fields */
#define USBOTG_OTGSTAT_AVBUSVLD_MASK             0x1u
#define USBOTG_OTGSTAT_AVBUSVLD_SHIFT            0
#define USBOTG_OTGSTAT_BSESSEND_MASK             0x4u
#define USBOTG_OTGSTAT_BSESSEND_SHIFT            2
#define USBOTG_OTGSTAT_SESS_VLD_MASK             0x8u
#define USBOTG_OTGSTAT_SESS_VLD_SHIFT            3
#define USBOTG_OTGSTAT_LINESTATESTABLE_MASK      0x20u
#define USBOTG_OTGSTAT_LINESTATESTABLE_SHIFT     5
#define USBOTG_OTGSTAT_ONEMSECEN_MASK            0x40u
#define USBOTG_OTGSTAT_ONEMSECEN_SHIFT           6
#define USBOTG_OTGSTAT_ID_MASK                   0x80u
#define USBOTG_OTGSTAT_ID_SHIFT                  7
/* OTGCTL Bit Fields */
#define USBOTG_OTGCTL_OTGEN_MASK                 0x4u
#define USBOTG_OTGCTL_OTGEN_SHIFT                2
#define USBOTG_OTGCTL_DMLOW_MASK                 0x10u
#define USBOTG_OTGCTL_DMLOW_SHIFT                4
#define USBOTG_OTGCTL_DPLOW_MASK                 0x20u
#define USBOTG_OTGCTL_DPLOW_SHIFT                5
#define USBOTG_OTGCTL_DPHIGH_MASK                0x80u
#define USBOTG_OTGCTL_DPHIGH_SHIFT               7
/* ISTAT Bit Fields */
#define USBOTG_ISTAT_USBRST_MASK                 0x1u
#define USBOTG_ISTAT_USBRST_SHIFT                0
#define USBOTG_ISTAT_ERROR_MASK                  0x2u
#define USBOTG_ISTAT_ERROR_SHIFT                 1
#define USBOTG_ISTAT_SOFTOK_MASK                 0x4u
#define USBOTG_ISTAT_SOFTOK_SHIFT                2
#define USBOTG_ISTAT_TOKDNE_MASK                 0x8u
#define USBOTG_ISTAT_TOKDNE_SHIFT                3
#define USBOTG_ISTAT_SLEEP_MASK                  0x10u
#define USBOTG_ISTAT_SLEEP_SHIFT                 4
#define USBOTG_ISTAT_RESUME_MASK                 0x20u
#define USBOTG_ISTAT_RESUME_SHIFT                5
#define USBOTG_ISTAT_ATTACH_MASK                 0x40u
#define USBOTG_ISTAT_ATTACH_SHIFT                6
#define USBOTG_ISTAT_STALL_MASK                  0x80u
#define USBOTG_ISTAT_STALL_SHIFT                 7
/* INTEN Bit Fields */
#define USBOTG_INTEN_USBRSTEN_MASK               0x1u
#define USBOTG_INTEN_USBRSTEN_SHIFT              0
#define USBOTG_INTEN_ERROREN_MASK                0x2u
#define USBOTG_INTEN_ERROREN_SHIFT               1
#define USBOTG_INTEN_SOFTOKEN_MASK               0x4u
#define USBOTG_INTEN_SOFTOKEN_SHIFT              2
#define USBOTG_INTEN_TOKDNEEN_MASK               0x8u
#define USBOTG_INTEN_TOKDNEEN_SHIFT              3
#define USBOTG_INTEN_SLEEPEN_MASK                0x10u
#define USBOTG_INTEN_SLEEPEN_SHIFT               4
#define USBOTG_INTEN_RESUMEEN_MASK               0x20u
#define USBOTG_INTEN_RESUMEEN_SHIFT              5
#define USBOTG_INTEN_ATTACHEN_MASK               0x40u
#define USBOTG_INTEN_ATTACHEN_SHIFT              6
#define USBOTG_INTEN_STALLEN_MASK                0x80u
#define USBOTG_INTEN_STALLEN_SHIFT               7
/* ERRSTAT Bit Fields */
#define USBOTG_ERRSTAT_PIDERR_MASK               0x1u
#define USBOTG_ERRSTAT_PIDERR_SHIFT              0
#define USBOTG_ERRSTAT_CRC5EOF_MASK              0x2u
#define USBOTG_ERRSTAT_CRC5EOF_SHIFT             1
#define USBOTG_ERRSTAT_CRC16_MASK                0x4u
#define USBOTG_ERRSTAT_CRC16_SHIFT               2
#define USBOTG_ERRSTAT_DFN8_MASK                 0x8u
#define USBOTG_ERRSTAT_DFN8_SHIFT                3
#define USBOTG_ERRSTAT_BTOERR_MASK               0x10u
#define USBOTG_ERRSTAT_BTOERR_SHIFT              4
#define USBOTG_ERRSTAT_DMAERR_MASK               0x20u
#define USBOTG_ERRSTAT_DMAERR_SHIFT              5
#define USBOTG_ERRSTAT_BTSERR_MASK               0x80u
#define USBOTG_ERRSTAT_BTSERR_SHIFT              7
/* ERREN Bit Fields */
#define USBOTG_ERREN_PIDERREN_MASK               0x1u
#define USBOTG_ERREN_PIDERREN_SHIFT              0
#define USBOTG_ERREN_CRC5EOFEN_MASK              0x2u
#define USBOTG_ERREN_CRC5EOFEN_SHIFT             1
#define USBOTG_ERREN_CRC16EN_MASK                0x4u
#define USBOTG_ERREN_CRC16EN_SHIFT               2
#define USBOTG_ERREN_DFN8EN_MASK                 0x8u
#define USBOTG_ERREN_DFN8EN_SHIFT                3
#define USBOTG_ERREN_BTOERREN_MASK               0x10u
#define USBOTG_ERREN_BTOERREN_SHIFT              4
#define USBOTG_ERREN_DMAERREN_MASK               0x20u
#define USBOTG_ERREN_DMAERREN_SHIFT              5
#define USBOTG_ERREN_BTSERREN_MASK               0x80u
#define USBOTG_ERREN_BTSERREN_SHIFT              7
/* STAT Bit Fields */
#define USBOTG_STAT_ODD_MASK                     0x4u
#define USBOTG_STAT_ODD_SHIFT                    2
#define USBOTG_STAT_TX_MASK                      0x8u
#define USBOTG_STAT_TX_SHIFT                     3
#define USBOTG_STAT_ENDP_MASK                    0xF0u
#define USBOTG_STAT_ENDP_SHIFT                   4
#define USBOTG_STAT_ENDP(x)                      (((x)<<USBOTG_STAT_ENDP_SHIFT)&USBOTG_STAT_ENDP_MASK)
/* CTL Bit Fields */
#define USBOTG_CTL_USBENSOFEN_MASK               0x1u
#define USBOTG_CTL_USBENSOFEN_SHIFT              0
#define USBOTG_CTL_ODDRST_MASK                   0x2u
#define USBOTG_CTL_ODDRST_SHIFT                  1
#define USBOTG_CTL_RESUME_MASK                   0x4u
#define USBOTG_CTL_RESUME_SHIFT                  2
#define USBOTG_CTL_HOSTMODEEN_MASK               0x8u
#define USBOTG_CTL_HOSTMODEEN_SHIFT              3
#define USBOTG_CTL_RESET_MASK                    0x10u
#define USBOTG_CTL_RESET_SHIFT                   4
#define USBOTG_CTL_TXSUSPENDTOKENBUSY_MASK       0x20u
#define USBOTG_CTL_TXSUSPENDTOKENBUSY_SHIFT      5
#define USBOTG_CTL_SE0_MASK                      0x40u
#define USBOTG_CTL_SE0_SHIFT                     6
#define USBOTG_CTL_JSTATE_MASK                   0x80u
#define USBOTG_CTL_JSTATE_SHIFT                  7
/* ADDR Bit Fields */
#define USBOTG_ADDR_ADDR_MASK                    0x7Fu
#define USBOTG_ADDR_ADDR_SHIFT                   0
#define USBOTG_ADDR_ADDR(x)                      (((x)<<USBOTG_ADDR_ADDR_SHIFT)&USBOTG_ADDR_ADDR_MASK)
#define USBOTG_ADDR_LSEN_MASK                    0x80u
#define USBOTG_ADDR_LSEN_SHIFT                   7
/* BDTPAGE1 Bit Fields */
#define USBOTG_BDTPAGE1_BDTBA_MASK               0xFEu
#define USBOTG_BDTPAGE1_BDTBA_SHIFT              1
#define USBOTG_BDTPAGE1_BDTBA(x)                 (((x)<<USBOTG_BDTPAGE1_BDTBA_SHIFT)&USBOTG_BDTPAGE1_BDTBA_MASK)
/* FRMNUML Bit Fields */
#define USBOTG_FRMNUML_FRM_MASK                  0xFFu
#define USBOTG_FRMNUML_FRM_SHIFT                 0
#define USBOTG_FRMNUML_FRM(x)                    (((x)<<USBOTG_FRMNUML_FRM_SHIFT)&USBOTG_FRMNUML_FRM_MASK)
/* FRMNUMH Bit Fields */
#define USBOTG_FRMNUMH_FRM_MASK                  0x7u
#define USBOTG_FRMNUMH_FRM_SHIFT                 0
#define USBOTG_FRMNUMH_FRM(x)                    (((x)<<USBOTG_FRMNUMH_FRM_SHIFT)&USBOTG_FRMNUMH_FRM_MASK)
/* TOKEN Bit Fields */
#define USBOTG_TOKEN_TOKENENDPT_MASK             0xFu
#define USBOTG_TOKEN_TOKENENDPT_SHIFT            0
#define USBOTG_TOKEN_TOKENENDPT(x)               (((x)<<USBOTG_TOKEN_TOKENENDPT_SHIFT)&USBOTG_TOKEN_TOKENENDPT_MASK)
#define USBOTG_TOKEN_TOKENPID_MASK               0xF0u
#define USBOTG_TOKEN_TOKENPID_SHIFT              4
#define USBOTG_TOKEN_TOKENPID(x)                 (((x)<<USBOTG_TOKEN_TOKENPID_SHIFT)&USBOTG_TOKEN_TOKENPID_MASK)
/* SOFTHLD Bit Fields */
#define USBOTG_SOFTHLD_CNT_MASK                  0xFFu
#define USBOTG_SOFTHLD_CNT_SHIFT                 0
#define USBOTG_SOFTHLD_CNT(x)                    (((x)<<USBOTG_SOFTHLD_CNT_SHIFT)&USBOTG_SOFTHLD_CNT_MASK)
/* BDTPAGE2 Bit Fields */
#define USBOTG_BDTPAGE2_BDTBA_MASK               0xFFu
#define USBOTG_BDTPAGE2_BDTBA_SHIFT              0
#define USBOTG_BDTPAGE2_BDTBA(x)                 (((x)<<USBOTG_BDTPAGE2_BDTBA_SHIFT)&USBOTG_BDTPAGE2_BDTBA_MASK)
/* BDTPAGE3 Bit Fields */
#define USBOTG_BDTPAGE3_BDTBA_MASK               0xFFu
#define USBOTG_BDTPAGE3_BDTBA_SHIFT              0
#define USBOTG_BDTPAGE3_BDTBA(x)                 (((x)<<USBOTG_BDTPAGE3_BDTBA_SHIFT)&USBOTG_BDTPAGE3_BDTBA_MASK)
/* ENDPT Bit Fields */
#define USBOTG_ENDPT_EPHSHK_MASK                 0x1u
#define USBOTG_ENDPT_EPHSHK_SHIFT                0
#define USBOTG_ENDPT_EPSTALL_MASK                0x2u
#define USBOTG_ENDPT_EPSTALL_SHIFT               1
#define USBOTG_ENDPT_EPTXEN_MASK                 0x4u
#define USBOTG_ENDPT_EPTXEN_SHIFT                2
#define USBOTG_ENDPT_EPRXEN_MASK                 0x8u
#define USBOTG_ENDPT_EPRXEN_SHIFT                3
#define USBOTG_ENDPT_EPCTLDIS_MASK               0x10u
#define USBOTG_ENDPT_EPCTLDIS_SHIFT              4
#define USBOTG_ENDPT_RETRYDIS_MASK               0x40u
#define USBOTG_ENDPT_RETRYDIS_SHIFT              6
#define USBOTG_ENDPT_HOSTWOHUB_MASK              0x80u
#define USBOTG_ENDPT_HOSTWOHUB_SHIFT             7
/* USBCTRL Bit Fields */
#define USBOTG_USBCTRL_PDE_MASK                  0x40u
#define USBOTG_USBCTRL_PDE_SHIFT                 6
#define USBOTG_USBCTRL_SUSP_MASK                 0x80u
#define USBOTG_USBCTRL_SUSP_SHIFT                7
/* OBSERVE Bit Fields */
#define USBOTG_OBSERVE_DMPD_MASK                 0x10u
#define USBOTG_OBSERVE_DMPD_SHIFT                4
#define USBOTG_OBSERVE_DPPD_MASK                 0x40u
#define USBOTG_OBSERVE_DPPD_SHIFT                6
#define USBOTG_OBSERVE_DPPU_MASK                 0x80u
#define USBOTG_OBSERVE_DPPU_SHIFT                7
/* CONTROL Bit Fields */
#define USBOTG_CONTROL_DPPULLUPNONOTG_MASK       0x10u
#define USBOTG_CONTROL_DPPULLUPNONOTG_SHIFT      4
/* USBTRC0 Bit Fields */
#define USBOTG_USBTRC0_USB_RESUME_INT_MASK       0x1u
#define USBOTG_USBTRC0_USB_RESUME_INT_SHIFT      0
#define USBOTG_USBTRC0_SYNC_DET_MASK             0x2u
#define USBOTG_USBTRC0_SYNC_DET_SHIFT            1
#define USBOTG_USBTRC0_USBRESMEN_MASK            0x20u
#define USBOTG_USBTRC0_USBRESMEN_SHIFT           5
#define USBOTG_USBTRC0_USBRESET_MASK             0x80u
#define USBOTG_USBTRC0_USBRESET_SHIFT            7

/*! \} */ /* end of group USBOTG_Register_Masks */


/* USBOTG - Peripheral instance base addresses */
/*! Peripheral USBOTG0 base pointer */
#define USBOTG0_BASE_PTR                         ((USBOTG_MemMapPtr)0x40072000u)

/* ----------------------------------------------------------------------------
   -- USBOTG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup USBOTG_Register_Accessor_Macros USBOTG - Register accessor macros */
/*! \{ */


/* USBOTG - Register instance definitions */
/* USBOTG0 */
#define USBOTG_PERID                             USBOTG_PERID_REG(USBOTG0_BASE_PTR)
#define USBOTG_IDCOMP                            USBOTG_IDCOMP_REG(USBOTG0_BASE_PTR)
#define USBOTG_REV                               USBOTG_REV_REG(USBOTG0_BASE_PTR)
#define USBOTG_ADDINFO                           USBOTG_ADDINFO_REG(USBOTG0_BASE_PTR)
#define USBOTG_OTGISTAT                          USBOTG_OTGISTAT_REG(USBOTG0_BASE_PTR)
#define USBOTG_OTGICR                            USBOTG_OTGICR_REG(USBOTG0_BASE_PTR)
#define USBOTG_OTGSTAT                           USBOTG_OTGSTAT_REG(USBOTG0_BASE_PTR)
#define USBOTG_OTGCTL                            USBOTG_OTGCTL_REG(USBOTG0_BASE_PTR)
#define USBOTG_ISTAT                             USBOTG_ISTAT_REG(USBOTG0_BASE_PTR)
#define USBOTG_INTEN                             USBOTG_INTEN_REG(USBOTG0_BASE_PTR)
#define USBOTG_ERRSTAT                           USBOTG_ERRSTAT_REG(USBOTG0_BASE_PTR)
#define USBOTG_ERREN                             USBOTG_ERREN_REG(USBOTG0_BASE_PTR)
#define USBOTG_STAT                              USBOTG_STAT_REG(USBOTG0_BASE_PTR)
#define USBOTG_CTL                               USBOTG_CTL_REG(USBOTG0_BASE_PTR)
#define USBOTG_ADDR                              USBOTG_ADDR_REG(USBOTG0_BASE_PTR)
#define USBOTG_BDTPAGE1                          USBOTG_BDTPAGE1_REG(USBOTG0_BASE_PTR)
#define USBOTG_FRMNUML                           USBOTG_FRMNUML_REG(USBOTG0_BASE_PTR)
#define USBOTG_FRMNUMH                           USBOTG_FRMNUMH_REG(USBOTG0_BASE_PTR)
#define USBOTG_TOKEN                             USBOTG_TOKEN_REG(USBOTG0_BASE_PTR)
#define USBOTG_SOFTHLD                           USBOTG_SOFTHLD_REG(USBOTG0_BASE_PTR)
#define USBOTG_BDTPAGE2                          USBOTG_BDTPAGE2_REG(USBOTG0_BASE_PTR)
#define USBOTG_BDTPAGE3                          USBOTG_BDTPAGE3_REG(USBOTG0_BASE_PTR)
#define USBOTG_ENDPT0                            USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,0)
#define USBOTG_ENDPT1                            USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,1)
#define USBOTG_ENDPT2                            USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,2)
#define USBOTG_ENDPT3                            USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,3)
#define USBOTG_ENDPT4                            USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,4)
#define USBOTG_ENDPT5                            USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,5)
#define USBOTG_ENDPT6                            USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,6)
#define USBOTG_ENDPT7                            USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,7)
#define USBOTG_ENDPT8                            USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,8)
#define USBOTG_ENDPT9                            USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,9)
#define USBOTG_ENDPT10                           USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,10)
#define USBOTG_ENDPT11                           USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,11)
#define USBOTG_ENDPT12                           USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,12)
#define USBOTG_ENDPT13                           USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,13)
#define USBOTG_ENDPT14                           USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,14)
#define USBOTG_ENDPT15                           USBOTG_ENDPT_REG(USBOTG0_BASE_PTR,15)
#define USBOTG_USBCTRL                           USBOTG_USBCTRL_REG(USBOTG0_BASE_PTR)
#define USBOTG_OBSERVE                           USBOTG_OBSERVE_REG(USBOTG0_BASE_PTR)
#define USBOTG_CONTROL                           USBOTG_CONTROL_REG(USBOTG0_BASE_PTR)
#define USBOTG_USBTRC0                           USBOTG_USBTRC0_REG(USBOTG0_BASE_PTR)

/*! \} */ /* end of group USBOTG_Register_Accessor_Macros */


/*! \} */ /* end of group USBOTG_Peripheral */


/* ----------------------------------------------------------------------------
   -- VREF
   ---------------------------------------------------------------------------- */

/*! \addtogroup VREF_Peripheral VREF */
/*! \{ */

/*! VREF - Peripheral register structure */
typedef struct VREF_MemMap {
  uint8_t TRM;                                     /*!< VREF Trim Register, offset: 0x0 */
  uint8_t SC;                                      /*!< VREF Status and Control Register, offset: 0x1 */
} volatile *VREF_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- VREF - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup VREF_Register_Accessor_Macros VREF - Register accessor macros */
/*! \{ */


/* VREF - Register accessors */
#define VREF_TRM_REG(base)                       ((base)->TRM)
#define VREF_SC_REG(base)                        ((base)->SC)

/*! \} */ /* end of group VREF_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- VREF Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup VREF_Register_Masks VREF Register Masks */
/*! \{ */

/* TRM Bit Fields */
#define VREF_TRM_TRIM_MASK                       0x3Fu
#define VREF_TRM_TRIM_SHIFT                      0
#define VREF_TRM_TRIM(x)                         (((x)<<VREF_TRM_TRIM_SHIFT)&VREF_TRM_TRIM_MASK)
/* SC Bit Fields */
#define VREF_SC_MODE_LV_MASK                     0x3u
#define VREF_SC_MODE_LV_SHIFT                    0
#define VREF_SC_MODE_LV(x)                       (((x)<<VREF_SC_MODE_LV_SHIFT)&VREF_SC_MODE_LV_MASK)
#define VREF_SC_VREFST_MASK                      0x4u
#define VREF_SC_VREFST_SHIFT                     2
#define VREF_SC_REGEN_MASK                       0x40u
#define VREF_SC_REGEN_SHIFT                      6
#define VREF_SC_VREFEN_MASK                      0x80u
#define VREF_SC_VREFEN_SHIFT                     7

/*! \} */ /* end of group VREF_Register_Masks */


/* VREF - Peripheral instance base addresses */
/*! Peripheral VREF base pointer */
#define VREF_BASE_PTR                            ((VREF_MemMapPtr)0x40074000u)

/* ----------------------------------------------------------------------------
   -- VREF - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup VREF_Register_Accessor_Macros VREF - Register accessor macros */
/*! \{ */


/* VREF - Register instance definitions */
/* VREF */
#define VREF_TRM                                 VREF_TRM_REG(VREF_BASE_PTR)
#define VREF_SC                                  VREF_SC_REG(VREF_BASE_PTR)

/*! \} */ /* end of group VREF_Register_Accessor_Macros */


/*! \} */ /* end of group VREF_Peripheral */


/* ----------------------------------------------------------------------------
   -- WDOG
   ---------------------------------------------------------------------------- */

/*! \addtogroup WDOG_Peripheral WDOG */
/*! \{ */

/*! WDOG - Peripheral register structure */
typedef struct WDOG_MemMap {
  uint16_t STCTRLH;                                /*!< Watchdog Status and Control Register High, offset: 0x0 */
  uint16_t STCTRLL;                                /*!< Watchdog Status and Control Register Low, offset: 0x2 */
  uint16_t TOVALH;                                 /*!< Watchdog Time-out Value Register High, offset: 0x4 */
  uint16_t TOVALL;                                 /*!< Watchdog Time-out Value Register Low, offset: 0x6 */
  uint16_t WINH;                                   /*!< Watchdog Window Register High, offset: 0x8 */
  uint16_t WINL;                                   /*!< Watchdog Window Register Low, offset: 0xA */
  uint16_t REFRESH;                                /*!< Watchdog Refresh Register, offset: 0xC */
  uint16_t UNLOCK;                                 /*!< Watchdog Unlock Register, offset: 0xE */
  uint16_t TMROUTH;                                /*!< Watchdog Timer Output Register High, offset: 0x10 */
  uint16_t TMROUTL;                                /*!< Watchdog Timer Output Register Low, offset: 0x12 */
  uint16_t RSTCNT;                                 /*!< Watchdog Reset Count Register, offset: 0x14 */
  uint16_t PRESC;                                  /*!< Watchdog Prescaler Register, offset: 0x16 */
} volatile *WDOG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros */
/*! \{ */


/* WDOG - Register accessors */
#define WDOG_STCTRLH_REG(base)                   ((base)->STCTRLH)
#define WDOG_STCTRLL_REG(base)                   ((base)->STCTRLL)
#define WDOG_TOVALH_REG(base)                    ((base)->TOVALH)
#define WDOG_TOVALL_REG(base)                    ((base)->TOVALL)
#define WDOG_WINH_REG(base)                      ((base)->WINH)
#define WDOG_WINL_REG(base)                      ((base)->WINL)
#define WDOG_REFRESH_REG(base)                   ((base)->REFRESH)
#define WDOG_UNLOCK_REG(base)                    ((base)->UNLOCK)
#define WDOG_TMROUTH_REG(base)                   ((base)->TMROUTH)
#define WDOG_TMROUTL_REG(base)                   ((base)->TMROUTL)
#define WDOG_RSTCNT_REG(base)                    ((base)->RSTCNT)
#define WDOG_PRESC_REG(base)                     ((base)->PRESC)

/*! \} */ /* end of group WDOG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup WDOG_Register_Masks WDOG Register Masks */
/*! \{ */

/* STCTRLH Bit Fields */
#define WDOG_STCTRLH_WDOGEN_MASK                 0x1u
#define WDOG_STCTRLH_WDOGEN_SHIFT                0
#define WDOG_STCTRLH_CLKSRC_MASK                 0x2u
#define WDOG_STCTRLH_CLKSRC_SHIFT                1
#define WDOG_STCTRLH_IRQRSTEN_MASK               0x4u
#define WDOG_STCTRLH_IRQRSTEN_SHIFT              2
#define WDOG_STCTRLH_WINEN_MASK                  0x8u
#define WDOG_STCTRLH_WINEN_SHIFT                 3
#define WDOG_STCTRLH_ALLOWUPDATE_MASK            0x10u
#define WDOG_STCTRLH_ALLOWUPDATE_SHIFT           4
#define WDOG_STCTRLH_DBGEN_MASK                  0x20u
#define WDOG_STCTRLH_DBGEN_SHIFT                 5
#define WDOG_STCTRLH_STOPEN_MASK                 0x40u
#define WDOG_STCTRLH_STOPEN_SHIFT                6
#define WDOG_STCTRLH_WAITEN_MASK                 0x80u
#define WDOG_STCTRLH_WAITEN_SHIFT                7
#define WDOG_STCTRLH_STNDBYEN_MASK               0x100u
#define WDOG_STCTRLH_STNDBYEN_SHIFT              8
#define WDOG_STCTRLH_TESTWDOG_MASK               0x400u
#define WDOG_STCTRLH_TESTWDOG_SHIFT              10
#define WDOG_STCTRLH_TESTSEL_MASK                0x800u
#define WDOG_STCTRLH_TESTSEL_SHIFT               11
#define WDOG_STCTRLH_BYTESEL_MASK                0x3000u
#define WDOG_STCTRLH_BYTESEL_SHIFT               12
#define WDOG_STCTRLH_BYTESEL(x)                  (((x)<<WDOG_STCTRLH_BYTESEL_SHIFT)&WDOG_STCTRLH_BYTESEL_MASK)
#define WDOG_STCTRLH_DISTESTWDOG_MASK            0x4000u
#define WDOG_STCTRLH_DISTESTWDOG_SHIFT           14
/* STCTRLL Bit Fields */
#define WDOG_STCTRLL_INTFLG_MASK                 0x8000u
#define WDOG_STCTRLL_INTFLG_SHIFT                15
/* TOVALH Bit Fields */
#define WDOG_TOVALH_TOVALHIGH_MASK               0xFFFFu
#define WDOG_TOVALH_TOVALHIGH_SHIFT              0
#define WDOG_TOVALH_TOVALHIGH(x)                 (((x)<<WDOG_TOVALH_TOVALHIGH_SHIFT)&WDOG_TOVALH_TOVALHIGH_MASK)
/* TOVALL Bit Fields */
#define WDOG_TOVALL_TOVALLOW_MASK                0xFFFFu
#define WDOG_TOVALL_TOVALLOW_SHIFT               0
#define WDOG_TOVALL_TOVALLOW(x)                  (((x)<<WDOG_TOVALL_TOVALLOW_SHIFT)&WDOG_TOVALL_TOVALLOW_MASK)
/* WINH Bit Fields */
#define WDOG_WINH_WINHIGH_MASK                   0xFFFFu
#define WDOG_WINH_WINHIGH_SHIFT                  0
#define WDOG_WINH_WINHIGH(x)                     (((x)<<WDOG_WINH_WINHIGH_SHIFT)&WDOG_WINH_WINHIGH_MASK)
/* WINL Bit Fields */
#define WDOG_WINL_WINLOW_MASK                    0xFFFFu
#define WDOG_WINL_WINLOW_SHIFT                   0
#define WDOG_WINL_WINLOW(x)                      (((x)<<WDOG_WINL_WINLOW_SHIFT)&WDOG_WINL_WINLOW_MASK)
/* REFRESH Bit Fields */
#define WDOG_REFRESH_WDOGREFRESH_MASK            0xFFFFu
#define WDOG_REFRESH_WDOGREFRESH_SHIFT           0
#define WDOG_REFRESH_WDOGREFRESH(x)              (((x)<<WDOG_REFRESH_WDOGREFRESH_SHIFT)&WDOG_REFRESH_WDOGREFRESH_MASK)
/* UNLOCK Bit Fields */
#define WDOG_UNLOCK_WDOGUNLOCK_MASK              0xFFFFu
#define WDOG_UNLOCK_WDOGUNLOCK_SHIFT             0
#define WDOG_UNLOCK_WDOGUNLOCK(x)                (((x)<<WDOG_UNLOCK_WDOGUNLOCK_SHIFT)&WDOG_UNLOCK_WDOGUNLOCK_MASK)
/* TMROUTH Bit Fields */
#define WDOG_TMROUTH_TIMEROUTHIGH_MASK           0xFFFFu
#define WDOG_TMROUTH_TIMEROUTHIGH_SHIFT          0
#define WDOG_TMROUTH_TIMEROUTHIGH(x)             (((x)<<WDOG_TMROUTH_TIMEROUTHIGH_SHIFT)&WDOG_TMROUTH_TIMEROUTHIGH_MASK)
/* TMROUTL Bit Fields */
#define WDOG_TMROUTL_TIMEROUTLOW_MASK            0xFFFFu
#define WDOG_TMROUTL_TIMEROUTLOW_SHIFT           0
#define WDOG_TMROUTL_TIMEROUTLOW(x)              (((x)<<WDOG_TMROUTL_TIMEROUTLOW_SHIFT)&WDOG_TMROUTL_TIMEROUTLOW_MASK)
/* RSTCNT Bit Fields */
#define WDOG_RSTCNT_RSTCNT_MASK                  0xFFFFu
#define WDOG_RSTCNT_RSTCNT_SHIFT                 0
#define WDOG_RSTCNT_RSTCNT(x)                    (((x)<<WDOG_RSTCNT_RSTCNT_SHIFT)&WDOG_RSTCNT_RSTCNT_MASK)
/* PRESC Bit Fields */
#define WDOG_PRESC_PRESCVAL_MASK                 0x700u
#define WDOG_PRESC_PRESCVAL_SHIFT                8
#define WDOG_PRESC_PRESCVAL(x)                   (((x)<<WDOG_PRESC_PRESCVAL_SHIFT)&WDOG_PRESC_PRESCVAL_MASK)

/*! \} */ /* end of group WDOG_Register_Masks */


/* WDOG - Peripheral instance base addresses */
/*! Peripheral WDOG base pointer */
#define WDOG_BASE_PTR                            ((WDOG_MemMapPtr)0x40052000u)

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros */
/*! \{ */


/* WDOG - Register instance definitions */
/* WDOG */
#define WDOG_STCTRLH                             WDOG_STCTRLH_REG(WDOG_BASE_PTR)
#define WDOG_STCTRLL                             WDOG_STCTRLL_REG(WDOG_BASE_PTR)
#define WDOG_TOVALH                              WDOG_TOVALH_REG(WDOG_BASE_PTR)
#define WDOG_TOVALL                              WDOG_TOVALL_REG(WDOG_BASE_PTR)
#define WDOG_WINH                                WDOG_WINH_REG(WDOG_BASE_PTR)
#define WDOG_WINL                                WDOG_WINL_REG(WDOG_BASE_PTR)
#define WDOG_REFRESH                             WDOG_REFRESH_REG(WDOG_BASE_PTR)
#define WDOG_UNLOCK                              WDOG_UNLOCK_REG(WDOG_BASE_PTR)
#define WDOG_TMROUTH                             WDOG_TMROUTH_REG(WDOG_BASE_PTR)
#define WDOG_TMROUTL                             WDOG_TMROUTL_REG(WDOG_BASE_PTR)
#define WDOG_RSTCNT                              WDOG_RSTCNT_REG(WDOG_BASE_PTR)
#define WDOG_PRESC                               WDOG_PRESC_REG(WDOG_BASE_PTR)

/*! \} */ /* end of group WDOG_Register_Accessor_Macros */


/*! \} */ /* end of group WDOG_Peripheral */


/* ----------------------------------------------------------------------------
   -- DMA
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMA_Peripheral DMA */
/*! \{ */

/*! DMA - Peripheral register structure */
typedef struct DMA_MemMap {
  uint32_t CR;                                     /*!< Control Register, offset: 0x0 */
  uint32_t ES;                                     /*!< Error Status Register, offset: 0x4 */
  uint8_t RESERVED_0[4];
  uint32_t ERQ;                                    /*!< Enable Request Register, offset: 0xC */
  uint8_t RESERVED_1[4];
  uint32_t EEI;                                    /*!< Enable Error Interrupt Register, offset: 0x14 */
  uint8_t CEEI;                                    /*!< Clear Enable Error Interrupt Register, offset: 0x18 */
  uint8_t SEEI;                                    /*!< Set Enable Error Interrupt Register, offset: 0x19 */
  uint8_t CERQ;                                    /*!< Clear Enable Request Register, offset: 0x1A */
  uint8_t SERQ;                                    /*!< Set Enable Request Register, offset: 0x1B */
  uint8_t CDNE;                                    /*!< Clear DONE Status Bit Register, offset: 0x1C */
  uint8_t SSRT;                                    /*!< Set START Bit Register, offset: 0x1D */
  uint8_t CERR;                                    /*!< Clear Error Register, offset: 0x1E */
  uint8_t CINT;                                    /*!< Clear Interrupt Request Register, offset: 0x1F */
  uint8_t RESERVED_2[4];
  uint32_t INT;                                    /*!< Interrupt Request Register, offset: 0x24 */
  uint8_t RESERVED_3[4];
  uint32_t ERR;                                    /*!< Error Register, offset: 0x2C */
  uint8_t RESERVED_4[4];
  uint32_t HRS;                                    /*!< Hardware Request Status Register, offset: 0x34 */
  uint8_t RESERVED_5[200];
  uint8_t DCHPRI3;                                 /*!< Channel n Priority Register, offset: 0x100 */
  uint8_t DCHPRI2;                                 /*!< Channel n Priority Register, offset: 0x101 */
  uint8_t DCHPRI1;                                 /*!< Channel n Priority Register, offset: 0x102 */
  uint8_t DCHPRI0;                                 /*!< Channel n Priority Register, offset: 0x103 */
  uint8_t DCHPRI7;                                 /*!< Channel n Priority Register, offset: 0x104 */
  uint8_t DCHPRI6;                                 /*!< Channel n Priority Register, offset: 0x105 */
  uint8_t DCHPRI5;                                 /*!< Channel n Priority Register, offset: 0x106 */
  uint8_t DCHPRI4;                                 /*!< Channel n Priority Register, offset: 0x107 */
  uint8_t DCHPRI11;                                /*!< Channel n Priority Register, offset: 0x108 */
  uint8_t DCHPRI10;                                /*!< Channel n Priority Register, offset: 0x109 */
  uint8_t DCHPRI9;                                 /*!< Channel n Priority Register, offset: 0x10A */
  uint8_t DCHPRI8;                                 /*!< Channel n Priority Register, offset: 0x10B */
  uint8_t DCHPRI15;                                /*!< Channel n Priority Register, offset: 0x10C */
  uint8_t DCHPRI14;                                /*!< Channel n Priority Register, offset: 0x10D */
  uint8_t DCHPRI13;                                /*!< Channel n Priority Register, offset: 0x10E */
  uint8_t DCHPRI12;                                /*!< Channel n Priority Register, offset: 0x10F */
  uint8_t RESERVED_6[3824];
  struct {                                         /* offset: 0x1000, array step: 0x20 */
    uint32_t SADDR;                                  /*!< TCD Source Address, array offset: 0x1000, array step: 0x20 */
    uint16_t SOFF;                                   /*!< TCD Signed Source Address Offset, array offset: 0x1004, array step: 0x20 */
    uint16_t ATTR;                                   /*!< TCD Transfer Attributes, array offset: 0x1006, array step: 0x20 */
    union {                                          /* offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLNO;                            /*!< TCD Minor Byte Count (Minor Loop Disabled), array offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLOFFNO;                         /*!< TCD Signed Minor Loop Offset (Minor Loop Enabled and Offset Disabled), array offset: 0x1008, array step: 0x20 */
      uint32_t NBYTES_MLOFFYES;                        /*!< TCD Signed Minor Loop Offset (Minor Loop and Offset Enabled), array offset: 0x1008, array step: 0x20 */
    };
    uint32_t SLAST;                                  /*!< TCD Last Source Address Adjustment, array offset: 0x100C, array step: 0x20 */
    uint32_t DADDR;                                  /*!< TCD Destination Address, array offset: 0x1010, array step: 0x20 */
    uint16_t DOFF;                                   /*!< TCD Signed Destination Address Offset, array offset: 0x1014, array step: 0x20 */
    union {                                          /* offset: 0x1016, array step: 0x20 */
      uint16_t CITER_ELINKYES;                         /*!< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x1016, array step: 0x20 */
      uint16_t CITER_ELINKNO;                          /*!< TCD Current Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x1016, array step: 0x20 */
    };
    uint32_t DLAST_SGA;                              /*!< TCD Last Destination Address Adjustment/Scatter Gather Address, array offset: 0x1018, array step: 0x20 */
    uint16_t CSR;                                    /*!< TCD Control and Status, array offset: 0x101C, array step: 0x20 */
    union {                                          /* offset: 0x101E, array step: 0x20 */
      uint16_t BITER_ELINKNO;                          /*!< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Disabled), array offset: 0x101E, array step: 0x20 */
      uint16_t BITER_ELINKYES;                         /*!< TCD Beginning Minor Loop Link, Major Loop Count (Channel Linking Enabled), array offset: 0x101E, array step: 0x20 */
    };
  } TCD[16];
} volatile *DMA_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros */
/*! \{ */


/* DMA - Register accessors */
#define DMA_CR_REG(base)                         ((base)->CR)
#define DMA_ES_REG(base)                         ((base)->ES)
#define DMA_ERQ_REG(base)                        ((base)->ERQ)
#define DMA_EEI_REG(base)                        ((base)->EEI)
#define DMA_CEEI_REG(base)                       ((base)->CEEI)
#define DMA_SEEI_REG(base)                       ((base)->SEEI)
#define DMA_CERQ_REG(base)                       ((base)->CERQ)
#define DMA_SERQ_REG(base)                       ((base)->SERQ)
#define DMA_CDNE_REG(base)                       ((base)->CDNE)
#define DMA_SSRT_REG(base)                       ((base)->SSRT)
#define DMA_CERR_REG(base)                       ((base)->CERR)
#define DMA_CINT_REG(base)                       ((base)->CINT)
#define DMA_INT_REG(base)                        ((base)->INT)
#define DMA_ERR_REG(base)                        ((base)->ERR)
#define DMA_HRS_REG(base)                        ((base)->HRS)
#define DMA_DCHPRI3_REG(base)                    ((base)->DCHPRI3)
#define DMA_DCHPRI2_REG(base)                    ((base)->DCHPRI2)
#define DMA_DCHPRI1_REG(base)                    ((base)->DCHPRI1)
#define DMA_DCHPRI0_REG(base)                    ((base)->DCHPRI0)
#define DMA_DCHPRI7_REG(base)                    ((base)->DCHPRI7)
#define DMA_DCHPRI6_REG(base)                    ((base)->DCHPRI6)
#define DMA_DCHPRI5_REG(base)                    ((base)->DCHPRI5)
#define DMA_DCHPRI4_REG(base)                    ((base)->DCHPRI4)
#define DMA_DCHPRI11_REG(base)                   ((base)->DCHPRI11)
#define DMA_DCHPRI10_REG(base)                   ((base)->DCHPRI10)
#define DMA_DCHPRI9_REG(base)                    ((base)->DCHPRI9)
#define DMA_DCHPRI8_REG(base)                    ((base)->DCHPRI8)
#define DMA_DCHPRI15_REG(base)                   ((base)->DCHPRI15)
#define DMA_DCHPRI14_REG(base)                   ((base)->DCHPRI14)
#define DMA_DCHPRI13_REG(base)                   ((base)->DCHPRI13)
#define DMA_DCHPRI12_REG(base)                   ((base)->DCHPRI12)
#define DMA_SADDR_REG(base,index)                ((base)->TCD[index].SADDR)
#define DMA_SOFF_REG(base,index)                 ((base)->TCD[index].SOFF)
#define DMA_ATTR_REG(base,index)                 ((base)->TCD[index].ATTR)
#define DMA_NBYTES_MLNO_REG(base,index)          ((base)->TCD[index].NBYTES_MLNO)
#define DMA_NBYTES_MLOFFNO_REG(base,index)       ((base)->TCD[index].NBYTES_MLOFFNO)
#define DMA_NBYTES_MLOFFYES_REG(base,index)      ((base)->TCD[index].NBYTES_MLOFFYES)
#define DMA_SLAST_REG(base,index)                ((base)->TCD[index].SLAST)
#define DMA_DADDR_REG(base,index)                ((base)->TCD[index].DADDR)
#define DMA_DOFF_REG(base,index)                 ((base)->TCD[index].DOFF)
#define DMA_CITER_ELINKYES_REG(base,index)       ((base)->TCD[index].CITER_ELINKYES)
#define DMA_CITER_ELINKNO_REG(base,index)        ((base)->TCD[index].CITER_ELINKNO)
#define DMA_DLAST_SGA_REG(base,index)            ((base)->TCD[index].DLAST_SGA)
#define DMA_CSR_REG(base,index)                  ((base)->TCD[index].CSR)
#define DMA_BITER_ELINKNO_REG(base,index)        ((base)->TCD[index].BITER_ELINKNO)
#define DMA_BITER_ELINKYES_REG(base,index)       ((base)->TCD[index].BITER_ELINKYES)

/*! \} */ /* end of group DMA_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMA_Register_Masks DMA Register Masks */
/*! \{ */

/* CR Bit Fields */
#define DMA_CR_EDBG_MASK                         0x2u
#define DMA_CR_EDBG_SHIFT                        1
#define DMA_CR_ERCA_MASK                         0x4u
#define DMA_CR_ERCA_SHIFT                        2
#define DMA_CR_HOE_MASK                          0x10u
#define DMA_CR_HOE_SHIFT                         4
#define DMA_CR_HALT_MASK                         0x20u
#define DMA_CR_HALT_SHIFT                        5
#define DMA_CR_CLM_MASK                          0x40u
#define DMA_CR_CLM_SHIFT                         6
#define DMA_CR_EMLM_MASK                         0x80u
#define DMA_CR_EMLM_SHIFT                        7
#define DMA_CR_ECX_MASK                          0x10000u
#define DMA_CR_ECX_SHIFT                         16
#define DMA_CR_CX_MASK                           0x20000u
#define DMA_CR_CX_SHIFT                          17
/* ES Bit Fields */
#define DMA_ES_DBE_MASK                          0x1u
#define DMA_ES_DBE_SHIFT                         0
#define DMA_ES_SBE_MASK                          0x2u
#define DMA_ES_SBE_SHIFT                         1
#define DMA_ES_SGE_MASK                          0x4u
#define DMA_ES_SGE_SHIFT                         2
#define DMA_ES_NCE_MASK                          0x8u
#define DMA_ES_NCE_SHIFT                         3
#define DMA_ES_DOE_MASK                          0x10u
#define DMA_ES_DOE_SHIFT                         4
#define DMA_ES_DAE_MASK                          0x20u
#define DMA_ES_DAE_SHIFT                         5
#define DMA_ES_SOE_MASK                          0x40u
#define DMA_ES_SOE_SHIFT                         6
#define DMA_ES_SAE_MASK                          0x80u
#define DMA_ES_SAE_SHIFT                         7
#define DMA_ES_ERRCHN_MASK                       0xF00u
#define DMA_ES_ERRCHN_SHIFT                      8
#define DMA_ES_ERRCHN(x)                         (((x)<<DMA_ES_ERRCHN_SHIFT)&DMA_ES_ERRCHN_MASK)
#define DMA_ES_CPE_MASK                          0x4000u
#define DMA_ES_CPE_SHIFT                         14
#define DMA_ES_ECX_MASK                          0x10000u
#define DMA_ES_ECX_SHIFT                         16
#define DMA_ES_VLD_MASK                          0x80000000u
#define DMA_ES_VLD_SHIFT                         31
/* ERQ Bit Fields */
#define DMA_ERQ_ERQ0_MASK                        0x1u
#define DMA_ERQ_ERQ0_SHIFT                       0
#define DMA_ERQ_ERQ1_MASK                        0x2u
#define DMA_ERQ_ERQ1_SHIFT                       1
#define DMA_ERQ_ERQ2_MASK                        0x4u
#define DMA_ERQ_ERQ2_SHIFT                       2
#define DMA_ERQ_ERQ3_MASK                        0x8u
#define DMA_ERQ_ERQ3_SHIFT                       3
#define DMA_ERQ_ERQ4_MASK                        0x10u
#define DMA_ERQ_ERQ4_SHIFT                       4
#define DMA_ERQ_ERQ5_MASK                        0x20u
#define DMA_ERQ_ERQ5_SHIFT                       5
#define DMA_ERQ_ERQ6_MASK                        0x40u
#define DMA_ERQ_ERQ6_SHIFT                       6
#define DMA_ERQ_ERQ7_MASK                        0x80u
#define DMA_ERQ_ERQ7_SHIFT                       7
#define DMA_ERQ_ERQ8_MASK                        0x100u
#define DMA_ERQ_ERQ8_SHIFT                       8
#define DMA_ERQ_ERQ9_MASK                        0x200u
#define DMA_ERQ_ERQ9_SHIFT                       9
#define DMA_ERQ_ERQ10_MASK                       0x400u
#define DMA_ERQ_ERQ10_SHIFT                      10
#define DMA_ERQ_ERQ11_MASK                       0x800u
#define DMA_ERQ_ERQ11_SHIFT                      11
#define DMA_ERQ_ERQ12_MASK                       0x1000u
#define DMA_ERQ_ERQ12_SHIFT                      12
#define DMA_ERQ_ERQ13_MASK                       0x2000u
#define DMA_ERQ_ERQ13_SHIFT                      13
#define DMA_ERQ_ERQ14_MASK                       0x4000u
#define DMA_ERQ_ERQ14_SHIFT                      14
#define DMA_ERQ_ERQ15_MASK                       0x8000u
#define DMA_ERQ_ERQ15_SHIFT                      15
/* EEI Bit Fields */
#define DMA_EEI_EEI0_MASK                        0x1u
#define DMA_EEI_EEI0_SHIFT                       0
#define DMA_EEI_EEI1_MASK                        0x2u
#define DMA_EEI_EEI1_SHIFT                       1
#define DMA_EEI_EEI2_MASK                        0x4u
#define DMA_EEI_EEI2_SHIFT                       2
#define DMA_EEI_EEI3_MASK                        0x8u
#define DMA_EEI_EEI3_SHIFT                       3
#define DMA_EEI_EEI4_MASK                        0x10u
#define DMA_EEI_EEI4_SHIFT                       4
#define DMA_EEI_EEI5_MASK                        0x20u
#define DMA_EEI_EEI5_SHIFT                       5
#define DMA_EEI_EEI6_MASK                        0x40u
#define DMA_EEI_EEI6_SHIFT                       6
#define DMA_EEI_EEI7_MASK                        0x80u
#define DMA_EEI_EEI7_SHIFT                       7
#define DMA_EEI_EEI8_MASK                        0x100u
#define DMA_EEI_EEI8_SHIFT                       8
#define DMA_EEI_EEI9_MASK                        0x200u
#define DMA_EEI_EEI9_SHIFT                       9
#define DMA_EEI_EEI10_MASK                       0x400u
#define DMA_EEI_EEI10_SHIFT                      10
#define DMA_EEI_EEI11_MASK                       0x800u
#define DMA_EEI_EEI11_SHIFT                      11
#define DMA_EEI_EEI12_MASK                       0x1000u
#define DMA_EEI_EEI12_SHIFT                      12
#define DMA_EEI_EEI13_MASK                       0x2000u
#define DMA_EEI_EEI13_SHIFT                      13
#define DMA_EEI_EEI14_MASK                       0x4000u
#define DMA_EEI_EEI14_SHIFT                      14
#define DMA_EEI_EEI15_MASK                       0x8000u
#define DMA_EEI_EEI15_SHIFT                      15
/* CEEI Bit Fields */
#define DMA_CEEI_CEEI_MASK                       0xFu
#define DMA_CEEI_CEEI_SHIFT                      0
#define DMA_CEEI_CEEI(x)                         (((x)<<DMA_CEEI_CEEI_SHIFT)&DMA_CEEI_CEEI_MASK)
#define DMA_CEEI_CAEE_MASK                       0x40u
#define DMA_CEEI_CAEE_SHIFT                      6
#define DMA_CEEI_NOP_MASK                        0x80u
#define DMA_CEEI_NOP_SHIFT                       7
/* SEEI Bit Fields */
#define DMA_SEEI_SEEI_MASK                       0xFu
#define DMA_SEEI_SEEI_SHIFT                      0
#define DMA_SEEI_SEEI(x)                         (((x)<<DMA_SEEI_SEEI_SHIFT)&DMA_SEEI_SEEI_MASK)
#define DMA_SEEI_SAEE_MASK                       0x40u
#define DMA_SEEI_SAEE_SHIFT                      6
#define DMA_SEEI_NOP_MASK                        0x80u
#define DMA_SEEI_NOP_SHIFT                       7
/* CERQ Bit Fields */
#define DMA_CERQ_CERQ_MASK                       0xFu
#define DMA_CERQ_CERQ_SHIFT                      0
#define DMA_CERQ_CERQ(x)                         (((x)<<DMA_CERQ_CERQ_SHIFT)&DMA_CERQ_CERQ_MASK)
#define DMA_CERQ_CAER_MASK                       0x40u
#define DMA_CERQ_CAER_SHIFT                      6
#define DMA_CERQ_NOP_MASK                        0x80u
#define DMA_CERQ_NOP_SHIFT                       7
/* SERQ Bit Fields */
#define DMA_SERQ_SERQ_MASK                       0xFu
#define DMA_SERQ_SERQ_SHIFT                      0
#define DMA_SERQ_SERQ(x)                         (((x)<<DMA_SERQ_SERQ_SHIFT)&DMA_SERQ_SERQ_MASK)
#define DMA_SERQ_SAER_MASK                       0x40u
#define DMA_SERQ_SAER_SHIFT                      6
#define DMA_SERQ_NOP_MASK                        0x80u
#define DMA_SERQ_NOP_SHIFT                       7
/* CDNE Bit Fields */
#define DMA_CDNE_CDNE_MASK                       0xFu
#define DMA_CDNE_CDNE_SHIFT                      0
#define DMA_CDNE_CDNE(x)                         (((x)<<DMA_CDNE_CDNE_SHIFT)&DMA_CDNE_CDNE_MASK)
#define DMA_CDNE_CADN_MASK                       0x40u
#define DMA_CDNE_CADN_SHIFT                      6
#define DMA_CDNE_NOP_MASK                        0x80u
#define DMA_CDNE_NOP_SHIFT                       7
/* SSRT Bit Fields */
#define DMA_SSRT_SSRT_MASK                       0xFu
#define DMA_SSRT_SSRT_SHIFT                      0
#define DMA_SSRT_SSRT(x)                         (((x)<<DMA_SSRT_SSRT_SHIFT)&DMA_SSRT_SSRT_MASK)
#define DMA_SSRT_SAST_MASK                       0x40u
#define DMA_SSRT_SAST_SHIFT                      6
#define DMA_SSRT_NOP_MASK                        0x80u
#define DMA_SSRT_NOP_SHIFT                       7
/* CERR Bit Fields */
#define DMA_CERR_CERR_MASK                       0xFu
#define DMA_CERR_CERR_SHIFT                      0
#define DMA_CERR_CERR(x)                         (((x)<<DMA_CERR_CERR_SHIFT)&DMA_CERR_CERR_MASK)
#define DMA_CERR_CAEI_MASK                       0x40u
#define DMA_CERR_CAEI_SHIFT                      6
#define DMA_CERR_NOP_MASK                        0x80u
#define DMA_CERR_NOP_SHIFT                       7
/* CINT Bit Fields */
#define DMA_CINT_CINT_MASK                       0xFu
#define DMA_CINT_CINT_SHIFT                      0
#define DMA_CINT_CINT(x)                         (((x)<<DMA_CINT_CINT_SHIFT)&DMA_CINT_CINT_MASK)
#define DMA_CINT_CAIR_MASK                       0x40u
#define DMA_CINT_CAIR_SHIFT                      6
#define DMA_CINT_NOP_MASK                        0x80u
#define DMA_CINT_NOP_SHIFT                       7
/* INT Bit Fields */
#define DMA_INT_INT0_MASK                        0x1u
#define DMA_INT_INT0_SHIFT                       0
#define DMA_INT_INT1_MASK                        0x2u
#define DMA_INT_INT1_SHIFT                       1
#define DMA_INT_INT2_MASK                        0x4u
#define DMA_INT_INT2_SHIFT                       2
#define DMA_INT_INT3_MASK                        0x8u
#define DMA_INT_INT3_SHIFT                       3
#define DMA_INT_INT4_MASK                        0x10u
#define DMA_INT_INT4_SHIFT                       4
#define DMA_INT_INT5_MASK                        0x20u
#define DMA_INT_INT5_SHIFT                       5
#define DMA_INT_INT6_MASK                        0x40u
#define DMA_INT_INT6_SHIFT                       6
#define DMA_INT_INT7_MASK                        0x80u
#define DMA_INT_INT7_SHIFT                       7
#define DMA_INT_INT8_MASK                        0x100u
#define DMA_INT_INT8_SHIFT                       8
#define DMA_INT_INT9_MASK                        0x200u
#define DMA_INT_INT9_SHIFT                       9
#define DMA_INT_INT10_MASK                       0x400u
#define DMA_INT_INT10_SHIFT                      10
#define DMA_INT_INT11_MASK                       0x800u
#define DMA_INT_INT11_SHIFT                      11
#define DMA_INT_INT12_MASK                       0x1000u
#define DMA_INT_INT12_SHIFT                      12
#define DMA_INT_INT13_MASK                       0x2000u
#define DMA_INT_INT13_SHIFT                      13
#define DMA_INT_INT14_MASK                       0x4000u
#define DMA_INT_INT14_SHIFT                      14
#define DMA_INT_INT15_MASK                       0x8000u
#define DMA_INT_INT15_SHIFT                      15
/* ERR Bit Fields */
#define DMA_ERR_ERR0_MASK                        0x1u
#define DMA_ERR_ERR0_SHIFT                       0
#define DMA_ERR_ERR1_MASK                        0x2u
#define DMA_ERR_ERR1_SHIFT                       1
#define DMA_ERR_ERR2_MASK                        0x4u
#define DMA_ERR_ERR2_SHIFT                       2
#define DMA_ERR_ERR3_MASK                        0x8u
#define DMA_ERR_ERR3_SHIFT                       3
#define DMA_ERR_ERR4_MASK                        0x10u
#define DMA_ERR_ERR4_SHIFT                       4
#define DMA_ERR_ERR5_MASK                        0x20u
#define DMA_ERR_ERR5_SHIFT                       5
#define DMA_ERR_ERR6_MASK                        0x40u
#define DMA_ERR_ERR6_SHIFT                       6
#define DMA_ERR_ERR7_MASK                        0x80u
#define DMA_ERR_ERR7_SHIFT                       7
#define DMA_ERR_ERR8_MASK                        0x100u
#define DMA_ERR_ERR8_SHIFT                       8
#define DMA_ERR_ERR9_MASK                        0x200u
#define DMA_ERR_ERR9_SHIFT                       9
#define DMA_ERR_ERR10_MASK                       0x400u
#define DMA_ERR_ERR10_SHIFT                      10
#define DMA_ERR_ERR11_MASK                       0x800u
#define DMA_ERR_ERR11_SHIFT                      11
#define DMA_ERR_ERR12_MASK                       0x1000u
#define DMA_ERR_ERR12_SHIFT                      12
#define DMA_ERR_ERR13_MASK                       0x2000u
#define DMA_ERR_ERR13_SHIFT                      13
#define DMA_ERR_ERR14_MASK                       0x4000u
#define DMA_ERR_ERR14_SHIFT                      14
#define DMA_ERR_ERR15_MASK                       0x8000u
#define DMA_ERR_ERR15_SHIFT                      15
/* HRS Bit Fields */
#define DMA_HRS_HRS0_MASK                        0x1u
#define DMA_HRS_HRS0_SHIFT                       0
#define DMA_HRS_HRS1_MASK                        0x2u
#define DMA_HRS_HRS1_SHIFT                       1
#define DMA_HRS_HRS2_MASK                        0x4u
#define DMA_HRS_HRS2_SHIFT                       2
#define DMA_HRS_HRS3_MASK                        0x8u
#define DMA_HRS_HRS3_SHIFT                       3
#define DMA_HRS_HRS4_MASK                        0x10u
#define DMA_HRS_HRS4_SHIFT                       4
#define DMA_HRS_HRS5_MASK                        0x20u
#define DMA_HRS_HRS5_SHIFT                       5
#define DMA_HRS_HRS6_MASK                        0x40u
#define DMA_HRS_HRS6_SHIFT                       6
#define DMA_HRS_HRS7_MASK                        0x80u
#define DMA_HRS_HRS7_SHIFT                       7
#define DMA_HRS_HRS8_MASK                        0x100u
#define DMA_HRS_HRS8_SHIFT                       8
#define DMA_HRS_HRS9_MASK                        0x200u
#define DMA_HRS_HRS9_SHIFT                       9
#define DMA_HRS_HRS10_MASK                       0x400u
#define DMA_HRS_HRS10_SHIFT                      10
#define DMA_HRS_HRS11_MASK                       0x800u
#define DMA_HRS_HRS11_SHIFT                      11
#define DMA_HRS_HRS12_MASK                       0x1000u
#define DMA_HRS_HRS12_SHIFT                      12
#define DMA_HRS_HRS13_MASK                       0x2000u
#define DMA_HRS_HRS13_SHIFT                      13
#define DMA_HRS_HRS14_MASK                       0x4000u
#define DMA_HRS_HRS14_SHIFT                      14
#define DMA_HRS_HRS15_MASK                       0x8000u
#define DMA_HRS_HRS15_SHIFT                      15
/* DCHPRI3 Bit Fields */
#define DMA_DCHPRI3_CHPRI_MASK                   0xFu
#define DMA_DCHPRI3_CHPRI_SHIFT                  0
#define DMA_DCHPRI3_CHPRI(x)                     (((x)<<DMA_DCHPRI3_CHPRI_SHIFT)&DMA_DCHPRI3_CHPRI_MASK)
#define DMA_DCHPRI3_DPA_MASK                     0x40u
#define DMA_DCHPRI3_DPA_SHIFT                    6
#define DMA_DCHPRI3_ECP_MASK                     0x80u
#define DMA_DCHPRI3_ECP_SHIFT                    7
/* DCHPRI2 Bit Fields */
#define DMA_DCHPRI2_CHPRI_MASK                   0xFu
#define DMA_DCHPRI2_CHPRI_SHIFT                  0
#define DMA_DCHPRI2_CHPRI(x)                     (((x)<<DMA_DCHPRI2_CHPRI_SHIFT)&DMA_DCHPRI2_CHPRI_MASK)
#define DMA_DCHPRI2_DPA_MASK                     0x40u
#define DMA_DCHPRI2_DPA_SHIFT                    6
#define DMA_DCHPRI2_ECP_MASK                     0x80u
#define DMA_DCHPRI2_ECP_SHIFT                    7
/* DCHPRI1 Bit Fields */
#define DMA_DCHPRI1_CHPRI_MASK                   0xFu
#define DMA_DCHPRI1_CHPRI_SHIFT                  0
#define DMA_DCHPRI1_CHPRI(x)                     (((x)<<DMA_DCHPRI1_CHPRI_SHIFT)&DMA_DCHPRI1_CHPRI_MASK)
#define DMA_DCHPRI1_DPA_MASK                     0x40u
#define DMA_DCHPRI1_DPA_SHIFT                    6
#define DMA_DCHPRI1_ECP_MASK                     0x80u
#define DMA_DCHPRI1_ECP_SHIFT                    7
/* DCHPRI0 Bit Fields */
#define DMA_DCHPRI0_CHPRI_MASK                   0xFu
#define DMA_DCHPRI0_CHPRI_SHIFT                  0
#define DMA_DCHPRI0_CHPRI(x)                     (((x)<<DMA_DCHPRI0_CHPRI_SHIFT)&DMA_DCHPRI0_CHPRI_MASK)
#define DMA_DCHPRI0_DPA_MASK                     0x40u
#define DMA_DCHPRI0_DPA_SHIFT                    6
#define DMA_DCHPRI0_ECP_MASK                     0x80u
#define DMA_DCHPRI0_ECP_SHIFT                    7
/* DCHPRI7 Bit Fields */
#define DMA_DCHPRI7_CHPRI_MASK                   0xFu
#define DMA_DCHPRI7_CHPRI_SHIFT                  0
#define DMA_DCHPRI7_CHPRI(x)                     (((x)<<DMA_DCHPRI7_CHPRI_SHIFT)&DMA_DCHPRI7_CHPRI_MASK)
#define DMA_DCHPRI7_DPA_MASK                     0x40u
#define DMA_DCHPRI7_DPA_SHIFT                    6
#define DMA_DCHPRI7_ECP_MASK                     0x80u
#define DMA_DCHPRI7_ECP_SHIFT                    7
/* DCHPRI6 Bit Fields */
#define DMA_DCHPRI6_CHPRI_MASK                   0xFu
#define DMA_DCHPRI6_CHPRI_SHIFT                  0
#define DMA_DCHPRI6_CHPRI(x)                     (((x)<<DMA_DCHPRI6_CHPRI_SHIFT)&DMA_DCHPRI6_CHPRI_MASK)
#define DMA_DCHPRI6_DPA_MASK                     0x40u
#define DMA_DCHPRI6_DPA_SHIFT                    6
#define DMA_DCHPRI6_ECP_MASK                     0x80u
#define DMA_DCHPRI6_ECP_SHIFT                    7
/* DCHPRI5 Bit Fields */
#define DMA_DCHPRI5_CHPRI_MASK                   0xFu
#define DMA_DCHPRI5_CHPRI_SHIFT                  0
#define DMA_DCHPRI5_CHPRI(x)                     (((x)<<DMA_DCHPRI5_CHPRI_SHIFT)&DMA_DCHPRI5_CHPRI_MASK)
#define DMA_DCHPRI5_DPA_MASK                     0x40u
#define DMA_DCHPRI5_DPA_SHIFT                    6
#define DMA_DCHPRI5_ECP_MASK                     0x80u
#define DMA_DCHPRI5_ECP_SHIFT                    7
/* DCHPRI4 Bit Fields */
#define DMA_DCHPRI4_CHPRI_MASK                   0xFu
#define DMA_DCHPRI4_CHPRI_SHIFT                  0
#define DMA_DCHPRI4_CHPRI(x)                     (((x)<<DMA_DCHPRI4_CHPRI_SHIFT)&DMA_DCHPRI4_CHPRI_MASK)
#define DMA_DCHPRI4_DPA_MASK                     0x40u
#define DMA_DCHPRI4_DPA_SHIFT                    6
#define DMA_DCHPRI4_ECP_MASK                     0x80u
#define DMA_DCHPRI4_ECP_SHIFT                    7
/* DCHPRI11 Bit Fields */
#define DMA_DCHPRI11_CHPRI_MASK                  0xFu
#define DMA_DCHPRI11_CHPRI_SHIFT                 0
#define DMA_DCHPRI11_CHPRI(x)                    (((x)<<DMA_DCHPRI11_CHPRI_SHIFT)&DMA_DCHPRI11_CHPRI_MASK)
#define DMA_DCHPRI11_DPA_MASK                    0x40u
#define DMA_DCHPRI11_DPA_SHIFT                   6
#define DMA_DCHPRI11_ECP_MASK                    0x80u
#define DMA_DCHPRI11_ECP_SHIFT                   7
/* DCHPRI10 Bit Fields */
#define DMA_DCHPRI10_CHPRI_MASK                  0xFu
#define DMA_DCHPRI10_CHPRI_SHIFT                 0
#define DMA_DCHPRI10_CHPRI(x)                    (((x)<<DMA_DCHPRI10_CHPRI_SHIFT)&DMA_DCHPRI10_CHPRI_MASK)
#define DMA_DCHPRI10_DPA_MASK                    0x40u
#define DMA_DCHPRI10_DPA_SHIFT                   6
#define DMA_DCHPRI10_ECP_MASK                    0x80u
#define DMA_DCHPRI10_ECP_SHIFT                   7
/* DCHPRI9 Bit Fields */
#define DMA_DCHPRI9_CHPRI_MASK                   0xFu
#define DMA_DCHPRI9_CHPRI_SHIFT                  0
#define DMA_DCHPRI9_CHPRI(x)                     (((x)<<DMA_DCHPRI9_CHPRI_SHIFT)&DMA_DCHPRI9_CHPRI_MASK)
#define DMA_DCHPRI9_DPA_MASK                     0x40u
#define DMA_DCHPRI9_DPA_SHIFT                    6
#define DMA_DCHPRI9_ECP_MASK                     0x80u
#define DMA_DCHPRI9_ECP_SHIFT                    7
/* DCHPRI8 Bit Fields */
#define DMA_DCHPRI8_CHPRI_MASK                   0xFu
#define DMA_DCHPRI8_CHPRI_SHIFT                  0
#define DMA_DCHPRI8_CHPRI(x)                     (((x)<<DMA_DCHPRI8_CHPRI_SHIFT)&DMA_DCHPRI8_CHPRI_MASK)
#define DMA_DCHPRI8_DPA_MASK                     0x40u
#define DMA_DCHPRI8_DPA_SHIFT                    6
#define DMA_DCHPRI8_ECP_MASK                     0x80u
#define DMA_DCHPRI8_ECP_SHIFT                    7
/* DCHPRI15 Bit Fields */
#define DMA_DCHPRI15_CHPRI_MASK                  0xFu
#define DMA_DCHPRI15_CHPRI_SHIFT                 0
#define DMA_DCHPRI15_CHPRI(x)                    (((x)<<DMA_DCHPRI15_CHPRI_SHIFT)&DMA_DCHPRI15_CHPRI_MASK)
#define DMA_DCHPRI15_DPA_MASK                    0x40u
#define DMA_DCHPRI15_DPA_SHIFT                   6
#define DMA_DCHPRI15_ECP_MASK                    0x80u
#define DMA_DCHPRI15_ECP_SHIFT                   7
/* DCHPRI14 Bit Fields */
#define DMA_DCHPRI14_CHPRI_MASK                  0xFu
#define DMA_DCHPRI14_CHPRI_SHIFT                 0
#define DMA_DCHPRI14_CHPRI(x)                    (((x)<<DMA_DCHPRI14_CHPRI_SHIFT)&DMA_DCHPRI14_CHPRI_MASK)
#define DMA_DCHPRI14_DPA_MASK                    0x40u
#define DMA_DCHPRI14_DPA_SHIFT                   6
#define DMA_DCHPRI14_ECP_MASK                    0x80u
#define DMA_DCHPRI14_ECP_SHIFT                   7
/* DCHPRI13 Bit Fields */
#define DMA_DCHPRI13_CHPRI_MASK                  0xFu
#define DMA_DCHPRI13_CHPRI_SHIFT                 0
#define DMA_DCHPRI13_CHPRI(x)                    (((x)<<DMA_DCHPRI13_CHPRI_SHIFT)&DMA_DCHPRI13_CHPRI_MASK)
#define DMA_DCHPRI13_DPA_MASK                    0x40u
#define DMA_DCHPRI13_DPA_SHIFT                   6
#define DMA_DCHPRI13_ECP_MASK                    0x80u
#define DMA_DCHPRI13_ECP_SHIFT                   7
/* DCHPRI12 Bit Fields */
#define DMA_DCHPRI12_CHPRI_MASK                  0xFu
#define DMA_DCHPRI12_CHPRI_SHIFT                 0
#define DMA_DCHPRI12_CHPRI(x)                    (((x)<<DMA_DCHPRI12_CHPRI_SHIFT)&DMA_DCHPRI12_CHPRI_MASK)
#define DMA_DCHPRI12_DPA_MASK                    0x40u
#define DMA_DCHPRI12_DPA_SHIFT                   6
#define DMA_DCHPRI12_ECP_MASK                    0x80u
#define DMA_DCHPRI12_ECP_SHIFT                   7
/* SADDR Bit Fields */
#define DMA_SADDR_SADDR_MASK                     0xFFFFFFFFu
#define DMA_SADDR_SADDR_SHIFT                    0
#define DMA_SADDR_SADDR(x)                       (((x)<<DMA_SADDR_SADDR_SHIFT)&DMA_SADDR_SADDR_MASK)
/* SOFF Bit Fields */
#define DMA_SOFF_SOFF_MASK                       0xFFFFu
#define DMA_SOFF_SOFF_SHIFT                      0
#define DMA_SOFF_SOFF(x)                         (((x)<<DMA_SOFF_SOFF_SHIFT)&DMA_SOFF_SOFF_MASK)
/* ATTR Bit Fields */
#define DMA_ATTR_DSIZE_MASK                      0x7u
#define DMA_ATTR_DSIZE_SHIFT                     0
#define DMA_ATTR_DSIZE(x)                        (((x)<<DMA_ATTR_DSIZE_SHIFT)&DMA_ATTR_DSIZE_MASK)
#define DMA_ATTR_DMOD_MASK                       0xF8u
#define DMA_ATTR_DMOD_SHIFT                      3
#define DMA_ATTR_DMOD(x)                         (((x)<<DMA_ATTR_DMOD_SHIFT)&DMA_ATTR_DMOD_MASK)
#define DMA_ATTR_SSIZE_MASK                      0x700u
#define DMA_ATTR_SSIZE_SHIFT                     8
#define DMA_ATTR_SSIZE(x)                        (((x)<<DMA_ATTR_SSIZE_SHIFT)&DMA_ATTR_SSIZE_MASK)
#define DMA_ATTR_SMOD_MASK                       0xF800u
#define DMA_ATTR_SMOD_SHIFT                      11
#define DMA_ATTR_SMOD(x)                         (((x)<<DMA_ATTR_SMOD_SHIFT)&DMA_ATTR_SMOD_MASK)
/* NBYTES_MLNO Bit Fields */
#define DMA_NBYTES_MLNO_NBYTES_MASK              0xFFFFFFFFu
#define DMA_NBYTES_MLNO_NBYTES_SHIFT             0
#define DMA_NBYTES_MLNO_NBYTES(x)                (((x)<<DMA_NBYTES_MLNO_NBYTES_SHIFT)&DMA_NBYTES_MLNO_NBYTES_MASK)
/* NBYTES_MLOFFNO Bit Fields */
#define DMA_NBYTES_MLOFFNO_NBYTES_MASK           0x3FFFFFFFu
#define DMA_NBYTES_MLOFFNO_NBYTES_SHIFT          0
#define DMA_NBYTES_MLOFFNO_NBYTES(x)             (((x)<<DMA_NBYTES_MLOFFNO_NBYTES_SHIFT)&DMA_NBYTES_MLOFFNO_NBYTES_MASK)
#define DMA_NBYTES_MLOFFNO_DMLOE_MASK            0x40000000u
#define DMA_NBYTES_MLOFFNO_DMLOE_SHIFT           30
#define DMA_NBYTES_MLOFFNO_SMLOE_MASK            0x80000000u
#define DMA_NBYTES_MLOFFNO_SMLOE_SHIFT           31
/* NBYTES_MLOFFYES Bit Fields */
#define DMA_NBYTES_MLOFFYES_NBYTES_MASK          0x3FFu
#define DMA_NBYTES_MLOFFYES_NBYTES_SHIFT         0
#define DMA_NBYTES_MLOFFYES_NBYTES(x)            (((x)<<DMA_NBYTES_MLOFFYES_NBYTES_SHIFT)&DMA_NBYTES_MLOFFYES_NBYTES_MASK)
#define DMA_NBYTES_MLOFFYES_MLOFF_MASK           0x3FFFFC00u
#define DMA_NBYTES_MLOFFYES_MLOFF_SHIFT          10
#define DMA_NBYTES_MLOFFYES_MLOFF(x)             (((x)<<DMA_NBYTES_MLOFFYES_MLOFF_SHIFT)&DMA_NBYTES_MLOFFYES_MLOFF_MASK)
#define DMA_NBYTES_MLOFFYES_DMLOE_MASK           0x40000000u
#define DMA_NBYTES_MLOFFYES_DMLOE_SHIFT          30
#define DMA_NBYTES_MLOFFYES_SMLOE_MASK           0x80000000u
#define DMA_NBYTES_MLOFFYES_SMLOE_SHIFT          31
/* SLAST Bit Fields */
#define DMA_SLAST_SLAST_MASK                     0xFFFFFFFFu
#define DMA_SLAST_SLAST_SHIFT                    0
#define DMA_SLAST_SLAST(x)                       (((x)<<DMA_SLAST_SLAST_SHIFT)&DMA_SLAST_SLAST_MASK)
/* DADDR Bit Fields */
#define DMA_DADDR_DADDR_MASK                     0xFFFFFFFFu
#define DMA_DADDR_DADDR_SHIFT                    0
#define DMA_DADDR_DADDR(x)                       (((x)<<DMA_DADDR_DADDR_SHIFT)&DMA_DADDR_DADDR_MASK)
/* DOFF Bit Fields */
#define DMA_DOFF_DOFF_MASK                       0xFFFFu
#define DMA_DOFF_DOFF_SHIFT                      0
#define DMA_DOFF_DOFF(x)                         (((x)<<DMA_DOFF_DOFF_SHIFT)&DMA_DOFF_DOFF_MASK)
/* CITER_ELINKYES Bit Fields */
#define DMA_CITER_ELINKYES_CITER_MASK            0x1FFu
#define DMA_CITER_ELINKYES_CITER_SHIFT           0
#define DMA_CITER_ELINKYES_CITER(x)              (((x)<<DMA_CITER_ELINKYES_CITER_SHIFT)&DMA_CITER_ELINKYES_CITER_MASK)
#define DMA_CITER_ELINKYES_LINKCH_MASK           0x1E00u
#define DMA_CITER_ELINKYES_LINKCH_SHIFT          9
#define DMA_CITER_ELINKYES_LINKCH(x)             (((x)<<DMA_CITER_ELINKYES_LINKCH_SHIFT)&DMA_CITER_ELINKYES_LINKCH_MASK)
#define DMA_CITER_ELINKYES_ELINK_MASK            0x8000u
#define DMA_CITER_ELINKYES_ELINK_SHIFT           15
/* CITER_ELINKNO Bit Fields */
#define DMA_CITER_ELINKNO_CITER_MASK             0x7FFFu
#define DMA_CITER_ELINKNO_CITER_SHIFT            0
#define DMA_CITER_ELINKNO_CITER(x)               (((x)<<DMA_CITER_ELINKNO_CITER_SHIFT)&DMA_CITER_ELINKNO_CITER_MASK)
#define DMA_CITER_ELINKNO_ELINK_MASK             0x8000u
#define DMA_CITER_ELINKNO_ELINK_SHIFT            15
/* DLAST_SGA Bit Fields */
#define DMA_DLAST_SGA_DLASTSGA_MASK              0xFFFFFFFFu
#define DMA_DLAST_SGA_DLASTSGA_SHIFT             0
#define DMA_DLAST_SGA_DLASTSGA(x)                (((x)<<DMA_DLAST_SGA_DLASTSGA_SHIFT)&DMA_DLAST_SGA_DLASTSGA_MASK)
/* CSR Bit Fields */
#define DMA_CSR_START_MASK                       0x1u
#define DMA_CSR_START_SHIFT                      0
#define DMA_CSR_INTMAJOR_MASK                    0x2u
#define DMA_CSR_INTMAJOR_SHIFT                   1
#define DMA_CSR_INTHALF_MASK                     0x4u
#define DMA_CSR_INTHALF_SHIFT                    2
#define DMA_CSR_DREQ_MASK                        0x8u
#define DMA_CSR_DREQ_SHIFT                       3
#define DMA_CSR_ESG_MASK                         0x10u
#define DMA_CSR_ESG_SHIFT                        4
#define DMA_CSR_MAJORELINK_MASK                  0x20u
#define DMA_CSR_MAJORELINK_SHIFT                 5
#define DMA_CSR_ACTIVE_MASK                      0x40u
#define DMA_CSR_ACTIVE_SHIFT                     6
#define DMA_CSR_DONE_MASK                        0x80u
#define DMA_CSR_DONE_SHIFT                       7
#define DMA_CSR_MAJORLINKCH_MASK                 0xF00u
#define DMA_CSR_MAJORLINKCH_SHIFT                8
#define DMA_CSR_MAJORLINKCH(x)                   (((x)<<DMA_CSR_MAJORLINKCH_SHIFT)&DMA_CSR_MAJORLINKCH_MASK)
#define DMA_CSR_BWC_MASK                         0xC000u
#define DMA_CSR_BWC_SHIFT                        14
#define DMA_CSR_BWC(x)                           (((x)<<DMA_CSR_BWC_SHIFT)&DMA_CSR_BWC_MASK)
/* BITER_ELINKNO Bit Fields */
#define DMA_BITER_ELINKNO_BITER_MASK             0x7FFFu
#define DMA_BITER_ELINKNO_BITER_SHIFT            0
#define DMA_BITER_ELINKNO_BITER(x)               (((x)<<DMA_BITER_ELINKNO_BITER_SHIFT)&DMA_BITER_ELINKNO_BITER_MASK)
#define DMA_BITER_ELINKNO_ELINK_MASK             0x8000u
#define DMA_BITER_ELINKNO_ELINK_SHIFT            15
/* BITER_ELINKYES Bit Fields */
#define DMA_BITER_ELINKYES_BITER_MASK            0x1FFu
#define DMA_BITER_ELINKYES_BITER_SHIFT           0
#define DMA_BITER_ELINKYES_BITER(x)              (((x)<<DMA_BITER_ELINKYES_BITER_SHIFT)&DMA_BITER_ELINKYES_BITER_MASK)
#define DMA_BITER_ELINKYES_LINKCH_MASK           0x1E00u
#define DMA_BITER_ELINKYES_LINKCH_SHIFT          9
#define DMA_BITER_ELINKYES_LINKCH(x)             (((x)<<DMA_BITER_ELINKYES_LINKCH_SHIFT)&DMA_BITER_ELINKYES_LINKCH_MASK)
#define DMA_BITER_ELINKYES_ELINK_MASK            0x8000u
#define DMA_BITER_ELINKYES_ELINK_SHIFT           15

/*! \} */ /* end of group DMA_Register_Masks */


/* DMA - Peripheral instance base addresses */
/*! Peripheral eDMA base pointer */
#define eDMA_BASE_PTR                            ((DMA_MemMapPtr)0x40008000u)

/* ----------------------------------------------------------------------------
   -- DMA - Register accessor macros
   ---------------------------------------------------------------------------- */

/*! \addtogroup DMA_Register_Accessor_Macros DMA - Register accessor macros */
/*! \{ */


/* DMA - Register instance definitions */
/* eDMA */
#define DMA_CR                                   DMA_CR_REG(eDMA_BASE_PTR)
#define DMA_ES                                   DMA_ES_REG(eDMA_BASE_PTR)
#define DMA_ERQ                                  DMA_ERQ_REG(eDMA_BASE_PTR)
#define DMA_EEI                                  DMA_EEI_REG(eDMA_BASE_PTR)
#define DMA_CEEI                                 DMA_CEEI_REG(eDMA_BASE_PTR)
#define DMA_SEEI                                 DMA_SEEI_REG(eDMA_BASE_PTR)
#define DMA_CERQ                                 DMA_CERQ_REG(eDMA_BASE_PTR)
#define DMA_SERQ                                 DMA_SERQ_REG(eDMA_BASE_PTR)
#define DMA_CDNE                                 DMA_CDNE_REG(eDMA_BASE_PTR)
#define DMA_SSRT                                 DMA_SSRT_REG(eDMA_BASE_PTR)
#define DMA_CERR                                 DMA_CERR_REG(eDMA_BASE_PTR)
#define DMA_CINT                                 DMA_CINT_REG(eDMA_BASE_PTR)
#define DMA_INT                                  DMA_INT_REG(eDMA_BASE_PTR)
#define DMA_ERR                                  DMA_ERR_REG(eDMA_BASE_PTR)
#define DMA_HRS                                  DMA_HRS_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI0                              DMA_DCHPRI0_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI1                              DMA_DCHPRI1_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI2                              DMA_DCHPRI2_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI3                              DMA_DCHPRI3_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI4                              DMA_DCHPRI4_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI5                              DMA_DCHPRI5_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI6                              DMA_DCHPRI6_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI7                              DMA_DCHPRI7_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI8                              DMA_DCHPRI8_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI9                              DMA_DCHPRI9_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI10                             DMA_DCHPRI10_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI11                             DMA_DCHPRI11_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI12                             DMA_DCHPRI12_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI13                             DMA_DCHPRI13_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI14                             DMA_DCHPRI14_REG(eDMA_BASE_PTR)
#define DMA_DCHPRI15                             DMA_DCHPRI15_REG(eDMA_BASE_PTR)
#define DMA_TCD0_SADDR                           DMA_SADDR_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_SOFF                            DMA_SOFF_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_ATTR                            DMA_ATTR_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_SLAST                           DMA_SLAST_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_DADDR                           DMA_DADDR_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_DOFF                            DMA_DOFF_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_DLASTSGA                        DMA_DLAST_SGA_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_CSR                             DMA_CSR_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,0)
#define DMA_TCD0_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,0)
#define DMA_TCD1_SADDR                           DMA_SADDR_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_SOFF                            DMA_SOFF_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_ATTR                            DMA_ATTR_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_SLAST                           DMA_SLAST_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_DADDR                           DMA_DADDR_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_DOFF                            DMA_DOFF_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_DLASTSGA                        DMA_DLAST_SGA_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_CSR                             DMA_CSR_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,1)
#define DMA_TCD1_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,1)
#define DMA_TCD2_SADDR                           DMA_SADDR_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_SOFF                            DMA_SOFF_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_ATTR                            DMA_ATTR_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_SLAST                           DMA_SLAST_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_DADDR                           DMA_DADDR_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_DOFF                            DMA_DOFF_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_DLASTSGA                        DMA_DLAST_SGA_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_CSR                             DMA_CSR_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,2)
#define DMA_TCD2_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,2)
#define DMA_TCD3_SADDR                           DMA_SADDR_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_SOFF                            DMA_SOFF_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_ATTR                            DMA_ATTR_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_SLAST                           DMA_SLAST_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_DADDR                           DMA_DADDR_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_DOFF                            DMA_DOFF_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_DLASTSGA                        DMA_DLAST_SGA_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_CSR                             DMA_CSR_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,3)
#define DMA_TCD3_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,3)
#define DMA_TCD4_SADDR                           DMA_SADDR_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_SOFF                            DMA_SOFF_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_ATTR                            DMA_ATTR_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_SLAST                           DMA_SLAST_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_DADDR                           DMA_DADDR_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_DOFF                            DMA_DOFF_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_DLASTSGA                        DMA_DLAST_SGA_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_CSR                             DMA_CSR_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,4)
#define DMA_TCD4_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,4)
#define DMA_TCD5_SADDR                           DMA_SADDR_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_SOFF                            DMA_SOFF_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_ATTR                            DMA_ATTR_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_SLAST                           DMA_SLAST_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_DADDR                           DMA_DADDR_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_DOFF                            DMA_DOFF_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_DLASTSGA                        DMA_DLAST_SGA_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_CSR                             DMA_CSR_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,5)
#define DMA_TCD5_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,5)
#define DMA_TCD6_SADDR                           DMA_SADDR_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_SOFF                            DMA_SOFF_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_ATTR                            DMA_ATTR_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_SLAST                           DMA_SLAST_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_DADDR                           DMA_DADDR_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_DOFF                            DMA_DOFF_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_DLASTSGA                        DMA_DLAST_SGA_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_CSR                             DMA_CSR_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,6)
#define DMA_TCD6_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,6)
#define DMA_TCD7_SADDR                           DMA_SADDR_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_SOFF                            DMA_SOFF_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_ATTR                            DMA_ATTR_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_SLAST                           DMA_SLAST_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_DADDR                           DMA_DADDR_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_DOFF                            DMA_DOFF_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_DLASTSGA                        DMA_DLAST_SGA_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_CSR                             DMA_CSR_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,7)
#define DMA_TCD7_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,7)
#define DMA_TCD8_SADDR                           DMA_SADDR_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_SOFF                            DMA_SOFF_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_ATTR                            DMA_ATTR_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_SLAST                           DMA_SLAST_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_DADDR                           DMA_DADDR_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_DOFF                            DMA_DOFF_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_DLASTSGA                        DMA_DLAST_SGA_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_CSR                             DMA_CSR_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,8)
#define DMA_TCD8_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,8)
#define DMA_TCD9_SADDR                           DMA_SADDR_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_SOFF                            DMA_SOFF_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_ATTR                            DMA_ATTR_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_NBYTES_MLOFFNO                  DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_NBYTES_MLNO                     DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_NBYTES_MLOFFYES                 DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_SLAST                           DMA_SLAST_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_DADDR                           DMA_DADDR_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_DOFF                            DMA_DOFF_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_CITER_ELINKYES                  DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_CITER_ELINKNO                   DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_DLASTSGA                        DMA_DLAST_SGA_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_CSR                             DMA_CSR_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_BITER_ELINKNO                   DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,9)
#define DMA_TCD9_BITER_ELINKYES                  DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,9)
#define DMA_TCD10_SADDR                          DMA_SADDR_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_SOFF                           DMA_SOFF_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_ATTR                           DMA_ATTR_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_SLAST                          DMA_SLAST_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_DADDR                          DMA_DADDR_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_DOFF                           DMA_DOFF_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_DLASTSGA                       DMA_DLAST_SGA_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_CSR                            DMA_CSR_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,10)
#define DMA_TCD10_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,10)
#define DMA_TCD11_SADDR                          DMA_SADDR_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_SOFF                           DMA_SOFF_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_ATTR                           DMA_ATTR_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_SLAST                          DMA_SLAST_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_DADDR                          DMA_DADDR_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_DOFF                           DMA_DOFF_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_DLASTSGA                       DMA_DLAST_SGA_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_CSR                            DMA_CSR_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,11)
#define DMA_TCD11_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,11)
#define DMA_TCD12_SADDR                          DMA_SADDR_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_SOFF                           DMA_SOFF_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_ATTR                           DMA_ATTR_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_SLAST                          DMA_SLAST_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_DADDR                          DMA_DADDR_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_DOFF                           DMA_DOFF_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_DLASTSGA                       DMA_DLAST_SGA_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_CSR                            DMA_CSR_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,12)
#define DMA_TCD12_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,12)
#define DMA_TCD13_SADDR                          DMA_SADDR_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_SOFF                           DMA_SOFF_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_ATTR                           DMA_ATTR_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_SLAST                          DMA_SLAST_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_DADDR                          DMA_DADDR_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_DOFF                           DMA_DOFF_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_DLASTSGA                       DMA_DLAST_SGA_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_CSR                            DMA_CSR_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,13)
#define DMA_TCD13_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,13)
#define DMA_TCD14_SADDR                          DMA_SADDR_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_SOFF                           DMA_SOFF_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_ATTR                           DMA_ATTR_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_SLAST                          DMA_SLAST_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_DADDR                          DMA_DADDR_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_DOFF                           DMA_DOFF_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_DLASTSGA                       DMA_DLAST_SGA_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_CSR                            DMA_CSR_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,14)
#define DMA_TCD14_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,14)
#define DMA_TCD15_SADDR                          DMA_SADDR_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_SOFF                           DMA_SOFF_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_ATTR                           DMA_ATTR_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_NBYTES_MLOFFYES                DMA_NBYTES_MLOFFYES_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_NBYTES_MLOFFNO                 DMA_NBYTES_MLOFFNO_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_NBYTES_MLNO                    DMA_NBYTES_MLNO_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_SLAST                          DMA_SLAST_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_DADDR                          DMA_DADDR_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_DOFF                           DMA_DOFF_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_CITER_ELINKYES                 DMA_CITER_ELINKYES_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_CITER_ELINKNO                  DMA_CITER_ELINKNO_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_DLASTSGA                       DMA_DLAST_SGA_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_CSR                            DMA_CSR_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_BITER_ELINKYES                 DMA_BITER_ELINKYES_REG(eDMA_BASE_PTR,15)
#define DMA_TCD15_BITER_ELINKNO                  DMA_BITER_ELINKNO_REG(eDMA_BASE_PTR,15)

/*! \} */ /* end of group DMA_Register_Accessor_Macros */


/*! \} */ /* end of group DMA_Peripheral */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*! \} */ /* end of group Peripheral_defines */


/* ----------------------------------------------------------------------------
   -- Backward Compatibility
   ---------------------------------------------------------------------------- */

/*! \addtogroup Backward_Compatibility_Symbols Backward Compatibility */
/*! \{ */

/* No backward compatibility issues. */

/*! \} */ /* end of group Backward_Compatibility_Symbols */


#endif  /* #if !defined(MCU_MK40N512VMD100) */

/* MK40N512VMD100.h, eof. */
