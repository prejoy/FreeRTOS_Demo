################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/CM3/CoreSupport/core_cm3.c 

OBJS += \
./CMSIS/CM3/CoreSupport/core_cm3.o 

C_DEPS += \
./CMSIS/CM3/CoreSupport/core_cm3.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/CM3/CoreSupport/%.o: ../CMSIS/CM3/CoreSupport/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F10X_HD -DUSE_STDPERIPH_DRIVER -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\newlib" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\FreeRTOS" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\FreeRTOS\include" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\FreeRTOS\port" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\CMSIS\CM3\CoreSupport" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\CMSIS\CM3\DeviceSupport\ST\STM32F10x" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\CMSIS\CM3\DeviceSupport\ST\STM32F10x\startup" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\STM32F10x_StdPeriph_Driver\inc" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\BSP" -I"D:\Studying_software\eclipse_stm32projs\test1\FreeRTOS_Demo\User" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


