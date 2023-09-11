/****************************************************************/
/******* Author    : Basel Mohamed Ramadan      *****************/
/******* Date      : 4 Sep 2023                 *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : RCC_program.c              *****************/
/****************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


Std_ReturnType Mcal_Rcc_InitSysClock(void)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    #if RCC_SYSCLK == RCC_HSE 
        
        /**< Enable the external clock to be the source for the system clock. */
        #if RCC_CLK_BYPASS == RCC_RC_CLK_
            SET_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose RC as a SYSCLK */
        #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK_
            CLR_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose CRYSTAL as a SYSCLK */
        #else 
            #error "Wrong Choice !!"
        #endif /**< RCC_CLK_BYPASS */

        /**< Enable the High-Speed External clock. */
        SET_BIT(RCC_CR, RCC_CR_HSEON);

        /**< Wait until the High-Speed External clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_HSERDY));

        /**< Select High-Speed External clock as the system clock source. */
        RCC_CFGR_SW = RCC_CFGR_SW_HSE;

        Local_FunctionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_HSI
        
        /**< Enable the High-Speed Internal clock. */
        SET_BIT(RCC_CR, RCC_CR_HSION);

        /**< Wait until the High-Speed Internal clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_HSIRDY));

        /**< Select High-Speed Internal clock as the system clock source. */
        RCC_CFGR_SW = RCC_CFGR_SW_HSI;

        Local_FunctionStatus = E_OK;

    #elif (RCC_SYSCLK == RCC_PLL  && (RCC_CFGR_PLLSRC == PLL_SRC_HSE || RCC_CFGR_PLLSRC == PLL_SRC_HSI) )

      /**< To define the PLL multiplication factor*/
        RCC_CFGR_PLLMUL = RCC_PLL_INP_CLK;

     /**< Enable the PLL clock. */
        SET_BIT(RCC_PLL , RCC_CR_PLLON);

     /**< Wait until the PLL is stable. */
        while (!GET_BIT(RCC_CR , RCC_CR_PLLRDY));

     /**< Select PLL as the system clock source. */
       RCC_CFGR_SW = RCC_CFGR_SW_HSE;
       
       u8 SYSTEM_CLOCK = Get_PLL_FREQUENCY;
       u8 val=1;

        while (SYS_CLk > 72 && val < 10) // it can be divided by 2^9 (512) max.
        {
            SYS_CLk /= pow(2, val);
            val++;
        }
        
        /**< The value when the while loop condition is false which means that the SYSTEM_CLOCK is less 72 MHZ */
        u8 Suitable_AHB_Division = pow(2, --val);

        /**< Start AHB Prescaler */
        if (val != 1) /**< If val == 1 then the AHB Prescaler is kept without changes (SYSTEM_CLOCK / 1)*/
        {
            /**< The prefetch buffer must be kept on when using a prescaler different from 1 on the AHB clock */
            SET_BIT(FLASH_ACR, FLASH_ACR_PRFTBE);

            RCC_CFGR &= ~((0b1111)<< RCC_CFGR_HPRE);
            switch (Suitable_AHB_Division)
            {
            case 2:
                RCC_CFGR |= (0b1000<< RCC_CFGR_HPRE);
            break;
            case 4:
                RCC_CFGR |= (0b1001<< RCC_CFGR_HPRE);
            break;
            case 8:
                RCC_CFGR |= (0b1010<< RCC_CFGR_HPRE);
            break;
            case 16:
                RCC_CFGR |= (0b1011<< RCC_CFGR_HPRE);
            break;
            case 64:
                RCC_CFGR |= (0b1100<< RCC_CFGR_HPRE);
            break;
            case 128:
                RCC_CFGR |= (0b1101<< RCC_CFGR_HPRE);
                 break;
            case 256:
                RCC_CFGR |= (0b1110<< RCC_CFGR_HPRE);
            break;
            case 512:
                RCC_CFGR |= (0b1111<< RCC_CFGR_HPRE);
            break;
            default:
                RCC_CFGR |= (0b0000<< RCC_CFGR_HPRE); /**<  SYSCLK not divided */
            break;
            }
        }
     

      
       


       Local_FunctionStatus = E_OK;  
       

    #else
        #error "Wrong Choice !!"

    #endif /**< RCC_SYSCLK */

    return Local_FunctionStatus;
}

Std_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        /**< Enable the peripheral on the AHB bus. */
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB1 bus. */
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Enable the peripheral on the APB2 bus. */
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;
}

Std_ReturnType Mcal_Rcc_DisablePeripheral(u8 Copy_BusId, u8 Copy_PeripheralId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_BusId)
    {
        /**< Disable the peripheral on the AHB bus. */
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Disable the peripheral on the APB1 bus. */
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        /**< Disable the peripheral on the APB2 bus. */
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
            break;

        default:
            Local_FunctionStatus = E_NOT_OK;
            break;
    }

    return Local_FunctionStatus;
}
  Std_ReturnType Get_PLL_FREQUENCY ( u8 RCC_CFGR_PLLSRC)
  {
    {
    u8 PLL_Frequency = 0;

    #if RCC_CFGR_PLLSRC == RCC_CFGR_PLLSRC_HSI /**< If HSI is the PLL source clock which provide (8MHZ / 2) */
        PLL_Frequency = 4 * (DesiredMultiplier + 2);
    #elif RCC_CFGR_PLLSRC == RCC_CFGR_PLLSRC_HSE /**< If HSE is the PLL source clock which provide (8MHZ) if it is Crystal or RC */
        #if HSE_DIV == RCC_CFGR_PLLSRC_HSE_NOT_DIV
            PLL_Frequency = 8 * (DesiredMultiplier + 2);
        #else
            PLL_Frequency = 4 * (DesiredMultiplier + 2);
        #endif
    #else
        PLL_Frequency = 0;
    #endif

    return PLL_Frequency;
}
  }