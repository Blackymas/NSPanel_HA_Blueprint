> ### _**ACHTUNG! Wenn bereits die Version "nspanel-lovelace-ui" von joBr99 auf dem NSPanel installiert ist, ist ein Zwischenschritt notwendig - ansonsten ist es nicht möglich, diese oder eine andere Version zu installieren.**_ 
>Siehe hierzu [Installation und Einrichtung](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-Erste-Schritte---Installation-und-Einrichtung#2-version-nspanel-lovelace-ui-von-jobr99-wurde-vorher-installiert)
<br>

> ### _**Die frühere Methode, bei der NSPanel das TFT direkt von GitHub heruntergeladen hat, wurde eingestellt, da eine große Anzahl von Benutzern langsame oder fehlgeschlagene Downloads verzeichnete. Daher muss der Upload nun mit einer lokal gehosteten tft-Datei vorgenommen werden**_ 

Es gibt eine Reihe von Problemen, die das Hochladen des TFT-Uploads beeinträchtigen können. Diese Probleme betreffen nicht das NSPanel HA Blueprint-Projekt, sondern scheinen bei Nextion-Displays und ESPhome aufzutreten. Nicht alle der unten genannten Ursachen betreffen alle Benutzer, jedoch haben die folgenden Massnahmen unter jedem Punkt zu einer Lösung geführt.

<br>In order of likelihood:

#### 1. Eine lokale Datenquelle verwenden (Home Assistant) 
Dies ist die häufigste Ursache für Probleme und der Grund, warum unsere Anleitung nicht mehr auf das Herunterladen des TFT von GitHub verweisen. Durch Ändern der nextion_update_url zum Hosten der TFT-Datei auf dem lokalen HA werden die meisten Probleme gelöst.

Siehe hierzu Punkt 2-4 in den [Installation und Einrichtung](https://github.com/Blackymas/NSPanel_HA_Blueprint/wiki/(DE)-Erste-Schritte---Installation-und-Einrichtung#2-version-nspanel-lovelace-ui-von-jobr99-wurde-vorher-installiert) 
<br><br>

#### 2. HTTP anstelle von HTTPS
Während HTTPS für einige Benutzer funktionieren kann, mussten wir feststellen, dass es eine Reihe von Problemen verursachen kann. Eine Möglichkeit ist, das  TFT-Dateihosting und nextion_update_url auf HTTPS umzustellen.
<br><br>

#### 3. Netzwerkprobleme
Eine instabile Netzwerkverbindung kann zu Verbindungsabbrüchen führen. Das NSPanel näher an den WiFi Zugangspunkt zu bringen, oder den Router neu zu starten sind zwei Möglichkeiten, dieses Problem zu lösen.
Wenn die Fehlermeldung _Connection Refused_ oder _Connection Reset_ erscheint, ist dies das häufigste Problem.
<br><br>

#### 4. DNS
Ähnlich wie Punkt 2, sollte eine IP Adresse statt die DNS Auflösung verwendet werden: 

also http://192.168.0.100:8123/local/nspanel.tft anstelle von http://homeassistant.local:8123/local/nspanel.tft
