# Add-on: Bluetooth Proxy

## Description

This add-on allows your panel's relays to function as a Bluetooth proxy (BLE only) by utilizing the internal Bluetooth radio
along with the [ESPHome Bluetooth Proxy component](https://esphome.io/components/bluetooth_proxy.html).

> [!IMPORTANT]
>  Ensure you configure the Bluetooth Proxy using this add-on as it will enable better memory management by releasing the Bluetooth stack before a TFT update.

## Installation

To install, add the reference to `nspanel_esphome_addon_bluetooth_proxy` in your ESPHome settings under the `packages` section
following the `remote_package` entry, as illustrated below:

> [!WARNING]
> While the `esp-idf` framework is the default and recommended for the [ESP32 Platform](#framework-esp-idf) when Bluetooth features are enabled,
> ensure it is not switched to the `arduino` framework. The `arduino` framework significantly increases memory usage, which may prevent installation on your panel.

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
      # - esphome/nspanel_esphome_advanced.yaml
      - esphome/nspanel_esphome_addon_bluetooth_proxy.yaml
      # - esphome/nspanel_esphome_addon_climate_cool.yaml
      # - esphome/nspanel_esphome_addon_climate_heat.yaml
      # - esphome/nspanel_esphome_addon_climate_dual.yaml
```
