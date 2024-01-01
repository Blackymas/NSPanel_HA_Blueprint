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
- [How To - All important thing you should know - Update](docs/howto.md#update-blueprint)

&nbsp;
## Breaking changes
1. **The `background` parameter in the `esphome.xxxxx_set_component_color` service is now deprecated.**
2. **On the home and climate pages, the button layout has changed.** This adjustment was made to incorporate additional custom buttons on the home page and new target temperature indicators on the climate page.
3. **Wi-Fi power save mode has been reset to `NONE` as the default setting.**<br>This was the standard up to v4.0. We switched it in v4.1 to accommodate Bluetooth components. However, since this feature isn't widely used, we're reverting to the original setting. For Bluetooth usage, you should manually set a different mode, such as `LIGHT`, as shown in the customization example below:
```yaml
##### My customization - Start #####
# Enable Bluetooth proxy
bluetooth_proxy:
# Set Wi-Fi power save mode to "LIGHT" as required for Bluetooth on ESP32
wifi:
  power_save_mode: LIGHT
##### My customization - End #####
```
4. **The default baud rate for advanced mode has been reverted to 115200 bps** to resolve issues that arise when rendering button pages.
5. **ESPHome v2023.12.0 has been established as the minimum required version** to ensure optimal performance and compatibility, particularly with the recent developments in the Nextion component.
6. **The Alarm section in the blueprint settings has been removed.** All configurations previously made in this section have been automatically transferred to custom button 07.
7. **Documentation in German is no longer maintained.** This change allows us to more efficiently update and maintain the remaining documentation.
8. **Reversion to "Toggle" as default action for automation entities on buttons.**

    In this update, we have reverted the default action for button presses on automation. entities back to "Toggle." This change reverses the adjustment made in version 4.1, where "Trigger" was set as the default action.

    **Impact:**

    - **Default Behavior:** With this reversion, pressing a button linked to an automation entity will now enable or disable the automation, as it did prior to version 4.1.
    - **Consistency and Familiarity:** This change aims to align with user expectations and maintain consistency in the user experience.
    - **Customization Still Available:** Users still have the option to manually set "Trigger" as the action for their automation. entities, as per their preference.

    We understand that changes in default settings can impact your workflows. We appreciate your understanding as we strive to balance new features with the familiarity and stability of the user experience.
9. **Advanced mode no longer enforces a specific framework.**<br>
    In the past, the enforcement of framework changes by the advanced mode could inadvertently result in users switching frameworks during OTA updates. This practice was not recommended due to the potential for errors.
10. **Alarm page cannot be used as wake-up page.**<br>
    As multiple alarms are supported now, the system don't know which one to show on the wake-up.

&nbsp;
## Overview of noteworthy changes
1. Standardized entity's icons
2. Additional custom buttons on Home page
3. Outdoor temperature selectable font size
4. Select icon size for button's pages
5. Support to Chinese (Taiwan) and prepared for other CJK languages
6. Upload baud rate selectable as substitution
7. Multiple Alarm Control Panels
8. Support to `remote`
9. Home page chips now supports covers
10. Chips can be inverted
11. Add swipe control to screensaver page
12. Enhanced control for automation entities on buttons
13. Dual thermostat controller support (add-on)
14. Dual thermostat display
15. Enhanced timeout flexibility for Sleep, Page fallback, and Dimming settings
16. Display time on the `screensaver` page

&nbsp;
## Details of noteworthy changes

### 1. Standardized entity's icons
The engine for defining the icons to be shown and it's color was standardize between all the pages, so now you may see a more consistent User's Interface.

&nbsp;
### 2. Additional custom buttons on Home page
It's that simple, now you have 7 buttons where used to be 3. Well, where used to be 4, as the space previously used by the Alarm button is now a custom button. 😉

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
### 7. Multiple Alarm Control Panels
Now alarm control panel entities can be assigned to chips and custom buttons in the Home page, but also to hardware buttons, any of the buttons pages or entities pages, similarly to other domains.

&nbsp;
### 8. Support to `remote`
Entities from the `remote` domain can now be assigned to buttons (hardware and buttons pages) and custom buttons (home and climate pages).

The service `remote.toggle` will be called when the button is pressed.

&nbsp;
### 9. Home page chips now supports covers
That's it!
Chips now include cover visualization, allowing for easy monitoring of covers directly from the Home page.

&nbsp;
### 10. Chips can be inverted
Chips now have an 'invert' option on the blueprint settings, providing additional customization flexibility.

&nbsp;
### 11. Add swipe control to Screensaver page
You can now navigate to button pages from the screensaver while your panel is in sleep mode. The swipe controls will function as they do on the Home page.

&nbsp;
### 12. Enhanced control for automation entities on buttons
We're pleased to announce a new feature that offers users enhanced control over their smart home setups. Now, you can globally select between **Toggle** and **Trigger** actions for button presses on automation entities. This update allows for a more personalized and efficient control experience, tailored to your unique preferences.

#### Key features:
- **Toggle:** This action will enable or disable the automation. It is set as the default option.
- **Trigger:** This action will execute the automation regardless of its current state, providing more flexibility.

#### How to use:
1. Access your configuration for automation under **Services** > **Automations & Scenes**. Select the automation associated with your panel setup.
1. Scroll to the **ADVANCED SETTINGS** section at the end.
1. From the menu, select your desired action - either **Toggle** or **Trigger**.
1. Apply the setting. This will then be effective across all relevant entities.

This update is specially designed to cater to diverse user needs, ensuring a more intuitive and responsive smart home experience.

&nbsp;
### 13. Dual thermostat controller support (add-on)
This new add-on enables the NSPanel to manage both heating and cooling systems simultaneously, utilizing its dual relay functionality.

#### Key Benefits:
- **Versatility:** Users can now configure their NSPanel to control both a heater and a cooler, offering increased flexibility in home temperature management.
- **Efficiency:** With the ability to control both heating and cooling systems, the NSPanel can more effectively maintain desired temperatures, potentially leading to energy savings.
- **User Experience:** This update simplifies the user interface by integrating control of both systems into one panel, making it easier to manage home climate.

#### Implementation Details:
- The dual thermostat controller functionality allows the NSPanel to utilize both of its relays for separate heating and cooling control.<br>
Users can configure their heating and cooling settings independently, providing a tailored climate control experience.
- The update is designed to be intuitive and user-friendly, ensuring a seamless transition for existing NSPanel users.
- Additional Documentation: For detailed instructions and configurations, refer to the updated [add-on climate documentation](docs/addon_climate.md).

#### Note to Users:
This feature enhances the capabilities of the NSPanel without compromising its existing functionalities. Users who previously used the NSPanel for single-mode (either heating or cooling) control can now explore dual-mode options for a more comprehensive climate control solution.

&nbsp;
### 14. Enhanced Climate Page for Dual Thermostat Control
Leveraging the capabilities introduced with the Dual Thermostat Controller add-on, the existing climate page has been upgraded to support systems with dual temperature settings. This enhancement allows users to effectively manage thermostats that require both heating and cooling target temperatures, directly from the NSPanel's interface. While originally developed to complement the new add-on, this refined climate page also seamlessly extends its functionality to existing thermostats with dual set capabilities, offering a more versatile and comprehensive climate control experience.

&nbsp;
### 15. Enhanced timeout flexibility for Sleep, Page fallback, and Dimming settings
We have improved the functionality of our system by enhancing the timeout flexibility for Sleep, Page Fallback, and Dimming settings. The previous timeout limit of 300 seconds has been significantly expanded, offering users more control and customization options for these specific features. This enhancement allows for a wider range of use cases, catering to the needs of those who require extended periods for these settings, while still maintaining the option for shorter durations.

&nbsp;
### 16. Display time on the `screensaver` page
In this release, we're excited to introduce a new feature that adds a display time function to the Screensaver page. With this update, our screensaver not only serves its primary purpose of saving screen energy but also doubles as an informative display, reflecting our commitment to creating practical, user-friendly solutions.

You can enable this feature on the bueprint settings, at the **CUSTOM CONFIGURATION** section (almost at the end). You also have to set **Display Brightness Sleep** at the device's page (**Settings** > **Devices & Services** > **ESPHome**).

&nbsp;
## What's Next?
Discover what's next and what we are working on right now in our [Milestones](https://github.com/Blackymas/NSPanel_HA_Blueprint/milestones?direction=asc&sort=due_date)

&nbsp;
## Special thanks to:
- @bluefoxlee - For the CJK fonts and all the support with #1359.
- @Floppe - Fix entity pages labels, #1455

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
