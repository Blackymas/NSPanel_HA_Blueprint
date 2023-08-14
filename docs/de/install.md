In diesem Beitrag geht es um die erst Konfiguration. Hier werden alle wichtigen Schritte zur Installation und Einrichtung von ESPHome und dem Blueprint beschrieben.&nbsp;

⭐ **_Step by Step [Einrichtungs Video](https://www.youtube.com/watch?v=3afPFg6kUdc)_**

&nbsp;
> ### _**ACHTUNG! solltest du vorher bereits auf deinem NSPanel die Version "nspanel-lovelace-ui" von joBr99 eingerichtet haben, ist ein zwischen Schritt nötig - sonst ist es nicht möglich diese oder irgendeine andere Version zu installieren**_ 

&nbsp;  
&nbsp;  

***

&nbsp;   
# Inhalt:

1. [Kurz Version der Einrichtung von Esphome und Blueprint](#1-kurz-version-der-einrichtung-von-esphome-und-blueprint) 

2. [Version "nspanel-lovelace-ui" von joBr99 wurde vorher installiert](#2-version-nspanel-lovelace-ui-von-jobr99-wurde-vorher-installiert)

3. [Advance Modus für ESPHome und HA Profis](#3-advanced-configuration-für-alle-esphome-und-home-assistant-profis)

4. [Step by Step Einrichtung und Konfiguration](#4-step-by-step-konfiguration-und-einrichtung-von-esphome-und-blueprint) 

&nbsp;  

***

&nbsp;  
&nbsp;  

## 1. Kurz Version der Einrichtung von Esphome und Blueprint
> _**(für alle die bereits mit ESPhome und Home Assistant Erfahrung haben)**_

#### 1. Als erstes muss das Blueprint installiert werden. Dazu nutze bitte folgenden Link

[![Open your Home Assistant instance and show the blueprint import dialog with a specific blueprint pre-filled.](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https%3A%2F%2Fgithub.com%2FBlackymas%2FNSPanel_HA_Blueprint%2Fblob%2Fmain%2Fnspanel_blueprint.yaml)

> Es ist auch möglich den Code aus der Datei _**"nspnael_blueprint.yaml"**_ zu kopieren und in HA einzufügen.
> Hinweise dazu findest du unter [Using Automation Blueprints](https://www.home-assistant.io/docs/automation/using_blueprints/) und [Automation blueprint tutorial](https://www.home-assistant.io/docs/blueprint/tutorial/#create-the-blueprint-file)

#### 2. Nun muss von Github das File **_"nspanel_eu.tft"_** oder **_"nspanel_us.tft"_**heruntergeladen werden 

![Bildschirmfoto 2023-01-23 um 21 31 05](https://user-images.githubusercontent.com/41958506/214161397-ec927f77-be77-433d-84a5-79fbfed33932.png)


#### 3. Das File muss nun auf deinen Home Assistant Server in den Ordner **_"www"_** hochgeladen werden. Siehe dazu auch hier [Home Assistant HTTP](https://www.home-assistant.io/integrations/http/#hosting-files) 'Hosting Files' Bereich für weiter Informationen.

![Bildschirmfoto 2023-01-23 um 21 33 20](https://user-images.githubusercontent.com/41958506/214162088-3bd67e46-c389-496f-a937-757ad63e1fe2.png)

#### 4. im nächsten Schritt muss eine neues ESP32 Device in ESPHome erstellt werden

#### 5. wenn das neue ESP32 Device erstellt wurde, klicke als nächstes bei dem soeben angelegten Device auf _**"Edit"**_ um den Web-Editor zu öffnen. Nun muss folgender Code kopiert und eingesetzt werden.

> ❗ _**WICHTIG!**_ Der bereits vorhanden Code in der ESPHome Datei muss _**"KOMPLETT"**_ gelöscht werden und durch den unten stehenden Code _**"ERSETZT"**_ werden.

> ❗ _**WICHTIG!**_ im Block _**"CHANGE ME"**_ müssen alle Werte _**(device_name, wifi_ssid, wifi_password)**_ in den _**" "**_ durch deine eigenen Werte ersetzt werden. Es ist hier auch möglich mit _**"!secret"**_ zu arbeiten


> ⚠️ _**ACHTUNG!**_ es dürfen bei _**"device_name"**_ max. 15 Zeichen _**[a-z] und [0-9]**_ verwendet werden und alles müssen _**"Kleinbuchstaben"**_ sein. Weiterhin sind Zeichen wie _**[-],  [SONDERZEICHEN] und [LEERZEICHEN]**_ verboten und führen zu Problemen mit dem Blueprint.

> **Beispiel:** _**nspanel_blackymas**_

&nbsp;
### CODE:
```
substitutions:
  ###### CHANGE ME - START ######
  device_name: "YOUR_NSPANEL_NAME" 
  wifi_ssid: !secret wifi_ssid
  wifi_password: !secret wifi_password

  nextion_update_url: "http://homeassistant.local:8123/local/nspanel_eu.tft"
  
  ##### addon-configuration #####
  ## addon_climate ##
  # addon_climate_heater_relay: "1" # possible values: 1/2
  
  ## addon_xx
  # addon_xx_yy: "true" # possible values true/false
  ##### CHANGE ME - END #####


##### DO NOT CHANGE ANYTHING! #####
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml
      #- nspanel_esphome_addon_climate.yaml # activate local climate-control
    refresh: 300s
##### DO NOT CHANGE ANYTHING! #####
```


> Im Pfad **_http://HOME-ASSISTANT-IP:8123/local/nspanel_eu.tft_** muss nun die IP Adresse von deinem _**Home Assistant Server**_ eingetragen werden. (_**/local/**_ ist das selbe Verzeichnis wie **_"www"_**
>
> 

> Das kann dann wie folgt aussehen **_http://192.168.1.1:8123/local/nspanel_eu.tft_**

> ⚠️ **_ACHTUNG_** Du kannst auch den Pfad zu Github verwenden **_https://raw.githubusercontent.com/Blackymas/NSPanel_HA_Blueprint/main/nspanel_eu.tft_** und das TFT direkt von Github herunter laden. Aber dabei kann es zu Problemen mit dem Upload zum NSPanel kommen. Das hängt von deinem Internet und WLAN ab. Für mehr Informationen zu diesem Thema schauen auf der **_Issue_** Seite im Github. Das ganze sollte dann so aussehen

```
#  nextion_update_url: "http://HOME-ASSISTANT-IP:8123/local/nspanel_eu.tft" # URL to local tft File
  nextion_update_url: "https://raw.githubusercontent.com/Blackymas/NSPanel_HA_Blueprint/main/nspanel_eu.tft" # URL to Github
```

> ⚠️ **_ACHTUNG_** soll das US Layout des Panels verwendet werden, dann muss anstelle von "nspanel_eu.tft" in der nextion_update_url "nspanel_us.tft" verwendet werden!&nbsp;

#### 6. Jetzt kann das NSPanel mit dem neuen ESPHome Code geflasht werden 
> wie das NSPanel geflasht wird kannst du dir hier ansehen [Anleitung - Flash Sonoff NSPanel mit ESPHome](https://www.youtube.com/watch?v=3afPFg6kUdc)

#### 7. Nachdem das NSPanel fertig geflasht wurde, kannst du unter _**"Einstellungen --> Geräte & Dienste --> Integration hinzufügen"**_ dein neues Gerät hinzufügen und fertig einrichten

#### 8. im letzten Schritt muss nun nur noch das TFT hochgeladen werden. Dazu öffne in der Integration ESPHome dein neues Device und aktiviere unter _**"Konfiguration"**_ den Punkt _**"Update TFT display"**_. Jetzt wird von deinem lokalen Home Assistant Server oder Github das aktuelle TFT File geladen und auf dein NSPanel hochgeladen. _**ACHTUNG!**_ dieser Vorgang kann einen Moment dauern

#### 9. jetzt ist die Einrichtung vom ESPHome und dem NSPanel abgeschlossen.

#### 10. Nun kannst du über das Blueprint dein NSPanel konfigurieren. Dazu gehe auf _**"Einstellungen --> Automatisierungen & Szenen --> Vorlagen --> NSPanel Configuration --> AUTOMATISIERUNG ERSTELLEN"**_ und starte mit der Einrichtung vom NSPanel.

> **HINWEIS!** Trage im Blueprint im Feld _**"ESPHOME Node Name"**_ exakt den selben Namen ein, den du in der _**"ESPHome Datei"**_ vergeben hast.

> **Beispiel:** _**nspanel_blackymas**_



&nbsp;  
&nbsp;  

***

&nbsp;  
&nbsp;  
##  2. Version "nspanel-lovelace-ui" von joBr99 wurde vorher installiert
> _**in der Version "nspanel-lovelace-ui" von joBr99 sind ein paar Besonderheiten eingebaut, die es nicht so einfach ermöglichen eine neue Version und TFT auf das NSPanel zu flashen. Da wir dieses Problem aber schon hatten, haben wir natürlich auch schon eine Lösung für euch ;)**_

### _**Es ist notwendig eine "Leeres TFT" Datei hochzuladen, solange "Lovelace ui" noch auf dem NSPanel installiert ist.**_

> WICHTIG! Wenn du bereits das NSPanel mit meiner Version installiert hast, musst du zuerst wieder "Lovelace ui" vollständig installieren.

### Folgende Schritte sind notwendig:

1. lade dir aus dem Ordner _**custom_configuration**_ die Datei _**"nspanel_blank.tft"**_ herunter.
2. lade nun die TFT Datei _**"nspanel_blank.tft"**_ in den Ordner _**"www"**_ in Home Assistant hoch
3. gehe jetzt zu dem Punkt _**"Entwicklerwerzeuge --> Dienste"**_ und suche dort nach dem Dienst
&nbsp;  
_**"ESPHome: DEVICE_NAME_upload_tft"**_  --> (esphome.device_name_upload_tft)
4. unter URL musst du jetzt den Pfad zu deiner Datei _**nspanel_blank.tft**_ eingeben. Das könnte zum Beispiel so aussehen _**"http://IP_HOME_ASSISTANT:8123/local/nspanel_blank.tft"**_
5. nun sollte die TFT Datei auf das NSPanel gespielt werden. Es kann einen Moment dauern, bis es fertig ist
6. sollte alles funktioniert haben, sollte auf dem NSPanel nur eine weiße Seite zu sehen sein
7. jetzt kann mit der Einrichtung und Konfiguration meiner Version fortgesetzt werden. Dazu siehe [Kurz Version der Einrichtung von Esphome und Blueprint](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-Erste-Schritte---Installation-und-Einrichtung#1-kurz-version-der-einrichtung-von-esphome-und-blueprint) 





&nbsp;  
&nbsp;  

***

&nbsp;  
&nbsp;  
##  3. Advanced configuration für alle ESPHome und Home Assistant Profis

* Blueprint Datei _**"nspnael_blueprint.yaml"**_ kann auch manuell installiert werden
* ESPHome Datei_**"nspanel_esphome.yaml"**_ kann auch manuell installiert werden. Dadurch können weitere _**"Advanced"**_ Konfigurationen aktiviert oder hinzugefügt werden.
* Außerdem besteht die Möglichkeit das TFT File _**"nspanel_eu.tft"**_ manuell hochzuladen. Das Ganze kann auch mit einem _**"Folder Watcher"**_ kombiniert werden
* zusätzlich stellen wir die HMI Datei _**"nspanel_eu.HMI"**_ für den Nextion Editor zur Verfügung, um Grafiken und Programmierung bei bedarf anpassen zu können

> _**ACHTUNG!**_ Wer diesen Modus benutzt, sollte wissen was er tut. Wir geben hier keinen Support!






&nbsp;  
&nbsp;  

***

&nbsp;  
&nbsp;  
##  4. Step by Step Konfiguration und Einrichtung von ESPHome und Blueprint
> _**(für alle die neu im Thema ESPhome sind oder noch keine Erfahrungen gesammelt haben)**_