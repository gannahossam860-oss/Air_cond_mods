/*
 * KP.h
 *
 *  Created on: Jul 16, 2026
 *      Author: ganna
 */

#ifndef HAL_KP_KP_H_
#define HAL_KP_KP_H_

#define ROWS_PORT   DIO_PORTC
#define ROW1_PIN    DIO_PIN5
#define ROW2_PIN    DIO_PIN4
#define ROW3_PIN    DIO_PIN3
#define ROW4_PIN    DIO_PIN2


#define COLS_PORT   DIO_PORTD
#define COL1_PIN    DIO_PIN7
#define COL2_PIN    DIO_PIN6
#define COL3_PIN    DIO_PIN5
#define COL4_PIN    DIO_PIN3

#define KP_NOT_PRESSED 255

void HKP_voidInit   (void) ;
u8   HKP_u8GetValue (void) ;

#endif /* HAL_KP_KP_H_ */
