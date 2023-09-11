/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 26 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : GPIO_interface.h               *****************/
/****************************************************************/
#ifndef GPIO_INTERFACE_H 
#define GPIO_INTERFACE_H 

#define GPIO_OUTOUT                      0
#define GPIO_INPUT                       1
 
#define GPIO_PORTA                       0  
#define GPIO_PORTB                       1  
#define GPIO_PORTC                       2     
 
#define GPIO_LOW                         0
#define GPIO_HIGH                        1
 
#define GPIO_PIN0                        0
#define GPIO_PIN1                        1
#define GPIO_PIN2                        2
#define GPIO_PIN3                        3
#define GPIO_PIN4                        4
#define GPIO_PIN5                        5
#define GPIO_PIN6                        6
#define GPIO_PIN7                        7
#define GPIO_PIN8                        8
#define GPIO_PIN9                        9
#define GPIO_PIN10                       10
#define GPIO_PIN11                       11
#define GPIO_PIN12                       12
#define GPIO_PIN13                       13
#define GPIO_PIN14                       14
#define GPIO_PIN15                       15




#define GPIO_INPUT_ANALOG                         0b0000 
#define GPIO_INPUT_FLOATING                       0b0100
#define GPIO_INPUT_PP                             0b1000
             
#define GPIO_OUTPUT_PP_10MHZ                      0b0001
#define GPIO_INPUT_OPEN_DRAIN_10MHZ               0b0101
#define GPIO_INPUT_AF_PP_10MHZ                    0b1001
#define GPIO_INPUT_AF_OPEN_DRAIN_10MHZ            0b1101

#define GPIO_OUTPUT_PP_2MHZ                       0b0010
#define GPIO_INPUT_OPEN_DRAIN_2MHZ                0b0110
#define GPIO_INPUT_AF_PP_2MHZ                     0b1010
#define GPIO_INPUT_AF_OPEN_DRAIN_2MHZ             0b1110

#define GPIO_OUTPUT_PP_50MHZ                      0b0011 
#define GPIO_INPUT_OPEN_DRAIN_50MHZ               0b0111 
#define GPIO_INPUT_AF_PP_50MHZ                    0b1011
#define GPIO_INPUT_AF_OPEN_DRAIN_50MHZ            0b1111

Std_ReturnType Local_FunctionStatus = E_NOT_OK;
Std_ReturnType GPIO_SetPinMode( u8 Copy_Portid , u8 Copy_Pinid , u8 Copy_PinMode )
Std_ReturnType Mcal_Gpio_SetPinValue( u8 Copy_Portid , u8 Copy_Pinid , u8 Copy_PinValue );
Std_ReturnType Mcal_Gpio_GetPinValue( u8 Copy_Portid , u8 Copy_Pinid , u8 *Copy_PinMode )







#endif