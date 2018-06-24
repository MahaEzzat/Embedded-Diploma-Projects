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
Button_LED_Relay.lss \

FLASH_IMAGE += \
Button_LED_Relay.hex \

EEPROM_IMAGE += \
Button_LED_Relay.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Button_LED_Relay.elf secondary-outputs

# Tool invocations
Button_LED_Relay.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Button_LED_Relay.map -mmcu=atmega16 -o "Button_LED_Relay.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Button_LED_Relay.lss: Button_LED_Relay.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Button_LED_Relay.elf  >"Button_LED_Relay.lss"
	@echo 'Finished building: $@'
	@echo ' '

Button_LED_Relay.hex: Button_LED_Relay.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Button_LED_Relay.elf  "Button_LED_Relay.hex"
	@echo 'Finished building: $@'
	@echo ' '

Button_LED_Relay.eep: Button_LED_Relay.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Button_LED_Relay.elf  "Button_LED_Relay.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Button_LED_Relay.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Button_LED_Relay.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Button_LED_Relay.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm16 -cusbasp -Uflash:w:Button_LED_Relay.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Button_LED_Relay.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
