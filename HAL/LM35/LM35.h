/*
 * LM35.h
 *
 *  Created on: Jul 24, 2026
 *      Author: ganna
 */

#ifndef HAL_LM35_LM35_H_
#define HAL_LM35_LM35_H_

#include "../../LIB/STD_TYPES.h"

void HLM35_voidInit(void);
u8   HLM35_u8GetTemp(u8 A_u8ChannelNumber);

#endif /* HAL_LM35_LM35_H_ */
