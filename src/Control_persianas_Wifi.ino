#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <RCSwitch.h>
#include <TickTwo.h>

#include "config.h"
#include "Server.hpp"
#include "RF.hpp"
#include "API.hpp"
#include "Websockets.hpp"
#include "ESP32_Utils.hpp"
#include "ESP32_Utils_AWS.hpp"
#include "Timer.hpp"

//Funciones
void setStateMode();
void horaNTP();

//Instancias temporizador
TickTwo timer1(setStateMode,1000);
TickTwo timer2(horaNTP,1000);


void setup(void)
{
  Serial.begin(9600);
  SPIFFS.begin();

  pinMode(2, OUTPUT); // Pin interno placa que indica conexión wifi conectado

  ConnectWiFi_STA();

  //Iniciamos servicios básicos
  InitServer();
  InitWebSockets();
  InitRF();
  InitTime();

  //Inicio temporizados
  timer1.start();
  timer2.start();
  
}

void loop()
{
  temporizadoMediaPersiana();
  modoAuto();
  ReconnectionWifi();

  timer1.update();
  timer2.update();
  
}
