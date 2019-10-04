################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayEmployees.c \
../src/TP2.c \
../src/lib_tp2.c 

OBJS += \
./src/ArrayEmployees.o \
./src/TP2.o \
./src/lib_tp2.o 

C_DEPS += \
./src/ArrayEmployees.d \
./src/TP2.d \
./src/lib_tp2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


