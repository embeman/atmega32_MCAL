

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "Std_Types.h"


void PushButton(void * pvparam);
#define PushButtonPr (1)

void Led(void * pvparam);
#define LedPr (2)

void init(void);

/*** Global Variable ****/
uint8 ButtonState = 1;

 int main(void)
{

	 /* Creation of the Task*/
	 xTaskHandle PushHandle  = NULL;
	 xTaskCreate(PushButton,(const signed char*)"Push Button",85,NULL,PushButtonPr,&PushHandle);

	 xTaskHandle LedHandle = NULL ;
	 xTaskCreate(Led,(const signed char*)"Led ",85,NULL,LedPr,&LedHandle);

	 /*Init Function*/
	 init();

	/*start Scheduler */
	vTaskStartScheduler();



	/*Never Enter Here */
	return 0;
}

void init(void){
	DDRB = 1<<7;

	DDRD &=~(1<<7);
    PORTD |=1<<0;

}

 void PushButton(void * pvparam){
	 portTickType Freq = 50;
	 portTickType Start = xTaskGetTickCount();
	 while (1){
		 /* if the Push Button is Pressed */
		 if ((PIND & (1 << 7)) == 0){
			 ButtonState = 0;
		 }

		 /*Make the Task Periodic with Period 50 Tick */
		 vTaskDelayUntil(&Start,Freq);
	 }

 }

 void Led(void * pvparam){
	 portTickType Freq = 50;
	 portTickType Start = xTaskGetTickCount();
	 while (1){
		 /* if the Push Button is Pressed */
		 if (ButtonState == 0){
			 PORTB ^= 1<<7;
			 ButtonState = 1;
		 }
		 /*Make the Task Periodic with Period 50 Tick */
		 vTaskDelayUntil(&Start,Freq);
	 }


 }

void vApplicationIdleHook(void){
    while (1)
    {
        /* code */
    }
    
}
