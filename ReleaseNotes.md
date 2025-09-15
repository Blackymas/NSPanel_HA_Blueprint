# v4.3.33 - Memory Optimization Focus for Boot Loop Resolution

## Summary

This release continues aggressive memory optimization efforts aimed at resolving boot loop issues for all configurations,
including support for Bluetooth add-ons. Additional bug fixes improve overall system stability.

## Breaking Changes

### Notification Text Sensors Removed

**Two notification-related text sensors have been removed** as part of memory optimization efforts:
- **Notification Label sensor** (page title)
- **Notification Message sensor** (page body)

**Why removed:** These sensors were redundant - they reflected back to Home Assistant the same information that was just sent via action calls from Home Assistant.

**Impact:** Most users won't notice any difference since these sensors provided duplicate information.

**Need these sensors?** If your automations rely on these sensors, please report this as an issue on GitHub. We're happy to help with either:
- Workarounds that don't require the sensors
- Adding them back as optional customizations

**For current supported actions and API capabilities, consult the [API documentation](docs/api.md).**

## Key Improvements

### Aggressive Memory Optimization

**Focused memory reduction effort** targeting complete boot loop resolution across all configurations, including support for memory-intensive add-ons like Bluetooth.

**Optimization goals:**
- **Universal boot reliability** - resolve boot loops for all users
- **Bluetooth compatibility** - enable stable operation with Bluetooth add-ons
- **Maximum memory efficiency** - aggressive reduction of non-essential components

**Progress status:** Significant memory freed up, with more optimization work planned for upcoming releases.

### Additional Bug Fixes

**Resolved several reported issues** continuing the stability improvement efforts from recent releases.

**Bug fixes include:**
- Various edge case handling improvements
- Enhanced system reliability
- Better error recovery mechanisms

## Current Status & Goals

**Primary objective:** Enable stable operation with Bluetooth add-ons through continued memory optimization.

**Ongoing work:** Additional memory optimizations planned for upcoming releases to achieve full Bluetooth compatibility.

**If you're currently stable - no immediate action needed.** These optimizations benefit all users by improving boot reliability and system stability.

## Technical Details

This release represents a focused approach to memory management,
prioritizing essential functionality while aggressively removing redundant or non-critical components.
The goal is achieving reliable operation across all add-on configurations, particularly memory-intensive ones like Bluetooth.

**Result:** Significant memory savings contributing toward universal boot reliability, with continued optimization work planned to achieve full add-on compatibility.

---

*Continued aggressive memory optimization targeting universal boot reliability and Bluetooth add-on support.*
