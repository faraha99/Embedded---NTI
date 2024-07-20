/*
 * main.c
 *
 * Created: 8/5/2023 2:50:04 PM
 *  Author: Owner
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "WDT.h"

int main(void)
{
	// Enable the Watchdog timer
	WDT_ON();

	// Configure PD6 as output pin
	DDRD |= (1<<PD6);

	// Toggle the led every reset
	PORTD |= (1<<PD6);
	_delay_ms(2200);
	PORTD &= ~(1<<PD6);

	// Refresh the watchdog timer
	WDT_Refresh();

	// Wait until the watch-dog reset the system
	while(1);
}
