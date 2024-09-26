# ESP8266 Keypad Password Entry System

## Overview

This project demonstrates a password entry system using the ESP8266 microcontroller, a 4x4 keypad, and a buzzer. Users can input a predefined password through the keypad, and the system will provide audio feedback indicating whether the entered password is correct or incorrect.

## Features

- **4x4 Keypad Input**: Easy password entry via a matrix keypad.
- **Password Verification**: Checks the entered password against a predefined one.
- **Audible Feedback**: Provides sound notifications through a buzzer for correct and incorrect password entries.
- **Serial Monitor Output**: Displays input and verification results on the Serial Monitor for debugging and monitoring.

## Components Needed

- ESP8266 microcontroller (e.g., NodeMCU)
- 4x4 matrix keypad
- Buzzer
- Breadboard and jumper wires

### Pin Connections

- **Keypad:**
  - Row Pins: GPIO5, GPIO4, GPIO14, GPIO12
  - Column Pins: GPIO13, GPIO0, GPIO16, GPIO2
- **Buzzer:**
  - Connect to GPIO15

## Installation

1. **Clone the Repository**:
   ```bash
   https://github.com/Yamil-Serrano/ESP8266-Keypad-Password-Entry-System.git
