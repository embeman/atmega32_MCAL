#include <Dio_Cfg.h>


#define NUM_OF_DIO 1

Pin_Config_t Pin_Configs[]={
		{PB0  , OUTPUT}
};

void Dio_Init(){
	int i=0;
	for (int i = 0; i < NUM_OF_DIO; i++) {
		Dio_InitChannel(Pin_Configs[i].PORT ,Pin_Configs[i].DDR );
	}
}
