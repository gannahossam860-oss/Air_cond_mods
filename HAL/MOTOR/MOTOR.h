/*
 * MOTOR.h
 *
 *  Created on: Jul 24, 2026
 *      Author: ganna
 */

#ifndef HAL_MOTOR_MOTOR_H_
#define HAL_MOTOR_MOTOR_H_

#include "../../LIB/STD_TYPES.h"

void HMotor_voidInit(void);
void HMotor_voidCW(void);    // Heating Mode (ãÚ ÚÞÇÑÈ ÇáÓÇÚÉ)
void HMotor_voidCCW(void);   // Cooling Mode (ÚßÓ ÚÞÇÑÈ ÇáÓÇÚÉ)
void HMotor_voidStop(void);  // ÅíÞÇÝ ÇáãæÊæÑ


#endif /* HAL_MOTOR_MOTOR_H_ */
