/***********************************************************************
�ļ����ƣ�main.C
��    �ܣ�
��дʱ�䣺
�� д �ˣ�������Ƕ���������Ӽ����Ŷ�
ע    �⣺
***********************************************************************/
#include "main.h"

int main(void)
{
	
	/* Setup STM32 system (clocks, GPIO, NVIC) */
	System_Setup();
    //NVIC_Configuration(); 
    USART_Configuration();
	I2C_Configuration();
	I2C_Test(); //ע��öβ��Գ���Ҫ�ŵ�ѭ���У�EEPROM��д�Ĵ��������޵ģ�����      
	while (1)
	{
		;
	}
}
/***********************************************************************
�������ƣ�I2C_Test(void)
��    �ܣ�����EEPROM
���������
���������
��дʱ�䣺2012.11.22
�� д �ˣ�
ע    �⣺����EEPROMдָ�����ݣ�Ȼ���ٶ����������ͨ��RS232���͵������ϣ�
		  ����֤��д�Ƿ���ȷ
***********************************************************************/
void I2C_Test(void)
{
	unsigned int i = 0;
	unsigned char WriteBuffer[256];
	unsigned char ReadBuffer[256];
	for(i = 0;i < 256;i ++)//��ʼ����д������
	{
		WriteBuffer[i] = i;
	}
	I2C_Write(I2C1,ADDR_24LC02,0,WriteBuffer,sizeof(WriteBuffer));	//��EEPROMд����
	I2C_Read(I2C1,ADDR_24LC02,0,ReadBuffer,sizeof(WriteBuffer));	//��EEPROM������
	RS232_Send_Data(ReadBuffer,256);								//ͨRS232�����������ݷ���ȥ	
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
