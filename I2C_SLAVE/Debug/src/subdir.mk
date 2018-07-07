################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Buzzer.c \
../src/DIO.c \
../src/I2C_Slave.c \
../src/LCD.c \
../src/main.c 

OBJS += \
./src/Buzzer.o \
./src/DIO.o \
./src/I2C_Slave.o \
./src/LCD.o \
./src/main.o 

C_DEPS += \
./src/Buzzer.d \
./src/DIO.d \
./src/I2C_Slave.d \
./src/LCD.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


