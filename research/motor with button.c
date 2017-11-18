/* Include core modules */
#include "stm32f4xx.h"
/* Include my libraries here */
#include "defines.h"
#include "tm_stm32f4_pwm.h"
//#include "tm_stm32f4_disco.h"
#include "tm_stm32f4_delay.h"

//ems 30A

int main(void) {
    TM_PWM_TIM_t TIM2_Data;
	TM_PWM_TIM_t TIM1_Data;
	GPIO_InitTypeDef GPIO_InitDef;
    //uint16_t position = 1000;

    SETUP();

    /* Initialize system */
    SystemInit();

    /* Initialize delay functions */
    TM_DELAY_Init();

    /* Set PWM to 50Hz frequency on timer TIM2 */
    /* 50Hz = 20ms = 20000us */
    TM_PWM_InitTimer(TIM2, &TIM2_Data, 500);
	TM_PWM_InitTimer(TIM1, &TIM1_Data, 500);
	 
    /* Initialize PWM on TIM2, Channel 1 and PinsPack 2 = PA5 */
    TM_PWM_InitChannel(&TIM2_Data, TM_PWM_Channel_1, TM_PWM_PinsPack_2);
	//Initialize PWM on TIM2, Channel 1 and PinsPack 3 = PA8 */
	TM_PWM_InitChannel(&TIM1_Data, TM_PWM_Channel_1, TM_PWM_PinsPack_1);

    /* Set channel 1 value, 1500us = servo at center position */
    //TM_PWM_SetChannelMicros(&TIM2_Data, TM_PWM_Channel_1, 1500);

    //TM_PWM_SetChannel(&TIM2_Data, TM_PWM_Channel_1, TIM2_Data.Period/1.2);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
 
    GPIO_InitDef.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitDef.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
    GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
    //Initialize pins
    GPIO_Init(GPIOA, &GPIO_InitDef);

    /* Servo in position */
    //Delayms(1000);
	static int state = 0;
    while (1) {
        //if (position == 1000) {
            /* Change direction */
            //position = 2000;
        //} else {
            /* Change direction */
            //position = 1000;
        //}

        /* Set servo position */
        //TM_PWM_SetChannelMicros(&TIM2_Data, TM_PWM_Channel_1, position);

        /* Set some delay for servo to set to correct position */
		int i;
        //Delayms(1500);
		//set pwm value for pin 
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)){
		TM_PWM_SetChannelPercent(&TIM2_Data, TM_PWM_Channel_1, 100);
		TM_PWM_SetChannelPercent(&TIM3_Data, TM_PWM_Channel_1, 0);
		}
		
		
		else{
			TM_PWM_SetChannelPercent(&TIM2_Data, TM_PWM_Channel_1, 0);
			TM_PWM_SetChannelPercent(&TIM3_Data, TM_PWM_Channel_1, 100);
    	}// Sets HIGH
    	    		 GPIO_SetBits(GPIOB, GPIO_Pin_3 | GPIO_Pin_5| GPIO_Pin_7); //pin 3=  slot6 ; pin 5 = MEN1 (Enable) ; pin 7 = MEN2 (Enable)
    	    		 //GPIO_WriteBit(GPIOD, GPIO_Pin_4, 0);
    	    		 // Sets LOW
    	    		 GPIO_ResetBits(GPIOD, GPIO_Pin_6);//pin 6 = MIN 1

    	    		 //TIM2->CCR1 = TIM2_Data.Period/2;
    	    		 
    	    		 //for (i = 0; i <= 100; i += 5)
    	    		        //{


    	    		  //TM_PWM_SetChannelPercent(&TIM2_Data, TM_PWM_Channel_1, 100);
    	    		        //}
    	    		 //TM_PWM_SetChannelPercent(&TIM2_Data, TM_PWM_Channel_1, 100);
    	    		 //Delayms(1500);


    }

}

void SETUP ()
    {
    	//Enable clock for GPIOB (Using AHB1 coz all pin connected to it)
    	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    	//Initialize struct or function for InitDef to work in GPIO_InitTypeDef
    	GPIO_InitTypeDef GPIO_InitDef;

    	//Declare the pin PE3,PE5,PE7,PD6
    	GPIO_InitDef.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_7 | GPIO_Pin_6 |GPIO_Pin_4;
    	//Set the pin as output
    	 ///////////GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;//
    	 GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
    	 GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
    	 GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
    	 GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;

    	 //Initialize pins on GPIOB and GPIOD port
    	 GPIO_Init(GPIOB, &GPIO_InitDef);
    	 GPIO_Init(GPIOD, &GPIO_InitDef);

    }

void SETUP2 ()
    {
    	//Enable clock for GPIOB (Using AHB1 coz all pin connected to it)
    	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    	//Initialize struct or function for InitDef to work in GPIO_InitTypeDef
    	GPIO_InitTypeDef GPIO_InitDef;

    	//Declare the pin PE3,PE5,PE7,PD6
    	GPIO_InitDef.GPIO_Pin = GPIO_Pin_4;
    	//Set the pin as output
    	 ///////////GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;//
    	 GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
    	 GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
    	 GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
    	 GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;

    	 //Initialize pins on GPIOB and GPIOD port
    	 GPIO_Init(GPIOB, &GPIO_InitDef);
    	 GPIO_Init(GPIOD, &GPIO_InitDef);

    }
