# API
This document provides details on custom services designed for integration with Home Assistant, including their usage, parameters, and examples.

## Service Documentation
### Command Service
Sends a custom command directly to the display, enabling direct interaction and dynamic content updates.

**Usage:**
This service is particularly useful for advanced customizations and direct display manipulations, such as showing messages, updating statuses, or any other display-centric commands.

**Parameters:**
- `cmd` (string): The command string to be sent to the display. Please refer to [The Nextion Instruction Set](https://nextion.tech/instruction-set/) for a comprehensive list of commands supported.

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_command
data:
  cmd: "page home"  # Go to page "Home"
```

> [!NOTE]
> Replace `<your_panel_name>` with your specific panel name as configured in Home Assistant to ensure correct service execution.
>
> Ensure the command string (`cmd`) is properly formatted according to your display's command processing capabilities.

### Component Color Service
Changes the foreground color of a specified component on the display, enabling dynamic color updates for user interface customization.

**Usage:**
This service is ideal for creating visually dynamic interfaces, allowing elements to change color based on conditions, events, or user actions, such as indicating status changes or highlighting specific UI components.

**Parameters:**
- `id` (string): Identifier of the component whose color will be updated. It is essential that this matches the component's ID in your display layout to ensure the correct element is targeted.
- `color` (int[]): The new color for the component, specified as an RGB array (e.g., `[255, 0, 0]` for red).

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_component_color
data:
  id: "home.time"
  color: [255, 0, 0]  # Changes the component's color to red
```
> [!NOTE]
> Replace `<your_panel_name>` with your specific panel name as configured in Home Assistant to ensure correct service execution.
>
> Ensure the `id` and color parameters accurately target and define the new color for the component.

### Component Hide Service
Hides a specified component on the display, allowing for dynamic interface changes.

**Usage:**
This service is ideal for creating interactive user interfaces that adapt by hiding certain elements based on user actions, conditions, or events.

**Parameters:**
- `id` (string): Identifier of the component to be hidden. It is crucial that this matches the component's ID in your display layout to ensure the correct element is hidden.

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_component_hide
data:
  id: "date"  # Hides the date display on Home page
```
> [!NOTE]
> Replace <your_panel_name> with your specific panel name as configured in Home Assistant to ensure correct service execution.
>
> Ensure the id matches the component on your display you wish to hide.

> [!IMPORTANT]
> This command only works when the page is visible and cannot contain the page id in the component id.
> 
> If the component being hidden is not part of the current page, the command will fail and an error message will be logged.

### Component Show Service
Makes a specified component visible on the display again, allowing for dynamic interface reversals.

**Usage:**
This service is essential for creating interactive user interfaces that can show elements previously hidden, based on user actions, conditions, or events, thereby restoring elements to the user interface as needed.

**Parameters:**
- `id` (string): Identifier of the component to be shown. It's crucial that this matches the component's ID in your display layout to ensure the correct element is made visible.

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_component_show
data:
  id: "date"  # Shows the date display on the Home page if it was previously hidden
```
> [!NOTE]
> Replace `<your_panel_name>` with your specific panel name as configured in Home Assistant to ensure correct service execution.
>
> Ensure the `id` precisely matches the component on your display you wish to make visible again.

### Component Text Service
Updates the text of a specified component on the display, enabling dynamic text content updates.

**Usage:**
Ideal for user interfaces that require real-time text updates, such as status messages, labels, or any text-based information display.

**Parameters:**
- `id` (string): Identifier of the component whose text will be updated. Ensure this matches the component's ID in your display layout.
- `text` (string): The new text content to display. This can include static text or dynamic information passed at runtime.

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_component_text
data:
  id: "home.time"
  text: "12:34"
```
> [!NOTE]
> Replace `<your_panel_name>` with your specific panel name as configured in Home Assistant to ensure correct service execution.
>
> Make sure the `id` corresponds to the correct component on your display for the text update to work as intended.

### Component Value Service
Updates the value of a specified component on the display, enabling dynamic value updates.

**Usage:**
Ideal for interfaces requiring real-time updates of numerical values, such as counters, temperature readings, or any numeric indicators.

**Parameters:**
- `id` (string): Identifier of the component whose value will be updated. It's crucial this matches the component's ID in your display layout accurately.
- `val` (int): The new integer value to be set for the component. This can represent various data types, depending on the component's purpose (e.g., temperature, humidity levels).

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_component_val
data:
  id: "cover.coverslider"
  val: 25
```
> [!NOTE]
> Replace `<your_panel_name>` with your specific panel name as configured in Home Assistant to ensure correct service execution.
>
> Ensure the `id` accurately matches the component on your display to successfully update its value.

### Icon Service
Updates a chip or custom button's icon, color, and visibility within Home Assistant.

**Usage:**
This service is ideal for dynamically updating icons on your Panel, allowing for a customizable and interactive user interface.

**Parameters:**
- `id` (string): Identifier of the chip or button component. Refer to "[Screen components](#screen-components)" for more details.
- `icon` (string): Icon codepoint from [HASwitchPlate Material Design Icons](https://htmlpreview.github.io/?https://github.com/jobr99/Generate-HASP-Fonts/blob/master/cheatsheet.html). Example: "/uE6E8" for `mdi:lightbulb-on-outline`.
- `icon_color` (int[]): RGB color array for the icon. Example: `[0, 255, 0]` for green.
- `visible` (bool): Flag indicating whether the icon should be visible (`true`) or hidden (`false`).

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_icon
data:
  id: "home.chip03"
  icon: "/uE6E8"           # Example for mdi:lightbulb-on-outline
  icon_color: [0, 255, 0]  # Green
  visible: true
```
> [!NOTE]
> Ensure the placeholder `<your_panel_name>` is replaced with the specific panel name you will need to reference in your Home Assistant configuration.

### Initialization Service: `init_global`
Transfers global settings from the blueprint to ESPHome,
ensuring that ESPHome is configured with the necessary parameters for operation according to the blueprint specifications.

**Usage:**
This service is crucial during the initialization phase or when global settings need to be updated to reflect changes in the blueprint.
It configures ESPHome with settings that affect overall functionality and user interface aspects.

**Parameters:**
- `blueprint_version` (string): Specifies the version of the blueprint being used.
- `embedded_climate` (bool): Indicates whether climate control is embedded in the panel.
- `embedded_climate_friendly_name` (string): Provides a friendly name for the embedded climate control.
- `embedded_indoor_temperature` (bool): Determines if indoor temperature display is enabled.
- `mui_please_confirm` (string): Localized (language based) message used for asking for confirmation in the UI.
- `mui_unavailable` (string): Localized (language based) message used for  indicating unavailability in the UI.
- `screensaver_time` (bool): Enables or disables the screensaver time display.
- `screensaver_time_color` (int[]): Specifies the RGB color array for the screensaver time display.

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_global_settings
data:
  blueprint_version: "4.2.5"
  embedded_climate: true
  embedded_climate_friendly_name: "Home Climate"
  embedded_indoor_temperature: true
  mui_please_confirm: "Confirme, por favor."
  mui_unavailable: "Indisponível"
  screensaver_time: true
  screensaver_time_color: [165, 42, 42]  # Reddish-brown
```
> [!NOTE]
> Replace `<your_panel_name>` with the specific name of your panel configured in Home Assistant.
>
> This service should be called to update ESPHome with the latest global settings as specified in your blueprint.

### Initialization Service: `init_relays`
Configures relay settings in ESPHome according to the specifications provided in the blueprint,
ensuring each relay operates with the correct parameters for control, appearance, and fallback behavior.

**Usage:**
This service is essential for initializing or updating relay configurations to reflect changes in the blueprint.
It tailors ESPHome's relay operations for specific use cases, including local control capabilities, iconography, color indications, and fallback states.

**Parameters:**
- `relay1_local_control` (bool): Enables or disables local control for Relay 1.
- `relay1_icon` (string): Specifies the icon for Relay 1.
- `relay1_icon_color` (int): Sets the RGB565 color for Relay 1's icon.
- `relay1_fallback` (bool): Determines the fallback state for Relay 1 in case of communication loss.
- `relay2_local_control` (bool): Enables or disables local control for Relay 2.
- `relay2_icon` (string): Specifies the icon for Relay 2.
- `relay2_icon_color` (int): Sets the RGB565 color for Relay 2's icon.
- `relay2_fallback` (bool): Determines the fallback state for Relay 2 in case of communication loss.

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_init_relays
data:
  relay1_local_control: true
  relay1_icon: "lightbulb"
  relay1_icon_color: 16711680  # Red
  relay1_fallback: false
  relay2_local_control: true
  relay2_icon: "power"
  relay2_icon_color: 65280  # Green
  relay2_fallback: true
```
> [!NOTE]
> Replace `<your_panel_name>` with the specific name of your panel configured in Home Assistant.
> This service initializes relay settings based on the provided parameters, customizing relay functionality and presentation as defined in the blueprint.

### Notification Clear Service
Removes any displayed notification from the screen, allowing the display to return to its normal state or view.

**Usage:**
This service is essential after displaying notifications or alerts.
It ensures the user interface remains clean and uncluttered by clearing messages once they are no longer needed or have been acknowledged.

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_notification_clear
```
> [!NOTE]
> Replace `<your_panel_name>` with the specific name of your panel configured in Home Assistant to ensure the service executes correctly.
This simple action clears the current notification from the display, maintaining a tidy interface.

### Notification Show Service
Displays a notification message on the screen, enabling dynamic presentation of information or alerts.

**Usage:**
Designed for scenarios requiring immediate feedback or notification on the display,
this service is suitable for showing alerts, informational messages, or updates directly on the screen interface.

**Parameters:**
- `label` (string): A brief title or label for the notification, typically displayed in a prominent, bold format.
- `message` (string): The detailed message or content of the notification, providing the main information or alert to the user.
The system will automatically wrap text to fit the display unless `\r` is used to insert manual line breaks. When `\r` is present, the system respects only the line breaks provided by the user, enhancing message formatting control.

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_notification_show
data:
  label: "Security Alert"
  message: "Front door opened at 10:30 PM\rPlease check the entrance."
```
> [!NOTE]
> Replace `<your_panel_name>` with the specific name of your panel configured in Home Assistant.
> The action ensures the service executes correctly, displaying the notification with the specified `label` and `message`.
>
> Utilize `\r` within the message for custom line breaks, offering precise formatting control.

### RTTTL Play Service
Plays melodies encoded in the RTTTL format, enabling the integration of audio feedback or alerts with simple text-based melody strings.

**Usage:**
This service is perfect for projects requiring audio signals, such as notifications, alerts, or simple melodies, by interpreting RTTTL (Ring Tone Text Transfer Language) strings.
RTTTL is a compact format for storing melody sequences in a text-based format, making it ideal for simple audio devices like buzzers.

**Parameters:**
- `tone` (string): The RTTTL string representing the melody to be played.
This string must conform to the RTTTL format, which includes the melody's name, default settings, and a sequence of notes. 

**Example Tones:**
For example tones and further inspiration, you can visit examples of RTTTL songs [here](https://codebender.cc/sketch:109888#RTTTL%20Songs.ino).

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_rtttl_play
data:
  tone: "d=4,o=5,b=140:c,e,g,8p,c6,e6,g6,8p,c7,p"
```
> [!NOTE]
> Replace `<your_panel_name>` with your specific panel name as configured in Home Assistant to ensure correct service execution.
>
> Ensure the `tone` parameter contains a valid RTTTL string to successfully play the melody.

### Value Service
Updates an entity to display specific values, allowing for dynamic updates of icons, names, and value colors within Home Assistant.

**Usage:**
This service is intended for entities that need to display information dynamically, such as sensor readings or state values, with customized icons, names, and color coding for both icon and value.

**Parameters:**
- `id` (string): Identifier of the entity being updated. For details on entity identifiers, refer to "[Screen components](#screen-components)".
- `icon` (string): Icon codepoint from [HASwitchPlate Material Design Icons](https://htmlpreview.github.io/?https://github.com/jobr99/Generate-HASP-Fonts/blob/master/cheatsheet.html). Indicates the icon displayed next to the value.
- `icon_color` (int[]): RGB color array for the icon, allowing for custom icon colors.
- `name` (string): The display name for the entity, useful for labeling the value displayed.
- `value` (string): The actual value to be displayed next to the icon and name.
- `value_color` (int[]): RGB color array for the value text, enabling custom coloring of the displayed value.

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_value
data:
  id: "sensor.temperature"
  icon: "/uE6E8"           # Example for mdi:thermometer
  icon_color: [255, 0, 0]  # Red
  name: "Temperature"
  value: "75°F"
  value_color: [255, 255, 0] # Yellow
```
> [!NOTE]
> Replace `<your_panel_name>` with your specific panel name as configured in Home Assistant to ensure correct service execution.

### Wake Up Service
Activates the display from a screensaver or low-power state, enabling dynamic interface adjustments based on user interactions or automated triggers.

**Usage:**
Ideal for scenarios requiring the display to become active upon certain events, such as motion detection, thereby conserving energy while ensuring the display is available when needed.

**Parameters:**
- `reset_timer` (bool): Determines whether to reset the sleep and dimming timers upon waking up the display.
Setting this to `true` ensures the display remains active during user presence, while `false` retains the existing timer durations.

**Home Assistant Example:**
```yaml
service: esphome.<your_panel_name>_wake_up
data:
  reset_timer: true
```
> [!NOTE]
> Replace `<your_panel_name>` with the specific name of your panel configured in Home Assistant.
> This action ensures the service is executed correctly, waking the display and optionally resetting timers based on the reset_timer parameter.

**Practical Use Case: Motion Sensor Activation:**
This service can be seamlessly integrated with a motion sensor to wake the display when motion is detected, making it instantly usable.
Additionally, if the display is already awake, calling this service with `reset_timer: true` can reset the sleep timer,
keeping the display active as long as there is movement and allowing it to sleep normally once no motion is detected.

The example bellow integrates the `wake_up` service with a motion sensor to ensure the display wakes or remains awake during periods of activity, reverting to sleep mode after inactivity.

```yaml
automation:
  - alias: "Wake Display on Motion"
    trigger:
      - platform: state
        entity_id: binary_sensor.motion_sensor_123
        to: 'on'
    action:
      - service: esphome.<your_panel_name>_wake_up
        data:
          reset_timer: true
    mode: restart
```
> [!NOTE]
> Adjust `<your_panel_name>` and `binary_sensor.motion_sensor_123` to your actual panel and sensor entity IDs.
> This setup ensures the display is responsive to environmental conditions, enhancing user interaction while managing energy consumption efficiently.

## Screen components

### Page Home - Chips
![Image](pics/Nextion_Components_Home_Chips_EU.png)
![Image](pics/Nextion_Components_Home_Chips_US.png)

#### User-defined Chips
- **Description**: Chips are icons that are shown in specific situations or hidden. Their behaviour is controlled by the blueprint.
- **Type**: Icon only with no touch commands.
- **Availability**: Global (available even when page is not visible).
- **Ids**: `home.chip01` to `home.chip07`.

#### Relays Chips
- **Description**: Icons representing each of the relays states.
- **Type**: Icon only with no touch commands.
- **Availability**: Global (available even when page is not visible).
- **Ids**: `home.chip_relay1` and `home.chip_relay2`.

#### Climate Chip
- **Description**: Icon representing the state of the main climate entity.
- **Type**: Icon only with no touch commands.
- **Availability**: Global (available even when page is not visible).
- **Ids**: `home.chip_relay1` and `home.chip_relay2`.

### Page Home - Custom buttons
![Image](pics/Nextion_Components_Home_Custom_Buttons_EU.png)
![Image](pics/Nextion_Components_Home_Custom_Buttons_US.png)
