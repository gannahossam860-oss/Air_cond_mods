/*
 * UART.h
 *
 *  Created on: Jul 23, 2026
 *      Author: ganna
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#define UDR    (*(volatile u8*)(0x2C))
#define UCSRA  (*(volatile u8*)(0x2B))
#define UCSRB  (*(volatile u8*)(0x2A))
#define UCSRC  (*(volatile u8*)(0x40))
#define UBRRH  (*(volatile u8*)(0x40))
#define UBRRL  (*(volatile u8*)(0x29))

void MUART_voidInit (u32 A_u32BoudRate , u8 A_u8DataSize) ;
void MUART_voidTX   (u16 A_u16Data) ;
u16  MUART_u16Rx    (void) ;

#endif /* MCAL_UART_UART_H_ */
