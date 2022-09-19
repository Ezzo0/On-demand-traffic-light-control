/*
 * application.c
 *
 * Created: 9/13/2022 3:52:48 PM
 *  Author: Ezz
 */ 

#include "application.h"

uint8_t status = Green_state, back = 0;
extern uint8_t flag, pushed;

void app_init()
{
	// Cars' traffic light initialization
	LED_init(portA,Green_cars);	// initialize cars' green led
	LED_init(portA,Yellow_cars);	// initialize cars' yellow led
	LED_init(portA,Red_cars);	// initialize cars' red led
	
	// Pedestrians' traffic light initialization
	LED_init(portB,Red_pedestrians);	// initialize Pedestrians' red led
	LED_init(portB,Yellow_pedestrians);	// initialize Pedestrians' yellow led
	LED_init(portB,Green_Pedestrians);	// initialize Pedestrians' green led
	
	//Pedestrian's button initialization
	BUTTON_init(portD,PIN_2);	// initialize Pedestrians' button
	
	// Interrupts activation
	enable_global_interrupts();
	timer0_enable_overflow_interrupt();
	timer2_enable_overflow_interrupt();
	enable_button_interrupt();
	
	setOvfCallback(LED_toggle);
	
	// Timers mode selection
	timer0_select_mode(normal);
	timer2_select_mode(normal);
	
	// Timers initial value 
	timer0_set_initial_value(initial_value_0);
	timer2_set_initial_value(initial_value_2);
}

void app_start()
{
	while (1)
	{
		// Green status 
		if(status == Green_state)
		{
			LED_on(portA,Green_cars);
			timer0_timer_start(1024,overflows_0); // wait for 5 seconds
			// If pushing on button was done at green state ==> the timer will reset then enter to the if condition
			if(flag)
			{
				LED_off(portA,Green_cars);
				LED_off(portB,Red_pedestrians);
				status = Red_state; // Go to red state
			}
			else
				status = Yellow1_state; // Go to first yellow state
		}
		
		// First Yellow state
		else if(status == Yellow1_state)
		{
			LED_on(portA,Yellow_cars);
			timer0_timer_start(1024,overflows_0); // wait for 5 seconds
			// If pushing on button was done at first yellow state ==> the timer will reset then enter to the if condition
			if(flag)
			{
				LED_off(portB,Red_pedestrians);
				LED_off(portA,Green_cars);
			}
			else
			{
				LED_off(portA,Yellow_cars);
				LED_off(portA,Green_cars);
			}
			status = Red_state; // Go to red state
		}
		
		// Red state
		else if(status == Red_state)
		{
			LED_on(portA,Red_cars);
			// If pushing on button was done at first yellow state ==> enter to the if condition
			if(flag)
			{
				LED_on(portB,Green_Pedestrians);
				back = 1; // Activate the flag. So,the two yellow leds plink at the same time
				flag = Interrupt_not_happened; // Deactivate the flag to indicate that interruption cycle has one last step
			}
			timer0_timer_start(1024,overflows_0); // wait for 5 seconds
			// If pushing on button was done at red state ==> the timer will reset then enter to the if condition
			if(flag)
			{
				back = 1; // Activate the flag. So,the two yellow leds plink at the same time
				flag = Interrupt_not_happened; // Deactivate the flag to indicate that interruption cycle has one last step
			}
			status = Yellow2_state; // Go to second yellow state
		}
		
		// Second Yellow state
		else
		{
			LED_on(portA,Yellow_cars);
			// If interrupt was happened in the previous states ==> enter to the if condition
			if(back)
				LED_on(portB,Yellow_pedestrians);
			timer0_timer_start(1024,overflows_0); // Wait for 5 seconds
			LED_off(portA,Yellow_cars);
			LED_off(portB,Yellow_pedestrians);
			// If interrupt was happened in the second yellow states ==> the timer will reset then enter to the if condition
			if(flag)
			{
				LED_off(portA,Green_cars);
				LED_off(portB,Red_pedestrians);
				status = Red_state; // Go to red state
			}
			else
			{
				LED_off(portA,Red_cars);
				LED_off(portB,Green_Pedestrians);
				// If there was a button interrupt in any state ==> enter the if condition
				if(pushed)
				{
					LED_on(portA,Green_cars);
					LED_on(portB,Red_pedestrians);
					timer2_timer_start(1024,overflows_2); // Wait for 3 seconds
					LED_off(portA,Green_cars);
					LED_off(portB,Red_pedestrians);
					
					// Deactivate the flag to indicate that interruption cycle has ended 
					pushed = Button_not_pushed;
					back = 0;
				}
				status = Green_state; // Go to green state (Normal mode again)
			}
		}
	}
}