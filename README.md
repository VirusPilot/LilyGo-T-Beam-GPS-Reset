## LilyGo-T-Beam-GPS-Reset
Arduino script to configure the u-blox GPS on the LilyGo T-Beam

### Requirements:
- install Arduino IDE (v1.8.xx)
- add "https://dl.espressif.com/dl/package_esp32_index.json" into the Additional Board Manager URLs
- open the Arduino Boards Manager and search for ESP32 and press install button for the ESP32 by Espressif Systems
- install (deprecated) SparkFun_Ublox_Arduino_Library: https://github.com/sparkfun/SparkFun_Ublox_Arduino_Library

### Steps:
- copy Github SoftRF folder to <My Documents>/Arduino/SoftRF
- copy Github libraries folder to <My Documents>/Arduino/libraries

### Compiling:
- open u-blox-reset sketch from File -> Open menu
- Select Tools -> Board -> ESP32 Dev Module
- Select Tools -> Flash Mode -> DIO
- Select Tools -> Flash Size -> 4MB
- Select Tools -> Partition Scheme -> Minimal SPIFFS
- Select Tools -> Flash Frequency -> 80MHz
- Select Tools -> CPU Frequency -> 80MHz
- Select Tools -> PSRAM -> Enabled
- compile or compile and upload
