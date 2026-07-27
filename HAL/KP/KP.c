/*
 * KP.c
 *
 *  Created on: Jul 16, 2026
 *      Author: ganna
 */
#include "../../LIB/BITMATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>
#include "KP.h"

u8 G_u8Array [4][4] = {

		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'C','0','=','+'}
};


void HKP_voidInit   (void)
{
	//all ROWS output
	MDIO_voidInitPin(ROWS_PORT, ROW1_PIN, DIO_OUTPUT) ;
	MDIO_voidInitPin(ROWS_PORT, ROW2_PIN, DIO_OUTPUT) ;
	MDIO_voidInitPin(ROWS_PORT, ROW3_PIN, DIO_OUTPUT) ;
	MDIO_voidInitPin(ROWS_PORT, ROW4_PIN, DIO_OUTPUT) ;

	//all COLS input
	MDIO_voidInitPin(COLS_PORT, COL1_PIN, DIO_INPUT) ;
	MDIO_voidInitPin(COLS_PORT, COL2_PIN, DIO_INPUT) ;
	MDIO_voidInitPin(COLS_PORT, COL3_PIN, DIO_INPUT) ;
	MDIO_voidInitPin(COLS_PORT, COL4_PIN, DIO_INPUT) ;

	//disable all ROWS
	MDIO_voidSetPinValue(ROWS_PORT, ROW1_PIN, DIO_HIGH) ;
	MDIO_voidSetPinValue(ROWS_PORT, ROW2_PIN, DIO_HIGH) ;
	MDIO_voidSetPinValue(ROWS_PORT, ROW3_PIN, DIO_HIGH) ;
	MDIO_voidSetPinValue(ROWS_PORT, ROW4_PIN, DIO_HIGH) ;

	//enable  internal pull up to COLS
	MDIO_voidSetPinValue(COLS_PORT, COL1_PIN, DIO_HIGH) ;
	MDIO_voidSetPinValue(COLS_PORT, COL2_PIN, DIO_HIGH) ;
	MDIO_voidSetPinValue(COLS_PORT, COL3_PIN, DIO_HIGH) ;
	MDIO_voidSetPinValue(COLS_PORT, COL4_PIN, DIO_HIGH) ;
}
u8   HKP_u8GetValue (void)
{
	u8 L_u8Col , L_u8Row , L_u8PressedValue = KP_NOT_PRESSED ;
	for (L_u8Row = 0 ; L_u8Row < 4 ; L_u8Row ++)
	{
		u8 L_u8RowNumb = 5-L_u8Row ;
		MDIO_voidSetPinValue(ROWS_PORT, L_u8RowNumb, DIO_LOW) ;
		for (L_u8Col = 0 ; L_u8Col < 4 ; L_u8Col ++)
		{
			u8 L_u8ColNumb = 7-L_u8Col;
			if (L_u8Col == 3)
			{
				L_u8ColNumb -- ;
			}
			if (MDIO_u8ReadPinValue(COLS_PORT, L_u8ColNumb) == 0)
			{
				_delay_ms(50) ;
				if (MDIO_u8ReadPinValue(COLS_PORT, L_u8ColNumb) == 0)
				{
					//getValue
					L_u8PressedValue = G_u8Array [L_u8Row][L_u8Col] ;
					while (MDIO_u8ReadPinValue(COLS_PORT, L_u8ColNumb) == 0);
					_delay_ms(50) ;
				}
			}
		}
		MDIO_voidSetPinValue(ROWS_PORT, L_u8RowNumb, DIO_HIGH) ;
	}
	return L_u8PressedValue ;
}
