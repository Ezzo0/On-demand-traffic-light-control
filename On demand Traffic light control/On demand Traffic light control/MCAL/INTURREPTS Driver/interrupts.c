/*
 * interupts.c
 *
 * Created: 9/11/2022 11:20:39 PM
 *  Author: Ezz
 */ 
#include "interrupts.h"

void enable_global_interrupts()
{
	SREG |=(1 << BIT_7_I); // set bit 7 in SREG register to one
}
void enable_button_interrupt()
{
	MCUCR |= ((1 << ISC00) | (1 << ISC01)); // set bit ISC00 and ISC01 in MCUCR register to one
	GICR |= (1 << INT_0); // set bit INT0 in MCUCR register to one
}
void timer0_enable_overflow_interrupt()
{
	TIMSK |= (1 << TOIE0); // set bit TOIE0 in TIMSK register to one
}
void timer2_enable_overflow_interrupt()
{
	TIMSK |= (1 << TOIE2); // set bit TOIE2 in TIMSK register to one
}