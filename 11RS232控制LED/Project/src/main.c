/***********************************************************************
文件名称：main.C
功    能：
编写时间：
编 写 人：北京智嵌物联网电子技术团队
注    意：
***********************************************************************/
#include "main.h"

void NVIC_Configuration(void); 
void Delay( u32 nCount);
void LED_GPIO_Config(void);

char ch=0;
int i=0;

int main(void)
{
	
	/* Setup STM32 system (clocks, GPIO, NVIC) */
	 System_Setup();
    NVIC_Configuration(); 
    USART_Configuration(); 
   LED_GPIO_Config();	
	while (1)
	{
		if(RS232_REC_Flag == 1)//RS232接收到了数据
		{
			RS232_REC_Flag = 0;
			ch=RS232_buff[0]-48;
			RS232_Send_Data(RS232_buff,RS232_rec_counter); //将接收到的数据发送出去
			for(i=0; i < ch; i++)
			{
				GPIO_ResetBits(GPIOE, GPIO_Pin_9 );
				Delay(9000000);
				GPIO_SetBits(GPIOE, GPIO_Pin_9 );
				Delay(9000000);
				GPIO_ResetBits(GPIOE, GPIO_Pin_11 );
				Delay(9000000);
				GPIO_SetBits(GPIOE, GPIO_Pin_11 );
				Delay(9000000);
				GPIO_ResetBits(GPIOE, GPIO_Pin_13 );
				Delay(9000000);
				GPIO_SetBits(GPIOE, GPIO_Pin_13 );
				Delay(9000000);
				GPIO_ResetBits(GPIOE, GPIO_Pin_14 );
				Delay(9000000);
				GPIO_SetBits(GPIOE, GPIO_Pin_14 );
				Delay(9000000);
			}
			
			
			RS232_rec_counter = 0;	//发送完将接收计数器清零
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


void Delay( u32 nCount)	 
{
	for(; nCount != 0; nCount--);
} 

void LED_GPIO_Config(void)
{		
	/*????GPIO_InitTypeDef??????*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*??GPIOC?????*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOE, ENABLE); 

	/*??????GPIOC??*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13  | GPIO_Pin_14;	

	/*?????????????*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*???????50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*?????,???GPIOC*/
  	GPIO_Init(GPIOE, &GPIO_InitStructure);		  

	/* ????led?	*/
	GPIO_SetBits(GPIOE, GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14);	 
}