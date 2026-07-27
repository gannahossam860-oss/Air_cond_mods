/*
 * DIO.c
 *
 *  Created on: Jul 14, 2026
 *      Author: ganna
 */
#include"../../LIB/BITMATH.h"
#include"../../LIB/STD_TYPES.h"
#include"DIO.h"

void MDIO_voidInitPin     (u8 A_u8PortName , u8 A_u8PinName , u8 A_u8Value)
{
	if( A_u8PortName == DIO_PORTA)
	{
		if(A_u8Value == DIO_INPUT)
		{
			CLR_BIT(DDRA , A_u8PinName);
		}
		else if(A_u8Value == DIO_OUTPUT)
		{
			SET_BIT(DDRA , A_u8PinName);
		}
	}
	else if( A_u8PortName == DIO_PORTB)
	{
		if(A_u8Value == DIO_INPUT)
		{
			CLR_BIT(DDRB , A_u8PinName);
		}
		else if(A_u8Value == DIO_OUTPUT)
		{
			SET_BIT(DDRB , A_u8PinName);
		}
	}
	else if( A_u8PortName == DIO_PORTC)
	{
		if(A_u8Value == DIO_INPUT)
		{
			CLR_BIT(DDRC , A_u8PinName);
		}
		else if(A_u8Value == DIO_OUTPUT)
		{
			SET_BIT(DDRC , A_u8PinName);
		}
	}
	else if( A_u8PortName == DIO_PORTD)
	{
		if(A_u8Value == DIO_INPUT)
		{
			CLR_BIT(DDRD , A_u8PinName);
		}
		else if(A_u8Value == DIO_OUTPUT)
		{
			SET_BIT(DDRD , A_u8PinName);
		}
	}

}
void MDIO_voidSetPinValue  (u8 A_u8PortName , u8 A_u8PinName , u8 A_u8Value)
{
	if( A_u8PortName == DIO_PORTA)
	{
		if(A_u8Value == DIO_LOW)
		{
			CLR_BIT(PORTA , A_u8PinName);
		}
		else if(A_u8Value == DIO_HIGH)
		{
			SET_BIT(PORTA , A_u8PinName);
		}
	}
	else if( A_u8PortName == DIO_PORTB)
	{
		if(A_u8Value == DIO_LOW)
		{
			CLR_BIT(PORTB , A_u8PinName);
		}
		else if(A_u8Value == DIO_HIGH)
		{
			SET_BIT(PORTB , A_u8PinName);
		}
	}
	else if( A_u8PortName == DIO_PORTC)
	{
		if(A_u8Value == DIO_LOW)
		{
			CLR_BIT(PORTC , A_u8PinName);
		}
		else if(A_u8Value == DIO_HIGH)
		{
			SET_BIT(PORTC , A_u8PinName);
		}
	}
	else if( A_u8PortName == DIO_PORTD)
	{
		if(A_u8Value == DIO_LOW)
		{
			CLR_BIT(PORTD , A_u8PinName);
		}
		else if(A_u8Value == DIO_HIGH)
		{
			SET_BIT(PORTD , A_u8PinName);
		}
	}

}
void MDIO_voidTogPinValue  (u8 A_u8PortName , u8 A_u8PinName               )
{
	if(A_u8PortName == DIO_PORTA)
	{
		TOG_BIT(PORTA , A_u8PinName);
	}
	else if(A_u8PortName == DIO_PORTB)
	{
		TOG_BIT(PORTB , A_u8PinName);
	}
	else if(A_u8PortName == DIO_PORTC)
	{
		TOG_BIT(PORTC , A_u8PinName);
	}
	else if(A_u8PortName == DIO_PORTD)
	{
		TOG_BIT(PORTD , A_u8PinName);
	}

}
u8   MDIO_u8ReadPinValue   (u8 A_u8PortName , u8 A_u8PinName               )
{
	u8 L_u8PinValue ;
	if (A_u8PortName == DIO_PORTA)
	{
		L_u8PinValue = READ_BIT(PINA , A_u8PinName);
	}
	else if(A_u8PortName == DIO_PORTB)
	{
		L_u8PinValue = READ_BIT(PINB , A_u8PinName);
	}
	else if(A_u8PortName == DIO_PORTC)
	{
		L_u8PinValue = READ_BIT(PINC , A_u8PinName);
	}
	else if(A_u8PortName == DIO_PORTD)
	{
		L_u8PinValue = READ_BIT(PIND , A_u8PinName);
	}
	return L_u8PinValue;
}
void MDIO_voidSetPortValue (u8 A_u8PortName , u8 A_u8Value                 )
{
	if (A_u8PortName == DIO_PORTA)
	{
		PORTA = A_u8Value;
	}
	else if (A_u8PortName == DIO_PORTB)
	{
		PORTB = A_u8Value;
	}
	else if (A_u8PortName == DIO_PORTC)
	{
		PORTC = A_u8Value;
	}
	else if (A_u8PortName == DIO_PORTD)
	{
		PORTD = A_u8Value;
	}
}
void MDIO_voidTogPortValue (u8 A_u8PortName                                )
{
	if (A_u8PortName == DIO_PORTA)
	{
		PORTA = ~PORTA;
	}
	else if (A_u8PortName == DIO_PORTB)
	{
		PORTB = ~PORTB;
	}
	else if (A_u8PortName == DIO_PORTC)
	{
		PORTC = ~PORTC;
	}
	else if (A_u8PortName == DIO_PORTD)
	{
		PORTD = ~PORTD;
	}
}
u8   MDIO_u8ReadPortValue  (u8 A_u8PortName                                )
{
	u8 L_u8PortValue ;
	if (A_u8PortName == DIO_PORTA)
	{
		L_u8PortValue = PINA;
	}
	else if (A_u8PortName == DIO_PORTB)
	{
		L_u8PortValue = PINB;
	}
	else if (A_u8PortName == DIO_PORTC)
	{
		L_u8PortValue = PINC;
	}
	else if (A_u8PortName == DIO_PORTD)
	{
		L_u8PortValue = PIND;
	}
	return L_u8PortValue;
}


