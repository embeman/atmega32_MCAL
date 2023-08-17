#include <Dio_Cfg.h>
#include <Dio.h>
#include <Lcd.h>
#include <Keypad.h>
#include <Uart.h>
#include <EEPROM.h>
#include <avr/io.h>
#include <util/delay.h>

int main(){
    Dio_InitChannel(GROUPB,PB0,OUTPUT);
    Dio_InitChannel(GROUPB,PB1,OUTPUT);

    Dio_WriteChannel(GROUPB , PB0 , HIGH);
    Dio_WriteChannel(GROUPB , PB1 , LOW);
    while (1){
        Dio_FlipChannel(GROUPB,PB0);
        Dio_FlipChannel(GROUPB,PB1);
        _delay_ms(100);
    }
    return 0;
}