# Creating `nspanel_us_land.HMI` from `nspanel_eu.HMI`:

## Program.s:
Comment out `lcd_dev fffb 0002 0000 0020`

## Page `home`:
1. Change left_bt_pic (x,y,w,h) from ( 47,307,120,3) to (467,173,3,120)
2. Change right_bt_pic(x,y,w,h) from (288,307,120,3) to (467, 27,3,120)
3. Rotate pictures 30 & 31 by 90degrees - You will find the pics under pics folder where this instruction file is
4. Add the following to "Preinitialize Event" on page `home` (at the end) to hide those elements:
```
vis left_bt_text,0
vis right_bt_text,0
```
