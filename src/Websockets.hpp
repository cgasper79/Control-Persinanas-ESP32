AsyncWebSocket ws("/ws");

//Recepción de mensajes del socket
void ProcessRequest(AsyncWebSocketClient *client, String request)
{
  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, request);
  if (error) { return; }
  
  String command = doc["command"];
  if(command == "buttonAction")
    doAction(doc["id"]);
  else if(command == "switchConfig") 
    setConfiguration(doc["id"], (bool)doc["status"]);
}

//Actualización de configuracion ON/OFF al websockets 
void updateConfiguration(int input, bool value)
{
  String response;
  StaticJsonDocument<300> doc;
  doc["command"] = "updateConfig";
  doc["id"] = input;
  doc["status"] = value;
  serializeJson(doc, response);
  ws.textAll(response);
  //Serial.print(input);
  //Serial.println(value ? String(" ON") : String(" OFF"));
  delay(10);
}

//Actualicación Información al Websockets STRING
void updateInformationString(int input2, String value2)
{
  String response2;
  StaticJsonDocument<300> doc2;
  doc2["command"] = "updateString";
  doc2["id"] = input2;
  doc2["status"] = value2;
  serializeJson(doc2, response2);
  ws.textAll(response2);
  //Serial.print(input2);
  //Serial.println(value2);
  delay(10);
}

//Actualicación Información al Websockets IPADDRESS
void updateInformationIpaddress(int input3, IPAddress value3)
{
  String response3;
  StaticJsonDocument<300> doc3;
  doc3["command"] = "updateIPAddress";
  doc3["id"] = input3;
  doc3["status"] = value3;
  serializeJson(doc3, response3);
  ws.textAll(response3);
  //Serial.print(input3);
  //Serial.println(value3);
  delay(10);
}


//Envio estado Configuración e Información a Websockets Dinamic
void sendWebsocketsDinamic(){

  updateConfiguration(9,modoNoche);
  updateConfiguration(10,modoDia);
  updateConfiguration(11,mitadPersiana);
  updateConfiguration(12,horarioVerano);
  updateInformationString(14,miRSSI);
  updateInformationString(17,horaActual);  
}

//Envio estado Información a Websocket Estatica
void sendWebsocketsStatic(){

  updateInformationString(13,ssid);
  updateInformationString(15,horaModoNoche);
  updateInformationString(16,horaModoDia);
  updateInformationIpaddress (19,miIP);
  updateInformationIpaddress (20, puertaEnlace);
  updateInformationIpaddress (21, miDNS);
}

//Limitar número de clientes websockets y cerrar los que no se utilizan
void cleanClientsSockets(){
  ws.cleanupClients();
}