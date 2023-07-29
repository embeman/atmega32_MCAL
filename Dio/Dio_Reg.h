#ifndef MCAL_DIO_REG_H_
#define MCAL_DIO_REG_H_

#include <Std_Types.h>

#define _PORTA (*(volatile uint8*)(0x3B))
#define _DDRA (*(volatile uint8*)(0x3A))
#define _PINA (*(volatile const uint8*)(0x39))

#define _PORTB (*(volatile uint8*)(0x38))
#define _DDRB (*(volatile uint8*)(0x37))
#define _PINB (*(volatile const uint8*)(0x36))

#define _PORTC (*(volatile uint8*)(0x35))
#define _DDRC (*(volatile uint8*)(0x34))
#define _PINC (*(volatile const uint8*)(0x33))

#define _PORTD (*(volatile uint8*)(0x32))
#define _DDRD (*(volatile uint8*)(0x31))
#define _PIND (*(volatile const uint8*)(0x30))


#endif
