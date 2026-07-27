/*
 * UART.c
 *
 *  Created on: Jul 23, 2026
 *      Author: ganna
 */
#include "../../LIB/BITMATH.h"
#include "../../LIB/STD_TYPES.h"

#include "UART.h"

void MUART_voidInit (u32 A_u32BoudRate , u8 A_u8DataSize)
{
	u16 L_u16UBRRVal = (8000000/(16*A_u32BoudRate))-1 ;
	UBRRL = (u8)L_u16UBRRVal ;
	UBRRH = (L_u16UBRRVal>>8) ;

	// Enable receiver and transmitter
	SET_BIT(UCSRB , 3);  // TX Enable
	SET_BIT(UCSRB , 4);  // RX Enable

	// Set frame format: 8 data bits, 1 stop bit, no parity
	SET_BIT(UCSRC , 7);   // Select UCSRC register
	SET_BIT(UCSRC , 3);   // Set UCSZ1
	SET_BIT(UCSRC , 2);   // Set UCSZ0
	CLR_BIT(UCSRC , 1);   // Clear UPM0 (no parity)
	CLR_BIT(UCSRC , 0);   // Clear UPM1 (no parity)

	// Disable double speed mode
	CLR_BIT(UCSRA , 1);
}

void MUART_voidTX   (u16 A_u16Data)
{
	while (READ_BIT(UCSRA , 5) == 0) ;
	UDR = A_u16Data ;
}

u16  MUART_u16Rx    (void)
{
	while (READ_BIT(UCSRA, 7) == 0);  // Wait for data to be received
	return UDR;  // Return the received byte
}
