#include "bsp_rccclkconfig.h"

void HSE_SetSysClk(uint32_t RLLMul_x)
{
	
	ErrorStatus HSEStatus;
	
	//��RCC�Ĵ�����λ
	RCC_DeInit();
	//ʹ�� HSE
	RCC_HSEConfig(RCC_HSE_ON);
	
	HSEStatus = RCC_WaitForHSEStartUp();
	
	if(HSEStatus == SUCCESS)
	{
		//ʹ��Ԥȡָ
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div2);
		RCC_PCLK2Config(RCC_HCLK_Div1);
		
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RLLMul_x);
		RCC_PLLCmd(ENABLE);
		
		//�ȴ�PLL�ȶ�
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
		
		//ѡ��ϵͳʱ��
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

