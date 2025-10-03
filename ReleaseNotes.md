# v4.3.35 - Alarm Pin Code Action Fix

## Summary

This release fixes a critical issue with alarm control panel functionality where selected actions
were not being executed when using a PIN code.

## Bug Fixes

### Alarm Action Execution with PIN Code

**Fixed alarm actions not executing when PIN code is used** - resolved issue where alarm control
actions (arm away, arm home, disarm, etc.) would fail to execute after entering a valid PIN code.

**Issue details:**
- Actions selected on the alarm page weren't being triggered when PIN code authentication was required
- Valid PIN codes were accepted but the intended action would not execute
- Affected all alarm operations that require PIN code verification

**Issue Reference:** #2884

**Result:** Alarm control panel now correctly executes selected actions after successful PIN code entry.

## Technical Details

This fix ensures proper action execution flow in the alarm control panel when PIN code authentication
is enabled, restoring full functionality to PIN-protected alarm operations.

**Result:** Reliable alarm control panel operation with PIN code authentication working as expected.

---

*Critical fix for alarm control panel PIN code functionality.*
