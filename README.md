# Air Conditioning Mode System - Team 3

## Project Overview
This project is an **embedded system for an Air Conditioning (AC) mode controller** built on an ATmega32 microcontroller. It automatically switches between **Cooling** and **Heating** modes based on the temperature detected by an LM35 sensor, simulating the behavior of a smart air conditioning system.

The system receives activation commands via UART, displays real-time temperature and mode status on an LCD, and allows manual control of indicator LEDs through a keypad. All settings are stored in EEPROM to maintain state even after power is OFF.

---

## System Features
- **Automatic Mode Switching**: 
  - **Cooling Mode** when temperature > 20°C (Motor rotates Clockwise)
  - **Heating Mode** when temperature ≤ 20°C (Motor rotates Counter-Clockwise)
- **UART Communication**: System activates upon receiving 'A' via serial terminal
- **LCD Display**: Shows real-time temperature and current mode
- **Keypad Control**: Toggle individual LEDs for system status indication
- **EEPROM Storage**: Saves LED states and mode for persistence
- **Hardware Simulation**: Complete Proteus simulation included

## there is Simulation Video uplouded to show how the system works
