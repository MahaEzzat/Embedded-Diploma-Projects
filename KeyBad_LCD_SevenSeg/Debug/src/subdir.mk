################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Buzzer.c \
../src/DIO.c \
../src/KeyBad.c \
../src/LCD.c \
../src/LED.c \
../src/Seven_Segment.c \
../src/main.c 

OBJS += \
./src/Buzzer.o \
./src/DIO.o \
./src/KeyBad.o \
./src/LCD.o \
./src/LED.o \
./src/Seven_Segment.o \
./src/main.o 

C_DEPS += \
./src/Buzzer.d \
./src/DIO.d \
./src/KeyBad.d \
./src/LCD.d \
./src/LED.d \
./src/Seven_Segment.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


