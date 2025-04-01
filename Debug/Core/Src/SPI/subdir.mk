################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/SPI/spi.c 

OBJS += \
./Core/Src/SPI/spi.o 

C_DEPS += \
./Core/Src/SPI/spi.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SPI/%.o Core/Src/SPI/%.su Core/Src/SPI/%.cyclo: ../Core/Src/SPI/%.c Core/Src/SPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F722xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-SPI

clean-Core-2f-Src-2f-SPI:
	-$(RM) ./Core/Src/SPI/spi.cyclo ./Core/Src/SPI/spi.d ./Core/Src/SPI/spi.o ./Core/Src/SPI/spi.su

.PHONY: clean-Core-2f-Src-2f-SPI

