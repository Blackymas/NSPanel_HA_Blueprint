# v4.2 - Multi-Alarm Control, Dual Thermostat Functionality, and More

## Support this project
**As always, we would like to thank everyone who donated to this project and remind you that every donation helps to support this project
So if you haven't made a donation yet, now would be a good time ;)**

[![Paypal](https://user-images.githubusercontent.com/41958506/212499642-b2fd097a-0938-4bfc-b37b-74df64592c58.png)](https://www.paypal.com/donate/?hosted_button_id=S974SWQMB8PB2)

## General
Hello everyone! Our latest update introduces a range of enhancements designed to elevate your experience with the firmware.
This update is focused on improving user interaction, featuring a more intuitive TFT upload process and expanded customization options.
Key enhancements include upgraded functionality for Alarm Control Panels & Thermostats and new personalization features on the Home page.

We're enthusiastic about our ongoing work to [make the NSPanel firmware more user-friendly and accessible](https://github.com/Blackymas/NSPanel_HA_Blueprint/discussions/1602).
This release marks significant progress in this direction, with improvements such as the
streamlined TFT upload process and initial steps towards adopting `esp-idf` as the default framework.
Additionally, our documentation has been revamped for greater clarity and user-friendliness.
Expect more user-centric updates coming your way soon!

Dive into the details below to see how these changes can enhance your daily use of NSPanel.
We value your feedback and are eager to hear your thoughts!

### Upcoming Change: Switching to ESP-IDF Framework by March 2024
We have some important updates for our community – by March 2024, we're moving to the **ESP-IDF** as our standard framework.
This shift aims to significantly boost the memory capacity on the ESP, allowing for the addition of new features and broader customizations.

There's ample time before this transition takes place, so no need to hurry.
When it's time to switch, flashing your device using a serial cable will be necessary, similar to the initial custom firmware setup.

For those who might need a serial firmware installation before March,
trying out `esp-idf` earlier could be a beneficial move towards adapting to future developments.

If you're unable to switch by March or if serial flashing isn't an option for you,
the `arduino` framework will still be available for Over-The-Air (OTA) updates.

For detailed guidance on framework customization, check out our [customization documentation](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/customization.md).
We're dedicated to facilitating a smooth transition and are here to assist with any queries or concerns.

## Updating
Updates may come with changes on the blueprint inputs and we highly recommend you review your settings and make sure all fields have the correct selection.
We did our best to support your legacy settings and avoid breaking your system, but please double check your settings if you see something not working as expected.

### Files that need to be reloaded
1. nspanel_eu.tft,  nspanel_us.tft or nspanel_us_land.tft - v4.2
2. nspanel_esphome.yaml - v4.2
3. nspanel_blueprint.yaml - v4.2

### Instructions
 *You can find the update procedures following here:*

- [How To - All important thing you should know - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/howto.md#update-blueprint)

## Breaking changes
1. **The `background` parameter in the `esphome.xxxxx_set_component_color` service is now deprecated.**
2. **On the home and climate pages, the button layout has changed.**

    This adjustment was made to incorporate additional custom buttons on the home page and new target temperature indicators on the climate page.
3. **Wi-Fi power save mode has been reset to `NONE` as the default setting.**

    This was the standard up to v4.0. We switched it in v4.1 to accommodate Bluetooth components.
    However, since this feature isn't widely used, we're reverting to the original setting.
    For Bluetooth usage, you should manually set a different mode, such as `LIGHT`, as shown in the customization example below:

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

    In this update, we have reverted the default action for button presses on automation. entities back to "Toggle".
    This change reverses the adjustment made in version 4.1, where "Trigger" was set as the default action.

    **Impact:**

    - **Default Behavior:** With this reversion, pressing a button linked to an automation entity will now enable or disable the automation, as it did prior to version 4.1.
    - **Consistency and Familiarity:** This change aims to align with user expectations and maintain consistency in the user experience.
    - **Customization Still Available:** Users still have the option to manually set "Trigger" as the action for their `automation.` entities, as per their preference.

    We understand that changes in default settings can impact your workflows.
    We appreciate your understanding as we strive to balance new features with the familiarity and stability of the user experience.
9. **Advanced mode no longer enforces a specific framework.**

    In the past, the enforcement of framework changes by the advanced mode could inadvertently result in users switching frameworks during OTA updates.
    This practice was not recommended due to the potential for errors.
10. **Alarm page cannot be used as wake-up page.**

    As multiple alarms are supported now, the system don't know which one to show on the wake-up.
11. **Refinement of Icon Presentation**

    In our continuous pursuit to refine the user experience, we've embarked on standardizing the presentation of icons across various pages.
    This initiative may lead to noticeable changes in icon appearance and behavior,
    encompassing aspects like the introduction of new colors for alarms, lights, climate icons,
    and the adoption of fresh icon designs.

    Our aim with these modifications is to establish a default presentation that adheres to a unified standard,
    enhancing both consistency and user experience across the platform.
    While this approach simplifies the overall design,
    it still preserves a degree of customization through blueprint settings.

    The complexity of managing icon colors, especially for items with multi-state attributes like alarm control panels,
    climate controls, and lights with adjustable brightness and color, has prompted us to rethink our approach.
    The current version implements domain-based colors for multi-state items, with specific states for alarms and climate being hard-coded.
    We're exploring ways to offer user-selectable colors for these states in future updates.

    The new color logic is as follows:
    - For the `off` state: Icons will be displayed in **gray**.
    - For states other than `off`:
        - For alarms and climate: Each state will have a specific, hard-coded color for immediate recognition.
        - For lights: If supported, the icon will reflect the light's RGB color, proportionally dimmed to match its brightness.
        - For other domains: Icons will be displayed in **white**.

    This transition towards a more standardized icon presentation is a step forward in enhancing
    the interface's intuitiveness while balancing it with the flexibility of customization.
    We understand this change might be an adjustment from previous versions,
    but our goal is to streamline the experience without compromising the essence of personalization.
12. ***Action required:* Reset your wake-up page selection.**

    We've enhanced the wake-up page functionality for improved consistency after power cycles.
    Previously, the system didn't remember your selection following a power outage.
    With our latest update, this issue has been resolved.
    However, this improvement requires you to reselect your wake-up page one more time.
    Thanks for your cooperation in making these settings more reliable for everyday use.

## Overview of noteworthy changes
1. Standardized entity icons
2. Additional custom buttons on Home page
3. Outdoor temperature selectable font size
4. Select icon size for button's pages
5. Support to CJK languages (experimental)
6. Improved TFT transfer
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

## Details of noteworthy changes

### 1. Standardized entity icons
The engine for defining the icons to be shown and it's color was standardize between all the pages, so now you may see a more consistent User's Interface.
We've upgraded the icon definition engine to standardize the appearance and color of icons across all pages.
This enhancement leads to a more consistent and harmonious user interface.
Expect a unified visual experience that aligns the look and feel of icons throughout the system, contributing to improved navigation and aesthetic appeal.

### 2. Additional custom buttons on Home page
It's that simple, now you have 7 buttons where used to be 3.
Well, where used to be 4, as the space previously used by the Alarm button is now a custom button. 😉

### 3. Outdoor temperature selectable font size
Now you can select the font size of your outdoor temperature display:

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/263f14d6-39f7-41d2-ae12-72f403d811fd)

> [!IMPORTANT]
> Long text with bigger fonts may exceed the limit of space reserved for this with incomplete information shown.

### 4. Select icon size for button's pages
You can also select the size of the icons on the buttos pages:

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/239e2682-c73b-44cc-b1fa-2bf07aeba78b)

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/8e650642-c117-44eb-9150-c5c360075922)

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/9f6471ae-2404-468a-82f1-208e807200bf)

