# Getting Started with NSPanel HA Blueprint
Welcome to this setup guide, a community-driven approach to integrating NSPanel into your smart home. Designed for users at all levels, it combines Home Assistant's user-friendly interface with ESPHome's customization options.

Whether you're a first-time smart device user or an enthusiast looking to personalize your setup, this guide provides the necessary tools and instructions. Let's embark on creating a smart home that's uniquely yours.

## Preparation
Start by ensuring you have all the necessary tools and files. This includes your NSPanel device, a stable internet connection, and access to your Home Assistant server.

## ESPHome firmware
### Setup a device on ESPHome dashboard
![image](pics/ha_esphome_dashboard_new_device_01.png)
![image](pics/ha_esphome_dashboard_new_device_02.png)
![image](pics/ha_esphome_dashboard_new_device_03.png)
![image](pics/ha_esphome_dashboard_new_device_04.png)
![image](pics/ha_esphome_dashboard_new_device_05.png)
![image](pics/ha_esphome_dashboard_new_device_06.png)
![image](pics/ha_esphome_dashboard_new_device_07.png)

### Flashing the device for the first time
### Making changes Over The Air (OTA)
### Updating
### Migrating from other custom firmware

## Upload TFT
### Select the right file
### Uploading to Nextion

## Blueprint
### Importing the blueprint
### Creating an automation
### Selecting the panel

## How to handle multiple panels

## Additional info



===================================== TO BE REMOVED =====================================
This section covers the initial configuration. All important steps for installation and setup of ESPHome and the Blueprint are described here.&nbsp;

