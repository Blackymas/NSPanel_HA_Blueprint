# `nspanel_blank.tft`

The NSPanel consist in a ESP32 board (the panel itself, controlling the relays, buttons, communications, etc.)
with a Nextion display connected to.

This Nextion display have an independent controller which also requires a firmware and its settings (the basic layout),
and this is done by an `.tft` file.

When you get your panel from Sonoff, their `tft` file is installed in the Nextion display and using a called "Reparse mode",
which makes a bit challenging to replace the `tft` file when using ESPHome and then, we highly recoment you using `nspanel_blank.tft`,
which is just a fraction of the size of a regular `tft` and will make the first `tft` replacement much easier.

Once NSPanel's original `tft` is replaced, is much easier to install a new `tft` with ESPHome,
so you can go directly to the final file (either `nspanel_eu.tft`, `nspanel_us.tft` or `nspanel_us_land.tft`).

For more datails on how to install the first `tft` file, specially if your panel still displaying the original Sonoff screen,
please refeer to the [Troubleshooting TFT transfer](tft_upload.md) guide.

## How to install a different `tft` file?

**v4.2 or later and `esp-idf` framework:**

Just go to your devices's page (under **Settings** > **Devices and Services** > **ESPHome**),
select your **Upload TFT display - Model** and then press **Upload TFT display**.

**Older versions or `arduino` framework:**

On your ESPHome settings, you have entered a url for `nextion_update_url`, in the substitutions, like this:

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
      # - nspanel_esphome_addon_climate_cool.yaml # activate for local climate (cooling) control
      # - nspanel_esphome_addon_climate_heat.yaml # activate for local climate (heater) control
      # - nspanel_esphome_addon_climate_dual.yaml # activate for local climate (dual) control
    refresh: 300s

esp32:
  framework:
    type: esp-idf
```

This url will indicate where your panel will look for the `tft` file when you click the "Upload TFT" button (under device's page)
or call the service `esphome.xxxxx_upload_tft`.

The most popular way to switch between the `nspanel_blank.tft` and `nspanel_xx.tft` is replacing the URL on the ESPHome settings
and flashing the device again, however, you can also do this calling the service `esphome.xxxxx_upload_tft_url`
adding the URL of the alternative file as a parameter.
It's up to you, as both ways will give the same result.

## What to do after installing `nspanel_blank.tft`?

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/3b0bb950-4857-4c22-a53a-062d09f315dc)

Once you have sucessfully installed any of the `tft` files from this project,
the `nspanel_blank.tft` file shouldn't be necessary anymore and you should be able to always install the final `tft` file.

**v4.2 or later and `esp-idf` framework:**

Just go to your devices's page (under **Settings** > **Devices and Services** > **ESPHome**),
select your **Upload TFT display - Model** and then press **Upload TFT display**.

**Older versions or `arduino` framework:**

Make sure you have one of the following final TFT files in your local http server (typically Home Assistant on ***www*** folder):
- [`nspanel_eu.tft`](../nspanel_eu.tft)
- [`nspanel_us.tft`](../nspanel_us.tft)
- [`nspanel_us_land.tft`](../nspanel_us_land.tft)

Now Flash your panel with `nextion_update_url` pointing to one of the final TFT files and
press **Upload TFT** in the device's page (**Settings** > **Devices & Services** > **ESPHome**).

## Additional Tips and Resources
We have an useful guide for [troubleshooting TFT transfer issues](tft_upload.md).
Please take a look there first.

After troubleshooting, if issues persist, consult the [Issues](https://github.com/Blackymas/NSPanel_HA_Blueprint/issues)
and feel free to create a new one asking for more personalized assistance.

Please share as much info as possible, like:
1. Describing (or a picture of) what is in your screen
2. Are updating from a previous version of this same project,
or coming from another NSPanel customization (which one?)
or customizing for the first time a panel with original Sonoff settings?
3. Please share the ESPHome logs from when your panel starts to the moment the upload fails.
4. Describe what you have already tried.

## Important note
Remember, these steps are a guideline and might vary slightly based on your specific setup and previously installed system.
