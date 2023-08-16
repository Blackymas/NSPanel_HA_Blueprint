# Alarm Control Panel

You can control an Alarm Control Panel from your NSPanel, which will allow you to set the alarm mode between the standard modes supported by Home Assistant (Home, Away, Night, Vacation or Custom bypass) or disarm the alarm.

Currently, only alarms without a code or alarms with a numeric code will be supported. If your alarm requires a text code, you will still be able to display it on your NSPanel, however, when you click in any button it will send services calls to Home Assistant without the code and it will fail for the calls where a code is required.

&nbsp;
### Security advisory

By default, the communication between your NSPanel (ESPHome) and Home Assistant (HA) is not encrypted, which means a person with access to your network could potentially monitor the communication between your panel and HA and replicate the service calls. Although this is not a big issue for most of the service calls (turn-on a light, close a curtain, etc.), it can be a problem when controlling your alarm system.<br>
Based on that, we hardly reccoment the use of API encryption for all users controlling an Alarm system via a NSPanel. You can easily enable this by following the ["API encryption" example available here](customization.md#api-encryption).

&nbsp;
## Configuration
### Allow the device to make Home Assistant service calls
First, you have to configure your Home Assistant to allow your panel to make service calls. All other services are called from the Blueprint, however this requires the ESPHome to send an event containing in plain text all the information needed to the service call, which could be a security issue, so all the alarm calls will be driven by the panel to ensure a safer environment.<br>
To enable this option, go to your ESPHome integrations panel (Settings > Devices and Services > ESPHome) and click "Configure" next to the entry related to your panel:<br>
<< ADD SCREENSHOT >><br>
Then check the option "Allow the device to make Home Assistant service calls":<br>
<< ADD SCREENSHOT >><br>
### Blueprint settings
Open the automation based on the NSPanel Blueprint and look for a section related to "Alarm Control Panel".<br>
Select your alarm control panel entity, click "Save", and your are done. :sunglasses:<br>
<<< ADD SCREENSHOT >>>>

&nbsp;
## Controlling your alarm from your panel
When an alarm control panel is set in your Blueprint automation, you will see the alarm icon on your panel's Home page:<br>
<<< ADD ICON IMAGE >>>><br>
![Home page](https://user-images.githubusercontent.com/41958506/212768891-9610d800-43c5-454f-a8b6-6b7c43677b5d.png)

A click on that icon will show the Alarm Control Panel page:<br>
<<< ADD SCREENSHOT >>>>

You can change your alarm settings with a single click on the button related to the new state you want to set your alarm to, or close the page to go back to Home page.