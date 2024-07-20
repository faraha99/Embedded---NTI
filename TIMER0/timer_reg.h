/*
 * timer_reg.h
 *
 * Created: 8/4/2023 11:14:14 AM
 *  Author: Owner
 */ 

#ifndef _TIMER_REG_H_
#define _TIMER_REG_H_

// Define Timer0 registers and settings
#define TCCR0A 0x00 // Normal mode
#define CS00    0
#define TCCR0B (1 << CS00) // No prescaler, clock source = system clock
#define TIMSK0 (1 << TOIE0) // Enable Timer0 overflow interrupt
#define TOIE0 0x01 // Timer0 overflow interrupt enable bit

#endif /* _TIMER_REG_H_ */