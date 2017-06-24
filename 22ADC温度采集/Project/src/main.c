
/***********************************************************************
函数名称：int main(void)
功    能：利用PT100温度变送器和一个150欧姆电阻
           产生电压信号，连接到PC3，利用ADC转换成电压，最后根据对应的公式
					 计算出温度
编写时间：2017.5.4
编 写 人：Glenn
注    意：
问    题：不能用系统滴答定时器延时。
***********************************************************************/

#include "main.h"



int main(void)
{
	System_Setup();
  USART_Configuration();  
	ADC_Configuration(); 
  //SysTick_Configuration();	
	while (1)
	{
		ADC_Show();
		delay(0xffffffff);
	}
}

