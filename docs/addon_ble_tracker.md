# Add-on: BLE Tracker

## Description
This add-on enables your NSPanel to use its internal Bluetooth module to track nearby Bluetooth Low Energy (BLE) devices
using the [ESPHome BLE Tracker component](https://esphome.io/components/esp32_ble_tracker.html).

> [!IMPORTANT]
> Configuring the BLE Tracker on your NSPanel is crucial for enabling device discovery and presence detection functionalities efficiently.
This component should be managed with careful consideration of ESP32's memory capabilities, especially when other Bluetooth components are used concurrently.

## Prerequisites
- The `esp-idf` framework is recommended for the [ESP32 Platform](customization.md#framework-esp-idf) to ensure optimal operation and compatibility when using BLE features.
The `arduino` framework is not advised as it may increase memory usage and impact the performance negatively.

> [!WARNING]
> Using the `arduino` framework can lead to high memory consumption which might interfere with the stability of BLE operations on the NSPanel.
It is crucial to use the `esp-idf` framework to avoid such issues.

## Configuration Steps
1. **Edit Your ESPHome YAML File**: Incorporate the BLE Tracker component into your NSPanel's configuration by adding the necessary entries under the `esp32_ble_tracker:` section as shown below:
    ```yaml
    substitutions:
      device_name: "YOUR_NSPANEL_NAME"        # Set your NSPanel's device name
      friendly_name: "Your Friendly Name"     # Set a friendly display name
      wifi_ssid: !secret wifi_ssid            # Your Wi-Fi SSID
      wifi_password: !secret wifi_password    # Your Wi-Fi password

    # Optional configurations (uncomment if needed)
    ## Add-on for specific tracked devices or automation triggers
    # sensor:
    #   - platform: ble_rssi
    #     mac_address: MAC_ADDRESS_OF_DEVICE
    #     name: "BLE Device RSSI"

    ## If you wanna set non-standard parameters to your BLE tracker, just add like this:
    # esp32_ble_tracker:
    #   scan_parameters:
    #     interval: 1100ms
    #     window: 1100ms
    #     active: true

    # Package Configuration
    packages:
      remote_package:
        url: https://github.com/Blackymas/NSPanel_HA_Blueprint
        ref: main
        refresh: 300s
        files:
          - nspanel_esphome.yaml # Basic NSPanel package
          # Optional packages for advanced features and other add-ons
          - esphome/nspanel_esphome_addon_ble_tracker.yaml # BLE Tracker add-on package
          # - esphome/nspanel_esphome_addon_bluetooth_proxy.yaml
          # - esphome/nspanel_esphome_addon_climate_cool.yaml
          # - esphome/nspanel_esphome_addon_climate_heat.yaml
          # - esphome/nspanel_esphome_addon_climate_dual.yaml
          # - esphome/nspanel_esphome_addon_cover.yaml
    ```
2. **Update Substitutions**: Customize `"YOUR_NSPANEL_NAME"` and `"Your Friendly Name"` to appropriate identifiers for your device and its Bluetooth functionality.
3. **Save and Upload**: After making the necessary changes, save your configuration file and upload it to your NSPanel via the ESPHome dashboard.

> [!NOTE]
> The first time this component is enabled for an ESP32, the code partition needs to be resized.
> Please flash the ESP32 via USB when adding this to your configuration. After that, you can use OTA updates again.

This configuration allows your NSPanel to efficiently manage Bluetooth connections, acting as a proxy for various BLE operations.
