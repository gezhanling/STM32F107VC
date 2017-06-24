#include "KEY.H"
#include "stm32f10x.h"

static void Key_Delay(uint32_t nCount);

void Key_Configuration(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);	
}

unsigned char Key_Value(void)
{
	if(KEY1)
	{
		Key_Delay(0XFFFF);
		if(KEY1)
		{
			return KEY1_VALUE;
		}	
	}
	else
	if(KEY2)
	{
		Key_Delay(0XFFFF);
		if(KEY2)
		{
			return KEY2_VALUE;
		}	
	}
	else
	if(KEY3)
	{
		Key_Delay(0XFFFF);
		if(KEY3)
		{
			return KEY3_VALUE;
		}	
	}
	else
	if(KEY4)
	{
		Key_Delay(0XFFFF);
		if(KEY4)
		{
			return KEY4_VALUE;
		}	
	}
	else	
	{
		return 0;
	}
	return 0;
}

static void Key_Delay(uint32_t nCount)
{ 
  while(nCount > 0)
  { 
  	  nCount --;   
  }

}
