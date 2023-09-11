/****************************************************************/
/******* Author    : Basel Mohamed Ramadan      *****************/
/******* Date      : 4 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : RCC_private.h              *****************/
/****************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/**
 * @defgroup RCC_Registers
 * @brief Reset and Clock Control (RCC) Registers
 *
 * This module provides definitions for the RCC (Reset and Clock Control) registers
 * for configuring and controlling system clocks and resets in the microcontroller.
 *
 * @{
 */

/**
 * @brief RCC Control Register (CR)
 *
 * This register provides control over the main and PLL (Phase-Locked Loop) system clocks.
 */
#define RCC_CR                  (*((volatile u32 *)0x40021000))

/**
 * @brief RCC Configuration Register (CFGR)
 *
 * This register configures the system clock sources, prescalers, and peripherals clocks.
 */
#define RCC_CFGR                (*((volatile u32 *)0x40021004))

/**
 * @brief RCC Clock Interrupt Register (CIR)
 *
 * This register manages clock interrupts and flags.
 */
#define RCC_CIR                 (*((volatile u32 *)0x40021008))

/**
 * @brief RCC APB2 Peripheral Reset Register (APB2RSTR)
 *
 * This register controls the reset state of peripherals connected to APB2 bus.
 */
#define RCC_APB2RSTR            (*((volatile u32 *)0x4002100C))

/**
 * @brief RCC APB1 Peripheral Reset Register (APB1RSTR)
 *
 * This register controls the reset state of peripherals connected to APB1 bus.
 */
#define RCC_APB1RSTR            (*((volatile u32 *)0x40021010))

/**
 * @brief RCC AHB Peripheral Clock Enable Register (AHBENR)
 *
 * This register enables clock access for peripherals connected to AHB bus.
 */
#define RCC_AHBENR              (*((volatile u32 *)0x40021014))

/**
 * @brief RCC APB1 Peripheral Clock Enable Register (APB1ENR)
 *
 * This register enables clock access for peripherals connected to APB1 bus.
 */
#define RCC_APB1ENR             (*((volatile u32 *)0x4002101C))

/**
 * @brief RCC APB2 Peripheral Clock Enable Register (APB2ENR)
 *
 * This register enables clock access for peripherals connected to APB2 bus.
 */
#define RCC_APB2ENR             (*((volatile u32 *)0x40021018))

/**
 * @brief RCC Backup Domain Control Register (BDCR)
 *
 * This register provides control over backup domain and RTC (Real-Time Clock).
 */
#define RCC_BDCR                (*((volatile u32 *)0x40021020))

/**
 * @brief RCC Control and Status Register (CSR)
 *
 * This register provides various control and status flags.
 */
#define RCC_CSR                 (*((volatile u32 *)0x40021024))

/** @} */ // end of RCC Control Register (CR)

/**
 * @defgroup RCC_CR_Bit_Definitions RCC Control Register (RCC_CR) Bit Definitions
 * @{
 */

#define RCC_CR_HSION        0   /**< Internal High-Speed Clock Enable */
#define RCC_CR_HSIRDY       1   /**< Internal High-Speed Clock Ready */
#define RCC_CR_HSICAL       8   /**< Internal High-Speed Clock Calibration */
#define RCC_CR_HSEON        16  /**< External High-Speed Clock Enable */
#define RCC_CR_HSERDY       17  /**< External High-Speed Clock Ready */
#define RCC_CR_HSEBYP       18  /**< External High-Speed Clock Bypass */
#define RCC_CR_HSEPRE       19  /**< External High-Speed Clock Prescaler */
#define RCC_CR_CSSON        19  /**< Clock Security System Enable */
#define RCC_CR_PLLON        24  /**< PLL Enable */
#define RCC_CR_PLLRDY       25  /**< PLL Ready */

/** @} */ // end of RCC_CR_Bit_Definitions

/**
 * @defgroup RCC_Clock_Source RCC Clock Source Macros
 * @{
 */

#define RCC_HSI             0   /**< High-Speed Internal Clock Source (HSI) */
#define RCC_HSE             1   /**< High-Speed External Clock Source (HSE) */
#define RCC_PLL             2   /**< Phase-Locked Loop Clock Source (PLL) */

/** @} */ // end of RCC_Clock_Source

/**
 * @defgroup RCC_Clock_Type RCC Clock Type Macros
 * @{
 */

#define RCC_CRYSTAL_CLK_    0   /**< Crystal Oscillator Clock Type */
#define RCC_RC_CLK_         1   /**< RC Oscillator Clock Type */

/** @} */ // end of RCC_Clock_Type


/**
 * @defgroup RCC_CFGR_Bit_Definitions RCC Control Register (RCC_CFGR) Bit Definitions
 * @{
 */

#define RCC_CFGR_SW          0    /**< Switch to enable which clock*/
#define RCC_CFGR_SWS         2    /**<  System clock switch status */
#define RCC_CFGR_HPRE        4    /**< AHB prescaler to control the division factor of the AHB clock. */
#define RCC_CFGR_PPRE1       8    /**< APB low-speed prescaler (APB1) to control the division factor of the APB low-speed clock  */
#define RCC_CFGR_PPRE2       11   /**< APB high-speed prescaler (APB2) to control the division factor of the APB high-speed clock  */
#define RCC_CFGR_ADCPRE      14   /**< ADC prescaler to select the frequency of the clock to the ADCs */
#define RCC_CFGR_PLLSRC      16   /**< PLL entry clock source to select PLL clock source */
#define RCC_CFGR_PLLXTPRE    17   /**< HSE divider for PLL entry */
#define RCC_CFGR_PLLMUL      18   /**< PLL multiplication factor */
#define RCC_CFGR_USBPREY     22   /**<  USB prescaler */
#define RCC_CFGR_MCO         24   /**<  Microcontroller clock output */

/** @} */ // end of RCC_CFGR_Bit_Definitions\

#define FLASH_ACR               (*((volatile u32 *)0x40022000))  /***< Flash Access Control Register */
#define FLASH_ACR_PRFTBE        4      /***< Prefetch Buffer Enable */


/**
 * @defgroup RCC_CFGR_SW Macros
 * @{
 */
#define RCC_CFGR_SW_HSE         0b00 
#define RCC_CFGR_SW_HSI         0b01 
#define RCC_CFGR_SW_PLL         0b10 

/** @} */ // end of RRCC_CFGR_SW Macros\



/**
 * @defgroup RCC_CFGR_INPUT_CLK Macros
 * @{
 */
#define RCC_PLL_INPUT_CLK_4         0b0010
#define RCC_PLL_INPUT_CLK_5         0b0011
#define RCC_PLL_INPUT_CLK_6         0b0100
#define RCC_PLL_INPUT_CLK_7         0b0101
#define RCC_PLL_INPUT_CLK_8         0b0110
#define RCC_PLL_INPUT_CLK_9         0b0111

/** @} */ // RCC_CFGR_INPUT_CLK Macros\


/**
 * @defgroup RCC_CFGR_MCO_IN
 * @{
 */
#define RCC_CFGR_MCO_SYSCLK         0b0100
#define RCC_CFGR_MCO_PLLDIV         0b0111
#define RCC_CFGR_MCO_HSE            0b0110
#define RCC_CFGR_MCO_HSI            0b0101

/** @} */ // RCC_CFGR_MCO_IN\

#endif /* RCC_PRIVATE_H_ */