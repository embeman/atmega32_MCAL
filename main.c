#include <Dio_Cfg.h>
#include <Dio.h>
#include <atmega32_Reg.h>

int main(){

    DIO_Init_Channel(PB0,OUTPUT);
    _PORTB |=1 <<0;
    while(1);
    return 0;
}