# v4.3 - TItle to be defined

## General
*To be updated.*

Hello everyone!
We're excited to introduce enhancements in this update, focusing on improving user interaction and expanding customization options.
This release features an intuitive TFT upload process, enhanced Alarm Control Panels & Thermostats functionality, and new personalization options.

We're committed to making NSPanel firmware more user-friendly.
This release marks significant progress, including a streamlined TFT upload process and steps towards adopting `esp-idf` as the default framework.
Our documentation has been revamped for clarity and ease of use.
Stay tuned for more updates!

[Learn more about our efforts](https://github.com/Blackymas/NSPanel_HA_Blueprint/discussions/1602).

## ESP-IDF Framework Transition
With this release, we've officially transitioned to the **ESP-IDF** framework.
This move is part of our ongoing efforts to enhance the memory capacity and expand the features available on the ESP, facilitating broader customization and new functionalities.

For users updating to this version:
- **Flashing Required**: To adopt the ESP-IDF framework, flashing your device using a serial cable is necessary. This step mirrors the initial custom firmware setup process.
- **Arduino Framework Still Available**: For those who prefer the `arduino` framework or require Over-The-Air (OTA) updates, it remains an option.
Detailed guidance on how to choose your framework is provided in our [customization documentation](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/customization.md).

This transition is a significant milestone for us, promising a robust platform for our community.
We're here to help with any questions or assistance needed during this change.
For more details and support, visit our [community discussion](https://github.com/Blackymas/NSPanel_HA_Blueprint/discussions/1756).

## Updating
Please review your settings post-update to ensure compatibility.
Refer to the update procedures [here](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/howto.md#update-blueprint).

## Breaking Changes and Guidance
With this release, we're implementing several important changes.
While we strive to improve the panel, we understand that changes can affect your setups.
Here's a detailed overview and guidance for a smooth transition:

1. **Transition to ESP-IDF Framework**: This release marks the official switch to the ESP-IDF framework, enhancing performance and allowing for more complex features. 
   - **What to Do**: You'll need to flash your device with the new firmware using a serial connection.
   Detailed instructions are available in our [flashing guide](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/flashing.md).
   - **Support for Arduino Framework**: If you're not ready to make the switch or prefer the Arduino framework, it's still supported for OTA updates.
   See our [framework customization documentation](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/customization.md#framework) for details on how to select your preferred framework.

2. **Several Services Changed**: In our pursuit to enhance integration capabilities and future-proof our services, we've undertaken a comprehensive restructuring of our API.
This change is aimed at improving functionality and compatibility but may require adjustments to your current automations.
   - **What to Do**: We strongly encourage you to review our updated [API documentation](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/api.md).
   This resource has been meticulously updated to assist you in updating your automation scripts accordingly.
   Pay special attention to the examples section, which offers valuable insights and practical guidance for adapting your existing setups seamlessly.

3. **15s Hardware Button Press No Longer Restarts the Device**: This feature was removed to repurpose the hardware button for more versatile uses.
   - **What to Do**: If you relied on this feature, see our [customization guide](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/customization.md#restart-with-15s-button-press) for alternatives.
   Additionally, the reset pin remains an option for manual resets.

4. **Relay Fallback Switches Removed**: These switches were deprecated and have now been removed to streamline the firmware and reduce memory usage.
   - **What to Do**: For users who utilized customizations to expose these switches, refer to our updated customization guide.
   Alternatively, use the `esphome.xxxxx_init_hardware` service for a similar functionality without the memory overhead.

We appreciate your understanding and patience during this transition.
Our goal is to ensure NSPanel continues to evolve in a way that enhances your experience and meets future needs.
Our community and support channels are open for any questions or assistance you may require.

## Overview of noteworthy changes
1. Transition to ESP-IDF as Default Framework
2. Performance improvements
3. New API documentation
4. Selectable font size for screensaver time display
5. Hardware buttons bars visible on all pages

## Details of noteworthy changes
### 1. Transition to ESP-IDF as Default Framework
We've transitioned to ESP-IDF, enhancing our platform's performance and capabilities.
This change promises new possibilities for your projects.
Those continuing with the Arduino framework can find instructions for setting framework preferences.

For more information, visit our [discussion](https://github.com/Blackymas/NSPanel_HA_Blueprint/discussions/1756).

### 2. Performance improvements
*Details to be added.*

### 3. New API documentation
*Details to be added.*

### 4. Selectable font size for screensaver time display
*Details to be added.*

### 5. The hardware buttons bars visible in all pages
Bars indicating statuses of entities controlled by hardware buttons are now visible on all pages, including screensaver.
Color customization for these bars is also available.

## Support
For support or more information about this update,
visit our [GitHub repository](https://github.com/Blackymas/NSPanel_HA_Blueprint)
or our [online documentation](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/README.md).

## What's Next?
Discover our upcoming projects in our [Milestones](https://github.com/Blackymas/NSPanel_HA_Blueprint/milestones?direction=asc&sort=title&state=open).

## Special Thanks
*Details to be added.*

## Previous releases
- [v4.2.6 - Enhancing Stability and User Experience](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2.6)
- [v4.2.5 - Celebrating 1000 Stars with Enhanced Functionality and UI Improvements](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2.5)
- [v4.2.4 - Critical bug fixes](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2.4)
- [v4.2.3 - Bug fixes and minor enhancements](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2.3)
- [v4.2.2 - Bug fixes and minor enhancements](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2.2)
- [v4.2.1 - Bug fixes](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2.1)
- [v4.2 - Multi-Alarm Control, Dual Thermostat Functionality, and More](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2)
- [v4.1.4 - Support to Home Assistant 2023.12.0](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.1.4)
- [v4.1.3 - Bug fixes](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.1.3)
- [v4.1.2 - Bug fixes and minor enhancements](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.1.2)
- [v4.1.1 - UI Enhancements and Reintroduction of `play_rtttl` Service](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.1.1)
- [v4.1 - Easier TFT transfer](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.1)
- [v4.0.2 - Bug fixes](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.0.2)
- [v4.0.1 - Bug fixes](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.0.1)
- [v4.0 - Alarm and Media player pages, Climate add-ons and a more robust panel](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.0)
- [v3.4.1 - Patch for issues when compiling with ESPHome 2023.7.0](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v3.4.1)
- [v3.4 - New climate page and some bug fixes](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v3.4)
- [v3.3 - New improvements and some issues fixed](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v.3.3)
- [v3.2.2 - fixed some bugs performance improvement](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v3.2.2)
- [v3.2.1 - New features and some fixes](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v3.2.1)
- [v3.2 - New features and custom configurations](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v.3.2)
- [v3.1.0 - New features and US Version](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v.3.1.0)
- [v3.0.0 - major update with many features and improvements](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v.3.0.0)
- [v2.2.0 - 25 new languages added](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v.2.2.0)
- [v2.1.0 - New Domains, Buttons and Button Page Label](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v2.1.0)
- [v2.0.2](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v2.0.2)
- [v2.0.1 - Bug Fixes](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v2.0.1)
- [v2.0.0](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v2.0.0)
- [v1.0.1 Blueprint](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/latest)
