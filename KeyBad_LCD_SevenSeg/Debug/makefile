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
KeyBad_LCD_SevenSeg.lss \

FLASH_IMAGE += \
KeyBad_LCD_SevenSeg.hex \

EEPROM_IMAGE += \
KeyBad_LCD_SevenSeg.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: KeyBad_LCD_SevenSeg.elf secondary-outputs

# Tool invocations
KeyBad_LCD_SevenSeg.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,KeyBad_LCD_SevenSeg.map -mmcu=atmega16 -o "KeyBad_LCD_SevenSeg.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

KeyBad_LCD_SevenSeg.lss: KeyBad_LCD_SevenSeg.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S KeyBad_LCD_SevenSeg.elf  >"KeyBad_LCD_SevenSeg.lss"
	@echo 'Finished building: $@'
	@echo ' '

KeyBad_LCD_SevenSeg.hex: KeyBad_LCD_SevenSeg.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex KeyBad_LCD_SevenSeg.elf  "KeyBad_LCD_SevenSeg.hex"
	@echo 'Finished building: $@'
	@echo ' '

KeyBad_LCD_SevenSeg.eep: KeyBad_LCD_SevenSeg.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex KeyBad_LCD_SevenSeg.elf  "KeyBad_LCD_SevenSeg.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: KeyBad_LCD_SevenSeg.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 KeyBad_LCD_SevenSeg.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: KeyBad_LCD_SevenSeg.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm16 -cusbasp -Uflash:w:KeyBad_LCD_SevenSeg.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) KeyBad_LCD_SevenSeg.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
