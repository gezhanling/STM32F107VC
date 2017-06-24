
#include "main.h"

void NVIC_Configuration(void); 
int trans2d();

 
 int res;
 	
int main(void)
{
		float i;
    NVIC_Configuration(); 
    USART_Configuration(); 
		Dac1_Init();
	while (1)
	{
if(RS232_REC_Flag == 1)  //"RS232_REC_Flag == 1" means serial port (RS232) receives a data.
		{
			RS232_REC_Flag = 0;    // make the flag bit "RS232_REC_Flag" go back to zero to handle the next data.
			trans2d();
			DAC_SetChannel2Data(DAC_Align_12b_R, res);
			i = res*(3.3/4095);
			printf("The voltage of PA5 is:%4.2fV\n",i);
			RS232_rec_counter = 0;	//  receiving counter "RS232_rec_counter" go back to zero when the transfer is complete.
			}
}

}

int trans2d()
{
	float i;
	i = RS232_buff[0]-48+(RS232_buff[2]-48)*0.1+(RS232_buff[3]-48)*0.01;
	res = 1242*i;//1V对应的DAC值为：1246 = (4096/3.3)
	return res;
}
