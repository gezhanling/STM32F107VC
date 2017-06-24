#include "main.h"

int main(void)
{	
	System_Setup();			
	LED_Configuration();	
	Key_Configuration();       
	while (1)
	{
		One_LED_ON(Key_Value());
	}
}
