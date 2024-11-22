# v4.4 - Automatic TFT Update

## General
This release introduces the option to automatically update the TFT when an older version is detected,
simplifying the update process and ensuring your panel always runs the latest display firmware.

## Breaking Changes and Guidance

### Home Assistant v2024.11.0 and ESPHome v2024.11.0 are required
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
1. Deprecated actions:

    <!-- markdownlint-disable MD033 -->
    | Deprecated action | Replacement | Previous use |
    | :--: | :--: | :-- |
    | `init_global`<br>`init_hardware`<br>`hw_button_state` | `set_number`<br>`set_string` | Used to send settings at boot |
    | `init_page_home` | [`component`](docs/api.md#component-action-component) | Used to send global values to page Home |
    | `set_timezone` | `set_string` | Used to send time zone settings at boot |
    | `component_text`<br>`component_color`<br>`component_visibility`<br>`icon`| [`component`](docs/api.md#component-action-component) | Used to set a component on the display |
    <!-- markdownlint-enable MD033 -->

1. Sensor `blueprint_status` was removed

    The boot process was totally rebuilt and this info is now transferred via events.

1. Notification unread sensor

    The former "**Notification unread**" switch is now a binary sensor.

### Customizations
We made improvements in some scripts, so the customizations using those scripts must be updated:
- [Sleep & Wake-up buttons](docs/customization.md#sleep--wake-up-buttons)
- [Set display as a light (deprecated)](docs/customization.md#set-display-as-a-light)

## Noteworthy Changes

### Dynamic QR Code
- **Description:**
  Introduces the ability to assign an entity (supports input text or sensors) to a QR code. 
  The QR code will automatically update on the panel when the entity's value changes.

  In addition, the limit for a QRcode was extended to 96 chars (or bytes), giving more room for complex codes.  

  This feature is useful in cases where you have dynamic content, such as a Wi-Fi password, and 
  want the panel to display the updated value in real-time.

  Your current selection for QRcode still working, as it will be used as a fallback value when an entity is not used or is used, but it is unavailable.
- **Related Issue Numbers:**
  - #452
  - #2282
  - #2283

### Full support to 921600bps
- **Description:**
  The default baud rate for the communication between ESP32 (ESPHome) and the Nextion Display was changed from 115200bps to 921600bps, multiplying by 8 the transfer rate.
  This may increase the responsiveness and user experience, and will allow for future development of features which requires more of this communication.
- **Related Issue Numbers:**
  - #2230
- **Issues and discussions that could benefit from this in the future:**
  - #1270
  - #2328
  - #2357

### Buzzer volume control
- **Description:**
  Now you can set the volume level of your panel's buzzer, allowing to better experience when using your panel for sounds.

> [!NOTE]
> You can disable the sound on changing volume by adding the following to your panel's substitutions:
> ```yaml
> substitutions:
>   tone_volume_change: "none"  # Or choose your own RTTTL tone

### Screen Wake-Up on Hardware Button Press Configurable
- **Description:** Added a new switch to configure whether the panel should wake up when a hardware button is pressed.
  This switch is available under **Settings** > **Devices & services** > **ESPHome** in Home Assistant.
  It provides users with flexibility to control display wake-up behavior via hardware buttons.
- **Issue Number:** #2194

### TFT Update Automatically
- **Description:** Introduced an automatic TFT update mechanism that triggers whenever the system detects an outdated TFT version.
  This enhancement streamlines the process of keeping your NSPanel display firmware up to date, minimizing manual intervention.
- **Issue Number:** #2227

### Versioning Engine Updated to Enforce Patch-Level Consistency
- **Description:** Updated the versioning engine to require all components (Blueprint, ESPHome, and TFT) to match at the patch level,
  enhancing reliability by ensuring all parts are fully synchronized. This supports the new automatic TFT update feature.

### Panel Display Control via Light Entity
- **Description:** Introduced a light entity to represent the NSPanel's display, allowing users to control the panel’s brightness, wake it up,
  or put it to sleep through third-party automations designed for lights.
  Users with existing customizations should remove them from their YAML configuration.
- **Issue Number:** #2091

### Updated CLIMATE_MODE_AUTO Icon on Climate Page
- **Description:** Updated the CLIMATE_MODE_AUTO icon on the Climate page from “mdi:calendar-sync” to “mdi:refresh-auto.”
  This change provides a clearer representation of the automatic mode.
- **Issue Number:** #2243

### Updated References from `service` to `action` for Compatibility with New Standards
- **Description:** Updated all references from `service` to `action` to comply with Home Assistant v2024.8.0 and ESPHome v2024.8.0 standards,
  ensuring full compatibility with the latest versions.

### Reduced Logging to Enhance Focus on Critical Information
- **Description:** Logging has been streamlined to focus on the most critical information, reducing noise and improving the clarity of logs.
  While this change enhances readability and allows users to quickly identify important messages,
  it may alter the behavior of existing troubleshooting processes that relied on more verbose logs.
  
> [!WARNING]
> Users who depend on detailed logs for debugging may need to adjust their troubleshooting strategies or temporarily adjust log levels as needed.
