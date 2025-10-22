# v4.3.45 - Alarm Security Vulnerability Fix

## Summary

This release fixes a critical security vulnerability in the alarm module where triggered alarms
could be bypassed by switching to another armed state.

## Key Enhancements

### Dynamic QR Code Support

**Rebuilt QR code engine enabling dynamic QR code functionality** - users can now assign entities to QR codes
that automatically update when the entity value changes.

**New capabilities:**
- **Entity-based QR codes:** Assign input text or sensor entities to QR codes
- **Automatic updates:** QR code refreshes automatically when entity value changes
- **Real-time display:** Panel shows updated QR codes immediately
- **Dynamic content support:** Ideal for changing content like Wi-Fi passwords, authentication codes, etc.

**Configuration options:**

**For boot-time static QR codes:**
```yaml
substitutions:
  qrcode_initial_value: ''         # Set initial QR code content
  qrcode_title_initial_value: ''   # Set initial QR code title
  qrcode_restore_value: false      # Set to true to remember last QR code across reboots
```

**Use cases:**
- Dynamic Wi-Fi passwords that change periodically
- Time-based authentication codes
- Rotating access credentials
- Any content that updates over time

**Issues Reference:** #452, #2283

**Result:** Flexible QR code system supporting both static and dynamic content with entity integration.

### Hardware Button Wake-Up Control

**Added configurable option to control display wake-up behavior with hardware buttons** - users can now
choose whether physical button presses should wake the display from sleep/screensaver mode.

**Configuration:**
```yaml
substitutions:
  wakeup_with_button_press: false  # Set to true to enable wake-up with hardware button press (default: false)
```

**Behavior:**
- **When set to `false` (default):** Physical button presses do NOT wake the display from screensaver/sleep mode
- **When set to `true`:** Physical button presses WILL wake the display from screensaver/sleep mode

**Use cases:**
- Prevent accidental wake-ups from unintended button presses
- Customized wake behavior based on installation location
- Coordinated wake-up with other automation triggers

**Issues Reference:** #2638

**Result:** Users gain granular control over display wake-up behavior, allowing customization based on specific use cases and preferences.

## Critical Security Fix

### Alarm Bypass Vulnerability Resolved

**Fixed security vulnerability allowing alarm trigger bypass** - resolved issue where switching
to another armed state while alarm was triggered would cancel the trigger, effectively bypassing the alarm.

**Vulnerability details:**
- **Previous behavior:** When alarm was armed and triggered, switching to another armed state (e.g., arm away to arm home) would cancel the trigger
- **Security risk:** Allowed bypassing active alarm triggers without disarming
- **Impact:** All users with alarm functionality were potentially affected

**Fix implemented:**
- **When alarm is triggered:** Only disarm action is available (always enforced)
- **When alarm is armed (optional):** Set `require_disarm_before_rearm: true` to require disarm before switching armed states
- **Configurable behavior:** Users can choose whether to require disarm when switching between armed states

**Configuration:**
```yaml
substitutions:
  require_disarm_before_rearm: false  # Set to true to require disarm before switching armed states (default: false)
```

**Default behavior:** 
- Disarm always required when triggered (security enforced)
- Switching between armed states allowed by default (`require_disarm_before_rearm: false`)
- Can be made more restrictive by setting substitution to `true`

**Result:** Alarm system now properly enforces security by requiring disarm action
for triggered alarms, with optional enforcement for armed state transitions.

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
