#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum {
	PA0=0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,
	PC0,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,
	PD0,
	PD1,
	PD2,
	PD3,
	PD4,
	PD5,
	PD6,
	PD7
} Pin_Channel;

typedef enum {
	LOW, HIGH
} Pin_Channel_State;

typedef enum{
	INPUT , OUTPUT , INPUT_PULLUP
}Pin_Channel_Direction;

#endif /* DIO_TYPES_H_ */
