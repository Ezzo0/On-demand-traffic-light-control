/*
 * timer.c
 *
 * Created: 9/11/2022 4:13:34 PM
 *  Author: Ezz
 */ 
#include "timer.h"

uint8_t number_of_overflows = 0, number_of_overflows_2 = 0; // variables for counting the overflows
extern uint8_t status, back, flag;

/************************************************************************/
/* Callback function for higher layers                                  */
/************************************************************************/

void static (*ovfCallback) (uint8_t portnum,uint8_t pinnum);
void setOvfCallback(void (*callback) (uint8_t portnum,uint8_t pinnum))
{
	ovfCallback = callback;
}

/************************************************************************/
/* Timer 0 functions                                                    */
/************************************************************************/

void timer0_select_mode(uint8_t mode)
{
	switch(mode)
	{
		case normal:
			TCCR_0 = 0; // set timer 0 to Normal mode
		break;
			
		case pwm:
			TCCR_0 |= (1 << WGM00); // set timer 0 to PWM mode 
		break;
		
		case ctc:
			TCCR_0 |= (1 << WGM01); // set timer 0 to CTC mode
		break;
		
		case fast_pwm:
			TCCR_0 |= ((1 << WGM01) | (1 << WGM00)); // set timer 0 to Fast PWM mode
		break;
		
		default:
		{
			//Error
		}
	}
		
}

void timer0_set_initial_value(uint8_t value)
{
	TCNT_0 = value;
}

void timer0_timer_start(int prescalar, uint8_t overflows)
{
	switch(prescalar)
	{
		case 0:
			TCCR_0 |= (1 << CS00); // choose no prescalar
		break;
		
		case 8:
			TCCR_0 |= (1 << CS01); // choose prescalar of 8
		break;
		
		case 64:
			TCCR_0 |= ((1 << CS00) | (1 << CS01)); // choose prescalar of 64
		break;
		
		case 256:
			TCCR_0 |= (1 << CS02); // choose prescalar of 256
		break;
		
		case 1024:
			TCCR_0 |= ((1 << CS00) | (1 << CS02)); // choose prescalar of 1024
		break;
		
		default:
			// Error Handling
		break;
	}
	
	while(number_of_overflows < overflows);
	timer0_timer_stop();
}

void timer0_timer_reset()
{
	number_of_overflows = 0;
	timer0_set_initial_value(initial_value_0);
}

void timer0_timer_stop()
{
	number_of_overflows = 0;
	TCCR_0 = 0x00; // stop the timer
}

/************************************************************************/
/* Timer 2 functions                                                    */
/************************************************************************/

void timer2_select_mode(uint8_t mode)
{
	switch(mode)
	{
		case normal:
			TCCR_2 = 0x00; // set timer 2 to Normal mode
		break;
		
		case pwm:
			TCCR_2 |= (1 << WGM20); // set timer 0 to PWM mode
		break;
		
		case ctc:
			TCCR_2 |= (1 << WGM21); // set timer 0 to CTC mode
		break;
		
		case fast_pwm:
			TCCR_2 |= ((1 << WGM20) | (1 << WGM21)); // set timer 0 to Fast PWM mode
		break;
		
		default:
		{
			//Error
		}
	}
}

void timer2_set_initial_value(uint8_t value)
{
	TCNT_2 = value;
}

void timer2_timer_start(int prescalar,uint8_t overflows)
{
	switch(prescalar)
	{
		case 0:
			TCCR_2 |= (1 << CS20); // choose no prescalar
		break;
		
		case 8:
			TCCR_2 |= (1 << CS21); // choose prescalar of 8
		break;
		
		case 32:
			TCCR_2 |= ((1 << CS20) | (1 << CS21)); // choose prescalar of 32
		break;
		
		case 64:
			TCCR_2 |= (1 << CS22); // choose prescalar of 64
		break;
		
		case 128:
			TCCR_2 |= ((1 << CS20) | (1 << CS22)); // choose prescalar of 128
		break;
		
		case 256:
			TCCR_2 |= ((1 << CS21) | (1 << CS22)); // choose prescalar of 256
		break;
		
		case 1024:
			TCCR_2 |= ((1 << CS20) | (1 << CS21) | (1 << CS22)); // choose prescalar of 1024
		break;
		
		default:
			// Error Handling
		break;
	}
	
	while(number_of_overflows_2 < overflows);
	timer2_timer_stop();
}

void timer2_timer_reset()
{
	number_of_overflows_2 = 0;
	timer2_set_initial_value(initial_value_2);
}

void timer2_timer_stop()
{
	number_of_overflows_2 = 0;
	TCCR_2 = 0x00; // stop the timer
}

// Timer 0 over flow interrupt service routine function
ISR(TIMER_0_OVF)
{
	timer0_set_initial_value(11);
	number_of_overflows++;
	if(number_of_overflows && status != 2 && (status == 1 || status == 3 || flag))
	{
		if(flag || back)
		{
			ovfCallback(portA,Yellow_cars); //Callback function for higher layers 
			ovfCallback(portB,Yellow_pedestrians); //Callback function for higher layers 
		}
		else
			ovfCallback(portA,Yellow_cars);
	}
}

// Timer 2 over flow interrupt service routine function
ISR(TIMER_2_OVF)
{
	++number_of_overflows_2;
}