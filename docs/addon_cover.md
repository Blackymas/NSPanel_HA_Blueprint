# Add-on: Cover

## Description

This add-on enables your panel's relays to act as a cover driver,
using its relays to drive the motor to open or close a cover.

- This is an experimental feature, so be prepared to face some issues.
  Please report those so we can improve.
- In its initial version, this control is not fully local,
  and Home Assistant still needs to process the open/close commands.
  We want to change this in the future so it could be fully controlled locally.

### Attention
The NSPanel is limited to 2A per relay.
Don't use it to directly power your cover's motor if it exceeds the panel specifications:
  - 150W/110V/Gang, 300W/110V/Total
  - 300W/220V/Gang, 600W/220V/Total

> [!NOTE]
> More details on the [Sonoff NSPanel's page](https://sonoff.tech/product/central-control-panel/nspanel/)
> and the [product specifications document](https://sonoff.tech/wp-content/uploads/2021/11/%E4%BA%A7%E5%93%81%E5%8F%82%E6%95%B0%E8%A1%A8-NSPanel-20210831.pdf).

## Installation

You will need to add the reference to the `addon_cover` file in your ESPHome 
settings in the `package` section and after the `remote_package` (base code), 
as shown below:

> [!NOTE]
> Occasionally, ESPHome updates may result in the `entity_id` of embedded covers 
> being appended with `_2`. If you experience this change, refer to this [forum 
> post](https://community.home-assistant.io/t/esphome-devices-all-renamed-with-2-added/388146)
> on the Home Assistant Forum for guidance.

```yaml
substitutions:
  # Settings - Editable values
  device_name: "YOUR_NSPANEL_NAME"
  friendly_name: "Your panel's friendly name"
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  # Add-on configuration (if needed)
  ## Add-on climate
  # heater_relay: "1"  # Possible values: "1" or "2"

# Customization area
##### My customization - Start #####
##### My customization - End #####

# Basic and optional configurations
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    refresh: 300s
    files:
      - nspanel_esphome.yaml # Basic package
      # Optional advanced and add-on configurations
      # - esphome/nspanel_esphome_addon_climate_cool.yaml
      # - esphome/nspanel_esphome_addon_climate_heat.yaml
      # - esphome/nspanel_esphome_addon_climate_dual.yaml
      - esphome/nspanel_esphome_addon_cover.yaml
```

## Configuration

For this add-on, all the basic settings are accessible via the device's page in
your Home Assistant. For most cases, no additional YAML settings are needed.
You will find the following configuration entities under the device's page (**Settings** > **Devices & services** > **ESPHome**):


<!-- markdownlint-disable MD013 MD033 -->
|Entity|Supported values|Default|Description|
|:-|:-:|:-:|:-|
|Cover relays mode|`Relay 1 opens, relay 2 closes` or `Relay 2 opens, relay 1 closes`|`Relay 1 opens, relay 2 closes`|This will define which relay (1 or 2) is used to open the cover and which is used to close the cover.|
|Cover open duration|`1ms` to `600000ms`|`1ms` (disabled)|The amount of time it takes the cover to open from the fully closed state.|
|Cover close duration|`1ms` to `600000ms`|`1ms` (disabled)|The amount of time it takes the cover to close from the fully open state.|
|Cover device class|Any of the [device classes supported by Home Assistant](https://www.home-assistant.io/integrations/cover/#device-class)|`None`|Select the cover type. It influences how the entity is represented in Home Assistant.|
|Cover acceleration wait time|`0ms` to `10000ms`|`0ms`|Considers the wait time needed by the cover to start moving after a command is issued, accounting for large inertia.|
|Cover direction change wait time|`0ms` to `10000ms`|`100ms`|Stops cover and forces a wait time between direction changes, protecting motors. If set, an intermediate stop action will be invoked if an open/close action is issued while moving in the opposite direction.|
|Cover interlock wait time|`1ms` to `5000ms`|`250ms`|Imposes a relay level time delay from one relay turning off until the other can turn on, preventing both relays from being on simultaneously.<br>***ATTENTION***, this is a software interlock, please read more about on [ESPHome Switch Interlocking](https://esphome.io/components/switch/gpio.html#interlocking) page|
<!-- markdownlint-enable MD013 MD033 -->

## Advanced settings

This add-on is based on the [ESPHome Feedback Cover](https://esphome.io/components/cover/feedback.html) component and supports any of the settings available for that component.
If you want to set a specific attribute, please use the `!extend` option in your panel's YAML, like the following:

```yaml
cover:
  - id: !extend cover_embedded
    max_duration: 60s
```
