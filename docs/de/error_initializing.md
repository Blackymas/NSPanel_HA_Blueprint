Es müssen verschiedene Dinge eingerichtet werden. Wenn diese nicht oder falsch eingerichtet sind, bleibt das NSPanel bei der Initialisierung stehen:<br>
![boot](https://user-images.githubusercontent.com/123868814/215597698-b89eb275-6c67-480a-a9d5-623ab17bee1b.png)
<br><br>

#### 1. Wurde ESPHome korrekt geflashed
Stellen Sie sicher, dass Sie die ESPHome-Konfiguration auf dem NSPanel installiert haben<br>
<br>

#### 2. ESPHome Name
Der Gerätename in ESPHome darf nur Kleinbuchstaben, Zahlen oder einen Unterstrich (\_) enthalten. Wenn Bindestriche (-) verwendet werden, kommt es zu Problemen.<br>
![Screenshot 2023-01-30 212555](https://user-images.githubusercontent.com/123868814/215598710-af41f2f6-7184-4469-9e45-a91504803722.png)<br>
<br>

#### 3. NSPanel zu HA hinzugefügt
Die ESPHome-Integration muss für jedes NSPanel  im HA hinzugefügt werden:
![HAESPHomeIntegration](https://user-images.githubusercontent.com/123868814/215600125-a9e8cb72-17b3-4517-8132-bb3c5da5a50a.png)<br>
<br>

#### 4. Blueprint installiert und Automation aktiviert
Sicherstellen, dass der Blueprint installiert ist:<br>
 [![Open your Home Assistant instance and show the blueprint import dialog with a specific blueprint pre-filled.](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https%3A%2F%2Fgithub.com%2FBlackymas%2FNSPanel_HA_Blueprint%2Fblob%2Fmain%2Fnspanel_blueprint.yaml)<br>
![Screenshot 2023-01-30 213511](https://user-images.githubusercontent.com/123868814/215600277-4c66bc36-91d5-40c9-9d81-21bd8be4b114.png)

Sicherstellen, dass eine Automatisierung für das NSPanel erstellt wurde und dass der **ESP Node Name** exakt dem Namen im ESPHome entspricht
![Screenshot 2023-01-30 214156](https://user-images.githubusercontent.com/123868814/215601843-bb5c31f7-6827-4c95-ac01-6b94e6dfdff4.png)

<br><br><br>

Sobald diese Schritte vorgenommen wurden, sollte sich das Display nach einem kurzen Delay verbinden.
