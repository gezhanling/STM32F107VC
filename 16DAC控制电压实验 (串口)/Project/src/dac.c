#include "main.h"
#include "dac.h"


//DACͨ��1�����ʼ��
void Dac1_Init(void)
{
  
	GPIO_InitTypeDef GPIO_InitStructure;
	DAC_InitTypeDef DAC_InitType;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE );	  //ʹ��PORTAͨ��ʱ��
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE );	  //ʹ��DACͨ��ʱ�� 

	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				 // �˿�����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 		 //ģ������
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//GPIO_SetBits(GPIOA,GPIO_Pin_4)	;//PA.4 �����	�����������𿹸��ŵ�����
	GPIO_SetBits(GPIOA,GPIO_Pin_5)	;    //PA.5
					
	DAC_InitType.DAC_Trigger=DAC_Trigger_None;	//��ʹ�ô�������
	//DAC_InitType.DAC_WaveGeneration=DAC_WaveGeneration_Triangle;//�������ǲ����η���
  DAC_InitType.DAC_WaveGeneration=DAC_WaveGeneration_None;// ��ʹ�ò��η�����
	DAC_InitType.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bit0;//���Ρ���ֵ����
	DAC_InitType.DAC_OutputBuffer=DAC_OutputBuffer_Disable ;	//DAC1�������ر� BOFF1=1
  //DAC_Init(DAC_Channel_1,&DAC_InitType);	 //��ʼ��DACͨ��1
  DAC_Init(DAC_Channel_2,&DAC_InitType);


	  //DAC_Cmd(DAC_Channel_1, ENABLE);  //ʹ��DAC1
	  DAC_Cmd(DAC_Channel_2, ENABLE);
    //DAC_SetChannel1Data(DAC_Align_12b_R,0);//12λ�Ҷ������ݸ�ʽ����DACֵ
		DAC_SetChannel2Data(DAC_Align_12b_R,0);
}

