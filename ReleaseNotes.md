# v4.3.30 - Memory Optimization for Add-on Stability

## Summary

This release focuses on reducing system memory usage to enable stable operation with add-ons.
Non-critical components have been removed to free up memory resources for core functionality and add-on support.

## Breaking Changes

### Boot Sound Configuration Change

**The "Sound - Boot" switch has been removed** as part of memory optimization efforts.
Boot sound functionality is now controlled via substitution for better memory efficiency.

**Migration required:**
- **Old method:** "Sound - Boot" switch in Home Assistant
- **New method:** `boot_sound` substitution in your YAML configuration

**How to enable boot sound:**
```yaml
substitutions:
  boot_sound: true  # Set to false to disable (default)
```

**Default behavior:** Boot sound is **disabled by default** (`boot_sound: false`).
If you were using the boot sound feature, you'll need to add the substitution above to maintain this functionality.

**Important notes:**
- **Volume dependency:** Boot sound won't be audible if the panel volume is set to 0
- **Previous behavior change:** Users who had notification sound enabled used to automatically get boot sound.
    Now boot sound must be explicitly enabled via the `boot_sound` substitution regardless of notification settings

## Key Improvements

### Memory Optimization Initiative

**Reduced system memory footprint** to provide stable foundation for add-on usage.
The recent boot compatibility challenges highlighted memory constraints as a critical factor,
leading to this focused optimization effort.

**Memory reduction approach:**
- **Removed non-critical diagnostic sensors** that consumed memory without essential functionality
- **Eliminated recently added controls** that weren't core to basic operation
- **Streamlined base system** to maximize available memory for add-ons
- **Prioritized core functionality** over optional diagnostic features

**Target achieved:**
- **Stable add-on operation** - primary goal of freeing memory for climate, cover, and other add-ons
- **Improved boot reliability** through reduced memory pressure
- **Better system resilience** with more memory headroom

### Component Removals

**Non-critical components removed to optimize memory usage:**
- Various diagnostic sensors that provided optional system information
- Recently added control components that weren't essential for core operation
- Other memory-consuming features that didn't impact basic NSPanel functionality

**What remains:**
- All core NSPanel functionality preserved
- Essential diagnostic and control features maintained
- Full compatibility with Home Assistant Blueprint configuration

### Minor Bug Fixes

**Resolved several minor issues** discovered during the memory optimization process,
improving overall system stability and reliability.

## Impact on Users

**No functional impact on core NSPanel operation** - all essential features remain available.

**Benefits:**
- **More stable add-on performance** - climate, cover, and other add-ons should run more reliably
- **Improved boot success rates** - reduced memory pressure during startup
- **Better overall system stability** - more memory headroom for normal operation

**Trade-offs:**
- **Fewer diagnostic sensors** - some optional system monitoring features removed
- **Reduced optional controls** - non-essential configuration options eliminated

## Technical Details

This release represents a strategic shift toward memory efficiency and add-on compatibility.
The optimization focuses on the core NSPanel experience while ensuring sufficient resources
for popular add-ons that enhance functionality.

**Result:** Optimized memory usage enabling stable add-on operation while maintaining
all essential NSPanel functionality and improving overall system reliability.

---

*Memory-focused optimization to enable stable add-on usage and improved system reliability.*
