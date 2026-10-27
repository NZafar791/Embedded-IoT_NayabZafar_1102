
# Homework 2 — Task 1: Dual-LED PWM Fading

## Project Overview
This project uses an ESP32 to control two LEDs independently using Pulse Width Modulation (PWM). Both LEDs fade smoothly from minimum to maximum brightness and back. Each LED uses a different PWM frequency.

## Components Required
- ESP32 DevKit board
- 1 Red LED
- 1 Blue LED
- 2 × 220-ohm resistors
- Jumper wires
- Wokwi simulator

## Circuit Connections

| Component | ESP32 Pin |
|---|---|
| Red LED anode through 220-ohm resistor | GPIO 18 |
| Red LED cathode | GND |
| Blue LED anode through 220-ohm resistor | GPIO 19 |
| Blue LED cathode | GND |

A separate 220-ohm resistor is used for each LED to limit current.

## PWM Configuration

| Parameter | LED 1 (Red) | LED 2 (Blue) |
|---|---|---|
| GPIO Pin | 18 | 19 |
| PWM Channel | 0 | 1 |
| PWM Frequency | 1000 Hz | 5000 Hz |
| PWM Resolution | 8-bit | 8-bit |
| Duty Cycle Range | 0–255 | 255–0 |

## Working Principle

1. The `setup()` function configures the PWM channels, frequencies, and resolution for both LEDs.
2. The first `for` loop increases the duty cycle from 0 to 255.
3. LED 1 becomes brighter while LED 2 becomes dimmer.
4. The second `for` loop decreases the duty cycle from 255 to 0.
5. The `ledcWrite()` function updates the PWM duty cycle.
6. The `delay(10)` function creates a short delay between brightness changes.

## Duty Cycle and Brightness

The duty cycle controls the apparent brightness of an LED.

- Duty cycle 0: LED is OFF.
- Duty cycle 127: LED is approximately half brightness.
- Duty cycle 255: LED is approximately full brightness.

An 8-bit PWM resolution provides 256 duty-cycle levels, from 0 to 255.

## PWM Frequency

PWM frequency is the number of ON/OFF cycles per second.

- LED 1 uses a frequency of 1000 Hz.
- LED 2 uses a frequency of 5000 Hz.

PWM frequency affects the switching speed of the signal, while duty cycle controls the apparent LED brightness.

## How to Run the Project

### Wokwi Simulation
1. Open the Homework-2 project in VS Code.
2. Check the circuit connections in `diagram.json`.
3. Build the project using PlatformIO.
4. Start the Wokwi simulation.
5. Verify that both LEDs fade smoothly.
6. Capture a screenshot of the running circuit.

### Physical Hardware
1. Connect both LEDs to the ESP32 using separate 220-ohm resistors.
2. Connect the red LED circuit to GPIO 18.
3. Connect the blue LED circuit to GPIO 19.
4. Connect both LED cathodes to GND.
5. Upload the program to the ESP32.
6. Verify that both LEDs fade correctly.

## Project Files

- `platformio.ini` — PlatformIO configuration.
- `src/main.cpp` — Main ESP32 program.
- `diagram.json` — Wokwi circuit configuration.
- `wokwi.toml` — Wokwi project configuration.
- `README.md` — Project documentation.


