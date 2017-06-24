
#include "main.h"

/***********************************************************************
�������ƣ�int main(void)
��    �ܣ�
���������
���������
��дʱ�䣺2012.11.22
�� д �ˣ�
ע    �⣺��Ϊ�������ǲɼ�16ͨ���ģ����ǰ�������Щadc�ܽź��������ܸ��ã���������������
		  ������ʹ�ù�������Ҫע�⣬��������һ����λ��������ͨ�����ڸõ�λ���۲��·�仯��
		  ADC��Ӧ�ܽţ�
		  ADC_Channel_0	   		 PA0
		  ADC_Channel_1   	 	 PA1
		  ADC_Channel_2	  		 PA2
		  ADC_Channel_3	  		 PA3
		  ADC_Channel_4	  		 PA4
		  ADC_Channel_5	   		 PA5
		  ADC_Channel_6	  		 PA6
		  ADC_Channel_7	   		 PA7
		  ADC_Channel_8	   		 PB0
		  ADC_Channel_9	   		 PB1
		  ADC_Channel_10	   	 PC0
		  ADC_Channel_11	  	 PC1
		  ADC_Channel_12	  	 PC2
		  ADC_Channel_13	  	 PC3
		  ADC_Channel_14	  	 PC4
		  ADC_Channel_15	 	 PC5
		  
***********************************************************************/


int main(void)
{
	
	/* Setup STM32 system (clocks, GPIO, NVIC) */
	System_Setup();
  USART_Configuration();  
	ADC_Configuration(); 
	SysTick_Configuration();	
	while (1)
	{
 		ADC_Show();
		Delay_ms(1000);
     }
  }


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif


/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
