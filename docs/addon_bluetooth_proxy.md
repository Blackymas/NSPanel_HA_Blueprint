# Add-on: Bluetooth Proxy

## Description
This add-on enables your NSPanel to function as a Bluetooth Low Energy (BLE) proxy utilizing its internal Bluetooth module
along with the [ESPHome Bluetooth Proxy component](https://esphome.io/components/bluetooth_proxy.html).

> [!IMPORTANT]
> It is crucial to configure the Bluetooth Proxy using this add-on for optimal memory management, which involves releasing the Bluetooth stack prior to any TFT updates.

### Prerequisites
- Ensure the `esp-idf` framework is utilized for the [ESP32 Platform](customization.md#framework-esp-idf) when enabling Bluetooth features.
Avoid switching to the `arduino` framework as it significantly increases memory usage, potentially causing installation failures on your panel.

> [!WARNING]
> The `arduino` framework, while compatible, should not be used for Bluetooth-intensive applications on the NSPanel due to its higher memory consumption.

### Configuration Steps
1. **Edit Your ESPHome YAML File**: Add the Bluetooth Proxy add-on to your configuration by including the `remote_package` entry under the `packages` section as illustrated below:
    ```yaml
    substitutions:
      device_name: "YOUR_NSPANEL_NAME"          # Set your NSPanel's device name
      friendly_name: "Your Friendly Name"       # Set a friendly display name
      wifi_ssid: !secret wifi_ssid              # Your Wi-Fi SSID
      wifi_password: !secret wifi_password      # Your Wi-Fi password

    # Optional configurations (uncomment if needed)
    ## Add-on for climate control
    # heater_relay: "1"  # Options: "1" or "2"

    # Begin Customization Section
    ##### Customization - Start #####
    ## If you wanna set non-standard parameters to your Bluetooth proxy just add like this:
    # esp32_ble_tracker:
    #   scan_parameters:
    #     interval: 1100ms
    #     window: 1100ms
    #     active: true
    #
    # bluetooth_proxy:
    #   active: true
    ##### Customization - End #####

    # Package Configuration
    packages:
      remote_package:
        url: https://github.com/Blackymas/NSPanel_HA_Blueprint
        ref: main
        refresh: 300s
        files:
          - nspanel_esphome.yaml # Basic NSPanel package
          # Optional packages for advanced features and other add-ons
          # - esphome/nspanel_esphome_addon_ble_tracker.yaml
          - esphome/nspanel_esphome_addon_bluetooth_proxy.yaml # Bluetooth Proxy add-on package
          # - esphome/nspanel_esphome_addon_climate_cool.yaml
          # - esphome/nspanel_esphome_addon_climate_heat.yaml
          # - esphome/nspanel_esphome_addon_climate_dual.yaml
    ```
2. **Update Substitutions**: Customize `"YOUR_NSPANEL_NAME"` and `"Your Friendly Name"` to appropriate identifiers for your device and its Bluetooth functionality.
3. **Save and Upload**: After making the necessary changes, save your configuration file and upload it to your NSPanel via the ESPHome dashboard.

> [!NOTE]
> The first time this component is enabled for an ESP32, the code partition needs to be resized.
> Please flash the ESP32 via USB when adding this to your configuration. After that, you can use OTA updates again.

This configuration allows your NSPanel to efficiently manage Bluetooth connections, acting as a proxy for various BLE operations.
