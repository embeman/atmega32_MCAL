#include <Dio.h>
#include <Bit_Math.h>
#include <atmega32_REG.h>

void DIO_Init_Channel(Pin_Channel pin ,Pin_Channel_Direction dir){
	switch(pin/8){
	case 0:
		SET_BIT(_DDRA , pin%8);
		break;
	case 1:
		SET_BIT(_DDRB , pin%8);
		break;
	case 2:
		SET_BIT(_DDRC , pin%8);
		break;
	default:
		SET_BIT(_DDRD , pin%8);
		break;
	}
}

void DIO_Write_Channel(Pin_Channel pin , Pin_Channel_State state){
	switch(pin/8){
	case 0:
		if(state){
			SET_BIT(_PORTA , pin%8);
		}else{
			CLEAR_BIT(_PORTA, pin%8);
		}
		break;
	case 1:
		if(state){
			SET_BIT(_PORTB , pin%8);
		}else{
			CLEAR_BIT(_PORTB, pin%8);
		}
		break;
	case 2:
		if(state){
			SET_BIT(_PORTC , pin%8);
		}else{
			CLEAR_BIT(_PORTC , pin%8);
		}
		break;
	default:
		if(state){
			SET_BIT(_PORTD , pin%8);
		}else{
			CLEAR_BIT(_PORTD , pin%8);
		}
		break;
	}
}

uint8 DIO_Read_Channel(Pin_Channel pin){
	switch(pin/8){
	case 0:
		return GET_BIT(_PINA , pin%8);
		break;
	case 1:
		return GET_BIT(_PINB , pin%8);
		break;
	case 2:
		return GET_BIT(_PINC , pin%8);
		break;
	default:
		return GET_BIT(_PIND , pin%8);
		break;
	}
	return 0;
}

