/***********************************************************************
文件名称：main.C
功    能：
编写时间：
编 写 人：北京智嵌物联网电子技术团队
注    意：
***********************************************************************/
#include "delay.h"
#include "sys.h"
#include "sci.h"
//#include "exti.h"
//#include "wdg.h"
#include "pwm.h"
#include "main.h"

extern void TIM3_PWM_Init(u16 arr,u16 psc);
extern void TIM4_PWMINPUT_INIT(u16 arr,u16 psc);

extern u16 period;
extern u16 duty ;
extern u8 CollectFlag ;

void NVIC_Configuration(void); 
int fputc(int ch, FILE *f);
void delay(u32 n);

int main(void)
{
	SystemInit();
	delay_init(72);	  
  NVIC_Configuration(); 
  USART_Configuration();    
  TIM3_PWM_Init(1000-1,72-1);   //1KHZ周期
	TIM_SetCompare1(TIM3,200);		//设置占空比
	TIM_SetCompare2(TIM3,400);		//设置占空比
	TIM_SetCompare3(TIM3,600);		//设置占空比
	TIM_SetCompare4(TIM3,800);		//设置占空比
	TIM4_PWMINPUT_INIT(0xffff,72-1);   //pwm输入初始化以1M的频率捕捉	
	while (1)
	{
// 		printf("\r\n this is a printf demo! \r\n");
// 		delay(9000000);
	    delay_ms(100);
 		  if(!CollectFlag)
			{
				printf("duty  	= %d%% \r\n",duty*100/period);				//打印占空比
				printf("cycle 	= %dHz\r\n",1000000/period);//打印周期另一种叫法
				printf("period  = %dus\r\n",period);    //打印周期
				printf("voleticy = %fm/s\n",1000000000/(period*100718.64));
				printf("\n");
				CollectFlag = 1;
				period = 0;
			}
	}
}

void delay(u32 n)
{
	for(; n != 0; n--);
}
