/***********************************************************************
文件名称：main.C
功    能:按下按键1时，PA5电压递增，利用DAC公式反推出电压并输出；PA5连接PA7利用ADC1的第7通道测量PA5的值并输出。
编写时间：2017.5.3
编 写 人：Glenn
注    意：
***********************************************************************/
#include "main.h"

void NVIC_Configuration(void); 

	
int main(void)
{
		u8 key;
		float i;
		float da = 0;
	
    NVIC_Configuration(); 
    USART_Configuration(); 
		Key_Configuration();
		Dac1_Init();
	  ADC_Configuration();
	while (1)
	{
		key = Key_Value();
		
		if(key == 1)
		{
			if(da<4000) da += 200;
			DAC_SetChannel2Data(DAC_Align_12b_R, da);
			while(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9) == 0);
			i = da*(3.3/4095);
			printf("PA5的计算电压值为：%4.2fV\n",i);
			ADC_Show();
			
		}
		else if(key == 2)
		{
			if(da>200) da -= 200;
			else da = 0;
			DAC_SetChannel2Data(DAC_Align_12b_R, da);
			while(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8) == 0);
			i = da*(3.3/4095);
			printf("PA5的计算电压值为：%4.2fV\n",i);
			ADC_Show();
		}	
	}
}

