
In diesem Beitrag werden wir alle wichtigen Dinge zu verschiedenen Themen zusammen tragen, die im Laufe der Zeit uns auffallen.&nbsp;
> ### _**HINWEIS! sollte dir bei der Konfiguration etwas auffallen oder du irgendein Problem hattest und es lösen konntest, wäre es für uns und alle anderen in der Community super, wenn du dein Wissen mit uns teilst. Dazu kannst du mir ein kurze Nachricht schreiben und ich nehme es in diesem Beitrag dann mit auf.**_ 

&nbsp;  
> ### WICHTIG! Wenn du ein Problem bei der Einrichtung oder einer Funktion hast und ein _**"Issue auf Github"**_ eröffnest, beschreibe dein Problem bitte so genau wie möglich. Auch Bilder können hier helfen.

&nbsp;  
> ### WICHTIG! Wenn du ein _**"Issue"**_ eröffnest, folge bitter der Anleitung sieh hier [Wie erstelle ich "Issues"](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#1-wie-erstelle-ich-issues-wenn-ich-ein-problem-habe)

&nbsp;  
&nbsp;  

***

&nbsp;   
# Inhalt:

1. [Wie erstelle ich "Issues" wenn ich ein Problem habe ](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#1-wie-erstelle-ich-issues-wenn-ich-ein-problem-habe) 
1. [Update Blueprint](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#2-update-blueprint)
1. [Update ESPHome](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#3-update-esphome)
1. [Update TFT](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#4-update-tft)
1. Manueller TFT Upload über lokalen HA (in Arbeit)
1. Upload TFT Fehler und Lösung (in Arbeit)
1. [Notification via HA](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#7-notification-via-ha)
1. [Climate für Relays](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#8-climate-für-relays)
1. [Interne Switches als Lampe darstellen in HA](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#9-interne-switches-als-lampe-darstellen-in-ha)
1. Schnell Navigation (in Arbeit)
1. [Bestimmte Seiten direkt aufrufen](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#11-bestimmte-seiten-direkt-aufrufen)
1. [RTTTL Sound abspielen](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#12-rtttl-sound-abspielen)
1. Erweiterte Funktionen und Automatisierungen (in Arbeit)
1. [Automationen starten via Input_Boolean](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte#14-automationen-starten-via-input_boolean)



&nbsp;  

***

&nbsp; 

## 1. Wie erstelle ich "Issues" wenn ich ein Problem habe
> _**Um dein Problem lösen zu können, ist es für uns wichtig so viele Informationen wie möglich zu haben**_

* Probleme können auf DE oder EN erstellt werden.
* Beschreibe dein Problem so genau wie möglich.
* Schreibe bitte deine ESPHome und Home Assistant Version 
* gehe bitte auf deine Automation und dann auf die "3 Punkte" und danach auf _**Als YAML bearbeiten**_. Kopiere den kompletten Code und füge es dem Ticket bei
* Ein wichtiger "Helfer" beim lösen der Probleme ist der Trace einer Automation. Den Trace findest du unter _**Einstellungen --> Automatisierungen & Szenen --> deine NSPanel Automatisierung --> Traces (rechts oben)**_

> TRACES! Bitte führe erneut aus, was nicht funktioniert und öffne danach sofort den Trace. Oft muss auch nach dem Reboot der trace geöffnet werden. Im Boot werden die meisten Dinge geladen.

> WICHTIG! im Trace kannst du anhand der _**"Orangen"**_ Linien sehen welchen Weg die Automation gegangen ist. Bitte teile uns diesen Weg mit. Außerdem erstelle bitte davon ein oder mehrer Screenshots die du deinem Ticket hinzufügst. Besonders wichtig ist für uns wo die _**"Orangen"**_ Linie aufhört, denn meist ist dort auch das Problem

> WICHTIG! Wenn du den Trace geöffnet hast, gibt es ganz oben die _**"Zeitstempel"**_. Es ist wichtig das du den richtigen Zeitstempel auswählst.


### Beispiel Trace nach Reboot:
![Bildschirmfoto 2022-11-27 um 14 54 58](https://user-images.githubusercontent.com/41958506/204139082-70d3a8d1-1c82-43cb-88f2-573f2e276a48.png)

### Beispiel Automatisierungen Blueprint:
```
alias: YYXYYXYYX - NSPanel Configuration
description: ""
use_blueprint:
  path: nspanel_configuration.yaml
  input:
    nspanel_name: nspanel_dev
    language: DE
    sync_value_ha: select_no
    sync_slider_ha: select_no
    weather: AccuWeather
    accuweather: home_wetter
    outdoortemp: sensor.terrasse_garage_motion_sensor_temperature
    humidity: sensor.kinderzimmer_lea_temperatur_sensor_humidity
    hotwatertemp: sensor.hotwater_temp
    hotwatercharge: switch.charge
    heatingsystemflame: binary_sensor.flamestatus
    climate: climate.nspanel_buro
    left_button_entity: light.haustur_spot_2
    right_button_entity: light.haustur_spot_1
    entity01: light.buro_sideboard
    entity01_name: Sideboard
    entity02: cover.kuche_rollo
    entity02_name: Küche Rollo
    entity03: switch.buro_dart_beleuchtung
    entity03_name: Dart Licht
    delay: 2
    right_button_name: Test 1
    left_button_name: Test 2
```

------

## 2. Update Blueprint

>Derzeit bietet HA nicht die Möglichkeit, Blueprints direkt über das UI upzudaten. Dies muss manuell bspw. über den File Editor geschehen.

>WICHTIG! Um eine neue Version des NSPanels zu installieren, muss zwingend der Blueprint, ESPHome sowie das TFT upgedatet werden!

1. Letztes Release des Blueprints von Github aus dem Repository laden.
2. Das existierende YAML File "nspanel_blueprint.yaml" im Folder ***./config/blueprints/automation/Blackymas*** mit der neuen Version ersetzen.
3. Automationen neu laden oder Home Assistant neu starten.
4. Der neue Blueprint steht zur Verfügung. Bereits vorgenommene Einstellungen werden übernommen.
   ![BlueprintUpdate](./(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte.assets/BlueprintUpdate.PNG)

------

## 3. Update ESPHome

>WICHTIG! Um eine neue Version des NSPanels zu installieren, muss zwingend der Blueprint, ESPHome sowie das TFT upgedatet werden!

Zum ESPHome Update auf die ESPHome Integration gehen. 

Dann die Konfiguration validieren:

![image-20230203111717731](./(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte.assets/image-20230203111717731.png)

Wenn die Validierung durchgelaufen ist, erscheint ein grünes Checkmark im oberen Bereich des Fensters. Danach auf "Install" klicken:

![image-20230203111838285](./(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte.assets/image-20230203111838285.png)

Ein neues Fenster öffnet sich, hier die gewünschte Verbindung zum Panel auswählen:

![image-20230203111919475](./(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte.assets/image-20230203111919475.png)

Danach startet der Installationsvorgang. Dies kann ein paar Minuten in Anspruch nehmen:

![image-20230203112632305](./(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte.assets/image-20230203112632305.png)

------

## 4. Update TFT

>WICHTIG! Um eine neue Version des NSPanels zu installieren, muss zwingend der Blueprint, ESPHome sowie das TFT upgedatet werden!

Das Update des Displays kann über das UI erfolgen:

1. Im Menü ***Einstellungen --> Geräte & Services  --> Integrationen*** unter der ESPHome Integration das Display auswählen.

2. Unter Configuration den Switch "Update TFT Display" drücken.

3. Das Display beginnt den Update Prozess und startet anschließend neu.

   ![DisplayUpdate](./(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte.assets/DisplayUpdate.PNG)

------

## 5. Manueller TFT Upload über lokalen HA

In Arbeit

------

## 6. Upload TFT Fehler und Lösung 

In Arbeit

------

## 7. Notification via HA

Um eine Notification auf dem NSPanel anzeigen zu lassen, kann folgender Service Call verwendet werden:

```
service: esphome.panelname_notification_show
data:
  label: Example text
  text: Example text
```

Um die Notifications auf dem Panel zu bestätigen, kann folgender Service Call verwendet werden:

```
service: esphome.panelname_notification_clear
data: {}
```


Die Notifications können einfach in eine Automation mit aufgenommen werden:

```
description: ""
mode: single
trigger:
  - platform: state
    entity_id:
      - binary_sensor.motion_detector
    to: "on"
    condition: []
    action:
  - service: esphome.panelname_notification_show
    data:
      label: Motion Detected
      text: Example for a Notification on the Panel Screen
```


------

## 8. Climate für Relays

Um das NSPanel zur Steuerung eines Heizkörpers oder einer Fussbodenheizung zu nutzen, muss im HA mindestens ein Generic Thermostat angelegt sein. Siehe hierzu: https://www.home-assistant.io/integrations/generic_thermostat/

Beispielkonfiguration Generic Thermostat:

```
climate:
  - platform: generic_thermostat
    name: Study
    heater: switch.study_heater ## Wenn das NSPanel Relays den Heizkreis Regler schaltet, kann dieser hier definiert werden
    target_sensor: sensor.study_temperature ## Hier kann der NSPanel Sensor verwendet werden
    min_temp: 15
    max_temp: 21
    ac_mode: false
    target_temp: 17
    cold_tolerance: 0.3
    hot_tolerance: 0
    min_cycle_duration:
      seconds: 5
    keep_alive:
      minutes: 3
    initial_hvac_mode: "off"
    away_temp: 16
    precision: 0.1
```

Danach muss die climate.entity noch entsprechend in der Panel Configuration hinterlegt werden:![climate](./(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte.assets/climate.PNG)

------

## 9. Interne Switches als Lampe darstellen in HA

In der Welt von Home Assistant ist das Relays im NSPanel ein Schalter. Und obwohl das im Allgemeinen richtig ist, werden diese Relays oft z. B. für eine Leuchte oder einen Ventilator verwendet. Wenn nun bspw. eine Lampe direkt mit dem Relays geschaltet wird, so ist es wünschenswert, dass auch im HA der Switch als Lampe angezeigt wird oder diese "Lampe" einer Lichter-Gruppe hinzugefügt werden soll.

Mit der Switch as X-Integration können diese Schalter in die Entitätstypen umwandeln, die dem jeweiligen Anwendungsfall am besten entsprechen: https://www.home-assistant.io/integrations/switch_as_x/ 

![Swichasx](./(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte.assets/Swichasx.png)



------

## 10. Schnell Navigation

In Arbeit

------

## 11. Bestimmte Seiten direkt aufrufen

Manchmal kann es Sinn machen, automatisch eine bestimmte Seite des Displays anzeigen zu lassen. Um dies zu tun, kann folgender Service genutzt werden:

```
service: esphome.nspanel_send_command_printf
data:
  cmd: page home
```

Um bspw. direkt die Button Page 2 anzuzeigen, muss "home" durch "buttonpage02" ersetzt werden.

Folgende Seiten sind derzeit verfügbar:

![img](./assets/Bildschirmfoto_2023-03-21_um_00.24.01.png)

------

## 12. RTTTL Sound abspielen

HA kann ein RTTTL an das NSPanel schicken, dabei sind eigene Melodien möglich. 

Hierzu wird folgender Service verwendet: ***nspanel_play_rtttl*** 

Man findet viele RTTTL-Strings im Web, wichtig ist, dass diese mit dem Namen und dann einem Doppelpunkt beginnen müssen. 

Hier ein Beispiel:

```
The Simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6
```

![image-20230320222454441](./assets/image-20230320222454441.png)

Mehr Informationen unter: https://esphome.io/components/rtttl.html#common-beeps

Mehr Songs hier: https://codebender.cc/sketch:109888#RTTTL%20Songs.ino

------

## 13. Erweiterte Funktionen und Automatisierungen

In Arbeit

------

## 14. Automationen starten via Input_Boolean

Obwohl mit dem NSPanel Scripts direkt über die Buttons gestartet werden können, gibt es auch die Möglichkeit, mittels Input_Boolean direkt Automationen zu starten.

Hierzu muss erst ein Helper angelegt werden unter ***Settings --> Devices&Services --> Helpers***, siehe hierzu: https://www.home-assistant.io/integrations/input_boolean/![Toggle1](./(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte.assets/Toggle1.PNG)

Anschliessend wird der erstellte Input_Boolean als Trigger in eine beliebige Automation aufgenommen unter State:![Toggle2](./(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte.assets/Toggle2.PNG)

Im letzten Schritt den Trigger noch einem Button in der Panel Config zuordnen:![Toggle3](./(DE)-HowTo---Alle-wichtigen-Dinge-die-man-wissen-sollte.assets/Toggle3.PNG)



------

