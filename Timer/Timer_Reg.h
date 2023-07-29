#ifndef MCAL_TIMER_TIMER_REG_H_
#define MCAL_TIMER_TIMER_REG_H_

#include <Std_Types.h>

// TIMER 0
#define _TCCR0	*(volatile uint8*)(0x53)
#define _TCNT0	*(volatile uint8*)(0x52)
#define _OCR0	*(volatile uint8*)(0x5C)
#define _TIMSK	*(volatile uint8*)(0x59)
#define _TIFR	*(volatile uint8*)(0x58)


// TIMER 1
#define _TCCR1A	*(volatile uint8*)(0x4F)
#define _TCCR1B	*(volatile uint8*)(0x4E)

#define _TCNT1L	*(volatile uint8*)(0x4C)
#define _TCNT1H	*(volatile uint8*)(0x4D)

#define _OCR1AL	*(volatile uint8*)(0x4A)
#define _OCR1AH	*(volatile uint8*)(0x4B)

#define _OCR1BL	*(volatile uint8*)(0x48)
#define _OCR1BH	*(volatile uint8*)(0x49)

#define _ICR1L	*(volatile uint8*)(0x46)
#define _ICR1H	*(volatile uint8*)(0x47)

// TIMER 2
#define _TCCR2	*(volatile uint8*)(0x45)
#define _TCNR2	*(volatile uint8*)(0x44)
#define _OCR2	*(volatile uint8*)(0x43)






#endif /* MCAL_TIMER_TIMER_REG_H_ */
