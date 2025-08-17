
# NAU7802 Library for Arduino

## About

Simple Arduino library for interfacing with the NAU7802 24-bit I2C ADC. Provides control over most basic functions of the ADC, including calibration, LDO, amplifier, channel, conversion rate, etc.

## Example Schematic

![Example Schematic](https://raw.githubusercontent.com/nathab32/NAU7802-Library/refs/heads/main/images/NAU7802_Schematic.png)

Typical application circuit for NAU7802. This schematic only utilizes channel 1 in a single ended mode, but other configurations are possible (differential, channel 2).

- SDIO connects to SDA pin on the Arduino (A4 on UNO and Nano)
- SCLK connects to SCL (A5 on UNO and Nano).

## Usage

1. Include the library using `#include <NAU7802.h>`
2. Create a NAU7802 variable.
3. Reset registers by calling `begin()`
4. Bring the NAU7802 out of low power mode by calling `standby(false)`
5. Configure the NAU7802 using the functions in the library.
6. Call `read()` to read the voltage across the current channel.

See `examples\example.cpp` for further help.
