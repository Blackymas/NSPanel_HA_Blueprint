# v20251001 (formerly v202510.1) - Bug Fixes & Versioning Update

## Summary

This release focuses on bug fixes addressing several issues reported in v202510.0, includes
improvements to the home page icon navigation engine, and updates the versioning format to
integer-based `yyyymmxx` to avoid floating-point precision issues.

## Bug Fixes

### QR Code Icon Display

**Fixed QR code icon showing when feature was disabled** - resolved issue where the QR code icon
was displayed on the home page even when the QR code feature was disabled in configuration.

**Issues Reference:** #3003

**Result:** QR code icon now correctly hidden when QR code feature is disabled.

## Improvements

### Home Page Icon Engine

**Rebuilt home page icon engine for page navigation** - improved the engine that handles icon
updates on the home page for QR code and utilities page access.

**Improvements:**
- Rebuilt icon update mechanism for home page
- Enhanced reliability when calling QR code page from home page icon
- Enhanced reliability when calling utilities page from home page icon

**Result:** More robust icon-based navigation from home page to QR code and utilities pages.

## Versioning Format Change

### Integer-Based Versioning

**Updated versioning format to integer-based `yyyymmxx`** - changed from `yyyymm.x` to
`yyyymmxx` format to avoid floating-point precision issues.

**Previous format (v202510.0):**
- Format: `yyyymm.x` (year, month, sequential with decimal)
- Issue: Floating-point precision problems in some systems
- Adopted in: v202510.0 (short-lived)

**New format (v20251101):**
- Format: `yyyymmxx` (year, month, zero-padded sequential starting from 01)
- First release of month: `yyyymm01` (e.g., `20251101` for first November 2025 release)
- Second release: `20251102`, then `20251103`, etc.
- Sequential counter: 01-99 (supports up to 99 releases per month)
- Pure integer format avoids floating-point issues

**Rationale:**
- **Eliminates floating-point precision issues:** Integer format ensures consistent parsing
- **Maintains calendar clarity:** Year and month still immediately visible
- **Retains sequential ordering:** Two-digit sequential counter supports up to 99 releases/month
- **System compatibility:** Works reliably across all platforms and parsers

**Note:** This change comes shortly after adopting the `yyyymm.x` format, but is necessary to
address technical limitations discovered during testing.

**Result:** Robust integer-based versioning that avoids floating-point precision issues while
maintaining calendar-based benefits.

## Bug Fixes (continued)

### Utility Icon Visibility

**Fixed utility icon not being displayed on home page** - resolved issue where the utility icon
was not shown on the home page when it should have been visible.

**Issues Reference:** #3004

**Result:** Utility icon now displays correctly on the home page when utilities are configured.

### Partial Wake-Up on Button Press

**Fixed incomplete wake-up behavior with button press** - resolved issue where pressing buttons
resulted in partial wake-up behavior on the screensaver page.

**Behavior:**
- **When `wakeup_with_button_press: true`:** Button presses now properly wake up the display from
  screensaver mode
- **When `wakeup_with_button_press: false` (default):** Panel stays in sleep mode as intended
- Button commands are processed regardless of the wake-up setting

**Issues Reference:** #3007

**Result:** Button press wake-up behavior now works correctly based on configuration, while
button commands are always processed.

### Blueprint Boot Initialization

**Fixed excessive requests to Blueprint during boot** - resolved issue causing too many requests
to be sent to the Blueprint during the initialization process, which could overload Wi-Fi.

**Issue details:**
- Multiple simultaneous requests during boot could overload Wi-Fi
- Problem was more pronounced on slower Wi-Fi connections
- Created a feedback loop where slow Wi-Fi made the issue worse

**Issues Reference:** #3011

**Result:** Reduced boot-time requests to Blueprint, improving initialization performance and
preventing Wi-Fi overload, especially on slower connections.

### Alarm Disarm from Triggered State

**Fixed alarm only disarming from triggered state** - resolved issue where the alarm could only
be disarmed when in triggered state, preventing normal disarm operations from armed states.

**Issues Reference:** #3013

**Result:** Alarm can now be properly disarmed from both armed and triggered states.

### Offline Panel Behavior

**Fixed panel not working properly when offline** - resolved issue where the panel did not
function correctly when disconnected from Blueprint data.

**Offline conditions:**
- Blueprint automation disabled, missing, or has errors
- Home Assistant inaccessible
- Wi-Fi connection lost or unavailable

**Issues Reference:** #3012

**Result:** Panel now operates correctly in offline mode when not receiving data from Blueprint.

---

*Bug fix release for v202510.0 issues.*
