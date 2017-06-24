#ifndef _TIM_H_
#define _TIM_H_

/*正弦波频率参数设置*/
#define Sin_Out_500Hz	  0x8B6
#define Sin_Out_1KHz  	  0x456
#define Sin_Out_2KHz  	  0x235
#define Sin_Out_3KHz  	  0x17A
#define Sin_Out_4KHz  	  0x119
#define Sin_Out_5KHz  	  0xE0
#define Sin_Out_10KHz  	  0x6F
#define Sin_Out_15KHz  	  0x4A

void TIM_Config(void);

#endif

