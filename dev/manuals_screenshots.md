# Nextion instructions used for screenshots

Please select "Instruction codes: utf-8" in the Nextion simulator

### Boot page
```
page boot
baud_rate.txt="115200 bps"
esph_version.txt="4.2"
bluep_version.txt="4.2"
tft_version.txt="4.2"
vis bt_reboot,1
framework.txt="esp-idf"
ip_addr.txt="192.168.0.123"
```

![Boot EU](/docs/pics/eu_boot.png)
<br>
![Boot US](/docs/pics/us_boot.png)

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
![Home EU](/docs/pics/eu_home.png)

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
![Home US](/docs/pics/us_home.png)

### Settings page
```
page settings
```

![Settings EU](/docs/pics/eu_settings.png)
![Settings US](/docs/pics/us_settings.png)


### Buttons pages (DRAFT)
```
api=1
page buttonpage01
page_label.txt="Bedroom"
vis 255,1
button01pic.picc=47
button01text.picc=47
button01icon.picc=47
button01bri.picc=47
button01text.txt="Ceiling\rlights"
button01text.pco=10597
button01icon.txt=""
button01icon.pco=64704
button01icon.font=10
button01bri.txt="100%"
button01bri.pco=10597
button02pic.picc=46
button02text.picc=46
button02icon.picc=46
button02bri.picc=46
button05pic.picc=47
button05text.picc=47
button05icon.picc=47
button05bri.picc=47
button05text.txt="Windows\rlights"
button05text.pco=10597
button05icon.txt=""
button05icon.pco=64704
button05icon.font=8
button05bri.txt="100%"
button05bri.pco=10597
button06pic.picc=46
button06text.picc=46
button06icon.picc=46
button06bri.picc=46
```