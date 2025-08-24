# v4.3.25 - Enhanced Display Component Reliability and Performance

## Summary

This release primarily fixes page construction issues that were introduced by earlier boot timing adjustments
and removes support for the advanced package to simplify memory management.
The queuing system introduced in v4.3.24 has been removed as it became obsolete after timing optimizations.

## Key Improvements

### Queuing System Removal

**Removed the queuing system introduced in v4.3.24** as it became obsolete after optimizing the timing approach.
By reverting the problematic delays that were causing page construction issues, 
the sequential queuing is no longer necessary to prevent timing conflicts.

**Simplification achieved:**
- **Direct component rendering restored** without queuing overhead
- **Cleaner code architecture** by removing unnecessary complexity
- **Better performance** through more direct component interaction

### Page Construction Issue Resolution

**Fixed page construction and update problems** that were introduced when boot timing adjustments were also applied to page constructors.
While the boot delays were necessary for ESPHome 2025.8.0 compatibility, applying similar delays to page construction caused rendering issues.

**Solution implemented:**
- **Removed delays from page constructors** while keeping essential boot delays intact
- **Maintained boot stability** for ESPHome 2025.8.0 compatibility
- **Restored normal page rendering speed** without timing interference

**Result:** Pages now construct and update properly while boot stability improvements remain in place.

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

This release represents a simplification approach, removing unnecessary complexity introduced during the boot crisis resolution.
By finding the optimal timing balance, both the queuing system and problematic delays could be removed,
resulting in cleaner code and better performance.

The removal of the advanced package aligns with our focus on core functionality and user-controlled customization,
particularly important given the memory constraints revealed during recent compatibility challenges.

**Result:** More responsive system performance with robust component rendering across all display elements.

-----

*This proactive expansion ensures reliable display functionality while improving overall system efficiency and simplifying project architecture.*
