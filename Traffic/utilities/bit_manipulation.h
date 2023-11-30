/*
 * bit_manipulation.h
 *
 * Created: 19-Oct-23 5:14:45 PM
 *  Author: mosta
 */ 
//include .h

#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H

#define SET_BIT( port,  pin_number)	(port |= (1<<pin_number))		// sets the specified bit

#define ClEAR_BIT( port,  pin_number)	(port &= ~(1<<pin_number))				// clears the specified bit

#define READ_BIT( port,  pin_number)	((port & (1<<pin_number))>>pin_number)		// gets state 1 or 0

#define TOGGLE_BIT( port,  pin_number)	(port ^= (1<<pin_number))		// flips the specified bit

#endif /* BIT_MANIPULATION_H_ */