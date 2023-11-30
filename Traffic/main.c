/*
 * Traffic.c
 *
 * Created: 10-Nov-23 2:56:36 PM
 * Author : mosta
 */ 

#include "MCAL/DIO Driver/dio.h"
#include "MCAL/Interrupt Library/interrupt.h"
#include "ECUAL/LED Driver/led.h"
#include <util/delay.h>

#define Red_Light		0
#define Yellow_Light	1
#define Green_Light		2
#define Yellow_Light_2  3

#define Red_LED 0
#define Yellow_LED 1
#define Green_LED 2

#define Button_pressed		1
#define Button_Not_pressed  0

#define ISR_Called			1
#define ISR_Not_Called		0

uint8_t current_state = 0;
uint8_t next_state = 0;
uint8_t counter = 0;
uint8_t Button_state = Button_Not_pressed;
uint8_t ISR_state = ISR_Not_Called;

void normal_mode(void);
void pedestrian_mode(void);
void traffic_init(void);

int main(void)
{
	traffic_init();	
    /* Replace with your application code */
    while (1) 
    {
		normal_mode();
    }
}
ISR(EXT_INT_0)
{
	DIO_write(PORT_D,PIN4,HIGH);
	if(Button_state == Button_Not_pressed)
	{
		ISR_state = ISR_Called;
		DIO_write(PORT_D,PIN3,HIGH);
		pedestrian_mode();
		DIO_write(PORT_D,PIN4,LOW);
	}
}

void normal_mode(void)
{
	DIO_write(PORT_D,PIN3,LOW);
	switch(next_state)
	{
		case Red_Light:
		DIO_write(PORT_A,Red_LED,HIGH);
		DIO_write(PORT_B,Green_LED,HIGH);
		next_state = Yellow_Light;
		current_state = Red_Light;
		TIMER0_delay(5000,no_prescale);
		ISR_state = ISR_Not_Called;
		DIO_write(PORT_A,Red_LED,LOW);
		DIO_write(PORT_B,Green_LED,LOW);
		break;
			
		case Yellow_Light:
		DIO_write(PORT_A,Yellow_LED,HIGH);
		DIO_write(PORT_B,Yellow_LED,HIGH);
		next_state = Green_Light;
		current_state = Yellow_Light;
		while(counter < 5 && ISR_state == ISR_Not_Called)
		{
			TIMER0_delay(1000,no_prescale);
			LED_toggle(PORT_A,PIN1);
			LED_toggle(PORT_B,PIN1);
			counter++;
		}
		counter = 0;
		ISR_state = ISR_Not_Called;
		DIO_write(PORT_A,Yellow_LED,LOW);
		DIO_write(PORT_B,Yellow_LED,LOW);
		break;

		case Green_Light:
		DIO_write(PORT_A,Green_LED,HIGH);
		DIO_write(PORT_B,Red_LED,HIGH);
		next_state = Yellow_Light_2;
		current_state = Green_Light;
		TIMER0_delay(5000,no_prescale);
		ISR_state = ISR_Not_Called;
		DIO_write(PORT_A,Green_LED,LOW);
		DIO_write(PORT_B,Red_LED,LOW);
		break;

		case Yellow_Light_2:
		DIO_write(PORT_A,Yellow_LED,HIGH);
		DIO_write(PORT_B,Yellow_LED,HIGH);
		next_state = Red_Light;
		current_state = Yellow_Light_2;
		while(counter < 5 && ISR_state == ISR_Not_Called)
		{
			TIMER0_delay(1000,no_prescale);
			LED_toggle(PORT_A,PIN1);
			LED_toggle(PORT_B,PIN1);
			counter++;
		}
		counter = 0;
		ISR_state = ISR_Not_Called;
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
	counter = 0;
	Button_state = Button_pressed;
	//_delay_ms(500);
	//DIO_write(PORT_D,PIN3,LOW);
	TIMER_stop();
	if(current_state == Red_Light)
	{
		DIO_write(PORT_A,PIN0,HIGH); /*Cars RED led ON*/
		DIO_write(PORT_B,PIN2,HIGH); /*pedestrian GREEN led ON*/
		TIMER0_delay(5000,no_prescale);
		Button_state = Button_Not_pressed;
	
	}
	else if(current_state == Green_Light || current_state == Yellow_Light || current_state == Yellow_Light_2)
	{
		DIO_write(PORT_B,PIN0,HIGH);	 /*pedestrian RED led ON*/
		DIO_write(PORT_B,PIN1,HIGH);	/*pedestrian YELLOW led ON*/
		DIO_write(PORT_A,PIN1,HIGH);	/*Cars YELLOW led ON*/
		while(counter < 5)
		{
			TIMER0_delay(1000,no_prescale);
			LED_toggle(PORT_A,PIN1);
			LED_toggle(PORT_B,PIN1);
			counter++;
		}
		counter = 0;		
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
		while(counter < 5)
		{
			TIMER0_delay(1000,no_prescale);
			LED_toggle(PORT_A,PIN1);
			LED_toggle(PORT_B,PIN1);
			counter++;
		}
		counter = 0;
		DIO_write(PORT_B,PIN2,LOW);		/*pedestrian GREEN led OFF*/
		DIO_write(PORT_B,PIN1,LOW);     /*pedestrian YELLOW led OFF*/
		DIO_write(PORT_B,PIN0,HIGH);	/*pedestrian RED led ON*/	
		DIO_write(PORT_A,PIN2,HIGH);	/*Cars GREEN led ON*/
		DIO_write(PORT_A,PIN1,LOW);		/*Cars YELLOW led OFF*/
		
		if(current_state == Green_Light)
		{
			TIMER0_delay(5000,no_prescale);
			next_state = Yellow_Light_2;
		}
		else if( current_state == Yellow_Light || current_state == Yellow_Light_2)
		{
			next_state = Green_Light;
		}
		else
		{
			
		}
		Button_state = Button_Not_pressed;		
	}	
	TIMER_start(no_prescale);
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
	
	/*LEDs for debugging only*/
	DIO_init(PORT_D,PIN3,OUT);
	DIO_init(PORT_D,PIN4,OUT);	
	DIO_write(PORT_D,PIN3,LOW);
	DIO_write(PORT_D,PIN4,LOW);
	
	/*Enable the interrupts*/
	sei();
	SET_BIT(MCUCR,PIN0);
	SET_BIT(MCUCR,PIN1);	
	SET_BIT(GICR,PIN6);	
}