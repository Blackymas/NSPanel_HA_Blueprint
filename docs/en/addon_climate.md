# Add-on: Climate

## Description
This add-on enables the use of your panel's relays to act as a thermostat (heater only for now) using the internal temperature sensor and independent of the network availability.

### Attention
The NSPanel is limited to 2A per relay. Don't use it for directly power your heater if exceeding the panel specifications:
- 150W/110V/Gang, 300W/110V/Total
- 300W/220V/Gang, 600W/220V/Total
More details on the [Sonoff NSPanel's page](https://sonoff.tech/product/central-control-panel/nspanel/) and the [product specifications document](https://sonoff.tech/wp-content/uploads/2021/11/%E4%BA%A7%E5%93%81%E5%8F%82%E6%95%B0%E8%A1%A8-NSPanel-20210831.pdf).

&nbsp;
## Installation
You will need to add the reference to the `addon_climate` file on your ESPHome settings in the `package` section and after te `remote_package` (base code), as shown bellow:

```yaml
substitutions:
  ###### CHANGE ME START ######
  device_name: "YOUR_NSPANEL_NAME" 
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  nextion_update_url: "http://homeassistant.local:8123/local/nspanel_eu.tft"
  
  addon_climate_heater_relay: "1"
  ##### CHANGE ME END #####


packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files: [nspanel_esphome.yaml]
    refresh: 300s

  addon_climate:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files: [nspanel_esphome_addon_climate.yaml]
    refresh: 300s	
```
&nbsp;
## Configuration

The following keys are available to be used in your `substitutions`:

|Key|Required|Supported values|Default|Description|
|:-|:-:|:-:|:-:|:-|
|addon_climate_heater_relay|Mandatory|`1` or `2`|`0` (disabled)|Relay used for conrol the heater. User `1` for "Relay 1" or `2` for "Relay 2".|
|addon_climate_temp_units|Optional|`°C` or `°F`|`°C`|Temperature unit.|
|addon_climate_min_heating_off_time|Optional|Positive integer representing the number of seconds|`300`|Minimum duration (in seconds) the heating action must be disengaged before it may be engaged.|
|addon_climate_min_heating_run_time|Optional|Positive integer representing the number of seconds|`300`|Minimum duration (in seconds) the heating action must be engaged before it may be disengaged.|
|addon_climate_min_idle_time|Optional|Positive integer representing the number of seconds|`30`|Minimum duration (in seconds) the idle action must be active before calling another climate action.|
|addon_climate_visual_min_temperature|Optional|Number representing a temperature in the selected unit|`5`|The minimum temperature the climate device can reach. Used to set the range of the frontend gauge.|
|addon_climate_visual_max_temperature|Optional|Number representing a temperature in the selected unit|`25`|The maximum temperature the climate device can reach. Used to set the range of the frontend gauge.|
|addon_climate_visual_temperature_step|Optional|Number representing a temperature in the selected unit|`0.5`|The granularity with which the target temperature can be controlled.|

- All values must be delimited with `""`
- For more details on the keys, please take a look at [ESPHome Base Climate Configurations](https://esphome.io/components/climate/index.html#base-climate-configuration) and [ESPHome Climate Thermostat - Additional actions behavior](https://esphome.io/components/climate/thermostat.html#additional-actions-behavior).

### Example:


```yaml
substitutions:
  ###### CHANGE ME START ######
  device_name: "YOUR_NSPANEL_NAME" 
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  nextion_update_url: "http://homeassistant.local:8123/local/nspanel_us.tft"

  addon_climate_heater_relay: "1" #Use relay 1
  addon_climate_temp_units: "°F" #Temperatures in Fahrenheit
  addon_climate_visual_min_temperature: "40" #Min supported temperature is 40F
  addon_climate_visual_max_temperature: "80" #Max supported temperature is 80F
  addon_climate_visual_temperature_step: "1" #Temperature granularity is 1F
    
  ##### CHANGE ME END #####


packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files: [nspanel_esphome.yaml]
    refresh: 300s

  addon_climate:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files: [nspanel_esphome_addon_climate.yaml]
    refresh: 300s	
```

