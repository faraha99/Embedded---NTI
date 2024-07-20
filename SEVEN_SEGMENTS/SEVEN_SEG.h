/*
 * 7SEGMENT.h
 *
 *  Created on: Sep 2, 2022
 *      Author: ahmed
 */

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_
#include "DIO.h"

#define Segment_Data_Port DIO_PORTB

#define Segment_EN1 DIO_PIN2

#define Segment_EN2 DIO_PIN1

#define Segment_DIP DIO_PIN3

#define Segment_Data_A DIO_PIN0

#define Segment_Data_B DIO_PIN1

#define Segment_Data_C DIO_PIN2

#define Segment_Data_D DIO_PIN4

void Segment_Init();

void Segment_Icrease();

void Segment_Decrease();

void Segment_Clear();




#endif /* HALL_7SEGMENT_H_ */
