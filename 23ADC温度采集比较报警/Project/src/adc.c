/***********************************************************************
�ļ����ƣ�adc.C
��    �ܣ���ɶ�adc����
��дʱ�䣺2012.11.22
�� д �ˣ�
ע    �⣺
***********************************************************************/
#include "main.h"

volatile uint16_t ADC_RCVTab ;   //�Լ����
// extern __IO u16 ADC_ConvertedValue;
 uint16_t ADC_ConvertedValue[112];   //�Լ����
// extern volatile unsigned int  ADC_RCVTab[16];
float p_ch[112];
float tem[112];
float m=0;
float n=0;
 /* ADC1 ת���ĵ�ѹֵͨ�� MDA ��ʽ���� sram*/
 #define V25 0x6EE

 //б�� ÿ���϶� 4.3mV ��Ӧÿ���϶� 0x05
 #define Avg_Slope 0x05
 
 // extern __IO u16 ADC_ConvertedValue;
//  uint16_t ADC_ConvertedValue;   //�Լ����
 
  /*�������¶�ֵ*/
  u16 Current_Temp[112];
/***********************************************************************
�������ƣ�void ADC_Configuration(void) 
��    �ܣ����adc������
���������
���������
��дʱ�䣺2012.11.22
�� д �ˣ�
ע    �⣺��Ϊ�������ǲɼ�16ͨ���ģ����ǰ�������Щadc�ܽź��������ܸ��ã���������������
		  ������ʹ�ù�������Ҫע�⣬��������һ����λ��������ͨ�����ڸõ�λ���۲��·�仯��
		  ADC��Ӧ�ܽţ�
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
		  ADC_Channel_15	 	   PC5
		  
***********************************************************************/
void ADC_Configuration(void)
{
	
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO | RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA ,ENABLE);
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);//ʹ��DMAʱ��
//    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_ADC1, ENABLE);//ʹ��ADC1ʱ��
	
	DMA_DeInit(DMA1_Channel1);

	DMA_InitStructure.DMA_PeripheralBaseAddr =(u32)&ADC1->DR;  //DMA����ADC����
//   DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;	// �������ַ

  //  DMA_InitStructure.DMA_MemoryBaseAddr =(u32)ADC_RCVTab;//�ڴ��ַ
  DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&ADC_ConvertedValue; // AD ת��ֵ����ŵ��ڴ����ַ �����Ǹ�����ַ��

	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;//dma���䷽����
//	DMA_InitStructure.DMA_BufferSize = 16;//����DMA�ڴ���ʱ�������ĳ��� word
    DMA_InitStructure.DMA_BufferSize = 112;		   // ����ָ�� DMA ͨ�� DMA ����Ĵ�С

	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//����DMA���������ģʽ��һ������
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//����DMA���ڴ����ģʽ��
//   DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;// �ڴ��ַ�Ĵ�������

 	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;//���������ֳ�
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//�ڴ������ֳ�
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//����DMA�Ĵ���ģʽ���������ϵ�ѭ��ģʽ
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;//����DMA�����ȼ���
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;//����DMA��2��memory�еı����������
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
	ADC_DeInit(ADC1);  //������ ADC1 ��ȫ���Ĵ�������Ϊȱʡֵ
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;	//������ͨ��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;   //����ת��
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; //ת������������
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; //�Ҷ��� 
//	ADC_InitStructure.ADC_NbrOfChannel = 16;//ɨ��ͨ����
	ADC_InitStructure.ADC_NbrOfChannel = 1;//ɨ��ͨ����
	/*���� ADC ʱ�ӣ�Ϊ PCLK2 �� 8 ��Ƶ���� 9MHz*/

	 
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
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 1, ADC_SampleTime_239Cycles5);
	//ADC_TempSensorVrefintCmd(ENABLE);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13,1, ADC_SampleTime_28Cycles5);  	
	/* Enable ADC1 */
	ADC_Cmd(ADC1, ENABLE);
	ADC_DMACmd(ADC1, ENABLE);
	/* Enable ADC1 reset calibaration register */              
	ADC_ResetCalibration(ADC1);          //��λָ����ADC1��У׼�Ĵ���           
	/* Check the end of ADC1 reset calibration register */           
	while(ADC_GetResetCalibrationStatus(ADC1));        //��ȡADC1��λУ׼�Ĵ�����״̬,����״̬��ȴ�
	/* Start ADC1 calibaration */           
	ADC_StartCalibration(ADC1);                //��ʼָ��ADC1��У׼״̬         
	/* Check the end of ADC1 calibration */          
	while(ADC_GetCalibrationStatus(ADC1));                //��ȡָ��ADC1��У׼����,����״̬��ȴ�
	/* Start ADC1 Software Conversion */
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE); 
	DMA_Cmd(DMA1_Channel1, ENABLE);  //����DMAͨ��
}
/***********************************************************************
�������ƣ�void ADC_Show(void) 
��    �ܣ�
���������
���������
��дʱ�䣺2012.11.22
�� д �ˣ�
ע    �⣺��Ϊ�������ǲɼ�16ͨ���ģ����ǰ�������Щadc�ܽź��������ܸ��ã���������������
		  ������ʹ�ù�������Ҫע�⣬��������һ����λ��������ͨ�����ڸõ�λ���۲��·�仯��
		  ADC��Ӧ�ܽţ�
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
/*	float p_ch[16];
	unsigned char i = 0;
	for(i = 0;i < 16;i ++)//���16·��ѹֵ
	{
		p_ch[i] = (ADC_RCVTab[i]) * 3.3 / 4096.0;
		printf("%4.2f   ",p_ch[i]);
	}
	printf("\n");		 */
   		 //���㷽�� 1
  //Current_Temp= (1.43-ADC_ConvertedValue*3.3/4096)*1000 / 4.3+ 25 ;
 
  //���㷽�� 2
 
 // ADC_ConvertedValue =ADC_RCVTab[15];
//float p_ch[16];
	unsigned char i = 0;
	for(i = 0;i < 111;++i)//���16·��ѹֵ
	{
		p_ch[i] = (ADC_ConvertedValue[i]) * 3.3 / 4096.0;
		tem[i] = (p_ch[i]/0.15-4)*12.5-56;
	}
		for(i = 0;i < 111;++i)//���16·��ѹֵ
	{
		
		m+=tem[i];
	}
	m = m/112;
	n = m;
	printf("The current temperature is %4.2f��   \n",n); 
	   //p_ch = ((ADC_ConvertedValue) * 3.3 / 4096.0);
// 	tem = (p_ch/0.15-4)*12.5-56;
// 	printf("The current temperature is %4.2f��   \n",tem); 
// 	printf("\n");
  
 //16 ������ʾ
  // printf("\r\n The current temperature= %04x \r\n", Current_Temp);

}

