#include "pwm.h"


/*�������ƣTIM3_PWM_Init(u16 arr,u16 psc)
	����      TIM3������·PWM
*/

void TIM3_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC  | RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��ʹ��
	
  GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE); //Timer3ȫӳ�� GPIOC-> 6,7,8,9                                                                    	 //����TIM3��CH2�����PWMͨ����LED��ʾ
 
   //���ø�����Ϊ�����������,���TIM3 CH1 CH2 CH3 CH4 ��PWM���岨��
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9; //��ʼ��GPIO
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	
	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIMx��CCR1�ϵ�Ԥװ�ؼĴ���
	
	
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIMx��CCR2�ϵ�Ԥװ�ؼĴ���
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIMx��CCR3�ϵ�Ԥװ�ؼĴ���
	
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIMx��CCR4�ϵ�Ԥװ�ؼĴ���
	
	TIM_ARRPreloadConfig(TIM3, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	
 
	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx����
 

}



/*�������ƣTIM4_PWMINPUT_INIT(u16 arr,u16 psc)
  ����      PWM�����ʼ��*/


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
 
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ  
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	
	/*�����ж����ȼ�*/
	
 
	TIM4_ICInitStructure.TIM_Channel = TIM_Channel_2;                   
  TIM4_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;       
  TIM4_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;   
  TIM4_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1; 
	TIM4_ICInitStructure.TIM_ICFilter = 0x0; 
 
	TIM_PWMIConfig(TIM4, &TIM4_ICInitStructure);     //PWM��������           
  TIM_SelectInputTrigger(TIM4, TIM_TS_TI2FP2);     //ѡ����Ч�����        
  TIM_SelectSlaveMode(TIM4, TIM_SlaveMode_Reset);  //����Ϊ���Ӹ�λģʽ
  TIM_SelectMasterSlaveMode(TIM4, TIM_MasterSlaveMode_Enable);                                       
  TIM_ITConfig(TIM4, TIM_IT_CC2|TIM_IT_Update, ENABLE);          //�ж�����
	TIM_ClearITPendingBit(TIM4, TIM_IT_CC2|TIM_IT_Update); //����жϱ�־λ
	TIM_Cmd(TIM4, ENABLE);    
}

u16 period = 0;
u16 duty  = 0;
u8 CollectFlag = 1;

void TIM4_IRQHandler(void)
{

	if(CollectFlag){
	if (TIM_GetITStatus(TIM4, TIM_IT_CC2) != RESET)//����1���������¼�
		{	
			duty = TIM_GetCapture1(TIM4); 				//�ɼ�ռ�ձ�		
		  period	=	TIM_GetCapture2(TIM4);     //�ɼ�����
		}
		
		CollectFlag = 0;
	}	
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC2|TIM_IT_Update); //����жϱ�־λ
}