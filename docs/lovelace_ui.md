> _**in the version "nspanel-lovelace-ui" from joBr99 are a few special features built in, which make it not so easy to flash a new version and TFT on the NSPanel. But since we already had this problem, we have of course already a solution for you ;)**_

### _**It is necessary to upload a "Blank TFT" file while "Lovelace ui" is still installed on the NSPanel.**_

> IMPORTANT! If you have already installed the NSPanel with my version, you must first fully install "Lovelace ui" again.

### The following steps are necessary:

1. download the file _**"nspanel_blank.tft"**_ from the folder _**custom_configuration**_.
2. now upload the TFT file _**"nspanel_blank.tft"**_ to the folder _**"www"**_ in Home Assistant
3. now go to the item _**"Developer tools --> Services"**_ and search there for the services
&nbsp;  
_**"ESPHome: DEVICE_NAME_upload_tft"**_  --> (esphome.device_name_upload_tft)
4. under URL you have to enter the path to your file _**nspanel_blank.tft**_. This could look like this
_**"http://homeassistan.local:8123/local/nspanel_blank.tft"**_
5. now the TFT file should be played on the NSPanel. It may take a moment until it is ready
6. If everything worked, you should see only a QR code on the NSPanel.
7. now you can continue with the setup and configuration of my version. For this see [Short version of the setup of Esphome and Blueprint](intall.md#1-short-version-of-the-setup-of-esphome-and-blueprint) 