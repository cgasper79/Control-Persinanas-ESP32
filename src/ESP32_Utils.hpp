
// Funcionamiento como cliente wifi
void ConnectWiFi_STA(bool useStaticIP = true)
{
   Serial.println("");
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid, password);
   if(useStaticIP) WiFi.config(ip, gateway, subnet, primaryDNS, secondaryDNS);
   while (WiFi.status() != WL_CONNECTED) 
   { 
     delay(100);  
     Serial.print('.'); 
   }
 
   Serial.println("");
   Serial.print("Iniciado STA:\t");
   Serial.println(ssid);
   Serial.print("IP address:\t");
   Serial.println(WiFi.localIP());
   Serial.print("ESP Mac Address: ");
   Serial.println(WiFi.macAddress());
   Serial.print("Subnet Mask: ");
   Serial.println(WiFi.subnetMask());
   Serial.print("Gateway IP: ");
   Serial.println(WiFi.gatewayIP());
   Serial.print("DNS: ");
   Serial.println(WiFi.dnsIP());
   digitalWrite(2, HIGH);  //Activamos led interno para indicar conexión WIFI establecida
   
}

// Reconexion Wifi si detecta que no está conectado

void ReconnectionWifi(){
  unsigned long currentMillis = millis();

  if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >=interval)) {
    digitalWrite(2, LOW);
    WiFi.disconnect();
    WiFi.reconnect();
    previousMillis = currentMillis;
  }else{
    digitalWrite(2, HIGH);
  }
}

//Funcionamiento como AP
void ConnectWiFi_AP(bool useStaticIP = true)
{ 
   Serial.println("");
   WiFi.mode(WIFI_AP);
   while(!WiFi.softAP(ssid, password))
   {
     Serial.println(".");
     delay(100);
   }
   if(useStaticIP) WiFi.softAPConfig(ip, gateway, subnet);

   Serial.println("");
   Serial.print("Iniciado AP:\t");
   Serial.println(ssid);
   Serial.print("IP address:\t");
   Serial.println(WiFi.softAPIP());
}
