#include "stm32f10x.h"
#include "DAC.h"
#include "DMA.h"
#include "TIM.h"


int main(void)
{
	GPIO_Config();
	DMA_Config();
	DAC_Config();
	TIM_Config();
	while(1);
}



