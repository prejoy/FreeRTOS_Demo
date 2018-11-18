/*
 * main.h
 *
 *  Created on: 2018Äê10ÔÂ24ÈÕ
 *      Author: prejoy
 */

#ifndef USER_MAIN_H_
#define USER_MAIN_H_
#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "usart.h"

#define MAINFUNC_TYPE	USE_MAIN_SOFTWARETIMER

#define USE_MAIN_QUEUE  1
#define USE_MAIN_SOFTWARETIMER  2

#if MAINFUNC_TYPE == USE_MAIN_QUEUE
	extern int main_queue(void);
#elif MAINFUNC_TYPE == USE_MAIN_SOFTWARETIMER
	extern int main_softwaretimre(void);
#endif




#endif /* USER_MAIN_H_ */
