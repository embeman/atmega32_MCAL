#include <GI/GI.h>
#include <Bit_Math.h>

#include <atmega32_REG.h>

void GI_Enable(){
	SET_BIT(SREG , 7);
}
void GI_Disable(){
	CLEAR_BIT(SREG , 7);
}
