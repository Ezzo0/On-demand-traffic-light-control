/*
 * button.c
 *
 * Created: 9/3/2022 6:09:29 PM
 *  Author: Ezz
 */ 

#include "button.h"

uint8_t flag = Interrupt_not_happened; // Flag to check first push
uint8_t pushed = Button_not_pushed; // Flag to check double push
extern uint8_t status;


//Initialize button port
void BUTTON_init(uint8_t buttonport, uint8_t buttonpin)
{
	DIO_init(buttonport,buttonpin,IN);
}

// button read
void BUTTON_read(uint8_t buttonport,uint8_t buttonpin, uint8_t *value)
{
	DIO_read(buttonport,buttonpin,value);
}

//Button interrupt service routine function
ISR(EXT_INT_0)
{
	// If pushed in red state
	if(status == Red_state && !pushed)
	{
		timer0_timer_reset();
		LED_on(portB,Green_Pedestrians);
		flag = Interrupt_happened; // activate the flag to indicate that interruption has happened 
		pushed = Button_pushed; // activate the flag to indicate that interruption cycle has begun
	}
	// If pushed in green state
	else if(status == Green_state && !pushed)
	{
		timer0_timer_reset();
		LED_on(portB,Red_pedestrians);
		flag = Interrupt_happened; // activate the flag to indicate that interruption has happened 
		pushed = Button_pushed; // activate the flag to indicate that interruption cycle has begun
	}
	// If pushed in yellow state
	else if((status == Yellow1_state || status == Yellow2_state) && !pushed)
	{
		timer0_timer_reset();
		LED_on(portB,Red_pedestrians);
		LED_off(portA,Yellow_cars); // Turn off cars' yellow led
		flag = Interrupt_happened; // activate the flag to indicate that interruption has happened 
		pushed = Button_pushed; // activate the flag to indicate that interruption cycle has begun
	}
}
