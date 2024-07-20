#include "std_types.h"
#include "Bit_Math.h"
#include "gpio.h"
#include "spi_init.h"
#include "SPI_priv.h"
#include "spi_config.h"

void (*CallBack) (void);

void SPI_voidSetCallBack(void (*PtrToFunc)(void))
{
	CallBack = PtrToFunc;
}

void __vector_12(void) __attribute__((signal, used));
void __vector_12(void)
{
	
	CallBack();
}



void SPI_voidSendDataISR(uint8 Copy_Data)
{
	SPDR = Copy_Data;
}

uint8 SPI_u8ReadDataISR(void)
{
	return SPDR;
}

uint8 SPI_u8Transfer(uint8 Copy_Data)
{
	SPDR = Copy_Data;
	while (!(SPSR & (1 << SPIF)))
	{
		/* Wait for transmission complete */
	}
	return SPDR;
}

void SPI_voidMasterInit(void)
{
	/* Set MOSI and SCK as output pins */
	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT); // MOSI
	GPIO_setupPinDirection(PORTB_ID, PIN7_ID, PIN_OUTPUT); // SCK

	/* Set MISO as input pin */
	GPIO_setupPinDirection(PORTB_ID, PIN6_ID, PIN_INPUT); // MISO

	/* Set SS as output pin */
	GPIO_setupPinDirection(PORTB_ID, PIN4_ID, PIN_OUTPUT); // SS

	/* Enable SPI, Set Master Mode, Set Clock Phase and Polarity, and Set Data Order */
	SPCR = (1 << SPE) | (1 << MSTR) | (CLOCK_PHASE << CPHA) | (CLOCK_POLARITY << CPOL) | (DATA_ORDER << DORD);

	/* Set SPI Frequency */
	SPCR = (SPCR & 0xFC) | ((SPI_FREQUENCY >> 2) & 0x03);
	SPSR = (SPSR & 0xFE) | ((SPI_FREQUENCY >> 1) & 0x01);
}

void SPI_voidSlaveInit(void)
{
	/* Set MISO as output pin */
	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT); // MISO

	/* Set MOSI and SCK as input pins */
	GPIO_setupPinDirection(PORTB_ID, PIN6_ID, PIN_INPUT);  // MOSI
	GPIO_setupPinDirection(PORTB_ID, PIN7_ID, PIN_INPUT);  // SCK

	/* Set SS as output pin */
	GPIO_setupPinDirection(PORTB_ID, PIN4_ID, PIN_OUTPUT); // SS

	/* Enable SPI and Set Slave Mode */
	SPCR = (1 << SPE);

	/* Set Data Order */
	SPCR = (SPCR & ~(1 << DORD)) | (DATA_ORDER << DORD);
}