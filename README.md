*Are you happy with our version for NSPanel? Please consider supporting us with a donation.*
<br>[![Paypal](https://user-images.githubusercontent.com/41958506/212499642-b2fd097a-0938-4bfc-b37b-74df64592c58.png)](https://www.paypal.com/donate/?hosted_button_id=S974SWQMB8PB2)

[![Open your Home Assistant instance and show the blueprint import dialog with a specific blueprint pre-filled.](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https%3A%2F%2Fgithub.com%2FBlackymas%2FNSPanel_HA_Blueprint%2Fblob%2Fmain%2Fnspanel_blueprint.yaml)

[![ESPHome (latest)](https://github.com/Blackymas/NSPanel_HA_Blueprint/actions/workflows/validate_esphome.yml/badge.svg)](https://github.com/Blackymas/NSPanel_HA_Blueprint/actions/workflows/validate_esphome.yml)
[![Validate ESPHome (beta)](https://github.com/Blackymas/NSPanel_HA_Blueprint/actions/workflows/validate_esphome_beta.yml/badge.svg)](https://github.com/Blackymas/NSPanel_HA_Blueprint/actions/workflows/validate_esphome_beta.yml)

# NSPanel Custom with HA Blueprint

This innovative solution is designed to revolutionize how you interact with your Sonoff NSPanel. Our goal? To make the customization of your NSPanel seamless, intuitive, and completely code-free!

## Table of Contents
1. [Project Highlights](#-project-highlights)
2. [Documentation & Resources](#-documentation--resources)
3. [Features](#-features)
4. [Pages Overview](#-pages-overview)
5. [Contributing](#-contributing)
6. [Community & Support](#-community--support)
7. [Acknowledgements](#-acknowledgements)
8. [Donations](#-donations)

## 🌟 Project Highlights

- **No Coding Required:** Customize your NSPanel without touching a single line of code. It's all about intuitive, user-friendly experiences!
- **Quick Setup:** Get your NSPanel up and running in minutes with our easy-to-follow graphical interface.
- **Local Control:** Embrace full local control of your NSPanel, steering clear of cloud dependencies.
- **Community-Driven:** A project for the users, by the users. Your contributions shape the future of this project!

## 📚 Documentation & Resources

- **Getting Started:** Dive into our comprehensive [Documentation and Setup Guide](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki) for detailed instructions.
- **Video Tutorial:** Prefer visual learning? Check out our [Step-by-Step Setup Video](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki).
- **Troubleshooting:** Encounter an issue? Here's how to report it: [WIKI HowTo](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki).
- **Feature Requests:** Got ideas? Share them [here](https://github.com/Blackymas/NSPanel_HA_Blueprint/labels/new%20feature%20request).
- **Project Roadmap:** Curious about what's next? Explore our [Roadmap](https://github.com/Blackymas/NSPanel_HA_Blueprint/labels/roadmap).

## 🚀 Features

- Easy to use and simple configuration via Blueprint - no change in the code is necessary
- 32 buttons on 4 button pages with long press function for settings (more buttons are also possible)
- Button design is automatically generated based on the selected entity
- Buttons show current brightness and cover position in the button itself
- Buttons label can be assigned via blueprint
- Weather + 5 days weather forecast
- Thermostat + Touch + [Relay control for floor heating](/docs/en/addon_climate.md)
- Light control (brightness, color and temperature) - via long Press
- Cover control (open, close and position) - via long press
- Settings page (display brightness, display dim brightness, sleep mode, reboot NSPanel)
- Swipe between pages
- Top menu with 10 icons for specific states
- Heating control (hot water)
- Modern design - design easy to change via Adobe Express (free + design template)
- 2 physical switches with optional fallback mode
- and much more ;)


## 📖 Pages Overview


### Home
![2 Home](https://user-images.githubusercontent.com/41958506/212768891-9610d800-43c5-454f-a8b6-6b7c43677b5d.png)

- Current weather with button to Weather Forcast page
- Hardware buttons can be freely assigned
- Hardware button label (optional)
- Blue line indicates the entity's states (`on` or `off`)
- Outside temperature
- Status icons at the top
- Room temperature with button to thermostat page
- Room humidity
- Up to 3 user's selectable entities

&nbsp;
### Button Page
![3 Buttonpage](https://user-images.githubusercontent.com/41958506/203654022-c6d81263-ce56-4a84-917a-9d4911f19f55.png)
![NEW Domains](https://user-images.githubusercontent.com/41958506/206879659-3aea30c1-b126-4d52-a869-abf6adfc8fa1.png)

- Up to 32 buttons
- 4 Button pages
- Button design is automatically generated based on the selected entity
- Buttons show current brightness and cover position in the button itself
- Buttons label can be assigned via blueprint
- All buttons with long press function
- Automatic detection by long press if it is a light, cover or climate for submenu
- Swipe between all pages 
- Swipe also down and up for fast access to certain pages

&nbsp;
### Light Settings
![4 lightsetting 1](https://user-images.githubusercontent.com/41958506/203654055-943d1910-7673-4d9f-ad81-7ef00d155e5a.png)
![5 Lightsetting 2](https://user-images.githubusercontent.com/41958506/203654076-93e110df-f314-4cf1-8500-ed667f2202fd.png)
![6 Lightsetting 3](https://user-images.githubusercontent.com/41958506/203654179-f7303b02-c886-4890-b976-cb498940a627.png)

- Light current state
- Brightness slider
- RGB color wheel
- Color temperature slider
- Jump back to the right button page

&nbsp;
### Cover Settings
![8 Cover](https://user-images.githubusercontent.com/41958506/203654290-c6ec2f2f-7924-492c-914c-0d96dc3907e0.png)

- Open and close cover
- Cover position via slider
- Cover battery value (when available)
- jump back to the right button page

&nbsp;
### Thermostat / Climate
- Target temperature control slider 
- Current temperature
- 4 user's selectable values (for water and external temperatures, etc.)
- All the standard climate controls from Home Assistant (`heat`, `fan`, `cool`, `auto`, `dry`)
- 2 user's selectable buttons
- [Can be used for local control (even when Wi-Fi is unavailable) when your panel's relays are used to control your cooler/heater](/docs/en/addon_climate.md)

&nbsp;
### Fan speed
- Turn-on and turn-off fan
- Set speed via slider or buttons
- jump back to the right button page

&nbsp;
### Alarm
- Arm/disarm an alarm (standard modes supported by Home Assistant)
- Support to numeric pin for arming or disarming


&nbsp;
### Weather Forecast
![9 Weather](https://user-images.githubusercontent.com/41958506/203654307-24000d00-b7e1-47eb-bd64-9e97b508db52.png)

- 5 days weather forecast via swipe (supports most used weather integrations)
- Min and max outside temperatures
- Date
- Other weather parameters (when provided by your integration):
  - Rain probability
  - Sunshine hours
  - UV index
  - Thunderstorm probability
  - Wind speed

&nbsp;
### Display Settings
![10 Settings](https://user-images.githubusercontent.com/41958506/203654386-e4e574ad-8674-4268-84dd-1c4e40f98eb9.png)

- Restart NSPanel
- Display brightness slider
- Display dim brightness slider

### Boot
![1 Boot](https://user-images.githubusercontent.com/41958506/203667473-d33523a4-3197-4838-9099-cccebfc727db.png)

## Home Assistant interface

## Device's page
![Device Setting 1](https://user-images.githubusercontent.com/41958506/203723223-8afc0e44-51cf-49ed-8a49-8ba713716639.png)
![Device Setting 2](https://user-images.githubusercontent.com/41958506/203724491-53ecd93d-bc7c-4c2d-850b-f106691e2639.png)

## Automation (Blueprint)
![Blueprint 1](https://user-images.githubusercontent.com/41958506/203655004-a11f5a1c-d098-4e1a-958a-0293e50000b2.png)
![Blueprint 2](https://user-images.githubusercontent.com/41958506/203655014-e6cae9df-aaf8-4537-8165-b8f44a177d3b.png)


## 🚀 Contributing

- **Pull Requests:** Please direct all pull requests to the `DEV` branch, not the `main` branch.
- **Join Our Team:** We're on the lookout for enthusiasts in programming, documentation, and translation. Interested? Please let us know.

## 🌍 Community & Support

Join our vibrant community! Whether you're seeking support, wanting to contribute, or just looking to share your NSPanel journey, we're here for you.

- **[Issues & Feature requests](https://github.com/Blackymas/NSPanel_HA_Blueprint/issues)**
- **[Discussion Forum](https://github.com/Blackymas/NSPanel_HA_Blueprint/discussions)**
- **[Home Assistant Community](https://community.home-assistant.io/t/sonoff-nspanel-blueprint-configure-your-own-custom-nspanel-easy-via-a-blueprint/500577)**

## 🎉 Acknowledgements

A huge thank you to everyone who has contributed to making this project a reality. Your support, feedback, and contributions have been invaluable.

And special thanks for the other projects which inspired us:
- Hellis81: https://github.com/Hellis81/NS-panel
- Jimmyboy83: https://github.com/Jimmyboy83/nspanel
- joBr99: https://github.com/joBr99/Generate-HASP-Fonts
- lovejoy77: https://github.com/lovejoy777/NSpanel
- Marcfager:  https://github.com/marcfager/nspanel-mf
- Masto: https://github.com/masto/NSPanel-Demo-Files
- sairon: https://github.com/sairon/esphome-nspanel-lovelace-ui
- SmartHome Yourself: https://www.youtube.com/c/SmarthomeyourselfDe_DIY


## 💖 Donations

Are you happy with our version for NSPanel? Please consider supporting us with a donation.

[![Paypal](https://user-images.githubusercontent.com/41958506/212499642-b2fd097a-0938-4bfc-b37b-74df64592c58.png)](https://www.paypal.com/donate/?hosted_button_id=S974SWQMB8PB2)
