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
	
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();
	
  
	while (1)
	{

	
	  LED1 (ON);
		Delay(25000000);
		LED2(ON);
		Delay(11000000);
		LED3(ON);
		Delay(3000000);			
		LED4(ON);
		Delay(1000000);	
		LED1( OFF );
		LED2( OFF );
		LED3( OFF );
		LED4( OFF );
		
		LED4 (ON);
		Delay(25000000);
		LED3(ON);
		Delay(11000000);
		LED2(ON);
		Delay(3000000);			
		LED1(ON);
		Delay(1000000);	
		LED1( OFF );
		LED2( OFF );
		LED3( OFF );
		LED4( OFF );
		
    }   
}

void Delay( u32 nCount)   //�򵥵���ʱ����
{
	while(nCount>0)
	{
		nCount--;
  }
} 


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
