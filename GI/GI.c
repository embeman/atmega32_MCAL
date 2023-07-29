#include <GI/GI.h>
#include <GI/GI_Reg.h>
#include <Bit_Math.h>


void GI_Enable(){
	SET_BIT(SREG , 7);
}
void GI_Disable(){
	CLEAR_BIT(SREG , 7);
}
