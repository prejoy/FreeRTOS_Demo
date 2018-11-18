/*
 * main_queue.c
 *
 *  Created on: 2018年10月24日
 *      Author: prejoy
 */
#include <stdlib.h>
#include <stdio.h>
#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "main.h"

#if MAINFUNC_TYPE == USE_MAIN_QUEUE


/*queue data type */
typedef struct A_Message
{
	char ucMessageID;
	char ucData[ 20 ];
} AMessage;

#define QUEUE_LENGTH 		5
#define QUEUE_ITEM_SIZE 	(sizeof( AMessage ))


static void vTaskLed1( void * pvParameters );
#define Prio_LED1	1
static TaskHandle_t TaskHandle_LED1;
#define STK_SIZE_LED1	256

static void vTaskLed2( void * pvParameters );
#define Prio_LED2	1
static TaskHandle_t TaskHandle_LED2;
#define STK_SIZE_LED2	256

static void vLED_Queue_Send( void * pvParameters );
#define Prio_LED_Queue	2
static TaskHandle_t TaskHandle_LED_Queue;
#define STK_SIZE_LED_Queue	1024



void vTaskLed1( void * pvParameters )
{
	QueueHandle_t LED_Queue;
	AMessage LED1_Meseg;

	LED_Queue = (QueueHandle_t)pvParameters;

	while(1)
	{
		if(xQueueReceive(LED_Queue,&LED1_Meseg,portMAX_DELAY)!=pdPASS)
		{
			printf("LED1 queue receive fail\r\n");
		}else
		{
			if(LED1_Meseg.ucMessageID==LED_NO_1)
			LED_Toggle (LED_NO_1);
		}

		vTaskDelay( pdMS_TO_TICKS(500) );
	}

}

void vTaskLed2( void * pvParameters )
{
	QueueHandle_t LED_Queue;
	AMessage LED2_Meseg;

	LED_Queue = (QueueHandle_t)pvParameters;

	while(1)
	{
		if(xQueueReceive(LED_Queue,&LED2_Meseg,portMAX_DELAY)!=pdPASS)
		{
			printf("LED2 queue receive fail\r\n");
		}else
		{
			if(LED2_Meseg.ucMessageID==LED_NO_2)
			LED_Toggle (LED_NO_2);
		}

		vTaskDelay( pdMS_TO_TICKS(500) );
	}

}

void vLED_Queue_Send( void * pvParameters )
{
	QueueHandle_t LED_Queue;
	AMessage LedMeseg;

	LED_Queue = (QueueHandle_t)pvParameters;
	LedMeseg.ucMessageID = LED_NO_1;

	while(1)
	{
		LedMeseg.ucMessageID = LED_NO_1 + LED_NO_2 - LedMeseg.ucMessageID;
		if(xQueueSend(LED_Queue,&LedMeseg,10)!=pdPASS)
		{
			printf("Led Queue send fail\r\n");
		}
		else
		{
			printf("LED Queue send to LED%d\r\n",(LedMeseg.ucMessageID));		//if STK_size == 512*4 堆栈会溢出导致HardFault_Handler异常
		}
		vTaskDelay(pdMS_TO_TICKS(250));
	}
}



int main_queue(void)
{
	BaseType_t retn;
	QueueHandle_t LED_Queue;
	LED_Queue=xQueueCreate(QUEUE_LENGTH,QUEUE_ITEM_SIZE);
	if(LED_Queue == NULL )
	{
		printf("LED_Queue created fail\r\n");
	}

	retn = xTaskCreate( vTaskLed1, "Task_Led1", STK_SIZE_LED1, (void *)LED_Queue, Prio_LED1, &TaskHandle_LED1 );
	if(retn!=pdPASS)
	{
		printf("Task_Led1 create fail\r\n");
	}

	retn = xTaskCreate( vTaskLed2, "Task_Led2", STK_SIZE_LED2, (void *)LED_Queue, Prio_LED_Queue, &TaskHandle_LED_Queue );
	if(retn!=pdPASS)
	{
		printf("Task_Led2 create fail\r\n");
	}

	retn = xTaskCreate( vLED_Queue_Send, "Task_LedQueue Send", STK_SIZE_LED_Queue, (void *)LED_Queue, Prio_LED2, &TaskHandle_LED2 );
	if(retn!=pdPASS)
	{
		printf("Task_LedQueue Send create fail\r\n");
	}

	vTaskStartScheduler();
	for(;;);
	return 0;
}


#endif

