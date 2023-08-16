# Set project directory one level above of Makefile directory. $(CURDIR) is a GNU make variable containing the path to the current working directory
PROJ_DIR := $(realpath $(CURDIR))
PROJ_NAME = myApp

CC = avr-gcc
LD = avr-ld
OBJCOPY = avr-objcopy

# Name of the final executable
TARGET = $(addsuffix .elf, $(PROJ_NAME))
HEX_FILE = $(patsubst %.elf,%.hex,$(TARGET))
BUILDDIR := Build

DIRS =		MCAL/WDT 		\
			MCAL/ADC 		\
			MCAL/DIO 		\
			MCAL/EXTI 		\
			MCAL/GI 		\
			MCAL/SPI		\
			MCAL/TIMER	 	\
			MCAL/TWI 		\
			MCAL/UART 		\
			HAL/LCD			\
			HAL/Keypad

SOURCES := $(foreach i , $(DIRS) , $(wildcard $(i)/*.c))
OBJECTS := $(foreach i, $(SOURCES), $(patsubst %.c,%.o,$(i)))
MKDIR := $(foreach i , $(DIRS) , $(addprefix $(BUILDDIR)/, $(i)))

IPATH = utils MCAL/ADC MCAL/DIO MCAL/EXTI MCAL/GI MCAL/SPI MCAL/TIMER MCAL/TWI MCAL/UART MCAL/WDT HAL/LCD HAL/Keypad 

INCLUDE = $(foreach dir, $(IPATH), $(addprefix -I, $(dir)))

MCU = atmega32
F_CPU = 1000000UL

CFLAGS := -mmcu=$(MCU) -Wall -Os -DF_CPU=$(F_CPU) $(INCLUDE)


all:$(TARGET) $(HEX_FILE)


$(TARGET): main.o $(OBJECTS)
	@echo "Linking $@"
	$(LD) $^ -o $@

main.o: main.c
	@echo "Building $<"
	@$(CC) -c $< -o $@ $(CFLAGS)

$(HEX_FILE): $(TARGET)
	@echo "Creating Hex File $(HEX_FILE)"
	@$(OBJCOPY) -j .text -j .data -O ihex $(TARGET) $@

########################################################################
# using static pattern rule to compile for now
# TODO : using generate rule method
$(OBJECTS):%.o:%.c
	@echo "Building $<"
	@$(CC) -c $< -o $@ $(CFLAGS)
########################################################################


flash: $(HEX_FILE)
	avrdude -p m32 -c usbasp -U flash:w:$<


test_connection:
	avrdude -p m32 -c usbasp


clean:
	@rm main.o
	@rm $(OBJECTS)
	@rm $(TARGET)
	@rm $(HEX_FILE)
	


# Used in Debuging Makefile By printing variables names
print-%: 
	@echo $* = $($*)