#include "stm32f107.h"

void GPIO_Configuration(void);
void NVIC_Configuration(void);


void System_Setup(void)
{
  /* Setup STM32 clock, PLL and Flash configuration) */
  SystemInit();

}

void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE,ENABLE);
  /********************************************************************
  void RCC_APB1PeriphClockCmd(u32 RCC_APB1Periph, FunctionalState NewState):
		该函数功能：使能或失能 APB1外设时钟；
		该函数功能：使能或失能 APB1外设时钟；
		RCC_APB1Periph: 门控APB1外设时钟
		NewState：指定外设时钟的新状态，值为ENABLE或者DISABLE
		RCC_APB1Periph包括：
							RCC_APB1Periph_TIM2
							RCC_APB1Periph_TIM3
							RCC_APB1Periph_TIM4
							RCC_APB1Periph_WWDG
							RCC_APB1Periph_SPI2
							RCC_APB1Periph_USART2
							RCC_APB1Periph_USART3
							RCC_APB1Periph_I2C1
							RCC_APB1Periph_I2C2
							RCC_APB1Periph_USB
							RCC_APB1Periph_CAN
  *********************************************************************/
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);
  GPIO_PinRemapConfig(GPIO_Remap2_CAN1,ENABLE);
  GPIO_PinRemapConfig(GPIO_Remap_CAN2,ENABLE);
  /********************************************************************
  void GPIO_PinRemapConfig(u32 GPIO_Remap, FunctionalState NewState):
  该函数功能是改变指定管脚的映射。
  GPIO_Remap: 选择重映射的管脚。
  NewState：值为ENABLE或者DISABLE。
  GPIO_Remap可以取的值为：
  						GPIO_Remap_SPI1           	SPI1复用功能映射
						GPIO_Remap_I2C1				I2C1复用功能映射
						GPIO_Remap_USART1			USART1复用功能映射
						GPIO_PartialRemap_USART3 	USART2复用功能映射
						GPIO_FullRemap_USART3 		USART3复用功能完全映射
						GPIO_PartialRemap_TIM1 		USART3复用功能部分映射
						GPIO_FullRemap_TIM1 		TIM1复用功能完全映射
						GPIO_PartialRemap1_TIM2 	TIM2复用功能部分映射1
						GPIO_PartialRemap2_TIM2 	TIM2复用功能部分映射2
						GPIO_FullRemap_TIM2 		TIM2复用功能完全映射
						GPIO_PartialRemap_TIM3 		TIM3复用功能部分映射
						GPIO_FullRemap_TIM3 		TIM3复用功能完全映射
						GPIO_Remap_TIM4 			TIM4复用功能映射
						GPIO_Remap1_CAN1 			CAN复用功能映射1
						GPIO_Remap2_CAN2 			CAN复用功能映射2
						GPIO_Remap_PD01			    PD01复用功能映射
						GPIO_Remap_SWJ_NoJTRST 		除JTRST外SWJ完全使能（JTAG+SW-DP）
						GPIO_Remap_SWJ_JTAGDisable  JTAG-DP失能 + SW-DP使能
						GPIO_Remap_SWJ_Disable      SWJ完全失能（JTAG+SW-DP�
  ********************************************************************/
	/* Configure CAN1 pin: RX */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOD, &GPIO_InitStructure);  
  /********************************************************************
  void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
  该函数的功能是：根据GPIO_InitStruct中指定的参数初始化外设GPIOx寄存器。
  typedef struct { 
					  u16 GPIO_Pin; 
					  GPIOSpeed_TypeDef GPIO_Speed; 
					  GPIOMode_TypeDef GPIO_Mode; 
				  } GPIO_InitTypeDef;

				  GPIO_Pin的取值为GPIO_Pin_0~15与GPIO_Pin_ALL.

				  GPIO_Speed用以设置选中管脚的速率:
				  GPIO_Speed_10MHz 			最高输出速率
				  10MHz GPIO_Speed_2MHz 	最高输出速率
				  2MHz GPIO_Speed_50MHz 	最高输出速率50MHz
			   	  
				  GPIO_Mode用以设置选中管脚的工作状态:
				  GPIO_Mode_AIN 			模拟输入 
				  GPIO_Mode_IN_FLOATING 	浮空输入 
				  GPIO_Mode_IPD 			下拉输入 
				  GPIO_Mode_IPU 			上拉输入 
				  GPIO_Mode_Out_OD 			开漏输出 
				  GPIO_Mode_Out_PP 			推挽输出 
				  GPIO_Mode_AF_OD 			复用开漏输出 
				  GPIO_Mode_AF_PP 			复用推挽输出


  ********************************************************************/
    
/*LED控制*/			
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
  GPIO_Init(GPIOE, &GPIO_InitStructure);

}

void NVIC_Configuration(void)
{
  NVIC_InitTypeDef   NVIC_InitStructure;

  /* Set the Vector Table base location at 0x08000000 */
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);

  /* 2 bit for pre-emption priority, 2 bits for subpriority */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
  
  /* Enable the Ethernet global Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = ETH_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);   
  
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;	  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;	
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure); 
}

