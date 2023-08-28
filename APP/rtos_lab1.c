

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

/* Define Tasks Priorities */
#define  LedOn_PRIORITY (2)

/*tasks codes prototypes */
 void LedIntro_code_red( void* pvParamter);
/*tasks codes prototypes */
 void LedIntro_code_green( void* pvParamter);
/*tasks codes prototypes */
 void LedIntro_code_blue( void* pvParamter);


 /*Create Task Handles Create */
 xTaskHandle Task1Hand = NULL;
 /*Create Task Handles Create */
 xTaskHandle Task2Hand = NULL;
 /*Create Task Handles Create */
 xTaskHandle Task3Hand = NULL;


 int main(void)
{
	/*Create tasks*/
	xTaskCreate(LedIntro_code_red,(const signed char *)"Task1",85,NULL,LedOn_PRIORITY,&Task1Hand);
	xTaskCreate(LedIntro_code_green,(const signed char *)"Task2",85,NULL,LedOn_PRIORITY,&Task2Hand);
	xTaskCreate(LedIntro_code_blue,(const signed char *)"Task3",85,NULL,LedOn_PRIORITY,&Task3Hand);

	/*start Scheduler */
	vTaskStartScheduler();

	/*Never Enter Here */
	return 0;
}

/*Task1 Code */
 void LedIntro_code_red(void*pvParamter)
{
    DDRB |= 1<<7;
	for (;;)
	{
		/*Toggle Led */
		PORTB ^= 1<<7;
		/*Send Task in Blocked Queue for 2000 Ticks */
		vTaskDelay(2000);
	}
}


/*Task3 Code */
 void LedIntro_code_green(void*pvParamter)
{
    DDRA |= 1<<4;
	for (;;){
		/*Toggle Led */
		PORTA ^= 1<<4;
		/*Send Task in Blocked Queue for 2000 Ticks */
		vTaskDelay(1000);
	}
}


/*Task3 Code */
 void LedIntro_code_blue(void*pvParamter)
{
    DDRA |= 1<<5;
	for (;;){
		/*Toggle Led */
		PORTA ^= 1<<5;
		/*Send Task in Blocked Queue for 2000 Ticks */
		vTaskDelay(500);
	}
}

void vApplicationIdleHook(void){
    while (1)
    {
        /* code */
    }
    
}