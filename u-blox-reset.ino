
#include "SparkFun_Ublox_Arduino_Library.h"
#include "utilities.h"

SFE_UBLOX_GPS myGPS;

#define GPS_BAUD_RATE 57600
#define GPS_UPDATE_RATE 5

void setup() {
  initBoard(); delay(1500);

  autobaud();

  //now we should have a successful serial connection

  myGPS.factoryReset(); Serial.println("performing GPS factory reset"); delay(3000);

  autobaud();

  //now we should have a successful serial connection @ 9600 baud

  //GPS configuration
  myGPS.setNavigationFrequency(GPS_UPDATE_RATE); Serial.print(GPS_UPDATE_RATE, DEC); Serial.println("Hz update rate is set");
  myGPS.setSerialRate(GPS_BAUD_RATE); Serial.print(GPS_BAUD_RATE, DEC); Serial.println(" baud is set");
  delay(1000);
  Serial1.begin(GPS_BAUD_RATE, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
  myGPS.saveConfiguration();
  delay(1000);

  //This will pipe all NMEA sentences to the serial port so we can see them
  myGPS.setNMEAOutputPort(Serial);
}

void loop() {
  myGPS.checkUblox(); //See if new data is available. Process bytes as they come in.
}

void autobaud() {
  Serial1.begin(115200, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
  if (myGPS.begin(Serial1) == false) {
    Serial1.begin(57600, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
    if (myGPS.begin(Serial1) == false) {
      Serial1.begin(38400, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
      if (myGPS.begin(Serial1) == false) {
        Serial1.begin(9600, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
        if (myGPS.begin(Serial1) == false) {
          Serial.println("autobaud not successful"); delay(10000);
        } else {
          Serial.println("9600 baud was used");
          delay(1000);
        }
      } else {
        Serial.println("38400 baud was used");
        delay(1000);
      }
    } else {
      Serial.println("57600 baud was used");
      delay(1000);
    }
  } else {
    Serial.println("115200 baud was used");
    delay(1000);
  }
}
