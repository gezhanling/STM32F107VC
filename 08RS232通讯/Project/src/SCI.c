
#include "main.h"

volatile unsigned char RS232_REC_Flag = 0;
volatile unsigned char RS232_buff[RS232_REC_BUFF_SIZE];
volatile unsigned int RS232_rec_counter = 0;

void USART_Configuration(void)
{ 
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO,ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_USART2,ENABLE);				
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	         
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOD, &GPIO_InitStructure);		   
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	        
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_Even;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; 
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; 
  USART_Init(USART2, &USART_InitStructure); 
	
  USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
  USART_Cmd(USART2, ENABLE); 
  USART_ClearITPendingBit(USART2, USART_IT_TC);
}

void USART2_IRQHandler(void)  
{

	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{	
		RS232_buff[RS232_rec_counter] = USART2->DR;
		RS232_rec_counter ++;
		if(RS232_rec_counter >= 2)	
		{
			if(RS232_buff[RS232_rec_counter - 2] == RS232_END_FLAG1 && RS232_buff[RS232_rec_counter - 1] == RS232_END_FLAG2) 
			{
				RS232_REC_Flag = 1;
			}
		}
		if(RS232_rec_counter > RS232_REC_BUFF_SIZE)
		{
			RS232_rec_counter = 0;
		}
	}
	if (USART_GetITStatus(USART2, USART_IT_TXE) != RESET) 
	{
        USART_ClearITPendingBit(USART2, USART_IT_TXE);           
    }
}

void RS232_Send_Data(unsigned char *send_buff,unsigned int length)
{
 	unsigned int i = 0;
	for(i = 0;i < length;i ++)
	{			
		USART2->DR = send_buff[i];
		while((USART2->SR&0X40)==0);	
	}	
}
