/***********************************************************************
文件名称main.h
功    能：
编写时间：
编 写 人：北京智嵌物联网电子技术团队
注    意：
***********************************************************************/
#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f10x.h"
#include "stm32f107.h"
#include "SCI.H"
#include "24C02.h"

void Time_Update(void);
void Delay(uint32_t nCount);
void I2C_Test(void);

#endif 
