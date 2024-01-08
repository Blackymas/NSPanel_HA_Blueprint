# Alarm Control Panel

You can control an Alarm Control Panel from your NSPanel,
which will allow you to set the alarm mode between the standard modes supported by
Home Assistant (Home, Away, Night, Vacation or Custom bypass) or disarm the alarm.

Currently, only alarms without a code or alarms with a numeric code will be supported.
If your alarm requires a text code, you will still be able to display it on your NSPanel,
however, when you click in any button it will send services calls to Home Assistant
without the code and it will fail for the calls where a code is required.

> [!IMPORTANT]
> **Security advisory**
> By default, the communication between your NSPanel (ESPHome) and Home Assistant (HA) is not encrypted,
> which means a person with access to your network could potentially monitor the communication between your panel and HA and replicate the service calls.
> Although this is not a big issue for most of the service calls (turn-on a light,
close a curtain, etc.), it can be a problem when controlling your alarm system.
>
> Based on that, we hardly reccoment the use of API encryption for all users controlling an Alarm system via a NSPanel.
> You can easily enable this by following the ["API encryption" example available here](customization.md#api-encryption).

## Configuration

### Allow the device to make Home Assistant service calls

First, you have to configure your Home Assistant to allow your panel to make service calls.
All other services are called from the Blueprint, however this requires the ESPHome to send
an event containing in plain text all the information needed to the service call,
which could be a security issue, so all the alarm calls will be driven by the panel to ensure a safer environment.

To enable this option, go to your ESPHome integrations panel (Settings > Devices and Services > ESPHome)
and click "Configure" next to the entry related to your panel:

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/37bfc622-c0cd-4941-a397-3eeb2ddbe6a2)

Then check the option "Allow the device to make Home Assistant service calls":

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/9b20a1b6-94ad-4fff-aef2-eb3599db9bf1)

### Blueprint settings

Open the automation based on the NSPanel Blueprint and look for a section related to "Alarm Control Panel".

Select your alarm control panel entity, click "Save", and your are done. :sunglasses:

![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/859d3f4b-9a05-4694-9e2c-c32ab3a5e22f)

## Controlling your alarm from your panel

When an alarm control panel is set in your Blueprint automation,
you will see the alarm icon on your panel's Home page.
This icon will change following the alarm state as described in the table below.

A click on that icon will show the Alarm Control Panel page:


![image](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/bc312981-3d5a-42c7-b0b4-203457ff549f)

You can change your alarm settings with a single click on the button related to the new state
you want to set your alarm to, or close the page to go back to Home page.

### Description of states shown with the alarm icon

State | Color | Icon | Icon name | Description
-- | -- | -- | -- | --
disarmed | White |![shield-off-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/5b1c8219-3958-4096-9100-0b4ef47e7dac)|mdi:shield-off-outline | The alarm is disarmed (off).
armed_home | Green |![shield-home-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/1ed9347b-139a-4729-a795-b08934b56581)| mdi:shield-home-outline | The alarm is armed in home mode.
armed_away | Green |![shield-lock-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/998db33c-3ec5-47dd-9686-c28eee81e9eb)| mdi:shield-lock-outline | The alarm is armed in away mode.
armed_night | Green |![shield-moon-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/84528bca-577d-4a43-8366-e6f9e41bc7b4)| mdi:shield-moon-outline | The alarm is armed in night mode.
armed_vacation | Green |![shield-airplane-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/067218de-ec8c-4fce-a427-7848a7ae9f27)| mdi:shield-airplane-outline | The alarm is armed in vacation mode.
armed_custom_bypass | Green |![shield-half-full](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/af7ed346-28eb-4796-b62b-2a51e9cb6272)| mdi:shield-half-full | The alarm is armed in bypass mode.
pending | Amber |![shield-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/31bcd613-04d6-455a-a443-3299211d487e)| mdi:shield-outline | The alarm is pending (towards triggered).
arming | Amber |![shield-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/31bcd613-04d6-455a-a443-3299211d487e)| mdi:shield-outline | The alarm is arming.
disarming | Amber |![shield-off-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/37c02584-dd65-4575-8d95-c7346de599e4)| mdi:shield-off-outline | The alarm is disarming.
triggered | Red |![shield-alert-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/ee1ec55b-e671-4aa0-9baa-77eb2a8c8c7f)| mdi:shield-alert-outline | The alarm is triggered.
unknown / unavailable | White |![shield-alert-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/a382e5ab-2e16-453c-bc9b-b3dcd3825de7)| mdi:shield-alert-outline | The alarm state is unknown or unavailable.
