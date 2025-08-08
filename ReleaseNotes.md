## v4.3.19 - Fix alarm control panel action name not updating between calls
Corrected the alarm control panel action name persistence introduced in v4.3.18,
which caused a runtime error when calling `alarm_control_panel.alarm_*` actions more than once.

### Other relevant changes
- **Simplified Release Notes file**: To make easier and faster to release. You can always find all the same info on the release area on GitHub.
- **Resolved warning message related to `publish_initial_state`**: That was deprecated and not used, so it was removed.
- **Added support to Catalan**: Thanks to @ppuig71 on #2660
