This article covers the settings in the Blueprint Automation. 

The Blueprint Automation is the central configuration element of this solution for the NSPanel.&nbsp;
In principle, the setup of the automation is self-explanatory. The individual elements of the Blueprint are described below.

It is possible to change both the color of the labels and the icons for most of the elements on each screen.

Default color is "65535". The desired Nextion color code can be found at

``https://nodtem66.github.io/nextion-hmi-color-convert/index.html``

The icons under the following link can be used: 
``https://htmlpreview.github.io/?https://github.com/jobr99/Generate-HASP-Fonts/blob/master/cheatsheet.html``

For an easier overview, the menu items "Icon Color" and "Label Color" will not be described separately in the following documentation.

&nbsp;   
# Parameters

### ESPhome Node Name 

Refers to the ESPhome device name. **Allowed characters are "__",a-z, 0-9, but no special characters or spaces**. This is a restriction on the side of HA, since the respective entity_IDs are generated from the device name of the blueprint.

### Language for NSPanel 

The language can be selected via the drop-down menu. Currently 26 languages are supported.

### Delay to avoid synchronization problems

If the WiFi signal is poor, menus may not be loaded completely. If this happens, a delay in 5ms increments can be set here to compensate for this.



## Weather and Temperature

### Weather integration
Choose between HA own weather integration or the more accurate Accuweather.

### Weather entity from HA

Dropdown menu to select the Weather entity to use. Example: If "Accuweather" is selected in item 7, then the entity for Accuweather must be selected here.

### Outdoor temperature Sensor (Optional)

Optionally, the value of an outdoor temperature sensor can be used here. If no separate sensor is used, the value of the weather integration will be used.

### Indoor Temperature Sensor (Optional)

An indoor temperature sensor is not necessary. Leave the field empty if you want to use the temperature sensor of the NSPanel. If the value of the sensor needs to be corrected, this can be done via the temperature correction for the NSPanel under HA Devices. 



## Sensor Home Page

#### Sensor 01-03 - Entity (Optional)

Up to three sensors can be displayed on the home screen. Select the corresponding HA entity.



## Chips

#### Chip 01-07 - Entity (Optional)

Used to display HA entities on the home screen. For example to display the status of a specific switch on the NSPanel. 


## Climate

### Climate to Control (Optional)

If a Climate Integration is to be controlled, it must be entered here. This can then be accessed via the temperature on the home screen of the NSPanel.

### Climate Control optimistic Mode (Optional)

Depending on the climate control, the optimistic mode can be used for better response. The changes made are only transferred to the device when the screen is exited.

### Hot Water Charge Button (Optional)

Optional hot water switch, e.g. for a boiler.


## QR Code

### Activate QR Code - TRUE/FALSE (Optional)

Activates the QR Code Page and the QR Code Button on the home page 


### QR Code content (Optional)

String, which is shown as a QR Code on the NSPanel. This can be a simple text, a URL or could also be used for a simplified login to the WiFi. Here is an example (simply change SSID and password to your credentials and either use "WPA" or "WEP"):

```WIFI:S:SSID;T:WPA/WEP;P:PASSWORD;;``` 



## Hardware Buttons

### Delay for HW-Buttons hold in seconds - VALUE

Setting for how long a button must remain pressed in order to be recognized as a "hold". Default: 1 second.

### Activate Relay x local Fallback (Optional)

Normally, the internal relays of the NSPanels are triggered via HA. If the NSPanel loses WiFi connection or HA is down, the hardware button can then switch the corresponding relay directly.

### Left/Right Hardware Button - Entity (Optional)

The entity that should be switched with the left/right hardware button.

### Left/Right Hardware Button Name - Label (Optional)

Text on the screen above the corresponding hardware button (home screen).

### Left/Right Hardware Button hold assignment - VALUE (optional)

Selection of what action should happen when the button is pressed for a longer time.

### Left/Right Hardware Button custom hold action - VALUE (Optional)

Selection of the action to start when holding the button.



## Button Page 01-04

### Button Page 01-04 name - LABEL (Optional)

Text on the respective button screens.

### Buttons 01 - 32 (Optional)

The buttons can be accessed by swiping on the Home Screen and their functions are completely identical.
Either the individual button pages can be accessed one after the other by swiping to the left, or the button pages can be accessed directly by swiping up, down or to the right.

The buttons are numbered as follows:

|       | Button Page 1 | Button Page 2 | Button Page 3 | Button Page 4 |
| ----- | ------------- | ------------- | ------------- | ------------- |
| Row 1 | 01 02 03 04   | 09 10 11 12   | 17 18 19 20   | 25 26 27 28   |
| Row 2 | 05 06 07 08   | 13 14 15 16   | 21 22 23 24   | 29 30 31 32   |

The following entities can be stored:

 - Light
 - Switch
 - Cover
 - Input Boolean
 - Automation
 - Button
 - Input Button
 - Scene
 - Person
 - Script
 - Binary Sensor
 - Fan
 - Climate

When the respective button is pressed, the corresponding page is automatically opened, e.g. the cover control for covers, etc.
For each button an own name can be specified optionally.
All buttons offer the possibility to optionally confirm the execution of the action. This can be activated or deactivated separately for each button via *"Confirm execution of the button press"*.



## Entity Page 01-04

### Activate Entity Page - TRUE/FALSE (Optional)

This option activates the entity pages on the Home Screen. The entity pages can be used for example to display values or statuses of entities on the individual pages.

### Entity Page 01-04 name - LABEL (Optional)

Naming of the corresponding Entity Screens.

### Entity 01 - 32 (Optional)

The entity pages can be accessed by pressing the symbol on the Home Screen and their functions are completely identical.

The entities are numbered as follows:

|       | Entity Page 1 | Entity Page 2 | Entity Page 3 | Entity Page 4 |
| ----- | ------------- | ------------- | ------------- | ------------- |
| Row 1 | 01 02 03 04   | 09 10 11 12   | 17 18 19 20   | 25 26 27 28   |
| Row 2 | 05 06 07 08   | 13 14 15 16   | 21 22 23 24   | 29 30 31 32   |

Additionally there is the possibility to choose an icon of your choice from 6896 icons.

Of course there is also the possibility to enter your own entity label and to assign a label for the 4 pages. If no entity label is set, the friendly name is taken from HA.

The currently implemented symbols can be found here: https://htmlpreview.github.io/?https://github.com/jobr99/Generate-HASP-Fonts/blob/master/cheatsheet.html

**To use the icons in the Blueprint you would have to click on the "U" on the website to copy the icon and then paste it in the Blueprint** *(Attention: Only a "strange" character is displayed, but that is correct).*


## Custom Configuration

### Hot Water Temperature Sensor (Optional)

Optional Hot Water Sensor. 

### Top 04 Flame

Displays a flame symbol on the home screen, e.g. when a boiler is switched on.
 
### Nextion TFT File Folder

Can be left blank. However, it is required if a custom TFT configuration is to be used.

### Synchronization of all values (Optional)

Light and cover pages (values) are updated continuously (may cause flickering).

### Synchronization of all all sliders (Optional)

Light and cover pages (cover position) are updated continuously (may cause flickering).





***

Example Screenshots

![image-20230317162851693](./assets/image-20230317162851693.png)

![image-20230317162944247](./assets/image-20230317162944247.png)

![image-20230317163012105](./assets/image-20230317163012105.png)

![image-20230317163035519](./assets/image-20230317163035519.png)
