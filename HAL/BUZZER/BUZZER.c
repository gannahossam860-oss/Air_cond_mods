/*
 * BUZZER.c
 *
 *  Created on: Jul 14, 2026
 *      Author: ganna
 */
#include"../../LIB/BITMATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO.h"
#include"BUZZER.h"

void HBuzzer_InitBuzzer    (void)
{
	MDIO_voidInitPin(BUZZER_PORT, BUZZER_PIN, DIO_OUTPUT) ;
}
void HBuzzer_TurnOnBuzzer  (void)
{
	MDIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_HIGH) ;
}
void HBuzzer_TurnOffBuzzer (void)
{
	MDIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_LOW) ;
}
void HBuzzer_TogBuzzer     (void)
{
	MDIO_voidTogPinValue(BUZZER_PORT, BUZZER_PIN) ;
}
