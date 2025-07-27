# v4.4 - Dynamic QR Codes, Improved Usability, and More

## General
Version 4.4 focuses on enhancing the usability and functionality of your NSPanel. The device page has been
refined for a cleaner, more user-friendly experience, now allowing you to control the panel as a light.

In addition to improved performance, this release introduces dynamic QR codes, automatic TFT updates, and
new features like buzzer volume control and configurable wake-up settings, making your panel more versatile.

## Dropping Arduino Framework Support

### Arduino framework support discontinued
Starting with version 4.4, NSPanel HA Blueprint will exclusively use the ESP-IDF framework, dropping support for the Arduino framework.
This change aligns with ESPHome's direction and provides several benefits while requiring a configuration update for existing users.

#### Background
The Arduino framework was previously supported as an alternative to ESP-IDF,
but maintaining compatibility with both frameworks has become increasingly challenging.
ESP-IDF has matured significantly and is now the recommended framework for ESP32 development in ESPHome.

**It has been quite some time since our default framework was changed to ESP-IDF, and all users have been recommended to migrate.**
This release formalizes that recommendation by removing Arduino framework support entirely.

#### Benefits of ESP-IDF Only
- **Better Memory Management:** ESP-IDF provides more efficient memory allocation and usage patterns
- **Enhanced Performance:** Native ESP-IDF components offer better performance and lower overhead
- **Improved Stability:** ESP-IDF's mature codebase provides better stability for complex applications
- **Future-Proof:** Aligns with ESPHome's long-term direction and receives priority support
- **Reduced Complexity:** Eliminates framework-specific code paths and testing requirements

#### Migration Required
If your current configuration uses the Arduino framework, simply remove the framework specification:
   ```yaml
    # OLD Arduino configuration - REMOVE THIS
    esp32:
      framework:
        type: arduino

    # That's it! The remote package handles the ESP-IDF configuration automatically
   ```

#### Critical Migration Steps
> [!IMPORTANT]
> When migrating from Arduino to ESP-IDF framework, proper flashing is essential for success.

**Recommended flashing method:**
1. **Serial/USB flashing (preferred):** Use a USB-to-serial adapter to flash directly via the programming pins.
   This method properly rebuilds partitions and ensures clean migration.

2. **OTA flashing (requires special attention):** If serial flashing is not possible:
   - **Flash twice in succession** to increase chances of success
   - The first flash may succeed but the device might boot from the wrong partition containing old Arduino firmware
   - The second flash ensures both partitions contain the new ESP-IDF firmware, eliminating boot issues
   - Monitor device behavior after each flash attempt

**Why multiple flashes may be needed:**
When migrating from Arduino to ESP-IDF via OTA,
the bootloader with Arduino-type partition table may boot from the partition where the older Arduino firmware is still installed.
Flashing twice increases the chances that both partitions will contain the new ESP-IDF firmware,
so booting from either partition will work correctly.

#### Arduino Framework Usage (Unsupported)
While it may be possible to continue using the Arduino framework with minor configuration adjustments, **this is not supported**.
Users choosing to remain on Arduino framework will be on their own for troubleshooting, compatibility issues, and future updates.
We strongly recommend migrating to ESP-IDF for the best experience and continued support.

#### What This Means for Users
- **New Installations:** Will automatically use ESP-IDF with no additional configuration needed
- **Existing Arduino Users:** Must remove the Arduino framework reference from their configuration and reflash their device
- **No Functional Changes:** All features remain available; only the underlying framework changes
- **Better Performance:** May experience improved responsiveness and stability

#### Compatibility Notes
- All existing features and functionalities remain unchanged
- Custom components and automations continue to work as before
- The change is transparent to Home Assistant integration
- Pre-built firmware images will use ESP-IDF exclusively

> [!WARNING]
> This change requires a full reflash of your device.
> Backup your configuration before updating and be prepared to reconfigure your device if the migration encounters issues.
> If possible, use serial/USB flashing for the most reliable migration experience.

## Breaking Changes and Guidance

### Home Assistant v2025.7.0 and ESPHome v2025.8.0 are required
Refer to our  
[Version Compatibility Matrix](docs/version_compatibility.md).

### Versioning changes require updating all three components
Update all components (Blueprint, ESPHome, and TFT) together for compatibility and consistency.

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

2. **Sensors `blueprint_status` and `device_name` removed**
   Device's and boot info is now transferred via events.

3. **Notification unread switch replaced**
   The "**Notification unread**" switch is now a binary sensor.

4. **Baud rate selectors removed**
   Communication now detects the Nextion display's current baud rate
   and changes it to 921,600bps (default target rate).
   Therefore the baud rate selectors have been removed, simplifying configuration.
   A substitution named `BAUD_RATE` can be used by advanced users to change the target baud rate.

5. **New "Display Command Spacing" control**
   A new control called **Display Command Spacing** has been introduced to manage the delay between commands sent to the Nextion display.
   This helps avoid buffer overflows, which can lead to a device restart if not managed properly.
   You can find more details in the [Performance Settings for NSPanel Project](docs/performance.md#2-esphome-performance-setting-display-command-spacing).

### Customizations
Updated scripts require adjustments to these customizations:  
- [Sleep & Wake-up buttons](docs/customization.md#sleep--wake-up-buttons)  
- [Set display as a light (deprecated)](docs/customization.md#set-display-as-a-light)

### Dropped support to *Wall Display*
This was an experimental feature, but the available memory on the NSPanel can't support all the desired features.

## Noteworthy Changes

### Core and Standard Functionality Split
In this release, we are introducing a new split between "Core" and "Standard" functionalities.  
This change is aimed at advanced users who wish to customize their panel by selectively removing  
certain functionalities to free up resources for other uses.

> [!IMPORTANT]
> Unless you want to remove some functionality, no changes are needed on your panel's yaml.

#### Background
Previously, we introduced the concept of `add-ons`, which allowed your panel to act as a Bluetooth proxy,  
local thermostat, or cover control, extending its capabilities beyond the core functionality.  
Now, we're taking a step further by splitting the core functionality into "Core" and "Standard" categories:  
- **Core Functionality:** Essential features required for any panel installation.  
- **Standard Functionality:** Common features included by default in regular installations, but optional for advanced users.

#### Benefits of the Split
1. **Resource Optimization:**  
   Advanced users can remove unused functionalities, freeing up memory for custom uses unrelated to this project.  
   - Example: If you're not using hardware relays, you can remove the package for Hardware Relays to free up resources.  
   - Similarly, if cover control is not used, you can exclude the related code.

2. **Improved Code Management:**  
   Each feature is now encapsulated in a dedicated package, making it easier to locate and customize specific functionality.  
   Developers and troubleshooters can focus on isolated areas of the code without interfering with unrelated parts.

3. **Future Accessibility:**  
   While currently targeted at advanced users, this split lays the groundwork for making functionality selection  
   more accessible for all users, including entry-level users, in future releases.

#### What's Next
While this change is currently focused on advanced users, we are working towards making it easier for all users,
allowing everyone to select what functionalities they want during installation in a more intuitive way.

#### How to Get More Information
For detailed guidance, visit our Installation documentation in the  
"[Advanced Configuration for ESPHome and Home Assistant Experts](docs/install.md#advanced-configuration-for-esphome-and-home-assistant-experts)" section.

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
Added a light entity for controlling the display's brightness, waking it up, or putting it to sleep.  
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