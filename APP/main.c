/*
 * main.c
 *
 *  Created on: Jul 18, 2026
 *      Author: ganna
 */

#include "../LIB/BITMATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/ADC/ADC.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/KP/KP.h"
#include "../HAL/LED/LED.h"
#include "../MCAL/UART/UART.h"
#include "../MCAL/EEPROM/EEPROM.h"
#include "../HAL/LM35/LM35.h"
#include "../HAL/MOTOR/Motor.h"
#include <util/delay.h>

// EEPROM Addresses
#define LED1_ADDR  0x00  // RED
#define LED2_ADDR  0x08  // YELLOW
#define LED3_ADDR  0x10  // BLUE
#define LED4_ADDR  0x18  // GREEN
#define MODE_ADDR  0x20  // MODE

// Global Variables
u8 G_u8LED1_State = 0 ;
u8 G_u8LED2_State = 0 ;
u8 G_u8LED3_State = 0 ;
u8 G_u8LED4_State = 0 ;
u8 G_u8Mode = 0 ;
u8 G_u8SystemActive = 0;  // 0 = Waiting for 'A', 1 = Active

void Read_EEPROM_Data(void);
void Write_EEPROM_Data(void);
void LCD_PrintNumber(u8 num);

void main (void)
{
	u8 temp = 0;
	u8 prev_temp = 255;
	u8 mode = 0;
	u8 prev_mode = 255;

	// Initialize LEDs
	HLED_InitLed(GREEN_LED);
	HLED_InitLed(BLUE_LED);
	HLED_InitLed(YELLO_LED);
	HLED_InitLed(RED_LED);

	// Turn off all LEDs at startup
	HLED_TurnOffLed(GREEN_LED);
	HLED_TurnOffLed(YELLO_LED);
	HLED_TurnOffLed(BLUE_LED);
	HLED_TurnOffLed(RED_LED);

	// Initialize UART
	MUART_voidInit(9600, 8);
	u16 L_u16Received;

	// Initialize Keypad, LCD, LM35, Motor
	HKP_voidInit();
	HLCD_voidInit();
	HLM35_voidInit();
	HMotor_voidInit();

	// Read EEPROM data into global variables (but don't apply LEDs yet)
	Read_EEPROM_Data();

	HLCD_voidClearScreen();

	// Display waiting message
	HLCD_voidMoveCursor(0, 0);
	HLCD_voidSendStr((u8*)"Send 'A' to");
	HLCD_voidMoveCursor(1, 0);
	HLCD_voidSendStr((u8*)"Start System");

	while(1)
	{
		// WAIT FOR 'A' FROM UART - SIMPLE APPROACH
		L_u16Received = MUART_u16Rx();  // Use the function directly

		if(L_u16Received == 'A')
		{
			HLCD_voidClearScreen();

			// Row 0: Welcome
			HLCD_voidMoveCursor(0, 0);
			HLCD_voidSendStr((u8*)"Welcome Team 3");

			// Row 1: Temperature label
			HLCD_voidMoveCursor(1, 0);
			HLCD_voidSendStr((u8*)"Temp:    C");

			// Row 2: Mode label
			HLCD_voidMoveCursor(0, 16);
			HLCD_voidSendStr((u8*)"Mode: ");

			// Read EEPROM data again to get latest values
			Read_EEPROM_Data();

			// Apply LED states from EEPROM (only after receiving 'A')
			if(G_u8LED1_State == 1) HLED_TurnOnLed(RED_LED);
			else HLED_TurnOffLed(RED_LED);

			if(G_u8LED2_State == 1) HLED_TurnOnLed(YELLO_LED);
			else HLED_TurnOffLed(YELLO_LED);

			if(G_u8LED3_State == 1) HLED_TurnOnLed(BLUE_LED);
			else HLED_TurnOffLed(BLUE_LED);

			if(G_u8LED4_State == 1) HLED_TurnOnLed(GREEN_LED);
			else HLED_TurnOffLed(GREEN_LED);

			// Reset previous values to force display update
			prev_temp = 255;
			prev_mode = 255;
			G_u8SystemActive = 1;

			// MAIN SYSTEM LOOP
			while(G_u8SystemActive == 1)
			{
				// Read temperature
				temp = HLM35_u8GetTemp(CHANNEL_0);

				if(temp != prev_temp)
				{
					HLCD_voidMoveCursor(1, 6);
					LCD_PrintNumber(temp);
					prev_temp = temp;
				}

				// UPDATE MODE
				if(temp > 20)
				{
					mode = 1;   // Cooling
				}
				else
				{
					mode = 0;   // Heating
				}

				if(mode != prev_mode)
				{
					HLCD_voidMoveCursor(2, 2);

					if(mode == 1)
					{
						HLCD_voidSendStr((u8*)"Cooling ");
						HMotor_voidCCW();  //CLOCK WISE
						G_u8Mode = 1;
					}
					else
					{
						HLCD_voidSendStr((u8*)"Heating ");
						HMotor_voidCW();  //ANTI CLOCK WISE
						G_u8Mode = 0;
					}
					Write_EEPROM_Data();
					prev_mode = mode;
				}

				// CHECK KEYPAD
				u8 key = HKP_u8GetValue();

				if(key != KP_NOT_PRESSED)
				{
					switch(key)
					{
					case '1':
						HLED_TogLed(GREEN_LED);
						G_u8LED4_State = !G_u8LED4_State;
						break;

					case '7':
						HLED_TogLed(BLUE_LED);
						G_u8LED3_State = !G_u8LED3_State;
						break;

					case '9':
						HLED_TogLed(YELLO_LED);
						G_u8LED2_State = !G_u8LED2_State;
						break;

					case '3':
						HLED_TogLed(RED_LED);
						G_u8LED1_State = !G_u8LED1_State;
						break;

					default:
						break;
					}
					Write_EEPROM_Data();
				}

				// Small delay to prevent CPU overuse and allow stable readings
				_delay_ms(10);
			}
		}
	}
}

