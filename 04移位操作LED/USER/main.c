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
	u32 i = 0x0001; 
	u32 j = 0;
	/* LED 端口初始化 */
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

void Delay( u32 nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
} 


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
