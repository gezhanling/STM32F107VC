/***********************************************************************
文件名称：SysTick.h
功    能：
编写时间：2013.4.25
编 写 人：
注    意：
***********************************************************************/

#ifndef _SYSTICK_H_
#define _SYSTICK_H_

void SysTick_Configuration(void);
void Delay_ms(__IO uint32_t nTime);
void TimingDelay_Decrement(void);

#endif 
