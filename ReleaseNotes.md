## General
This patch includes bug fixes only, with no new functionality implemented.

You can see the list of changes below and decided what to update based on how you are affected by the different changes.

There is compatibility between components with v4.0, v4.0.1 and v4.0.2, then your system will work with no issues with a mix of those versions, althoug we recommend always updating all the components to the latest version available.

### Instructions
 _You can find the update procedures following here:_
- [(EN) How To - All important thing you should know - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-HowTo---All-important-thing-you-should-know#2-update-blueprint)
- [(DE) How To - Alle wichtigen Dinge die man wissen sollte - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#2-update-blueprint)


&nbsp;
## Overview of all changes

| Change | Criticality | Page/area | Components affected |
| :-- | :--: | :--: | :--: |
| Fix incorrect addressing on short press of button02 at buttonpage03 | Critical | `buttonpage03` | TFT (US model only) |
| Fix incorrect service call for Media Player on short press at button pages | Medium | `buttonpageXX` | Blueprint |
| Update to customization instructions | Low | N/A | GitHub page (docs) |
| Use UTC for date selection on weather pages | Low | `weatherXX` | Blueprint |
| Removed unnecessary refresh of relay's chips | Low | `home` | ESPHome |