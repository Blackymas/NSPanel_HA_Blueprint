# v4.3.25 - Enhanced Display Component Reliability and Performance

## Summary

This release extends the queuing system introduced in v4.3.24 to additional display components,
optimizes boot timing for better performance without compromising stability,
and removes support for the advanced package to simplify memory management.

## Key Improvements

### Comprehensive Component Queue System

**Extended queued rendering system** beyond button pages to cover additional display components that
could experience similar timing conflicts.
Building on the successful button fix in v4.3.24, this release applies the same sequential processing approach
to prevent rendering conflicts across all affected components.

**Components now using queued processing:**

- Button pages (previously fixed in v4.3.24)
- Additional display components susceptible to timing conflicts
- All components that interact with display rendering during boot sequence

### Optimized Boot Timing

**Refined boot delays for improved efficiency** while maintaining ESPHome 2025.8.0 compatibility.
The timing adjustments have been fine-tuned to provide better performance
without compromising the stability improvements that resolved the original boot issues.

**Boot sequence optimization:**
- **Wi-Fi component initialization moved later** in the boot process to reduce early-stage system load
- **Core components load first** ensuring essential functionality is established before network connectivity
- **Reduced boot crashes** by distributing component loading more evenly across the boot timeline

**Performance improvements:**

- **More efficient boot sequence** with optimized delay timing and component loading order
- **Faster overall boot times** while preserving compatibility fixes
- **Reduced system overhead** through smarter timing management and load distribution

## Breaking Changes

### Advanced Package Support Removed

**The `nspanel_esphome_advanced.yaml` package has been discontinued** as part of our ongoing simplification efforts.

#### What Was Removed:
- **Obsolete "Exit reparse" button** - no longer needed with modern firmware
- **Memory-intensive components** - `web_server`, `captive_portal`, and other optional components
- **Legacy functionality** - components that aren't required by the core project

#### Why This Change:
- **Better memory management** - removes unnecessary memory consumption that could contribute to boot issues
- **User responsibility** - users who need these components can add them manually with full control over memory usage
- **Simplified releases** - fewer packages to maintain and test
- **Cleaner core functionality** - focuses on essential NSPanel features

#### Migration Guide:
If you were using the advanced package:

1. **Remove from your YAML:**
   ```yaml
   # Remove this line
   - esphome/nspanel_esphome_advanced.yaml
   ```

2. **Add components manually if needed:**
   ```yaml
   # Only add what you actually need
   web_server:
     port: 80
   
   captive_portal:
   ```

3. **Monitor memory usage** - these components consume significant memory, so ensure your panel has sufficient resources

## Technical Details

This release represents a comprehensive approach to display timing management and boot sequence optimization,
applying lessons learned from the button rendering fix to the broader system.
The optimized delays and component loading order strike a better balance between performance and reliability,
with Wi-Fi initialization deferred to reduce early boot system load.

The removal of the advanced package aligns with our focus on core functionality and user-controlled customization,
particularly important given the memory constraints revealed during recent compatibility challenges.

**Result:** More responsive system performance with robust component rendering across all display elements.

-----

*This proactive expansion ensures reliable display functionality while improving overall system efficiency and simplifying project architecture.*