### 5. Support to CJK languages (experimental)
You will find 3 new TFT files on the repository for the CJK languages.
These files are considerably bigger, as the fonts requires more memory, but it should work fine in your panel.

> [!WARNING]
> This is an experimental feature and may contain bugs or some areas missing translations.
> Please report if you find anything.

### 6. Improved TFT transfer

#### TFT file selectors (`ESP-IDF` framework required)
We still working on the Upload TFT engine to make it easier for new and for experienced users.
Now, together with the **Update TFT Display** button, you will find also **Update TFT Display - Model** and **Update TFT Display - Branch** (disabled by default)
where you can select the different model you are using and the upload URL will be automatically adjusted to donwload the file directly from the repository on GitHub,
making this process much easier and removing the need of flashing your device every time you want to play with another TFT file or install the `nspanel_blank.tft`.

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/73d5e552-f52f-41ee-8008-136596035004)

If you have issues with the remote file and want to transfer it from your local server just as before, simply select **Use nextion_update_url** in **Update TFT Display - Model**.

And you also can use the `esphome.xxxxx_upload_tft_url` service to upload using an alternative URL without the need of flash your panel again.

#### Alternative baud rate for TFT uploads
You can select an alternative baud rate for your TFT uploads.
This allows faster TFT uploads and also supports displays previously set with baud rates not supported by this project (currently 115200 bps and 921600 bps).

