#include "SEVEN_SEG.h"
#include <util/delay.h>

uint8 counter =1;

void Segment_Init()
{
	uint8 portValue,command;
	DIO_SetPinDir(Segment_Data_Port, Segment_Data_A, DIO_PIN_OUTPUT);
	DIO_SetPinDir(Segment_Data_Port, Segment_Data_B, DIO_PIN_OUTPUT);
	DIO_SetPinDir(Segment_Data_Port, Segment_Data_C, DIO_PIN_OUTPUT);
	DIO_SetPinDir(Segment_Data_Port, Segment_Data_D, DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTA, DIO_PIN3, DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTA, DIO_PIN2, DIO_PIN_OUTPUT);
	
	DIO_SetPinVal(DIO_PORTB, DIO_PIN5, 0);    //active low
	DIO_SetPinVal(DIO_PORTB, DIO_PIN6, 0);
	DIO_SetPinVal(DIO_PORTA, DIO_PIN3, 0);
	DIO_SetPinVal(DIO_PORTA, DIO_PIN2, 0);
	
	portValue=DIO_GetPortVal(Segment_Data_Port);

	command = (0) | (portValue & 0xE8);

	DIO_SetPortVal(Segment_Data_Port, command);


}

void Segment_Icrease()
{

 uint8 portValue,command;

 if(counter>17)
 {
	 counter=0;

 }
 if(counter==8)
 {
	 counter=16;
 }
 portValue=DIO_GetPortVal(Segment_Data_Port);

 	command = (counter) | (portValue & 0xE8);

 	DIO_SetPortVal(Segment_Data_Port, command);
	 _delay_ms(1000);
	 
counter++;

}
void Segment_Decrease()
{

	 uint8 portValue,command;

	 if(counter>0)
	 {
		 counter--;

	 }
	 if(counter==15)
	 {
		 counter=7;
	 }
	 portValue=DIO_GetPortVal(Segment_Data_Port);

	 	command = (counter) | (portValue & 0xE8);

	 	DIO_SetPortVal(Segment_Data_Port, command);


}
void Segment_Clear()
{
	uint8 portValue,command;
	portValue=DIO_GetPortVal(Segment_Data_Port);

	command = (0) | (portValue & 0xE8);

	DIO_SetPortVal(Segment_Data_Port, command);
}
