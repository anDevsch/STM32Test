#include "bsp_rccclkconfig.h"

void HSE_SetSysClk(uint32_t RLLMul_x)
{
	
	ErrorStatus HSEStatus;
	
	//把RCC寄存器复位
	RCC_DeInit();
	//使能 HSE
	RCC_HSEConfig(RCC_HSE_ON);
	
	HSEStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStatus == SUCCESS)
	{
		//使能预取指
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div2);
		RCC_PCLK2Config(RCC_HCLK_Div1);
		
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RLLMul_x);
		RCC_PLLCmd(ENABLE);
		
		//等待PLL稳定
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
		
		//选择系统时钟
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource() != 0x08);
		
	}
	else
	{
		
	}
}


void MCO_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);
}

