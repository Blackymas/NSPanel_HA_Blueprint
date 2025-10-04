# v4.3.38 - Memory Optimization

## Summary

This release continues memory optimization efforts to enable stable operation with add-ons and Bluetooth functionality.
The TFT upload control has been converted from a switch to a substitution for better memory efficiency.

## Breaking Changes

### TFT Upload Configuration Change

**The "Update TFT automatically" switch has been removed** as part of memory optimization efforts.
Automatic TFT upload functionality is now controlled via substitution for better memory efficiency.

**Migration required:**
- **Old method:** "Update TFT automatically" switch in Home Assistant
- **New method:** `upload_tft_automatically` substitution in your YAML configuration

**How to disable automatic TFT upload:**
```yaml
substitutions:
  upload_tft_automatically: false  # Set to true to enable (default)
```

**Default behavior:** Automatic TFT upload is **enabled by default** (`upload_tft_automatically: true`).
If you had disabled automatic TFT uploads via the switch, you'll need to add the substitution above to maintain this preference.

## Key Improvements

### Continued Memory Optimization

**Further memory reduction** targeting stable operation with memory-intensive add-ons,
particularly focusing on enabling reliable operation for users who add Bluetooth components to their panels.

**Optimization progress:**
- **TFT upload control streamlined** - reduced memory usage by converting switch to substitution
- **Add-on compatibility focus** - freeing memory for stable add-on operation
- **Bluetooth support goal** - working toward reliable Bluetooth functionality

### Memory Management Strategy

**Systematic approach** to memory optimization by identifying and removing components
that can be optionally restored via customizations for users who need them.

**Strategy benefits:**
- **Default configuration optimized** for maximum compatibility
- **User choice preserved** through substitution options
- **Targeted memory savings** focusing on high-impact optimizations

## Technical Details

This release continues the aggressive memory optimization approach,
targeting components that provide optional functionality while maintaining
core NSPanel features and user customization options.

**Result:** Additional memory savings contributing toward reliable add-on support and Bluetooth functionality
for users who add Bluetooth components to their panels.

---

*Continued memory optimization for add-on compatibility with user customization options preserved.*
