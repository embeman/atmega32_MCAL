FILES = main.o Dio_Cfg.o Dio.o
INCLUDE = ./Dio/include/ utils/
MCU = atmega32

all:

test_target:
	avrdude -p m32 -c usbasp

flash: main.hex
	avrdude -p m32 -c usbasp -U flash:w:full.hex:i

main.hex: $(FILES)
	avr-ld  $(FILES) -o full.o
	avr-objcopy -j .text -j .data -O ihex full.o full.hex
	rm *.o
	
# main file
main.o: main.c
	avr-gcc -c $^ -o $@ -mmcu=$(MCU) -O0 -IDio/include/ -Iutils/

# DIO file
Dio.o: Dio/src/Dio.c
	avr-gcc -c $^ -o $@ -mmcu=$(MCU) -O0 -IDio/include/ -Iutils/

Dio_Cfg.o: Dio/src/Dio_Cfg.c
	avr-gcc -c $^ -o $@ -mmcu=$(MCU) -O0 -IDio/include/ -Iutils/



.Phony: clean

clean:
	rm full.hex
