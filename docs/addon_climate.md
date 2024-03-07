# Add-on: Climate

## Description

This add-on enables the use of your panel's relays to act as a thermostat (either cooler or heater)
using the internal temperature sensor and independent of the network availability.

### Attention
1. The NSPanel is limited to 2A per relay.
Don't use it for directly power your cooler/heater if exceeding the panel specifications:
    - 150W/110V/Gang, 300W/110V/Total
    - 300W/220V/Gang, 600W/220V/Total
2. A target temperature must be set on the climate entity in Home Assistant or the page Climate in your panel.

> [!NOTE]
> More details on the [Sonoff NSPanel's page](https://sonoff.tech/product/central-control-panel/nspanel/)
> and the [product specifications document](https://sonoff.tech/wp-content/uploads/2021/11/%E4%BA%A7%E5%93%81%E5%8F%82%E6%95%B0%E8%A1%A8-NSPanel-20210831.pdf).

## Installation

You will need to add the reference to `addon_climate_heat`, `addon_climate_cool` or `addon_climate_dual` files on your ESPHome settings in the `package` section
and after the `remote_package` (base code), as shown bellow (for `heat` in this example):

> [!NOTE]
> From time to time, there are changes in ESPHome that lead to an added `_2` for the embedded thermostats. 
> If you encounter this issue, please have a look at this [entry](https://community.home-assistant.io/t/esphome-devices-all-renamed-with-2-added/388146) in the Home Assistent Forum. 

```yaml
substitutions:
  # Settings - Editable values
  device_name: "YOUR_NSPANEL_NAME"
  friendly_name: "Your panel's friendly name"
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  # Add-on configuration (if needed)
  ## Add-on climate
  heater_relay: "1"  # Possible values: "1" or "2"

# Customization area
##### My customization - Start #####
##### My customization - End #####

# Basic and optional configurations
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml # Basic package
      # Optional advanced and add-on configurations
      # - esphome/nspanel_esphome_advanced.yaml
      # - nspanel_esphome_addon_climate_cool.yaml
      - nspanel_esphome_addon_climate_heat.yaml
      # - nspanel_esphome_addon_climate_dual.yaml
    refresh: 300s
```

## Configuration

The following keys are available to be used in your `substitutions`:

<!-- markdownlint-disable MD013 MD033 -->
Key|Required|Supported values|Default|Description
:-|:-:|:-:|:-:|:-
cooler_relay|Mandatory for *cool* and *dual*|`1` or `2`|`0` (disabled)|Relay used for control the cooler. User `1` for "Relay 1" or `2` for "Relay 2".
heater_relay|Mandatory for *heat* and *dual*|`1` or `2`|`0` (disabled)|Relay used for control the heater. User `1` for "Relay 1" or `2` for "Relay 2".
temp_units|Optional|`°C` or `°F`|`°C`|Temperature unit.
min_off_time|Optional|Positive integer representing the number of seconds|`300`|Minimum duration (in seconds) the cooling/heating action must be disengaged before it may be engaged.
min_run_time|Optional|Positive integer representing the number of seconds|`300`|Minimum duration (in seconds) the cooling/heating action must be engaged before it may be disengaged.
min_idle_time|Optional|Positive integer representing the number of seconds|`30`|Minimum duration (in seconds) the idle action must be active before calling another climate action.
target_low|Optional|Number representing a temperature in the selected unit|`18`|The initial lower treshold for the target temperature.
target_high|Optional|Number representing a temperature in the selected unit|`24`|The initial higher treshold for the target temperature.
temp_min|Optional|Number representing a temperature in the selected unit|*cool: `15`*<br>*heat: `7`*<br>*dual: `7`* |The minimum temperature the climate device can reach. Used to set the range of the frontend gauge.
temp_max|Optional|Number representing a temperature in the selected unit|*cool: `45`*<br>*heat: `35`*<br>*dual: `45`* |The maximum temperature the climate device can reach. Used to set the range of the frontend gauge.
temp_step|Optional|Number representing a temperature in the selected unit|`0.5`|The granularity with which the target temperature can be controlled.
cool_deadband|Optional|Number representing a temperature hysteresis in the selected unit|`0.5`|The minimum temperature differential (temperature above the set point) before engaging cooling.
cool_overrun|Optional|Number representing a temperature hysteresis in the selected unit|`0.5`|The minimum temperature differential (cooling beyond the set point) before disengaging cooling.
heat_deadband|Optional|Number representing a temperature hysteresis in the selected unit|`0.5`|The minimum temperature differential (temperature below the set point) before engaging heat.
heat_overrun|Optional|Number representing a temperature hysteresis in the selected unit|`0.5`|The minimum temperature differential (heating beyond the set point) before disengaging heat.

<!-- markdownlint-enable MD013 MD033 -->

- All values must be delimited with `""`
- For more details on the keys, please take a look at [ESPHome Base Climate Configurations](https://esphome.io/components/climate/index.html#base-climate-configuration)
and [ESPHome Climate Thermostat - Additional actions behavior](https://esphome.io/components/climate/thermostat.html#additional-actions-behavior).

## Examples

### Cooler

```yaml
substitutions:
  # Settings - Editable values
  device_name: "YOUR_NSPANEL_NAME"
  friendly_name: "Your panel's friendly name"
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  # Add-on configuration (if needed)
  ## Add-on climate
  cooler_relay: "1"     # Possible values: "1" or "2"
  temp_units: "°F"      # Temperatures in Fahrenheit
  temp_min: "40"        # Min supported temperature is 40°F
  temp_max: "80"        # Max supported temperature is 80°F
  temp_step: "1"        # Temperature granularity is 1°F
  cool_deadband: "1.2"  # Temperature delta before engaging cooling
  cool_overrun: "1.2"   # Temperature delta before disengaging cooling

# Customization area
##### My customization - Start #####
##### My customization - End #####

# Basic and optional configurations
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml # Basic package
      # Optional advanced and add-on configurations
      # - esphome/nspanel_esphome_advanced.yaml
      - nspanel_esphome_addon_climate_cool.yaml
      # - nspanel_esphome_addon_climate_heat.yaml
      # - nspanel_esphome_addon_climate_dual.yaml
    refresh: 300s
```

### Heater

```yaml
substitutions:
  # Settings - Editable values
  device_name: "YOUR_NSPANEL_NAME"
  friendly_name: "Your panel's friendly name"
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  # Add-on configuration (if needed)
  ## Add-on climate
  heater_relay: "1"     # Possible values: "1" or "2"
  temp_units: "°F"      # Temperatures in Fahrenheit
  temp_min: "40"        # Min supported temperature is 40°F
  temp_max: "80"        # Max supported temperature is 80°F
  temp_step: "1"        # Temperature granularity is 1°F
  heat_deadband: "1.2"  # Temperature delta before engaging heat
  heat_overrun: "1.2"   # Temperature delta before disengaging heat

# Customization area
##### My customization - Start #####
##### My customization - End #####

# Basic and optional configurations
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml # Basic package
      # Optional advanced and add-on configurations
      # - esphome/nspanel_esphome_advanced.yaml
      # - nspanel_esphome_addon_climate_cool.yaml
      - nspanel_esphome_addon_climate_heat.yaml
      # - nspanel_esphome_addon_climate_dual.yaml
    refresh: 300s
```

### Dual

```yaml
substitutions:
  # Settings - Editable values
  device_name: "YOUR_NSPANEL_NAME"
  friendly_name: "Your panel's friendly name"
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  # Add-on configuration (if needed)
  ## Add-on climate
  heater_relay: "1"     # Possible values: "1" or "2"
  cooler_relay: "2"     # Possible values: "1" or "2"
  temp_units: "°F"      # Temperatures in Fahrenheit
  temp_min: "40"        # Min supported temperature is 40°F
  temp_max: "80"        # Max supported temperature is 80°F
  temp_step: "1"        # Temperature granularity is 1°F
  cool_deadband: "1.2"  # Temperature delta before engaging cooling
  cool_overrun: "1.2"   # Temperature delta before disengaging cooling
  heat_deadband: "1.2"  # Temperature delta before engaging heat
  heat_overrun: "1.2"   # Temperature delta before disengaging heat

# Customization area
##### My customization - Start #####
##### My customization - End #####

# Basic and optional configurations
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml # Basic package
      # Optional advanced and add-on configurations
      # - esphome/nspanel_esphome_advanced.yaml
      # - nspanel_esphome_addon_climate_cool.yaml
      # - nspanel_esphome_addon_climate_heat.yaml
      - nspanel_esphome_addon_climate_dual.yaml
    refresh: 300s
```

### Concrete example: (Water) underfloor heating

The NSPanel is particularly nice as a replacement for existing water underfloor heating controllers. 
They are installed at approximately eye level and (often) supplied by 230V. 
In my case, the valve is type 'normally closed,' i.e. an open relay corresponds to 'no heating.' 
I am using relay #1. Please note that this is _not_ a PID controller, but simply on-off. 
At a certain value, the heating starts and at another value it switches off again. 
These value were set to `0.3°C` below and `0.1°C` above the setpoint, respectively. 
It turned out that `0.3`and `0.1` worked well for all off our 4 rooms. 
The minimum settable value is `15°C`, the maximum `22°C` and the granularity (step size) is `0.1°C`. 
In addition, I chose to set the default temperature to `21.2°C`. 

```yaml
 ##### addon-configuration #####
  ## addon_climate ##
  heater_relay: "1" #Use relay 1
  temp_min: "15" 
  temp_max: "22" 
  temp_step: "0.1"
  cold_tolerance: "0.3"
  hot_tolerance: "0.1"
    
  ##### CHANGE ME END #####
climate:
  - id: !extend thermostat_embedded
    preset:
      - name: Home
        default_target_temperature_low: 21.2
        mode: "heat"
```

Please note, that any filter that smoothes the temperature readings (e.g. averaging) is discouraged since it slows the response times of the already slow underwater floor heater. 
The temperature stability is quite nice which can be seen in the following viewgraph. 

![temperature vs time](pics/addon_underfloor.png)

Mar 5 at approx. 9.30am, the window was opened and all heaters were set to 'off.'  