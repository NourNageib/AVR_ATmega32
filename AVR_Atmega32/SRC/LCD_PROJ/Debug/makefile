################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
LCD_PROJ.lss \

FLASH_IMAGE += \
LCD_PROJ.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: LCD_PROJ.elf secondary-outputs

# Tool invocations
LCD_PROJ.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LCD_PROJ.map -mmcu=atmega32 -o "LCD_PROJ.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LCD_PROJ.lss: LCD_PROJ.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LCD_PROJ.elf  >"LCD_PROJ.lss"
	@echo 'Finished building: $@'
	@echo ' '

LCD_PROJ.hex: LCD_PROJ.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LCD_PROJ.elf  "LCD_PROJ.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LCD_PROJ.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LCD_PROJ.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: LCD_PROJ.elf
	@echo 'Invoking: AVRDude'
	E:\IMT_Tools\SDK\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:LCD_PROJ.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LCD_PROJ.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