In most cases, this would be set for a higher value to enable faster TFT transfer.
The default is 921600 bps, the maximum supported by Nextion displays.

You can also use this if you have issues with TFT transfer and want to try a lower baud rate as in some rare cases Nextion will automatically set itself to 9600 bps.

To enable an alternative upload TFT baud rate, add the desired value in your substitutions like this:

```yaml
  upload_tft_baud_rate: "9600"
```

If an invalid value is entered, 115200 bps will be used.
The default value for this substitution (in case it is not set by users) will be 921600 bps.

During a TFT transfer, the system will always fall back to the standard baud rate (115200 bps) if other tentatives fails.

### 7. Multiple Alarm Control Panels
Now alarm control panel entities can be assigned to chips and custom buttons in the Home page,
but also to hardware buttons, any of the buttons pages or entities pages, similarly to other domains.

### 8. Support to `remote`
Entities from the `remote` domain can now be assigned to buttons (hardware and buttons pages) and custom buttons (home and climate pages).

The service `remote.toggle` will be called when the button is pressed.

### 9. Home page chips now supports covers
That's it!
Chips now include cover visualization, allowing for easy monitoring of covers directly from the Home page.

### 10. Chips can be inverted
Chips now have an 'invert' option on the blueprint settings, providing additional customization flexibility.

### 11. Add swipe control to Screensaver page
You can now navigate to button pages from the screensaver while your panel is in sleep mode.
The swipe controls will function as they do on the Home page.

### 12. Enhanced control for automation entities on buttons
We're pleased to announce a new feature that offers users enhanced control over their smart home setups.
Now, you can globally select between **Toggle** and **Trigger** actions for button presses on automation entities.
This update allows for a more personalized and efficient control experience, tailored to your unique preferences.

#### Key features
- **Toggle:** This action will enable or disable the automation.
It is set as the default option.
- **Trigger:** This action will execute the automation regardless of its current state, providing more flexibility.

#### How to use
1. Access your configuration for automation under **Services** > **Automations & Scenes**.
Select the automation associated with your panel setup.
1. Scroll to the **ADVANCED SETTINGS** section at the end.
1. From the menu, select your desired action - either **Toggle** or **Trigger**.
1. Apply the setting.
This will then be effective across all relevant entities.

This update is specially designed to cater to diverse user needs, ensuring a more intuitive and responsive smart home experience.

### 13. Dual thermostat controller support (add-on)
This new add-on enables the NSPanel to manage both heating and cooling systems simultaneously, utilizing its dual relay functionality.

#### Key Benefits
- **Versatility:** Users can now configure their NSPanel to control both a heater and a cooler, offering increased flexibility in home temperature management.
- **Efficiency:** With the ability to control both heating and cooling systems, the NSPanel can more effectively maintain desired temperatures, potentially leading to energy savings.
- **User Experience:** This update simplifies the user interface by integrating control of both systems into one panel, making it easier to manage home climate.

