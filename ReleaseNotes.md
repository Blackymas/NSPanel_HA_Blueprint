# v4.2 <= pending update

## Support this project

### As always, we would like to thank everyone who donated to this project and remind you that every donation helps to support this project - so if you haven't made a donation yet, now would be a good time ;)

[![Paypal](https://user-images.githubusercontent.com/41958506/212499642-b2fd097a-0938-4bfc-b37b-74df64592c58.png)](https://www.paypal.com/donate/?hosted_button_id=S974SWQMB8PB2)

&nbsp;
## General <= pending update
The focus this time was on making easier to transfer the TFT files.

As this project grows with features, it becomes more hungry of resources from all sides (ESPHome, your Home Assistant server and even the Nextion display) and with that the chances of something going wrong when updating increased.

So at this release we concentrated on cleaning up de code everywhere and shave some unnecessary elements, making the system easier to install and opening some space for future features. But you still can find a couple of nice new things not related to the cleaning.

&nbsp;
## Updating
Updates may come with changes on the blueprint inputs and we highly recommend you review your settings and make sure all fields have the correct selection. We did our best to support your legacy settings and avoid breaking your system, but please double check your settings if you see something not working as expected.

### Files that need to be reloaded:
1. nspanel_eu.tft,  nspanel_us.tft or nspanel_us_land.tft - v4.2
2. nspanel_esphome.yaml - v4.2
3. nspanel_blueprint.yaml - v4.2

####

### Instructions
 _You can find the update procedures following here:_
- [(EN) How To - All important thing you should know - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-HowTo---All-important-thing-you-should-know#2-update-blueprint)
- [(DE) How To - Alle wichtigen Dinge die man wissen sollte - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#2-update-blueprint)

&nbsp;
## Breaking changes

1. Service `esphome.xxxxx_set_component_color` parameter `background` is deprecated.
2. Due to the additional custom buttons, the other buttons on home page changed their positions.
3. The Wi-Fi power save mode is back to "NONE" as default.<br>
This was the default until v4.0, but we changed on v4.1 to support Bluetooth components, however as this is not used by the majority of users, we are reverting back to the original setting. You can (and should if you want use Bluetooth) enforce other mode as a customization, like in the example bellow:
```yaml
##### My customization - Start #####
# Enable Bluetooth proxy
bluetooth_proxy:
# Set Wi-Fi power save mode to "LIGHT" as required for Bluetooth on ESP32
wifi:
  power_save_mode: LIGHT
##### My customization - End #####
```
4. Default baud rate for advanced mode is back to 115200 bps, to avoid issues when creating buttons pages.
5. ESPHome v2023.12.0 is now the minimum required version

&nbsp;
## Overview of noteworthy changes
1. Standardized entity's icons
2. Additional custom buttons on Home page
3. Outdoor temperature selectable font size
4. Select icon size for button's pages
5. Support to Chinese (Taiwan) and prepared for other CJK languages
6. Upload baud rate selectable as substitution

&nbsp;
## Details of noteworthy changes

### 1. Standardized entity's icons
The engine for defining the icons to be shown and it's color was standardize between all the pages, so now you may see a more consistent User's Interface.

&nbsp;
### 2. Additional custom buttons on Home page
It's that simple, now you have 6 buttons where used to be 3. 😉

&nbsp;
### 3. Outdoor temperature selectable font size
Now you can select the font size of your outdoor temperature display:

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/263f14d6-39f7-41d2-ae12-72f403d811fd)

> Important: Long text with bigger fonts may exceed the limit of space reserved for this with incomplete information shown.

&nbsp;
### 4. Select icon size for button's pages
You can also select the size of the icons on the buttos pages:

<<add blueprint screenshot>>
<<add page screenshot (US and EU)>>

&nbsp;
### 5. Support to Chinese (Taiwan) and prepared for other CJK languages
You will find 3 new TFT files on the repository for the CJK languages. These files are considerably bigger, as the fonts requires more memory, but it should work fine in your panel.
Currently only translations to Chinese (Taiwan) are available, but as soon we get the strings for other languages we will be happy to add to the blueprint selection.
<< Add screenshots of blueprint >>

&nbsp;
### 6. Upload baud rate selectable as substitution
You can select an alternative baud rate for your TFT uploads. This allows faster TFT uploads and also supports displays previously set with baud rates not supported by this project (currently 115200 bps and 921600 bps).

To enable an alternative upload TFT baud rate, add the desired value in your substitutions like this:

```yaml
  upload_tft_baud_rate: "921600"
```

If an invalid value is entered or this substitution is not present, the current baud rate will be used.

The system will always fall back to the standard baud rate (115200 bps) if other tentatives fails.

&nbsp;
## What's Next?
Discover what's next and what we are working on right now in our [Milestones](https://github.com/Blackymas/NSPanel_HA_Blueprint/milestones?direction=asc&sort=due_date)

&nbsp;
## Special thanks to:

## New Contributors

## Previous releases
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
