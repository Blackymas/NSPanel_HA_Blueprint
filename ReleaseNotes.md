# (DRAFT) v4.1 - Easier TFT transfer

## Support this project

### As always, we would like to thank everyone who donated to this project and remind you that every donation helps to support this project - so if you haven't made a donation yet, now would be a good time ;)

[![Paypal](https://user-images.githubusercontent.com/41958506/212499642-b2fd097a-0938-4bfc-b37b-74df64592c58.png)](https://www.paypal.com/donate/?hosted_button_id=S974SWQMB8PB2)

&nbsp;
## General
The focus this time was on making easier to transfer the TFT files.

As this project grows with features, it becomes more hungry of resources from all sides (ESPHome, your Home Assistant server and even the Nextion display) and with that the chances of something going wrong when updating increased.

So at this release we concentrated on cleaning up de code everywhere and shave some unnecessary elements, making the system easier to install and opening some space for future features.

&nbsp;
## Updating
Since in this update lots of input to the blueprint changed, we highly recommend you review your settings and make sure all fields have the correct selection. We did our best to support your legacy settings and avoid breaking your system, but please double check your settings if you see something not working as expected.

### Files that need to be reloaded:
1. nspanel_eu.tft,  nspanel_us.tft or nspanel_us_land.tft - v4.1
2. nspanel_esphome.yaml - v4.1
3. nspanel_blueprint.yaml - v4.1

####

### Instructions
 _You can find the update procedures following here:_
- [(EN) How To - All important thing you should know - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-HowTo---All-important-thing-you-should-know#2-update-blueprint)
- [(DE) How To - Alle wichtigen Dinge die man wissen sollte - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#2-update-blueprint)

&nbsp;
## Breaking changes
1. Home Assistant 2023.9.0 or later is now required
This is necessary in order to support the new [Weather Forecast Service](https://www.home-assistant.io/blog/2023/09/06/release-20239/#weather-forecast-service).
The legacy forecast based on attributes will be deprecated in Home Assistant on the begining of 2024.

2.The following components are now deprecated:
   - Buttons:
     - Exit reparse (`button.xxxxx_exit_reparse`) - It shouldn't be necessary with the new TFT upload engine
   - Services:
     - Play rtttl (`esphome.xxxxx_play_rtttl`)
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
If you have a custom automation using very long hold (more than 15s) of hardware buttons it may fail as now the panel will restart with button hold for 15s.

4. Logger via UART is disable
You can add it back as a [customization](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/%28EN%29-Customization/_edit#logger-via-uart):
&nbsp;
## Overview of noteworthy changes
1. New Upload TFT engine
2. Hardware restarts with button hold for 15s
3. Support to `esp-idf` framework
4. Support to 921600 bps

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
The `arduino` protocol still more popular and therefore more components are available, but as `esp-idf` is maintained by EspressIF and is kept updated, more boards are supported and the memory management is better, making it ideal if you wanna customize your panel to support memory consumption functionalities, like `bluetooth_proxy` or [Improv](https://www.improv-wifi.com/).
Please look at [customizations docs in the Wiki](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-Customization#framework-esp-idf) for more details on how to change the framework.

&nbsp;
### 4. Support to 921600 bps
Until this point, the communication between ESPHome and the Nextion display is at 115200 bps. This is not changing for now, but we are preparing to change this in the near future to a higer rate of 921600 bps, which is 8 times higher than the one used currently.
After installing the latest TFT v4.1, you will be able to [change the speed as a customization](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-Customization#change-uarts-baud-rate) and your system will switch to the higher transfer rate after the next boot.

In most of the cases, you are not going to see any diference related tho this change, but it will reduce significantly the time to upload a TFT file.

&nbsp;
## Next topics we are currently working on
See here: https://github.com/Blackymas/NSPanel_HA_Blueprint/labels/roadmap

## Special thanks to:
- @misery - Fixing a typo in the docs (#1176)
- @Floppe - Adding space for value fields on Home page (#1180)

## New Contributors
@misery
@Floppe