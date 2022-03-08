# FLY-Screen-RepRap
Firmware for the Fly Screens to be used with RepRapFirmware

## Config.g Setup

Edit the config file to include the following line
```
M575 P1 S0 B57600
```
## Upgrading the firmware

- Download the update
- Rename it to update.img
- Place the relevant update into the root of a FAT32 formatted SD card.
- Power on the screen.
- Apply the update.
- Once complete, power down the screen and remove the SD Card

## Adding a boot display

### 4.3" Screen
- Create a 480x232 resolution picture, the picture size should not exceed 128kb
- Rename the picture name to boot_logo.JPG, JPG is uppercase. 
- Put the picture into the root directory of the sd card.
- Plug it into the screen to upgrade.
### 7" Screen
- Create 800x480 resolution picture, the picture size should not exceed 128kb
- Rename the picture name to boot_logo.JPG, JPG is uppercase. 
- Put the picture into the root directory of the sd card.
- Plug it into the screen to upgrade.

## Future Features
- Support printing from the screen sd card and USB disk
- firmware settings are temporarily unavailable, and will be supported in the near future 
- Modify the config.g file on the screen. 
- Configure the machine firmware on the screen without opening the web page configuration

## Compiling/Editing instructions
Please see [here](https://teamgloomy.github.io/fly_firmware_compile.html) for more detailed information regarding compiling and editing the firmware now it is open source.

## Support
If you have any usage problems, please join https://discord.gg/hccjyvv Come to consult me
