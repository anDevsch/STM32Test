#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"

#if 0
#define GPIOB_ODR_Addr    (GPIOB_BASE+0x0C)
#define PBout(n) 					*(unsigned int*)((GPIOB_ODR_Addr & 0xF0000000)+0x02000000+((GPIOB_ODR_Addr & 0x00FFFFFF)<<5)+(n<<2))
	
#define GPIOA_IDR_Addr    (GPIOA_BASE+0x08)
#define PAin(n)  					*(unsigned int*)((GPIOA_IDR_Addr & 0xF0000000)+0x02000000+((GPIOA_IDR_Addr & 0x00FFFFFF)<<5)+(n<<2))

#define GPIOC_IDR_Addr    (GPIOC_BASE+0x08)
#define PCin(n)  					*(unsigned int*)((GPIOC_IDR_Addr & 0xF0000000)+0x02000000+((GPIOC_IDR_Addr & 0x00FFFFFF)<<5)+(n<<2))
#endif

int main(void)
{
//	USART_Config();
//	
//	Usart_SendByte(DEBUG_USARTx,0xFFFF);
	while(1)
	{
		
		return 0;
	}
}

