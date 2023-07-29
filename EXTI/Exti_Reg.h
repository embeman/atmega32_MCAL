#ifndef MCAL_EXTI_EXTI_REG_H_
#define MCAL_EXTI_EXTI_REG_H_
#include "Std_Types.h"

#define _MCUCR	(*(volatile uint8*)(0x55))
#define _MCUCSR (*(volatile uint8*)(0x54))
#define _GICR	(*(volatile uint8*)(0x5B))
#define _GIFR	(*(volatile uint8*)(0x5A))

#define _DDRD (*(volatile uint8*)(0x31))
#define _DDRB (*(volatile uint8*)(0x37))


#endif /* MCAL_EXTI_EXTI_REG_H_ */
