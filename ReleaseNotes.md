# v2026011 – Rollback of Home Assistant 2026.1 Blueprint Changes and Fixes

## Summary

This release **rolls back the blueprint changes introduced in v2026010 for Home Assistant 2026.1.0 compatibility**,
as they caused automation breakage for many users.
The original Home Assistant issue was limited to UI behavior and did not break functionality,
so restoring stability is prioritized.
This release also fixes an ESPHome compilation issue affecting temperature entities configured in Fahrenheit.

## Rollback Details

### Blueprint Changes for Home Assistant 2026.1.0

**Reverted the blueprint modifications introduced to support Home Assistant 2026.1.0.**

**Reason:**
- The changes broke automations for a significant number of users
- The underlying Home Assistant issue affected only the UI and not core functionality
- The regression impact outweighed the benefit of the UI-related fix

**Result:** Restored the previously stable and working automation behavior.

## User Guidance

If issues persist after updating to this release, it is recommended to **re-set or re-save automations affected by recent changes**,
as some problems may be related to formatting changes introduced in **v2026010**.

**Result:** Re-applying the configuration should restore correct behavior in remaining edge cases.

## Bug Fixes

### Temperature Entity (Fahrenheit) – ESPHome Compile Error

**Fixed an issue with temperature entities configured in Fahrenheit that prevented ESPHome from compiling.**

**Result:** ESPHome now compiles correctly when using Fahrenheit-based temperature entities.

## Compatibility Notes

### Home Assistant 2026.1.0

- Compatible with Home Assistant 2026.1.0
- Blueprint changes related to HA 2026.1.0 have been reverted
- A known UI limitation may remain, but functionality is preserved

**Result:** Stable operation without automation regressions.

---

*Rollback release prioritizing automation stability, with additional fixes for Fahrenheit temperature entities and ESPHome compilation.*
