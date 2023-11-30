/*
 * app.h
 *
 * Created: 10-Nov-23 11:00:15 PM
 *  Author: mosta
 */ 

#include "../MCAL/DIO Driver/dio.h"
#include "../MCAL/Interrupt Library/interrupt.h"
#include "../MCAL/TIMER0/timer0.h"

#define Red_Light		0
#define Yellow_Light	1
#define Green_Light		2
#define Yellow_Light_2  3

#define Red_LED			0
#define Yellow_LED		1
#define Green_LED		2



void normal_mode(void);
void pedestrian_mode(void);
void traffic_init(void);


#ifndef APP_H_
#define APP_H_


#endif /* APP_H_ */