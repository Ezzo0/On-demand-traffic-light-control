/*
 * button.h
 *
 * Created: 9/3/2022 6:09:51 PM
 *  Author: Ezz
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../LED Driver/led.h"
#include "../../MCAL/TIMER Driver/timer.h"

#define Green_state 0
#define Yellow1_state 1
#define Red_state 2
#define Yellow2_state 3
#define Button_pushed 1
#define Button_not_pushed 0
#define Interrupt_happened 1
#define Interrupt_not_happened 0

//Initialize button port
void BUTTON_init(uint8_t buttonport, uint8_t buttonpin);

// button read
void BUTTON_read(uint8_t buttonport,uint8_t buttonpin, uint8_t *value);

#endif /* BUTTON_H_ */