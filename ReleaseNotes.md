# v4.3.46 - QR Code Initialization Hotfix

## Summary

This hotfix release resolves a critical initialization issue introduced in v4.3.45
that prevented the blueprint from being recognized as loaded when QR code functionality was disabled.

## Critical Fix

### Blueprint Initialization with QR Code Disabled

**Fixed initialization failure when QR code is disabled** - resolved issue where the blueprint would not be considered fully loaded
if QR code functionality was disabled in configuration.

**Issue details:**
- **Problem introduced in:** v4.3.45
- **Impact:** Blueprint failed to initialize properly when QR code was disabled
- **Affected users:** Anyone with QR code functionality disabled in their configuration

**Fix implemented:**
- Corrected initialization sequence to properly handle disabled QR code state
- Blueprint now loads correctly regardless of QR code configuration

**Issues Reference:** #2991, #2994

**Result:** Blueprint initialization now works correctly with QR code functionality disabled.

---

*Hotfix for v4.3.45 QR code initialization issue.*