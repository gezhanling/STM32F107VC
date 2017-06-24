/***********************************************************************
文件名称：main.C
功    能：
编写时间：
编 写 人：北京智嵌物联网电子技术团队
注    意：
***********************************************************************/
#include "main.h"

void NVIC_Configuration(void); 


//unsigned char array[6]={0x31,0x3F,0x3B,0x32,0x3F,0x3B} ;
unsigned char array[3] = "1?;" ;
unsigned char array1[3] = "2?;";


void delay(int i)
{
	while(i != 0)
		i--;
}

int main(void)
{
	
	/* Setup STM32 system (clocks, GPIO, NVIC) */
	System_Setup();
  NVIC_Configuration(); 
  USART_Configuration();  
  LED_Configuration();
	RS232_Send_Data(array,3);
	while (1)
	{
			
		//RS232_Send_Data(RS232_buff,RS232_rec_counter); //将接收到的数据发送出去 
		//if(RS232_REC_Flag == 1)//RS232接收到了数据
		//{
			//RS232_REC_Flag = 0;
			//RS232_Send_Data(RS232_buff,RS232_rec_counter); //将接收到的数据发送出去
			//LED1_ON;
			//RS232_rec_counter = 0;	//发送完将接收计数器清零
		//}
		if(RS232_REC_Flag == 1)
		{
		  RS232_REC_Flag = 0;
			RS232_Send_Data(array1,3);
			delay(100000);
			RS232_Send_Data(array,3);
			delay(100000);
      RS232_rec_counter = 0;	
		}
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
