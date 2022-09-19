/*
 * interupts.h
 *
 * Created: 9/11/2022 11:20:20 PM
 *  Author: Ezz
 */ 


#ifndef INTERUPTS_H_
#define INTERUPTS_H_

#include "../../utilities/registers.h"

// Macros of Vectors
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2
#define EXT_INT_2 __vector_3
#define TIMER_0_OVF __vector_11
#define TIMER_2_OVF __vector_5

// Macro of interrupt service routine function
#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

void enable_global_interrupts();
void timer0_enable_overflow_interrupt();
void timer2_enable_overflow_interrupt();
void enable_button_interrupt();



#endif /* INTERUPTS_H_ */