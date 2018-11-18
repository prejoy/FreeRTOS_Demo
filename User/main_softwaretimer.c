/*
 * main_softwaretimer.c
 *
 *  Created on: 2018Äê11ÔÂ17ÈÕ
 *      Author: lenovo
 */
#include <stdlib.h>
#include <stdio.h>
#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "main.h"

#if MAINFUNC_TYPE == USE_MAIN_SOFTWARETIMER
/*LED toggle task*/
static void vTaskLed1Toggle( void * pvParameters );
#define Prio_LED1	1
static TaskHandle_t TaskHandle_LED1Toggle;
#define STK_SIZE_LED1	256

/*timer user to periodly print string*/
TimerHandle_t Timer_stdout;
void vTimer_stdoutCallBack(TimerHandle_t xTimer);
uint32_t T_counter = 0;

void vTaskLed1Toggle( void * pvParameters )
{
	while(1)
	{
		LED_Toggle (LED_NO_1);
		printf("T_counter:%d\r\n",T_counter);
		vTaskDelay( pdMS_TO_TICKS(500) );
	}
}


int main_softwaretimre(void)
{
	BaseType_t retn;
	retn = xTaskCreate(vTaskLed1Toggle,"Led1Toggle",STK_SIZE_LED1,NULL,Prio_LED1,TaskHandle_LED1Toggle);
	if(retn != pdPASS)
	{
		printf("LED toggle create failed\r\n");
	}
	Timer_stdout = xTimerCreate("Timer_stdout",pdMS_TO_TICKS(2000),pdTRUE,(void*)0,vTimer_stdoutCallBack);
	if(Timer_stdout == NULL)
	{
		printf("Timer created failed!\r\n");
	}else
	{
		if(xTimerStart(Timer_stdout,pdMS_TO_TICKS(200)) != pdPASS)
		{
			printf("Timer started failed!\r\n");
		}
	}
	vTaskStartScheduler();
	for(;;);
	return 0;
}

void vTimer_stdoutCallBack(TimerHandle_t xTimer)
{
	T_counter++;
}


#endif

