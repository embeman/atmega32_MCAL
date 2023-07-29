FILES = main.o Dio_Cfg.o Dio.o Exti.o GI.o Timer.o
INCLUDE = -IEXTI/ -IGI/ -ITimer/ -IDio/ -Iutils/ 
MCU = atmega32

all:

test_connection_target:
	avrdude -p m32 -c usbasp

flash: main.hex
	avrdude -p m32 -c usbasp -U flash:w:full.hex:i

main.hex: $(FILES)
	avr-ld  $(FILES) -o full.o
	avr-objcopy -j .text -j .data -O ihex full.o full.hex
	rm *.o
	
# main file
main.o: main.c
	avr-gcc -c $^ -o $@ -mmcu=$(MCU) -O0 $(INCLUDE)

# DIO file
Dio.o: Dio/src/Dio.c
	avr-gcc -c $^ -o $@ -mmcu=$(MCU) -O0 $(INCLUDE)

Dio_Cfg.o: Dio/src/Dio_Cfg.c
	avr-gcc -c $^ -o $@ -mmcu=$(MCU) -O0 -IDio/include/ -Iutils/
#EXTI 
Exti.o: Exti/Exti.c
	avr-gcc -c $^ -o $@ -mmcu=$(MCU) -O0 $(INCLUDE)
# GI 
GI.o: GI/GI.c
	avr-gcc -c $^ -o $@ -mmcu=$(MCU) -O0 $(INCLUDE)
# Timer
Timer.o: Timer/Timer.c
	avr-gcc -c $^ -o $@ -mmcu=$(MCU) -O0 $(INCLUDE)

.Phony: clean

clean:
	rm full.hex
