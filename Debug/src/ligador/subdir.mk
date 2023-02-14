################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ligador/ligador.c \
../src/ligador/lista.c \
../src/ligador/main.c 

OBJS += \
./src/ligador/ligador.o \
./src/ligador/lista.o \
./src/ligador/main.o 

C_DEPS += \
./src/ligador/ligador.d \
./src/ligador/lista.d \
./src/ligador/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/ligador/%.o: ../src/ligador/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


