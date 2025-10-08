# v4.3.38 - Memory Optimization

## Summary

This release continues memory optimization efforts to enable stable operation with add-ons and Bluetooth functionality.
The TFT upload control has been converted from a switch to a substitution for better memory efficiency.

## Breaking Changes

### TFT Upload Configuration Changes

**The "Update TFT automatically" switch has been removed** as part of memory optimization efforts.
Automatic TFT upload functionality is now controlled via substitution for better memory efficiency.

**The "Update TFT display - Baud rate" select has also been removed** and replaced with a substitution.

**The "Sound - Volume" control has been removed** as part of memory optimization efforts.

**Migration required:**

**For automatic TFT upload control:**
- **Old method:** "Update TFT automatically" switch in Home Assistant
- **New method:** `upload_tft_automatically` substitution in your YAML configuration

**How to disable automatic TFT upload:**
```yaml
substitutions:
  upload_tft_automatically: false  # Set to true to enable (default)
```

**For TFT upload baud rate:**
- **Old method:** "Update TFT display - Baud rate" select in Home Assistant
- **New method:** `upload_tft_baud_rate` substitution in your YAML configuration
- **Important:** UART baud rate changes are buggy and may cause failures.
  The substitution option remains available for advanced users,
  but changing baud rates carries significant risk of communication failures.

**How to change TFT upload baud rate (advanced users only):**
```yaml
substitutions:
  upload_tft_baud_rate: 115200  # Default value, changing not recommended due to UART bugs
```

**Note:** We're investigating alternatives for future versions,
including potentially moving all UART communications to 921600 baud rate permanently for improved performance and reliability.

**For sound volume:**
- **Old method:** "Sound - Volume" control in Home Assistant
- Volume control has been removed to reduce memory usage
- Volume now operates at maximum level (as it did before the control was introduced)

**Default behaviors:** 
- Automatic TFT upload is **enabled by default** (`upload_tft_automatically: true`)
- TFT upload baud rate defaults to **115200** (`upload_tft_baud_rate: 115200`)

If you had customized these settings via switches/selects, you'll need to add the appropriate substitutions to maintain your preferences.

## Key Improvements

### Continued Memory Optimization

**Further memory reduction** targeting stable operation with memory-intensive add-ons,
particularly focusing on enabling reliable operation for users who add Bluetooth components to their panels.

**Optimization progress:**
- **TFT upload control streamlined** - reduced memory usage by converting switch to substitution
- **Add-on compatibility focus** - freeing memory for stable add-on operation
- **Bluetooth support goal** - working toward reliable Bluetooth functionality
- **Bluetooth testing success** - initial tests show successful operation with `bluetooth_proxy`

**Issue Reference:** #2717

**Important note:** While initial testing shows `bluetooth_proxy` working successfully,
Bluetooth functionality remains officially unsupported at this time.
Users who choose to add Bluetooth components do so at their own risk, understanding that stability may vary and support is limited.

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
