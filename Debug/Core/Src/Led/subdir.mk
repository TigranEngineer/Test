################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Led/led.c 

OBJS += \
./Core/Src/Led/led.o 

C_DEPS += \
./Core/Src/Led/led.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Led/%.o Core/Src/Led/%.su Core/Src/Led/%.cyclo: ../Core/Src/Led/%.c Core/Src/Led/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F722xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Led

clean-Core-2f-Src-2f-Led:
	-$(RM) ./Core/Src/Led/led.cyclo ./Core/Src/Led/led.d ./Core/Src/Led/led.o ./Core/Src/Led/led.su

.PHONY: clean-Core-2f-Src-2f-Led

