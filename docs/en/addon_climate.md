# Add-on: Climate

## Description
This add-on enables the use of your panel's relays to act as a thermostat (either cooler or heater) using the internal temperature sensor and independent of the network availability.

### Attention
1. The NSPanel is limited to 2A per relay. Don't use it for directly power your cooler/heater if exceeding the panel specifications:
    - 150W/110V/Gang, 300W/110V/Total
    - 300W/220V/Gang, 600W/220V/Total<br>
  - More details on the [Sonoff NSPanel's page](https://sonoff.tech/product/central-control-panel/nspanel/) and the [product specifications document](https://sonoff.tech/wp-content/uploads/2021/11/%E4%BA%A7%E5%93%81%E5%8F%82%E6%95%B0%E8%A1%A8-NSPanel-20210831.pdf).

2. At this moment you have to choose between `heat` or `cool`. The dual/simultaneous operation is not supported at this moment.
3. A target temperature must be set on the climate entity in Home Assistant or the page Climate in your panel.

&nbsp;
## Installation
You will need to add the reference to `addon_climate_heat` or `addon_climate_cool` files on your ESPHome settings in the `package` section and after te `remote_package` (base code), as shown bellow (for `heat` in this example):

```yaml
substitutions:
  ###### CHANGE ME START ######
  device_name: "YOUR_NSPANEL_NAME" 
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  nextion_update_url: "http://homeassistant.local:8123/local/nspanel_eu.tft"
  
  ##### addon-configuration #####
  ## addon_climate ##
  heater_relay: "1" # possible values: 1/2

  ##### CHANGE ME END #####


packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml # Core package
      # - nspanel_esphome_addon_climate_cool.yaml # activate for local climate (cooling) control
      - nspanel_esphome_addon_climate_heat.yaml # activate for local climate (heater) control
      
    refresh: 300s	
```
&nbsp;
## Configuration

The following keys are available to be used in your `substitutions`:

Key|Required|Supported values|Default|Description
:-|:-:|:-:|:-:|:-
cooler_relay|Mandatory for `cool`|`1` or `2`|`0` (disabled)|Relay used for control the cooler. User `1` for "Relay 1" or `2` for "Relay 2".
heater_relay|Mandatory for `heat`|`1` or `2`|`0` (disabled)|Relay used for control the heater. User `1` for "Relay 1" or `2` for "Relay 2".
temp_units|Optional|`°C` or `°F`|`°C`|Temperature unit.
min_off_time|Optional|Positive integer representing the number of seconds|`300`|Minimum duration (in seconds) the cooling/heating action must be disengaged before it may be engaged.
min_run_time|Optional|Positive integer representing the number of seconds|`300`|Minimum duration (in seconds) the cooling/heating action must be engaged before it may be disengaged.
min_idle_time|Optional|Positive integer representing the number of seconds|`30`|Minimum duration (in seconds) the idle action must be active before calling another climate action.
temp_min|Optional|Number representing a temperature in the selected unit|`15` for `cool`, `5` for `heat`|The minimum temperature the climate device can reach. Used to set the range of the frontend gauge.
temp_max|Optional|Number representing a temperature in the selected unit|`45` for `cool`, `25` for `heat`|The maximum temperature the climate device can reach. Used to set the range of the frontend gauge.
temp_step|Optional|Number representing a temperature in the selected unit|`0.5`|The granularity with which the target temperature can be controlled.

- All values must be delimited with `""`
- For more details on the keys, please take a look at [ESPHome Base Climate Configurations](https://esphome.io/components/climate/index.html#base-climate-configuration) and [ESPHome Climate Thermostat - Additional actions behavior](https://esphome.io/components/climate/thermostat.html#additional-actions-behavior).

&nbsp;
### Examples:

#### Cooler:

```yaml
substitutions:
  ###### CHANGE ME START ######
  device_name: "YOUR_NSPANEL_NAME" 
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  nextion_update_url: "http://homeassistant.local:8123/local/nspanel_us.tft"

    
  ##### addon-configuration #####
  ## addon_climate ##
  cooler_relay: "1" #Use relay 1
  temp_units: "°F" #Temperatures in Fahrenheit
  temp_min: "40" #Min supported temperature is 40°F
  temp_max: "80" #Max supported temperature is 80°F
  temp_step: "1" #Temperature granularity is 1°F
    
  ##### CHANGE ME END #####


packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml # Core package
      - nspanel_esphome_addon_climate_cool.yaml # activate for local climate (cooling) control
      # - nspanel_esphome_addon_climate_heat.yaml # activate for local climate (heater) control
    refresh: 300s
```

&nbsp;
#### Heater:

```yaml
substitutions:
  ###### CHANGE ME START ######
  device_name: "YOUR_NSPANEL_NAME" 
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  nextion_update_url: "http://homeassistant.local:8123/local/nspanel_us.tft"

    
  ##### addon-configuration #####
  ## addon_climate ##
  heater_relay: "1" #Use relay 1
  temp_units: "°F" #Temperatures in Fahrenheit
  temp_min: "40" #Min supported temperature is 40°F
  temp_max: "80" #Max supported temperature is 80°F
  temp_step: "1" #Temperature granularity is 1°F
    
  ##### CHANGE ME END #####


packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml # Core package
      # - nspanel_esphome_addon_climate_cool.yaml # activate for local climate (cooling) control
      - nspanel_esphome_addon_climate_heat.yaml # activate for local climate (heater) control
    refresh: 300s
```

