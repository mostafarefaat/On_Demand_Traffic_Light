/*
 * led.c
 *
 * Created: 19-Oct-23 6:34:54 PM
 *  Author: mosta
 */ 
//include .h
#include "led.h"

// global variables

// functions definitions
void LED_init(uint8_t ledport, uint8_t ledpin)
{
	DIO_init(ledport, ledpin, OUT);
}
void LED_on(uint8_t ledport, uint8_t ledpin)
{
	DIO_write(ledport, ledpin, HIGH);
}
void LED_off(uint8_t ledport, uint8_t ledpin)
{
	DIO_write(ledport, ledpin, LOW);
}
void LED_toggle(uint8_t ledport, uint8_t ledpin)
{
	DIO_toggle(ledport, ledpin);
}

	

