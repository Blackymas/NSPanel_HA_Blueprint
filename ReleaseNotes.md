# v2026013 – Fahrenheit Temperature Handling Fixes and Fixed Baud Rate

## Summary

This release focuses on **fixing temperature unit handling when using Fahrenheit**,
addressing multiple issues related to incorrect display, reporting, and UI behavior.
It also **standardizes the serial communication speed to 115200 bps**,
removing configurable speed selectors to reduce the risk of baud rate mismatches between the TFT and ESPHome.

## Climate and Temperature Fixes

### Fahrenheit (°F) Temperature Handling

**Fixed multiple issues affecting temperature display and behavior when using Fahrenheit.**

**Scope:**
- Corrected cases where temperatures were always reported or displayed as Celsius
- Fixed erratic UI behavior when changing temperature values in Fahrenheit
- Ensured hardware temperature sensors report the correct unit when `temp_units: "°F"` is configured
- Improved consistency between Home Assistant, ESPHome, and panel UI when operating in Fahrenheit

**Result:** Correct, consistent, and predictable temperature handling when using Fahrenheit across the entire climate stack.

## Communication and Stability Improvements

### Fixed Baud Rate at 115200 bps

**Standardized the communication baud rate to 115200 bps across the project.**

**Changes:**
- Removed baud rate / speed selectors to avoid configuration mismatches
- The TFT file now enforces **115200 bps**
- The ESPHome configuration is hard-coded to **115200 bps**

**Reason:**
- Reduces the likelihood of communication issues caused by mismatched baud rates
- Improves reliability during panel upgrades and restarts

**Result:** More robust and predictable communication between ESPHome and the TFT, with fewer connection-related issues.

---

*Fixes Fahrenheit temperature handling issues and enforces a fixed 115200 bps baud rate to improve reliability.*
