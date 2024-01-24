# Alarm Control Panel

You can control an Alarm Control Panel from your NSPanel, which allows you to set the alarm mode to standard 
modes supported by Home Assistant (Home, Away, Night, Vacation, or Custom bypass) or disarm the alarm.

Currently, the NSPanel supports alarms without a code or with a numeric code. For alarms using a text code, 
the NSPanel will display it, but interactions (like button clicks) will send service calls to Home Assistant 
without the code, leading to failed operations that require a code.

> [!IMPORTANT]
> **Security advisory**
> The default communication between your NSPanel (ESPHome) and Home Assistant (HA) is not encrypted. This 
> could allow someone with network access to monitor and replicate the service calls. This risk is 
> particularly relevant when controlling your alarm system.
>
> To enhance security, we strongly recommend enabling API encryption for NSPanel users managing an Alarm 
> system. Follow the instructions in the ["API encryption" example here](customization.md#api-encryption) 
> to implement this security measure.
## Configuration

### Allow the device to make Home Assistant service calls

First, you need to configure your Home Assistant to permit your NSPanel to make service calls. While 
most services are handled via the Blueprint, ESPHome needs to send events with all necessary data in 
plain text for these service calls. To mitigate any security risks, alarm-related calls are managed 
directly by the panel.

To enable this:
1. Go to your ESPHome integrations panel (Settings > Devices and Services > ESPHome).
2. Click "Configure" next to your panel's entry.

   ![Configure option in ESPHome integrations panel](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/37bfc622-c0cd-4941-a397-3eeb2ddbe6a2)

3. Select the "Allow the device to make Home Assistant service calls" option.

   ![Allow service calls option in ESPHome configuration](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/9b20a1b6-94ad-4fff-aef2-eb3599db9bf1)

### Blueprint settings

To assign Alarm Control Panel entities to buttons:
1. Open the NSPanel Blueprint automation.
2. Find the button configuration section.
3. Choose a button and select your alarm control panel entity.
4. Click "Save" to complete setup.

   ![Assigning Alarm Control Panel entities in Blueprint](pics/ha_blueprint_home_custom_buttons_alarm.png)

Follow these steps to ensure your NSPanel is correctly configured for controlling your alarm system.
## Controlling your alarm from your panel

When an alarm control panel is configured in your Blueprint automation, the alarm icon appears on your 
NSPanel's Home page or the respective button page. This icon changes based on the alarm state, detailed 
in the following table.

Clicking this button opens the Alarm Control Panel page. Here, you can adjust alarm settings with a 
single click or return to the Home page.

![View of the Alarm Control Panel page on NSPanel](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/bc312981-3d5a-42c7-b0b4-203457ff549f)
### Description of states shown with the alarm icon

<!-- markdownlint-disable MD013 -->
State | Color | Icon | Icon Name | Description
-- | -- | -- | -- | --
disarmed | White | ![shield-off-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/5b1c8219-3958-4096-9100-0b4ef47e7dac) | mdi:shield-off-outline | The alarm is disarmed (off).
armed_home | Green | ![shield-home-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/1ed9347b-139a-4729-a795-b08934b56581) | mdi:shield-home-outline | The alarm is armed in home mode.
armed_away | Green | ![shield-lock-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/998db33c-3ec5-47dd-9686-c28eee81e9eb) | mdi:shield-lock-outline | The alarm is armed in away mode.
armed_night | Green | ![shield-moon-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/84528bca-577d-4a43-8366-e6f9e41bc7b4) | mdi:shield-moon-outline | The alarm is armed in night mode.
armed_vacation | Green | ![shield-airplane-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/067218de-ec8c-4fce-a427-7848a7ae9f27) | mdi:shield-airplane-outline | The alarm is armed in vacation mode.
armed_custom_bypass | Green | ![shield-half-full](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/af7ed346-28eb-4796-b62b-2a51e9cb6272) | mdi:shield-half-full | The alarm is armed in bypass mode.
pending | Amber | ![shield-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/31bcd613-04d6-455a-a443-3299211d487e) | mdi:shield-outline | The alarm is pending (towards triggered).
arming | Amber | ![shield-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/31bcd613-04d6-455a-a443-3299211d487e) | mdi:shield-outline | The alarm is arming.
disarming | Amber | ![shield-off-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/37c02584-dd65-4575-8d95-c7346de599e4) | mdi:shield-off-outline | The alarm is disarming.
triggered | Red | ![shield-alert-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/ee1ec55b-e671-4aa0-9baa-77eb2a8c8c7f) | mdi:shield-alert-outline | The alarm is triggered.
unknown/unavailable | White | ![shield-alert-outline](https://github.com/Blackymas/NSPanel_HA_Blueprint/assets/94725493/a382e5ab-2e16-453c-bc9b-b3dcd3825de7) | mdi:shield-alert-outline | The alarm state is unknown or unavailable.
<!-- markdownlint-enable MD013 -->
