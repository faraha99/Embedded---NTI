
#include <util/delay.h>
#include "KEYPAD.h"

const uint8 KeyPad_Values[4][4] = {{'7' , '4' , '1' , 'c'} ,
{'8' , '5' , '2' , '0'} ,
{'9' , '6' , '3' , '='} ,
{'/' , 'x' , '-' , '+'}  };



void KeyPad_Init(void)
{

	DIO_SetPinDir(COLUMN_PORT, KEYPAD_COLUM_0, DIO_PIN_OUTPUT);
	DIO_SetPinDir(COLUMN_PORT, KEYPAD_COLUM_1, DIO_PIN_OUTPUT);
	DIO_SetPinDir(COLUMN_PORT, KEYPAD_COLUM_2, DIO_PIN_OUTPUT);
	DIO_SetPinDir(COLUMN_PORT, KEYPAD_COLUM_3, DIO_PIN_OUTPUT);

	DIO_SetPinVal(COLUMN_PORT, KEYPAD_COLUM_0, DIO_PIN_HIGH);
	DIO_SetPinVal(COLUMN_PORT, KEYPAD_COLUM_1, DIO_PIN_HIGH);
	DIO_SetPinVal(COLUMN_PORT, KEYPAD_COLUM_2, DIO_PIN_HIGH);
	DIO_SetPinVal(COLUMN_PORT, KEYPAD_COLUM_3, DIO_PIN_HIGH);

	DIO_SetPinDir(ROW_PORT, KEYPAD_ROW_0, DIO_PIN_INPUT);
	DIO_SetPinDir(ROW_PORT, KEYPAD_ROW_1, DIO_PIN_INPUT);
	DIO_SetPinDir(ROW_PORT, KEYPAD_ROW_2, DIO_PIN_INPUT);
	DIO_SetPinDir(ROW_PORT, KEYPAD_ROW_3, DIO_PIN_INPUT);


	DIO_SetPullUpRes(ROW_PORT, KEYPAD_ROW_0);
	DIO_SetPullUpRes(ROW_PORT, KEYPAD_ROW_1);
	DIO_SetPullUpRes(ROW_PORT, KEYPAD_ROW_2);
	DIO_SetPullUpRes(ROW_PORT, KEYPAD_ROW_3);


}

uint8 KeyPad_GetChar(void)
{
	uint8 COLUMNS[]={7,6,5,3};
	uint8 ROWS[]={5,4,3,2};
	uint8 i  = 0;
	uint8 j  = 0;

	uint8 Temp , Value = ' ';

	for(i=0 ;i<4 ;i++ )//colunm
	{
		DIO_SetPinVal(COLUMN_PORT, COLUMNS[i], DIO_PIN_LOW);

		for(j=0 ;j<4 ;j++) //rows
		{
			Temp = DIO_GetPinVal(ROW_PORT, ROWS[j]);
			_delay_ms(5);
			
			if(Temp==0)
			{
				_delay_ms(5);
				Value = KeyPad_Values[i][j];
			}
			while(Temp==0)
			{
				Temp = DIO_GetPinVal(ROW_PORT, ROWS[j]);
			}

		}
		DIO_SetPinVal(COLUMN_PORT, COLUMNS[i], DIO_PIN_HIGH);
	}
	return Value;


}
