//STM32自带的三角波发生器，产生一个峰对峰值为2047--1.65V（参考电压为3.3V）的三角波
//#include "led.h"
#include "delay.h"
//#include "key.h"
#include "sys.h"
//#include "lcd.h"
#include "usart.h"
#include "dac.h"
 	
 int main(void)
 {	 
    //u16 adcx;
	//float temp;
	//u8 t=0;	  
 	//u8 x=0;
	//u16 dacval=0;
	//u8 key;
	//u8 lcd_id[12];			//存放LCD ID字符串
	delay_init();	    	 //延时函数初始化	  
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	//uart_init(9600);	 	//串口初始化为9600
	//KEY_Init();			  //初始化按键程序
 	//LED_Init();			     //LED端口初始化
	//LCD_Init();
	Dac1_Init();				//DAC初始化
	//POINT_COLOR=RED;//前景色为红色，前景色就是数字，字符等的颜色
	//sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//将LCD ID打印到lcd_id数组。				 	
//   	POINT_COLOR=RED;//设置字体为红色 
// 	LCD_ShowString(60,50,200,16,16,"WarShip STM32");	
// 	LCD_ShowString(60,70,200,16,16,"DAC TEST");	
// 	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
// 	LCD_ShowString(60,110,200,16,16,"2012/9/8");	
// 	LCD_ShowString(60,130,200,16,16,"WK_UP:+  KEY1:-");	
	//显示提示信息											      
// 	POINT_COLOR=BLUE;//设置字体为蓝色
// 	LCD_ShowString(60,150,200,16,16,"DAC VAL:");	      
// 	LCD_ShowString(60,170,200,16,16,"DAC VOL:0.000V");
	while(1) 
	{	
		//DAC_SoftwareTriggerCmd(DAC_Channel_1, ENABLE);//使能DAC1软件触发
		DAC_SoftwareTriggerCmd(DAC_Channel_2, ENABLE);
//	  		t++;
//		key=KEY_Scan(0);			  
//		if(key==4)
//		{		 
//			if(dacval<4000)dacval+=200;
//		    DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//设置DAC值	
//		}else if(key==2)	
//		{
//			if(dacval>200)dacval-=200;
//			else dacval=0;
//		    DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//设置DAC值
//		}	 
//		if(t==10||key==2||key==4) 		//WKUP/KEY1按下了,或者定时时间到了
//		{	  
//
//			adcx=DAC_GetDataOutputValue(DAC_Channel_1);//读取前面设置DAC的值
//			LCD_ShowxNum(124,150,adcx,4,16,0);     	//显示DAC寄存器值
//			temp=(float)adcx*(3.3/4096);			//得到DAC电压值
//			adcx=temp;
// 			LCD_ShowxNum(124,170,temp,1,16,0);     	//显示电压值整数部分
// 			temp-=adcx;
//			temp*=1000;
//			LCD_ShowxNum(140,170,temp,3,16,0X80); 	//显示电压值的小数部分
		 //LED0=!LED0;
			 //t=0;	
		} 
//		switch(x)//12中背景色循环切换
//		{
//			case 0:LCD_Clear(WHITE);break;
//			case 1:LCD_Clear(BLACK);break;
//			case 2:LCD_Clear(BLUE);break;
//			case 3:LCD_Clear(RED);break;
//			case 4:LCD_Clear(MAGENTA);break;
//			case 5:LCD_Clear(GREEN);break;
//			case 6:LCD_Clear(CYAN);break;
//
//			case 7:LCD_Clear(YELLOW);break;
//			case 8:LCD_Clear(BRRED);break;
//			case 9:LCD_Clear(GRAY);break;
//			case 10:LCD_Clear(LGRAY);break;
//			case 11:LCD_Clear(BROWN);break;
//		}
//		POINT_COLOR=RED;//前景色为红色	  
//		LCD_ShowString(30,50,200,16,16,"WarShip STM32 ^_^");//显示一行字符串，字符串左上角的坐标为x=30，y=50；字符串在一个长为200，宽为16的长方形区域中；每一个字符的字体大小为1608；		
//		                                                    //另外这个长方形的区域可通过设置不让它显示， 即在此函数中LCD_ShowChar(x,y,*p,size,0);把0该为1即可
//		//LCD_ShowString(30,70,200,16,16,"TFTLCD TEST");	
//		//LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
// 		LCD_ShowString(30,70,200,16,16,lcd_id);		//显示LCD驱动器的型号	      					 
//		//LCD_ShowString(30,130,200,16,16,"2012/9/5");
//		Draw_Circle(45,110,15);//圆心坐标为（45,110），半径为15
//		//LCD_ShowxNum(30,130,759488,6,16,0);
//		 LCD_ShowNum(30,150,454488360,9,16);//显示一数字串，数字左上角的坐标为（30,150）；数字串为454488360；长度为9，每一个数字的大小为1608,；还是在一个长方形的区域中显示，但是可以通过设置不显示这个长方形的区域
//		 LCD_DrawRectangle(30, 170, 80, 195);//画一个矩形，矩形的左上角的坐标为（30,170），右下角的坐标为（80,195）。
//		 LCD_DrawLine(30, 200, 90, 220);//画一条直线，直线左端的坐标为（30,200），右端的坐标为（90,220）。
//		 LCD_Fill(30,230,80,260,GREEN);//画一个矩形，矩形左上角的坐标为（30,230），右下角的坐标为（80,260）矩形的内部用绿色填充      					 
	    //x++;
		//if(x==12)x=0;
						 
		//delay_ms(10);	
	} 

