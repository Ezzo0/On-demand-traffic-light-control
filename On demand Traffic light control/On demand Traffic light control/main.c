/*
 * On demand Traffic light control.c
 *
 * Created: 9/3/2022 1:31:28 PM
 * Author : Ezz
 */ 

//#include <avr/io.h>
#include "APPLICATION/application.h"


int main(void)
{
	app_init(); 
	app_start();
	/*enable_global_interrupts();
	timer2_enable_overflow_interrupt();
	uint8_t value;
	LED_init(portA,PIN_2);
	BUTTON_init(portD,PIN_0);
	timer2_select_mode(normal);
	timer2_set_initial_value(40);
	while(1)
	{
		BUTTON_read(portD,PIN_0,&value);
		if(value)
		{
			LED_on(portA,PIN_2);
			timer2_timer_start(1024,13);
			LED_off(portA,PIN_2);
		}
		else
			LED_off(portA,PIN_2);		
	}*/
}

