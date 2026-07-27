/*
 * MOTOR.c
 *
 *  Created on: Jul 24, 2026
 *      Author: ganna
 */
#include "Motor.h"
#include "../../MCAL/DIO/DIO.h"

#define MOTOR_PORT    DIO_PORTC
#define MOTOR_PIN_1   DIO_PIN0
#define MOTOR_PIN_2   DIO_PIN1

void HMotor_voidInit(void)
{
    MDIO_voidInitPin(MOTOR_PORT, MOTOR_PIN_1, DIO_OUTPUT);
    MDIO_voidInitPin(MOTOR_PORT, MOTOR_PIN_2, DIO_OUTPUT);
}

void HMotor_voidCW(void)
{
    // Heating Mode
    MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_1, DIO_HIGH);
    MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_2, DIO_LOW);
}

void HMotor_voidCCW(void)
{
    // Cooling Mode
    MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_1, DIO_LOW);
    MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_2, DIO_HIGH);
}

void HMotor_voidStop(void)
{
    MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_1, DIO_LOW);
    MDIO_voidSetPinValue(MOTOR_PORT, MOTOR_PIN_2, DIO_LOW);
}


