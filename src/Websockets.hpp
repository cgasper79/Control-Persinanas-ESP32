AsyncWebSocket ws("/ws");

//Recepción de mensajes del socket
void ProcessRequest(AsyncWebSocketClient *client, String request)
{
  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, request);
  if (error) { return; }
  
  String command = doc["command"];
  if(command == "doAction")
    doAction(doc["id"]);
  else if(command == "setGPIO") 
    setGPIO(doc["id"], (bool)doc["status"]);
}

//Actualización de configuracion ON/OFF al websockets 
void updateConfiguration(int input, bool value)
{
  String response;
  StaticJsonDocument<300> doc;
  doc["command"] = "updateGPIO";
  doc["id"] = input;
  doc["status"] = value;
  serializeJson(doc, response);
  ws.textAll(response);
  //Serial.print(input);
  //Serial.println(value ? String(" ON") : String(" OFF"));
  delay(10);
}

//Actualicación Información al Websockets
void updateInformation(int input2, String value2)
{
  String response2;
  StaticJsonDocument<300> doc2;
  doc2["command"] = "updateConection";
  doc2["id"] = input2;
  doc2["status"] = value2;
  serializeJson(doc2, response2);
  ws.textAll(response2);
  //Serial.print(input2);
  //Serial.println(value2);
  delay(10);
}


//Envio estado Configuración e Información a Websockets
void setStateMode(){
  updateConfiguration(9,modoNoche);
  updateConfiguration(10,modoDia);
  updateConfiguration(11,mitadPersiana);
  updateConfiguration(12,horarioVerano);
  updateInformation(13,ssid);
  updateInformation(14,miRSSI);
  updateInformation(15,horaModoNoche);
  updateInformation(16,horaModoDia);
  updateInformation(17,horaActual);  
}

//Limitar número de clientes websockets y cerrar los que no se utilizan
void cleanClientsSockets(){
  ws.cleanupClients();
}