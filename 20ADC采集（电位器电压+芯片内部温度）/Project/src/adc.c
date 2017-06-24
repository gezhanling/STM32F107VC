/***********************************************************************
文件名称：adc.C
功    能：完成对adc操作
编写时间：2012.11.22
编 写 人：
注    意：
***********************************************************************/
#include "main.h"

volatile uint16_t ADC_RCVTab[2] ;   //自己添加
// extern __IO u16 ADC_ConvertedValue;
//volatile uint16_t ADC_ConvertedValue;   //自己添加
// extern volatile unsigned int  ADC_RCVTab[16];


 /* ADC1 转换的电压值通过 MDA 方式传到 sram*/
 #define V25 0x6EE

 //斜率 每摄氏度 4.3mV 对应每摄氏度 0x05
 #define Avg_Slope 0x05
 
 // extern __IO u16 ADC_ConvertedValue;
//  uint16_t ADC_ConvertedValue;   //自己添加
 
  /*计算后的温度值*/
  u16 Current_Temp;
/***********************************************************************
函数名称：void ADC_Configuration(void) 
功    能：完成adc的配置
输入参数：
输出参数：
编写时间：2012.11.22
编 写 人：
注    意：因为该配置是采集16通道的，但是板子上有些adc管脚和其他功能复用（接了其他器件）
		  所以在使用过程中需要注意，板子上有一个电位器，可以通过调节该电位器观察该路变化。	   
		  //本程序要采集温度和点位器电压，在串口精灵上同时显示//
		  ADC对应管脚：
		  ADC_Channel_0	   		 PA0
		  ADC_Channel_1   	 	 PA1
		  ADC_Channel_2	  		 PA2
		  ADC_Channel_3	  		 PA3
		  ADC_Channel_4	  		 PA4
		  ADC_Channel_5	   		 PA5
		  ADC_Channel_6	  		 PA6
		  ADC_Channel_7	   		 PA7
		  ADC_Channel_8	   		 PB0
		  ADC_Channel_9	   		 PB1	 //次引脚上有一个点位器
		  ADC_Channel_10	   	 PC0
		  ADC_Channel_11	  	 PC1
		  ADC_Channel_12	  	 PC2
		  ADC_Channel_13	  	 PC3
		  ADC_Channel_14	  	 PC4
		  ADC_Channel_15	 	 PC5
		  
***********************************************************************/
void ADC_Configuration(void)
{
	
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO | RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA ,ENABLE);
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);//使能DMA时钟
//    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_ADC1, ENABLE);//使能ADC1时钟
	
	DMA_DeInit(DMA1_Channel1);

	DMA_InitStructure.DMA_PeripheralBaseAddr =(u32)&ADC1->DR;  //DMA外设ADC基地
//   DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;	// 外设基地址

    DMA_InitStructure.DMA_MemoryBaseAddr =(u32)ADC_RCVTab;//内存地址
//    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&ADC_ConvertedValue; // AD 转换值所存放的内存基地址 （就是给个地址）

	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;//dma传输方向单向
