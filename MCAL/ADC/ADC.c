/*
 * ADC.c
 *
 *  Created on: Jul 23, 2026
 *      Author: ganna
 */
#include "../../LIB/BITMATH.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>
#include "ADC.h"
void (*PTR_ADC) (void) ;

void MADC_voidInit (u8 A_u8Prescaller , u8 A_u8Aref)
{
	// Clear ADMUX first
	ADMUX = 0;

	// Set reference voltage
	ADMUX |= (A_u8Aref << 6);

	// Set prescaller
	ADCSRA |= (A_u8Prescaller);

	// Right adjust result (ADC register)
	CLR_BIT(ADMUX, 5);

	// Enable ADC
	SET_BIT(ADCSRA, 7);

	// Do a dummy conversion to stabilize ADC (ADD THIS)
	MADC_voidStartConversion(0);
	_delay_ms(10);
	MADC_u16ReadDataUsingPolling();
}
void MADC_voidStartConversion (u8 A_u8ChannelNumber)
{
	ADMUX |= (A_u8ChannelNumber) ;
	SET_BIT(ADCSRA, 6) ;
}

u16  MADC_u16ReadDataUsingPolling (void)
{
	while (READ_BIT(ADCSRA , 4) == 0) ;
	SET_BIT(ADCSRA , 4) ;
	return ADC ;
}

u16  MADC_u16ReadDataUsingInterrupt (void)
{
	return ADC ;
}

void MADC_voidCallback (void (*fptr)(void))
{
	PTR_ADC = fptr ;
}

void __vector_16 (void)__attribute__((signal)) ;
void __vector_16 (void)
{
	PTR_ADC () ;
}
