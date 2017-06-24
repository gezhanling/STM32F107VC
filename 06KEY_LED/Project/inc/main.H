#ifndef _MAIN_H_
#define _MAIN_H_

#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "stm32f107.h"
#include "LED.h"
#include "KEY.H"

void Time_Update(void);
void Delay(uint32_t nCount);
void System_Setup(void );			//设置系统时钟72MHZ
#endif 

