#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
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
#include "Timer.hpp"

void setup(void)
{
  Serial.begin(9600);
  SPIFFS.begin();

  pinMode(2, OUTPUT); // Pin interno placa que indica conexión wifi conectado

  ConnectWiFi_STA();

  InitServer();
  InitWebSockets();
  InitRF();
  InitTime();
}

void loop()
{
  delay(500);
  temporizadoMediaPersiana();
  modoAuto();
  setStateMode();
}
