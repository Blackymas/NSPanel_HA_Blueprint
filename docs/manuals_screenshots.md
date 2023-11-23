# Nextion instructions used for screenshots

Please select "Instruction codes: utf-8" in the Nextion simulator

### Boot page
```
page boot
ip_addr.txt="192.168.0.33"
baud_rate.txt="115200 bps"
framework.txt="arduino"
esph_version.txt=tft_version.txt
bluep_version.txt=tft_version.txt
vis bt_reboot,1
```

![Boot EU](pics/eu_boot.png)
<br>
![Boot US](pics/us_boot.png)

### Home page
#### EU version
```
page home
date.txt="Sunday, 29/11"
outdoor_temp.txt="8.9°"
time.txt="12:34"
vis wifi_icon,1
wifi_icon.txt=""
weather.pic=11
left_bt_text.txt="Ceiling lights"
left_bt_pic.pic=32
icon_top_01.txt=""
right_bt_text.txt="Desk lights"
icon_top_03.txt=""
icon_top_03.pco=64164
icon_top_06.txt=""
icon_top_08.txt="侀"
current_temp.txt="21.6 °C"
indoortempicon.txt=""
value01_state.txt="47%"
value01_icon.txt=""
bt_notific.txt=""
vis bt_notific,1
bt_qrcode.txt=""
vis bt_qrcode,1
bt_entities.txt=""
vis bt_entities,1
bt_alarm.txt=""
bt_alarm.pco=19818
vis bt_alarm,1
button01.txt=""
button02.txt=""
button03.txt=""
value03_state.txt="715 W"
value03_icon.txt=""
```
![Home EU](pics/eu_home.png)

#### US version
```
page home
meridiem.txt="PM"
date.txt="Sunday, 11/29"
outdoor_temp.txt="48°"
time.txt="12:34"
vis wifi_icon,1
wifi_icon.txt=""
weather.pic=11
left_bt_text.txt="Ceiling lights"
left_bt_pic.pic=32
icon_top_01.txt=""
right_bt_text.txt="Desk lights"
icon_top_03.txt=""
icon_top_03.pco=64164
icon_top_06.txt=""
icon_top_08.txt="侀"
current_temp.txt="71 °F"
indoortempicon.txt=""
value01_state.txt="47%"
value01_icon.txt=""
bt_notific.txt=""
vis bt_notific,1
bt_qrcode.txt=""
vis bt_qrcode,1
bt_entities.txt=""
vis bt_entities,1
bt_alarm.txt=""
bt_alarm.pco=19818
vis bt_alarm,1
button01.txt=""
button02.txt=""
button03.txt=""
value03_state.txt="715 W"
value03_icon.txt=""
```
![Home US](pics/us_home.png)

### Settings page
```
page settings
```

![Settings EU](pics/eu_settings.png)
![Settings US](pics/us_settings.png)
