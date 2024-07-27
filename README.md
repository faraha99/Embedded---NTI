
# Embedded AVR NTI

Welcome to the **Embedded AVR NTI** repository! This repository contains a collection of projects designed to help you develop embedded systems using AVR microcontrollers. Each project demonstrates a specific functionality or technique relevant to AVR programming and hardware interfacing.

## Table of Contents

- [Introduction](#introduction)
- [Projects](#projects)
  - [Blink LED](#blink-led)
  - [Button Control](#button-control)
  - [PWM Signal Generator](#pwm-signal-generator)
  - [UART Communication](#uart-communication)
  - [Temperature Sensor](#temperature-sensor)
  - [LCD Display](#lcd-display)
  - [EEPROM Data Storage](#eeprom-data-storage)
  - [I2C Communication](#i2c-communication)
  - [ADC (Analog-to-Digital Converter)](#adc-analog-to-digital-converter)
  - [SPI Communication](#spi-communication)
  - [Timer0 Example](#timer0-example)
  - [ICU (Input Capture Unit)](#icu-input-capture-unit)
  - [Seven Segments Display](#seven-segments-display)
- [Getting Started](#getting-started)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Introduction

The Embedded AVR NTI repository is aimed at providing practical examples and tools for developing embedded systems with AVR microcontrollers. Each project demonstrates specific functionalities and techniques useful in AVR programming.

## Projects

### Blink LED

**Description**: A fundamental project to make an LED blink using a timer, demonstrating basic I/O operations and timing control.

- **Purpose**: To show basic microcontroller programming concepts.

### Button Control

**Description**: This project reads input from a button and uses it to control an LED, demonstrating how to handle digital inputs and outputs.

- **Purpose**: To teach digital input handling and control of output devices.

### PWM Signal Generator

**Description**: Generates a PWM signal to control the brightness of an LED, illustrating Pulse Width Modulation for analog control.

- **Purpose**: To illustrate the use of PWM for varying signal levels.

### UART Communication

**Description**: Implements UART communication for serial data exchange between the AVR microcontroller and external devices.

- **Purpose**: To provide examples of serial data transmission and reception using UART.

### Temperature Sensor

**Description**: Interfaces with an analog temperature sensor and reads temperature data using ADC (Analog-to-Digital Conversion).

- **Purpose**: To demonstrate sensor interfacing and ADC usage.

### LCD Display

**Description**: Shows how to interface with an LCD display to show text or data from the microcontroller.

- **Purpose**: To teach LCD control and text display techniques.

### EEPROM Data Storage

**Description**: Demonstrates reading from and writing to EEPROM memory for non-volatile data storage.

- **Purpose**: To illustrate EEPROM usage for preserving data across resets.

### I2C Communication

**Description**: Shows how to use the I2C protocol for communication with external devices.

- **Purpose**: To provide examples of I2C bus communication and device interfacing.

### ADC (Analog-to-Digital Converter)

**Description**: Demonstrates how to use the ADC to convert analog signals into digital values.

- **Purpose**: To show how to read and process analog inputs using ADC.

### SPI Communication

**Description**: Implements SPI communication for interfacing with SPI-compatible devices.

- **Purpose**: To demonstrate the use of SPI for high-speed data transfer between devices.

### Timer0 Example

**Description**: Shows how to use Timer0 to generate time delays or periodic interrupts.

- **Purpose**: To illustrate the use of Timer0 for timing and scheduling tasks.

### ICU (Input Capture Unit)

**Description**: Demonstrates the use of the Input Capture Unit (ICU) to measure the duration of an external signal.

- **Purpose**: To show how to use the ICU for precise timing and pulse measurement.

### Seven Segments Display

**Description**: Interfaces with a seven-segment display to show numeric values or characters.

- **Purpose**: To illustrate how to drive seven-segment displays for numeric and alphanumeric output.

## Getting Started

To get started with any of these projects:

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/faraha99/Embedded-AVR-NTI.git
   ```

2. **Navigate to the Project Directory**:

   ```bash
   cd Embedded-AVR-NTI/<project-folder>
   ```

3. **Compile the Code**:

   Use the provided `Makefile` or compile manually using `avr-gcc`. For example:

   ```bash
   avr-gcc -mmcu=atmega328p -o output.elf main.c
   ```

4. **Upload to Microcontroller**:

   Use an AVR programmer or debugger. For example:

   ```bash
   avrdude -c usbtiny -p atmega328p -U flash:w:output.hex
   ```

5. **Run and Test**:

   Power up the microcontroller and observe the behavior as described in the project documentation.

## Contributing

We welcome contributions! If you have suggestions or improvements:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a Pull Request.

Please ensure your contributions adhere to the coding standards and include relevant documentation.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- **AVR Microcontroller Community**: For valuable resources and support.
- **Open Source Projects**: Various libraries and tools used in this repository.
- **Contributors**: Thanks to all who have contributed to the repository.
