#include "key.h" 

 void Delay(__IO u32 nCount)
{
  for(; nCount != 0; nCount--);
} 
void Key_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

u8 Key_Scan(GPIO_TypeDef* GPIOx,u16 GPIO_Pin)
{			
   	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == KEY_ON|
		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7) == KEY_ON|
		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) == KEY_ON|
		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) == KEY_ON) 
	  {	   
	  	Delay(10000);		
	   		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == KEY_ON 
					|GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7) == KEY_ON
				|GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) == KEY_ON|
				GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) == KEY_ON)  
					{	 
						while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == KEY_ON|
							GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7) == KEY_ON|
						GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) == KEY_ON|
						GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) == KEY_ON);   
			 			return 	KEY_ON;	 
					}
			else
					return KEY_OFF;
		}
	else
		return KEY_OFF;
}
