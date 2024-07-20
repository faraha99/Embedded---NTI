
#include "DIO.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define   ROW_PORT    DIO_PORTC
#define   COLUMN_PORT    DIO_PORTD

#define   KEYPAD_COLUM_0 	DIO_PIN7
#define   KEYPAD_COLUM_1    DIO_PIN6
#define   KEYPAD_COLUM_2 	DIO_PIN5
#define   KEYPAD_COLUM_3 	DIO_PIN3

#define   KEYPAD_ROW_0	 	DIO_PIN5
#define   KEYPAD_ROW_1 	    DIO_PIN4
#define   KEYPAD_ROW_2 	    DIO_PIN3
#define   KEYPAD_ROW_3 	    DIO_PIN2

void KeyPad_Init(void);

uint8 KeyPad_GetChar(void);

#endif /* KEYPAD_H_ */
