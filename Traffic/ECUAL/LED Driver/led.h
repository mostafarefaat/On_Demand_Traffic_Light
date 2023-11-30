/*
 * led.h
 *
 * Created: 19-Oct-23 6:34:46 PM
 *  Author: mosta
 */ 
//include .h
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/TIMER0/timer0.h"



#ifndef LED_H_
#define LED_H_

// all internal driver typedefs
// all driver macros
// all functions prototype

void LED_init(uint8_t ledport, uint8_t ledpin);		// calls dio_init
void LED_on(uint8_t ledport, uint8_t ledpin);	// turns led on
void LED_off(uint8_t ledport, uint8_t ledpin);	// turns led off
void LED_toggle(uint8_t ledport, uint8_t ledpin);	// toggle led 



#endif /* LED_H_ */