
#include <avr/io.h>
#include "KEYPAD.h"
#include "LCD.h"

int main(void)
{
    KeyPad_Init();
	LCD_Init();
	
    while (1) 
    {
		uint8 x=KeyPad_GetChar();
		if(x!=' '){
		LCD_WriteChar(x);}
    }
}

