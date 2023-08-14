# Customization

## Description
This project adds lots of functionalities to your NSPanel and we are constantly adding new features based on user's feedback. However, you might have some specific case that are not included on the current implementation or is not a common case for other users.

You can take advantage of [ESPHome Configuration Types](https://esphome.io/guides/configuration-types.html) to add your custom functionality or even to customize an existing functionality with minimum effort and this document intents to clarify how to use this and give some examples of customization.

Please feel free to add your own customation to this document by creating a PR in the `dev` branch.

***IMPORTANT:** Use customization at your own risk. Custom/advanced systems won't be supported by this project's team.*

&nbsp;
## Instructions
There's nothing particular for this project, so you can just use any of the [ESPHome Configuration Types](https://esphome.io/guides/configuration-types.html) and only edit your local ESPHome yaml settings.

Most of the ESPHome components in this project contains an `Id`, which can be used together with the `!extend` key to add or replace existing code.

You should add your customizations at the end of your ESPHome yaml, as in the example bellow:

```yaml
substitutions:
  ###### CHANGE ME START ######
  device_name: "YOUR_NSPANEL_NAME" 
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  nextion_update_url: "http://homeassistant.local:8123/local/nspanel_us.tft"

  ##### addon-configuration #####
  ## addon_climate ##
  # addon_climate_heater_relay: "1" # possible values: 1/2

  ##### CHANGE ME END #####

packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml
      #- nspanel_esphome_addon_climate.yaml # activate local climate-control
    refresh: 300s

##### My customization - Start #####
# Encrypt the communication between ESPHome and Home Assistant
api:
  encryption:
    key: !secret api_encryption_key
# More detailed log (for troubleshooting only)
logger:
  level: VERBOSE
##### My customization - End #####
```

&nbsp;
## Examples
### API encryption
This is highly recommended when you are transfer sensitive information between your panel and Home Assistant, as when you use your panel to enter the PIN for an Alarm Control Panel.

```yaml
# Encrypt the communication between ESPHome and Home Assistant
api:
  encryption:
    key: !secret api_encryption_key
```
&nbsp;
### Custom OTA password
By default, the Wi-Fi password will be used as your OTA password, but you can replace it using this customization:
```yaml
# Use my global OTA password
ota:
  password: !secret ota_password
```
&nbsp;
### Web server credentials
By default, the web server credentials are defined by this project as using `admin` as `username` and your Wi-Fi password, but you can replace it using this customization:
```yaml
# Custom web server credentials
web_server:
  auth:
    username: !secret web_server_username
    password: !secret web_server_password
```
&nbsp;
### Reboot when API fails
Reboot your panel if it loses it's connection to Home Assistant for more than a certain time (15 minutes in this example).<br>
Sometimes the low level ESP functions could report that the ESP is connected to the network, when in fact it is not and only a full reboot fixes it.<br>
To support long times without Wi-Fi, this is disabled by default in this project, but you can set a reasonable interval to restart, based on your network reliability.
```yaml
# Reboot if HA is not connected for 15 minutes
api:
  reboot_timeout: 15min
```
&nbsp;
### Change uart's baud rate
Use this to change the baud rate on the communication between ESPHome and Nextion display.<br>
Important: Use only when troubleshooting as your display should be set to always communicate at 115200 bps.
```yaml
# Set Nextion comm's baud rate to 9600 bps
uart:
  baud_rate: 9600
```
&nbsp;
### Manual IP
Set IP address manually.
```yaml
# Set IP address manually
wifi:
  networks:
    - id: !extend wifi_default
      manual_ip:
        static_ip: 192.168.0.123
        gateway: 192.168.0.1
        subnet: 255.255.255.0
```
&nbsp;
### Hidden Wi-Fi
Connect to a hidden Wi-Fi network.
```yaml
# Connect to a hidden Wi-Fi network.
wifi:
  networks:
    - id: !extend wifi_default
      hidden: true
```

&nbsp;
### SNTP (time) server
ESPHome takes it's time from Home Assistant, however you can configure it to use a Network Time Server instead.
```yaml
# Use my own local network time server
time:
  - id: !extend time_provider
    platform: sntp
    timezone: Europe/Stockholm
    servers:
      - !secret mysntpserver
      - europe.pool.ntp.org
      - 0.pool.ntp.org
```

