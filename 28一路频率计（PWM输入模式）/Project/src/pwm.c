#include "pwm.h"


/*功能名称IM3_PWM_Init(u16 arr,u16 psc)
	描述      TIM3产生四路PWM
*/

void TIM3_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC  | RCC_APB2Periph_AFIO, ENABLE);  //使能GPIO外设和AFIO复用功能模块时钟使能
	
  GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE); //Timer3全映射 GPIOC-> 6,7,8,9                                                                    	 //用于TIM3的CH2输出的PWM通过该LED显示
 
   //设置该引脚为复用输出功能,输出TIM3 CH1 CH2 CH3 CH4 的PWM脉冲波形
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9; //初始化GPIO
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIMx在CCR1上的预装载寄存器
	
	
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIMx在CCR2上的预装载寄存器
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIMx在CCR3上的预装载寄存器
	
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIMx在CCR4上的预装载寄存器
	
	TIM_ARRPreloadConfig(TIM3, ENABLE); //使能TIMx在ARR上的预装载寄存器
	
 
	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设
 

}



/*功能名称IM4_PWMINPUT_INIT(u16 arr,u16 psc)
  描述      PWM输入初始化*/


void TIM4_PWMINPUT_INIT(u16 arr,u16 psc)
{
  
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	//NVIC_InitTypeDef NVIC_InitStructure;
	TIM_ICInitTypeDef  TIM4_ICInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);     //Open TIM4 clock
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  //open gpioB clock
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;                               //GPIO??
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值  
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
 
	
	/*配置中断优先级*/
	
 
	TIM4_ICInitStructure.TIM_Channel = TIM_Channel_2;                   
  TIM4_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;       
  TIM4_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;   
  TIM4_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1; 
	TIM4_ICInitStructure.TIM_ICFilter = 0x0; 
 
	TIM_PWMIConfig(TIM4, &TIM4_ICInitStructure);     //PWM输入配置           
  TIM_SelectInputTrigger(TIM4, TIM_TS_TI2FP2);     //选择有效输入端        
  TIM_SelectSlaveMode(TIM4, TIM_SlaveMode_Reset);  //配置为主从复位模式
  TIM_SelectMasterSlaveMode(TIM4, TIM_MasterSlaveMode_Enable);                                       
  TIM_ITConfig(TIM4, TIM_IT_CC2|TIM_IT_Update, ENABLE);          //中断配置
	TIM_ClearITPendingBit(TIM4, TIM_IT_CC2|TIM_IT_Update); //清除中断标志位
	TIM_Cmd(TIM4, ENABLE);    
}

u16 period = 0;
u16 duty  = 0;
u8 CollectFlag = 1;

void TIM4_IRQHandler(void)
{

	if(CollectFlag){
	if (TIM_GetITStatus(TIM4, TIM_IT_CC2) != RESET)//捕获1发生捕获事件
		{	
			duty = TIM_GetCapture1(TIM4); 				//采集占空比		
		  period	=	TIM_GetCapture2(TIM4);     //采集周期
		}
		
		CollectFlag = 0;
	}	
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC2|TIM_IT_Update); //清除中断标志位
}