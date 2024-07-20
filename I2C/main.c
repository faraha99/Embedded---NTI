/*
 * main.c
 *
 * Created: 8/7/2023 10:51:12 AM
 *  Author: Owner
 */ 

#include "std_types.h"
#include "Bit_Math.h"
#include "gpio.h"
#include "I2C_interface.h"
#include "lcd.h"
#include "util/delay.h"

int main(void)
{
	GPIO_setupPinDirection(PORTA_ID,PIN0_ID,PIN_INPUT);
	GPIO_writePin(PORTA_ID,PIN0_ID,LOGIC_HIGH);
	GPIO_setupPinDirection(PORTA_ID,PIN1_ID,PIN_INPUT);
	GPIO_writePin(PORTA_ID,PIN1_ID,LOGIC_HIGH);
	
	LCD_init();
	
	I2C_Master_voidInit();
	I2C_Error_State Error=I2C_OK;
	while (1)
	{
		Error =I2C_Master_enuSendStartCond();
		Error=I2C_Master_enuSendSlaveAddressWithWrite(0x10);
		if(Error==I2C_OK && GPIO_readPin(PORTA_ID,PIN0_ID)==0)
		{
			Error=I2C_Master_enuSendu8Data('H');
			LCD_displayString("H");
			_delay_ms(300);
			LCD_clearScreen();
			//LCD_clearScreen(40);
			
			
		}
		else if(Error==I2C_OK && GPIO_readPin(PORTA_ID,PIN1_ID)==0)
		{
			Error=I2C_Master_enuSendu8Data('L');
			LCD_displayString("L");
			_delay_ms(300);
			LCD_clearScreen();
			//LCD_clearScreen(40);
			
		}
		
	}
}