#### Implementation Details
- The dual thermostat controller functionality allows the NSPanel to utilize both of its relays for separate heating and cooling control.

  Users can configure their heating and cooling settings independently, providing a tailored climate control experience.
- The update is designed to be intuitive and user-friendly, ensuring a seamless transition for existing NSPanel users.
- Additional Documentation: For detailed instructions and configurations, refer to the updated [add-on climate documentation](docs/addon_climate.md).

> [!NOTE]
> This feature enhances the capabilities of the NSPanel without compromising its existing functionalities.
> Users who previously used the NSPanel for single-mode (either heating or cooling) control can
> now explore dual-mode options for a more comprehensive climate control solution.

### 14. Enhanced Climate Page for Dual Thermostat Control
Leveraging the capabilities introduced with the Dual Thermostat Controller add-on,
the existing climate page has been upgraded to support systems with dual temperature settings.
This enhancement allows users to effectively manage thermostats that require both heating and cooling target temperatures, directly from the NSPanel's interface.
While originally developed to complement the new add-on,
this refined climate page also seamlessly extends its functionality to existing thermostats with dual set capabilities,
offering a more versatile and comprehensive climate control experience.

### 15. Enhanced timeout flexibility for Sleep, Page fallback, and Dimming settings
We have improved the functionality of our system by enhancing the timeout flexibility for Sleep, Page Fallback, and Dimming settings.
The previous timeout limit of 300 seconds has been significantly expanded, offering users more control and customization options for these specific features.
This enhancement allows for a wider range of use cases, catering to the needs of those who require extended periods for these settings,
while still maintaining the option for shorter durations.

### 16. Display time on the `screensaver` page
In this release, we're excited to introduce a new feature that adds a display time function to the Screensaver page.
With this update, our screensaver not only serves its primary purpose of saving screen energy but also doubles as an informative display,
reflecting our commitment to creating practical, user-friendly solutions.

You can enable this feature on the bueprint settings, at the **CUSTOM CONFIGURATION** section (almost at the end).
You also have to set **Display Brightness Sleep** at the device's page (**Settings** > **Devices & Services** > **ESPHome**).

## Patch v4.2.1
This patch introduces minor updates aimed at enhancing the user experience and improving documentation.
Below you'll find a detailed list of the changes.
While this update is designed to integrate smoothly with existing v4.2 components,
we recommend updating all components to this latest version for the best performance.

