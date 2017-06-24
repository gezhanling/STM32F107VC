#include "stm32f10x.h"
#include "led.h"
#include "key.h"  

void delay(u32 c);
void XH(int w);
/**
  * @brief  Main program.
  * @param  None
  * @retval : None
  */
int main(void)
{ 
	/* config the sysclock to 72m */      
  SystemInit();

	/* config the led */
  LED_GPIO_Config();
	/*config key*/
	Key_GPIO_Config();


  while(1)                            
  {	 	
 	if( Key_Scan(GPIOC,GPIO_Pin_6) == KEY_ON  )
	{
			XH(1);
	}   
	
	if( Key_Scan(GPIOC,GPIO_Pin_7) == KEY_ON  )
	{
			XH(2);
	} 
	if( Key_Scan(GPIOC,GPIO_Pin_8) == KEY_ON  )
	{
			XH(3);
	}   
	
	if( Key_Scan(GPIOC,GPIO_Pin_9) == KEY_ON  )
	{
			XH(4);
	}   
 
  }
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE****/
void XH(int w)
{	
	u32 i = 0x0001; 
	int j = 0;
	int t = 0;
	int k = 0;
  
	for(k = 0; k < w; k++)
	{
			i = 0x0001;
			j = 0;
		for(t = 0; t < 4; t++)
		{
			
			if(i==1)
			{
					LED1(ON);
					delay(1000000);
			}
			else
			{
					LED1(OFF);
					delay(1000000);
			}
			if(i==2)
			{
				LED2(ON);
				delay(1000000);
			}
			else
			{
				LED2(OFF);
				delay(1000000);
			}
			if(i==4)
			{
				LED3(ON);
				delay(1000000);
			}
			else
			{
				LED3(OFF);
				delay(1000000);
			}
			if(i==8)
			{
				LED4(ON);
				delay(1000000);
			}
			else
			{
				LED4(OFF);
				delay(1000000);
			}
			i = i << 1;
			j++;
			if(j == 4)
			{
				LED4(OFF);
				delay(1000000);
				delay(1000000);
				delay(1000000);
				LED4(ON);
				LED3(ON);
				LED2(ON);
				LED1(ON);
				delay(1000000);
				LED4(OFF);
				LED3(OFF);
				LED2(OFF);
				LED1(OFF);
				delay(1000000);
				delay(1000000);
				delay(1000000);
				LED4(ON);
				LED3(ON);
				LED2(ON);
				LED1(ON);
				delay(1000000);
				LED4(OFF);
				LED3(OFF);
				LED2(OFF);
				LED1(OFF);
				delay(1000000);
				delay(1000000);
				delay(1000000);	
				LED4(ON);
				LED3(ON);
				LED2(ON);
				LED1(ON);
				delay(1000000);
				LED4(OFF);
				LED3(OFF);
				LED2(OFF);
				LED1(OFF);
				delay(1000000);
				delay(1000000);
				delay(1000000);	
			}
			}
			//i = 0x1000;
			j = 0; 
			for(t=0; t<5;t++)
			{
				
				if(i==8)
			{
				LED4(ON);
				delay(1000000);
			}
			else
			{
				LED4(OFF);
				delay(1000000);
			}
			if(i==4)
			{
				LED3(ON);
				delay(1000000);
			}
			else
			{
				LED3(OFF);
				delay(1000000);
			}
			if(i==2)
			{
				LED2(ON);
				delay(1000000);
			}
			else
			{
				LED2(OFF);
				delay(1000000);
			}
			if(i==1)
			{
					LED1(ON);
					delay(1000000);
			}
			else
			{
					LED1(OFF);
					delay(1000000);
			}
				
			i = i >> 1;
			j++;
			if(j == 5)
			{
				LED1(OFF);
				delay(1000000);
				delay(1000000);
				delay(1000000);
				LED1(ON);
				LED2(ON);
				LED3(ON);
				LED4(ON);
				delay(1000000);
				LED1(OFF);
				LED2(OFF);
				LED3(OFF);
				LED4(OFF);
				delay(1000000);
				delay(1000000);
				delay(1000000);
				LED1(ON);
				LED2(ON);
				LED3(ON);
				LED4(ON);
				delay(1000000);
				LED1(OFF);
				LED2(OFF);
				LED3(OFF);
				LED4(OFF);
				delay(1000000);
				delay(1000000);
				delay(1000000);
				LED1(ON);
				LED2(ON);
				LED3(ON);
				LED4(ON);
				delay(1000000);
				LED1(OFF);
				LED2(OFF);
				LED3(OFF);
				LED4(OFF);
				delay(1000000);
				delay(1000000);
				delay(1000000);
			}
		}
	}
}

void delay( u32 nCount)	 //???????
{
	for(; nCount != 0; nCount--);
} 
