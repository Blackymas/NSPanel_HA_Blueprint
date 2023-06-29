## Support this project

### As always, we would like to thank everyone who donated to this project and remind you that every donation helps to support this project - so if you haven't made a donation yet, now would be a good time ;)

[![Paypal](https://user-images.githubusercontent.com/41958506/212499642-b2fd097a-0938-4bfc-b37b-74df64592c58.png)](https://www.paypal.com/donate/?hosted_button_id=S974SWQMB8PB2)

&nbsp;
## General

### 

&nbsp;
## Updating
Since in this update lots of input to the blueprint changed, we highly recommend you review your settings and make sure all fields have the correct selection. We did our best to support your legacy settings and avoid breaking your system, but please double check your settings if you see something not working as expected.

### Files that need to be reloaded:
1. nspanel_blueprint.yaml - v3.5
2. nspanel_eu.tft or nspanel_us.tft - v3.5
3. nspanel_esphome.yaml - v3.5

### Instructions
 _You can find the update procedures following here:_
- [(EN) HowTo - All important thing you should know - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-HowTo---All-important-thing-you-should-know#2-update-blueprint)
- [(DE) HowTo - Alle wichtigen Dinge die man wissen sollte - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#2-update-blueprint)
&nbsp;
## Breaking changes
1. New requirement: Home Assistant 2023.5.0 or later
2. Exisiting users will have o select again the language for the panel, otherwise English will be used to display strings.
3. Removed entity `sensor.xxxxx_settings_entity` and service `esphome.xxxxx_set_settings_entity`

&nbsp;
## Overview of all changes
1. Alarm control panel
2. Support to sensor display precision from Home Assistant (#880)
3. Filtered device list (#881)
4. New language selector (#882)
5. Removed `settings_entity` (#887)
6. Support for US model on landscape mode (#890)
7. API status indication on the panel ([#5ff5d35](https://github.com/Blackymas/NSPanel_HA_Blueprint/commit/5ff5d35833be1a1cf9ca0f570662456058980024))
8. Light & cover settings pages will show only the supported features (#896)
9. New "Fan speed page" (#897)
   
&nbsp;
## Details of all changes

### 1. Alarm control panel
recommend api-encryption: https://esphome.io/components/api.html#configuration-variables
and, of course warn the user that this is a possible security issue.
Anyways - this is also done with many other projects, AND it would require that a possible hacker is already inside the internal (or mayby iot) (W)LAN - and at this point....
recommend to have a big warning, and that the user has to take care about e.g.:
- secure internal network
- split internal networks: IOT, Guest, Internal, Management, ...
- enable api-encryption

### 2. Support to sensor display precision from Home Assistant
Now the values shown in your panel will follow the [sensor display precision](https://www.home-assistant.io/blog/2023/03/01/release-20233/#sensor-display-precision) provided by Home Assistant.

=> If you have problems with a value exceeding the available space in your panel, please reduce the number of decimals using Home Assistant [sensor display precision](https://www.home-assistant.io/blog/2023/03/01/release-20233/#sensor-display-precision).

### 3. Filtered device list
When selecting the NSPanel on the automation, only ESP32 devices will be shown, making easier to find your panel.
![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/0e66bd6b-23c3-4014-8603-958acea48462)

### 4. New language selector
Starts using the new language selector release with HA 2023.5.0 and based on RFC 5646, which will increase reliability and standardization of the code.
Althougt this is not visible for users at the first view, it will enable the use of more granualar language selections (like pt-BR vs pt-PT or en-US vs en-UK) if needed in the future.

=> If you are an existing users, please remember to select your language again after the update, as the previous selection will be invalid.
&nbsp;

### 5. Removed `settings_entity`
The entity `sensor.xxxxx_settings_entity` was previously used by ESPHome to to transfer information about the selected entity on the settings page to the Blueprint, enabling the transfer of settings from different instances of the blueprint with the use of service `esphome.xxxxx_set_settings_entity`. This mechanism was a bit fragile and not user friendly.
With this version the information about the entity shown will be part of the `sensor.xxxxx_nspanel_event` and the settings pages will be called with the service `esphome.xxxxx_open_entity_settings_page`.
Apart of a cleaner device page, this change should be transparent for most users. If you have made automations based on the removed elements, please update it using the new service.
&nbsp;
### 6. Support for US model on landscape mode
If you are using a panel model US in landscape mode, you can now use `nspanel_us_land.tft` where the bars related to the hardware buttons will be located at the right, closer to the respective buttons and fixing the offset on the touch screen when using `nspanel_eu.tft` into a US panel.

=> The hardware buttons labels are hidden in this format, as Nextion cannot support rotated text.
&nbsp;
### 7. API status indication on the panel
Now the Wi-Fi icon in the panel (at the right side of the time) will show one of 3 possible states:

![wifi_gray](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/8e462abb-68d7-4ade-b3c1-ef115aa66c2c) The panel is connected to the Wi-Fi and the API is connected to Home Assistant (mdi:wifi)

![api-off_red](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/2486df3b-17ea-4c2c-a3c2-057c565a3173) The panel is connected to the Wi-Fi, but the API is not connected to Home Assistant (mdi:api-off)

![wifi-off_red](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/c8b15d1f-0950-42d7-84d1-fca8610543c0) The panel is **NOT** connected to the Wi-Fi (mdi:wifi-off)
&nbsp;
### 8. Light & cover settings pages will show only the supported features
Now when long press a button conneted to a light or a cover, the detailed light settings page will open only when the entity supports advanced control, and the detailed page will only show the controls supported by that entity.
&nbsp;
### 9. New "Fan speed page"
If you have a connected fan supporting speed control, now you wilhave all the speed control settings in your panel. Just add the new fan to one of the buttons pages or to the hardware buttons and a long press on those buttons will pop up the new "Fan speed page":
![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/4167928e-6822-4db6-a24b-f8a1d52806f5)

## Next topics we are currently working on
See here: https://github.com/Blackymas/NSPanel_HA_Blueprint/labels/roadmap

## What's Changed
* 

## New Contributors
* 
