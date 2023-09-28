/****************************************************************/
/******* Author    : Basel Mohamed Ramadan      *****************/
/******* Date      : 4 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : RCC_config.h               *****************/
/****************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/**
 * @defgroup RCC_System_Clock_Config RCC System Clock Configuration Macros
 * @brief Macros for configuring the RCC system clock source and type.
 * @{
 */

/**
 * @brief Select the system clock source.
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.
 */
#define RCC_SYSCLK            RCC_HSE


/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS        RCC_CRYSTAL_CLK_

#endif /**< RCC_SYSCLK */

#define RCC_PLL_INP_CLK     RCC_PLL_INPUT_CLK_4  /**< To define the multiplication factor for the PLL clock
                                                   Your choices are: RCC_PLL_INPUT_CLK_4
                                                                     RCC_PLL_INPUT_CLK_5
                                                                     RCC_PLL_INPUT_CLK_6
                                                                     RCC_PLL_INPUT_CLK_7
                                                                     RCC_PLL_INPUT_CLK_8
                                                                     RCC_PLL_INPUT_CLK_9*/

#define RCC_CFGR_MCO_IN     RCC_CFGR_MCO_SYSCLK   /***< To select which clock you want to read
                                                        OPTIONS : RCC_CFGR_MCO_SYSCLK 
                                                                  RCC_CFGR_MCO_PLLDIV 
                                                                  RCC_CFGR_MCO_HSE    
                                                                  RCC_CFGR_MCO_HSI    */                                                                    
                                              
                    




/** @} */ // end of RCC_System_Clock_Config


                                
#endif /**< RCC_CONFIG_H_ */