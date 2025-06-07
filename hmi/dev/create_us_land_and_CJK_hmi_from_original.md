# Creating additional TFT files

Note: the script `scripts/generate_derived_hmi.sh` will do the below steps automatically for you. If the script fails however these are the steps that need to be done:

## Creating `nspanel_us_land.HMI` from `nspanel_eu.HMI`

- **Program.s:**
    - Change to `display_mode=3`

- **Page boot:**
    - Change component `progress` (the progress bar in the very bottom) width to `480`.

## Creating `nspanel_CJK_xxx.HMI` from `nspanel_xxx.HMI`

- **Program.s:**
    - Change to `charset=2`

- **Fonts:**
    - Replace all fonts by the ones available under `hmi/dev/ui/fonts/cjk` folder.
