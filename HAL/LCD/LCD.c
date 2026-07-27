/*
 * LCD.c
 *
 *  Created on: Jul 15, 2026
 *      Author: ganna
 */
#include"../../LIB/BITMATH.h"
#include"../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"

#include "LCD.h"
#include <util/delay.h>

void HLCD_voidInit      (void)
{
	_delay_ms(50) ;
	MDIO_voidInitPin(RS_PORT, RS_PIN, DIO_OUTPUT) ;
	MDIO_voidInitPin(EN_PORT, EN_PIN, DIO_OUTPUT) ;

	MDIO_voidInitPin(LCD_PORT, D4_PIN, DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_PORT, D5_PIN, DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_PORT, D6_PIN, DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_PORT, D7_PIN, DIO_OUTPUT) ;

	HLCD_voidWriteCmd(0x02) ;//functional set
	_delay_ms(1) ;

	HLCD_voidWriteCmd(0x28) ;//functional set
	_delay_ms(1) ;

	HLCD_voidWriteCmd(0x0E) ;//Display
	_delay_ms(1) ;

	HLCD_voidWriteCmd(0x01) ;//clear
	_delay_ms(5) ;

	HLCD_voidWriteCmd(0x06) ;//Display
	_delay_ms(1) ;
}
void HLCD_voidWriteCmd  (u8 A_u8Cmd)
{
	u8 L_u8HighNibble = A_u8Cmd>>4;
	u8 L_u8LowNibble =  A_u8Cmd&(0x0f);
	MDIO_voidSetPinValue(RS_PORT, RS_PIN, DIO_LOW) ;
	MDIO_voidSetPinValue(LCD_PORT, D4_PIN, READ_BIT(L_u8HighNibble , 0)) ;
	MDIO_voidSetPinValue(LCD_PORT, D5_PIN, READ_BIT(L_u8HighNibble , 1)) ;
	MDIO_voidSetPinValue(LCD_PORT, D6_PIN, READ_BIT(L_u8HighNibble , 2)) ;
	MDIO_voidSetPinValue(LCD_PORT, D7_PIN, READ_BIT(L_u8HighNibble , 3)) ;
	MDIO_voidSetPinValue(EN_PORT, EN_PIN, DIO_HIGH) ;
	_delay_ms(1) ;
	MDIO_voidSetPinValue(EN_PORT, EN_PIN, DIO_LOW) ;

	MDIO_voidSetPinValue(RS_PORT, RS_PIN, DIO_LOW) ;
	MDIO_voidSetPinValue(LCD_PORT, D4_PIN, READ_BIT(L_u8LowNibble , 0)) ;
	MDIO_voidSetPinValue(LCD_PORT, D5_PIN, READ_BIT(L_u8LowNibble , 1)) ;
	MDIO_voidSetPinValue(LCD_PORT, D6_PIN, READ_BIT(L_u8LowNibble , 2)) ;
	MDIO_voidSetPinValue(LCD_PORT, D7_PIN, READ_BIT(L_u8LowNibble , 3)) ;
	MDIO_voidSetPinValue(EN_PORT, EN_PIN, DIO_HIGH) ;
	_delay_ms(1) ;
	MDIO_voidSetPinValue(EN_PORT, EN_PIN, DIO_LOW);
}
void HLCD_voidWriteData (u8 A_u8Data)
{
	u8 L_u8HighNibble = A_u8Data>>4;
	u8 L_u8LowNibble =  A_u8Data&(0x0f);
	MDIO_voidSetPinValue(RS_PORT, RS_PIN, DIO_HIGH) ;
	MDIO_voidSetPinValue(LCD_PORT, D4_PIN, READ_BIT(L_u8HighNibble , 0)) ;
	MDIO_voidSetPinValue(LCD_PORT, D5_PIN, READ_BIT(L_u8HighNibble , 1)) ;
	MDIO_voidSetPinValue(LCD_PORT, D6_PIN, READ_BIT(L_u8HighNibble , 2)) ;
	MDIO_voidSetPinValue(LCD_PORT, D7_PIN, READ_BIT(L_u8HighNibble , 3)) ;
	MDIO_voidSetPinValue(EN_PORT, EN_PIN, DIO_HIGH) ;
	_delay_ms(1) ;
	MDIO_voidSetPinValue(EN_PORT, EN_PIN, DIO_LOW) ;

	MDIO_voidSetPinValue(RS_PORT, RS_PIN, DIO_HIGH) ;
	MDIO_voidSetPinValue(LCD_PORT, D4_PIN, READ_BIT(L_u8LowNibble , 0)) ;
	MDIO_voidSetPinValue(LCD_PORT, D5_PIN, READ_BIT(L_u8LowNibble , 1)) ;
	MDIO_voidSetPinValue(LCD_PORT, D6_PIN, READ_BIT(L_u8LowNibble , 2)) ;
	MDIO_voidSetPinValue(LCD_PORT, D7_PIN, READ_BIT(L_u8LowNibble , 3)) ;
	MDIO_voidSetPinValue(EN_PORT, EN_PIN, DIO_HIGH) ;
	_delay_ms(1) ;
	MDIO_voidSetPinValue(EN_PORT, EN_PIN, DIO_LOW) ;
}
void HLCD_voidSendStr   (u8*pstr)
{
	u8 L_u8Iterator = 0 ;
	while (pstr[L_u8Iterator]!=0)
	{
		HLCD_voidWriteData (pstr[L_u8Iterator]) ;
		L_u8Iterator++ ;
	}
}
void HLCD_voidClearScreen (void)
{
	HLCD_voidWriteCmd(0x01) ;//clear
	_delay_ms(5) ;
}
void HLCD_voidShiftLeft (void)
{
	HLCD_voidWriteCmd(0x18) ;
	_delay_ms(1) ;
}
void HLCD_voidShiftRight (void)
{
	HLCD_voidWriteCmd(0x1C) ;
	_delay_ms(1) ;
}
void HLCD_voidMoveCursor (u8 A_u8Row , u8 A_u8Col)
{
	u8 L_u8Address = 0 ;

	switch (A_u8Row)
	{
	case 0 : L_u8Address = A_u8Col + 0x80 + 0x00; break ;
	case 1 : L_u8Address = A_u8Col + 0x80 + 0x40; break ;
	case 2 : L_u8Address = A_u8Col + 0x80 + 0x14; break ;
	case 3 : L_u8Address = A_u8Col + 0x80 + 0x54; break ;
	}
	HLCD_voidWriteCmd(L_u8Address) ;
}
