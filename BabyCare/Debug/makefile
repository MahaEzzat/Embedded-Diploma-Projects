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
BabyCare.lss \

FLASH_IMAGE += \
BabyCare.hex \

EEPROM_IMAGE += \
BabyCare.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: BabyCare.elf secondary-outputs

# Tool invocations
BabyCare.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,BabyCare.map -mmcu=atmega16 -o "BabyCare.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

BabyCare.lss: BabyCare.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S BabyCare.elf  >"BabyCare.lss"
	@echo 'Finished building: $@'
	@echo ' '

BabyCare.hex: BabyCare.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex BabyCare.elf  "BabyCare.hex"
	@echo 'Finished building: $@'
	@echo ' '

BabyCare.eep: BabyCare.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex BabyCare.elf  "BabyCare.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: BabyCare.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 BabyCare.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: BabyCare.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm16 -cusbasp -Uflash:w:BabyCare.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) BabyCare.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
