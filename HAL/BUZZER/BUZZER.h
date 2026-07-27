/*
 * BUZZER.h
 *
 *  Created on: Jul 14, 2026
 *      Author: ganna
 */

#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_

#define BUZZER_PORT DIO_PORTC
#define BUZZER_PIN  DIO_PIN6

void HBuzzer_InitBuzzer    (void) ;
void HBuzzer_TurnOnBuzzer  (void) ;
void HBuzzer_TurnOffBuzzer (void) ;
void HBuzzer_TogBuzzer     (void) ;

#endif /* HAL_BUZZER_BUZZER_H_ */
