#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"




 
  //Functions prototypes
    void EXTI0_IRQHandler(void);
	void BlinkYellow(void);
	void GoToYellow(void);
	void GoToGreen(void);


		
	int main()
	{
		//Initialize the system clock
		MCAL_RCC_InitSysClock();

		//Enable GPIO Ports A and B
		MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPAEN);
		MCAL_RCC_EnablePeripheral(RCC_APB2,RCC_APB2ENR_IOPBEN);

		//Configure GPIO pins modes
		
		/***********< CAR PINS****************/
		MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT_PUSH_PULL_2MHZ); //RED
		MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT_PUSH_PULL_2MHZ); //YELLOW
		MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUT_PUSH_PULL_2MHZ); //GREEN
		
		/***********< PUSHBUTTON****************/
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN0,GPIO_INPUT_PULL_DOWN );
		
		/***********< PRED PINS****************/
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN1,GPIO_OUTPUT_PUSH_PULL_2MHZ);  //RED
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN2,GPIO_OUTPUT_PUSH_PULL_2MHZ);  //YELLOW
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN3,GPIO_OUTPUT_PUSH_PULL_2MHZ);  //GREEN
		
		//Enable the EXTI0 interrupt
		MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);

		//Initialize and configure the EXTI (External Interrupt) peripheral
		MCAL_EXTI_vInit();
		MCAL_EXTI_InitEXTIForGPIO(GPIO_PIN0, GPIO_PORTB);
		MCAL_EXTI_SetTrigger( EXTI_LINE0 , EXTI_RISING_EDGE);
		MCAL_EXTI_EnableLine(EXTI_LINE0);
		
		while (1) 
		{
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	     	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
			
			  MCAL_STK_SetDelay_ms(3000);
			
		 	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	     	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
			 
			 MCAL_STK_SetDelay_ms(2000);
			
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	   	    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
				
				MCAL_STK_SetDelay_ms(3000);
				
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	   	    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
			
			 MCAL_STK_SetDelay_ms(2000);
			
			
			
		}
		
	
		
			return 0 ;
			
		}
	
		void EXTI0_IRQHandler(void)
		{
			u8 VAL;
			u8 Car_Green , Car_Yellow , Car_Red ;
			
			for( u32 i = 0 ; i < 10000; i++);
			
			MCAL_GPIO_GetPinValue(GPIO_PORTB,GPIO_PIN0,&VAL);
			
			
			if( VAL == GPIO_LOW )
			{
				
				
				MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN3,&Car_Green); //green
				MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN2,&Car_Yellow); //yellow
				MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN1,&Car_Red); //red
				
			if( Car_Green == GPIO_HIGH ){
				
				
					BlinkYellow();
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	     	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
			
		      	for( u32 f = 0 ; f < 80000 ; f++);
			
						
						GoToYellow();
		    	for( u32 i = 0 ; i < 200000 ; i++);
					  GoToGreen();
					for( f = 0 ; f < 200000 ; f++);

				}	
     				
			
			else if ( Car_Yellow == GPIO_HIGH )
				{
		     BlinkYellow();
				
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	  	 	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
					
					for( u32 c = 0 ; c < 10000 ; c++);
					
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
	   	    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
					
					for( u32 y = 0 ; y < 100000; y++);
					
					GoToYellow();
				
					for( y = 0 ; y < 100000; y++);
					
					
				}	
					
	  
				
		 
			 
			}
		}
		
		void GoToYellow(void)
		{
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	   	    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
		}
			
		
		void GoToGreen(void)
			{
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	   	    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
							
		  }
			
			void BlinkYellow(void)
				{
					
					for( u32 i = 0 ; i < 4 ; i++){
						
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	   	    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
						
						for( u32 i = 0 ; i < 20000 ; i++);
						
			MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	   	    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
		    MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
			MCAL_GPIO_SetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);
						for( u32 c = 0 ; c < 20000 ; c++);
						
					}	
			}
		
			
		

		
	
		