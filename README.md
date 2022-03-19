## LilyGo-T-Beam-GPS-Reset
- Arduino sketch to configure the u-blox M6/M7/M8 GPS on a **LilyGo T-Beam v1.0 and v1.1** version
- this sketch is required to run https://github.com/VirusPilot/SoftRF connected to the latest **Stratux Europe Edition**

### Works only with T-BEAM v1.0 and v1.1 versions
- if you need to reset a T-Beam v0.7 version, please change the define in `utilities.h` accordingly

### Settings for https://github.com/VirusPilot/SoftRF
- GPS_BAUD_RATE 57600
- GPS_UPDATE_RATE 5

### Revert to default settings (defines in the sketch need to be changed accordingly)
- GPS_BAUD_RATE 9600
- GPS_UPDATE_RATE 1

### Requirements:
- install Arduino IDE (v1.8) and add `https://dl.espressif.com/dl/package_esp32_index.json` into the Additional Board Manager URLs
- open the Arduino Boards Manager, search and install `esp32 by Espressif Systems`
- open the Arduino Library Manager, search and install `SparkFun u-blox Arduino Library` (only use deprecated version v1.8, do not use v2.0)

### Prepare:
- download or clone `https://github.com/VirusPilot/LilyGo-T-Beam-GPS-Reset`
- copy `LilyGo-T-Beam-GPS-Reset` folder to `~/Documents/Arduino/LilyGo-T-Beam-GPS-Reset`

### Compile:
- open u-blox-reset sketch from File -> Open menu
- Select Tools -> Board -> ESP32 Dev Module
- Select Tools -> Upload Speed -> 921600
- Select Tools -> CPU Frequency -> 80MHz
- Select Tools -> Flash Frequency -> 80MHz
- Select Tools -> Flash Mode -> DIO
- Select Tools -> Flash Size -> 4MB
- Select Tools -> Partition Scheme -> Minimal SPIFFS
- Select Tools -> PSRAM -> Enabled
- Select Tools -> open serial monitor @ 115200 baud
- connect your T-Beam
- Select Tools -> Port -> (select accodingly)
- you should see some output on the serial monitor, e.g. NMEA sentences
- compile or compile and upload
- after the automatic reboot you should see GPS NMEA sentences

### Compile and run SoftRF Stratux version for T-Beam
- download or clone `https://github.com/VirusPilot/SoftRF`
- copy Github SoftRF folder to `~/Documents/Arduino/SoftRF`
- copy Github libraries folder to `~/Documents/Arduino/libraries`
- same steps as before
