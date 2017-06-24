/***********************************************************************
�ļ����ƣ�NVIC.C
��    �ܣ�
��дʱ�䣺2013.4.25
�� д �ˣ�
ע    �⣺
***********************************************************************/
#include "main.h"
/***********************************************************************
�������ƣ�NVIC_Configuration(void)
��    �ܣ�����ж����ȼ�������
���������
���������
��дʱ�䣺
�� д �ˣ�
ע    �⣺
***********************************************************************/
void NVIC_Configuration(void)
{
	
	NVIC_InitTypeDef NVIC_InitStructure;
	/* Set the Vector Table base location at 0x08000000 */
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);  	

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	/* Enable and set EXTI Line0 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}