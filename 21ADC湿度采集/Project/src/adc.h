#ifndef _ADC_H_
#define _ADC_H_

#define     TIMER					1000 //��λms

#define  	FLITER_A     			0.2

//extern volatile unsigned int ADC_ConvertedValue ;//����RS232���ռ���
void ADC_Configuration(void);
void ADC_Show(void);
extern int abs(int x);

#endif
