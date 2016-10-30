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
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
BlueModuleATmega8.lss \

FLASH_IMAGE += \
BlueModuleATmega8.hex \

EEPROM_IMAGE += \
BlueModuleATmega8.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: BlueModuleATmega8.elf secondary-outputs

# Tool invocations
BlueModuleATmega8.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,BlueModuleATmega8.map -mmcu=atmega8 -o "BlueModuleATmega8.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

BlueModuleATmega8.lss: BlueModuleATmega8.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S BlueModuleATmega8.elf  >"BlueModuleATmega8.lss"
	@echo 'Finished building: $@'
	@echo ' '

BlueModuleATmega8.hex: BlueModuleATmega8.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex BlueModuleATmega8.elf  "BlueModuleATmega8.hex"
	@echo 'Finished building: $@'
	@echo ' '

BlueModuleATmega8.eep: BlueModuleATmega8.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex BlueModuleATmega8.elf  "BlueModuleATmega8.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: BlueModuleATmega8.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega8 BlueModuleATmega8.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) BlueModuleATmega8.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
