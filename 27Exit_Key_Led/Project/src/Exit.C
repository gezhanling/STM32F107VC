/***********************************************************************
�ļ����ƣ�Exit.C
��    �ܣ�
��дʱ�䣺
�� д �ˣ�
ע    �⣺
***********************************************************************/
#include "main.h"

/***********************************************************************
�������ƣ�EXTILine10_Configuration(void)
��    �ܣ�
���������
���������
��дʱ�䣺2013.4.25
�� д �ˣ�
ע    �⣺ GPIOC10�ⲿ����������
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
�������ƣ�EXTI15_10_IRQHandler(void)
��    �ܣ�
���������
���������
��дʱ�䣺2013.4.25
�� д �ˣ�
ע    �⣺ 
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