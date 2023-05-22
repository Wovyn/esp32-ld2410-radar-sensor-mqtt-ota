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
