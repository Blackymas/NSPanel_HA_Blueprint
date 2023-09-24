## General
This patch includes bug fixes only, with no new functionality implemented.

You can see the list of changes below and decided what to update based on how you are affected by the different changes.

There is compatibility between components with v4.0 and v4.0.1, then your system will work with no issues with a mix of those versions, althoug we recommend always updating all the components to the latest version available.

### Instructions
 _You can find the update procedures following here:_
- [(EN) How To - All important thing you should know - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(EN)-HowTo---All-important-thing-you-should-know#2-update-blueprint)
- [(DE) How To - Alle wichtigen Dinge die man wissen sollte - Update](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#2-update-blueprint)


&nbsp;
## Overview of all changes

| Change | Criticality | Page/area | Components affected |
| :-- | :--: | :--: | :--: |
| Incorrect button addressing on long press at buttonpage03 | Critical | `buttonpage03` | TFT (US model only) |
| Volume button not working | Medium | `media_player` | TFT |
| Fixes on instructions | Minor | N/A | Blueprint<br>GitHub page (docs) |
| Prevents media player crashing when called before `media_position_updated_at` is able to provide a value. | Minor | `media_player` | Blueprint |
| Add instructions to enforce a timezone selection in customizations | Minor | N/A | GitHub page (docs) |
| Translations to Dutch | Minor | `settings` | Blueprint |
| Removed `display_current_brightness` messages from log | Minor | N/A | ESPHome |
| Version control to support patches | Minor | N/A | ESPHome |
| Support for flexible time format | Minor | `home` | Blueprint |
| Added date format for Finish | Minor | `home` | Blueprint |
| Reset sleep timer when brightness settings changes | Minor | All | ESPHome |

## Special thanks to:
* @chpego
  - Fixes on README.md and blueprint UI (#1059)

## New Contributors
* @chpego
