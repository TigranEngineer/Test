################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/LED/led.c 

OBJS += \
./Core/Src/LED/led.o 

C_DEPS += \
./Core/Src/LED/led.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/LED/%.o Core/Src/LED/%.su Core/Src/LED/%.cyclo: ../Core/Src/LED/%.c Core/Src/LED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F722xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-LED

clean-Core-2f-Src-2f-LED:
	-$(RM) ./Core/Src/LED/led.cyclo ./Core/Src/LED/led.d ./Core/Src/LED/led.o ./Core/Src/LED/led.su

.PHONY: clean-Core-2f-Src-2f-LED

