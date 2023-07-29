#ifndef DIO_H_
#define DIO_H_

#include <Dio_Types.h>
#include <Dio_Reg.h>


void DIO_Write_Channel(Pin_Channel pin ,Pin_Channel_State state);
uint8 DIO_Read_Channel(Pin_Channel pin);
void DIO_Init_Channel(Pin_Channel pin ,Pin_Channel_Direction dir);

#endif

