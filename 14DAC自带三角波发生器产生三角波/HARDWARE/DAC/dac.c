#include "dac.h"

//DAC通道1输出初始化
void Dac1_Init(void)
{
  
	GPIO_InitTypeDef GPIO_InitStructure;
	DAC_InitTypeDef DAC_InitType;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE );	  //使能PORTA通道时钟
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE );	  //使能DAC通道时钟 

	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				 // 端口配置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 		 //模拟输入
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//GPIO_SetBits(GPIOA,GPIO_Pin_4)	;//PA.4 输入高	，上拉输入起抗干扰的作用
	GPIO_SetBits(GPIOA,GPIO_Pin_5)	;
					
	DAC_InitType.DAC_Trigger=DAC_Trigger_Software;	//使用软件触发，设置的位为位2和为5:3，这两个必须同时设置
	//DAC_InitType.DAC_WaveGeneration=DAC_WaveGeneration_Triangle;//产生三角波波形发生
 	DAC_InitType.DAC_WaveGeneration=DAC_WaveGeneration_Noise;
	DAC_InitType.DAC_LFSRUnmask_TriangleAmplitude=DAC_TriangleAmplitude_4095;//屏蔽、幅值设置
	DAC_InitType.DAC_OutputBuffer=DAC_OutputBuffer_Disable ;	//DAC1输出缓存关闭 BOFF1=1
    //DAC_Init(DAC_Channel_1,&DAC_InitType);	 //初始化DAC通道1
  DAC_Init(DAC_Channel_2,&DAC_InitType);


	//DAC_Cmd(DAC_Channel_1, ENABLE);  //使能DAC1
	  DAC_Cmd(DAC_Channel_2, ENABLE);
    DAC_SetChannel1Data(DAC_Align_12b_R, 0);  //12位右对齐数据格式设置DAC值

}




