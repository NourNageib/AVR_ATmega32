################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HKPD_config.c \
../HKPD_program.c \
../HLCD_config.c \
../HLCD_program.c \
../MDIO_program.c \
../main.c 

OBJS += \
./HKPD_config.o \
./HKPD_program.o \
./HLCD_config.o \
./HLCD_program.o \
./MDIO_program.o \
./main.o 

C_DEPS += \
./HKPD_config.d \
./HKPD_program.d \
./HLCD_config.d \
./HLCD_program.d \
./MDIO_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


