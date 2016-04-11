################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Celda.cpp \
../src/FuncDisp.cpp \
../src/FuncExpl.cpp \
../src/Hash.cpp 

OBJS += \
./src/Celda.o \
./src/FuncDisp.o \
./src/FuncExpl.o \
./src/Hash.o 

CPP_DEPS += \
./src/Celda.d \
./src/FuncDisp.d \
./src/FuncExpl.d \
./src/Hash.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


