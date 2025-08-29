# v4.3.28 - Enhanced Notifications and Boot Screen Improvements

## Summary

This release rebuilds the notification system and ensures the screen remains active during boot,
providing better user experience and visibility into system status.

## Key Improvements

### Alarm Page Crash Fix

**Resolved crash when opening the alarm page** by adjusting timing delays that were likely triggering the watchdog timer.
Users experiencing crashes when accessing alarm functionality should see improved stability.

**Issue resolved:**
- Fixed watchdog-triggered crashes on alarm page access
- Improved alarm page loading reliability
- Better overall stability when navigating to alarm controls

**Issue Reference:** #2795

### Rebuilt Notification System

**Comprehensive rebuild of the notification system** to improve reliability and functionality.
The notification handling has been redesigned to provide more consistent behavior
and better integration with the overall system.

**Notification improvements:**
- Enhanced notification display reliability
- Better notification management and clearing
- Improved notification persistence and timing
- More consistent notification behavior across different scenarios

### Boot Screen Behavior Restored

**Reverted to pre-crisis boot screen behavior** where the display remains active during boot.
During the crisis response, we implemented a delay before turning the screen on during boot,
but this showed no significant improvement in boot reliability while reducing user experience.

**Boot screen restoration:**
- Screen no longer turns off during shutdown/restart sequence
- Immediate boot visibility restored (pre-crisis behavior)
- Better user experience during system restarts
- No measurable impact on boot reliability, so prioritizing usability

## User Experience

These changes provide immediate benefits for daily use:
- **Better notification reliability** - messages display and clear more predictably
- **Boot transparency** - users can see what's happening during startup
- **Improved troubleshooting** - boot issues are more visible and diagnosable

## Technical Details

**Issue Reference:** #2783

The notification system rebuild addresses long-standing reliability issues,
while the boot screen enhancement provides valuable visibility into system startup.
These improvements contribute to both functionality and user experience.

**Result:** More reliable notification handling and better boot process visibility
for improved system usability and troubleshooting capability.

---

*Enhanced user experience with better notifications and boot visibility.*
