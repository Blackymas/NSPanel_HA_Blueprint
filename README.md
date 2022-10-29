# NSPanel Custom with HA Blueprint
Custom Firmware for NsPanel (esphome) and HA Blueprint with configuration of button, light settings, thermostate, colorwheel, colortemp, cover, weather preview, automatic TFT upload etc.

Why another version for the NSPanel? 
Well - all versions I've seen have been missing something everywhere. 
That's why I decided to create something myself.

My thanks to Masto, Marcfager, lovejoy777, Hellis81 and SmartHome yourself ( link see below) for sharing your code. Give them the credit they deserve, I'm merely a copy paste ninja. XDD


### GOAL:
My goal was to create a version that could be quickly adopted for multiple NSPanels.
In addition, the configuration should be as simple as possible. Therefore I decided to put most of it into a HA Blueprint

In addition, another NSPanel can be configured very quickly. But have a look yourself ;)

![My project-1-16](https://user-images.githubusercontent.com/41958506/192649717-6b04cd1a-1829-4fd5-8ba4-09eaf32f85d0.png)
![My project-1-18](https://user-images.githubusercontent.com/41958506/192650810-c7210d15-a07e-4f70-a593-af0a51c7f4bb.png)

(Home / Thermostat - more pictures see below)

## Features:
- easy to use and simple configuration via Blueprint
- 40 buttons on 5 button pages with long press function for settings (more buttons are also possible)
- Weather + 5 days weather forcast
- Thermostat + Touch + Relay control for floor heating
- Light control (brightness-slider, colorwheel, TempColor-slider) - via Long Press
- Cover control (open, close, position-slider) - via long press
- Settings page (display brightness, display dim brightness, auto-dim, sleep mode, reboot NSPanel)
- Swipe between pages
- Top menu with 10 icons for specific states
- Heating control (hot water)
- Auto Upload TFT File to Nextion Display
- Swipe between pages
- modern design - design easy to change via Adobe Express (free + design template)
- 2 pysical switches
- and much more ;)


## NSPanel:
![My project-1-16](https://user-images.githubusercontent.com/41958506/192649717-6b04cd1a-1829-4fd5-8ba4-09eaf32f85d0.png)
![My project-1-17](https://user-images.githubusercontent.com/41958506/192650793-9b657fa2-8056-46d7-aca3-065cde291df8.png)

(Home / Weather Forcast)

![My project-1-18](https://user-images.githubusercontent.com/41958506/192650810-c7210d15-a07e-4f70-a593-af0a51c7f4bb.png)
![My project-1-20](https://user-images.githubusercontent.com/41958506/192652078-ec4f3268-c00b-42a8-b1f9-c4da3e53d7a5.png)

(Thermostat / Settings Page)

![My project-1-22](https://user-images.githubusercontent.com/41958506/192652105-23baac1d-9dee-40c1-8596-9cae8827cf1c.png)
![My project-1-23](https://user-images.githubusercontent.com/41958506/192652116-93b850d3-553b-4f14-bb0f-78dff959e2fd.png)

(Light Settings Colorwheel / Light Settings TempColor)

![My project-1-24](https://user-images.githubusercontent.com/41958506/192652126-91b0aae9-75ae-44a0-842d-0a78d93f2da5.png)
![My project-1-25](https://user-images.githubusercontent.com/41958506/192652131-604c0636-0f96-44b8-ae6a-793bde56d0e1.png)

(Cover Settings / Button Page)

![My project-1-26](https://user-images.githubusercontent.com/41958506/192652263-297cda87-3eff-452c-9ec3-3cd76da94de7.png)

## Blueprint:
![Bildschirmfoto 2022-09-27 um 23 13 33](https://user-images.githubusercontent.com/41958506/192652755-069f91c9-927e-4aea-9569-d596cdfa0e56.png)

# Pages

## Home
- current weather with button to Weather Forcast page
- Temperature outside
- Status icons at the top
- Room temperature with button to thermostat page
- Room humidity
- Hot water temperature
- Button to display settings page

## Weather Forcast
- 5 days Weather Forcast via swipe (Integration Accuweather - but should also go with another integration)
- Lowest and highest temperature outside
- Date
- Rain probability
- Sunshine hours
- Sun pressure 
- Thunderstorm probability
- Wind speed
- Night thunderstorm probability and wind speed

## Thermostat
- Touch Temp control 
- Outside temperature
- Hot water
- Floor heating on, off and idle
- Hot water button
- Status icons

## Display Settings
- Restart NSPanel
- Sleep mode - display off after time X
- Display brightness slider
- Display dim brightness slider
- Status Brightness in %

## Light Settings
- Light on and off (alignment with HA)
- Light color with Colorwheel
- Light color with TempColor slider
- Brightness Slider
- Brightness in %.
- Tempcolor value
- Jump back to the right button page

## Cover Settings
- Open and close cover
- Cover position via slider
- Cover battery value (I use Ikea roller blind)
- jump back to the right button page

## Button Page
- 40 Button
- 5 Button pages
- all buttons with long press function
- automatic detection by long press if it is a light or cover for submenu
- swipe between all pages 
- swipe also down and up for fast access to certain pages
- number of buttons and button pages can be extended - functions like long press, light settings and cover settings stay the same

## Upcoming Features
- Shorten Esphome code and transfer to Blueprint
- Cover page with window open status as image
- small design adjustments
- Notifications on Home Page
- Energy and Gas consumption on home page
- Extra page for energy dashboard
- Garbage plan with icon on home page
- Let's see what ideas I still have ;)

## HowTo Deutsch
1. den Code aus der Datei esphome.yaml kopieren und in HA unter esphome einfügen. Vorher muss natürlich ein Device erstellt werden.
1.2 in der ESPhome Datei müssen Passwörter eingesetzt werden. Entweder in der ESPHome Secret oder einfach in der ESPhome Datei
1.3 Einige Entities sind aktuell noch in der Esphome Datei angegeben (direkt unter den Passwörtern. Diese Entities müssen noch angepasst werden. In zukunft will ich aber auch diese ins Bluebrint einbauen
3. den Code aus der Datei blueprint.yaml kopieren und eine neue yaml Datei unter config/blueprints erstellen und den Code einfügen
4. HA Automationen neu starten -> Enticklerwerkzege -> YAML -> Automatisierungen
5. den Code aus der Datei sensor.yaml und climate.yaml kopieren und eine eigenen yaml Datei erstellen. Der Code wird in zukunft direkt im Blueprint eingebaut.
6. den Code aus der Datei folder_wather kopieren und in der coniguration.yaml einfügen
7. TFT File auf Home Assistant hochladen (Der Pfad kann später im Blueprint angegeben werden
8. Blueprint unter Automationen auswählen und und Felder ausfüllen.



## Thanks to:
SmartHome Yourself: https://www.youtube.com/c/SmarthomeyourselfDe_DIY

Masto: https://github.com/masto/NSPanel-Demo-Files

Marcfager:  https://github.com/marcfager/nspanel-mf

lovejoy77: https://github.com/lovejoy777/NSpanel

Hellis81: https://github.com/Hellis81/NS-panel
