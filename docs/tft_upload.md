# Troubleshooting TFT transfer

> [!IMPORTANT]  
> If you have already installed the version "nspanel-lovelace-ui" from joBr99 on your NSPanel, an intermediate step is necessary - otherwise,
> it is not possible to install this or any other version.
>
> See [Common Issues | TFT Upload when NSPanel Lovelace UI has been installed](howto.md)

## Common Issues and Troubleshooting

The following is a list of common issues affecting the TFT upload, along with suggested solutions.
These issues are not specific to the NSPanel HA Blueprint project but are common to Nextion displays and ESPHome.

### Resolving "System data ERROR!" on Display

![System Data ERROR](pics/us_system_data_error_upside_down.jpg)

#### Don't Panic!

The "System data ERROR!" message, sometimes displayed upside-down, appears when a TFT upload is incomplete.
While it may seem alarming, this message simply indicates that the TFT file on the display is invalid.
A successful TFT upload will resolve this issue.

### Using the `nspanel_blank.tft` File to Assist

Many TFT upload problems are associated with the Nextion Active Reparse Mode,
which is used in some implementations like the original Sonoff firmware or other popular custom firmwares.
Installing any TFT file from this project will disable this mode.
However, the size of a typical TFT file (7 to 12 Mb) can be challenging for devices with limited memory,
such as the ESP32 in your panel, especially over a serial interface.

To facilitate the process, we've created the `nspanel_blank.tft` file.
Although it's not a fully functional TFT file, it's sufficient to disable the Reparse Mode and is significantly smaller (less than 300kb). 

If you encounter any issues, try installing the `nspanel_blank.tft` file first. This should make it easier to subsequently install larger, fully functional TFT files.

### Enabling TFT upload components
If the components necessary for uploading a TFT file are not available in the device's page under **Settings** > **Devices & Services** > **ESPHome**,
and you cannot simply enable the entity on it's settings, please try removing the device integration from there, restart your Home Assistant instance and then add the device again.
It should be automatically detected as a new integration, but if this is not happening,
click the **Add integration** button, select **ESPHome**, add the device hostname or IP address and follow the steps required.

### Wait a Bit Before Starting the TFT Upload

- **Issue**: The Nextion display might not connect to ESPHome immediately after boot.
- **Solution**: Wait up to 2 minutes for the boot script to complete.
If you are already using a TFT from this project, the display of ESPHome version and the framework used (`arduino` vs `esp-idf`) is an indication that a communication was established.
If you haven't installed any TFT yet, look for Nextion related messages on ESPHome logs.
- **Additional Guidance**: Knowing when the device is fully booted and ready to accept the TFT upload can prevent many issues.
Observe any changes in the display or logs indicators to ensure the device is ready.

### Using a Local Source (Home Assistant)

- **Issue**: Problems with downloading the TFT from GitHub.
- **Solution**: Host the TFT file on your Home Assistant and change the `nextion_update_url` accordingly.
- **Step-by-Step Guide**: Here's how you can change your `nextion_update_url`:
    1. Locate your panel's ESPHome configuration file.
    2. Find the line with `nextion_update_url`.
    3. Replace the URL with the local address where your TFT file is hosted.

### HTTP Instead of HTTPS

- **Issue**: HTTPS connections may be problematic with ESP.
- **Solution**: Use HTTP for hosting the TFT file and updating the `nextion_update_url`.
- **Why HTTP?**: HTTP can be more stable for these connections.
To switch, simply replace 'https' with 'http' in your URLs and make sure your http server supports non-secure connections.

### Remove Customizations

- **Issue**: Customizations like `bluetooth_proxy` and `ble_tracker` may interfere with the upload.
- **Solution**: Temporarily remove any customizations to free up memory.
- **How to Remove Customizations**: Identify any additional features you've added and remove them from your configuration file.
Pay special attention to memory-intensive customizations.

### Use IP Address Instead of DNS

- **Issue**: DNS may cause connection problems.
- **Solution**: Use the IP address of your Home Assistant directly.
- **Example**: Replace `http://homeassistant.local:8123/local/nspanel_blank.tft` with `http://192.168.0.100:8123/local/nspanel_blank.tft`.

