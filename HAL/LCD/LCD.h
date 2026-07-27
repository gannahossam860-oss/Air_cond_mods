/*
 * LCD.h
 *
 *  Created on: Jul 15, 2026
 *      Author: ganna
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#define RS_PORT  DIO_PORTA
#define RS_PIN   DIO_PIN3

#define EN_PORT  DIO_PORTA
#define EN_PIN   DIO_PIN2

#define LCD_PORT DIO_PORTB
#define D4_PIN   DIO_PIN0
#define D5_PIN   DIO_PIN1
#define D6_PIN   DIO_PIN2
#define D7_PIN   DIO_PIN4

void HLCD_voidInit      (void) ;
void HLCD_voidWriteCmd  (u8 A_u8Cmd) ;
void HLCD_voidWriteData (u8 A_u8Data) ;
void HLCD_voidSendStr   (u8*pstr) ;
void HLCD_voidClearScreen (void) ;
void HLCD_voidShiftLeft (void) ;
void HLCD_voidShiftRight (void) ;
void HLCD_voidMoveCursor (u8 A_u8Row , u8 A_u8Col) ;


#endif /* HAL_LCD_LCD_H_ */
