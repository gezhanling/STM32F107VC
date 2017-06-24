#include "main.h"

void NVIC_Configuration(void); 

int main(void)
{
	System_Setup();
  NVIC_Configuration(); 
  USART_Configuration();       
	while (1)
	{
		if(RS232_REC_Flag == 1)
		{
			RS232_REC_Flag = 0;
			RS232_Send_Data(RS232_buff,RS232_rec_counter); 
			RS232_rec_counter = 0;	
		}
	}
}
