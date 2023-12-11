## Konfiguration

#### Im Home Assistant NSPanel Blueprint
Im Blueprint muss als Integration "Accuweather" ausgewählt werden und die Weather Entitiy von AccuWeather (bspw. Home) ausgewählt werden:<br> 
![Screenshot 2023-01-30 214603](https://user-images.githubusercontent.com/123868814/215602716-60d92287-943f-465b-aac7-8b47795ef608.png)<br>
<br>

#### AccuWeather Vorhersage aktivieren

Unter Settings - Devices&Services - Accuweather - Configure muss der Haken bei "Weather forecast" gesetzt sein:

![Screenshot 2023-01-30 214638](https://user-images.githubusercontent.com/123868814/215602723-7732578b-3870-4c1a-baec-5ebee98b37ad.png)<br>
<br>

#### Überprüfen in Developer Tools

#### In developer tools the weather entity should have the attribute 'attribution: Data provided by AccuWeather'<br>

Unter Developer Tools - States kann die AccuWeather integration überprüft werden. Die Weather Entity (hier im Beispiel weather.home) muss das Attribute "attribution: Data provided by Accuweather" haben:

#### ![Screenshot 2023-01-30 214739](https://user-images.githubusercontent.com/123868814/215602730-87093a5d-1a67-460d-9a9c-27a93371ea82.png)<br>
<br>

<br>

## Wenn das Problem immer noch besteht
Es kann in Einzelfällen vorkommen, dass mehrere Wetter Integrationen nicht zusammen funktionieren. Um dies zu beheben, empfehlen wir ALLE Wetter Integrations zu löschen und AccuWeather neu hinzuzufügen. Achtung: Dabei werden alle assoziierten Daten sowie Entities gelöscht!!

Das Vorgehen ist wie folgt:

#### 1. Löschen der Standard und AccuWeather Integration

#### 2. Hinzufügen der AccuWeather Integration & Aktivieren der Vorhersage

#### 3. In der Blueprint Automation des NSPanels AccuWeather hinzufügen und die Entität auswählen

