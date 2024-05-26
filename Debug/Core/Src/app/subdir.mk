################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/app/App.cpp \
../Core/Src/app/AppWrapper.cpp 

OBJS += \
./Core/Src/app/App.o \
./Core/Src/app/AppWrapper.o 

CPP_DEPS += \
./Core/Src/app/App.d \
./Core/Src/app/AppWrapper.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/app/%.o Core/Src/app/%.su Core/Src/app/%.cyclo: ../Core/Src/app/%.cpp Core/Src/app/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-app

clean-Core-2f-Src-2f-app:
	-$(RM) ./Core/Src/app/App.cyclo ./Core/Src/app/App.d ./Core/Src/app/App.o ./Core/Src/app/App.su ./Core/Src/app/AppWrapper.cyclo ./Core/Src/app/AppWrapper.d ./Core/Src/app/AppWrapper.o ./Core/Src/app/AppWrapper.su

.PHONY: clean-Core-2f-Src-2f-app

