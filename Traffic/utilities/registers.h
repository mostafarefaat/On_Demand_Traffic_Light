/*
 * registers.h
 *
 * Created: 19-Oct-23 3:53:32 PM
 *  Author: mosta
 */ 
//include .h
#include "types.h"

#ifndef REGISTERS_H_
#define REGISTERS_H_

/*-------------------------------------------------- DIO I/O PINS --------------------------------------------------*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
/*-------------------------------------------------- END OF DIO I/O PINS --------------------------------------------------*/

/*-------------------------------------------------- DIO REGISTERS--------------------------------------------------*/

/*------------------------------PORTA REGISTERS------------------------------*/
#define PORTA *((volatile uint8_t *)0x3B)
#define DDRA *((volatile uint8_t *)0x3A)
#define PINA *((volatile uint8_t *)0x39)
/*------------------------------PORTB REGISTERS------------------------------*/
#define PORTB *((volatile uint8_t *)0x38)
#define DDRB *((volatile uint8_t *)0x37)
#define PINB *((volatile uint8_t *)0x36)
/*------------------------------PORTC REGISTERS------------------------------*/
#define PORTC *((volatile uint8_t *)0x35)
#define DDRC *((volatile uint8_t *)0x34)
#define PINC *((volatile uint8_t *)0x33)
/*------------------------------PORTD REGISTERS------------------------------*/
#define PORTD *((volatile uint8_t *)0x32)
#define DDRD *((volatile uint8_t *)0x31)
#define PIND *((volatile uint8_t *)0x30)
/*--------------------------------------------------END OF DIO REGISTERS--------------------------------------------------*/

/*-------------------------------------------------- TIMERS INTERUPTS REGISTERS--------------------------------------------------*/

#define TIFR *((volatile uint8_t *)0x58)
#define TIMSK *((volatile uint8_t *)0x59)

/*--------------------------------------------------END OF TIMERS INTERUPTS REGISTERS--------------------------------------------------*/



/*-------------------------------------------------- TIMER 0 REGISTERS--------------------------------------------------*/

#define TCCR0 *((volatile uint8_t *)0x53)
#define TCNT0 *((volatile uint8_t *)0x52)

/*--------------------------------------------------END OF TIMER 0 REGISTERS--------------------------------------------------*/

/*--------------------------------------------------  INTERRUPTS REGISTERS--------------------------------------------------*/

#define SREG *((volatile uint8_t *)0x5F)
#define MCUCR *((volatile uint8_t *)0x55)
#define MCUCSR *((volatile uint8_t *)0x54)
#define GICR *((volatile uint8_t *)0x5B)
#define GIFR *((volatile uint8_t *)0x5A)

/*--------------------------------------------------END OF INTERRUPTS REGISTERS--------------------------------------------------*/

/*--------------------------------------------------  ADC REGISTERS--------------------------------------------------*/

#define ADMUX *((volatile uint8_t *)0x27)
#define ADCSRA *((volatile uint8_t *)0x26)
#define ADCH *((volatile uint8_t *)0x25)
#define ADCL *((volatile uint8_t *)0x24)
#define SFIOR *((volatile uint8_t *)0x50)

/*--------------------------------------------------END OF ADC REGISTERS--------------------------------------------------*/

/*--------------------------------------------------  UART REGISTERS--------------------------------------------------*/

#define UBRRH *((volatile uint8_t *)0x40)
#define UBRRL *((volatile uint8_t *)0x29)
#define UCSRA *((volatile uint8_t *)0x2B)
#define UCSRB *((volatile uint8_t *)0x2A)
#define UCSRC *((volatile uint8_t *)0x40)
#define UDR *((volatile uint8_t *)0x2C)

/*--------------------------------------------------END OF UART REGISTERS--------------------------------------------------*/

/*--------------------------------------------------  SPI REGISTERS--------------------------------------------------*/

#define SPDR *((volatile uint8_t *)0x2F)
#define SPSR *((volatile uint8_t *)0x2E)
#define SPCR *((volatile uint8_t *)0x2D)


/*--------------------------------------------------END OF SPI REGISTERS--------------------------------------------------*/

/*--------------------------------------------------  I2C REGISTERS--------------------------------------------------*/

#define TWBR *((volatile uint8_t *)0x20)
#define TWCR *((volatile uint8_t *)0x56)
#define TWSR *((volatile uint8_t *)0x21)
#define TWDR *((volatile uint8_t *)0x23)
#define TWAR *((volatile uint8_t *)0x22)


/*--------------------------------------------------END OF I2C REGISTERS--------------------------------------------------*/


#endif /* REGISTERS_H_ */