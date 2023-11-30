/*
 * dio.h
 *
 * Created: 19-Oct-23 4:09:40 PM
 *  Author: mosta
 */ 
//include .h
#include "../../utilities/registers.h"
#include "../../utilities/bit_manipulation.h"

#ifndef DIO_H_
#define DIO_H_

// all internal driver typedefs
// all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define IN 0
#define OUT 1

#define LOW 0
#define HIGH 1

// all functions prototype
void DIO_init(uint8_t port_number, uint8_t pin_number, uint8_t direction); // initialize the DIO pin

void DIO_write(uint8_t port_number, uint8_t pin_number, uint8_t value); // write on the DIO pin

void DIO_read(uint8_t port_number, uint8_t pin_number, uint8_t *value); // read from the DIO pin

void DIO_toggle(uint8_t port_number, uint8_t pin_number); // toggle the DIO pin


#endif /* DIO_H_ */