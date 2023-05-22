/**********************************************
 * These are all of the configuration items
 * 
 * Make sure these are set to your values!
 **********************************************/

// WiFi Settings
const char *ssid = "{your ssid}";
const char *password = "{your password}";

// How often to check for OTA updates?
#define OTA_CHECK_EVERY 24 * 60 * 60 * 1000

// For the OTA, set the firmware type and version for this code
const char* firmwareType = "esp32-s3-LD2410-MQTT-OTA";

/*
 * #define STRINGIFY(x) STRINGIFY_HELPER(x)
 * #define STRINGIFY_HELPER(x) #x 
 * #define MAJOR 1
 * #define MINOR 2
 * #define PATCH 3
 * #define STRING (STRINGIFY(MAJOR) "." STRINGIFY(MINOR) "." STRINGIFY(PATCH))
 */
#define FIRMWARE_MAJOR_VERSION  1
#define FIRMWARE_MINOR_VERSION  0
#define FIRMWARE_PATCH_VERSION  0
#define FIRMWARE_VERSION_STRING "1.0.0"

// do we want to post to our defined endpoints?
#define POST_TO_ENDPOINT  true

// Your MQTT(S) broker details
#define ENABLE_MQTT         true
#define USE_MQTTS           true   // Testing with WiFiClientSecure
const char broker[] =       "yourhost.domain.tld";
const int  mqttPort =       8883;
const char mqttUserName[] = "";  // your mqtt username
const char mqttPassword[] = "";  // your mqtt password
String clientId =           "esp32-ld2410-mqtt-ota-";

//  To blink the LED we need to know the LED Pin
#define LED_PIN  10

// This is how often the waiting messages are debug output
#define   WAITING_MESSAGE_EVERY_SECONDS   15

//  How often should we update the MQTT broker
//    - defaulting to every 15 minutes with no events
//    - motion events will be sent immediately
#define HEARTBEAT_INTERVAL   900

// radar report interval
#define RADAR_REPORT_INTERVAL   1000