**Overview of Changes:**
| Change | Criticality | Affected Components |
| :-- | :--: | :--: |
| Resolved issue with the dimming feature not activating when button is held (#1599) | Minor | `Blueprint` |
| Added "Clean Build Files" step to the update instructions for clarity (#1601) | Minor | `Documentation` |

**Key Improvements:**
- **Dimming Feature Fix**: Addressed an issue where the long press in the buttons was not responding as expected,
ensuring smoother light control from your panel.
- **Updated Documentation**: Enhanced our update instructions to include a "Clean Build Files" step,
providing clearer guidance for a more efficient update process.

## Patch v4.2.2
This update focuses on enhancing user customization, improving data management, and addressing a range of issues from minor to critical in our system.
Our commitment is to continuously enhance the usability, stability, and efficiency of your panel.

> [!IMPORTANT]
> **Breaking Change**: This patch requires Home Assistant v2023.12.0 or higher to ensure compatibility with new enhancements.
> Please update your Home Assistant installation before applying this patch.

We encourage all users to update their components to this latest version for the best experience.
While this update is compatible with existing v4.2 components, it offers optimized performance and usability when fully updated.

**Overview of Changes:**
| Change | Criticality | Affected Components |
| :-- | :--: | :--: |
| Fix Climate page not working with embedded climate (#1627) | Critical | `ESPHome` |
| Fix weather pages crashing when Home Assistant OS is not used (#1630) | Medium | `Blueprint` |
| Correct Wi-Fi reference in QR code example (#1609) | Minor | `Documentation` |
| Resolve incorrect labelling on entity pages (#1628) | Minor | `Blueprint` |
| Address lights with no brightness in 'supported_features' (#1633) | Minor | `Blueprint` |
| Implement ISO8601 date formatting option (#1610) | Enhancement | `Blueprint` |
| Enable dynamic icons based on device_class (#1635) | Enhancement | `Blueprint` |

**Key Improvements:**
- **Fix for Climate Page Not Working**: Resolved a critical issue with the climate page not functioning properly when using embedded climate controls (#1627).
This fix enhances system stability and user interaction with climate features.
- **Fix for Weather Pages Crashing**: Addressed an issue causing weather pages to crash when Home Assistant Operating System (HAOS) is not used (#1630).
This fix ensures stability and reliability of weather-related features across various Home Assistant installation modes, such as containerized installations and other setups.
- **Wi-Fi Reference Update in QR Code Example**: Updated the Wi-Fi reference in the QR code example (#1609) to prevent user errors during system setup.
This documentation change aids in clearer guidance for configuring connections.
- **Entity Pages Configuration Labeling**: Corrected the labeling of options in the blueprint for entity page configuration (#1628).
This fix ensures that the labels accurately reflect the behavior on the pages, enhancing the configuration experience.
- **Handling Lights Without Brightness Feature**: Improved handling of information for lights that lack brightness control in 'supported_features' (#1633).
This update resolves the issue of incorrectly displaying brightness levels (as "0%") for lights that do not support brightness adjustment, ensuring more accurate display of buttons.
- **ISO8601 Date Formatting**: Introduced ISO8601 date formatting (#1610) to improve date readability and consistency in the user interface.
- **Dynamic Icons Using Device Class**: Upgraded dynamic icons to utilize device_class (#1635), offering a more intuitive and context-aware UI.

For support, feedback, or detailed information about this update,
visit our [GitHub repository](https://github.com/Blackymas/NSPanel_HA_Blueprint)
or our [online documentation](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/README.md).

Special thanks to @PaulAntonDeen and @illuzn for their invaluable contributions to these enhancements.
Your feedback and support are crucial to our continuous improvement.

## Patch v4.2.3
This release focuses on targeted bug fixes and enhancements to enhance system stability and functionality.
Major updates include a critical fix for an issue where the panel was getting warmer,
potentially affecting temperature measurements, and resolving a crash issue associated with climate entity rendering.
Additionally, this update introduces new Dutch/Italian date formats for improved localization,
and addresses a minor display issue with the battery indicator on cover pages.

> [!IMPORTANT]
> **Breaking Change**: If you are using the [Customization "Set display as a light"](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/customization.md#set-display-as-a-light),
> please update the code related to the extension to `script`/`set_brightness` as the global variable `display_last_brightness` was replaced by the new sensor `current_brightness`.

We highly recommend all users update their components to this latest version for an optimized and enhanced user experience.
While this update is compatible with existing v4.2 components, fully updating ensures the best performance and usability.

**Overview of Changes:**
<!-- markdownlint-disable MD013 MD033 -->
| Change | Criticality | Affected Components |
| :-- | :--: | :--: |
| Fix device temperature gap since v4.2 (#1620) | Critical | `Blueprint`<br>`ESPHome`<br>`TFT` |
| Fix crash when rendering a climate entity with no `hvac_action` (#1647) | Critical | `Blueprint` |
| Fix battery indicator not showing on cover pages (#1661) | Minor | `Blueprint` |
| Add Dutch/Italian date format (#1658) | Enhancement | `Blueprint` |
<!-- markdownlint-enable MD013 MD033 -->

**Key Improvements:**
- **Fix for Device Temperature Gap**: Resolved a critical issue with the panel getting warmer on v4.2, potentially affecting its temperature measurements.
- **Fix for Crash When Rendering Climate Entities**: Resolves a critical issue where the blueprint was crashing when trying to render icons for climate entities with no `hvac_action` attributes,
preventing pages from being fully loaded.
- **Fix for Battery Indicator**: Addressed the issue where the battery indicator was not displayed correctly on cover pages. As a bonus, the icon now changes based on the battery level. 😉
- **Add Dutch/Italian Date Format**: Expanding the existing pre-listed date formats, we've added the **Weekday, DD-MM (ex. "Friday, 22-03")** format.
This enhancement caters to our Dutch and Italian users, adding a touch of local flair to their experience.

A special thanks to the community for their support and contributions,
especially to @andythomas for providing useful, informative, and visually appealing temperature trend plots,
and to @shing6326 for their dedicated efforts in resolving the crashes with climate entities.
Your contributions significantly enhance the quality of our project.

For support, feedback, or detailed information about this update,
visit our [GitHub repository](https://github.com/Blackymas/NSPanel_HA_Blueprint)
or our [online documentation](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/README.md).

## Patch v4.2.4
In this update, we have focused on addressing critical issues to enhance the reliability and performance of our system.

We highly recommend all users update their components to this latest version for an optimized and enhanced user experience.
While this update is compatible with existing v4.2 components, fully updating ensures the best performance and usability.

**Overview of Changes:**
<!-- markdownlint-disable MD013 MD033 -->
| Change | Criticality | Affected Components |
| :-- | :--: | :--: |
| Nextion is not connected for too long time on boot (#1667 & #1674) | Critical | `TFT` |
| Panel not starting when no climate entity is selected (#1676 & #1677) | Critical | `Blueprint` |
<!-- markdownlint-enable MD013 MD033 -->

**Key Improvements:**
- **Fix for Panel Long Boot Process**: Resolved an issue with the panel taking an excessively long time on the Boot page ("Initializing..."),
ensuring a quicker startup and more efficient operation.
- **Fix for Panel Not Starting Without Climate Entity**: Addressed a critical issue where the panel would not start if no climate entity was selected.
This fix ensures smooth operation and startup of the panel regardless of the climate entity configuration.

For support, feedback, or detailed information about this update,
visit our [GitHub repository](https://github.com/Blackymas/NSPanel_HA_Blueprint)
or our [online documentation](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/README.md).

## What's Next?
Discover what's next and what we are working on right now in our [Milestones](https://github.com/Blackymas/NSPanel_HA_Blueprint/milestones?direction=asc&sort=title&state=open).

## Special thanks to
- @bluefoxlee:
    - For the CJK fonts and all the support with #1359
    - Update T.Chinese translation and Zi fonts, #1453
    - Update CJK fonts and T.Chinese translation, #1532
    - Update CJK character set for future reference, #1589
- @Floppe - Fix entity pages labels, #1455
- @tikismoke - Customization guide: Exposing relay fallback switch to Home Assistant, #1537
- @andythomas:
    - Allow to set upper and lower set points for embedded thermostat, #1573
    - Bugfix for embedded climate/cool functionality, #1587
- @PaulAntonDeen:
    - Add ISO8601 date formatting as an option, #1610 - Patch v4.2.2
    - Fix Wi-Fi reference on QR code example, #1609 - Patch v4.2.2
- @illuzn:
    - Fix for Lights with no brightness supported_features, #1633 - Patch v4.2.2
    - Implement dynamic icons and use device_class, #1635 - Patch v4.2.2
    - Fixes the incorrect labelling of the entity pages alignment, #1628 - Patch v4.2.2
- @bkbartk - Add Dutch/Italian date format, #1658 - Patch v4.2.3
- @shing6326 - Fix crash on climate page, fix climate icon and color, #1649 - Patch v4.2.3
- And to all users who helped with the tests during development and beta.

## Previous releases
- [v4.2.3 - Bug fixes and minor enhancements](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2.3)
- [v4.2.2 - Bug fixes and minor enhancements](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2.2)
- [v4.2.1 - Bug fixes](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2.1)
- [v4.2 - Multi-Alarm Control, Dual Thermostat Functionality, and More](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2)
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
