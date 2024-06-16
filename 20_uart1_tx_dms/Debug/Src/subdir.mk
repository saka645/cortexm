################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart1.c 

OBJS += \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart1.o 

C_DEPS += \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart1.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32F030R8Tx -DSTM32 -DSTM32F0 -DSTM32F0308_DISCO -DSTM32F030x8 -c -I../Inc -I"D:/bare_metal/workspace/chip_headers/CMSIS/Device/ST/STM32F0xx/Include" -I"D:/bare_metal/workspace/chip_headers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart1.cyclo ./Src/uart1.d ./Src/uart1.o ./Src/uart1.su

.PHONY: clean-Src

