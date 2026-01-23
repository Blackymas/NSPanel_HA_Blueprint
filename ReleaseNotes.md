# v2026012 – Climate Page Fixes, Alarm Page Regression Fix, and ESPHome 2026.2 Preparation

## Summary

This release fixes multiple issues related to **climate page temperature handling**,
resolves a **critical regression in the alarm page** introduced in v2026010,
and addresses a **deprecation warning announced for ESPHome 2026.2.0**.

Starting with this version, **ESPHome 2026.1.0 is now required**.

## Breaking Changes

### ESPHome 2026.1.0 Required

**ESPHome 2026.1.0 or newer is now required**.

**Reason:**
- The fixes and refactoring included in this release depend on changes introduced in ESPHome 2026.1.0
- Ensures correct behavior and avoids compatibility issues with older ESPHome versions

**Required action:**
- Upgrade ESPHome to **2026.1.0 or newer** before updating to this release

**Result:** Guaranteed compatibility with current and upcoming ESPHome releases.

## Climate Page Fixes

### Fahrenheit (°F) Handling Improvements

**Fixed issues affecting climate entities when operating in Fahrenheit mode.**

**Scope:**
- Corrected temperature handling and display inconsistencies when using °F
- Prevented erratic or incorrect temperature values on the climate page
- Improved robustness of climate logic for Fahrenheit-based entities

**Result:** Stable and correct climate page behavior when using Fahrenheit.

## Alarm Page Fixes

### Alarm Action Not Sent Correctly (Regression since v2026010)

**Fixed a critical regression where alarm state change actions were not being sent correctly.**

**Details:**
- The regression was introduced in **v2026010**
- Alarm page interactions appeared correct in the UI but did not reliably propagate the action

**Result:** Alarm actions are now sent and processed correctly again.

## Compatibility and Maintenance

### ESPHome 2026.2.0 Deprecation Warning

**Resolved a deprecation warning scheduled to be introduced with ESPHome 2026.2.0** (expected end of February).

**Details:**
- Updated affected code paths to align with upcoming ESPHome changes
- Prevents future warnings and potential breakage

**Result:** Clean builds and forward compatibility with ESPHome 2026.2.0.

---

*Requires ESPHome 2026.1.0+. Includes climate page Fahrenheit fixes, alarm page regression fix, and preparation for ESPHome 2026.2.0.*
