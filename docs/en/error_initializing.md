A number of different things needs to be setup, if they are either not setup or setup incorrectly the NSPanel will stay on Initializing.<br>
![boot](https://user-images.githubusercontent.com/123868814/215597698-b89eb275-6c67-480a-a9d5-623ab17bee1b.png)
<br><br>

#### 1. Flashed ESPHome
Make sure you have installed the ESPHome config onto the NSPanel<br>
<br>

#### 2. ESPHome Name
The device_name in ESPHome must only use lowercase letters, numbers or underscore (\_). If you use hyphens (-) then it will 100% not work.<br>
![Screenshot 2023-01-30 212555](https://user-images.githubusercontent.com/123868814/215598710-af41f2f6-7184-4469-9e45-a91504803722.png)<br>
<br>

#### 3. NSPanel added to Home Assistant
You must add the ESPHome integration in Home Assistant for each NSPanel
![HAESPHomeIntegration](https://user-images.githubusercontent.com/123868814/215600125-a9e8cb72-17b3-4517-8132-bb3c5da5a50a.png)<br>
<br>

#### 4. Blueprint installed and Automation deployed
Make sure the blueprint is installed.<br>
 [![Open your Home Assistant instance and show the blueprint import dialog with a specific blueprint pre-filled.](https://my.home-assistant.io/badges/blueprint_import.svg)](https://my.home-assistant.io/redirect/blueprint_import/?blueprint_url=https%3A%2F%2Fgithub.com%2FBlackymas%2FNSPanel_HA_Blueprint%2Fblob%2Fmain%2Fnspanel_blueprint.yaml)<br>
![Screenshot 2023-01-30 213511](https://user-images.githubusercontent.com/123868814/215600277-4c66bc36-91d5-40c9-9d81-21bd8be4b114.png)

Make sure you have created an automation for the NSPanel and that the **ESP Node Name** matches the name from ESPHome exactly
![Screenshot 2023-01-30 214156](https://user-images.githubusercontent.com/123868814/215601843-bb5c31f7-6827-4c95-ac01-6b94e6dfdff4.png)

<br><br><br>

Once these steps are complete the display should connect after a short delay
