# Performance Settings for NSPanel Project

This document provides an overview of the performance settings available in the NSPanel project.
Proper tuning of these settings can enhance the responsiveness of the system while avoiding issues like WLAN overload or buffer overflow in the Nextion display.
Below, we'll discuss the two primary performance settings: one on the blueprint side and another on the ESPHome side.

## 1. Blueprint Performance Setting: Command Delay to Prevent Overload

On the blueprint side, the performance setting is used to define a delay before each service call is sent to the display.
This delay helps prevent consecutive calls from overloading both the WLAN and the NSPanel.

### Where to Find It
- **Location:** This setting is found in the automation created with the Blueprint to control your panel.
- **Advanced Settings:** Scroll down to the "Advanced Settings" section of the configuration list.
- **Name:** The setting is named **"Command Delay to Prevent Overload"**.

### Input Details
- **Name:** Command Delay to Prevent Overload
- **Description:** Sets the time delay between sequential commands sent to the Nextion display.
    This delay prevents overload and synchronization issues, which could cause system instability.
    Increasing the delay improves stability but may slow down page rendering. Adjust carefully to balance stability and responsiveness.
- **Default Value:** 5 milliseconds
- **Selector Settings:**
  - **Range:** Minimum of 0 milliseconds, maximum of 250 milliseconds.
  - **Step Size:** 5 milliseconds per step.
  - **Unit of Measurement:** Milliseconds
  - **Mode:** Box

Adjusting this delay can help manage the network load and ensure that the commands are spaced out properly,
allowing the NSPanel and WLAN to process them without being overwhelmed.

## 2. ESPHome Performance Setting: Display Delay

On the ESPHome side, the performance setting involves configuring a delay when sending commands to the Nextion display.
This delay is critical in preventing the "Buffer overload" issue that can occur on the Nextion display.

### Where to Find It
- **Location:** This setting can be found on the ESPHome device's page under `Settings > Devices & Services > ESPHome`.
- **Configuration Group:** Look for the setting under the "Configuration" group.
- **Name:** The setting is named **"Display delay"**.

Note that this setting may be hidden or disabled in some systems. You may need to enable it before you can adjust its value.

### Purpose
The **Display Delay** setting prevents buffer overload on the Nextion display, which occurs when too many commands are received and cannot be processed in time.
If the buffer overloads, the Nextion queue will fall out of sync, leading to a device restart.
Each time this restart occurs, the delay will automatically increase one step in the delay interval (measured in milliseconds).

## Combining Delays: Impact on Responsiveness
The two delay settings (Blueprint and ESPHome) are combined, which can lead to a slower response time on the panel.
You can reduce these intervals to improve the panel's responsiveness.
However, it's important to note that reducing the **Display Delay** on the ESPHome side too much can lead to buffer overflows, causing instability.

### Recommendations
- **Fine-Tune the Blueprint Delay** to manage WLAN and command pacing effectively.
- **Adjust ESPHome Display Delay Carefully**: Lowering it too much can lead to buffer issues.
    Start with a conservative value and decrease it slowly while monitoring performance.

Maintaining a balance between the two settings is essential to ensure a responsive and stable NSPanel experience.
