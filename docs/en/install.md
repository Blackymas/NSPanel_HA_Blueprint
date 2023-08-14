

This section covers the initial configuration. All important steps for installation and setup of ESPHome and the Blueprint are described here.&nbsp;

⭐ **_Step by Step [Setup Video](https://www.youtube.com/watch?v=jpSTA_ILB8g)_**


&nbsp;
> ### _**ATTENTION! if you have already installed the version "nspanel-lovelace-ui" from joBr99 on your NSPanel, an intermediate step is necessary - otherwise it is not possible to install this or any other version.**_ 

&nbsp;
> ### _**NOTE! All documentation are written in DE and then translated into EN. Since we are not EN native speakers, there may well be errors in translation or sentence structure. If something is wrong or unclear an "Issues" can be opened. If you want to help us, we are also looking for someone who would like to do the translation from DE to EN.**_ 

&nbsp;  
&nbsp;  

***

&nbsp;   
# Content:

1. [Short version of the setup of Esphome and Blueprint](#1-short-version-of-the-setup-of-esphome-and-blueprint)
2. [Version "nspanel-lovelace-ui" by joBr99 was previously installed](#2-version-nspanel-lovelace-ui-by-jobr99-was-previously-installed)
3. [Advanced configuration for all ESPHome and Home Assistant professionals](#3-advanced-configuration-for-all-esphome-and-home-assistant-professionals)
4. [Step by Step Configuration and setup of ESPHome and Blueprint](#4-step-by-step-configuration-and-setup-of-esphome-and-blueprint)

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


> ⚠️ _**ATTENTION!**_ for _**"device_name"**_ max. 15 characters _**[a-z], [0-9] and [\_]**_ may be used and all must be _**"lowercase"**_. Furthermore, characters like _**[-], [SPECIAL CHARACTARS] and [SPACES]**_ are forbidden and will cause problems with the blueprint.

**Example:** _**nspanel_blackymas**_

&nbsp;
### CODE:
```yaml
substitutions:
  ###### CHANGE ME - START ######
  device_name: "YOUR_NSPANEL_NAME" 
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  nextion_update_url: "http://homeassistant.local:8123/local/nspanel_eu.tft"
  
  ##### addon-configuration #####
  ## addon_climate ##
  # addon_climate_heater_relay: "1" # possible values: 1/2
  
  ## addon_xx
  # addon_xx_yy: "true" # possible values true/false
  ##### CHANGE ME - END #####


##### DO NOT CHANGE ANYTHING! #####
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml
      #- nspanel_esphome_addon_climate.yaml # activate local climate-control
    refresh: 300s
##### DO NOT CHANGE ANYTHING! #####
```

> At **_http://HOME-ASSISTANT-IP:8123/local/nspanel.tft_** you have to enter your _**IP from Home Assistant**_.

> This could look like this **_http://192.168.1.1:8123/local/nspanel_us.tft_** 

> ⚠️ _**ATTENTION!**_ You can also comment out the path nextion_update_url: "https://raw.githubusercontent.com/Blackymas/NSPanel_HA_Blueprint/main/nspanel_us.tft" and load the TFT directly from Github. But it can happen that there are problems with the upload to the NSPanel. This depends on your internet and wifi. For more information on this issue, see the issue page on Github. It should then look like this

```yaml
#  nextion_update_url: "http://HOME-ASSISTANT-IP:8123/local/nspanel_us.tft" # URL to local tft File
  nextion_update_url: "https://raw.githubusercontent.com/Blackymas/NSPanel_HA_Blueprint/main/nspanel_us.tft"
```

>  _⚠️ **Attention**_if you want to use the European Layout of the NSPanel, you must use "nspanel_eu.tft" instead of "nspanel_us.tft"!

&nbsp;

#### 6. Now the NSPanel can be flashed with the new ESPHome code. 
> how to flash the NSPanel you can see here [HowTo - Flash NSPanel with ESPhome](https://www.youtube.com/watch?v=jpSTA_ILB8g)

#### 7. After the NSPanel is flashed, you can go to _**"Settings --> Devices & Services --> Add Integration"**_ to add your new device and finish setting it up.

#### 8. In the last step, only the TFT must be uploaded. To do this, open your new device in the ESPHome integration and activate the item _**"Update TFT display "**_ under _**"Configuration"**_. Now the current TFT file is loaded from local Home Assistant Server or Github and uploaded to your NSPanel. _**ATTENTION!**_ this process may take a moment.

#### 9. now the setup of ESPHome and NSPanel is completed.

#### 10. Now you can configure your NSPanel via the Blueprint. To do this, go to _**"Settings --> Automations & Scenes --> Templates --> NSPanel Configuration --> CREATE AUTOMATION"**_ and start with the setup of the NSPanel.

> _**NOTE!**_ In the blueprint, in the _**"ESPHOME Node Name"**_ field, enter exactly the same name that you assigned in the _**"ESPHome File"**_.

> **Example:** _**nspanel_blackymas**_

&nbsp;  
&nbsp;  

***

&nbsp;  
&nbsp; 
##  2. Version "nspanel-lovelace-ui" by joBr99 was previously installed
See [(EN) Common Issues | TFT Upload When nspanel lovelace ui has been installed](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-Common-Issues-TFT-Upload-When-nspanel-lovelace-ui-has-been-installed)

&nbsp;  
&nbsp;  

***

&nbsp;  
&nbsp; 
##  3. Advanced configuration for all ESPHome and Home Assistant professionals

* Blueprint file _**"nspnael_blueprint.yaml "**_ can also be installed manually.
* ESPHome file_**"nspanel_esphome.yaml "**_ can also be installed manually. This allows to activate or add more _**"Advanced "**_ configurations.
* There is also the possibility to upload the TFT file _**"nspanel_us.tft "**_ manually. The whole thing can also be combined with a _**"Folder Watcher "**_.
* additionally we provide the HMI file _**"nspanel_us.HMI "**_ for the Nextion Editor to customize graphics and programming if needed

> _**ATTENTION!**_ If you use this mode, you should know what you are doing. We do not give support here!






&nbsp;  
&nbsp;  

***

&nbsp;  
&nbsp;  
##  4. Step by Step Configuration and setup of ESPHome and Blueprint
> _**(for all those who are new to ESPhome or have no experience yet)**_