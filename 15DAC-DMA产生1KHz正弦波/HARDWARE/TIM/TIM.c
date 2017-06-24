#include "stm32f10x.h"
#include "TIM.h"

void TIM_Config(void)
{
	TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;//定义TIM结构体

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);//打开TIM的时钟

	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure); 
	TIM_TimeBaseStructure.TIM_Period = Sin_Out_4KHz;   //正弦波1频率设置         
	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;       
	TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;    
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
	

	TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);

	/* TIM2 enable counter */
	TIM_Cmd(TIM6, ENABLE);
}

