# v4.4 - Automatic TFT Update

## General
This release introduces the option to automatically update the TFT when an older version is detected,
simplifying the update process and ensuring your panel always runs the latest display firmware.

## Breaking Changes and Guidance

### Home Assistant v2024.10.0 and ESPHome v2024.8.0 are required
Please refer to our [Version Compatibility Matrix](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/version_compatibility.md) for a full list.

### Changes on the versioning requires updating all the three components
Moving forward, update all three components (Blueprint, ESPHome, and TFT) together to ensure consistency.

### Many diagnostic sensors disappeared
I know some of you love some of those, but we had to compromise something to free-up a bit of memory for the new things.
The values are now shown in the logs and if you need as a sensor please report as an issue and we can support with customizations.

### Users using the "Display as a light" customization must remove it
This is now part of the core system.

### Several changes in the API
Now all actions will use a common way of transferring information to ESPHome, with the main goal to make it easier to use,
but also trying to reduce the communication between ESPHome and Nextion, preventing buffer overflows and slowness on the interface.
We highly recommend visiting our [API documentation](docs/api.md) for the latest syntax for the different actions.

In addition to this standardization, there are some noteworth changes to the API:
1. Action `components_visibility` is deprecated

    It was replaced by [`component_visibility` action](docs/api.md#component-visibility-action-component_visibility).

1. Action `icon` now requires page name as a parameter

    More info at [API doc - Icon action](docs/api.md#icon-action-icon).

1. Actions `init_global`, `init_hardware`, `init_page_home`, `set_timezone` and `hw_button_state` are deprecated

    They have been replaced by `set_number` and `set_string` which are used only during the boot or automation reloaded.

1. Sensor `blueprint_status` was removed

    The boot process was totally rebuilt and this info is now transferred via events.

1. Notification unread sensor

    The former "**Notification unread**" switch is now a binary sensor.

### Customizations
We made improvements in some scripts, so the customizations using those scripts must be updated:
- [Sleep & Wake-up buttons](docs/customization.md#sleep--wake-up-buttons)
- [Set display as a light (deprecated)](docs/customization.md#set-display-as-a-light)

## Noteworthy Changes

### Dynamic QR Code (#452 & #2283)
- **Criticality:** Enhancement
- **Issue Numbers:**
  - #452
  - #2283
- **Description:**
  Introduces the ability to assign an entity (supports input text or sensors) to a QR code. 
  The QR code will automatically update on the panel when the entity's value changes.

  This feature is useful in cases where you have dynamic content, such as a Wi-Fi password, and 
  want the panel to display the updated value in real-time.

### Swipe Functionality Improvement and Bug Fix (#2244)
- **Criticality:** Medium
- **Issue Number:** #2244
- **Description:** Resolved an issue where swipe functionality would intermittently stop working under specific conditions.
  The swipe timer is now properly stopped on touch release before checking API status, preventing the timer from running indefinitely.
  The swipe engine has been removed from pages where swipe is not available, enhancing system performance and reliability.

### Fix for Climate Page Access with Embedded Thermostat Without Blueprint (#2190)
- **Criticality:** Minor
- **Issue Number:** #2190
- **Description:** Resolved an issue preventing access to the climate page from the home page when using the embedded thermostat without blueprint connection
  (e.g., when Home Assistant or Wi-Fi is unavailable).
  This fix ensures that the NSPanel can still navigate correctly to the climate page when the internal temperature sensor is displayed, even if the blueprint connection is lost.

### Keep Display Off with Button Press While Sleeping (#2194)
- **Criticality:** Minor
- **Issue Number:** #2194
- **Description:** Implemented a fix that allows the display to remain off when a button is pressed while the panel is sleeping.
  This update addresses a reported problem and enhances the overall behavior of the display during sleep mode.

### Fix for Missing Default Icon After Manual Deletion (#2200)
- **Criticality:** Minor
- **Issue Number:** #2200
- **Description:** Fixed an issue where default icons were not displayed after manually deleting a previously set custom icon on the home page.
  Once a custom icon is removed and the field is left blank, the system now correctly reverts to displaying the default icon.

### Custom UART Compilation Issue Resolved (#2265)
- **Criticality:** Minor
- **Issue Number:** #2265
- **Description:** Fixed a compilation issue when using a custom UART with the advanced package by specifying the Nextion UART ID during command execution.
  This fix ensures compatibility and prevents build failures, allowing advanced UART configurations.

### Screen Wake-Up on Hardware Button Press Configurable (#2194)
- **Criticality:** Enhancement
- **Issue Number:** #2194
- **Description:** Added a new switch to configure whether the panel should wake up when a hardware button is pressed.
  This switch is available under **Settings** > **Devices & services** > **ESPHome** in Home Assistant.
  It provides users with flexibility to control display wake-up behavior via hardware buttons.

### TFT Update Automatically (#2227)
- **Criticality:** Enhancement
- **Issue Number:** #2227
- **Description:** Introduced an automatic TFT update mechanism that triggers whenever the system detects an outdated TFT version.
  This enhancement streamlines the process of keeping your NSPanel display firmware up to date, minimizing manual intervention.

### Versioning Engine Updated to Enforce Patch-Level Consistency
- **Criticality:** Enhancement
- **Description:** Updated the versioning engine to require all components (Blueprint, ESPHome, and TFT) to match at the patch level,
  enhancing reliability by ensuring all parts are fully synchronized. This supports the new automatic TFT update feature.

### Panel Display Control via Light Entity (#2091)
- **Criticality:** Enhancement
- **Affected Components:** ESPHome
- **Issue Number:** #2091
- **Description:** Introduced a light entity to represent the NSPanel's display, allowing users to control the panel’s brightness, wake it up,
  or put it to sleep through third-party automations designed for lights.
  Users with existing customizations should remove them from their YAML configuration.

### Updated CLIMATE_MODE_AUTO Icon on Climate Page (#2243)
- **Criticality:** Enhancement
- **Affected Components:** ESPHome
- **Issue Number:** #2243
- **Description:** Updated the CLIMATE_MODE_AUTO icon on the Climate page from “mdi:calendar-sync” to “mdi:refresh-auto.”
  This change provides a clearer representation of the automatic mode.

### Updated References from `service` to `action` for Compatibility with New Standards
- **Criticality:** Enhancement
- **Affected Components:** Blueprint, ESPHome
- **Description:** Updated all references from `service` to `action` to comply with Home Assistant v2024.8.0 and ESPHome v2024.8.0 standards,
  ensuring full compatibility with the latest versions.

### Reduced Logging to Enhance Focus on Critical Information
- **Criticality:** Enhancement, Breaking Change
- **Affected Components:** ESPHome, Blueprint
- **Description:** Logging has been streamlined to focus on the most critical information, reducing noise and improving the clarity of logs.
  While this change enhances readability and allows users to quickly identify important messages,
  it may alter the behavior of existing troubleshooting processes that relied on more verbose logs.
  
> [!WARNING]
> Users who depend on detailed logs for debugging may need to adjust their troubleshooting strategies or temporarily adjust log levels as needed.
