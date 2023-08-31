# NSPanel Custom with HA Blueprint

*You use our NSPanel version and are satisfied with it? Then we would be very happy about a donation to support our project.*

[![Paypal](https://user-images.githubusercontent.com/41958506/212499642-b2fd097a-0938-4bfc-b37b-74df64592c58.png)](https://www.paypal.com/donate/?hosted_button_id=S974SWQMB8PB2)

[![Open your Home Assistant instance and show the blueprint import dialog with a specific blueprint pre-filled.](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https%3A%2F%2Fgithub.com%2FBlackymas%2FNSPanel_HA_Blueprint%2Fblob%2Fmain%2Fnspanel_blueprint.yaml)

This project allows you to configure your complete NSPanel via a Blueprint with UI.
### *That means you don't have to customize any code or change any lines in the code.*

So you have a nice graphical interface where you can build your NSPanel.
And the best thing is, the installation takes only a few minutes.

The goal was to create a version that allows everyone to use the NSpanel fully local without having to deal with programming or reading hours of documentation - *AND YES WE DID IT!!!!* ;)

📕 Full documentation and installation is available here [NSPanel Configuration, Setup and HowTo](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki).

📌 Step by Step - [Setup and Overview Video´s](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki)

🚀 How to create "Issues" when I have a problem [WIKI HowTo](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki)

⭐ All Feature Requests can be found here [All Feature Request](https://github.com/Blackymas/NSPanel_HA_Blueprint/labels/new%20feature%20request)

🎉 Roadmap Roadmap can be found here [Roadmap](https://github.com/Blackymas/NSPanel_HA_Blueprint/labels/roadmap)

💥 Please move pull request to DEV branch and not to main branch - thanks!

🙋 WE ARE LOOKING FOR YOU! _**We are always looking for people who would like to support this project. We are looking for help with "programming new features, writing documentation or translating documentation to EN. If you are interested then please contact us :)**_

&nbsp;
## NSPanel:
![2 Home](https://user-images.githubusercontent.com/41958506/212768891-9610d800-43c5-454f-a8b6-6b7c43677b5d.png)


![3 Buttonpage](https://user-images.githubusercontent.com/41958506/203654022-c6d81263-ce56-4a84-917a-9d4911f19f55.png)
![NEW Domains](https://user-images.githubusercontent.com/41958506/206879659-3aea30c1-b126-4d52-a869-abf6adfc8fa1.png)

(Home and Button page)


![4 lightsetting 1](https://user-images.githubusercontent.com/41958506/203654055-943d1910-7673-4d9f-ad81-7ef00d155e5a.png)
![5 Lightsetting 2](https://user-images.githubusercontent.com/41958506/203654076-93e110df-f314-4cf1-8500-ed667f2202fd.png)

(Light settings - Brightness and TEMP Color)


![6 Lightsetting 3](https://user-images.githubusercontent.com/41958506/203654179-f7303b02-c886-4890-b976-cb498940a627.png)
![7 Thermostat](https://user-images.githubusercontent.com/41958506/203654189-4294b634-430f-423c-b170-9f1680f94b0e.png)

(Light color wheel and Thermostat)


![8 Cover](https://user-images.githubusercontent.com/41958506/203654290-c6ec2f2f-7924-492c-914c-0d96dc3907e0.png)
![9 Weather](https://user-images.githubusercontent.com/41958506/203654307-24000d00-b7e1-47eb-bd64-9e97b508db52.png)

(Cover settings and Weather forecast)


![10 Settings](https://user-images.githubusercontent.com/41958506/203654386-e4e574ad-8674-4268-84dd-1c4e40f98eb9.png)
![1 Boot](https://user-images.githubusercontent.com/41958506/203667473-d33523a4-3197-4838-9099-cccebfc727db.png)

(NSPanel settings and Boot screen)


![Device Setting 1](https://user-images.githubusercontent.com/41958506/203723223-8afc0e44-51cf-49ed-8a49-8ba713716639.png)
![Device Setting 2](https://user-images.githubusercontent.com/41958506/203724491-53ecd93d-bc7c-4c2d-850b-f106691e2639.png)


(HA device settings - Temperature correction)

&nbsp;
## Blueprint:
![Blueprint 1](https://user-images.githubusercontent.com/41958506/203655004-a11f5a1c-d098-4e1a-958a-0293e50000b2.png)
![Blueprint 2](https://user-images.githubusercontent.com/41958506/203655014-e6cae9df-aaf8-4537-8165-b8f44a177d3b.png)


&nbsp;
## Features:
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

&nbsp;
## Pages

### Home
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
- Light current state
- Brightness slider
- RGB color wheel
- Color temperature slider
- Jump back to the right button page

&nbsp;
### Cover Settings
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
- Restart NSPanel
- Sleep mode - Turn off display after given time (seconds)
- Display brightness slider
- Display dim brightness slider


&nbsp;
## Thanks to:
SmartHome Yourself: https://www.youtube.com/c/SmarthomeyourselfDe_DIY

Masto: https://github.com/masto/NSPanel-Demo-Files

Marcfager:  https://github.com/marcfager/nspanel-mf

lovejoy77: https://github.com/lovejoy777/NSpanel

Hellis81: https://github.com/Hellis81/NS-panel