//	DMA_InitStructure.DMA_BufferSize = 16;//设置DMA在传输时缓冲区的长度 word
    DMA_InitStructure.DMA_BufferSize = 2;		   // 定义指定 DMA 通道 DMA 缓存的大小，一个是电位器，一个是温度

	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//设置DMA的外设递增模式，一个外设
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//设置DMA的内存递增模式，
 //  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;// 内存地址寄存器不变

 	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;//外设数据字长
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//内存数据字长
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//设置DMA的传输模式：连续不断的循环模式
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;//设置DMA的优先级别
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;//设置DMA的2个memory中的变量互相访问
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	
	DMA_Cmd(DMA1_Channel1, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* ADC1 Configuration ------------------------------------------------------*/
	ADC_DeInit(ADC1);  //将外设 ADC1 的全部寄存器重设为缺省值
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;	//连续多通道模式
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;   //连续转换
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; //转换不受外界决定
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; //右对齐 
//	ADC_InitStructure.ADC_NbrOfChannel = 16;//扫描通道数
	ADC_InitStructure.ADC_NbrOfChannel = 2;//扫描通道数2个  分别为温度通道16和9号通道点位器
	/*配置 ADC 时钟，为 PCLK2 的 8 分频，即 9MHz*/

	 
	ADC_Init(ADC1, &ADC_InitStructure);
	/* ADC1 regular channel10 configuration */

     RCC_ADCCLKConfig(RCC_PCLK2_Div8);
/*
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_28Cycles5); 	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_28Cycles5); 	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_28Cycles5); 	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 4, ADC_SampleTime_28Cycles5);	 	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 5, ADC_SampleTime_28Cycles5);	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 6, ADC_SampleTime_28Cycles5);	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 7, ADC_SampleTime_28Cycles5);	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 8, ADC_SampleTime_28Cycles5);	  	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 9, ADC_SampleTime_28Cycles5);	   	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 10, ADC_SampleTime_28Cycles5);	  	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10,11, ADC_SampleTime_28Cycles5);	   
	ADC_RegularChannelConfig(ADC1, ADC_Channel_11,12, ADC_SampleTime_28Cycles5);	 
	ADC_RegularChannelConfig(ADC1, ADC_Channel_12,13, ADC_SampleTime_28Cycles5);	   
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13,14, ADC_SampleTime_28Cycles5);	   	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_14,15, ADC_SampleTime_28Cycles5);	   	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_15,16, ADC_SampleTime_28Cycles5);
*/	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1, ADC_SampleTime_239Cycles5);	 //开启电位器电压检测	  优先级次序最高
	ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 2, ADC_SampleTime_239Cycles5);	 //开启内部温度传感器检测 优先级其次

	ADC_TempSensorVrefintCmd(ENABLE);		                                         //软件开启内部温度检测
	
		   	
	/* Enable ADC1 */
	ADC_Cmd(ADC1, ENABLE);
	ADC_DMACmd(ADC1, ENABLE);
	/* Enable ADC1 reset calibaration register */              
	ADC_ResetCalibration(ADC1);          //复位指定的ADC1的校准寄存器           
	/* Check the end of ADC1 reset calibration register */           
	while(ADC_GetResetCalibrationStatus(ADC1));        //获取ADC1复位校准寄存器的状态,设置状态则等待
	/* Start ADC1 calibaration */           
	ADC_StartCalibration(ADC1);                //开始指定ADC1的校准状态         
	/* Check the end of ADC1 calibration */          
	while(ADC_GetCalibrationStatus(ADC1));                //获取指定ADC1的校准程序,设置状态则等待
	/* Start ADC1 Software Conversion */
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE); 
	DMA_Cmd(DMA1_Channel1, ENABLE);  //启动DMA通道
}
/***********************************************************************
函数名称：void ADC_Show(void) 
功    能：
输入参数：
输出参数：
编写时间：2012.11.22
编 写 人：
注    意：因为该配置是采集16通道的，但是板子上有些adc管脚和其他功能复用（接了其他器件）
		  所以在使用过程中需要注意，板子上有一个电位器，可以通过调节该电位器观察该路变化。
		  ADC对应管脚：
		  ADC_Channel_0	   		 PA0
		  ADC_Channel_1   	 	 PA1
		  ADC_Channel_2	  		 PA2
		  ADC_Channel_3	  		 PA3
		  ADC_Channel_4	  		 PA4
		  ADC_Channel_5	   		 PA5
		  ADC_Channel_6	  		 PA6
		  ADC_Channel_7	   		 PA7
		  ADC_Channel_8	   		 PB0
		  ADC_Channel_9	   		 PB1
		  ADC_Channel_10	   	 PC0
		  ADC_Channel_11	  	 PC1
		  ADC_Channel_12	  	 PC2
		  ADC_Channel_13	  	 PC3
		  ADC_Channel_14	  	 PC4
		  ADC_Channel_15	 	 PC5
		  
***********************************************************************/
void ADC_Show(void)
{
   float voltage_register;
   uint16_t temp_regeister;   //自己添加
/*	float p_ch[16];
	unsigned char i = 0;
	for(i = 0;i < 16;i ++)//输出16路电压值
	{
		p_ch[i] = (ADC_RCVTab[i]) * 3.3 / 4096.0;
		printf("%4.2f   ",p_ch[i]);
	}
	printf("\n");		 */
   		 //计算方法 1
  //Current_Temp= (1.43-ADC_ConvertedValue*3.3/4096)*1000 / 4.3+ 25 ;
 
  //计算方法 2
 
 // ADC_ConvertedValue =ADC_RCVTab[15];
 //Current_Temp=(V25-ADC_ConvertedValue)/Avg_Slope+25;
 
   voltage_register=ADC_RCVTab[0]* 3.3 / 4096.0;
   temp_regeister= (V25-ADC_RCVTab[1])/Avg_Slope+25;
  //10 进制显示
  printf("\r\n The current temperature= %3d ℃\r\n", temp_regeister);
 	printf("\r\n The current Voltage= %4.2f V\r\n", voltage_register);
    //printf("%4.2f   ",p_ch[i]);
 //16 进制显示
  // printf("\r\n The current temperature= %04x \r\n", Current_Temp);

}

