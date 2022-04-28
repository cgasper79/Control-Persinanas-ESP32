AsyncWebSocket ws("/ws");

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

void updateWeb(int input, bool value)
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
}

void updateConection(int input2, String value2)
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
}


//Envio estado Configuración e Información a Websockets
void setStateMode(){
  updateWeb(9,modoNoche);
  updateWeb(10,modoDia);
  updateWeb(11,mitadPersiana);
  updateWeb(12,horarioVerano);
  updateConection(13,ssid);
  updateConection(14,miRSSI);
  updateConection(15,horaModoNoche);
  updateConection(16,horaModoDia);
  updateConection(17,horaActual);  
}
