/*
 * dio.c
 *
 * Created: 19-Oct-23 4:09:29 PM
 *  Author: mosta
 */ 
// include .h
#include "dio.h"


// global variables
// functions definitions
void DIO_init(uint8_t port_number, uint8_t pin_number, uint8_t direction)
{
	switch(port_number)
	{
		case PORT_A:
		if(direction == OUT)
		{
			//DDRA |= (1<<pin_number); //output
			SET_BIT(DDRA, pin_number);
			
		}
		else if(direction == IN)
		{
			//DDRA &= ~(1<<pin_number); // input
			ClEAR_BIT(DDRA, pin_number);
		}
		else
		{
			//ERROR handling
		}
		break;
		
		case PORT_B:
		if(direction == OUT)
		{
			//DDRB |= (1<<pin_number);
			SET_BIT(DDRB, pin_number);
		}
		else if(direction == IN)
		{
			//DDRB &= ~(1<<pin_number);
			ClEAR_BIT(DDRB, pin_number);
		}
		else
		{
			//ERROR handling
		}
		break;
		
		case PORT_C:
		if(direction == OUT)
		{
			//DDRC |= (1<<pin_number);
			SET_BIT(DDRC, pin_number);
		}
		else if(direction == IN)
		{
			//DDRC &= ~(1<<pin_number);
			ClEAR_BIT(DDRC, pin_number);
		}
		else
		{
			//ERROR handling
		}
		break;
		
		case PORT_D:
		if(direction == OUT)
		{
			//DDRD |= (1<<pin_number);
			SET_BIT(DDRD, pin_number);
		}
		else if(direction == IN)
		{
			//DDRD &= ~(1<<pin_number);
			ClEAR_BIT(DDRD, pin_number);
		}
		else
		{
			//ERROR handling
		}
		break;
	 	default:
	 	break;
	}
}

void DIO_write(uint8_t port_number, uint8_t pin_number, uint8_t value)
{
		switch(port_number)
		{
			case PORT_A:
			if(value == HIGH)
			{
				//PORTA |= (1<<pin_number); //write 1
				SET_BIT(PORTA, pin_number);
			}
			else if(value == LOW)
			{
				//PORTA &= ~(1<<pin_number); // write 0
				ClEAR_BIT(PORTA, pin_number);
			}
			else
			{
				//ERROR handling
			}
			break;
			
			case PORT_B:
			if(value == HIGH)
			{
				//PORTB |= (1<<pin_number); //write 1
				SET_BIT(PORTB, pin_number);
			}
			else if(value == LOW)
			{
				//PORTB &= ~(1<<pin_number); // write 0
				ClEAR_BIT(PORTB, pin_number);
			} 
			else
			{
				//ERROR handling
			}
			break;
			
			case PORT_C:
			if(value == HIGH)
			{
				//PORTC |= (1<<pin_number); //write 1
				SET_BIT(PORTC, pin_number);
			}
			else if(value == LOW)
			{
				//PORTC &= ~(1<<pin_number); //write 0
				ClEAR_BIT(PORTC, pin_number);
			}
			else
			{
				//ERROR handling
			}
			break;
			
			case PORT_D:
			if(value == HIGH)
			{
				//PORTD |= (1<<pin_number); //write 1
				SET_BIT(PORTD, pin_number);
			}
			else if(value == LOW)
			{
				//PORTD &= ~(1<<pin_number); //write 0
				ClEAR_BIT(PORTD, pin_number);
			}
			else
			{
				//ERROR handling
			}
			break;
			default:
			break;
		}	
}

void DIO_read(uint8_t port_number, uint8_t pin_number, uint8_t *value)
{  
 		switch(port_number)
 		{
	 		case PORT_A:
				*value = READ_BIT(PINA, pin_number);
	 		break;
	 		
	 		case PORT_B:
				*value = READ_BIT(PINB, pin_number);
	 		break;
	 		
	 		case PORT_C:
				*value = READ_BIT(PINC, pin_number);
	 		break;
	 		
	 		case PORT_D:
				*value = READ_BIT(PIND, pin_number);
	 		break;
			
			default:
			break;
 		}	
		
}

void DIO_toggle(uint8_t port_number, uint8_t pin_number)
{
 		switch(port_number)
 		{
	 		case PORT_A:
	 		TOGGLE_BIT(PORTA, pin_number);
	 		break;
	 		
	 		case PORT_B:
	 		TOGGLE_BIT(PORTB, pin_number);
	 		break;
	 		
	 		case PORT_C:
	 		TOGGLE_BIT(PORTC, pin_number);
	 		break;
	 		
	 		case PORT_D:
	 		TOGGLE_BIT(PORTD, pin_number);
	 		break;
	 		
	 		default:
	 		break;
 		}	
}