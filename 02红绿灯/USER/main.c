/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：LED流水灯，频率可调……         
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "led.h"

//#define    MI_ERR    (-2)

void Delay(__IO u32 nCount);

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{	
	
	//u32  i=0;
	/* LED 端口初始化 */
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

void Delay( u32 nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
} 


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
