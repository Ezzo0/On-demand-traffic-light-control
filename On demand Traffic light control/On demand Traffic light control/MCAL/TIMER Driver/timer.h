/*
 * timer.h
 *
 * Created: 9/11/2022 4:13:23 PM
 *  Author: Ezz
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../INTURREPTS Driver/interrupts.h"
#include "../DIO Driver/dio.h"

// Modes Macros
#define normal 'n'
#define pwm 'p'
#define ctc 'c'
#define fast_pwm 'f'
#define overflows_0 20
#define overflows_2 14
#define initial_value_0 11
#define initial_value_2 47

void timer0_select_mode(uint8_t mode);
void timer0_set_initial_value(uint8_t value);
void timer0_timer_start(int prescalar,uint8_t overflows);
void timer0_timer_reset();
void timer0_timer_stop();
void timer2_select_mode(uint8_t mode);
void timer2_set_initial_value(uint8_t value);
void timer2_timer_start(int prescalar,uint8_t overflows);
void timer2_timer_reset();
void timer2_timer_stop();

#endif /* TIMER_H_ */