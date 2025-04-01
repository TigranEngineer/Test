################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/UART/uart.c 

OBJS += \
./Core/Src/UART/uart.o 

C_DEPS += \
./Core/Src/UART/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/UART/%.o Core/Src/UART/%.su Core/Src/UART/%.cyclo: ../Core/Src/UART/%.c Core/Src/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F722xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-UART

clean-Core-2f-Src-2f-UART:
	-$(RM) ./Core/Src/UART/uart.cyclo ./Core/Src/UART/uart.d ./Core/Src/UART/uart.o ./Core/Src/UART/uart.su

.PHONY: clean-Core-2f-Src-2f-UART

