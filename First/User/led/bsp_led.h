#ifndef __BSP_LED_H
#define __BSP_LED_H

#include"stm32f10x.h"

#define LED_GPIO_PIN      GPIO_Pin_1
#define LED_GPIO_PORT     GPIOB
#define LED_GPIO_CLK      RCC_APB2Periph_GPIOB


#define ON     1
#define OFF    0

#define LED_O(a)   if(a) \
										GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN); \
									 else \
										GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN);

//与0异或不变，与1异或改变
#define LED_O_TOGGLE        {LED_GPIO_PORT->ODR ^= LED_GPIO_PIN;}

void LED_GPIO_Config(void);
									 
#endif




