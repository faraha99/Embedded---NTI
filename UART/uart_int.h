/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _USART_INT_H
#define _USART_INT_H
#include "Std_types.h"

/****************************************************************/
/** !comment : SPEED_OPERATION							   		*/
/****************************************************************/
#define DOUBLE_SPEED_MODE			0
#define NORMAL_SPEED_MODE			3

#define U2X 1
#define RXEN    4
#define TXEN    3
#define URSEL   7
#define UCSZ0   1
#define UCSZ1   2
#define UDRE    5
#define RXC     7


/****************************************************************/
/* Description    :  This function used to initialize USART     */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void USART_Init( );


/****************************************************************/
/* Description    : This function used to Send Data				*/
/*																*/
/*					Inputs : u8 data				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
void USART_Transmit(uint8 data );


/****************************************************************/
/* Description    : This function used to Receive Data			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : u8			 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after USART		*/
/*     				 initialized 							    */
/****************************************************************/
uint8 USART_Receive( );


#endif	/** !comment  :  End of guard                          **/