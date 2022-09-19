/*
 * dio.h
 *
 * Created: 9/3/2022 2:22:06 PM
 *  Author: Ezz
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../utilities/registers.h"

#define portA 'A'
#define portB 'B'
#define portC 'C'
#define portD 'D'

#define HIGH 1
#define LOW 0

#define OUT 1
#define IN 0

void DIO_init(uint8_t portnum,uint8_t pinnum, uint8_t direction); // initializations of a pin
void DIO_write(uint8_t portnum,uint8_t pinnum, uint8_t value); // write data to a pin
void DIO_toggle(uint8_t portnum,uint8_t pinnum); // toggle a pin
void DIO_read(uint8_t portnum,uint8_t pinnum, uint8_t *value); // read a pin

#endif /* DIO_H_ */