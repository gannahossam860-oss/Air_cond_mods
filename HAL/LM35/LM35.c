/*
 * LM35.c
 *
 *  Created on: Jul 24, 2026
 *      Author: ganna
 */
#include "LM35.h"
#include "../../MCAL/ADC/ADC.h"
#include <util/delay.h>

void HLM35_voidInit(void)
{
	// CHANGE THIS: Use internal 2.56V reference instead of AVCC
	MADC_voidInit(PRESCALLER_128, REF_INTERNAL);  // Changed from REF_AVCC to REF_INTERNAL
}

u8 HLM35_u8GetTemp(u8 A_u8ChannelNumber)
{
	u16 L_u16ADCResult = 0;
	u32 L_u32Sum = 0;
	u8 L_u8Sample = 0;

	// Take 5 samples and average
	for(L_u8Sample = 0; L_u8Sample < 5; L_u8Sample++)
	{
		MADC_voidStartConversion(A_u8ChannelNumber);
		L_u16ADCResult = MADC_u16ReadDataUsingPolling();
		L_u32Sum += L_u16ADCResult;
		_delay_ms(2);
	}

	L_u16ADCResult = (u16)(L_u32Sum / 5);

	// NEW FORMULA for internal 2.56V reference
	// Temp = (ADC * 256) / 1024
	u8 L_u8TempC = (u8)(((u32)L_u16ADCResult * 256) / 1024);

	return L_u8TempC;
}
