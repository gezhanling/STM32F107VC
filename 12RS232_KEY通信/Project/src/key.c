
#include "key.h" 

 void Delay(__IO u32 nCount)
{
  for(; nCount != 0; nCount--);
} 

 /*
 * function name:  Key_GPIO_Config
 * describe:configuration the input or output pin which are used by keys
 */
void Key_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

 /*
 * function name:Key_Scan
 * describe £º  check whether there is a key press 
 *  input  : PC6  PC7  PC8  PC9
 *  output £ºKEY_OFF(not press button);KEY1(button KEY1 press );KEY2(button KEY2 press);
 *                                     KEY3(button KEY press ) ;KEY4(button KEY4 press );
 */
uint8_t Key_Scan(void)
{			
		/* check whether there is a key press*/
   	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == KEY_ON) 
	  {	   
	 	 /*delay to jitters elimination*/
	  	Delay(10000);		
	   		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == KEY_ON )  
					{	 
						/*waiting button to release  */
						while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6) == KEY_ON);   
			 			return 	KEY1;	 
					}
			else
					return KEY_OFF;
		}
		else if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7) == KEY_ON)
		{
				Delay(10000);		
	   		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7) == KEY_ON )  
					{	 
						/*waiting button to release */
						while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7) == KEY_ON);   
			 			return 	KEY2;	 
					}
				else
					return KEY_OFF;
		}
		else if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) == KEY_ON)
		{
				Delay(10000);		
	   		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) == KEY_ON )  
					{	 
						/*waiting button to release */
						while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) == KEY_ON);   
			 			return 	KEY3;	 
					}
				else
					return KEY_OFF;
		}
		else if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) == KEY_ON)
		{
				Delay(10000);		
	   		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) == KEY_ON )  
					{	 
						/*waiting button to release*/
						while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) == KEY_ON);   
			 			return 	KEY4;	 
					}
				else
					return KEY_OFF;
		}
		
	else
		return KEY_OFF;
}
