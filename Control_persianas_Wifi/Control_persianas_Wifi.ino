#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <RCSwitch.h>

 
#include "config.h"
#include "Server.hpp"

#include "RF.hpp"
#include "API.hpp"
#include "Websockets.hpp"
#include "ESP32_Utils.hpp"
#include "ESP32_Utils_AWS.hpp"




void setup(void) 
{
   Serial.begin(115200);
   SPIFFS.begin();
   
   ConnectWiFi_STA();
   
   InitServer();
   InitWebSockets();
   InitRF();
}


void loop()
{
  
}
