//STM32�Դ������ǲ�������������һ����Է�ֵΪ2047--1.65V���ο���ѹΪ3.3V�������ǲ�
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
	//u8 lcd_id[12];			//���LCD ID�ַ���
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	//uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	//KEY_Init();			  //��ʼ����������
 	//LED_Init();			     //LED�˿ڳ�ʼ��
	//LCD_Init();
	Dac1_Init();				//DAC��ʼ��
	//POINT_COLOR=RED;//ǰ��ɫΪ��ɫ��ǰ��ɫ�������֣��ַ��ȵ���ɫ
	//sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//��LCD ID��ӡ��lcd_id���顣				 	
//   	POINT_COLOR=RED;//��������Ϊ��ɫ 
// 	LCD_ShowString(60,50,200,16,16,"WarShip STM32");	
// 	LCD_ShowString(60,70,200,16,16,"DAC TEST");	
// 	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
// 	LCD_ShowString(60,110,200,16,16,"2012/9/8");	
// 	LCD_ShowString(60,130,200,16,16,"WK_UP:+  KEY1:-");	
	//��ʾ��ʾ��Ϣ											      
// 	POINT_COLOR=BLUE;//��������Ϊ��ɫ
// 	LCD_ShowString(60,150,200,16,16,"DAC VAL:");	      
// 	LCD_ShowString(60,170,200,16,16,"DAC VOL:0.000V");
	while(1) 
	{	
		//DAC_SoftwareTriggerCmd(DAC_Channel_1, ENABLE);//ʹ��DAC1�������
		DAC_SoftwareTriggerCmd(DAC_Channel_2, ENABLE);
//	  		t++;
//		key=KEY_Scan(0);			  
//		if(key==4)
//		{		 
//			if(dacval<4000)dacval+=200;
//		    DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//����DACֵ	
//		}else if(key==2)	
//		{
//			if(dacval>200)dacval-=200;
//			else dacval=0;
//		    DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//����DACֵ
//		}	 
//		if(t==10||key==2||key==4) 		//WKUP/KEY1������,���߶�ʱʱ�䵽��
//		{	  
//
//			adcx=DAC_GetDataOutputValue(DAC_Channel_1);//��ȡǰ������DAC��ֵ
//			LCD_ShowxNum(124,150,adcx,4,16,0);     	//��ʾDAC�Ĵ���ֵ
//			temp=(float)adcx*(3.3/4096);			//�õ�DAC��ѹֵ
//			adcx=temp;
// 			LCD_ShowxNum(124,170,temp,1,16,0);     	//��ʾ��ѹֵ��������
// 			temp-=adcx;
//			temp*=1000;
//			LCD_ShowxNum(140,170,temp,3,16,0X80); 	//��ʾ��ѹֵ��С������
		 //LED0=!LED0;
			 //t=0;	
		} 
//		switch(x)//12�б���ɫѭ���л�
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
//		POINT_COLOR=RED;//ǰ��ɫΪ��ɫ	  
//		LCD_ShowString(30,50,200,16,16,"WarShip STM32 ^_^");//��ʾһ���ַ������ַ������Ͻǵ�����Ϊx=30��y=50���ַ�����һ����Ϊ200����Ϊ16�ĳ����������У�ÿһ���ַ��������СΪ1608��		
//		                                                    //������������ε������ͨ�����ò�������ʾ�� ���ڴ˺�����LCD_ShowChar(x,y,*p,size,0);��0��Ϊ1����
//		//LCD_ShowString(30,70,200,16,16,"TFTLCD TEST");	
//		//LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
// 		LCD_ShowString(30,70,200,16,16,lcd_id);		//��ʾLCD���������ͺ�	      					 
//		//LCD_ShowString(30,130,200,16,16,"2012/9/5");
//		Draw_Circle(45,110,15);//Բ������Ϊ��45,110�����뾶Ϊ15
//		//LCD_ShowxNum(30,130,759488,6,16,0);
//		 LCD_ShowNum(30,150,454488360,9,16);//��ʾһ���ִ����������Ͻǵ�����Ϊ��30,150�������ִ�Ϊ454488360������Ϊ9��ÿһ�����ֵĴ�СΪ1608,��������һ�������ε���������ʾ�����ǿ���ͨ�����ò���ʾ��������ε�����
//		 LCD_DrawRectangle(30, 170, 80, 195);//��һ�����Σ����ε����Ͻǵ�����Ϊ��30,170�������½ǵ�����Ϊ��80,195����
//		 LCD_DrawLine(30, 200, 90, 220);//��һ��ֱ�ߣ�ֱ����˵�����Ϊ��30,200�����Ҷ˵�����Ϊ��90,220����
//		 LCD_Fill(30,230,80,260,GREEN);//��һ�����Σ��������Ͻǵ�����Ϊ��30,230�������½ǵ�����Ϊ��80,260�����ε��ڲ�����ɫ���      					 
	    //x++;
		//if(x==12)x=0;
						 
		//delay_ms(10);	
	} 

