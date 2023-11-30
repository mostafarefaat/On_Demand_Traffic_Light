/*
 * timer0.h
 *
 * Created: 20-Oct-23 11:16:20 AM
 *  Author: mosta
 */ 
 
 //include .h
#include "../../utilities/registers.h"
#include "../../utilities/bit_manipulation.h"
#include "../DIO Driver/dio.h"
#include <math.h>

 
 
#define Normal 0x00
#define PWM_Phase_Correct 0x01
#define CTC 0x02
#define Fast_PWM 0x03
 

#define no_prescale			1
#define prescale8			8
#define prescale64			64
#define prescale256			256		
#define prescale1024		1024
#define External_Falling	5
#define External_Raising	6

#define  CPU_Frequency pow(10,6)



#ifndef TIMER0_H_
#define TIMER0_H_

unsigned int overflows_counter;
//functions declarations

void TIMER_set(uint8_t Mode);
void TIMER_start(uint16_t prescale);
void TIMER_overflow_read(void);
void TIMER_stop(void);
void TIMER0_delay(uint16_t Time_delay, uint16_t prescale);




#endif /* TIMER0_H_ */