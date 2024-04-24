# Customization

Table of contents:
- [Description](#description)
- [Instructions](#instructions)
- [Memory Management](#memory-management)
- [Removing Standard Settings](#removing-standard-settings)
- [Examples](#examples)
  - [API encryption](#api-encryption)
  - [Custom OTA password](#custom-ota-password)
  - [Web server credentials](#web-server-credentials)
  - [Reboot when API fails](#reboot-when-api-fails)
  - [Manual IP](#manual-ip)
  - [Hidden Wi-Fi](#hidden-wi-fi)
  - [Connect to multiple networks](#connect-to-multiple-networks)
  - [SNTP (time) server](#sntp-time-server)
  - [Sensor for display awake vs sleeping](#sensor-for-display-awake-vs-sleeping)
  - [Deep sleep](#deep-sleep)
  - [Enforce time zone](#enforce-time-zone)
  - [Compiling ESPHome on lower powered machines](#compiling-esphome-on-lower-powered-machines)
  - [Sleep & Wake-up buttons](#sleep--wake-up-buttons)
  - [Set display as a light](#set-display-as-a-light)
  - [Scheduled actions](#scheduled-actions)
    - [Scheduled relay](#scheduled-relay)
    - [Scheduled climate](#scheduled-climate)
  - [Frameworks](#frameworks)
    - [Framework `arduino`](#framework-arduino)
    - [Framework `esp-idf`](#framework-esp-idf)
  - [Bluetooth proxy](#bluetooth-proxy)
  - [BLE tracker](#ble-tracker)
  - [Logger via UART](#logger-via-uart)
  - [Climate custom presets](#climate-custom-presets)
  - [Push button / Momentary switch](#push-button--momentary-switch)
  - [Expose relay fallback switch](#expose-relay-fallback-switch)
  - [Relay Interlocking](#relay-interlocking)
  - [Remove non-essential components](#remove-non-essential-components)

&nbsp;
&nbsp;
## Description
This project adds lots of functionalities to your NSPanel and we are constantly adding new features based on user's feedback.
However, you might have some specific case that are not included on the current implementation or is not a common case for other users.

You can take advantage of [ESPHome Configuration Types](https://esphome.io/guides/configuration-types.html) to add your custom functionality
or even to customize an existing functionality with minimum effort and this document intents to clarify how to use this and give some examples of customization.

Please feel free to add your own customation to this document by creating a PR in the `dev` branch.

***IMPORTANT:***
- *Use customization at your own risk. Custom/advanced systems won't be supported by this project's team.*
- *Please monitor the memory consumption when using customizations. Getting closer to the full memory can drive to errors in the system or prevent your system to support the future updates.*

&nbsp;
## Instructions
There's nothing particular for this project, so you can just use any of the [ESPHome Configuration Types](https://esphome.io/guides/configuration-types.html)
and only edit your local ESPHome yaml settings.

Most of the ESPHome components in this project contains an `Id`, which can be used together with the `!extend` key to add or replace existing code.

You should add your customizations at the end of your ESPHome yaml, as in the example bellow:

```yaml
substitutions:
  # Settings - Editable values
  device_name: "YOUR_NSPANEL_NAME"
  friendly_name: "Your panel's friendly name"
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  # Add-on configuration (if needed)
  ## Add-on climate
  # heater_relay: "1"  # Possible values: "1" or "2"

# Customization area
##### My customization - Start #####

# Encrypt the communication between ESPHome and Home Assistant
api:
  encryption:
    key: !secret api_encryption_key

# More detailed log (for troubleshooting only)
logger:
  level: VERBOSE

##### My customization - End #####

# Basic and optional configurations
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    refresh: 300s
    files:
      - nspanel_esphome.yaml # Basic package
      # Optional advanced and add-on configurations
      # - esphome/nspanel_esphome_advanced.yaml
      # - esphome/nspanel_esphome_addon_ble_tracker.yaml
      # - esphome/nspanel_esphome_addon_bluetooth_proxy.yaml
      # - esphome/nspanel_esphome_addon_climate_cool.yaml
      # - esphome/nspanel_esphome_addon_climate_heat.yaml
      # - esphome/nspanel_esphome_addon_climate_dual.yaml
```

## Memory Management
When adding new components or code to your ESP32, it's important to be mindful of memory usage.
Your device has limited memory, and every addition uses some of this precious resource.

### Understanding Memory Usage
After compiling your firmware, you'll see a summary showing how much memory your firmware needs.
Here's what it might look like:

```log
Successfully created esp32 image.
Linking .pioenvs/office-workstation-panel/firmware.elf
RAM:   [=         ]  10.5% (used 34484 bytes from 327680 bytes)
Flash: [=======   ]  67.5% (used 1239253 bytes from 1835008 bytes)
Building .pioenvs/office-workstation-panel/firmware.bin
Creating esp32 image...
Successfully created esp32 image.
```

- **Static Memory**: This is the memory required to load your firmware.
Running your firmware requires additional memory.
- **Dynamic Memory**: This is the memory allocated while your firmware is running.
ESPHome checks if your static memory usage exceeds your device's limits to prevent installation issues, but it doesn't check dynamic memory usage.
**Aim to keep static RAM usage below 20% and static Flash usage below 75%** to ensure there's enough room for dynamic operations.

### Risks of Exceeding Memory Limits
Exceeding memory limits can lead to issues:
- **During Compilation**: ESPHome might prevent firmware installation if static memory is too high.
- **During Runtime**: Exceeding dynamic memory can cause unexpected restarts.
- **During Startup**: If your device runs out of memory at startup, it may not load the firmware, resulting in a black screen and an unresponsive device.
The solution is to use a serial cable to reflash your device with a lighter firmware.

### Tips for Managing Memory
- Be cautious when adding memory-intensive components like `bluetooth_proxy`.
- Compile your firmware with the option to download it before installation.
This lets you check static memory usage without risking wireless installation issues.

## Removing Standard Settings
You can use customizations to remove certain default components or settings from this project.
This is useful for altering standard settings or freeing up memory for additional components.
Here's how you might remove some default settings:

```yaml
# Removes the `captive_portal` component
captive_portal: !remove

# Removes the OTA password
ota:
  password: !remove
```

> [!ATTENTION]
> Be aware of the implications before removing components or settings.
> Some of them are crucial for allowing your panel to interact correctly with the blueprint or for enabling ESPHome to install the firmware Over The Air.
> Incorrect removals could render your panel unusable, potentially requiring a reflash via a serial cable.

## Examples

### API encryption
> [!IMPORTANT]
> Changing the API encryption can break the connection to Home Assistant,
> requiring the device to be removed from integrations (**Settings** > **Devices & Services** > **ESPHome**) and then re-added.

This is highly recommended when you are transfer sensitive information between your panel and Home Assistant,
as when you use your panel to enter the PIN for an Alarm Control Panel.

```yaml
# Encrypt the communication between ESPHome and Home Assistant
api:
  encryption:
    key: !secret api_encryption_key
```

### Custom OTA password
By default, the Wi-Fi password will be used as your OTA password, but you can replace it.

First, you need to change the default password using this code.

```yaml
# change OTA password, remove after flashing
esphome:
  on_boot:
    - priority: 601.0
      then:
        - lambda: |-
            id(my_ota).set_auth_password("New password");
ota:
  password: !secret wifi_password
  id: my_ota
```

After flashing the device, you must remove the code above and replace it with the code below to start using this customization.

```yaml
# Use my global OTA password
ota:
  password: !secret ota_password
```

### Web server credentials
By default, the web server credentials are defined by this project using `admin` as `username` and your `Wi-Fi password` as `password`, but you can replace it using this customization:

```yaml
# Custom web server credentials
web_server:
  auth:
    username: !secret web_server_username
    password: !secret web_server_password
```

### Reboot when API fails
Reboot your panel if it loses it's connection to Home Assistant for more than a certain time (15 minutes in this example).

Sometimes the low level ESP functions could report that the ESP is connected to the network, when in fact it is not and only a full reboot fixes it.

To support long times without Wi-Fi, this is disabled by default in this project, but you can set a reasonable interval to restart, based on your network reliability.

```yaml
# Reboot if HA is not connected for 15 minutes
api:
  reboot_timeout: 15min
```

### Manual IP
Set IP address manually.

> [!ATTENTION]
> At least one DNS server is required to enable TFT transfer direcly from GitHub, otherwise use `nextion_update_url`.

```yaml
# Set IP address manually
wifi:
  networks:
    - id: !extend wifi_default
      manual_ip:
        static_ip: 192.168.0.123
        gateway: 192.168.0.1
        subnet: 255.255.255.0
        dns1: 1.1.1.1  # At least one DNS server is required to enable TFT transfer direcly from GitHub, otherwise use `nextion_update_url`.
        dns2: 8.8.8.8
```

### Hidden Wi-Fi
Connect to a hidden Wi-Fi network.

```yaml
# Connect to a hidden Wi-Fi network.
wifi:
  networks:
    - id: !extend wifi_default
      hidden: true
  fast_connect: true
```

### Connect to multiple networks
NSPanel will attempt to connect to the one with the highest signal strength or, if you set a priority, it will try to connect to the highest priority.
After failing it will connect to the second network.

```yaml
# Set dual network
wifi:
  networks:
    - id: !extend wifi_default
      priority: 10
    - ssid: !secret wifi_ssid_backup
      password: !secret wifi_password_backup
      priority: 0
```

### SNTP (time) server
ESPHome takes it's time from Home Assistant, however you can configure it to use a Network Time Server instead.

```yaml
# Use my own local network time server
time:
  - id: !extend time_provider
    platform: sntp
    servers:
      - !secret mysntpserver
      - europe.pool.ntp.org
      - 0.pool.ntp.org
```

### Sensor for display awake vs sleeping
Creates a binary sensor to indicate either when the display is showing some page (`on`) or sleeping (`off`).

```yaml
# Is display awake?
binary_sensor:
  - name: Display state
    id: display_state
    platform: template
    lambda: |-
      return (current_page->state != "screensaver");
```

You can easily invert the meaning to have a sensor for display sleeping:

```yaml
# Is display sleeping?
binary_sensor:
  - name: Display sleeping
    id: display_sleeping
    platform: template
    lambda: |-
      return (current_page->state == "screensaver");
```

### Deep sleep
In this example, the panel will deep sleep for 7 hours, starting at 23:00:00 every day, for its maximum energy saving.

During this time, nothing will be shown, the screen will be off and therefore no response to touch, and the panel will be disconnected from Wi-Fi,
but you can still wake-up the panel by pressing one of the hardware buttons (the left one in this example):

```yaml
# Define the wake-up button. Use pin 14 for left button or pin 27 for right button
deep_sleep:
  wakeup_pin:
    number: 14
    allow_other_uses: true
  wakeup_pin_mode: INVERT_WAKEUP

binary_sensor:
  - id: !extend left_button
    pin:
      allow_other_uses: true

time:
  - id: !extend time_provider
    on_time:
      - hours: 23
        minutes: 0
        seconds: 0
        then:
          - deep_sleep.enter:
              sleep_duration: 7h
```

You can find more ideas around this on [#955](https://github.com/Blackymas/NSPanel_HA_Blueprint/issues/955).

### Enforce time zone
Until v3.4 (including), the time was coming from Home Assistant with it's timezone, so the Blueprint was sending the info with no transformation, to the panel.
From v4.0, the time reference still coming from HA (or optionally from a time server), but is calculated in ESPHome, which will try to detect the timezone from the server.
From v4.3.3 or later, the time still calculated on ESPHome side, however, you can select the timezone on the Blueprint, making this customization obsolete.

If your system is not showing the time in the correct timezone, it's probabily ESPHome not succeeding on finding your time zone.
You can easily force a timezone by adding this to your ESPHome settings:

```yaml
time:
  - id: !extend time_provider
    timezone: "America/Cancun"
```

### Compiling ESPHome on lower powered machines
For systems with lower CPU or memory capabilities, like an RPi 3 or systems with less than 2GB of RAM, this could help preventing errors caused by lack of resources when compiling ESPHome firmware.

More datails on the [ESPHome docs](https://esphome.io/changelog/2022.11.0.html#running-esphome-on-lower-powered-machines).

```yaml
# Limit the amount of resources used for compiling
esphome:
  compile_process_limit: 1
```

### Sleep & Wake-up buttons
There are several ways to wake-up or put your panel to sleep, but in this example we tried a simple approach by adding two buttons (you can implement only one of those if you want):

```yaml
button:
  # Adds a button to put the panel to sleep
  - name: Sleep
    id: force_sleep
    platform: template
    icon: mdi:sleep
    on_press:
      then:
        - logger.log: Button Sleep pressed
        - lambda: |-
            goto_page->execute("screensaver");
  
  # Adds a button to wake-up the panel (similar to the existing service)
  - name: Wake-up
    id: force_wake_up
    platform: template
    icon: mdi:alarm
    on_press:
      then:
        - logger.log: Button Wake-up pressed
        - lambda: |-
            if (current_page->state == "screensaver") id(disp1).goto_page(id(wakeup_page_name).state.c_str());
            // timer_page->execute(); // enable this if you want page timeout to be reset
            timer_sleep->execute();
            timer_dim->execute();
```

### Set display as a light
You can set your display as a light in Home Assistant, so you can control the brightness and turn on/off just like any other light,
and even use this in your automation to control when your panel is on with the same automation you use for your lights:

```yaml
light:
  # Add the display as a light in Home Assistant
  - name: Display
    id: display_light
    icon: mdi:tablet-dashboard
    platform: monochromatic
    output: display_output
    default_transition_length: 0s
    on_turn_on:
      then:
        - lambda: |-
            ESP_LOGD("light.display_light", "Turn-on");
            if (current_page->state == "screensaver") disp1->goto_page(wakeup_page_name->state.c_str());
            timer_reset_all->execute();
    on_turn_off:
      then:
        - lambda: |-
            ESP_LOGD("light.display_light", "Turn-off");
            goto_page->execute("screensaver");

output:
  # Output required by `display_light` to send the commands to Nextion
  - id: display_output
    platform: template
    type: float
    write_action:
      - lambda: |-
          ESP_LOGV("output.display_output", "state: %f", state);
          uint8_t current_brightness = int(round(display_light->current_values.is_on() ? (display_light->current_values.get_brightness() * 100.0f) : 0.0));
          ESP_LOGV("output.display_output", "current_brightness: %i%%", current_brightness);
          set_brightness->execute(current_brightness);
    
script:
  # Updates the existing `page_changed` script to update the `display_light` status when a page changes
  - id: !extend page_changed
    then:
      - lambda: |-
          ESP_LOGD("script.page_changed(custom)", "page: %s", current_page->state.c_str());
          ESP_LOGV("script.page_changed(custom)", "is_on(): %s", display_light->current_values.is_on() ? "True" : "False");
          if (current_page->state == "screensaver" and display_light->current_values.is_on()) {
            auto call = display_light->turn_off();
            call.perform();
          } else if (current_page->state != "screensaver" and (not display_light->current_values.is_on())) {
            auto call = display_light->turn_on();
            call.perform();
          }

  # Updates the existing `set_brightness` script to update the `display_light` status when a new brightness level is set
  - id: !extend set_brightness
    then:
      - lambda: |-
          ESP_LOGD("script.set_brightness(custom)", "brightness: %.0f%%", brightness);
          uint8_t current_light_brightness = int(round(display_light->current_values.is_on() ? (display_light->current_values.get_brightness() * 100.0f) : 0.0));
          ESP_LOGV("script.set_brightness(custom)", "current_light_brightness: %i%%", current_light_brightness);
          if (brightness != current_light_brightness) {
            if (current_page->state != "screensaver" and brightness > 0) {
              auto call = display_light->turn_on();
              call.set_brightness(static_cast<float>(current_brightness->state) / 100.0f);
              call.perform();
            } else if (display_light->current_values.is_on()) {
              auto call = display_light->turn_off();
              call.set_brightness(0);
              call.perform();
            }
          }

```

### Scheduled actions
Although ESPHome doesn't have a Scheduler component, it is possible to use the timer to schedule actions and this is entirely managed in the device,
so it will work even if Home Assistant and/or the Wi-Fi are unavailable.

Following some examples:

#### Scheduled relay

```yaml
# Scheduled relay
time:
  - id: !extend time_provider
    on_time:
      - hours: 7
        minutes: 30
        seconds: 0
        then:
          - switch.turn_on: relay_1
      - hours: 12
        minutes: 15
        seconds: 0
        then:
          - switch.turn_off: relay_1
      - hours: 19
        minutes: 0
        seconds: 0
        then:
          - switch.turn_on: relay_1
      - hours: 23
        minutes: 30
        seconds: 0
        then:
          - switch.turn_off: relay_1
```

#### Scheduled climate
> [!NOTE]
> This requires add-on climate to be installed

```yaml
# Scheduled climate
time:
  - id: !extend time_provider
    on_time:
      - hours: 7
        minutes: 0
        seconds: 0
        then:
          - climate.control:
              id: thermostat_embedded
              mode: auto
              target_temperature: 22°C
      - hours: 19
        minutes: 0
        seconds: 0
        then:
          - climate.control:
              id: thermostat_embedded
              mode: auto
              target_temperature: 20°C
      - hours: 23
        minutes: 0
        seconds: 0
        then:
          - climate.control:
              id: thermostat_embedded
              mode: auto
              target_temperature: 18°C
```

### Frameworks
> [!IMPORTANT]
> When switching between frameworks, make sure to update the device with a serial cable as the partition table is different between the two frameworks
as [OTA Update Component](https://esphome.io/components/ota) updates will not change the partition table. While it will appear to work, the device will boot the old framework after a reset.

This project currently uses `esp-idf` as default framework.
You can overlap the settings with this customization.

> [!NOTE]
> For more info about frameworks, please visit [ESPHome docs](https://esphome.io/components/esp32).

`esp-idf` is maintained by EspressIF and is kept updated,
more boards are supported and the memory management is better, making it ideal if you wanna customize your panel to support memory consumption functionalities,
like `bluetooth_proxy` or [Improv](https://www.improv-wifi.com/). Consequently, this project uses `esp-idf` as the default framework since `v4.3`. 

However, the `arduino` protocol still very popular and, therefore, more components are available and the project allows to switch between the frameworks 
by adding the following lines in your panel's yaml file.

#### Framework `arduino`
```yaml
# Change framework to `arduino`
esp32:
  framework:
    type: arduino
```
#### Framework `esp-idf`
```yaml
# Change framework to `esp-idf`
# (should not be required)
esp32:
  framework:
    type: esp-idf
```

### Bluetooth Proxy
Please refer to the "[Add-on: Bluetooth Proxy](addon_bluetooth_proxy.md)" guide.

### BLE Tracker
Please refer to the "[Add-on: BLE Tracker Proxy](addon_ble_tracker.md)" guide.

### Logger via UART

By default, the logging via hardware UART is disable in this project.
You can enable it by setting the baud rate accordingly to your interface:

```yaml
# Enable hardware UART serial logging
logger:
  baud_rate: 115200
```

### Climate custom presets

```yaml
# Add custom presets to your climate (heat in this example)
climate:
  - id: !extend thermostat_embedded
    default_preset: "Home"
    preset:
      - name: "Off"
        default_target_temperature_low: ${temp_min} ${temp_units}
        mode: "off"
      - name: Home
        default_target_temperature_low: 21 ${temp_units}
        mode: "heat"
      - name: Away
        default_target_temperature_low: 16.5 ${temp_units}
        mode: "heat"
      - name: Sleep
        default_target_temperature_low: 17.5 ${temp_units}
        mode: "heat"
```

### Push button / Momentary switch
You can set the physical relays to be `on` only while the hardware buttons are pressed, and then back to `off` when the buttons are released:

```yaml
binary_sensor:
  # Left button custom action: Push button / Momentary switch - Relay 1
  - id: !extend left_button
    on_click:
      then:
    on_press:
      then:
        switch.turn_on: relay_1
    on_release:
        switch.turn_off: relay_1

  # Right button custom action: Push button / Momentary switch - Relay 2
  - id: !extend right_button
    on_click:
      then:
    on_press:
      then:
        switch.turn_on: relay_2
    on_release:
        switch.turn_off: relay_2
```

### Expose Relay Fallback Switch
You can configure a local fallback relay to integrate with Home Assistant.
This is particularly useful for devices like WiFi-connected lights.
For instance, you can program it to cut the power to a connected light under certain conditions, directly via a switch.

#### Use Case
One application, as utilized by @tikismoke and detailed in [#1349](https://github.com/Blackymas/NSPanel_HA_Blueprint/issues/1349), is in response to fluctuating energy prices.
When the energy price is high, an automation can change the fallback mode to cut off the relay.
This ensures that the bulb does not consume energy in standby mode. However, it will still function normally with `light.toggle` from the blueprint in all other cases.
Local control is reinstated when the power price returns to normal.
On the next switch activation, the relay turns `on`, powering up the bulb.
Subsequent activations will trigger `light.toggle` from the blueprint, as this functionality is already embedded in the ESPHome YAML code.

> [!NOTE]  
> In this scenario, the bulb must be set to turn `on` automatically when power is restored.

```yaml
# Expose relay local control switch to Home Assistant
switch:
  - name: Relay 1 Local
    platform: template
    id: relay1_local
    entity_category: config
    internal: false
    lambda: |-
      return (id(relay_settings) & nspanel_ha_blueprint::RelaySettings::Relay1_Local);
    turn_on_action:
      - lambda: nspanel_ha_blueprint::update_bitwise_setting(id(relay_settings), true, RelaySettings::Relay1_Local);
    on_turn_on:
      - logger.log: "Relay 1 Local turned On!"
    turn_off_action:
      - lambda: nspanel_ha_blueprint::update_bitwise_setting(id(relay_settings), false, RelaySettings::Relay1_Local);
    on_turn_off:
      - logger.log: "Relay 1 Local turned Off!"
  - name: Relay 2 Local
    platform: template
    id: relay2_local
    entity_category: config
    internal: false
    lambda: return (id(relay_settings) & nspanel_ha_blueprint::RelaySettings::Relay2_Local);
    turn_on_action:
      - lambda: nspanel_ha_blueprint::update_bitwise_setting(id(relay_settings), true, RelaySettings::Relay2_Local);
    on_turn_on:
      - logger.log: "Relay 2 Local turned On!"
    turn_off_action:
      - lambda: nspanel_ha_blueprint::update_bitwise_setting(id(relay_settings), false, RelaySettings::Relay2_Local);
    on_turn_off:
      - logger.log: "Relay 2 Local turned Off!"
```

### Relay Interlocking
This is using ESPHome capability to prevents the two relays to be active at the same time, which could be useful in some cases,
like to control a cover like discussed in [#965](https://github.com/Blackymas/NSPanel_HA_Blueprint/issues/965).

> [!ATTENTION]
> There are some considerations about using software interlocking on the [ESPHome GPIO Switch documentation](https://esphome.io/components/switch/gpio.html#interlocking).
Please read that carefully to understand what this is doing.

```yaml
switch:
  # Prevents the two relays to be on simultaneously
  - id: !extend relay_1
    interlock: [relay_1, relay_2]
    interlock_wait_time: 500ms  # Please adjust this accordingly
  - id: !extend relay_2
    interlock: [relay_1, relay_2]
    interlock_wait_time: 500ms  # Please adjust this accordingly
```

### Remove non-essential components
This can be useful to free-up memory, so other custom components could be used instead.

```yaml
# Removes captive portal
captive_portal: !remove

# Removes embedded web server
web_server: !remove
```

### Restart with 15s button press
This could be used to have an easy way to restart your panel locally in addition to the [reset pin in the bottom of your panel](pics/eu_reset_button.png).

```yaml
binary_sensor:
  # Restarts the Nextion display after pressing and holding the left button for 15s
  - id: !extend left_button
    on_multi_click:
      - timing:
          - ON for at least 15.0s
        invalid_cooldown: ${invalid_cooldown}
        then:  # Restart the display
          - switch.turn_off: screen_power
          - delay: 5s
          - switch.turn_on: screen_power
          - delay: 2s
          - lambda: disp1->soft_reset();
          - delay: 2s
          - script.execute: setup_sequence

  # Restarts ESPHome after pressing and holding the right button for 15s
  - id: !extend right_button
    on_multi_click:
      - timing:
          - ON for at least 15.0s
        invalid_cooldown: ${invalid_cooldown}
        then:  # Restart the panel
          - button.press: restart_nspanel
```
