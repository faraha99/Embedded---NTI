#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"

#define  LCD_8BIT_CMD_PORT     DIO_PORTD
#define  LCD_8BIT_DATA_PORT    DIO_PORTC


#define  LCD_4BIT_CMD_PORT     DIO_PORTA
#define  LCD_4BIT_DATA_PORT    DIO_PORTB



#define  LCD_RS_PIN            DIO_PIN3
#define  LCD_RW_PIN            DIO_PIN0
#define  LCD_E_PIN             DIO_PIN2


#define  D4_PIN                DIO_PIN0
#define  D5_PIN                DIO_PIN1
#define  D6_PIN                DIO_PIN2
#define  D7_PIN                DIO_PIN4


void LCD_Init();
void LCD_WriteCommand(uint8 cmd);
void LCD_WriteChar(uint8 chr);

void LCD_WriteString(uint8* str);
void LCD_GoTo(uint8 row , uint8 col);

void LCD_WriteInteger(sint32 intgr);
void LCD_WriteSpecialChar(uint8 Custom[]);

#endif
