/*
 * BITMATH.h
 *
 *  Created on: Jul 14, 2026
 *      Author: ganna
 */

#ifndef LIB_BITMATH_H_
#define LIB_BITMATH_H_

#define SET_BIT(REG,BIT)  ((REG)|=(1<<(BIT)))
#define TOG_BIT(REG,BIT)  ((REG)^=(1<<(BIT)))
#define CLR_BIT(REG,BIT)  ((REG)&=(~(1<<(BIT))))
#define READ_BIT(REG,BIT) (((REG)&(1<<(BIT)))>>(BIT))

#endif /* LIB_BITMATH_H_ */
