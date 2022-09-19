/*
 * led.h
 *
 * Created: 9/3/2022 5:09:43 PM
 *  Author: Ezz
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"

void LED_init(uint8_t ledport, uint8_t ledpin); // output device
void LED_on(uint8_t ledport, uint8_t ledpin); // turn on a LED
void LED_off(uint8_t ledport, uint8_t ledpin); // turn off a LED
void LED_toggle(uint8_t ledport, uint8_t ledpin); // toggle a LED



#endif /* LED_H_ */