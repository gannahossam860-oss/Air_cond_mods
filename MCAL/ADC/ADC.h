/*
 * ADC.h
 *
 *  Created on: Jul 23, 2026
 *      Author: ganna
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#define ADMUX    (*(volatile u8*)0x27)
#define ADCSRA   (*(volatile u8*)0x26)
#define ADC      (*(volatile u16*)0x24)
#define SFIOR    (*(volatile u8*)0x50)
#define SREG     (*(volatile u8*)0x5F)


#define CHANNEL_0  0
#define CHANNEL_1  1
#define CHANNEL_2  2
#define CHANNEL_3  3
#define CHANNEL_4  4
#define CHANNEL_5  5
#define CHANNEL_6  6
#define CHANNEL_7  7

#define REF_AREF     0
#define REF_AVCC     1
#define REF_INTERNAL 3

#define PRESCALLER_2   1
#define PRESCALLER_4   2
#define PRESCALLER_8   3
#define PRESCALLER_16  4
#define PRESCALLER_32  5
#define PRESCALLER_64  6
#define PRESCALLER_128 7

#define ADC_INTERRUPT_ENABLE  1

void MADC_voidInit (u8 A_u8Prescaller , u8 A_u8Aref) ;
void MADC_voidStartConversion (u8 A_u8ChannelNumber) ;
u16  MADC_u16ReadDataUsingPolling (void) ;
u16  MADC_u16ReadDataUsingInterrupt (void) ;
void MADC_voidCallback (void (*fptr)(void)) ;


#endif /* MCAL_ADC_ADC_H_ */
