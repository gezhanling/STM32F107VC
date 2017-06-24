/**
  ******************************************************************************
  * @file    stm32f107.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    11/20/2009
  * @brief   STM32F107 hardware configuration
  *******************************************************************************/
#include "stm32f107.h"

void System_Setup(void)
{

  /* Setup STM32 clock, PLL and Flash configuration) */
  SystemInit();
}


void NVIC_Configuration(void)
{
  /* Set the Vector Table base location at 0x08000000 */
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);  
}

