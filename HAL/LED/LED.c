/*
 * LED.c
 *
 *  Created on: Jul 14, 2026
 *      Author: ganna
 */
#include"../../LIB/BITMATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO.h"
#include"LED.h"


void HLED_InitLed    (u8 A_u8LedName)
{
	switch(A_u8LedName)
	{
	case RED_LED :
		MDIO_voidInitPin (RED_PORT , RED_PIN , DIO_OUTPUT);
		break;
	case BLUE_LED :
		MDIO_voidInitPin (BLUE_PORT , BLUE_PIN , DIO_OUTPUT);
		break;
	case YELLO_LED :
		MDIO_voidInitPin (YELLO_PORT , YELLO_PIN , DIO_OUTPUT);
		break;
	case GREEN_LED :
		MDIO_voidInitPin (GREEN_PORT , GREEN_PIN , DIO_OUTPUT);
		break;
	}
}
void HLED_TurnOnLed  (u8 A_u8LedName)
{
	switch(A_u8LedName)
	{
	case RED_LED :
		MDIO_voidSetPinValue  (RED_PORT , RED_PIN , DIO_HIGH);
		break;
	case BLUE_LED :
		MDIO_voidSetPinValue   (BLUE_PORT , BLUE_PIN , DIO_HIGH);
		break;
	case YELLO_LED :
		MDIO_voidSetPinValue   (YELLO_PORT , YELLO_PIN , DIO_HIGH);
		break;
	case GREEN_LED :
		MDIO_voidSetPinValue   (GREEN_PORT , GREEN_PIN , DIO_HIGH);
		break;
	}
}
void HLED_TurnOffLed (u8 A_u8LedName)
{
	switch(A_u8LedName)
	{
	case RED_LED :
		MDIO_voidSetPinValue   (RED_PORT , RED_PIN , DIO_LOW);
		break;
	case BLUE_LED :
		MDIO_voidSetPinValue   (BLUE_PORT , BLUE_PIN , DIO_LOW);
		break;
	case YELLO_LED :
		MDIO_voidSetPinValue   (YELLO_PORT , YELLO_PIN , DIO_LOW);
		break;
	case GREEN_LED :
		MDIO_voidSetPinValue   (GREEN_PORT , GREEN_PIN , DIO_LOW);
		break;
	}
}
void HLED_TogLed     (u8 A_u8LedName)
{
	switch(A_u8LedName)
	{
	case RED_LED :
		MDIO_voidTogPinValue   (RED_PORT , RED_PIN);
		break;
	case BLUE_LED :
		MDIO_voidTogPinValue   (BLUE_PORT , BLUE_PIN);
		break;
	case YELLO_LED :
		MDIO_voidTogPinValue   (YELLO_PORT , YELLO_PIN);
		break;
	case GREEN_LED :
		MDIO_voidTogPinValue   (GREEN_PORT , GREEN_PIN);
		break;
	}
}
