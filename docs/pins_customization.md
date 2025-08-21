# 🔌 GPIO Pin Configuration Guide

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
  GPIO_RELAY_1_PIN: 22             # Simple GPIO number
  GPIO_BUZZER_OUTPUT_PIN: 21       # Custom GPIO for Buzzer output
  GPIO_BUTTON_LEFT_PIN:            # Complex GPIO with options
    number: 26
    inverted: true
  GPIO_DISPLAY_POWER_PIN:          # Another complex GPIO example
    number: 4
    inverted: true
```

**Key Notes:**
- Use simple numeric values (e.g., `22`) for basic GPIO assignments
- Use indented YAML syntax for complex configurations with multiple properties
- `inverted: true` is used when your hardware behaves in active-low mode (e.g., relay turns ON when pin is LOW)
- For advanced GPIO configuration options, see [ESPHome Pin Schema documentation](https://esphome.io/guides/configuration-types.html#pin-schema)

---

## 🔧 Available GPIO Keys

| Substitution Key              | Default Value                  | Function                                |
|-------------------------------|--------------------------------|-----------------------------------------|
| `GPIO_BUTTON_LEFT_PIN`        | `number: 14<br>inverted: true` | Left button input                       |
| `GPIO_BUTTON_RIGHT_PIN`       | `number: 27<br>inverted: true` | Right button input                      |
| `GPIO_BUZZER_OUTPUT_PIN`      | `21`                           | Buzzer output (PWM-compatible)          |
| `GPIO_DISPLAY_NEXTION_TX_PIN` | `16`                           | Nextion display TX (MCU → Display)      |
| `GPIO_DISPLAY_NEXTION_RX_PIN` | `17`                           | Nextion display RX (Display → MCU)      |
| `GPIO_DISPLAY_POWER_PIN`      | `number: 4<br>inverted: true`  | Backlight / display power control       |
| `GPIO_PSRAM_CLK_PIN`          | `5`                            | Optional PSRAM clock                    |
| `GPIO_PSRAM_CS_PIN`           | `18`                           | Optional PSRAM chip select              |
| `GPIO_RELAY_1_PIN`            | `22`                           | Relay 1 output                          |
| `GPIO_RELAY_2_PIN`            | `19`                           | Relay 2 output                          |
| `GPIO_TEMPERATURE_ADC_PIN`    | `38`                           | Analog input for NTC/temperature sensor |

---

## ⚠️ Troubleshooting

### Common Issues
- **Boot loops**: Check if you're using conflicting pins with your hardware design
- **Non-functional outputs**: Verify your hardware supports the selected pins
- **Inverted behavior**: Toggle the `inverted` flag or use `*_INVERTED` substitutions

### Validation Steps
1. Test each function individually after pin changes
2. Monitor serial logs for GPIO-related errors during boot
3. Refer to your hardware's documentation for pin compatibility

---
