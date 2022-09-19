/*
 * dio.c
 *
 * Created: 9/3/2022 2:22:15 PM
 *  Author: Ezz
 */ 

#include "dio.h"

void DIO_init(uint8_t portnum,uint8_t pinnum, uint8_t direction)
{
	switch(portnum)
	{
		case portA:
			if(direction == IN)
				DDR_A &= ~(1 << pinnum); // Make pin number (pinnum) in port A an input pin 
			else if(direction == OUT)
				DDR_A |= (1 << pinnum);	// Make pin number (pinnum) in port A an output pin
			else
			{
				//Error Handling
			}
		break;
		
		case portB:
			if(direction == IN)
				DDR_B &= ~(1 << pinnum); // Make pin number (pinnum) in port B an input pin
			
			else if(direction == OUT)
				DDR_B |= (1 << pinnum);	// Make pin number (pinnum) in port B an output pin
			
			else
			{
				//Error Handling
			}
		break;
		
		case portC:
			if(direction == IN)
				DDR_C &= ~(1 << pinnum); // Make pin number (pinnum) in port C an input pin
			
			else if(direction == OUT)
				DDR_C |= (1 << pinnum);	// Make pin number (pinnum) in port C an output pin
			
			else
			{
				//Error Handling
			}
		break;
		
		case portD:
			if(direction == IN)
				DDR_D &= ~(1 << pinnum); // Make pin number (pinnum) in port D an input pin
			
			else if(direction == OUT)
				DDR_D |= (1 << pinnum);	// Make pin number (pinnum) in port D an input pin
			
			else
			{
				//Error Handling
			}
		break;
		
		default:
		{
			//Error Handling
		}
	}
}

void DIO_write(uint8_t portnum,uint8_t pinnum, uint8_t value)
{
	switch(portnum)
	{
		case portA:
			if(value == LOW)
				PORT_A &= ~(1 << pinnum); // make pin number (pinnum) in port A has a value of 0
			
			else if(value == HIGH)
				PORT_A |= (1 << pinnum); // make pin number (pinnum) in port A has a value of 1
			
			else
			{
				//Error Handling
			}
		break;
		
		case portB:
			if(value == LOW)
				PORT_B &= ~(1 << pinnum); // make pin number (pinnum) in port B has a value of 0
			
			else if(value == HIGH)
				PORT_B |= (1 << pinnum); // make pin number (pinnum) in port B has a value of 1
			
			else
			{
				//Error Handling
			}
		break;
		
		case portC:
			if(value == LOW)
				PORT_C &= ~(1 << pinnum); // make pin number (pinnum) in port C has a value of 0
			
			else if(value == HIGH)
				PORT_C |= (1 << pinnum); // make pin number (pinnum) in port C has a value of 1
			
			else
			{
				//Error Handling
			}
		break;
		
		case portD:
			if(value == LOW)
				PORT_D &= ~(1 << pinnum); // make pin number (pinnum) in port D has a value of 0
			
			else if(value == HIGH)
				PORT_D |= (1 << pinnum); // make pin number (pinnum) in port D has a value of 1
			
			else
			{
				//Error Handling
			}
		break;
		
		default:
		{
			//Error Handling
		}
	}
}

void DIO_toggle(uint8_t portnum,uint8_t pinnum)
{
	switch(portnum)
	{
		case portA:
			PORT_A ^= (1 << pinnum); // toggle pin number (pinnum) in port A
		break;
		
		case portB:
			PORT_B ^= (1 << pinnum); // toggle pin number (pinnum) in port B
		break;
		
		case portC:
			PORT_C ^= (1 << pinnum); // toggle pin number (pinnum) in port C
		break;
		
		case portD:
			PORT_D ^= (1 << pinnum); // toggle pin number (pinnum) in port D
		break;
		
		default:
		{
			//Error Handling
		}
	}
}

void DIO_read(uint8_t portnum,uint8_t pinnum, uint8_t *value)
{
	switch(portnum)
	{
		case portA:
			*value = (PIN_A & (1 << pinnum)) >> pinnum; // save the value of pin number (pinnum) in port A in a variable
		break;
		
		case portB:
			*value = (PIN_B & (1 << pinnum)) >> pinnum; // save the value of pin number (pinnum) in port B in a variable
		break;
		
		case portC:
			*value = (PIN_C & (1 << pinnum)) >> pinnum; // save the value of pin number (pinnum) in port C in a variable
		break;
		
		case portD:
			*value = (PIN_D & (1 << pinnum)) >> pinnum; // save the value of pin number (pinnum) in port D in a variable
		break;
		
		default:
		{
			//Error Handling
		}
	}
}


