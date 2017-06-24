/***********************************************************************
�ļ����ƣ�main.C
��    �ܣ�
��дʱ�䣺
�� д �ˣ�������Ƕ���������Ӽ����Ŷ�
ע    �⣺
***********************************************************************/
#include "main.h"

void NVIC_Configuration(void); 
void delay(int i);

unsigned char array[3]={0x31,0x3F,0x3B} ;
//unsigned char ch , ch1;



int main(void)
{
	
	/* Setup STM32 system (clocks, GPIO, NVIC) */
	  System_Setup();
    NVIC_Configuration(); 
    USART_Configuration();  
    LED_Configuration();
	while (1)
	{
			
		//RS232_Send_Data(RS232_buff,RS232_rec_counter); //�����յ������ݷ��ͳ�ȥ
//if(RS232_REC_Flag == 1)//RS232���յ�������
		//{
			//RS232_REC_Flag = 0;
			//RS232_Send_Data(RS232_buff,RS232_rec_counter); //�����յ������ݷ��ͳ�ȥ
		//RS232_Send_Data(array,3);
			//RS232_rec_counter = 0;	//�����꽫���ռ���������
		//}
		if(RS232_REC_Flag == 1)//RS232���յ�������
		{
			RS232_REC_Flag = 0;
			//RS232_Send_Data(RS232_buff,RS232_rec_counter); //�����յ������ݷ��ͳ�ȥ
			//LED1_ON;
			//ch = RS232_buff[0];
			//ch1 = RS232_buff[3];
			if(RS232_buff[0] == '1')
			{
				LED1_ON;
				delay(10000000);
			}
			
			if(RS232_buff[3] == '2')
			{
				LED1_OFF;
				delay(10000000);
			}
			RS232_Send_Data(array,3);
			RS232_rec_counter = 0;	//�����꽫���ռ���������
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
void delay(int i)
{
	while(i!=0)
		i--;
}
