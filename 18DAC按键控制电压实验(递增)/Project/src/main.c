/***********************************************************************
�ļ����ƣ�main.C
��    ��:���°���1ʱ��PA5��ѹ����������DAC��ʽ���Ƴ���ѹ�������PA5����PA7����ADC1�ĵ�7ͨ������PA5��ֵ�������
��дʱ�䣺2017.5.3
�� д �ˣ�Glenn
ע    �⣺
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
			printf("PA5�ļ����ѹֵΪ��%4.2fV\n",i);
			ADC_Show();
			
		}
		else if(key == 2)
		{
			if(da>200) da -= 200;
			else da = 0;
			DAC_SetChannel2Data(DAC_Align_12b_R, da);
			while(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8) == 0);
			i = da*(3.3/4095);
			printf("PA5�ļ����ѹֵΪ��%4.2fV\n",i);
			ADC_Show();
		}	
	}
}

