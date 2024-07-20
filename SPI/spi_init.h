#ifndef SPI_INT_H_
#define SPI_INT_H_

#define DUMMY 0xFF
#include "std_types.h"

void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);

uint8 SPI_u8Transfer(uint8 Copy_Data);

void SPI_voidSetCallBack( void (*PtrToFunc) (void) );

uint8 SPI_u8ReadDataISR(void);

void SPI_voidSendDataISR(uint8 Copy_Data);


#endif /* SPI_INT_H_ */