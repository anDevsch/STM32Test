#ifndef __BSP_RCCCLKCONFIG_H
#define __BSP_RCCCLKCONFIG_H

#include "stm32f10x.h"
void HSE_SetSysClk(uint32_t RLLMul_x);
void MCO_GPIO_Config(void);
#endif

