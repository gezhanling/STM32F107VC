/***********************************************************************
�ļ����ƣ�RS232����LDED
��    �ܣ�ͨ��������������1?;ʱ��LED1�򿪣�����2?;ʱ��LED1�رա�
��дʱ�䣺2017.5.3
�� д �ˣ�Glenn
ע    �⣺?;��ʾ�ַ����Ľ�����־��
***********************************************************************/

#include "main.h"

void NVIC_Configuration(void); 
void Delay( u32 nCount);
void LED_GPIO_Config(void);

char ch=0;   //define a variable : ch.

int main(void)
{
	  System_Setup();
    NVIC_Configuration(); 
    USART_Configuration(); 
    LED_GPIO_Config();	
	while (1)
	{
		if(RS232_REC_Flag == 1)  //"RS232_REC_Flag == 1" means serial port (RS232) receives a data.
		{
			RS232_REC_Flag = 0;    // make the flag bit "RS232_REC_Flag" go back to zero to handle the next data.
			ch=RS232_buff[0];      
			switch(ch)
			{
				case '1':
					LED1(ON);
					break;
				case '2':
					LED1(OFF);
					break;
				default:
					break;				
			}
			RS232_rec_counter = 0;	//  receiving counter "RS232_rec_counter" go back to zero when the transfer is complete.
			}
	}
}


void Delay( u32 nCount)	 
{
	for(; nCount != 0; nCount--);
} 

