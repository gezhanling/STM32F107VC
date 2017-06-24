/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ��LED��ˮ�ƣ�Ƶ�ʿɵ�����         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "led.h"

//#define    MI_ERR    (-2)

void Delay(__IO u32 nCount);

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{	
	u32 i = 0x0001; 
	u32 j = 0;
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();
  
	while (1)
	{
		
		if(i==1)
		{
				LED1(ON);
		    Delay(10000000);
		}
		else
		{
				LED1(OFF);
			  Delay(10000000);
		}
		if(i==2)
		{
			LED2(ON);
			Delay(10000000);
		}
	  else
		{
			LED2(OFF);
			Delay(10000000);
    }
		if(i==4)
		{
			LED3(ON);
			Delay(10000000);
		}
		else
		{
			LED3(OFF);
			Delay(10000000);
		}
		if(i==8)
		{
			LED4(ON);
			Delay(10000000);
		}
		else
		{
			LED4(OFF);
			Delay(10000000);
		}
		i = i << 1;
		j++;
		if(j>4)
		{
			i = 0x0001;
			j = 0;
		}
			
			
  }
}

void Delay( u32 nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
} 


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
