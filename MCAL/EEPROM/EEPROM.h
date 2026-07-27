/*
 * EEPROM.h
 *
 *  Created on: Jul 16, 2026
 *      Author: ganna
 */

#ifndef MCAL_EEPROM_EEPROM_H_
#define MCAL_EEPROM_EEPROM_H_

#define EECR    (*(volatile u8*)(0x3C))
#define EEDR    (*(volatile u8*)(0x3D))
#define EEAR    (*(volatile u16*)(0x3E))


void MEEPROM_voidWriteData (u16 A_u16Address , u8 A_u8Data) ;
u8   MEEPROM_u8ReadData    (u16 A_u16Address              ) ;

#endif /* MCAL_EEPROM_EEPROM_H_ */
