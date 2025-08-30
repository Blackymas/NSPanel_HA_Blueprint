# v4.3.29 - Climate Add-on Boot Reliability Enhancement

## Summary

This release focuses on improving boot reliability for users with the climate add-on
by implementing automatic NVS (Non-Volatile Storage) reset functionality during boot loops.

## Key Improvements

### Climate Add-on Boot Loop Recovery

**Implemented `factory_reset` platform** to automatically clear NVS data when boot loops are detected,
specifically targeting improved reliability for climate add-on configurations.

**How it works:**
- **Automatic NVS wipe** when boot loop conditions are detected
- **Targeted for climate add-on users** who have been experiencing persistent boot issues
- **Community-contributed solution** that has shown positive results in testing

**Expected benefits:**
- **Improved boot success rates** for climate add-on configurations
- **Automatic recovery** from corrupted NVS data that may cause boot loops  
- **Reduced need for manual intervention** during boot failures

**Important note:** When NVS reset occurs, **panel-specific settings will be lost** (display type, temperature offset, brightness settings, etc.).
However, **Blueprint configuration remains unaffected** - only settings stored locally on the panel are cleared.

### Community Collaboration

**Special thanks to @idstein** for suggesting this solution approach.
This improvement demonstrates the value of community input in solving complex technical challenges.

## Technical Details

**Issue Reference:** Community feedback and testing

The `factory_reset` platform monitors boot behavior and automatically clears Non-Volatile Storage
when boot loop conditions are detected. This addresses cases where corrupted or problematic
NVS data prevents successful system startup, particularly in memory-intensive configurations
like the climate add-on.

**Result:** Enhanced boot reliability for climate add-on users through automatic NVS reset functionality,
reducing manual recovery procedures and improving overall system resilience.

---

*Targeted improvement for climate add-on boot reliability through community-suggested NVS reset functionality.*
