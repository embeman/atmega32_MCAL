#include <Dio_Cfg.h>


#define NUM_OF_DIO 1

Pin_Config_t Pin_Configs[]={
		{PB0  , OUTPUT}
};

void Dio_Init(){
	int i=0;
	for (int i = 0; i < NUM_OF_DIO; i++) {
		DIO_Init_Channel(Pin_Configs[i].PORT ,Pin_Configs[i].DDR );
	}
}
