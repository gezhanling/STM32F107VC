/***********************************************************************
文件名称：main.C
功    能：
编写时间：
编 写 人：北京智嵌物联网电子技术团队
注    意：
***********************************************************************/
#include "main.h"

int main(void)
{
	
	/* Setup STM32 system (clocks, GPIO, NVIC) */
	System_Setup();
    //NVIC_Configuration(); 
    USART_Configuration();
	I2C_Configuration();
	I2C_Test(); //注意该段测试程序不要放到循环中，EEPROM擦写的次数是有限的！！！      
	while (1)
	{
		;
	}
}
/***********************************************************************
函数名称：I2C_Test(void)
功    能：测试EEPROM
输入参数：
输出参数：
编写时间：2012.11.22
编 写 人：
注    意：先向EEPROM写指定数据，然后再读出来，最后通过RS232发送到电脑上，
		  以验证读写是否正确
***********************************************************************/
void I2C_Test(void)
{
	unsigned int i = 0;
	unsigned char WriteBuffer[256];
	unsigned char ReadBuffer[256];
	for(i = 0;i < 256;i ++)//初始化待写数据区
	{
		WriteBuffer[i] = i;
	}
	I2C_Write(I2C1,ADDR_24LC02,0,WriteBuffer,sizeof(WriteBuffer));	//向EEPROM写数据
	I2C_Read(I2C1,ADDR_24LC02,0,ReadBuffer,sizeof(WriteBuffer));	//向EEPROM读数据
	RS232_Send_Data(ReadBuffer,256);								//通RS232将读到的数据发出去	
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
