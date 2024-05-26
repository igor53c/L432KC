################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/app/util/DebugLogger.cpp \
../Core/Src/app/util/MemoryMonitor.cpp 

OBJS += \
./Core/Src/app/util/DebugLogger.o \
./Core/Src/app/util/MemoryMonitor.o 

CPP_DEPS += \
./Core/Src/app/util/DebugLogger.d \
./Core/Src/app/util/MemoryMonitor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/app/util/%.o Core/Src/app/util/%.su Core/Src/app/util/%.cyclo: ../Core/Src/app/util/%.cpp Core/Src/app/util/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-app-2f-util

clean-Core-2f-Src-2f-app-2f-util:
	-$(RM) ./Core/Src/app/util/DebugLogger.cyclo ./Core/Src/app/util/DebugLogger.d ./Core/Src/app/util/DebugLogger.o ./Core/Src/app/util/DebugLogger.su ./Core/Src/app/util/MemoryMonitor.cyclo ./Core/Src/app/util/MemoryMonitor.d ./Core/Src/app/util/MemoryMonitor.o ./Core/Src/app/util/MemoryMonitor.su

.PHONY: clean-Core-2f-Src-2f-app-2f-util

