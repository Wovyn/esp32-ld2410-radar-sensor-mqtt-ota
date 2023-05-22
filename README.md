# esp32-ld2410-radar-sensor-mqtt-ota
An Arduino sketch for an ESP32 using the LD2410 as a Radar Sensor with MQTT reporting and OTA

ESP32 LD2410 Radar Sensor

Designed to monitor the LD2410 for motion indications and publish via MQTT to a broker

Publishing to MQTT is triggered by two different conditions:
 1. once every HEARTBEAT_INTERVAL that you can define in the settings.  This is a heartbeat.
 2. once every RADAR_REPORT_INTERVAL as long as motion is detected. Also defined in settings.

OTA checks are done on cold boot and every OTA_CHECK_EVERY defined in settings.

 Last updated 2023-05-21
 Written by Scott C. Lemon
 Based on code from:
         https://github.com/ncmreynolds/ld2410

Version 1.0.0
 - Using a SmartBee Bee S3 - ESP32 S3
     https://www.tindie.com/products/smartbee/bee-s3-esp32-s3/
 - started with the code above
 - integrated MQTT publish code
 - integrated OTA update code
 - implemented setup and main loop

TODO:
   Add the WiFi Manager library to allow dynamic configuration
---------------------------------------------------
Make sure to pay attention to the pins being used!

Using a UART is highly recommended due to the high data rate.  Wire your module according to the
following code, or modify the code to match your module.

```
#if defined(ESP32)
  #ifdef ESP_IDF_VERSION_MAJOR // IDF 4+
    #if CONFIG_IDF_TARGET_ESP32 // ESP32/PICO-D4
      #define MONITOR_SERIAL Serial
      #define RADAR_SERIAL Serial1
      #define RADAR_RX_PIN 32
      #define RADAR_TX_PIN 33
    #elif CONFIG_IDF_TARGET_ESP32S2
      #define MONITOR_SERIAL Serial
      #define RADAR_SERIAL Serial1
      #define RADAR_RX_PIN 9
      #define RADAR_TX_PIN 8
    #elif CONFIG_IDF_TARGET_ESP32S3
      #define MONITOR_SERIAL Serial
      #define RADAR_SERIAL Serial1
      #define RADAR_RX_PIN 44
      #define RADAR_TX_PIN 43
    #elif CONFIG_IDF_TARGET_ESP32C3
      #define MONITOR_SERIAL Serial
      #define RADAR_SERIAL Serial1
      #define RADAR_RX_PIN 4
      #define RADAR_TX_PIN 5
    #else 
      #error Target CONFIG_IDF_TARGET is not supported
    #endif
  #else // ESP32 Before IDF 4.0
    #define MONITOR_SERIAL Serial
    #define RADAR_SERIAL Serial1
    #define RADAR_RX_PIN 32
    #define RADAR_TX_PIN 33
  #endif
#elif defined(__AVR_ATmega32U4__)
  #define MONITOR_SERIAL Serial
  #define RADAR_SERIAL Serial1
  #define RADAR_RX_PIN 0
  #define RADAR_TX_PIN 1
#endif
```
