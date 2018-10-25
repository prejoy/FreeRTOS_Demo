################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/delay.c \
../BSP/led.c \
../BSP/sys.c \
../BSP/usart.c 

OBJS += \
./BSP/delay.o \
./BSP/led.o \
./BSP/sys.o \
./BSP/usart.o 

C_DEPS += \
./BSP/delay.d \
./BSP/led.d \
./BSP/sys.d \
./BSP/usart.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/%.o: ../BSP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\newlib" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\FreeRTOS" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\FreeRTOS\include" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\FreeRTOS\port" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\CMSIS\CM3\CoreSupport" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\CMSIS\CM3\DeviceSupport\ST\STM32F10x" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\CMSIS\CM3\DeviceSupport\ST\STM32F10x\startup" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\STM32F10x_StdPeriph_Driver\inc" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\BSP" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\User" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


