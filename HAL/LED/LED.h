/*
 * LED.h
 *
 *  Created on: Jul 14, 2026
 *      Author: ganna
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

#define GREEN_LED  0
#define YELLO_LED  1
#define BLUE_LED   2
#define RED_LED    3

#define GREEN_PORT  DIO_PORTA
#define YELLO_PORT  DIO_PORTA
#define BLUE_PORT   DIO_PORTA
#define RED_PORT    DIO_PORTB

#define GREEN_PIN  DIO_PIN4
#define YELLO_PIN  DIO_PIN6
#define BLUE_PIN   DIO_PIN5
#define RED_PIN    DIO_PIN7

void HLED_InitLed    (u8 A_u8LedName) ;
void HLED_TurnOnLed  (u8 A_u8LedName) ;
void HLED_TurnOffLed (u8 A_u8LedName) ;
void HLED_TogLed     (u8 A_u8LedName) ;



#endif /* HAL_LED_LED_H_ */
