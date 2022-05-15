#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <RCSwitch.h>
#include <TickTwo.h>
#include <AsyncElegantOTA.h>
#include <AsyncTCP.h>


#include "config.h"
#include "Server.hpp"
#include "RF.hpp"
#include "API.hpp"
#include "Websockets.hpp"
#include "ESP32_Utils.hpp"
#include "Timer.hpp"
#include "ESP32_Utils_AWS.hpp"


//Funciones
void sendWebsocketsDinamic();
void horaNTP();
void cleanClientsSockets();
void timeStartUp();

//Instancias temporizador
TickTwo timer1(sendWebsocketsDinamic,1000);
TickTwo timer2(horaNTP,1000);
TickTwo timer3(cleanClientsSockets,2000);
TickTwo timer4(timeStartUp,30000);

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
  timer3.start();
  timer4.start();
  
}

void loop()
{
  currentMillis = millis();

  temporizadoMediaPersiana();
  modoAuto();
  ReconnectionWifi();
  timer1.update();
  timer2.update();
  timer3.update();
  timer4.update();


  //reinicia cada 7 dias
  if (currentMillis == 604800000){
    ESP.restart();
  }
}
