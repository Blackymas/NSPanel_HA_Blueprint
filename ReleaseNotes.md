# Release Notes

## Breaking Changes
- **Removed Add-ons:** BLE Tracker and Bluetooth Proxy add-ons have been removed
- **Reason:** Improved Bluetooth memory management no longer requires specific component IDs for TFT upload operations
- **Benefits:** Simplified setup, better user experience, reduced maintenance overhead
- **Migration:** Use native ESPHome components directly:
  - [ESPHome BLE Tracker](https://esphome.io/components/esp32_ble_tracker.html)
  - [ESPHome Bluetooth Proxy](https://esphome.io/components/bluetooth_proxy.html)
