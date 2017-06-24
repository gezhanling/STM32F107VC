/***********************************************************************
文件名称：main.C
功    能：
编写时间：
编 写 人：北京智嵌物联网电子技术团队
注    意：
***********************************************************************/
#include "main.h"

void NVIC_Configuration(void); 


	
int main(void)
{
		u8 key;
		float i;
		
    NVIC_Configuration(); 
    USART_Configuration(); 
		Key_Configuration();
		Dac1_Init();
	while (1)
	{
		key = Key_Value();
		
		if(key == 1)
		{
		
			DAC_SetChannel2Data(DAC_Align_12b_R, 623);
			while(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9) == 0);
			i = 623*(3.3/4095);
			printf("PA5的电压值为：%4.2fV\n",i);
		}
		else if(key == 2)
		{
		
			DAC_SetChannel2Data(DAC_Align_12b_R, 1246);
			while(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8) == 0);
			i = 1246*(3.3/4095);
			printf("PA5的电压值为：%4.2fV\n",i);
		}
				else if(key == 3)
		{
		
			DAC_SetChannel2Data(DAC_Align_12b_R, 1869);
			while(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7) == 0);
			i = 1869*(3.3/4095);
			printf("PA5的电压值为：%4.2fV\n",i);
		}
						else if(key == 4)
		{
		
			DAC_SetChannel2Data(DAC_Align_12b_R, 2492);
			while(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6) == 0);
			i = 2492*(3.3/4095);
			printf("PA5的电压值为：%4.2fV\n",i);
		}
	}
}
