/*
 * registers.h
 *
 * Created: 9/3/2022 2:08:31 PM
 *  Author: Ezz
 */ 

/************************************************************************/
/* Registers of AtMega32 Micro controller                               */
/************************************************************************/

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "typedefs.h"

/************************************************************************/
/* DIO Registers                                                        */
/************************************************************************/

//PORT A
#define PORT_A *((volatile uint8_t *) 0x3B)	//8-bit register 
#define DDR_A  *((volatile uint8_t *) 0x3A)	//8-bit register
#define PIN_A  *((volatile uint8_t *) 0x39)	//8-bit register

//PORT B
#define PORT_B *((volatile uint8_t *) 0x38)	//8-bit register
#define DDR_B  *((volatile uint8_t *) 0x37)	//8-bit register
#define PIN_B  *((volatile uint8_t *) 0x36)	//8-bit register

//PORT C
#define PORT_C *((volatile uint8_t *) 0x35)	//8-bit register
#define DDR_C  *((volatile uint8_t *) 0x34)	//8-bit register
#define PIN_C  *((volatile uint8_t *) 0x33)	//8-bit register

//PORT D
#define PORT_D *((volatile uint8_t *) 0x32)	//8-bit register
#define DDR_D  *((volatile uint8_t *) 0x31)	//8-bit register
#define PIN_D  *((volatile uint8_t *) 0x30)	//8-bit register

//PINS
#define  PIN_0 0
#define  PIN_1 1
#define  PIN_2 2
#define  PIN_3 3
#define  PIN_4 4
#define  PIN_5 5
#define  PIN_6 6
#define  PIN_7 7
#define Green_cars PIN_0
#define Yellow_cars PIN_1
#define Red_cars PIN_2
#define Red_pedestrians PIN_0
#define Yellow_pedestrians PIN_1
#define Green_Pedestrians PIN_2

/************************************************************************/
/* global interrupts register                                           */
/************************************************************************/

#define SREG *((volatile uint8_t *) 0x5F)	//8-bit register

//SREG pins
#define BIT_7_I 7

/************************************************************************/
/* External interrupts registers                                        */
/************************************************************************/

#define MCUCR *((volatile uint8_t *) 0x55)	//8-bit register
#define GICR *((volatile uint8_t *) 0x5B)	//8-bit register

// MCUCR pins
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define SM0 4
#define SM1 5
#define SM2 6
#define SM3 7

// GICR pins
#define IVCE 0
#define IVSEL 1
#define INT_2 5
#define INT_0 6
#define INT_1 7

/************************************************************************/
/* TIMER Registers                                                      */
/************************************************************************/

// Timer - Counter Interrupt Mask Register
#define TIMSK *((volatile uint8_t *) 0x59)	//8-bit register

// TIMSK pins
#define TOIE0 0
#define OCIE0 1
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2 6
#define OCIE2 7

// Timer - Counter Interrupt Flag Register
#define TIFR  *((volatile uint8_t *) 0x58)	//8-bit register

// TIFR pins
#define TOV0 0
#define OCF0 1
#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
#define TOV2 6
#define OCF2 7

//TIMER 0
#define TCCR_0 *((volatile uint8_t *) 0x53)	//8-bit register
#define TCNT_0 *((volatile uint8_t *) 0x52)	//8-bit register

// TCCR0 pins
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7

//TIMER 2
#define TCCR_2 *((volatile uint8_t *) 0x45)	//8-bit register
#define TCNT_2 *((volatile uint8_t *) 0x44)	//8-bit register

// TCCR2 pins
#define CS20 0
#define CS21 1
#define CS22 2
#define WGM21 3
#define COM20 4
#define COM21 5
#define WGM20 6
#define FOC2 7


#endif /* REGISTERS_H_ */