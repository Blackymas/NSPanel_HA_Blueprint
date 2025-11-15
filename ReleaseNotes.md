# v2025110 - Display Light Add-on & Bug Fixes

## Summary

This release introduces an optional display control light entity add-on, prepares the codebase
for upcoming ESPHome 2025.11.x optimizations, and includes numerous bug fixes, some imported
from the unreleased v4.4 branch.

## Key Enhancements

### Panel Display Control via Light Entity (Add-on)

**Added optional light entity add-on for display control** - introduced a new add-on that
exposes display brightness, wake-up, and sleep control through a standard light entity in Home
Assistant.

**New capabilities:**
- Control display brightness through a light entity
- Wake up the display by turning the light on
- Put the display to sleep by turning the light off
- Native integration with Home Assistant lighting controls and automations

**Configuration:**
To enable this add-on, uncomment the following line in your ESPHome YAML packages section:
```yaml
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml
      # Optional add-ons
      - esphome/nspanel_esphome_addon_display_light.yaml  # Uncomment to enable
```

**Migration:**
- **If using custom display light configuration:** Remove your custom YAML and use this add-on
  instead for official support
- **If not using display light control:** No action required, this is optional

**Use cases:**
- Control display brightness alongside room lights
- Include display in "all lights off" automations
- Schedule display sleep/wake times using existing light automation tools
- Unified control interface for all lighting including the panel

**Issues Reference:** #2091

**Result:** Optional add-on providing display control via light entity, with cleaner integration
than previous custom configurations.

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
