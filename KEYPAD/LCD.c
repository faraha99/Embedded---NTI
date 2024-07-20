
#include "LCD.h"
#include <util/delay.h>
void LCD_Init()
{

	/*initializing the pins direction in 4-bit mode*/
	DIO_SetPinDir(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT);
	//DIO_SetPinDir(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D4_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D5_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D6_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D7_PIN , DIO_PIN_OUTPUT);

	_delay_ms(100);
	/*send commands to LCD for initializing as 4-bit mode*/
	
	//send command
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_LOW);

	//Low level on E PIN
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D7_PIN ,0);
	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D6_PIN ,0);
	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D5_PIN ,1);
	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D4_PIN ,0);
	
	//latch
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	LCD_WriteCommand(0x28);
	
	_delay_ms(100);

	/*display on ,cursor off*/
	LCD_WriteCommand(0x0F);
	
	_delay_ms(100);
	
	/*clear display*/
	LCD_WriteCommand(0x01);
	
	_delay_ms(100);
	
	/* return home*/
	LCD_WriteCommand(0x06);
}

void LCD_WriteCommand(uint8 cmd)
{
		//send command
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_LOW);

		//Low level on E PIN
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);


		DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D7_PIN ,GET_BIT(cmd,7));
		DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D6_PIN ,GET_BIT(cmd,6));
		DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D5_PIN ,GET_BIT(cmd,5));
		DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D4_PIN ,GET_BIT(cmd,4));
		
		
		//latch
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
		_delay_ms(1);
		
		DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D7_PIN ,GET_BIT(cmd,3));
		DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D6_PIN ,GET_BIT(cmd,2));
		DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D5_PIN ,GET_BIT(cmd,1));
		DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D4_PIN ,GET_BIT(cmd,0));
		
		//latch
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);

		_delay_ms(5);

}

void LCD_WriteChar(uint8 chr)
{

	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_HIGH);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);

	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D7_PIN ,GET_BIT(chr,7));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D6_PIN ,GET_BIT(chr,6));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D5_PIN ,GET_BIT(chr,5));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D4_PIN ,GET_BIT(chr,4));


	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
			_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
			_delay_ms(1);
			
	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D7_PIN ,GET_BIT(chr,3));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D6_PIN ,GET_BIT(chr,2));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D5_PIN ,GET_BIT(chr,1));
	DIO_SetPinVal(LCD_4BIT_DATA_PORT ,D4_PIN ,GET_BIT(chr,0));

	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
			_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
			_delay_ms(1);
}


void LCD_WriteString(uint8* str)
{
	uint8 i = 0 ;

	while(str[i] != '\0')
	{
		LCD_WriteChar(str[i]);
		i++;
	}
}


void LCD_GoTo(uint8 row , uint8 col)
{
	uint8 pos[2] = {0x80 , 0xc0};

	LCD_WriteCommand(pos[row]+col);
}

void LCD_WriteInteger(sint32 intgr)
{

	sint32 y = 1;

	if(intgr < 0)
	{
		LCD_WriteChar('-');
		intgr *= -1;
	}

	while(intgr > 0)
	{
		y = ((y*10) + (intgr%10));
		intgr /= 10;
	}

	while(y > 1 )
	{
		LCD_WriteChar(((y%10)+48));
		y /= 10;
	}
}
void LCD_WriteSpecialChar(uint8 Custom[])
{
	//DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_LOW);
	uint8 i=0;
	LCD_WriteCommand(0x40);
	//DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_HIGH);
	
	for(i=0; i<8; i++)
	{
	LCD_WriteChar(Custom[i]);
	}
}



