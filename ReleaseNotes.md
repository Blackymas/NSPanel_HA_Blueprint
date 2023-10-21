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
1. The following components are now deprecated:
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

    You can still add these components by adding the file `nspanel_esphome_advanced.yaml` in your ESPHome settings as in the example bellow, but please have in mind that these are not used by the blueprint and will be using some memory of your ESPHome. 
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

&nbsp;
## Overview of all changes
1. New Upload TFT engine
2. 

&nbsp;
## Details of all changes

### 1. New Upload TFT engine
We rebuilt the Upload TFT engine and now it will be using less resources from ESPHome during the transfer and, in addition, will provide more logs for troubleshooting.

The original engine from Nextion component still as a fallback in case the new engine fails, but it might be removed in a future version.

### 2. 

&nbsp;
## Next topics we are currently working on
See here: https://github.com/Blackymas/NSPanel_HA_Blueprint/labels/roadmap

## Special thanks to:
- @misery - Fixing a typo in the docs (#1176)
- @Floppe - Adding space for value fields on Home page (#1180)
## New Contributors
@misery
@Floppe