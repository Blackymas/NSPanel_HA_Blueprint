> #### _**ATTENTION! if you have already installed the version "nspanel-lovelace-ui" from joBr99 on your NSPanel, an intermediate step is necessary - otherwise it is not possible to install this or any other version.**_ 
> See [Common Issues | TFT Upload when NSPanel Lovelace UI has been installed](howto.md)
<br>

> #### _**The previous method of having the NSPanel download the TFT directly from GitHub has been discontinued due to a large number of users experiencing slow or failed downloads. Please make sure you change to locally hosted tft file**_ 

There are a number of issues that can affect the upload of the TFT upload, these are not issues with the NSPanel HA Blueprint project but seem to be common to Nextion displays and ESPhome. Not all of the below causes affect all users however following instructions in each point have resolved 

<br>In order of likelihood:

### Using a local source (Home Assistant) 
This is our most common cause of issues and is the reason our instructions no longer point to downloading the TFT from GitHub, changing the nextion_update_url to host the TFT file on your home assistant resolves the majority of issues.

&nbsp;
### HTTP instead of HTTPS
While HTTPS may work for some users we have seen it cause a number of issues. Change your TFT file hosting and nextion_update_url to use http. 

&nbsp;
### Remove customizations
Please try removing any customization you might have added to your panel. Specially `bluetooth_proxy` and `ble_tracker` consumes quite a lot of memory, competing with the uploading TFT engine, which also requires lots of memory from ESP.

&nbsp;
### Network issues
Check there are no issues with your network, bring your NSPanel and router closer together or try rebooting the router.
The issue we have seen with this is _connection refused_ or _connection reset_.

&nbsp;
### DNS
Related to point 2, please use IP address instead of DNS. e.g. use http://192.168.0.100:8123/local/nspanel.tft instead of http://homeassistant.local:8123/local/nspanel.tft

&nbsp;
### Check the file size by downloading to your computer
Use the same url provided to ESPHome into your browser (in your computer), e.g. http://192.168.0.100:8123/local/nspanel_eu.tft, and make sure you can download the file to your computer and the file have the same size as the one from GitHub.

&nbsp;
### Power cycle your panel
Cut the power supply off, wait a bit, and power on again. It usually helps when you already tried many other things.
If your panel is already installed in your wall, you probably can still power cycle using your power relay connected to that room.

&nbsp;
### Consider changing the framework
This project supports both `arduino` (ESPHome default) or `esp-idf` frameworks. Those have totally independently upload TFT engines, so changing the framework may cause a significant change.
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

&nbsp;
### Flash your panel again
Remove all add-ons and non-essential customization, flash your panel again (you can do this over the air/wirelessly, although it is recommended to use serial when changing between frameworks), try to update the TFT, add the add-ons and removed customization back and then flash it again.

&nbsp;
### Try an alternative http service. There are many options available for free to run under you local Windows, MAC or Linux machine.
Just to name some:
- NGINX
- IIS
- Apache
- Xampp
- etc.
