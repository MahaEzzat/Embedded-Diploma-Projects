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
SevenSeg.lss \

FLASH_IMAGE += \
SevenSeg.hex \

EEPROM_IMAGE += \
SevenSeg.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: SevenSeg.elf secondary-outputs

# Tool invocations
SevenSeg.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SevenSeg.map -mmcu=atmega16 -o "SevenSeg.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SevenSeg.lss: SevenSeg.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SevenSeg.elf  >"SevenSeg.lss"
	@echo 'Finished building: $@'
	@echo ' '

SevenSeg.hex: SevenSeg.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SevenSeg.elf  "SevenSeg.hex"
	@echo 'Finished building: $@'
	@echo ' '

SevenSeg.eep: SevenSeg.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SevenSeg.elf  "SevenSeg.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SevenSeg.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 SevenSeg.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: SevenSeg.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm16 -cusbasp -Uflash:w:SevenSeg.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SevenSeg.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
