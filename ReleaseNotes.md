# v4.3 - TItle to be defined

## Support this project
**As always, we would like to thank everyone who donated to this project and remind you that every donation helps to support this project
So if you haven't made a donation yet, now would be a good time ;)**

[![Paypal](https://user-images.githubusercontent.com/41958506/212499642-b2fd097a-0938-4bfc-b37b-74df64592c58.png)](https://www.paypal.com/donate/?hosted_button_id=S974SWQMB8PB2)

## General
MUST BE UPDATED.

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
1. nspanel_eu.tft,  nspanel_us.tft or nspanel_us_land.tft - v4.3
2. nspanel_esphome.yaml - v4.3
3. nspanel_blueprint.yaml - v4.3

### Instructions
 *You can find the update procedures following here:*

- [How To - All important thing you should know - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/howto.md#update-blueprint)

## Breaking changes
1. **Default framework changed to `esp-idf`**. Please follow instructions bellow for more details on how to proceed.
2. **All services have changed**. If you are using the services directly in your automations, please look at our [API documentation](docs/api.md).

    We understand this change can require substantial work on the exisiting automations with direct calls to the panel's services,
    however this will significantly improve the future customizations by providing compreensive documentation, standardizing and optimizing services calls.
3. **`captive_portal` and `web_server` are back to basic package**. If you want to remove those to free-up memory,
please look at "[Customizations - Remove non-essential components](docs/customization.md#remove-non-essential-components)".
4. **15s hardware button press no longer restarts the device** as the benefits of this were too small compared to leaving the button available for other uses.
If you still want the 15s restart behaviour, you can look at "[Customizations - Restart with 15s button press](docs/customization.md#restart-with-15s-button-press) and,
in addition to that, the [reset pin in the bottom of your panel](docs/pics/eu_reset_button.png) can be used.

## Overview of noteworthy changes
1. New default framework
2. Performance improvements
3. New API documentation

## Details of noteworthy changes

### 1. New default framework
Some text

### 2. Performance improvements
Some text

## Support
For support, feedback, or detailed information about this update,
visit our [GitHub repository](https://github.com/Blackymas/NSPanel_HA_Blueprint)
or our [online documentation](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/README.md).

## What's Next?
Discover what's next and what we are working on right now in our [Milestones](https://github.com/Blackymas/NSPanel_HA_Blueprint/milestones?direction=asc&sort=title&state=open).

## Special thanks to

## Previous releases
- [v4.2.4 - Critical bug fixes](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases/tag/v4.2.4)
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
