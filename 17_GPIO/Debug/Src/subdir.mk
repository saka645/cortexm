################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Src/main.s 

C_SRCS += \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

S_DEPS += \
./Src/main.d 

C_DEPS += \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/main.o: ../Src/main.s Src/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0 -g3 -c -x assembler-with-cpp -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"
Src/syscalls.o: ../Src/syscalls.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32F030R8Tx -DSTM32 -DSTM32F0 -DSTM32F0308_DISCO -c -I../Inc -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32F030R8Tx -DSTM32 -DSTM32F0 -DSTM32F0308_DISCO -c -I../Inc -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Device/ST/STM32F0xx/Include" -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

