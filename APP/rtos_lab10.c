#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "Std_Types.h"
#include "semphr.h"

#ifndef NULL
#define NULL (void *)0
#endif


void Led2(void * pvparam);
#define Led2Pr (3)

void PushButton2(void * pvparam);
#define PushButton2Pr (2)

void Led(void * pvparam);
#define LedPr (1)

void init(void);

xSemaphoreHandle ButtonSemaphore = NULL;


 int main(void)
{

	 /* Creation of the Task*/
	 xTaskHandle Led2Handle  = NULL;
	 xTaskCreate(Led2,(const signed char*)"Led 2",85,NULL,Led2Pr,&Led2Handle);

	 /* Creation of the Task*/
	 xTaskHandle PushHandle2  = NULL;
	 xTaskCreate(PushButton2,(const signed char*)"Push Button 2",85,NULL,PushButton2Pr,&PushHandle2);


	 xTaskHandle LedHandle = NULL ;
	 xTaskCreate(Led,(const signed char*)"Led ",85,NULL,LedPr,&LedHandle);

	 /*Init Function*/
	 init();

	 /*Create Semaphore for the Button */
	 vSemaphoreCreateBinary(ButtonSemaphore);


	/*start Scheduler */
	vTaskStartScheduler();



	/*Never Enter Here */
	return 0;
}

void init(void){

	DDRA = 1<<4 | 1 <<5;

	DDRD = 0x00;

	PORTD = 0xFF;

}
 void Led2(void * pvparam){
	 portTickType Freq = 1000;
	 portTickType Start = xTaskGetTickCount();
	 vTaskDelay(20);
	 while (1){

			 /* If the Resource No One is Using so Take the Semaphore  **/
			 while(pdFALSE == xSemaphoreTake(ButtonSemaphore,100)){
				 vTaskDelay(100);
				 PORTA ^= 1<<5;
			 }

			 vTaskDelay(10000);

			 xSemaphoreGive(ButtonSemaphore);

		 /*Make the Task Periodic with Period 50 Tick */
		 vTaskDelayUntil(&Start,Freq);
	 }

 }


 void PushButton2(void * pvparam){
	 portTickType Freq = 100;
	 portTickType Start = xTaskGetTickCount();
	 while (1){

				 while(pdFALSE == xSemaphoreTake(ButtonSemaphore,100));

				 if( (PIND & 1<<7) == 0){
                    
                 }

				 vTaskDelay(1000);

				 /**Give the Semaphore */

				 xSemaphoreGive(ButtonSemaphore);

		 /*Make the Task Periodic with Period 50 Tick */
		 vTaskDelayUntil(&Start,Freq);
	 }

 }



 void Led(void * pvparam){
	 portTickType Freq = 100;
	 portTickType Start = xTaskGetTickCount();
	 vTaskDelay(30);
	 while (1){

		 PORTA ^= 1<<4;PORTA ^= 1<<5;

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
