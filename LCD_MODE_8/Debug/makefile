################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
LCD_MODE_8.lss \

FLASH_IMAGE += \
LCD_MODE_8.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: LCD_MODE_8.elf secondary-outputs

# Tool invocations
LCD_MODE_8.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LCD_MODE_8.map -mmcu=atmega16 -o "LCD_MODE_8.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LCD_MODE_8.lss: LCD_MODE_8.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LCD_MODE_8.elf  >"LCD_MODE_8.lss"
	@echo 'Finished building: $@'
	@echo ' '

LCD_MODE_8.hex: LCD_MODE_8.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LCD_MODE_8.elf  "LCD_MODE_8.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LCD_MODE_8.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 LCD_MODE_8.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: LCD_MODE_8.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm16 -cusbasp -Uflash:w:LCD_MODE_8.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LCD_MODE_8.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
