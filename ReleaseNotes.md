# v4.3.34 - Memory Optimization

## Summary

This release continues memory optimization efforts to enable stable operation with add-ons and Bluetooth functionality for users who add Bluetooth components to their panels.
The focus this time is on optimizing brightness controls in the settings page.

## Breaking Changes

### Brightness Control Optimization

**Removed "Current brightness" sensor** that was previously available to users in Home Assistant,
as part of ongoing memory optimization to support add-ons and Bluetooth functionality.

**What was removed:**
- **Current brightness sensor** - previously visible to users in Home Assistant
- **Two internal brightness sensors** - these were already internal and not visible to users

**Migration options:**
- **For general users:** Most won't be affected as this sensor isn't commonly used in automations
- **For affected users:** The sensor can be restored as a customization - see [Current Brightness Sensor](docs/customization.md#current-brightness-sensor) documentation
- **For "Display as a light" users:** Update your customization code - the [updated code](docs/customization.md#set-display-as-a-light) is already available in documentation

## Key Improvements

### Continued Memory Optimization

**Further memory reduction** targeting stable operation with memory-intensive add-ons,
particularly focusing on enabling smooth Bluetooth functionality for users who add Bluetooth components to their panels.

**Optimization progress:**
- **Settings page streamlined** - reduced memory usage in brightness controls
- **Add-on compatibility focus** - freeing memory for stable add-on operation
- **Bluetooth support goal** - working toward reliable Bluetooth add-on functionality

### Memory Management Strategy

**Systematic approach** to memory optimization by identifying and removing components
that can be optionally restored via customizations for users who need them.

**Strategy benefits:**
- **Default configuration optimized** for maximum compatibility
- **User choice preserved** through customization options
- **Targeted memory savings** focusing on high-impact optimizations

## Bug Fixes

### Relay Icon Display Fix

**Fixed relay icons showing incorrectly during home page load** - resolved visual glitch where relay icons would display incorrect state for a brief moment during page loading.

**Issue details:**
- Problem was recently introduced during optimization efforts
- Icons would show wrong state for a fraction of a second during home page load
- **Fixed by @gr1los** in PR #2885

**Result:** Clean home page loading with correct relay icon states from the start.

## Technical Details

This release continues the aggressive memory optimization approach,
targeting components that provide optional functionality while maintaining
core NSPanel features and user customization options.

**Result:** Additional memory savings contributing toward reliable add-on support and Bluetooth functionality for users who add Bluetooth components to their panels,
with clear migration paths for affected users.

---

*Continued memory optimization for add-on compatibility with user customization options preserved.*
