/*
 * main.c
 *
 * Created: 8/4/2023 11:03:54 AM
 *  Author: Owner
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "counter.h"
#include <util/delay.h> 
#include "gpio.h"
#include <avr/interrupt.h>



#define BUTTON_PRESSED     LOGIC_HIGH
#define BUTTON_RELEASED    LOGIC_LOW


volatile uint8_t count = 0;

int main(void)
{
	DDRC  |= (1<<PD2);            // Configure the led pin as output pin.
	PORTC &= ~(1<<PD2);           // LED is off at the beginning (Positive Logic).

	SREG  |= (1<<7);              // Enable global interrupts in MC.

	Timer0_Init_CTC_Mode(250);    // Start the timer.

	while(1)
	{

	}
}
