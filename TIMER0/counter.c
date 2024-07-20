/*
 * counter.c
 *
 * Created: 8/4/2023 11:10:19 AM
 *  Author: Owner
 */ 
#include "counter.h"
#include "timer_reg.h"
#include "std_types.h"
#include <avr/interrupt.h>


#include <avr/io.h>

#define NUMBER_OF_COMPARE_MTACHES_PER_HALF_SECOND 2

/* global variable contain the ticks count of the timer */
unsigned char g_tick = 0;


/*
void Timer0_Init_Normal_Mode(void)
{
	
	
	TCNT0 = 0;

	// Enable Timer0 Overflow Interrupt
	TIMSK |= (1 << TOIE0);

	// Configure the timer control register
	// 1. Non PWM mode FOC0=1
	// 2. Normal Mode WGM01=0 & WGM00=0
	// 3. Normal Mode COM00=0 & COM01=0
	// 4. clock = F_CPU/1024 CS00=0 CS01=1 CS02=1
	TCCR0 = (1 << FOC0) | (1 << CS02) | (1 << CS00);

	
}
*/
/*
void Timer0_Init_Normal_Mode(void)
{
	// Set Timer initial value to 0
	TCNT0 = 0;

	// Enable Timer0 Overflow Interrupt
	TIMSK |= (1 << TOIE0);

	// Configure the timer control register
	// 1. Non PWM mode FOC0=1
	// 2. Normal Mode WGM01=0 & WGM00=0
	// 3. Normal Mode COM00=0 & COM01=0
	// 4. clock = F_CPU/1 (CS00=0 CS01=0 CS02=0)
	TCCR0 = (1 << FOC0);
}

*/
void Timer0_Init_CTC_Mode(unsigned char tick)
{
	TCNT0 = 0;    // Set Timer initial value to 0

	OCR0  = tick; // Set Compare Value

	TIMSK |= (1<<OCIE0); // Enable Timer0 Compare Interrupt

	/* Configure timer0 control register
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 in this example so COM00=0 & COM01=0
	 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);
}

ISR(TIMER0_COMP_vect)
{
	g_tick++;

	if(g_tick == NUMBER_OF_COMPARE_MTACHES_PER_HALF_SECOND)
	{
		PORTC = PORTC ^ (1<<PC0);   //toggle led every 0.5 second
		g_tick = 0;                 //clear the tick counter again to count a new 0.5 second
	}
}