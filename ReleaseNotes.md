# v4.3.45 - Alarm Security Vulnerability Fix

## Summary

This release fixes a critical security vulnerability in the alarm module where triggered alarms
could be bypassed by switching to another armed state.

## Critical Security Fix

### Alarm Bypass Vulnerability Resolved

**Fixed security vulnerability allowing alarm trigger bypass** - resolved issue where switching
to another armed state while alarm was triggered would cancel the trigger, effectively bypassing the alarm.

**Vulnerability details:**
- **Previous behavior:** When alarm was armed and triggered, switching to another armed state (e.g., arm away to arm home) would cancel the trigger
- **Security risk:** Allowed bypassing active alarm triggers without disarming
- **Impact:** All users with alarm functionality were potentially affected

**Fix implemented:**
- **Once armed, arming, or triggered:** Only disarm action is allowed
- **All other state changes disabled:** Prevents bypassing triggered alarms
- **Security enforced:** Triggered alarms can only be resolved by proper disarming

**Result:** Alarm system now properly enforces security by requiring disarm action
for triggered alarms, closing the security loophole.

## Community Contribution

**Special thanks to @ecov773** for identifying this security vulnerability and providing the fix.

**Pull Request:** #2981

## Technical Details

This fix strengthens alarm security by restricting state transitions when the alarm is armed, arming, or triggered.
The only permitted action from these states is disarm, preventing security bypasses through state switching.

**Result:** Enhanced alarm security with proper state transition enforcement
preventing alarm trigger bypass.

---

*Critical security fix for alarm trigger bypass vulnerability. Thanks @ecov773!*