⭐ **_Step by Step [Setup Video](https://www.youtube.com/watch?v=jpSTA_ILB8g)_**


&nbsp;
> _**ATTENTION! if you have already installed the version "nspanel-lovelace-ui" from joBr99 on your NSPanel, an [intermediate step](lovelace_ui.md) is necessary - otherwise it is not possible to install this or any other version.**_ 

&nbsp;
> _**NOTE! We are not EN native speakers, there may well be errors in translation or sentence structure. If something is wrong or unclear an "[Issue](/Blackymas/NSPanel_HA_Blueprint/issues)" can be opened. If you want to help us, feel free to propose a change directly in GitHub or please get in contact with us.**_ 

&nbsp;  
&nbsp;  

***

&nbsp;   
# Content:

1. [Short version of the setup of Esphome and Blueprint](install.md#1-short-version-of-the-setup-of-esphome-and-blueprint)
2. [Version "nspanel-lovelace-ui" by joBr99 was previously installed](install.md#2-version-nspanel-lovelace-ui-by-jobr99-was-previously-installed)
3. [Advanced configuration for all ESPHome and Home Assistant professionals](install.md#3-advanced-configuration-for-all-esphome-and-home-assistant-professionals)
4. [Step by Step Configuration and setup of ESPHome and Blueprint](install.md#4-step-by-step-configuration-and-setup-of-esphome-and-blueprint)

&nbsp;  

***

&nbsp;  
&nbsp;  

## 1. Short version of the setup of Esphome and Blueprint
> _**(for those who already have experience with ESPhome and Home Assistant)**_

#### 1. First you have to install the Blueprint. For this please use the following link

[![Open your Home Assistant instance and show the blueprint import dialog with a specific blueprint pre-filled.](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https%3A%2F%2Fgithub.com%2FBlackymas%2FNSPanel_HA_Blueprint%2Fblob%2Fmain%2Fnspanel_blueprint.yaml)

> It is also possible to copy the code from the file _**"nspnael_blueprint.yaml "**_ and paste it into HA.
> You can find instructions for this under [Using Automation Blueprints](https://www.home-assistant.io/docs/automation/using_blueprints/) and [Automation blueprint tutorial](https://www.home-assistant.io/docs/blueprint/tutorial/#create-the-blueprint-file)

#### 2. You have to download the file **_nspanel_us.tft_** or **_"nspanel_eu.tft"_** from Github

![Bildschirmfoto 2023-01-23 um 21 31 05](https://user-images.githubusercontent.com/41958506/214144182-e2a5f28e-e96d-4263-8c4b-b7fbcc6658e7.png)


#### 3. Upload the file to your **_Home Assistant Server_** in the **_www_** folder, see [Home Assistant HTTP](https://www.home-assistant.io/integrations/http/#hosting-files) 'Hosting Files' section for details.

![Bildschirmfoto 2023-01-23 um 21 33 20](https://user-images.githubusercontent.com/41958506/214144729-08fb5d3f-9255-4f57-9c6e-a5e33665e4df.png)


#### 4. In the next step you have to create a new ESP32 device in ESPHome

#### 5. When the new ESP32 device has been created, next click _**"Edit "**_ on the device you have just created to open the web editor. Now the following code must be copied and pasted.

> ❗ _**IMPORTANT!**_ The already existing code in the ESPHome file must be _**"COMPLETELY "**_ deleted and _**"REPLACED "**_ by the code below.

> ❗ _**IMPORTANT!**_ in the block _**"CHANGE ME "**_ all values _**(device_name, wifi_ssid, wifi_password, nextion_update_url )**_ in the _**" "**_ must be replaced by your own values. It is also possible to work here with _**"!secret "**_.

&nbsp;
### CODE:
```yaml
substitutions:
  ###### CHANGE ME START ######
  device_name: "YOUR_NSPANEL_NAME" 
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  nextion_update_url: "http://homeassistant.local:8123/local/nspanel_eu.tft"
  nextion_blank_url: "http://homeassistant.local:8123/local/nspanel_blank.tft"

  ##### addon-configuration #####
  ## addon_climate ##
  # addon_climate_heater_relay: "1" # possible values: 1/2

  ##### CHANGE ME END #####

packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml # Core package
      # - advanced/esphome/nspanel_esphome_advanced.yaml # activate advanced (legacy) elements - can be useful for troubleshooting
      # - nspanel_esphome_addon_climate_cool.yaml # activate for local climate (cooling) control
      # - nspanel_esphome_addon_climate_heat.yaml # activate for local climate (heater) control
      # - nspanel_esphome_addon_climate_dual.yaml # activate for local climate (dual) control
    refresh: 300s

esp32:
  framework:
    type: esp-idf

##### My customization - Start #####
##### My customization - End #####
```
⚠️ The following TFT files are available and can be replaced in your URL accordingly:
- [`nspanel_eu.tft`](/Blackymas/NSPanel_HA_Blueprint/raw/main/nspanel_eu.tft) (European layout)
- [`nspanel_us.tft`](/Blackymas/NSPanel_HA_Blueprint/raw/main/nspanel_us.tft) (US layout)
- [`nspanel_us_land.tft`](/Blackymas/NSPanel_HA_Blueprint/raw/main/nspanel_us_land.tft) (US layout - landscape orientation)


&nbsp;

#### 6. Now the NSPanel can be flashed with the new ESPHome code. 
> How to flash the NSPanel you can see here: [HowTo - Flash NSPanel with ESPhome](https://www.youtube.com/watch?v=jpSTA_ILB8g)

#### 7. After the NSPanel is flashed, you can go to _**"Settings --> Devices & Services --> Add Integration"**_ to add your new device and finish setting it up.

#### 8. In the last step, only the TFT must be uploaded. To do this, open your new device in the ESPHome integration and activate the item _**"Update TFT display "**_ under _**"Configuration"**_. Now the current TFT file is loaded from local Home Assistant Server or GitHub and uploaded to your NSPanel. _**ATTENTION!**_ This process will take up to 30 minutes.

#### 9. Now the setup of ESPHome and NSPanel is completed.

#### 10. Now you can configure your NSPanel via the Blueprint. To do this, go to _**"Settings --> Automations & Scenes --> Templates --> NSPanel Configuration --> CREATE AUTOMATION"**_ and start with the setup of the NSPanel.

> _**NOTE!**_ In the blueprint, the field _**"NSPanel device"**_ is required. Although you can still save the automation without a device selected, it would be unusable without that information.
&nbsp;  
&nbsp;  

***

&nbsp;  
&nbsp; 
##  2. Version "nspanel-lovelace-ui" by joBr99 was previously installed
See [(EN) Common Issues | TFT Upload When nspanel lovelace ui has been installed](lovelace_ui.md)

&nbsp;  
&nbsp;  

***

&nbsp;  
&nbsp; 
##  3. Advanced configuration for all ESPHome and Home Assistant professionals
> _**ATTENTION!**_ Customizations and advanced mode are not supported by this project's team. Use this with caution and only when you know what you are doing.

Before you start customizing your system, we would like to invite you to share anything nice you achieve. You can always create a new [Pull Request](/Blackymas/NSPanel_HA_Blueprint/pulls) to `dev` branch and this will give a chance for other users with similar challenges to take advantage of your discoveries.

The simpler way to go "advanced" with ESPHome is to use "Customizations". We have a page specifically for that where, again, your contribution is very welcome: [Customization](customization.md)

If you want for some reason use a local copy of `nspanel_esphome.yaml`, you can copy the file from GitHub to you local file system and reference in your ESPHome settings like this:

```yaml
substitutions:
  ###### CHANGE ME START ######
  device_name: office-workstation-panel
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  nextion_update_url: "http://homeassistant.local:8123/local/nspanel_eu.tft"
  nextion_blank_url: "http://homeassistant.local:8123/local/nspanel_blank.tft"

  ##### CHANGE ME END #####

packages:
  local_package: !include packages/nspanel_esphome.yaml

esp32:
  framework:
    type: esp-idf
```
> Note that a sub-folder was used in the example above in order to avoid that file to be added as an additional device in your ESPHome dashboard. You can also have the file in the same folder, but with it's name starting with `.`, so ESPHome dashboard understands that file should be ignored when listing devices.


* Blueprint file _**"nspanel_blueprint.yaml "**_ can also be installed manually.
* There is also the possibility to upload the TFT file _**"nspanel_us.tft "**_ manually. The whole thing can also be combined with a _**"Folder Watcher "**_.
* additionally we provide the HMI files _**"nspanel_xx.HMI "**_ for the Nextion Editor to customize graphics and programming if needed.
