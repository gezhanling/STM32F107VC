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
	
	//u32  i=0;
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();
	

	while (1)
	{
		//if(i%2==0)
		//{
		LED4( ON );
		LED2( ON );
		Delay(7000000);
		LED2( OFF );   
		Delay(500000);
		LED2( ON );
		Delay(500000);
		LED2( OFF ); 
		Delay(500000);
		LED2( ON );
    Delay(500000);			
		LED2( OFF ); 
		Delay(500000);		
		LED2( ON );
		Delay(500000);
		LED2( OFF );
		LED4( OFF ); 	
		//}
		//else
		//{
		LED1( ON );
		LED3( ON );
		Delay(7000000);
		LED3( OFF );   
		Delay(500000);
		LED3( ON );
		Delay(500000);
		LED3( OFF ); 
		Delay(500000);
		LED3( ON );
    Delay(500000);			
		LED3( OFF ); 
		Delay(500000);		
		LED3( ON );
		Delay(500000);
		LED3( OFF );
    LED1( OFF ); 			
	  //}
		//	i++;  
   }
}

void Delay( u32 nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
} 


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
