/*
 * WDT.c
 *
 * Created: 8/5/2023 3:00:29 PM
 *  Author: Owner
 */ 

#include <avr/io.h>
#include <util/delay.h>

#include "WDT.h"

#define WDCE   7

//	function to enable Watchdog timer.
void WDT_ON(void)
{
	// Watchdog timer enables with timeout period 2.1 second.
	WDTCR = (1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0);
}

// 	function to disable Watchdog timer.
void WDT_OFF(void)
{
	// Set the WDTOE & WDE bits in the same operation
	WDTCR = (1<<WDTOE)|(1<<WDE);
	// Wait 4 cycles before clear the WDE bit
	_delay_us(4);
	WDTCR = 0x00;
}

//	function to refresh Watchdog timer.
void WDT_Refresh(void)
{
	// Set the WDCE bit
	WDTCR |= (1<<WDCE);
	// Clear the WDE bit
	WDTCR &= ~(1<<WDE);
	// Write a logic one to the WDR register
	WDTCR = 0x00;
}

