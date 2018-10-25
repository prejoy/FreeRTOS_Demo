################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/main.c \
../User/main_queue.c \
../User/stm32f10x_it.c \
../User/system_stm32f10x.c 

OBJS += \
./User/main.o \
./User/main_queue.o \
./User/stm32f10x_it.o \
./User/system_stm32f10x.o 

C_DEPS += \
./User/main.d \
./User/main_queue.d \
./User/stm32f10x_it.d \
./User/system_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\newlib" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\FreeRTOS" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\FreeRTOS\include" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\FreeRTOS\port" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\CMSIS\CM3\CoreSupport" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\CMSIS\CM3\DeviceSupport\ST\STM32F10x" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\CMSIS\CM3\DeviceSupport\ST\STM32F10x\startup" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\STM32F10x_StdPeriph_Driver\inc" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\BSP" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\User" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


