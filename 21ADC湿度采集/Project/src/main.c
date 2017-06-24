
#include "main.h"

/***********************************************************************
函数名称：int main(void)
功    能：
输入参数：
输出参数：
编写时间：2012.11.22
编 写 人：
注    意：因为该配置是采集16通道的，但是板子上有些adc管脚和其他功能复用（接了其他器件）
		  所以在使用过程中需要注意，板子上有一个电位器，可以通过调节该电位器观察该路变化。
		  ADC对应管脚：
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
