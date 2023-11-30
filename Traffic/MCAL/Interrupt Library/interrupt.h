/*
 * interrupt.h
 *
 * Created: 23-Oct-23 5:37:56 PM
 *  Author: mosta
 */ 
#include "../../utilities/bit_manipulation.h"
#include "../../utilities/registers.h"

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/*External interrupt Vectors*/
/*External interrupt Request 1*/
#define  EXT_INT_0	__vector_1
/*External interrupt Request 2*/
#define  EXT_INT_1	__vector_2
/*External interrupt Request 3*/
#define  EXT_INT_2	__vector_3

/*Set Global interrupts bit 7 in SREG*/
#define sei() SET_BIT(SREG,PIN7)
//#define sei() __asm__ __volatile__ ("sei" ::: "memory")
/*Clear Global interrupts bit 7 in SREG*/
#define cli() ClEAR_BIT(SREG,PIN7)
//#define cli() __asm__ __volatile__ ("cli" ::: "memory")	
/*ISR Definition*/
#define ISR(INT_Vect)void INT_Vect(void) __attribute__ ((signal,used));\
void INT_Vect(void)

	




#endif /* INTERRUPT_H_ */