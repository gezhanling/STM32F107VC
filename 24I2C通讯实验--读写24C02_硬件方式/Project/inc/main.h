/***********************************************************************
�ļ����ƣmmain.h
��    �ܣ�
��дʱ�䣺
�� д �ˣ�������Ƕ���������Ӽ����Ŷ�
ע    �⣺
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
