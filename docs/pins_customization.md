# 📌 GPIO Pin Configuration Guide

> [!WARNING]
> This configuration is tailored for a specific hardware layout.
> If you override GPIO pins without understanding your hardware, you may encounter issues or conflicts.
>
> **Only customize these pins if you are confident in your hardware compatibility and understand the risks.**

This document explains how to customize GPIO pin assignments for this project using **ESPHome `substitutions`**.
Substitutions allow you to reuse the same YAML configuration across different hardware variants or setups by
overriding key parameters like GPIO pins or logic inversion flags.

---

## 🧩 How to Customize Pins

To change any pin, simply override the substitution in your ESPHome YAML configuration:

```yaml
substitutions:
  GPIO_RELAY_1_PIN: '12'       # Custom GPIO for Relay 1
  GPIO_RELAY_1_INVERTED: 'true'
```

Inverted logic is used when your connected hardware behaves in active-low mode (e.g., relay turns ON when pin is LOW).

---

## 🔧 Available GPIO Keys

| Substitution Key                   | Default Value | Function                                  |
|------------------------------------|---------------|-------------------------------------------|
| `GPIO_BUTTON_LEFT_PIN`             | `14`          | Left button input                         |
| `GPIO_BUTTON_LEFT_INVERTED`        | `true`        | Inverts logic for left button             |
| `GPIO_BUTTON_RIGHT_PIN`            | `27`          | Right button input                        |
| `GPIO_BUTTON_RIGHT_INVERTED`       | `true`        | Inverts logic for right button            |
| `GPIO_BUZZER_OUTPUT_PIN`           | `21`          | Buzzer output (PWM-compatible)            |
| `GPIO_BUZZER_OUTPUT_INVERTED`      | `false`       | Inverts buzzer logic                      |
| `GPIO_DISPLAY_NEXTION_TX_PIN`      | `16`          | Nextion display TX (MCU → Display)        |
| `GPIO_DISPLAY_NEXTION_RX_PIN`      | `17`          | Nextion display RX (Display → MCU)        |
| `GPIO_DISPLAY_POWER_PIN`           | `4`           | Backlight / display power control         |
| `GPIO_DISPLAY_POWER_INVERTED`      | `true`        | Inverts display power logic               |
| `GPIO_PSRAM_CLK_PIN`               | `5`           | Optional PSRAM clock                      |
| `GPIO_PSRAM_CS_PIN`                | `18`          | Optional PSRAM chip select                |
| `GPIO_RELAY_1_PIN`                 | `22`          | Relay 1 output                            |
| `GPIO_RELAY_1_INVERTED`            | `false`       | Inverts logic for Relay 1                 |
| `GPIO_RELAY_2_PIN`                 | `19`          | Relay 2 output                            |
| `GPIO_RELAY_2_INVERTED`            | `false`       | Inverts logic for Relay 2                 |
| `GPIO_TEMPERATURE_ADC_PIN`         | `38`          | Analog input for NTC/temperature sensor   |

---
