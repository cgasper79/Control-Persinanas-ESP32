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

//Envio estado Modos a Web
void setStateMode(){
  
  if (modoNoche){
    updateWeb(9,1);
  }else{
    updateWeb(9,0);
  }

  if (mitadPersiana){
    updateWeb(10,1);
  }else{
    updateWeb(10,0);
  }
  
}
