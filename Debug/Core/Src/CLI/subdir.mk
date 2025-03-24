################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/CLI/cli_adc.c \
../Core/Src/CLI/cli_eeprom.c \
../Core/Src/CLI/cli_handlers.c \
../Core/Src/CLI/cli_input.c \
../Core/Src/CLI/cli_led.c 

OBJS += \
./Core/Src/CLI/cli_adc.o \
./Core/Src/CLI/cli_eeprom.o \
./Core/Src/CLI/cli_handlers.o \
./Core/Src/CLI/cli_input.o \
./Core/Src/CLI/cli_led.o 

C_DEPS += \
./Core/Src/CLI/cli_adc.d \
./Core/Src/CLI/cli_eeprom.d \
./Core/Src/CLI/cli_handlers.d \
./Core/Src/CLI/cli_input.d \
./Core/Src/CLI/cli_led.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/CLI/%.o Core/Src/CLI/%.su Core/Src/CLI/%.cyclo: ../Core/Src/CLI/%.c Core/Src/CLI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F722xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-CLI

clean-Core-2f-Src-2f-CLI:
	-$(RM) ./Core/Src/CLI/cli_adc.cyclo ./Core/Src/CLI/cli_adc.d ./Core/Src/CLI/cli_adc.o ./Core/Src/CLI/cli_adc.su ./Core/Src/CLI/cli_eeprom.cyclo ./Core/Src/CLI/cli_eeprom.d ./Core/Src/CLI/cli_eeprom.o ./Core/Src/CLI/cli_eeprom.su ./Core/Src/CLI/cli_handlers.cyclo ./Core/Src/CLI/cli_handlers.d ./Core/Src/CLI/cli_handlers.o ./Core/Src/CLI/cli_handlers.su ./Core/Src/CLI/cli_input.cyclo ./Core/Src/CLI/cli_input.d ./Core/Src/CLI/cli_input.o ./Core/Src/CLI/cli_input.su ./Core/Src/CLI/cli_led.cyclo ./Core/Src/CLI/cli_led.d ./Core/Src/CLI/cli_led.o ./Core/Src/CLI/cli_led.su

.PHONY: clean-Core-2f-Src-2f-CLI

