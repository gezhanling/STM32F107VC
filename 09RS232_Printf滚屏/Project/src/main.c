/***********************************************************************
�ļ����ƣ�main.C
��    �ܣ�
��дʱ�䣺
�� д �ˣ�������Ƕ���������Ӽ����Ŷ�
ע    �⣺
***********************************************************************/
#include "main.h"


void NVIC_Configuration(void); 
int fputc(int ch, FILE *f);
void delay(u32 n);

int main(void)
{
    NVIC_Configuration(); 
    USART_Configuration();       
	while (1)
	{
		printf("\r\n this is a printf demo! \r\n");
		delay(9000000);
		
		printf("\r\n this is Tom's demo! \r\n");
		delay(9000000);
		
	  printf("\r\n this is Jay's demo! \r\n");
		delay(9000000);
	}
}

void delay(u32 n)
{
	for(; n != 0; n--);
}
