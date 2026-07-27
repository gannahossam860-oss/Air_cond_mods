/*
 * EEPROM.c
 *
 *  Created on: Jul 16, 2026
 *      Author: ganna
 */
#include "../../LIB/BITMATH.h"
#include "../../LIB/STD_TYPES.h"
#include "EEPROM.h"

void MEEPROM_voidWriteData (u16 A_u16Address , u8 A_u8Data)
{
	EEAR = A_u16Address ;
	EEDR = A_u8Data ;
	SET_BIT(EECR , 2) ;
	SET_BIT(EECR , 1) ;

	while (READ_BIT(EECR , 1) == 1) ;
}
u8   MEEPROM_u8ReadData    (u16 A_u16Address              )
{
	EEAR = A_u16Address ;
	SET_BIT(EECR , 0) ;
	return EEDR ;
}
