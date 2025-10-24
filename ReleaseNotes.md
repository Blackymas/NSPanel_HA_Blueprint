# v202510.0 - Memory Optimization & UI Enhancements

## Summary

This release introduces a new calendar-based versioning model, focuses on memory optimization,
and changes button bar text to match button bar colors by default (breaking change - can be
reverted with configuration).

## Versioning Model Change

### New Calendar-Based Versioning

**Transitioned from semantic to calendar-based versioning** - version numbers now follow a
`yyyymm.x` format for more predictable and frequent releases.

**Previous versioning:**
- Format: `v4.3.46` (major.medium.minor)
- Based on perceived importance/criticality of changes
- Required subjective decisions about version number increments

**New versioning:**
- Format: `v202510.0` (yyyymm.sequential)
- Year and month followed by sequential number within that month
- First release of October 2025 is `v202510.0`, second would be `v202510.1`, etc.

**Rationale:**
- **Removes subjectivity:** No need to classify changes as major/medium/minor
- **Enables faster releases:** Supports "fail fast, fix fast" development approach
- **Calendar clarity:** Users can immediately see when a release was published
- **Memory efficient:** Numeric format saves bytes compared to date strings (also used by
  ESPHome Builder and Home Assistant)
- **Reduces confusion:** Different format from ESPHome Builder and Home Assistant (`yyyy.mm.x`)
  helps distinguish between firmware version and builder/HA version when users report issues

**Result:** More predictable versioning with frequent, iterative releases and reduced decision overhead.

## Key Enhancements

### Memory Optimization

**Further memory optimizations implemented** - additional improvements to reduce flash memory
usage, providing more headroom for future features and customizations.

**Improvements:**
- Optimized code structure to reduce flash memory footprint
- Enhanced memory efficiency across core components
- Improved resource utilization for ESP32 devices

**Result:** Reduced flash memory usage, ensuring better performance and leaving more space
available for user customizations and future updates.

### Button Bar Text Color Matching

**Breaking Change: Button bar text now matches button bar color by default** - button bar text
color now follows the button bar background color, creating a more cohesive visual appearance.
Users who prefer the previous behavior can opt out of this change.

**Configuration:**
```yaml
substitutions:
  # Set to false to restore previous text color behavior (default: true)
  buttons_bar_text_follow_color: false
```

**Behavior:**
- **Default (`true`):** Button bar text color matches the button bar background color (NEW)
- **When set to `false`:** Button bar text uses the standard/default text color (PREVIOUS)

**Migration:**
- If you prefer the previous text color appearance, set `buttons_bar_text_follow_color: false`
- No action needed if you want the new color-matched appearance

**Use cases:**
- Improved visual consistency across the interface
- Better color coordination for themed designs
- Flexibility to maintain traditional appearance if preferred

**Issues Reference:** #2675

**Result:** Enhanced visual consistency with configurable text color behavior for button bars.

## Bug Fixes

### Notification Icon Persistence

**Fixed notification icon not clearing on home page** - resolved issue where the notification
icon remained visible on the home page after the notification was cleared.

**Issue details:**
- **Problem:** Notification icon on home page persisted even after clearing the notification
- **Impact:** Users had no visual indication that notifications were actually cleared
- **Affected area:** Home page notification indicator

**Fix implemented:**
- Notification icon now properly clears when notification is dismissed
- Home page visual state correctly reflects notification status

**Issues Reference:** #2627

**Result:** Notification icon state now correctly syncs with notification status.

---

*Memory optimization and improved button bar aesthetics.*
