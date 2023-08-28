#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "Std_Types.h"
#include "semphr.h"

#ifndef NULL
#define NULL (void *)0
#endif


void PushButton(void * pvparam);
#define PushButtonPr (1)

void PushButton2(void * pvparam);
#define PushButton2Pr (2)


void Led(void * pvparam);
#define LedPr (2)

void init(void);

/*** Global Variable ****/
uint8 ButtonState = 1;
uint8 ButtonState2 = 1;


xSemaphoreHandle ButtonSemaphore = NULL;

xSemaphoreHandle Button2Semaphore = NULL;

 int main(void)
{

	 /* Creation of the Task*/
	 xTaskHandle PushHandle  = NULL;
	 xTaskCreate(PushButton,(const signed char*)"Push Button",85,NULL,PushButtonPr,&PushHandle);

	 /* Creation of the Task*/
	 xTaskHandle PushHandle2  = NULL;
	 xTaskCreate(PushButton2,(const signed char*)"Push Button 2",85,NULL,PushButton2Pr,&PushHandle2);


	 xTaskHandle LedHandle = NULL ;
	 xTaskCreate(Led,(const signed char*)"Led ",85,NULL,LedPr,&LedHandle);

	 /*Init Function*/
	 init();

	 /*Create Semaphore for the Button */
	 vSemaphoreCreateBinary(ButtonSemaphore);

	 /*Create Semaphore for the Button */
	 vSemaphoreCreateBinary(Button2Semaphore);

	/*start Scheduler */
	vTaskStartScheduler();



	/*Never Enter Here */
	return 0;
}

void init(void){

	DDRB = 1<<0;

	DDRD &=~(1<<7);

	PORTD = 1<<7;

}
 void PushButton(void * pvparam){

	 portTickType Freq = 100;
	 portTickType Start = xTaskGetTickCount();
	 while (1){
		 /* if the Push Button is Pressed */
		 if ((PIND & 1<<7) == 0){

			 /* If the Resource No One is Using so Take the Semaphore  **/
			 if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100)){

				 vTaskDelay(1000);

				 while(pdFALSE == xSemaphoreTake(Button2Semaphore,100));

				 /*Change the State **/
				 ButtonState = 0;

				 /**Give the Semaphore */

				 xSemaphoreGive(Button2Semaphore);

				 xSemaphoreGive(ButtonSemaphore);


		 }

		 }

		 /*Make the Task Periodic with Period 50 Tick */
		 vTaskDelayUntil(&Start,Freq);
	 }

 }


 void PushButton2(void * pvparam){
	 portTickType Freq = 100;
	 portTickType Start = xTaskGetTickCount();
	 while (1){
		 /* if the Push Button is Pressed */
		 if ((PIND & 1<<6) == 0){

			 /* If the Resource No One is Using so Take the Semaphore  **/
			 if(pdTRUE == xSemaphoreTake(Button2Semaphore,100)){

				 vTaskDelay(1000);

				 while(pdFALSE == xSemaphoreTake(ButtonSemaphore,100));

				 /*Change the State **/
				 ButtonState2 = 0;

				 /**Give the Semaphore */

				 xSemaphoreGive(ButtonSemaphore);

				 xSemaphoreGive(Button2Semaphore);


		 }

		 /*Make the Task Periodic with Period 50 Tick */
		 vTaskDelayUntil(&Start,Freq);
	 }

 }
 }


 void Led(void * pvparam){
	 portTickType Freq = 100;
	 portTickType Start = xTaskGetTickCount();
	 while (1){
		 /* if the Push Button is Pressed */

			 /* If the Resource No One is Using so Take the Semaphore  **/
			 if(pdTRUE == xSemaphoreTake(ButtonSemaphore,100)){

				 vTaskDelay(1000);

				 while(pdFALSE == xSemaphoreTake(Button2Semaphore,100));

				 if (ButtonState == 0 && ButtonState2 == 0){
					 PORTB ^= 0x01;
					 ButtonState = 1;
					 ButtonState2 = 1;
				 }

				 /**Give the Semaphore */
				 xSemaphoreGive(Button2Semaphore);
				 xSemaphoreGive(ButtonSemaphore);

		 /*Make the Task Periodic with Period 50 Tick */
		 vTaskDelayUntil(&Start,Freq);
	 }


 }
 }

void vApplicationIdleHook(void){
    while (1)
    {
        /* code */
    }
    
}
