
#########
# Task 1 and 2:

## Project Overview

This project uses an ESP32 to control two LEDs with different PWM frequencies. Both LEDs fade in and out independently. An OLED display shows the brightness percentage, PWM frequency, and resolution of the LEDs.

The project is developed using PlatformIO and the Arduino framework. It can be simulated in Wokwi or tested on physical ESP32 hardware.

## Objectives

- Control two LEDs using PWM.
- Configure different PWM frequencies for both LEDs.
- Use 8-bit PWM resolution.
- Create independent LED fading effects.
- Display LED brightness and PWM information on an OLED screen.
- Use `millis()` for non-blocking updates.

## Components Used

- ESP32 DevKit V4
- 1 Red LED
- 1 Green LED
- 2 × 220Ω resistors
- SSD1306 OLED display (128 × 64)
- Jumper wires
- Wokwi simulator or physical hardware

## Pin Configuration

| Component | ESP32 Pin |
|---|---|
| Red LED | GPIO 18 |
| Green LED | GPIO 19 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |
| OLED VCC | 3.3V |
| OLED GND | GND |

Each LED is connected in series with a 220Ω resistor. The LED cathodes are connected to GND.

## PWM Configuration

| Parameter | LED 1 (Red) | LED 2 (Green) |
|---|---:|---:|
| GPIO Pin | 18 | 19 |
| PWM Channel | 0 | 1 |
| Frequency | 1000 Hz | 5000 Hz |
| Resolution | 8-bit | 8-bit |
| Duty Cycle Range | 0–255 | 0–255 |

An 8-bit PWM resolution provides 256 duty-cycle levels, from 0 to 255.

## OLED Display

The SSD1306 OLED displays:

- Project title: DUAL PWM MONITOR
- LED 1 brightness percentage and frequency
- LED 2 brightness percentage and frequency
- PWM resolution: 8-bit

The display refreshes approximately every 150 milliseconds.

## How It Works

1. The ESP32 initializes the two PWM channels with different frequencies.
2. LED 1 uses a frequency of 1000 Hz, while LED 2 uses 5000 Hz.
3. Both LEDs independently increase and decrease their duty cycles.
4. A higher duty cycle increases the LED's average brightness, while a lower duty cycle decreases it.
5. The OLED updates periodically to show the current brightness percentage and configured PWM frequency.
6. The `millis()` function schedules updates without using long delays in the main loop.

## Software and Libraries

- Visual Studio Code
- PlatformIO IDE
- Arduino framework for ESP32
- Adafruit GFX Library
- Adafruit SSD1306 Library
- Wire library
- Wokwi Simulator

## How to Run the Project

1. Open the project in Visual Studio Code with PlatformIO installed.
2. Ensure the OLED and LED connections match the pin configuration.
3. Open `src/main.cpp` and check the program code.
4. Open the Wokwi simulation and start it.
5. Observe both LEDs fading independently.
6. Check the OLED display for brightness percentages and PWM frequencies.
7. To use physical hardware, connect the ESP32 using a USB data cable and upload the program.

## Expected Output

- The red LED fades in and out.
- The green LED fades in and out independently.
- The LEDs use different PWM frequencies.
- The OLED displays the brightness percentages and frequency values.
- The display indicates an 8-bit PWM resolution.

## Conclusion

This project demonstrates PWM-based LED brightness control using the ESP32. It also demonstrates independent fading, different PWM frequencies, non-blocking timing with `millis()`, and real-time monitoring through an SSD1306 OLED display.
