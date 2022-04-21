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

void updateConection(int input, String value)
{
  String response;
  StaticJsonDocument<300> doc;
  doc["command"] = "updateConection";
  doc["id"] = input;
  doc["status"] = value;
  serializeJson(doc, response);
  ws.textAll(response);
}

//Envio estado Configuración a Web
void setStateMode(){
  
  if (modoNoche){
    updateWeb(9,1);
  }else{
    updateWeb(9,0);
  }

  if (modoDia){
    updateWeb(10,1);
  }else{
    updateWeb(10,0);
  }

  if (mitadPersiana){
    updateWeb(11,1);
  }else{
    updateWeb(11,0);
  }

  if (horarioVerano){
    updateWeb(12,1);
  }else{
    updateWeb(12,0);
  }
  
}
