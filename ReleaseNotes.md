# v4.3.40 - Major Memory Optimization

## Summary

This release delivers significant memory optimization through a complete restructuring of the Nextion-ESPHome communication protocol, replacing JSON with CSV format for substantially reduced memory usage.

## Key Improvements

### Communication Protocol Overhaul

**Completely replaced JSON-based communication with CSV format** between Nextion display and ESPHome,
resulting in dramatic memory savings and improved efficiency.

**Protocol changes:**

- **Replaced JSON parsing with CSV** - eliminated heavy JSON library dependencies
- **Reduced memory footprint** - CSV parsing requires significantly less memory than JSON
- **Improved performance** - faster parsing and lower overhead
- **Maintained functionality** - all features work identically from user perspective

**Benefits:**

- **Substantial memory savings** - major reduction in RAM usage during communication
- **Better Bluetooth compatibility** - more memory available for Bluetooth and add-ons
- **Increased stability** - reduced memory pressure improves overall system reliability
- **No user impact** - change is completely transparent to users

### Additional Memory Optimizations

**Extensive memory optimization work** throughout the codebase beyond the protocol change,
targeting maximum memory efficiency while preserving all core functionality.

**Optimization scope:**

- Component memory usage reviewed and optimized
- Data structure efficiency improvements
- Eliminated unnecessary memory allocations
- Streamlined memory-intensive operations

## Technical Details

The JSON to CSV conversion represents a fundamental architectural improvement in how the panel
communicates internally. CSV’s simplicity and efficiency make it ideal for the constrained
embedded environment, providing the same functionality with a fraction of the memory overhead.

This release represents one of the most significant memory optimization efforts in the project,
opening the door for more reliable operation with memory-intensive features like Bluetooth.

**Result:** Dramatically reduced memory usage through protocol modernization and comprehensive optimization,
improving stability and compatibility with add-ons and Bluetooth functionality.

-----

*Major memory optimization release with fundamental communication protocol improvements.*
