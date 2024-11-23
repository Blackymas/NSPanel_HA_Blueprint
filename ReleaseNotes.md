# v4.4 - Dynamic QR Codes, Improved Usability, and More

## General
Version 4.4 focuses on enhancing the usability and functionality of your NSPanel. The device page has been  
refined for a cleaner, more user-friendly experience, now allowing you to control the panel as a light.

In addition to improved performance, this release introduces dynamic QR codes, automatic TFT updates, and  
new features like buzzer volume control and configurable wake-up settings, making your panel more versatile.

## Breaking Changes and Guidance

### Home Assistant v2024.11.0 and ESPHome v2024.11.0 are required
Refer to our  
[Version Compatibility Matrix](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/version_compatibility.md).

### Versioning changes require updating all three components
Update all components (Blueprint, ESPHome, and TFT) together for compatibility and consistency.

### Substitution `nextion_update_url` deprecated
To simplify the system and make it more intuitive, the substitution `nextion_update_url` has been deprecated.  
It is replaced by `nextion_update_base_url`, which specifies a base location (e.g., a local server or remote URL).  
The system automatically appends the version name to the path, making it easier to organize and manage files.

For example, if you set:  
`nextion_update_base_url: "http://homeassistant.local:8234/local/nspanel/"`  
and your panel is running version `v4.4.0`, the system will look for files under:  
`http://homeassistant.local:8234/local/nspanel/v4.4.0/`.

This enables flexible hosting options while maintaining the ability to use local files.  
The default value for `nextion_update_base_url` is:  
`https://raw.githubusercontent.com/Blackymas/NSPanel_HA_Blueprint/`.

To use a local server (e.g., Home Assistant), ensure the files are organized by version. For example:  
Store the files for version `v4.4.0` in `/www/nspanel/v4.4.0/` on your Home Assistant server, and configure:  
```yaml
substitutions:
  nextion_update_base_url: "http://homeassistant.local:8234/local/nspanel/"  # Base folder for files
```

### Diagnostic sensors removed
Some diagnostic sensors were removed to free memory for new features. Their values are logged; request custom  
sensor support via an issue if required.

### "Display as a light" customization removed
This feature is now part of the core system. Remove the related YAML customization from your configuration.

### API changes and standardization
All actions now use a unified method to transfer information, reducing overhead and improving responsiveness  
between ESPHome and Nextion. Visit the updated [API documentation](docs/api.md) for details.

#### Key API Changes:
1. **Deprecated actions**  
   <!-- markdownlint-disable MD033 -->  
   | Deprecated action                  | Replacement              | Previous use                    |  
   | :--------------------------------- | :----------------------- | :----------------------------- |  
   | `init_global`, `init_hardware`     | `set_number`, `set_string` | Sent settings at boot          |  
   | `init_page_home`                   | [`component`](docs/api.md#component-action-component) | Sent values to page Home |  
   | `set_timezone`                     | `set_string`             | Sent timezone settings         |  
   | `component_text`, `icon`, etc.     | [`component`](docs/api.md#component-action-component) | Set display components |  
   <!-- markdownlint-enable MD033 -->

2. **Sensor `blueprint_status` removed**  
   Boot info is now transferred via events.

3. **Notification unread switch replaced**  
   The "**Notification unread**" switch is now a binary sensor.

### Customizations
Updated scripts require adjustments to these customizations:  
- [Sleep & Wake-up buttons](docs/customization.md#sleep--wake-up-buttons)  
- [Set display as a light (deprecated)](docs/customization.md#set-display-as-a-light)

## Noteworthy Changes

### Dynamic QR Code
Assign an entity (input text or sensor) to a QR code. The QR code updates dynamically with entity value changes.  
QR code length limit extended to 96 chars for more complex codes.  

If no entity is set or is unavailable, the fallback QR code is used.  

**Related Issues:**  
- #452  
- #2282  
- #2283  

### Full support for 921600bps
Communication baud rate between ESP32 and Nextion increased from 115200bps to 921600bps, enhancing transfer speed.  
This supports better user experience and future feature development.  

**Related Issues:**  
- #2230  
- #1270  
- #2328  
- #2357  

### Buzzer volume control
Set the panel buzzer volume for a tailored sound experience.  

> [!NOTE]  
> Disable sound during volume change by adding the following to substitutions:  
> ```yaml  
> substitutions:  
>   tone_volume_change: "none"  # Or set a custom RTTTL tone  
> ```

### Configurable hardware button wake-up
A new switch configures whether hardware button presses wake the panel.  
Access this option via **Settings** > **Devices & services** > **ESPHome** in Home Assistant.  

**Related Issues:**  
- #2194  

### Automatic TFT updates
Automatic TFT updates now trigger when an outdated version is detected, minimizing manual intervention.  

**Related Issues:**  
- #2227  

### Versioning engine updated
All components (Blueprint, ESPHome, and TFT) now enforce patch-level version consistency, ensuring reliability.  

### Panel display control via light entity
Added a light entity for controlling the display’s brightness, waking it up, or putting it to sleep.  
Remove any existing custom YAML configuration for display control.  

**Related Issues:**  
- #2091  

### Updated CLIMATE_MODE_AUTO icon
The Climate page's CLIMATE_MODE_AUTO icon changed from `mdi:calendar-sync` to `mdi:refresh-auto` for clarity.  

**Related Issues:**  
- #2243  

### References updated from `service` to `action`
Revised API to replace `service` with `action`, ensuring compatibility with Home Assistant and ESPHome standards.  

### Streamlined logging
Logging reduced to critical info, improving readability. This change may impact troubleshooting processes.  

> [!WARNING]  
> Adjust log levels if more detailed information is needed for debugging.  

### Device page clean-up
The device page was refined for better usability and clarity. The panel now integrates more seamlessly  
into automation workflows.