### Consider changing the framework

- **Issue**: You might be facing some situation where the transfer engine used by your framework cannot handle it properly.
- **Solution**: Temporarily switch between the frameworks.
- **Additional Guidance**: This project supports both `arduino` (ESPHome default) or `esp-idf` frameworks.
Those have totally independently upload TFT engines, so changing the framework may cause a significant change.
In our experience, `esp-idf` have a better memory management and therefore is more efficient with uploading TFT, however the support to HTTPS is a bit better (although not indicated) with `arduino`.
You can set the framework you want by adding this to your ESPHome yaml:

#### ESP-IDF

```yaml
esp32:
  framework:
    type: esp-idf
```

#### Arduino

```yaml
esp32:
  framework:
    type: arduino
```

### Check the File Size by Downloading to Your Computer

- **Issue**: Ensuring the file size matches the GitHub version.
- **Solution**: Use the same URL you provided to ESPHome to download the file on your computer and compare sizes.
- **Verification Steps**: Download the file, then right-click and select 'Properties' to check the size.
Compare this with the size listed on GitHub or from the file you downlodaded directly from GitHub.

### Power Cycle Your Panel

- **Issue**: General troubleshooting.
- **Solution**: Turn off the power supply, wait a moment, and power it back on.
If your panel is already installed in the wall, you probably can still power cycle using your electricity relay's panel and switching the relay connected to your panel.
- **How Long to Wait**: Wait at least 30 seconds before turning the power back on.
This ensures the system resets to a clean state.

### Flash your panel again

- **Issue**: Your firmware might be missing some important library, you may be using an outdated version or the ESP may be out of memory.
- **Solution**: Remove all add-ons and non-essential customization and flash your panel again.
- **Step-by-Step Guide**:
    1. Look your yaml file and commment out all the customization (typically on a section name "My customizations") and any of the remote files other than `nspanel_esphome.yaml`.
    2. Flash your panel with the new cleaner yaml. You can do this over the air/wirelessly, although it is recommended to use serial when changing between frameworks
    3. Try to update the TFT file again
    4. Add the add-ons and removed customization back and then flash it again.

### Try an alternative http service

- **Issue**: Your current http server may be overloaded.
- **Solution**: Try another http server installed in your computer.
There are many options available for free to run under you local Windows, MAC or Linux machine.
- **Examples**: Just to name some:
  | Solution | Website | Supported OSs | Pros | Cons |
  |----------|---------|---------------|------|------|
  | NGINX | [nginx.org](https://nginx.org/en/) | Linux, Windows, macOS | High performance, efficient for static content, good for high concurrency | Configuration can be complex for beginners |
  | IIS | [Microsoft Web Platform](https://www.microsoft.com/web/downloads/platform.aspx) | Windows | Integrated with Windows, GUI for setup, good for Windows environments | Limited to Windows OS |
  | Apache | [httpd.apache.org](https://httpd.apache.org/) | Linux, Windows, macOS | Highly reliable and flexible, wide OS compatibility, extensive customization | Can be less efficient under high load than NGINX |
  | XAMPP | [apachefriends.org](https://www.apachefriends.org/index.html) | Linux, Windows, macOS | All-in-one package, easy to install, ideal for beginners | Not optimized for high-traffic sites, more suited for development than production |

## Additional Tips and Resources

After troubleshooting, if issues persist, consult the [Issues](https://github.com/Blackymas/NSPanel_HA_Blueprint/issues) and feel free to create a new one asking for more personalized assistance.

Please share as much info as possible, like:
1. Describing (or a picture of) what is in your screen
2. Are updating from a previous version of this same project, or coming from another NSPanel customization (which one?) or customizing for the first time a panel with original Sonoff settings?
3. Please share the ESPHome logs from when your panel starts to the moment the upload fails.
4. Describe what you have already tried.

## Important note

Remember, these steps are a guideline and might vary slightly based on your specific setup and previously installed system.
