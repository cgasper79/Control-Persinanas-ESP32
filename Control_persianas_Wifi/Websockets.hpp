AsyncWebSocket ws("/ws");

void ProcessRequest(AsyncWebSocketClient *client, String request)
{
  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, request);
  if (error) { return; }
  
  String command = doc["command"];
  if(command == "doAction")
    doAction(doc["id"]);
}
