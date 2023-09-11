/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 26 Aug 2023                *****************/
/******* Version   : 0.1                        *****************/
/******* File Name : GPIO_program.c               *****************/
/****************************************************************/


/*****LIB****/
#include <STD_TYPES.h>
#include <BIT_MATH.h>

/******MCAL*********/
#include <GPIO_interface.h>
#include <GPIO_private.h>
#include <GPIO_config.h>


Std_ReturnType Mcal_Gpio_SetPinMode( u8 Copy_Portid , u8 Copy_Pinid , u8 Copy_PinMode )
{
 
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch(Copy_Portid)
    {
   case GPIO_PORTA :

          if (Copy_Pinid <8) 
          {
            GPIO_PORTA_CRL =~ ( 0b111 << (Copy_PinMode * 4));
            GPIO_PORTA_CRL =| ( GPIO_PORTA_CRL << (Copy_PinMode * 4));
            Local_FunctionStatus = E_OK;
          }
          else if(Copy_Pinid <16)
          {
               GPIO_PORTA_CRH =~ ( 0b111 << (Copy_PinMode * 4));
               GPIO_PORTA_CRH =| ( GPIO_PORTA_CRH << (Copy_PinMode * 4));
               Local_FunctionStatus = E_OK;
          }
          else {Local_FunctionStatus = E_NOT_OK;}
             break;
             
   case GPIO_PORTB :

         if (Copy_Pinid <8)
          {
               GPIO_PORTB_CRL =~ (0b111 << (Copy_PinMode * 4));
               GPIO_PORTB_CRL =| (GPIO_PORTA_CRL << (Copy_PinMode * 4));
               Local_FunctionStatus = E_OK;
          }
          else if(Copy_Pinid <16)
          {
             GPIO_PORTA_CRH =~ (0b111 << (Copy_PinMode * 4));
             GPIO_PORTA_CRH =| (GPIO_PORTA_CRL << (Copy_PinMode * 4));
             Local_FunctionStatus = E_OK;
          }
          else {Local_FunctionStatus = E_NOT_OK;}
             break;

   case GPIO_PORTC :

         if (Copy_Pinid <8)
          {
            GPIO_PORTA_CRL =~ (0b111 << (Copy_PinMode * 4));
            GPIO_PORTA_CRL =| (GPIO_PORTA_CRL << (Copy_PinMode * 4));
            Local_FunctionStatus = E_OK;
          }
          else if(Copy_Pinid <16)
          {
              GPIO_PORTA_CRH =~ (0b111 << (Copy_PinMode * 4));
              GPIO_PORTA_CRH =| (GPIO_PORTA_CRL << (Copy_PinMode * 4));
              Local_FunctionStatus = E_OK;
          }
          else {Local_FunctionStatus = E_NOT_OK;}
             break;
    default :
        Local_FunctionStatus = E_NOT_OK;
        break;

    }

      return Local_FunctionStatus;
}

Std_ReturnType Mcal_Gpio_SetPinValue( u8 Copy_Portid , u8 Copy_Pinid , u8 Copy_PinValue )
{
   switch (Copy_Portid){

      case GPIO_PORTA :
          switch( Copy_PinValue ) { 

            case GPIO_HIGH :
               SET_BIT( GPIO_PORTA_ODR , Copy_Pinid );
               Local_FunctionStatus = E_OK;
               break;
            
            case GPIO_LOW :
               CLR_BIT( GPIO_PORTA_ODR , Copy_Pinid );
               Local_FunctionStatus = E_OK;
               break;

            default : Local_FunctionStatus = E_NOT_OK;
            break;
          }
      break;

      case GPIO_PORTB :
       switch( Copy_PinValue ) { 

            case GPIO_HIGH :
               SET_BIT( GPIO_PORTB_ODR , Copy_Pinid );
               Local_FunctionStatus = E_OK;
               break;
            
            case GPIO_LOW :
               CLR_BIT( GPIO_PORTB_ODR , Copy_Pinid );
               Local_FunctionStatus = E_OK;
               break;

            default : Local_FunctionStatus = E_NOT_OK;
            break;
          }
      break;

      case GPIO_PORTC :
       switch( Copy_PinValue ) { 

            case GPIO_HIGH :
               SET_BIT( GPIO_PORTC_ODR , Copy_Pinid );
               Local_FunctionStatus = E_OK;
               break;
            
            case GPIO_LOW :
               CLR_BIT( GPIO_PORTC_ODR , Copy_Pinid );
               Local_FunctionStatus = E_OK;
               break;

            default : Local_FunctionStatus = E_NOT_OK;
            break;
          }
      break;

      default:
      Local_FunctionStatus = E_NOT_OK;
      break;

   }


 return Local_FunctionStatus;





}

Std_ReturnType Mcal_Gpio_GetPinValue( u8 Copy_Portid , u8 Copy_Pinid , u8 *Copy_PinReturnValue )
{
   if( *Copy_PinReturnValue != NULL )
   {

      switch (Copy_Portid) {

         case GPIO_PORTA:
         *Copy_PinReturnValue = GET_BIT( GPIO_PORTA_IDR , Copy_Pinid);
         Local_FunctionStatus = E_OK;
         break;

         case GPIO_PORTB:
        *Copy_PinReturnValue =  GET_BIT( GPIO_PORTB_IDR , Copy_Pinid);
         Local_FunctionStatus = E_OK;
         break;

         case GPIO_PORTC:
        *Copy_PinReturnValue =  GET_BIT( GPIO_PORTC_IDR , Copy_Pinid);
         Local_FunctionStatus = E_OK;
         break;

         default :
         Local_FunctionStatus = E_NOT_OK;

         break;

      
      }





   }
   else{ Local_FunctionStatus = E_NOT_OK}
   return Local_FunctionStatus;

}
#ifndef GPIO_PROGRAM_H 
#define GPIO_PROGRAM_H 











#endif