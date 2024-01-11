# Weather support

## Expected configuration

### In Home Assistant Automation 
The integration should be Accuweather and you weather entity selected
![Screenshot 2023-01-30 214603](https://user-images.githubusercontent.com/123868814/215602716-60d92287-943f-465b-aac7-8b47795ef608.png)

### Enable Accuweather forcasts
![Screenshot 2023-01-30 214638](https://user-images.githubusercontent.com/123868814/215602723-7732578b-3870-4c1a-baec-5ebee98b37ad.png)

### Confirm source in Developer Tools States
In developer tools the weather entity should have the attribute 'attribution: Data provided by AccuWeather'
![Screenshot 2023-01-30 214739](https://user-images.githubusercontent.com/123868814/215602730-87093a5d-1a67-460d-9a9c-27a93371ea82.png)

## If you are still having issues
Its likely you weather integrations are clashing.
A method we have found to resolve this is to delete ALL weather integrations and just re-add Accuweather.
Be aware you will lose your existing weather integrations and any associated data / entities.

1. Delete the Standard and AccuWeather integrations
2. Add Accuweather & Enable forcasts
3. Set the Weather entity in the Automation
