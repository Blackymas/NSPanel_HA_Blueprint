## Support this project

### As always, we would like to thank everyone who donated to this project and remind you that every donation helps to support this project - so if you haven't made a donation yet, now would be a good time ;)

[![Paypal](https://user-images.githubusercontent.com/41958506/212499642-b2fd097a-0938-4bfc-b37b-74df64592c58.png)](https://www.paypal.com/donate/?hosted_button_id=S974SWQMB8PB2)

&nbsp;
## General

### 

&nbsp;
## Updating
Since in this update lots of input to the blueprint changed, we highly recommend you review your settings and make sure all fields have the correct selection. We did our best to support your legacy settings and avoid breaking your system, but please double check your settings if you see something not working as expected.

### Files that need to be reloaded:
1. nspanel_blueprint.yaml - v3.5
2. nspanel_eu.tft or nspanel_us.tft - v3.5
3. nspanel_esphome.yaml - v3.5

### Instructions
 _You can find the update procedures following here:_
- [(EN) HowTo - All important thing you should know - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-HowTo---All-important-thing-you-should-know#2-update-blueprint)
- [(DE) HowTo - Alle wichtigen Dinge die man wissen sollte - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#2-update-blueprint)
&nbsp;
## Breaking changes

&nbsp;
## Overview of all changes
1. Alarm control panel

&nbsp;
## Details of all changes

### 1. Alarm control panel
recommend api-encryption: https://esphome.io/components/api.html#configuration-variables
and, of course warn the user that this is a possible security issue.
Anyways - this is also done with many other projects, AND it would require that a possible hacker is already inside the internal (or mayby iot) (W)LAN - and at this point....
recommend to have a big warning, and that the user has to take care about e.g.:
- secure internal network
- split internal networks: IOT, Guest, Internal, Management, ...
- enable api-encryption


&nbsp;

## Next topics we are currently working on
See here: https://github.com/Blackymas/NSPanel_HA_Blueprint/labels/roadmap

## What's Changed
* 

## New Contributors
* 
