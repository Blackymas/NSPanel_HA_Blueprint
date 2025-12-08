# v2025120 - Configurable Climate Page Button Icon Sizes

## Summary

This release introduces configurable icon sizes for climate page buttons, leverages new
optimizations from ESPHome 2025.11.0, and includes breaking changes that require ESPHome
2025.11.0 or newer.

## Breaking Changes

### ESPHome 2025.11.0 Required

**ESPHome 2025.11.0 or newer is now required** - this release takes advantage of optimizations
introduced in ESPHome 2025.11.0 and is not compatible with earlier versions.

**Required action:**
- Upgrade to ESPHome 2025.11.0 or newer before updating to this firmware version
- Earlier ESPHome versions will not build this release successfully

### Temperature Step Substitution Deprecated

**Deprecated `temp_step` substitution** - temperature step values are now hard-coded for
consistency and optimized memory usage.

**Previous behavior:**
- `temp_step` substitution allowed custom temperature step configuration

**New behavior:**
- Target temperature step: 0.5°C or 1°F (hard-coded)
- Current temperature step: 0.1°C or 0.1°F (hard-coded)

**Migration:**
- Remove `temp_step` substitution from your configuration if present
- Temperature steps now follow standard HVAC conventions

**Result:** Simplified configuration with standardized temperature steps following common HVAC
practices.

## Key Enhancements

### Configurable Climate Page Icon Size

**Added configurable icon size for climate page buttons** - climate page button icons can now
be resized via automation/blueprint configuration.

**New capabilities:**
- Adjust icon size for climate control buttons
- Larger touch area for improved usability
- Configurable through Home Assistant automation/blueprint

**Benefits:**
- Better accessibility with larger icons and touch areas
- Customizable to user preferences
- Improved touch responsiveness

**Result:** More flexible and accessible climate page interface with configurable icon sizes and
enhanced touch areas.

### ESPHome 2025.11.0 Optimizations

**Implemented optimizations enabled by ESPHome 2025.11.0** - leveraged new optimization
features introduced in ESPHome 2025.11.0 for improved performance and memory efficiency.

**Improvements:**
- Reduced flash memory usage through ESPHome 2025.11.0 optimizations
- Enhanced runtime performance
- Better memory management

**Result:** Improved performance and memory efficiency through ESPHome 2025.11.0 features.

---

*Climate icon configuration and ESPHome 2025.11.0 optimizations. Requires ESPHome 2025.11.0+.*
