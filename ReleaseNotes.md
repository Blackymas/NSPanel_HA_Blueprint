# v2026010 – ESPHome 2026.1 Compatibility and Climate Page Fixes

## Summary

This release prepares the codebase for **ESPHome 2026.1.0** compatibility,
fixes issues introduced by **Home Assistant 2026.1.0**, and resolves a climate page bug affecting maximum temperature selection when a large number of temperature steps is allowed.

## Compatibility Notes

### ESPHome 2026.1.0 Support (Upcoming)

This release updates the codebase to support **ESPHome 2026.1.0**, scheduled for release on **January 21st**.

**Notes:**
- The changes are forward-compatible with ESPHome 2026.1.0
- No functional behavior changes are expected for earlier supported ESPHome versions
- This prepares the project for upcoming ESPHome internal and API changes

**Result:** Smooth transition once ESPHome 2026.1.0 is released, with no further firmware changes required.

### Home Assistant 2026.1.0 Fixes

**Fixed issues introduced by Home Assistant 2026.1.0** (released January 7th).

**Scope:**
- Adjustments to maintain correct behavior after Home Assistant 2026.1 internal changes
- Prevents regressions affecting UI behavior and entity handling

**Result:** Restored correct operation when running Home Assistant 2026.1.0.

## Bug Fixes

### Climate Page – Maximum Temperature Selection

**Fixed a bug in the climate page that caused the maximum temperature to break when more than 256 temperature steps are allowed.**

**Previous behavior:**
- When the climate entity allowed a large number of temperature steps, the maximum selectable temperature could not be reached correctly
- This resulted in truncated or incorrect temperature limits on the climate page

**New behavior:**
- Correct handling of climate entities with more than 256 temperature steps
- Maximum temperature can now be selected and displayed correctly regardless of step count

**Result:** Reliable and correct temperature control for climate entities with fine-grained temperature resolution.

---

*ESPHome 2026.1.0 compatibility preparation, Home Assistant 2026.1.0 fixes, and climate page temperature limit correction.*
