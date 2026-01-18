# v2026010 – ESPHome 2026.1 Compatibility and Climate Page Fixes

## Summary

This release updates the codebase for compatibility with **ESPHome 2026.1.0**,
fixes issues introduced by **Home Assistant 2026.1.0**,
and includes fixes and improvements related to the climate page UI.

## Compatibility Notes

### ESPHome 2026.1.0 Support (Upcoming)

This release prepares the project for **ESPHome 2026.1.0**, scheduled for release on **January 21st**.

**Notes:**
- Forward-compatible changes aligned with ESPHome 2026.1 internal updates
- Fixes build issues observed with early ESPHome 2026.1 development versions
- No functional behavior changes are expected for earlier supported ESPHome versions

**Result:** The project will continue to build and operate correctly once ESPHome 2026.1.0 is released.

### Home Assistant 2026.1.0 Compatibility

**Fixed issues introduced by Home Assistant 2026.1.0** (released January 7th).

**Scope:**
- Adjustments required due to internal changes in Home Assistant 2026.1.0
- Fixes regressions affecting normal operation and entity handling

**Result:** Restored correct behavior when running Home Assistant 2026.1.0.

## Climate Page Fixes and Improvements

### Maximum Temperature Selection (Bug #3137)

**Fixed an issue where the climate page could not correctly set or display target temperatures above 9.4 °C when a large number of temperature steps was allowed.**

**Details:**
- The issue occurred with climate entities exposing fine-grained temperature steps
- Internally, the temperature range overflowed when more than 256 steps were available

**Result:** Correct maximum temperature handling for climate entities with high-resolution step configurations. (Tracked as **#3137**)

### Standardized Temperature Information (Enhancement #2343)

**Standardized the display of temperature information across climate and weather-related views.**

**Result:** Consistent and clearer temperature presentation using the configured temperature unit (°C / °F). (Tracked as **#2343**)

---

*ESPHome 2026.1.0 compatibility, Home Assistant 2026.1.0 fixes, and climate page UI improvements.*
