/*
 * SEVEN_SEGMENTS.c
 *
 * Created: 7/22/2023 2:07:58 PM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include "DIO.h"
#include "SEVEN_SEG.h"

int main(void)
{
	Segment_Init();
    while (1) 
    {
		Segment_Icrease();
    }
}

