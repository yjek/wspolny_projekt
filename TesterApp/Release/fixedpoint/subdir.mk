################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../fixedpoint/fixed_func.cpp 

OBJS += \
./fixedpoint/fixed_func.o 

CPP_DEPS += \
./fixedpoint/fixed_func.d 


# Each subdirectory must supply rules for building sources it contributes
fixedpoint/%.o: ../fixedpoint/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -Wextra -pedantic -g -std=c++11 -mmcu=atxmega32a4 -DF_CPU=32000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


