# v4.3.19 - Fix alarm control panel action name not updating between calls

## Critical Fixes
- **Alarm Control Panel Action Persistence (#2653)**: Corrected the alarm control panel action name persistence issue introduced in v4.3.18,
  which caused a runtime error when calling `alarm_control_panel.alarm_*` actions more than once.
  Thanks @Kaibob2 for the numerous tests and detailed logs on #2653.

## Enhancements
- **Release Notes Simplification**: Streamlined the Release Notes file format to accelerate the release process.
  Complete change history remains available in the GitHub release section.
- **Climate Dual Relay Support (#2605)**: Enhanced Climate Dual component to allow assignment of the same relay to both "heat" and "cool" modes
  for unified heating/cooling systems.

## Maintenance
- **Deprecated Warning Resolution**: Removed unused `publish_initial_state` parameter that generated deprecation warnings.
- **Localization Enhancement (#2660)**: Added Catalan language support. Thanks to @ppuig71.
- **HMI/TFT Update**: Updated HMI/TFT files to v1.68.1 for latest Nextion compatibility.
