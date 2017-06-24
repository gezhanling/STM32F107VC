/***********************************************************************
�ļ����ƣ�main.C
��    �ܣ�
��дʱ�䣺
�� д �ˣ�������Ƕ���������Ӽ����Ŷ�
ע    �⣺
***********************************************************************/
#include "main.h"


void USART_Configuration(void);
void SPI_Test(void);
int main(void)
{
	
	/* Setup STM32 system (clocks, GPIO, NVIC) */
	System_Setup();
    USART_Configuration();
	SPI_FLASH_Init();
	SPI_Test(); //ע��öβ��Գ���Ҫ�ŵ�ѭ���У�flash��д�Ĵ��������޵ģ�����      
	while (1)
	{
		;
	}
}
/***********************************************************************
�������ƣ�SPI_Test(void)
��    �ܣ���������flash
���������
���������
��дʱ�䣺2012.11.22
�� д �ˣ�
ע    �⣺����flashдָ�����ݣ�Ȼ���ٶ����������ͨ��RS232���͵������ϣ�
		  ����֤��д�Ƿ���ȷ
***********************************************************************/
void SPI_Test(void)
{
	unsigned int i = 0;
	unsigned int flash_start_addr = 0;//FLASH�׵�ַ
	unsigned char WriteBuffer[256];
	unsigned char ReadBuffer[256];
	for(i = 0;i < 256;i ++)//��ʼ����д������
	{
		WriteBuffer[i] = i;
	}
	SPI_FLASH_Test();//flash���ԣ���Ҫ�Ƕ�ȡ���к�
	/* д֮ǰҪ�Ȳ��� */
	SSTF016B_Erase( flash_start_addr/SEC_SIZE , ( flash_start_addr + sizeof(WriteBuffer) )/SEC_SIZE +1 );
	df_write_open( flash_start_addr );    /* ��Ҫд�ĳ�ʼ��ַ */
	df_write( (unsigned char*)WriteBuffer,256); //��WriteBufferָ���256���ֽ�д��flash
	df_write_close();							//д�ر� 
	df_read_open(flash_start_addr);    /* ��ȡ�ĳ�ʼ��ַ */ 
	df_read(ReadBuffer, 256); //��ȡflash�е�256���ֽڷŵ�ReadBufferָ���ĵ�ַ
	RS232_Send_Data(ReadBuffer,256);//ͨRS232�����������ݷ���ȥ	
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
