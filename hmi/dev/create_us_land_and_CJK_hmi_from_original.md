# Creating additional TFT files

## Creating `nspanel_us_land.HMI` from `nspanel_eu.HMI`

- **Program.s:**
    - Change to `display_mode=3`

- **Page boot:**
    - Change component `progress` (the progress bar in the very bottom) width to 480.

## Creating `nspanel_CJK_xxx.HMI` from `nspanel_xxx.HMI`

- **Program.s:**
    - Change to `charset=2`

- **Fonts:**
    - Replace `ubuntuXX` fonts by the ones available under `\dev\ui\fonts\CJK` folder.
