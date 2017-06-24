/***********************************************************************
文件名称：Exit.C
功    能：
编写时间：
编 写 人：
注    意：
***********************************************************************/
#include "main.h"

/***********************************************************************
函数名称：EXTILine10_Configuration(void)
功    能：
输入参数：
输出参数：
编写时间：2013.4.25
编 写 人：
注    意： GPIOC10外部有上拉电阻
***********************************************************************/
void EXTI_Configuration(void)
{
	
	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef   GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;                 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;          
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;                  
	GPIO_Init(GPIOC,&GPIO_InitStructure);	
	 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource6);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource7);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource8);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource9);
	
	EXTI_ClearITPendingBit(EXTI_Line6);
	EXTI_ClearITPendingBit(EXTI_Line7);
	EXTI_ClearITPendingBit(EXTI_Line8);
	EXTI_ClearITPendingBit(EXTI_Line9);
	
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_InitStructure.EXTI_Line = EXTI_Line6 | EXTI_Line7 | EXTI_Line8 | EXTI_Line9;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

/***********************************************************************
函数名称：EXTI15_10_IRQHandler(void)
功    能：
输入参数：
输出参数：
编写时间：2013.4.25
编 写 人：
注    意： 
***********************************************************************/
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line6) != RESET)
	{
		/* Toggle LED1 */
		GPIO_ToggleBits(LED1);
		
		/* Clear the EXTI line 10 pending bit */
		EXTI_ClearITPendingBit(EXTI_Line6);
	}

	if(EXTI_GetITStatus(EXTI_Line7) != RESET)
	{
		/* Toggle LED1 */
		GPIO_ToggleBits(LED2);
		
		/* Clear the EXTI line 10 pending bit */
		EXTI_ClearITPendingBit(EXTI_Line7);
	}

	if(EXTI_GetITStatus(EXTI_Line8) != RESET)
	{
		/* Toggle LED1 */
		GPIO_ToggleBits(LED3);
		
		/* Clear the EXTI line 10 pending bit */
		EXTI_ClearITPendingBit(EXTI_Line8);
	}
	if(EXTI_GetITStatus(EXTI_Line9) != RESET)
	{
		/* Toggle LED1 */
		GPIO_ToggleBits(LED4);
		
		/* Clear the EXTI line 10 pending bit */
		EXTI_ClearITPendingBit(EXTI_Line9);
	}
}
