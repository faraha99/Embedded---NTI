
#include <avr/io.h>
#include "DIO.h"
#include "SEVEN_SEG.h"

int main(void)
{
	Segment_Init();
    while (1) 
    {
		Segment_Icrease();
    }
}

