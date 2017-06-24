#ifndef _ADC_H_
#define _ADC_H_

#define     TIMER					1000 //单位ms

#define  	FLITER_A     			0.2

//extern volatile unsigned int ADC_ConvertedValue ;//用于RS232接收计数
void ADC_Configuration(void);
void ADC_Show(void);
extern int abs(int x);

#endif
