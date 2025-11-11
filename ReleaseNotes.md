# v2025110 - Display Control Light Entity & Bug Fixes

## Summary

This release introduces native display control via a light entity, eliminates the need for
custom YAML configurations, and prepares the codebase for upcoming ESPHome 2025.11.x
optimizations. It also includes numerous bug fixes, some imported from the unreleased v4.4
branch.

## Key Enhancements

### Panel Display Control via Light Entity

**Added native light entity for display control** - integrated display brightness, wake-up, and
sleep control through a standard light entity, previously only available as a custom
configuration.

**New capabilities:**
- Control display brightness through a light entity
- Wake up the display by turning the light on
- Put the display to sleep by turning the light off
- Native integration with Home Assistant lighting controls and automations

**Migration:**
- **Action required:** Remove any existing custom YAML configuration for display control
- The light entity is now part of the core functionality
- Previous customizations (like those from customization docs) are no longer needed

**Use cases:**
- Control display brightness alongside room lights
- Include display in "all lights off" automations
- Schedule display sleep/wake times using existing light automation tools
- Unified control interface for all lighting including the panel

**Issues Reference:** #2091

**Result:** Simplified display control with native light entity integration, eliminating the
need for custom YAML configurations.

### ESPHome 2025.11.x Optimization Support

**Prepared code for new ESPHome optimizations** - updated codebase to take advantage of new
optimization features coming in ESPHome 2025.11.x (expected release: November 19, 2025).

**Improvements:**
- Code optimized for upcoming ESPHome 2025.11.x features
- Maintains backward compatibility with current ESPHome versions
- Ready to leverage performance improvements when ESPHome 2025.11.x is released

**Note:** These optimizations will automatically activate when upgrading to ESPHome 2025.11.0 or
later. No configuration changes required.

**Result:** Future-ready codebase prepared for ESPHome 2025.11.x performance improvements.

## Bug Fixes

### Multiple Issue Resolutions

**Fixed numerous bugs from v2025102 and unreleased v4.4** - resolved various issues including
bug fixes that were developed for v4.4 but never released.

**Fix sources:**
- Issues reported after v2025102 release
- Bug fixes from unreleased v4.4 branch integrated into this release
- General stability and reliability improvements

**Result:** Improved overall stability with comprehensive bug fixes from multiple development
branches.

---

*Display control light entity and extensive bug fixes.*
