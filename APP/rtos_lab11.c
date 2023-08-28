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
#define PushButton2Pr (2)


void Led(void * pvparam);
#define LedPr (1)

void init(void);

xSemaphoreHandle ButtonSemaphore = NULL;
/* Creation of the Task*/


xTaskHandle LedHandle = NULL ;
xTaskHandle PushHandle2  = NULL;

int main(void)
{
	/* Creation of the Task*/
	xTaskCreate(PushButton,(const signed char*)"Push Button 2",85,NULL,PushButton2Pr,&PushHandle2);
	xTaskCreate(Led,(const signed char*)"Led ",85,NULL,LedPr,&LedHandle);

	/*Init Function*/
	init();

	/*Create Semaphore for the Button */
	vSemaphoreCreateBinary(ButtonSemaphore);
	xSemaphoreTake(ButtonSemaphore,100);

	/*start Scheduler */
	vTaskStartScheduler();



	/*Never Enter Here */
	return 0;
}

void init(void){

	DDRB = 1<<7;

	DDRD &=~(1<<7);

	PORTD |= 1<<7;

}



void PushButton(void * pvparam){
	portTickType Freq = 150;
	portTickType Start = xTaskGetTickCount();
	while (1){

		if((PIND & 1<<7) == 0){
			xSemaphoreGive(ButtonSemaphore);
		}
		/*Make the Task Periodic with Period 50 Tick */
		vTaskDelayUntil(&Start,Freq);
	}
}

void Led(void * pvparam){
	portTickType Freq = 10000;
	portTickType Start = xTaskGetTickCount();
	while (1){

		/* If the Resource No One is Using so Take the Semaphore  **/
		while(pdFALSE == xSemaphoreTake(ButtonSemaphore,100));
		PORTB ^= 1<<7;
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
