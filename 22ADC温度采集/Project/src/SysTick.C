/***********************************************************************
文件名称：SysTick.C
功    能：
编写时间：2013.4.25
编 写 人：
注    意：
***********************************************************************/
#include "main.h"

 __IO uint32_t TimingDelay;
uint32_t SystemCoreClock = 72000000;

  /* Setup SysTick Timer for 1 msec interrupts.
     ------------------------------------------
    1. The SysTick_Config() function is a CMSIS function which configure:
       - The SysTick Reload register with value passed as function parameter.
       - Configure the SysTick IRQ priority to the lowest value (0x0F).
       - Reset the SysTick Counter register.
       - Configure the SysTick Counter clock source to be Core Clock Source (HCLK).
       - Enable the SysTick Interrupt.
       - Start the SysTick Counter.
    
    2. You can change the SysTick Clock source to be HCLK_Div8 by calling the
       SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8) just after the
       SysTick_Config() function call. The SysTick_CLKSourceConfig() is defined
       inside the misc.c file.

    3. You can change the SysTick IRQ priority by calling the
       NVIC_SetPriority(SysTick_IRQn,...) just after the SysTick_Config() function 
       call. The NVIC_SetPriority() is defined inside the core_cm3.h file.

    4. To adjust the SysTick time base, use the following formula:
                            
         Reload Value = SysTick Counter Clock (Hz) x  Desired Time base (s)
    
       - Reload Value is the parameter to be passed for SysTick_Config() function
       - Reload Value should not exceed 0xFFFFFF
   */
/***********************************************************************
函数名称：SysTick_Configuration(void)
功    能： 1ms中断一次
输入参数：
输出参数：
编写时间：2013.4.25
编 写 人：
注    意：
***********************************************************************/
void SysTick_Configuration(void)
{
	if (SysTick_Config(SystemCoreClock / 1000))
	{ 
		/* Capture error */ 
		while (1);
	}
}


/***********************************************************************
函数名称：Delay(__IO uint32_t nTime)
功    能： 延时，单位ms
输入参数：
输出参数：
编写时间：2013.4.25
编 写 人：
注    意：
***********************************************************************/
void Delay_ms(__IO uint32_t nTime)
{ 
	TimingDelay = nTime;
	while(TimingDelay != 0);
}
/***********************************************************************
函数名称：TimingDelay_Decrement(void)
功    能： 延时计数，
输入参数：
输出参数：
编写时间：2013.4.25
编 写 人：
注    意： 在中断函数里调用
***********************************************************************/
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
		TimingDelay--;
	}
}
/***********************************************************************
函数名称：SysTick_Handler(void)
功    能： SysTick中断函数
输入参数：
输出参数：
编写时间：2013.4.25
编 写 人：
注    意：
***********************************************************************/
void SysTick_Handler(void)
{
	TimingDelay_Decrement();
}
