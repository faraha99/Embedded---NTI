
#include <avr/io.h>
#include "DIO.h"

int main(void)
{
    DIO_SetPinDir(DIO_PORTD ,DIO_PIN3 ,DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTA ,DIO_PIN4 ,DIO_PIN_OUTPUT);
	DIO_SetPinVal(DIO_PORTA ,DIO_PIN4 ,0);
	
    while (1) 
    {
		uint8 pressed =DIO_GetPinVal(DIO_PORTD ,DIO_PIN3);
		
		if(pressed==1){
			DIO_SetPinVal(DIO_PORTA ,DIO_PIN4 ,1);
		}
		else if(pressed==0){
			DIO_SetPinVal(DIO_PORTA ,DIO_PIN4 ,0);
		}
    }
}

