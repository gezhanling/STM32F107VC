/***********************************************************************
文件名称：main.C
功    能：
编写时间：
编 写 人：北京智嵌物联网电子技术团队
注    意：
***********************************************************************/

#include "main.h"

void USART_Configuration(void);
void SPI_Test(void);
void EXTI_Configuration(void);
void delay(__IO u32 nCount);

int i = 1824/16;
unsigned char k ;
unsigned int flash_start_addr = 0;//FLASH首地址
unsigned char ReadBuffer[1];
extern unsigned char t[1];

int main(void)
{
	
	/* Setup STM32 system (clocks, GPIO, NVIC) */
	System_Setup();
  USART_Configuration();
	SPI_FLASH_Init();
	LED_Configuration();	
  Key_Configuration();
	EXTI_Configuration();
	NVIC_Configuration();
	ADC_Configuration();

	df_read_open(flash_start_addr);
	df_read(ReadBuffer, 1); //读取flash中的256个字节放到ReadBuffer指定的地址
	RS232_Send_Data(ReadBuffer,1);//通RS232将读到的数据发出去	
	 ADC_Show();
	RS232_Send_Data(t,1);
     if(t[0] < ReadBuffer[0])
		 {LED1_ON;}
	while (1)
	{
		;
	}
}
/***********************************************************************
函数名称：SPI_Test(void)
功    能：测试外扩flash
输入参数：
输出参数：
编写时间：2012.11.22
编 写 人：
注    意：先向flash写指定数据，然后再读出来，最后通过RS232发送到电脑上，
		  以验证读写是否正确
***********************************************************************/
void SPI_Test(void)
{
	
	unsigned char WriteBuffer[1];
	
	
		WriteBuffer[0] = i;
	
	SPI_FLASH_Test();//flash测试，主要是读取序列号
	/* 写之前要先擦除 */
	SSTF016B_Erase( flash_start_addr/SEC_SIZE , ( flash_start_addr + sizeof(WriteBuffer) )/SEC_SIZE +1 );
	df_write_open( flash_start_addr );    /* 打开要写的初始地址 */
	df_write( (unsigned char*)WriteBuffer,1); //将WriteBuffer指向的256个字节写入flash
	df_write_close();							//写关闭 
	df_read_open(flash_start_addr);    /* 读取的初始地址 */ 
	df_read(ReadBuffer, 1); //读取flash中的256个字节放到ReadBuffer指定的地址
	RS232_Send_Data(ReadBuffer,1);//通RS232将读到的数据发出去	
}





void EXTI_Configuration(void)
{
	
	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef   GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;                 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;          
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;                  
	GPIO_Init(GPIOC,&GPIO_InitStructure);	
	 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource6);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource7);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource8);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource9);
	
	EXTI_ClearITPendingBit(EXTI_Line6);
	EXTI_ClearITPendingBit(EXTI_Line7);
	EXTI_ClearITPendingBit(EXTI_Line8);
	EXTI_ClearITPendingBit(EXTI_Line9);
	
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_InitStructure.EXTI_Line = EXTI_Line6 | EXTI_Line7 | EXTI_Line8 | EXTI_Line9;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}


void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line6) != RESET)
	{	delay(800);
		if(EXTI_GetITStatus(EXTI_Line6) != RESET)
		{
		/* Toggle LED1 */
		i = i+4.69;
		/* Clear the EXTI line 10 pending bit */
		SPI_Test(); //注意该段测试程序不要放到循环中，flash擦写的次数是有限的！！！   
		}
		EXTI_ClearITPendingBit(EXTI_Line6);
	}

	if(EXTI_GetITStatus(EXTI_Line7) != RESET)
	{  delay(800);
		if(EXTI_GetITStatus(EXTI_Line7) != RESET)
		{
		/* Toggle LED1 */
		i = i-4.69;
		SPI_Test(); //注意该段测试程序不要放到循环中，flash擦写的次数是有限的！！！   
		/* Clear the EXTI line 10 pending bit */
		}
		EXTI_ClearITPendingBit(EXTI_Line7);
	}

// 	if(EXTI_GetITStatus(EXTI_Line8) != RESET)
// 	{
// 		/* Toggle LED1 */
// 		GPIO_ToggleBits(LED3);
// 		
// 		/* Clear the EXTI line 10 pending bit */
// 		EXTI_ClearITPendingBit(EXTI_Line8);
// 	}
// 	if(EXTI_GetITStatus(EXTI_Line9) != RESET)
// 	{
// 		/* Toggle LED1 */
// 		GPIO_ToggleBits(LED4);
// 		
// 		/* Clear the EXTI line 10 pending bit */
// 		EXTI_ClearITPendingBit(EXTI_Line9);
// 	}
}

void delay(__IO u32 nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
} 
