Embedded AVR NTI
Welcome to the Embedded AVR NTI repository! This repository contains a collection of projects designed to help you develop embedded systems using AVR microcontrollers. Each project demonstrates a specific functionality or technique relevant to AVR programming and hardware interfacing.

Table of Contents
Introduction
Projects
Blink LED
Button Control
PWM Signal Generator
UART Communication
Temperature Sensor
LCD Display
EEPROM Data Storage
I2C Communication
ADC (Analog-to-Digital Converter)
SPI Communication
Timer0 Example
ICU (Input Capture Unit)
Seven Segments Display
Getting Started
Contributing
License
Acknowledgements
Introduction
The Embedded AVR NTI repository is aimed at providing practical examples and tools for developing embedded systems with AVR microcontrollers. Each project demonstrates specific functionalities and techniques useful in AVR programming.

Projects
Blink LED
Description: A fundamental project to make an LED blink using a timer, demonstrating basic I/O operations and timing control.

Button Control
Description: This project reads input from a button and uses it to control an LED, demonstrating how to handle digital inputs and outputs.

PWM Signal Generator
Description: Generates a PWM signal to control the brightness of an LED, illustrating Pulse Width Modulation for analog control.

UART Communication
Description: Implements UART communication for serial data exchange between the AVR microcontroller and external devices.

Temperature Sensor
Description: Interfaces with an analog temperature sensor and reads temperature data using ADC (Analog-to-Digital Conversion).

LCD Display
Description: Shows how to interface with an LCD display to show text or data from the microcontroller.

EEPROM Data Storage
Description: Demonstrates reading from and writing to EEPROM memory for non-volatile data storage.

I2C Communication
Description: Shows how to use the I2C protocol for communication with external devices.

ADC (Analog-to-Digital Converter)
Description: Demonstrates how to use the ADC to convert analog signals into digital values.

SPI Communication
Description: Implements SPI communication for interfacing with SPI-compatible devices.

Timer0 Example
Description: Shows how to use Timer0 to generate time delays or periodic interrupts.

ICU (Input Capture Unit)
Description: Demonstrates the use of the Input Capture Unit (ICU) to measure the duration of an external signal.

Seven Segments Display
Description: Interfaces with a seven-segment display to show numeric values or characters.

Getting Started
To get started with any of these projects:

Clone the Repository:

bash
نسخ الكود
git clone https://github.com/faraha99/Embedded-AVR-NTI.git
Navigate to the Project Directory:

bash
نسخ الكود
cd Embedded-AVR-NTI/<project-folder>
Compile the Code:

Use the provided Makefile or compile manually using avr-gcc. For example:

bash
نسخ الكود
avr-gcc -mmcu=atmega328p -o output.elf main.c
Upload to Microcontroller:

Use an AVR programmer or debugger. For example:

bash
نسخ الكود
avrdude -c usbtiny -p atmega328p -U flash:w:output.hex
Run and Test:

Power up the microcontroller and observe the behavior as described in the project documentation.

Contributing
We welcome contributions! If you have suggestions or improvements:

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Commit your changes (git commit -am 'Add new feature').
Push to the branch (git push origin feature-branch).
Create a Pull Request.
Please ensure your contributions adhere to the coding standards and include relevant documentation.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgements
AVR Microcontroller Community: For valuable resources and support.
Open Source Projects: Various libraries and tools used in this repository.
Contributors: Thanks to all who have contributed to the repository.
