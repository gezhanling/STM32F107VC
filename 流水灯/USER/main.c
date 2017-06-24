#include "stm32f10x.h"
#include "led.h"

void Delay(__IO u32 nCount);

int main(void)
{	
	LED_GPIO_Config();
	while (1)
	{
	  LED1 (ON);
		Delay(16000000);
		LED1( OFF );
		Delay(16000000);
		LED2(ON);
		Delay(16000000);
		LED2( OFF );
		Delay(16000000);
		LED3(ON);
		Delay(16000000);	
		LED3( OFF );
		Delay(16000000);
		LED4(ON);
		Delay(16000000);
		LED4( OFF );
		Delay(16000000);		
    }   
}

void Delay( u32 nCount)   
{
	while(nCount>0)
	{
		nCount--;
  }
} 
