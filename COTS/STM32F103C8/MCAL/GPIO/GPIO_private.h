/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 26 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : GPIO_private.h               *****************/
/****************************************************************/
#ifndef GPIO_PRIVATE_H 
#define GPIO_PRIVATE_H 

#define GPIO_PORTA_BASE_ADRESS           0x40010800U
#define GPIO_PORTB_BASE_ADRESS           0x40010C00U
#define GPIO_PORTC_BASE_ADRESS           0x40011000U

/***********************************<PORT A**********************************************/
#define GPIO_PORTA_CRL           (*(volatile u32*) GPIO_PORTA_BASE_ADRESS + 0x00 )
#define GPIO_PORTA_CRH           (*(volatile u32*) GPIO_PORTA_BASE_ADRESS + 0x04 )
#define GPIO_PORTA_IDR           (*(volatile u32*) GPIO_PORTA_BASE_ADRESS + 0x08 )
#define GPIO_PORTA_ODR           (*(volatile u32*) GPIO_PORTA_BASE_ADRESS + 0x0C )
#define GPIO_PORTA_BSRR          (*(volatile u32*) GPIO_PORTA_BASE_ADRESS + 0x10 )
#define GPIO_PORTA_BRR           (*(volatile u32*) GPIO_PORTA_BASE_ADRESS + 0x14 )
#define GPIO_PORTA_LCKR          (*(volatile u32*) GPIO_PORTA_BASE_ADRESS + 0x18 )

/***********************************<PORT B**********************************************/
#define GPIO_PORTB_CRL           (*(volatile u32*) GPIO_PORTB_BASE_ADRESS + 0x00 )
#define GPIO_PORTB_CRH           (*(volatile u32*) GPIO_PORTB_BASE_ADRESS + 0x04 )
#define GPIO_PORTB_IDR           (*(volatile u32*) GPIO_PORTB_BASE_ADRESS + 0x08 )
#define GPIO_PORTB_ODR           (*(volatile u32*) GPIO_PORTB_BASE_ADRESS + 0x0C )
#define GPIO_PORTB_BSRR          (*(volatile u32*) GPIO_PORTB_BASE_ADRESS + 0x10 )
#define GPIO_PORTB_BRR           (*(volatile u32*) GPIO_PORTB_BASE_ADRESS + 0x14 )
#define GPIO_PORTB_LCKR          (*(volatile u32*) GPIO_PORTB_BASE_ADRESS + 0x18 )

/***********************************<PORT C **********************************************/
#define GPIO_PORTC_CRL           (*(volatile u32*) GPIO_PORTC_BASE_ADRESS + 0x00 )
#define GPIO_PORTC_CRH           (*(volatile u32*) GPIO_PORTC_BASE_ADRESS + 0x04 )
#define GPIO_PORTC_IDR           (*(volatile u32*) GPIO_PORTC_BASE_ADRESS + 0x08 )
#define GPIO_PORTC_ODR           (*(volatile u32*) GPIO_PORTC_BASE_ADRESS + 0x0C )
#define GPIO_PORTC_BSRR          (*(volatile u32*) GPIO_PORTC_BASE_ADRESS + 0x10 )
#define GPIO_PORTC_BRR           (*(volatile u32*) GPIO_PORTC_BASE_ADRESS + 0x14 )
#define GPIO_PORTC_LCKR          (*(volatile u32*) GPIO_PORTC_BASE_ADRESS + 0x18 )







#endif