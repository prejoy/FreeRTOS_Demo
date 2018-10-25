/*
 * main.c
 *
 *  Created on: 2018Äê10ÔÂ23ÈÕ
 *      Author: prejoy
 */
#include <stdlib.h>
#include <stdio.h>
#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "usart.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "main.h"





int main()
{
	LED_Init ();
	uart_init(115200);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

#if MAINFUNC_TYPE == 1
	main_queue();
#endif

	printf("MAIN ERROR\r\n");
	for(;;);

}
