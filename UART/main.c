/*
 * main.c
 *
 * Created: 7/31/2023 11:38:00 AM
 *  Author: Owner
 */ 

#include "uart_int.h"
#include "Std_types.h"
#include "Bit_Math.h"
#include <util/delay.h>



int main(void)
{
	
	uint8 data;

	/* Initialize the UART driver with Baud-rate = 9600 bits/sec */
	UART_init(51);
	LCD_init();

	while(1)
	{
		data = USART_Receive(); /* Receive Byte from Terminal */
		USART_Transmit(data);       /* Re-send the received byte to Terminal */
		
		
		
	}
}

