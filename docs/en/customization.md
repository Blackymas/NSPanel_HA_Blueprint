# Customization

## Description
This project adds lots of functionalities to your NSPanel and we are constantly adding new features based on user's feedback. However, you might have some specific case that are not included on the current implementation or is not a common case for other users.

You can take advantage of [ESPHome Configuration Types](https://esphome.io/guides/configuration-types.html) to add your custom functionality or even to customize an existing functionality with minimum effort and this document intents to clarify how to use this and give some examples of customization.

Please feel free to add your own customation to this document by creating a PR in the `dev` branch.

***IMPORTANT:***
- *Use customization at your own risk. Custom/advanced systems won't be supported by this project's team.*
- *Please monitor the memory consumption when using customizations. Getting closer to the full memory can drive to errors in the system or prevent your system to support the future updates.*

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
      - nspanel_esphome.yaml # Core package
      # - nspanel_esphome_addon_climate_cool.yaml # activate for local climate (cooling) control
      # - nspanel_esphome_addon_climate_heat.yaml # activate for local climate (heater) control
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
By default, the Wi-Fi password will be used as your OTA password, but you can replace it.<br>
First, you need to change the default password using this code.
```yaml
# change OTA password, remove after flashing
esphome:
  on_boot:
    - lambda: |-
        id(my_ota).set_auth_password("New password");
ota:
  password: !secret wifi_password
  id: my_ota
```
After flashing the device, you must remove the code above and replace it with the code below to start using this customization.
```yaml
# Use my global OTA password
ota:
  password: !secret ota_password
```
&nbsp;
### Web server credentials
By default, the web server credentials are defined by this project using `admin` as `username` and your `Wi-Fi password` as `password`, but you can replace it using this customization:
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
    fast_connect: true
```
&nbsp;
### Connect to multiple networks
NSPanel will attempt to connect to the one with the highest signal strength or, if you set a priority, it will try to connect to the highest priority. After failing it will connect to the second network.
```yaml
# Set dual network
wifi:
  networks:
    - id: !extend wifi_default
      priority: 10
    - ssid: !secret wifi_ssid_backup
      password: !secret wifi_password_backup
      priority: 0
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

&nbsp;
### Sensor for display awake vs sleeping
Creates a binary sensor to indicate either when the display is showing some page (`on`) or sleeping (`off`).
```yaml
# Is display awake?
binary_sensor:
  - name: ${device_name} Display state
    id: display_state
    platform: template
    lambda: |-
      return (id(current_page).state != "screensaver");
```

You can easily invert the meaning to have a sensor for display sleeping:
```yaml
# Is display sleeping?
binary_sensor:
  - name: ${device_name} Display sleeping
    id: display_sleeping
    platform: template
    lambda: |-
      return (id(current_page).state == "screensaver");
```

&nbsp;
### Button to upload `nspanel_blank.tft`
This can also be used for any other alternative tft file you might want to use frequently:

```yaml
button:
  ##### UPDATE TFT BLANK DISPLAY #####
  - name: ${device_name} Update TFT display (blank)
    platform: template
    icon: mdi:file-sync
    id: tft_update_blank
    entity_category: config
    on_press:
      - logger.log: "Button pressed: Update TFT display (blank)"
      - binary_sensor.template.publish:
          id: nextion_init
          state: false
      - delay: 16ms
      - lambda: |-
          id(disp1)->set_tft_url("${nextion_update_blank_url}");
          id(disp1).upload_tft();
```
You also must add the url for the alternative tft in your substitutions, like this:
```yaml
  nextion_update_blank_url: "http://homeassistant.local:8123/local/nspanel/dev/nspanel_blank.tft"
```

&nbsp;
### Deep sleep
In this example, the panel will deep sleep for 7 hours, starting at 23:00:00 every day, for its maximum energy saving.

During this time, nothing will be shown, the screen will be off and therefore no response to touch, and the panel will be disconnected from Wi-Fi, but you can still wake-up the panel by pressing one of the hardware buttons (the left one in this example):

```yaml
# Define the wake-up button. Use pin 14 for left button or pin 27 for right button
deep_sleep:
  wakeup_pin: 14
  wakeup_pin_mode: INVERT_WAKEUP

time:
  - id: !extend time_provider
    on_time:
      - hours: 23
        minutes: 0
        seconds: 0
        then:
          - deep_sleep.enter:
              sleep_duration: 7h
```

You can find more ideas around this on [#955](https://github.com/Blackymas/NSPanel_HA_Blueprint/issues/955).

&nbsp;
### Enforce time zone
Until v3.4 (including), the time was coming from Home Assistant with it's timezone, so the Blueprint was sending the info with no transformation, to the panel.
From v4.0, the time reference still coming from HA (or optionally from a time server), but is calculated in ESPHome, which will try to detect the timezone from the server.

If your system is not showing the time in the correct timezone, it's probabily ESPHome not succeeding on finding your time zone.
You can easily force a timezone by adding this to your ESPHome settings:

```yaml
time:
  - id: !extend time_provider
    timezone: "America/Cancun"
```

&nbsp;
### Compiling ESPHome on lower powered machines
For systems with lower CPU or memory capabilities, like an RPi 3 or systems with less than 2GB of RAM, this could help preventing errors caused by lack of resources when compiling ESPHome firmware.

More datails on the [ESPHome docs](https://esphome.io/changelog/2022.11.0.html#running-esphome-on-lower-powered-machines).
```yaml
# Limit the amount of resources used for compiling
esphome:
  compile_process_limit: 1
```

&nbsp;
### Sleep & Wake-up buttons
There are several ways to wake-up or put your panel to sleep, but in this example we tried a simple approach by adding two buttons (you can implement only one of those if you want):
```yaml
button:
  # Adds a button to put the panel to sleep
  - name: ${device_name} Sleep
    id: force_sleep
    platform: template
    icon: mdi:sleep
    on_press:
      then:
        - logger.log: Button Sleep pressed
        - lambda: |-
            if (id(current_page).state != "screensaver") id(disp1).goto_page("screensaver");
  
  # Adds a button to wake-up the panel (similar to the existing service)
  - name: ${device_name} Wake-up
    id: force_wake_up
    platform: template
    icon: mdi:alarm
    on_press:
      then:
        - logger.log: Button Wake-up pressed
        - lambda: |-
            if (id(current_page).state == "screensaver") id(disp1).goto_page(id(wakeup_page_name).state.c_str());
            // id(timer_page).execute(id(wakeup_page_name).state.c_str()); // enable this if you want page timeout to be reset
            id(timer_sleep).execute(id(wakeup_page_name).state.c_str(), int(id(timeout_sleep).state));
            id(timer_dim).execute(id(wakeup_page_name).state.c_str(), int(id(timeout_dim).state));
```
