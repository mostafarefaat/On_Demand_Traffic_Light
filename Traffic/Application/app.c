/*
 * app.c
 *
 * Created: 10-Nov-23 11:00:23 PM
 *  Author: mosta
 */ 
#include "app.h"

unsigned char current_state = 0;
unsigned char next_state = 0;

void normal_mode(void)
{
	switch(next_state)
	{
		case Red_Light:
		DIO_write(PORT_A,Red_LED,HIGH);
		DIO_write(PORT_B,Green_LED,HIGH);
		next_state = Yellow_Light;
		current_state = Red_Light;
		TIMER0_delay(5000,no_prescale);
		DIO_write(PORT_A,Red_LED,LOW);
		DIO_write(PORT_B,Green_LED,LOW);
		break;
		
		case Yellow_Light:
		DIO_write(PORT_A,Yellow_LED,HIGH);
		DIO_write(PORT_B,Yellow_LED,HIGH);
		next_state = Green_Light;
		current_state = Yellow_Light;
		TIMER0_delay(5000,no_prescale);
		DIO_write(PORT_A,Yellow_LED,LOW);
		DIO_write(PORT_B,Yellow_LED,LOW);
		break;

		case Green_Light:
		DIO_write(PORT_A,Green_LED,HIGH);
		DIO_write(PORT_B,Red_LED,HIGH);
		next_state = Yellow_Light_2;
		current_state = Green_Light;
		TIMER0_delay(5000,no_prescale);
		DIO_write(PORT_A,Green_LED,LOW);
		DIO_write(PORT_B,Red_LED,LOW);
		break;

		case Yellow_Light_2:
		DIO_write(PORT_A,Yellow_LED,HIGH);
		DIO_write(PORT_B,Yellow_LED,HIGH);
		next_state = Red_Light;
		current_state = Yellow_Light_2;
		TIMER0_delay(5000,no_prescale);
		DIO_write(PORT_A,Yellow_LED,LOW);
		DIO_write(PORT_B,Yellow_LED,LOW);
		break;
		
		default:
		break;
	}
}


void pedestrian_mode(void)
{
	PORTB = 0x00;
	if(current_state == Red_Light)
	{
		DIO_write(PORT_A,PIN0,HIGH); /*Cars RED led ON*/
		DIO_write(PORT_B,PIN2,HIGH); /*pedestrian GREEN led ON*/
		TIMER0_delay(5000,no_prescale);
		
	}
	else if(current_state == Green_Light || current_state == Yellow_Light || current_state == Yellow_Light_2)
	{
		DIO_write(PORT_B,PIN0,HIGH);	 /*pedestrian RED led ON*/
		DIO_write(PORT_B,PIN1,HIGH);	/*pedestrian YELLOW led ON*/
		DIO_write(PORT_A,PIN1,HIGH);	/*Cars YELLOW led ON*/
		
		TIMER0_delay(5000,no_prescale);
		
		DIO_write(PORT_B,PIN0,LOW);      /*pedestrian RED led OFF*/
		DIO_write(PORT_B,PIN1,LOW);      /*pedestrian YELLOW led OFF*/
		DIO_write(PORT_A,PIN2,LOW);		 /*Cars GREEN led OFF*/
		DIO_write(PORT_A,PIN1,LOW);		 /*Cars YELLOW led OFF*/
		
		
		DIO_write(PORT_A,PIN0,HIGH);	/*Cars RED led ON*/
		DIO_write(PORT_B,PIN2,HIGH);	/*pedestrian GREEN led ON*/
		TIMER0_delay(5000,no_prescale);
		
		DIO_write(PORT_A,PIN0,LOW);		/*Cars RED led OFF*/
		DIO_write(PORT_A,PIN1,HIGH);	/*Cars YELLOW led ON*/
		DIO_write(PORT_B,PIN1,HIGH);   /*pedestrian YELLOW led ON*/
		TIMER0_delay(5000,no_prescale);
		
		DIO_write(PORT_B,PIN2,LOW);		/*pedestrian GREEN led OFF*/
		DIO_write(PORT_B,PIN1,LOW);     /*pedestrian YELLOW led OFF*/
		DIO_write(PORT_B,PIN0,HIGH);	/*pedestrian RED led ON*/
		DIO_write(PORT_A,PIN2,HIGH);	/*Cars GREEN led ON*/
		DIO_write(PORT_A,PIN1,LOW);		/*Cars YELLOW led OFF*/
		
		if(current_state == Green_Light)
		{
			next_state = Yellow_Light_2;
		}
		else if( current_state == Yellow_Light || current_state == Yellow_Light_2)
		{
			next_state = Green_Light;
		}
		else
		{
			
		}
	}
}


void traffic_init(void)
{
	/*Setting the LEDs of the cars and the pedestrian to be outputs*/
	DIO_init(PORT_A,PIN0,OUT);
	DIO_init(PORT_A,PIN1,OUT);
	DIO_init(PORT_A,PIN2,OUT);
	DIO_init(PORT_B,PIN0,OUT);
	DIO_init(PORT_B,PIN1,OUT);
	DIO_init(PORT_B,PIN2,OUT);
	
	/*Setting the Interrupt PIN2 in PORTD to be input*/
	DIO_init(PORT_D,PIN2,IN);
	
	
	/*Initializing the outputs pins to be LOW*/
	DIO_write(PORT_A,PIN0,LOW);
	DIO_write(PORT_A,PIN1,LOW);
	DIO_write(PORT_A,PIN2,LOW);
	DIO_write(PORT_B,PIN0,LOW);
	DIO_write(PORT_B,PIN1,LOW);
	DIO_write(PORT_B,PIN2,LOW);

	/*Enable the interrupts*/
	sei();
	SET_BIT(MCUCR,PIN0);
	SET_BIT(MCUCR,PIN1);
	SET_BIT(GICR,PIN6);
}