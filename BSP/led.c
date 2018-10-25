#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
	
//	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
//	GPIO_ResetBits(GPIOE,GPIO_Pin_5);
//	delay_ms(500);
	
	
}


//locat=0 :LED0
//locat=1 :LED1

void LED_Set(u8 locat,u8   TF)
{
	switch(locat)
	{
		case 0:
		{
			if(TF)GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			else GPIO_SetBits(GPIOB,GPIO_Pin_5);
			break;
		}
		case 1:
		{
			if(TF)GPIO_ResetBits(GPIOE,GPIO_Pin_5);
			else GPIO_SetBits(GPIOE,GPIO_Pin_5);
			break;
		}
	}
}

void LED_Toggle(unsigned char No)
{
	switch(No)
	{
		case 1:
		{
			LED0=!LED0;
			break;
		}
		case 2:
		{
			LED1=!LED1;
			break;
		}
		default:
		{
			//ERROR
			break;
		}
	}
}
