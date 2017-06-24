#include "stm32f10x.h"
#include "DMA.h"

const uint16_t Sine12bit[258] = { 
2048, 2098, 2148, 2198, 2248, 2298, 2348, 2398, 2447, 2496,
 2545, 2594, 2642, 2690, 2737, 2785, 2831, 2877, 2923, 2968,
 3013, 3057, 3100, 3143, 3185, 3227, 3267, 3307, 3347, 3385,
 3423, 3460, 3496, 3531, 3565, 3598, 3631, 3662, 3692, 3722,
 3750, 3778, 3804, 3829, 3854, 3877, 3899, 3920, 3940, 3958,
 3976, 3992, 4007, 4021, 4034, 4046, 4056, 4065, 4073, 4080,
 4086, 4090, 4093, 4095, 4095, 4095, 4093, 4090, 4086, 4080,
 4073, 4065, 4056, 4046, 4034, 4021, 4007, 3992, 3976, 3958,
 3940, 3920, 3899, 3877, 3854, 3829, 3804, 3778, 3750, 3722,
 3692, 3662, 3631, 3598, 3565, 3531, 3496, 3460, 3423, 3385,
 3347, 3307, 3267, 3227, 3185, 3143, 3100, 3057, 3013, 2968,
 2923, 2877, 2831, 2785, 2737, 2690, 2642, 2594, 2545, 2496,
 2447, 2398, 2348, 2298, 2248, 2198, 2148, 2098, 2047, 1997,
 1947, 1897, 1847, 1797, 1747, 1697, 1648, 1599, 1550, 1501,
 1453, 1405, 1358, 1310, 1264, 1218, 1172, 1127, 1082, 1038,
 995, 952, 910, 868, 828, 788, 748, 710, 672, 635,
 599, 564, 530, 497, 464, 433, 403, 373, 345, 317,
 291, 266, 241, 218, 196, 175, 155, 137, 119, 103,
 88, 74, 61, 49, 39, 30, 22, 15, 9, 5,
 2, 0, 0, 0, 2, 5, 9, 15, 22, 30,
 39, 49, 61, 74, 88, 103, 119, 137, 155, 175,
 196, 218, 241, 266, 291, 317, 345, 373, 403, 433,
 464, 497, 530, 564, 599, 635, 672, 710, 748, 788,
 828, 868, 910, 952, 995, 1038, 1082, 1127, 1172, 1218,
 1264, 1310, 1358, 1405, 1453, 1501, 1550, 1599, 1648, 1697,
 1747, 1797, 1847, 1897, 1947, 1997 };

void DMA_Config(void)
{
	DMA_InitTypeDef            DMA_InitStructure;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

	/* DMA2 channel2 configuration */
	DMA_DeInit(DMA2_Channel4);
	DMA_InitStructure.DMA_PeripheralBaseAddr = DAC_DHR12R2; //指定DMA2通道3的目标地址为DAC1_DHR12R1
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&Sine12bit;	//指定DMA的源地址为数组Sine12bit
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
	DMA_InitStructure.DMA_BufferSize = 256;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA2_Channel4, &DMA_InitStructure);
	
	/* Enable DMA2 Channel2 */
	DMA_Cmd(DMA2_Channel4, ENABLE); 
}