void Read_EEPROM_Data(void)// READ EEPROM
{
	u8 L_u8LED1, L_u8LED2, L_u8LED3, L_u8LED4, L_u8Mode;

	L_u8LED1 = MEEPROM_u8ReadData(LED1_ADDR);
	L_u8LED2 = MEEPROM_u8ReadData(LED2_ADDR);
	L_u8LED3 = MEEPROM_u8ReadData(LED3_ADDR);
	L_u8LED4 = MEEPROM_u8ReadData(LED4_ADDR);
	L_u8Mode = MEEPROM_u8ReadData(MODE_ADDR);

	if(L_u8LED1 != 0xFF && L_u8LED2 != 0xFF && L_u8LED3 != 0xFF &&
			L_u8LED4 != 0xFF && L_u8Mode != 0xFF)
	{
		G_u8LED1_State = L_u8LED1;
		G_u8LED2_State = L_u8LED2;
		G_u8LED3_State = L_u8LED3;
		G_u8LED4_State = L_u8LED4;
		G_u8Mode = L_u8Mode;
	}
}

void Write_EEPROM_Data(void)// WRITE EEPROM
{
	MEEPROM_voidWriteData(LED1_ADDR, G_u8LED1_State);
	MEEPROM_voidWriteData(LED2_ADDR, G_u8LED2_State);
	MEEPROM_voidWriteData(LED3_ADDR, G_u8LED3_State);
	MEEPROM_voidWriteData(LED4_ADDR, G_u8LED4_State);
	MEEPROM_voidWriteData(MODE_ADDR, G_u8Mode);
}

// Function to print 2-digit number on LCD
void LCD_PrintNumber(u8 num)
{
	u8 tens = num / 10;
	u8 ones = num % 10;

	// Print with leading zero instead of space
	HLCD_voidWriteData(tens + '0');
	HLCD_voidWriteData(ones + '0');
}
