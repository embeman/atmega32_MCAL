

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

#ifndef NULL
#define NULL (void *)0
#endif


/* Define Tasks Priorities */
#define  LedOn_PRIORITY (3)
#define  ButtonOn_PRIORITY (2)

void LedIntro_code(void*pvParamter) ;
void ButtonIntro_code (void * pvParamter) ;
/*Create Task Handles Create */
xTaskHandle Task1Hand = NULL;
xTaskHandle Task2Hand = NULL;

char flag = 0 ;

int main(void)
{

	DDRA = 0x01 ;
	DDRB =0x00;
	PORTB |=0x01;
	xTaskCreate(LedIntro_code,(const signed char *)"Task1",85,NULL,LedOn_PRIORITY,&Task1Hand);

	xTaskCreate(ButtonIntro_code,(const signed char *)"Task2",85,NULL,ButtonOn_PRIORITY,&Task2Hand);

	/*start Scheduler */
	vTaskStartScheduler();

	/*Never Enter Here */
	return 0;
}

/*Task1 Code */
void LedIntro_code(void*pvParamter)
{
    DDRB |= 1<<7;
    PORTB &=~(1<<7);
	while(1){
		vTaskDelay(200);
		if (flag == 1){
			PORTB ^= (1<<7);
			/*Send Task in Blocked Queue for 200 Ticks */
			flag = 0;
		}
	}


}

void ButtonIntro_code (void * pvParamter)
{
    // init switch 
    DDRD &=~(1<<7);
    PORTD |= 1<<7;
	
    while(1)
	{
		vTaskDelay(100);
		if ( ( (PIND >> 7) & 0x01 ) == 0 )
		{
			flag = 1 ;

		}

	}
}

void vApplicationIdleHook(void){
    while (1)
    {
        /* code */
    }
    
}



