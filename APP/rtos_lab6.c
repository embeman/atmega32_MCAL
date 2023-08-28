

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "Std_Types.h"

#ifndef NULL
#define NULL (void *)0
#endif


void PushButton(void * pvparam);
#define PushButtonPr (1)

void Led(void * pvparam);
#define LedPr (2)

void init(void);

/*** Global Variable ****/
uint8 ButtonState = 1;

uint8 ButtonStateFlag = 0;


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

	DDRD = 0x00;

	PORTD = 0xFF;

}

void PushButton(void * pvparam){
	 portTickType Freq = 50;
	 portTickType Start = xTaskGetTickCount();
	 while (1){
		 /* if the Push Button is Pressed */
		 if ((PIND & (1<<7)) == 0){

			 /* If the Resource No One is Using so Raise a Flag to Use it **/
			 if(ButtonStateFlag == 0){
				 /*Raise the Flag */
				 ButtonStateFlag = 1;

				 /*Change the State **/
				 ButtonState = 0;

				 /*Release the Flag */
				 ButtonStateFlag = 0;
			 }
			 /*Else Delay 10 Tick till the Resource is Free **/
			 else {
				 vTaskDelay(10);
			 }

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


		 /* If the Resource No One is Using so Raise a Flag to Use it **/
		 if(ButtonStateFlag == 0){

			 /*Raise the Flag */
			 ButtonStateFlag = 1;

			 if (ButtonState == 0){
				 PORTB ^= 1<<7;
				 ButtonState = 1;
			 }

			 /*Release the Flag */
			 ButtonStateFlag = 0;
		 }
		 /*Else Delay 10 Tick till the Resource is Free **/
		 else {
			 vTaskDelay(10);
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