/***********************************************************************
�ļ����ƣ������򴮿ڷ�������
��    �ܣ����°���1������������ʾ The KEY1 is pressed !   ������2��3��4�Դ����ơ�
��дʱ�䣺2017.5.3
�� д �ˣ�Glenn
ע    �⣺��������ͨ�����򴮿ڷ������ݵ�ʵ��
***********************************************************************/
#include "main.h"

void NVIC_Configuration(void); 
int fputc(int ch, FILE *f);

int i;

int main(void)
{
    NVIC_Configuration(); 
    USART_Configuration(); 
		Key_GPIO_Config();
		
	while (1)
	{
		i = Key_Scan();
		if(i == KEY1)
		{
		printf("\r\n The KEY1 is pressed ! \r\n");
		}
		
		if(i == KEY2)
		{
		printf("\r\n The KEY2 is pressed ! \r\n");
		}
		
		if(i == KEY3)
		{
		printf("\r\n The KEY3 is pressed ! \r\n");
		}
		
		if(i == KEY4)
		{
		printf("\r\n The KEY4 is pressed ! \r\n");
		}
	}
}
int fputc(int ch, FILE *f)
{
	USART_SendData(USART2, (unsigned char) ch);
	while(USART_GetFlagStatus(USART2,USART_FLAG_TC)!=SET);
	return(ch);
}
