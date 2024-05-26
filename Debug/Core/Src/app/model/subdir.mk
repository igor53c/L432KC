################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/app/model/LedController.cpp \
../Core/Src/app/model/TimerManager.cpp 

OBJS += \
./Core/Src/app/model/LedController.o \
./Core/Src/app/model/TimerManager.o 

CPP_DEPS += \
./Core/Src/app/model/LedController.d \
./Core/Src/app/model/TimerManager.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/app/model/%.o Core/Src/app/model/%.su Core/Src/app/model/%.cyclo: ../Core/Src/app/model/%.cpp Core/Src/app/model/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-app-2f-model

clean-Core-2f-Src-2f-app-2f-model:
	-$(RM) ./Core/Src/app/model/LedController.cyclo ./Core/Src/app/model/LedController.d ./Core/Src/app/model/LedController.o ./Core/Src/app/model/LedController.su ./Core/Src/app/model/TimerManager.cyclo ./Core/Src/app/model/TimerManager.d ./Core/Src/app/model/TimerManager.o ./Core/Src/app/model/TimerManager.su

.PHONY: clean-Core-2f-Src-2f-app-2f-model

