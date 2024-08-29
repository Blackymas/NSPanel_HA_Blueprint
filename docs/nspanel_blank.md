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

Just go to your devices's page (under **Settings** > **Devices & services** > **ESPHome**),
select your **Upload TFT display - Model** and then press **Upload TFT display**.

## What to do after installing `nspanel_blank.tft`?

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/3b0bb950-4857-4c22-a53a-062d09f315dc)

Once you have sucessfully installed any of the `tft` files from this project,
the `nspanel_blank.tft` file shouldn't be necessary anymore and you should be able to always install the final `tft` file.

Just go to your devices's page (under **Settings** > **Devices & services** > **ESPHome**),
select your **Upload TFT display - Model** and then press **Upload TFT display**.

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
