#ifndef __KEY_H
#define	__KEY_H

#include "stm32f10x.h"
 /*******
 *按键按下标置
 KEY_ON 0
 KEY_OFF 1
 ********/
#define KEY_ON	0
#define KEY_OFF	1
#define KEY1 2
#define KEY2 3
#define KEY3 4
#define KEY4 5


void Key_GPIO_Config(void);
uint8_t Key_Scan(void);

#endif /* __LED_H */

