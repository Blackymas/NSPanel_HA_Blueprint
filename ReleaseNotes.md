# v4.1.1 - Easier TFT transfer

## Support this project

### As always, we would like to thank everyone who donated to this project and remind you that every donation helps to support this project - so if you haven't made a donation yet, now would be a good time ;)

[![Paypal](https://user-images.githubusercontent.com/41958506/212499642-b2fd097a-0938-4bfc-b37b-74df64592c58.png)](https://www.paypal.com/donate/?hosted_button_id=S974SWQMB8PB2)

&nbsp;
## General
The focus this time was on making easier to transfer the TFT files.

As this project grows with features, it becomes more hungry of resources from all sides (ESPHome, your Home Assistant server and even the Nextion display) and with that the chances of something going wrong when updating increased.

So at this release we concentrated on cleaning up de code everywhere and shave some unnecessary elements, making the system easier to install and opening some space for future features. But you still can find a couple of nice new things not related to the cleaning.

&nbsp;
## Updating
Since in this update lots of input to the blueprint changed, we highly recommend you review your settings and make sure all fields have the correct selection. We did our best to support your legacy settings and avoid breaking your system, but please double check your settings if you see something not working as expected.

### Files that need to be reloaded:
1. nspanel_eu.tft,  nspanel_us.tft or nspanel_us_land.tft - v4.1.4
2. nspanel_esphome.yaml - v4.1.4
3. nspanel_blueprint.yaml - v4.1.4

####

### Instructions
 _You can find the update procedures following here:_
- [(EN) How To - All important thing you should know - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-HowTo---All-important-thing-you-should-know#2-update-blueprint)
- [(DE) How To - Alle wichtigen Dinge die man wissen sollte - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#2-update-blueprint)

&nbsp;
## Breaking changes

1. Home Assistant 2023.9.0 or later is now required
<br>This is necessary in order to support the new [Weather Forecast Service](https://www.home-assistant.io/blog/2023/09/06/release-20239/#weather-forecast-service).
<br>The legacy forecast based on attributes will be deprecated in Home Assistant on the begining of 2024.

2. The following components are now deprecated:
   - Buttons:
     - Exit reparse (`button.xxxxx_exit_reparse`) - It shouldn't be necessary with the new TFT upload engine
   - ~~Services:~~
     - ~~Play rtttl (`esphome.xxxxx_play_rtttl`)~~
   - Sensors:
     - API uptime
     - Device uptime
     - RSSI
     - ESPhome Version
     - IP
     - SSID
     - BSSID
   - ESPHome components:
     - Web server

    You can still add these components (except by "Exit reparse") by adding the file `nspanel_esphome_advanced.yaml` in your ESPHome settings as in the example bellow, but please have in mind that these are not used by the blueprint and will be using some memory of your ESPHome. 
```yaml
...
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml # Core package
      - nspanel_esphome_advanced.yaml # activate advanced (legacy) elements - can be useful for troubleshooting
...
```

3. Very long press on hardware buttons
<br>If you have a custom automation using very long hold (more than 15s) of hardware buttons it may fail as now the panel will restart with button hold for 15s.

4. Logger via UART is disable
<br>You can add it back as a [customization](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/%28EN%29-Customization/_edit#logger-via-uart).
5. Service `notification_show` parameter `text` was renamed to `message` to support ESPHome 2023.11.0.

6. Buttons now will run an automation
<br>On the previous versions, a button with an automation will enable or disable the automation. Now the button will trigger the automation.
<br>If you want the legacy behavior, please create a script to enable/disable the automation and assign this to your button. 😉
&nbsp;
## Overview of noteworthy changes
1. New Upload TFT engine
2. Hardware restarts with button hold for 15s
3. Support to `esp-idf` framework
4. Support to 921600 bps
5. Font size for chips
6. Short click to open Climate and Media Player

- 4.1.1 patch:
   - Service `esphome.xxxxx_play_rtttl` is back to core package
   - Stop the fallback to Home page when Notification or Confirm pages are shown
   - Display current temperature on buttons even when climate is off
   - Buttons on both the Home and Buttons pages shows entity's icon when available
- 4.1.2 patch:
   - Fix light icon color not being used for buttons
   - Add option to wake-up to Climate page
   - New switch "Nextion display - Power" which can turn the screen on/off
   - Fix for button image update when local fallback is enabled.
   - Don't show thermostat chip when state is `auto` and no action is available.
   - Fallback to legacy forecast (attributes based) when new method (service based) fails.
   - Fix custom buttons icons not updating on Home page
   - Fix Nextion not communicating with ESPHome 2023.11.6
- 4.1.3 patch:
   - Upload TFT remove dependency to from ESPHome Nextion component
   - Fix light icon color on buttons
   - Fix climate page not updating properly
- 4.1.4 patch:
   - Supports new `weather.get_forecasts` introduced by Home Assistant 2023.12.0
   - Manual line break on multiline text with `\r`
   - Upload TFT user's interface on the panel

&nbsp;
## Details of noteworthy changes

### 1. New Upload TFT engine
We rebuilt the Upload TFT engine and now it will be using less resources from ESPHome during the transfer and, in addition, will provide more logs for troubleshooting.

The original engine from Nextion component still as a fallback in case the new engine fails, but it might be removed in a future version.

&nbsp;
### 2. Hardware restarts with button hold for 15s
Now if you press the hardware buttons for more than 15s, the panel will act as the following:
| Button | Action | Details |
| :--: | :--: | :- |
| Left | Power cycle the screen | It can remove the need to power cycle the panel when the screen can't stablish connection to ESPHome (`Nextion is not connected!` on logs). |
| Right | Restarts the panel | It is equivalent to press the "Restart" button on the Settings page or from Home Assistant, but is available even when the Wi-Fi isn't connected or Home Assistant is out. |

&nbsp;
### 3. Support to `esp-idf` framework
Although this project still using ESPHome default framework (currently `arduino`), we started supporting the framework `esp-idf` as this is a recomendation from ESPHome team since an year ago or so.
The `arduino` protocol still more popular and therefore more components are available, but there are some advantages with the ESP-IDF framework:
- It is updated more frequently by EspressIF, which means it is more secure and stable.
- It reduces a layer, as Arduino is developed in top of ESP-IDF, so basically we are changing from ESPHome -> Arduino -> ESP-IDF -> Hardware to ESPHome -> ESP-IDF -> Hardware.
- By reducing a layer, more memory is available for future features and for the custom components you might want to add to your panel.
- The memory management is more efficient, which makes critical tasks, like uploading a TFT file, more reliable.
<br>In the future we will probably make this as the default framework, so if you are a new user or if for some reason you have to flash your panel via serial/usb, it's a good idea to change to ESP-IDF now.
<br>Please look at [customizations docs in the Wiki](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-Customization#framework-esp-idf) for more details on how to change the framework.
<br>-> The ESP-IDF framework will be used when you enable the advanced mode.

&nbsp;
### 4. Support to 921600 bps
Until this point, the communication between ESPHome and the Nextion display is at 115200 bps. This is not changing for now, but we are preparing to change this in the near future to a higer rate of 921600 bps, which is 8 times higher than the one used currently.
After installing the latest TFT v4.1, you will be able to [change the speed as a customization](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-Customization#change-uarts-baud-rate) and your system will switch to the higher transfer rate after the next boot.
<br>In most of the cases, you are not going to see any diference related tho this change, but it will reduce significantly the time to upload a TFT file.

&nbsp;
### 5. Font size for chips
We ran a poll, the maiority select one option, but we respect the minority and... we supported both options. :smiley:
<br>Now you can have your chips a bit bigger, making it easier to see from the distance:

| 24px | 32px |
| :--: | :--: |
| As before | New option |
| ![EU font 8](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/dfb79856-8456-443c-b4de-a955be8e4561) | ![EU font 9](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/268ec945-94dc-4f17-be94-8abd691ef2ed)  |
| ![US font 8](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/a9eb3578-901a-444f-9d52-3909f2aa4f34) | ![US font 9](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/e46bac5e-8a84-4cfe-a01d-159042828350) |

If you wanna try the new option, just go to your blueprint setting and select the font size:
![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/83e64dfa-b2cf-4186-af2a-6f89c96e9044)

&nbsp;
### 6. Short click to open Climate and Media Player
Now on any button page, buttons assigned to Climate or Media Player entities will always open the detailed page. As it is hard to define an adequate toggle action for all the different cases, it makes more sense to just open the page and let the control to the users.

&nbsp;
## Next topics we are currently working on
See here: https://github.com/Blackymas/NSPanel_HA_Blueprint/labels/roadmap

## Special thanks to:
- @misery - Fixing a typo in the docs (#1176)
- @Floppe - Adding space for value fields on Home page (#1180)
- @bkbartk:
   - Display current temperature on buttons even when climate is off (#1268)
   - Button pages shows entity's icon when available (#1269)
   - Home page buttons shows entity's icon when available (#1276)
   - New switch "Nextion display - Power" which can turn the screen on/off (#1327)
   - Fix for button image update when local fallback is enabled (#1333)

## New Contributors
@misery
@Floppe
@bkbartk

## Previous releases
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
