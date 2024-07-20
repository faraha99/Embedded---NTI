/*
 * main.c
 *
 * Created: 8/3/2023 12:52:39 PM
 *  Author: Owner
 */ 

#include "spi_init.h"
#include "gpio.h"

/* Push button pull-down configuration */
#define BUTTON_PRESSED     LOGIC_HIGH
#define BUTTON_RELEASED    LOGIC_LOW

/* LED Positive Logic configuration */
#define LED_ON             LOGIC_HIGH
#define LED_OFF            LOGIC_LOW

int main(void)
{
	uint8 data_received;

	/* Initialize the SPI driver as Slave */
	SPI_voidSlaveInit();

	GPIO_setupPinDirection(PORTC_ID,PIN3_ID,PIN_OUTPUT); /* Configure PC3 as output pin */
	GPIO_writePin(PORTC_ID,PIN3_ID,LED_OFF); /* Turn OFF the LED */

    while(1)
    {
    	/*
    	 * Receive button status from the MC1 using SPI,
    	 * and send SPI_DEFAULT_DATA_VALUE as no need to send data to other device.
    	 */
		data_received = SPI_u8ReadDataISR();

		if(data_received == BUTTON_PRESSED)
		{
			GPIO_writePin(PORTC_ID,PIN3_ID,LED_ON); /* Turn ON the LED */
		}
		else
		{
			GPIO_writePin(PORTC_ID,PIN3_ID,LED_OFF); /* Turn OFF the LED */
		}
    }
}
