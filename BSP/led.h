#ifndef __LED_H__
#define __LED_H__

#include "stm32f10x.h"
#include "sys.h"

#define LED0	PBout(5)
#define LED1	PEout(5)

#define LED_NO_1	1
#define LED_NO_2	2

void LED_Init(void);
void LED_Set(u8 locat,u8  TF);
void LED_Toggle(unsigned char No);

#endif

