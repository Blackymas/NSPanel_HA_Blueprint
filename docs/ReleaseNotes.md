## Support this project

### As always, we would like to thank everyone who donated to this project and remind you that every donation helps to support this project - so if you haven't made a donation yet, now would be a good time ;)

[![Paypal](https://user-images.githubusercontent.com/41958506/212499642-b2fd097a-0938-4bfc-b37b-74df64592c58.png)](https://www.paypal.com/donate/?hosted_button_id=S974SWQMB8PB2)

&nbsp;
## General

First of all, we wanna say a big thanks to all of you who starred this project in GitHub. It's amazing how the number of stars keeps growing and is now around 650!!!

After a long wait since the latest big release, which we used to leave our desks for a while and enjoy some vacations time with our beloved ones, we are proud to introduce the version 4.0, which adds new screens and makes your panel more flexible and robust.

&nbsp;
## Updating
Since in this update lots of input to the blueprint changed, we highly recommend you review your settings and make sure all fields have the correct selection. We did our best to support your legacy settings and avoid breaking your system, but please double check your settings if you see something not working as expected.

### Files that need to be reloaded:
1. nspanel_blueprint.yaml - v3.5
2. nspanel_eu.tft or nspanel_us.tft - v3.5
3. nspanel_esphome.yaml - v3.5

### Instructions
 _You can find the update procedures following here:_
- [(EN) How To - All important thing you should know - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-HowTo---All-important-thing-you-should-know#2-update-blueprint)
- [(DE) How To - Alle wichtigen Dinge die man wissen sollte - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#2-update-blueprint)

&nbsp;
## Breaking changes
1. New requirements: Home Assistant and ESPHome v2023.5.0 or later.
2. Existing users will have to select again the language for the panel, otherwise English will be used to display strings.
3. Removed entity `sensor.xxxxx_settings_entity` and service `esphome.xxxxx_set_settings_entity`.
4. Due to the changes on the time display engine, you might have to select your time format again in the blueprint settings.
5. The network settings was moved to under `networks` on the `wifi` section. If you are using advanced/custom settings for Wi-Fi on ESPHome, you may have to update it in order to follow the new format.
6. The sensor "Uptime" is deprecated. It was replaced by "API timestamp" and "Device timestamp" sensors, which makes it more readable to humans on Home Assistant interface and shows respectively the last time the API got connected (between the panel and Home Assistant) and the last time the device started. Thanks to @WZYProjects (#986 and #998) for the new sensors.<br>
7. Service `esphome.xxxxx_qr_code` is deprecated. It was replaced by service `qrcode` which can be used for changing the QRcode value even when the QRcode page is not visible (useful when using dynamic Wi-Fi credentials).
8. Removed switches "Relay 1 Local Fallback" and "Relay 2 Local Fallback", together with the relay fallback inputs. Now when you assign your panel's relay to it's respective button the control will be fully local and therefore will have the same behavior as the "fallback" in previous versions.
9. The "Hardware button long press hold delay" input was removed and the delay (800ms) is now hard coded in ESPHome.
10. The service `esphome.xxxxx_wake_up_display` was deprecated. Please use `esphome.xxxxx_wake_up` instead which uses the parameter `reset_timer: bool` to indicate if the timeout timer (to move back to Home page) should be reset.
11. The services `esphome.xxxxx_send_command_font_color` and `esphome.xxxxx_send_command_background_color` where deprecated. Please use `esphome.xxxxx_set_component_color` instead, and you can use RGB arrays for `foreground` and `background` colors, a 1-element array with the Nextion color code or an empty array if you don't want to change that specific parameter.
12. Old color selection (based in a text input where you typed a number) is being deprecated gradually.<br>The icons colors selected before the implementation of the color picker (when it was about typing a number) might fail now, so if you haven't done this yet, please select the color using the new color selector. Open the Blueprint and if the colors are shown properly, you are good, otherwise, please select a color.
13. Sensor "NSPanel Event".<br>This sensor contains a json-like text and is used for ESPHome to send information to the blueprint. This is slowly being replaced by Home Assistant events and then will be removed.<br>The sensor "Current page" is back with the information about the page currently visible in your panel, so please update your automation if you are using the event sensor.
13. The panel selection based on a text box (where you manually typed the panel name).<br>The new device selection was introduce a few releases ago and is more reliable. The previous selections are still valid, but requires extra processing every time the automation is triggered, so it will be removed.<br>If you can see your device name on the blueprint settings screen, you are good, otherwise, pick your panel from the new drop down list.

&nbsp;
## Overview of all changes
1. Add-ons support
	-  Embedded thermostat (cooler or heater) (#917)
2. Alarm control panel
3. Support to sensor display precision from Home Assistant (#880)
4. Filtered device list (#881)
5. New language selector (#882)
6. Removed `settings_entity` (#887)
7. Support for US model on landscape mode (#890)
13. API status indication on the panel ([#5ff5d35](https://github.com/Blackymas/NSPanel_HA_Blueprint/commit/5ff5d35833be1a1cf9ca0f570662456058980024))
14. Light & cover settings pages will show only the supported features (#896)
15. New "Fan speed page" (#897)
16. Select wake-up page (#898)
17. Panel's local control

&nbsp;
## Details of all changes

### 1. Support to add-ons
We are trying to make your panel more useful and more robust by changing some of the functionalities to run internally in the panel, even when the Wi-Fi network or Home Assistant are not available, however, every new functionality takes a bit from the ESP embedded in your panel and increases the complexity, and having a code capable to adapt to all the different user cases will be very complex and certainly will exceed the available memory.

The first add-on available is an **[embedded thermostat](/docs/en/addon_climate.md)**, able to control it locally even when your Wi-Fi is out or Home Assistant is unavailable.

Please refer to the [documentation](/docs/en/addon_climate.md) to get more details on how to enable this add-on.

&nbsp;
### 2. Alarm control panel
Now you can control an Alarm Control Panel from your NSPanel, which will allow you to set the alarm mode between the standard modes supported by Home Assistant (Home, Away, Night, Vacation or Custom bypass) or disarm the alarm.
On this first release, only the basic functionality will be available, so please share your ideas for future improvements.

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/bc312981-3d5a-42c7-b0b4-203457ff549f)

For more details, instructions and security considerations, please take a look at the [Alarm Control Panel docs](/docs/en/alarm.md). You may also want to join [this discussion](https://github.com/Blackymas/NSPanel_HA_Blueprint/discussions/984) about the alarm implementation and some ideas for the future releases.

**Important:** At this moment, this functionality is available only for alarms without a code or alarms using a numeric code. Alarms with text code are not yet supported.

&nbsp;
### 3. Support to sensor display precision from Home Assistant
Now the values shown in your panel will follow the [sensor display precision](https://www.home-assistant.io/blog/2023/03/01/release-20233/#sensor-display-precision) provided by Home Assistant.

=> If you have problems with a value exceeding the available space in your panel, please reduce the number of decimals using Home Assistant [sensor display precision](https://www.home-assistant.io/blog/2023/03/01/release-20233/#sensor-display-precision).

&nbsp;
### 4. Filtered device list
When selecting the NSPanel on the automation, only ESP32 devices will be shown, making easier to find your panel.
![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/0e66bd6b-23c3-4014-8603-958acea48462)

&nbsp;
### 5. New language selector
Starts using the new language selector release with HA 2023.5.0 and based on RFC 5646, which will increase reliability and standardization of the code.
Althougt this is not visible for users at the first view, it will enable the use of more granular language selections (like pt-BR vs pt-PT or en-US vs en-UK) if needed in the future.

=> If you are an existing users, please remember to select your language again after the update, as the previous selection will be invalid.

&nbsp;
### 6. Removed `settings_entity`
The entity `sensor.xxxxx_settings_entity` was previously used by ESPHome to to transfer information about the selected entity on the settings page to the Blueprint, enabling the transfer of settings from different instances of the blueprint with the use of service `esphome.xxxxx_set_settings_entity`. This mechanism was a bit fragile and not user friendly.
With this version the information about the entity shown will be part of the `sensor.xxxxx_nspanel_event` and the settings pages will be called with the service `esphome.xxxxx_open_entity_settings_page`.
Apart of a cleaner device page, this change should be transparent for most users. If you have made automation based on the removed elements, please update it using the new service.

&nbsp;
### 7. Support for US model on landscape mode
If you are using a panel model US in landscape mode, you can now use `nspanel_us_land.tft` where the bars related to the hardware buttons will be located at the right, closer to the respective buttons and fixing the offset on the touch screen when using `nspanel_eu.tft` into a US panel.

=> The hardware buttons labels are hidden in this format, as Nextion cannot support rotated text.

&nbsp;
### 8. API status indication on the panel
Now the Wi-Fi icon in the panel (at the right side of the time) will show one of 3 possible states:

![wifi_gray](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/8e462abb-68d7-4ade-b3c1-ef115aa66c2c) The panel is connected to the Wi-Fi and the API is connected to Home Assistant (mdi:wifi)

![api-off_red](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/2486df3b-17ea-4c2c-a3c2-057c565a3173) The panel is connected to the Wi-Fi, but the API is not connected to Home Assistant (mdi:api-off)

![wifi-off_red](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/c8b15d1f-0950-42d7-84d1-fca8610543c0) The panel is **NOT** connected to the Wi-Fi (mdi:wifi-off)

&nbsp;
### 9. Light & cover settings pages will show only the supported features
Now when long press a button connected to a light or a cover, the detailed light settings page will open only when the entity supports advanced control, and the detailed page will only show the controls supported by that entity.

&nbsp;
### 10. New "Fan speed page"
If you have a connected fan supporting speed control, now you are able to control it's speed from your panel. Just add the new fan to one of the buttons pages or to the hardware buttons and a long press on those buttons will pop up the new "Fan speed page":
![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/4167928e-6822-4db6-a24b-f8a1d52806f5)

&nbsp;
### 11. Select wake-up page
Now you can select the wake-up page on the blueprint settings:

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/30b54682-f1ca-43ac-80af-f89459a6ffd7)

This selected page will be shown after a boot (after the boot page) and with a touch in the screen when on screen saver page. After showing this wake-up page, all the previous behavior for closing the page (with a click or after a timeout) will be the same.

&nbsp;
### 12. Panel's local control
We are trying to make your panel as autonomous as possible by moving some of the controls from the Blueprint to ESPHome. This will reduce the load in your network and Home Assistant, but also will make a more reliable system capable to do it's core functionality even when the network is unavailable or Home Assistant is restarting.
With this version, the following engines have been moved to your panel (local control):
- Time display
- Physical relay control (when hardware left button is connected to relay 1 or right button to relay 2) - Replacing the fallback mode from previous versions.
- Embedded thermostat (see item 1 about add-ons)

&nbsp;
## Next topics we are currently working on
See here: https://github.com/Blackymas/NSPanel_HA_Blueprint/labels/roadmap

## What's Changed
* @chpego - Fixes on the blueprint UI (#928)
* @WZYProjects - Human readable "Last started" sensor (#986) and support with customization (#1003)

## New Contributors
* @chpego
* @WZYProjects
