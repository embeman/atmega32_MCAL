#include <Dio_Cfg.h>


#define NUM_OF_DIO 12

Pin_Config_t Pin_Configs[]={
		{PB0  , OUTPUT}, // inputs to bcd
		{PB1  , OUTPUT},
		{PB2  , OUTPUT},
		{PB4  , OUTPUT},

		{PB6  , OUTPUT},
		{PB5  , OUTPUT},
		{PA2  , OUTPUT},
		{PA3  , OUTPUT},

		// LEDs
		{PB7  , OUTPUT},	// Red
		{PA4  , OUTPUT},	// Green
		{PA5  , OUTPUT},	// Blue
		{PA6  , OUTPUT}		// Yellow
};

void Dio_Init(){
	int i=0;
	for (int i = 0; i < NUM_OF_DIO; i++) {
		DIO_Init_Channel(Pin_Configs[i].PORT ,Pin_Configs[i].DDR );
	}
}
