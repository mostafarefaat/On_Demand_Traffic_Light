/*
 * timer0.c
 *
 * Created: 20-Oct-23 11:16:06 AM
 *  Author: mosta
 */ 
//include .h

#include "timer0.h"

//global variables


unsigned int Number_of_overflows_needed;
float prescale_int_Value;
float Timer_Tick;
float Timer_Delay_max;
float Time_delay_;
uint8_t Timer_initial_value;

//functions definitions

void TIMER_set(uint8_t Mode)
{
	switch(Mode)
	{
		case Normal:
			ClEAR_BIT(TCCR0, PIN3) ;		//Normal Mode
			ClEAR_BIT(TCCR0, PIN6) ;	
		break;
		
		case PWM_Phase_Correct:
			ClEAR_BIT(TCCR0, PIN3) ;
			SET_BIT(TCCR0, PIN6) ;			//PWM_Phase_Correct Mode
		break;	
			
		case CTC:
			SET_BIT(TCCR0, PIN3) ;			//CTC Mode
			ClEAR_BIT(TCCR0, PIN6) ;			
		break;
		
		case Fast_PWM:
			SET_BIT(TCCR0, PIN3) ;			//Fast_PWM Mode
			SET_BIT(TCCR0, PIN6) ;			
		break;
		
		default:
		
		break;
			
	}
	
}
void TIMER_start(uint16_t prescale)
{
	switch(prescale)
	{
		case no_prescale:				//No prescaling
			TCCR0 |= 0b00000001;
		break;
		
		case prescale8:					//8 prescaling
			TCCR0 |= 0b00000010;
		break;

		case prescale64:				//64 prescaling
			TCCR0 |= 0b00000011;
		break;
		
		case prescale256:				// 256 prescaling
			TCCR0 |= 0b00000100;
		break;
		
		case prescale1024:				//1024 prescaling
			TCCR0 |= 0b00000101;
		break;
		
		case External_Falling: //External_Falling on T0 pin
			TCCR0 |= 0b00000110;
		break;


		case External_Raising : //External_Raising on T0 pin
			TCCR0 |= 0b00000111;
		break;	
	}
	
}
void TIMER_overflow_read(void)
{
	//wait until the overflow flag is set
	while((READ_BIT(TIFR, PIN0) == 0));
	
	//Clear the OverFlow flag
	SET_BIT(TIFR, PIN0);
}
void TIMER_stop(void)
{
	//Stop the timer
	TCCR0 = 0x00;
	TCNT0 = 0x00;
	overflows_counter = 0;
	Time_delay_ = 0;
	Timer_Tick = 0;
	Timer_Delay_max = 0;
}

void TIMER0_delay(uint16_t Time_delay, uint16_t prescale)
{
	Time_delay_ = Time_delay*0.001;
	
	Timer_Tick = ( (prescale) / (pow(10.0,6.0)) );
	
	Timer_Delay_max = 	(Timer_Tick) * (256.0);
	
	if(Time_delay_ < Timer_Delay_max)
	{
		Timer_initial_value = ( (Timer_Delay_max - Time_delay_ ) / (Timer_Tick) );
			
		Number_of_overflows_needed = 1;
	}
	else if(Time_delay_ == Timer_Delay_max)
	{
		Timer_initial_value = 0x00;
		Number_of_overflows_needed = 1;
	}	
	
	else if(Time_delay_ > Timer_Delay_max)
	{
		Number_of_overflows_needed = ceil((Time_delay_/Timer_Delay_max));
		Timer_initial_value = (ceil((256) - ((Time_delay_/Timer_Tick)/(Number_of_overflows_needed))));
	}
	
	TCNT0 = Timer_initial_value;		// setting initial value
	
	TIMER_start(prescale);

	while(overflows_counter < Number_of_overflows_needed)
	{
		TIMER_overflow_read();
		overflows_counter++;
	}
	overflows_counter = 0;
	
	TIMER_stop();
}


