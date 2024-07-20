
#include "lcd.h"
#include <util/delay.h> /* For the delay functions */

int main(void)
{
	LCD_init(); /* Initialize the LCD */
	LCD_displayStringRowColumn(0,2,"My LCD Driver");
	LCD_displayStringRowColumn(1,3,"Embedded WS");
	_delay_ms(4000); /* wait four seconds */

	LCD_clearScreen(); /* clear the LCD display */
	LCD_displayString("LCD Interfacing");
	LCD_displayStringRowColumn(1,4,"Group ");
	LCD_intgerToString(65);

    while(1)
    {
		/* Note: we write the code before while(1) because we want to execute it only once */
    }
}
