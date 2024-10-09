################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/sysmem.c \
../Src/timer.c \
../Src/uart1.c 

OBJS += \
./Src/main.o \
./Src/sysmem.o \
./Src/timer.o \
./Src/uart1.o 

C_DEPS += \
./Src/main.d \
./Src/sysmem.d \
./Src/timer.d \
./Src/uart1.d 


# Each subdirectory must supply rules for building sources it contributes
Src/main.o: ../Src/main.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32F030R8Tx -DSTM32 -DSTM32F0 -DSTM32F0308_DISCO -DSTM32F030x8 -c -I../Inc -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Include" -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Device/ST/STM32F0xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32F030R8Tx -DSTM32 -DSTM32F0 -DSTM32F0308_DISCO -DSTM32F030x8 -c -I../Inc -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Include" -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Device/ST/STM32F0xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/timer.o: ../Src/timer.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32F030R8Tx -DSTM32 -DSTM32F0 -DSTM32F0308_DISCO -DSTM32F030x8 -c -I../Inc -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Include" -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Device/ST/STM32F0xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/timer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/uart1.o: ../Src/uart1.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32F030R8Tx -DSTM32 -DSTM32F0 -DSTM32F0308_DISCO -DSTM32F030x8 -c -I../Inc -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Include" -I"C:/Users/saka6/STM32CubeIDE/workspace_1.6.1/chip_headers/CMSIS/Device/ST/STM32F0xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/uart1.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

