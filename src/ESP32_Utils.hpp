
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
   miIP = String (WiFi.localIP());
   

   Serial.print("ESP Mac Address: ");
   Serial.println(WiFi.macAddress());
   macAddr = WiFi.macAddress();

   Serial.print("Subnet Mask: ");
   Serial.println(WiFi.subnetMask());
   mascaraRed = String (WiFi.subnetMask());

   Serial.print("Gateway IP: ");
   Serial.println(WiFi.gatewayIP());
   puertaEnlace = String (WiFi.gatewayIP());

   Serial.print("DNS: ");
   Serial.println(WiFi.dnsIP());
   miDNS = String (WiFi.dnsIP());

   Serial.print("RRSI: ");
   Serial.println(WiFi.RSSI());
   miRSSI = String (WiFi.RSSI());

   digitalWrite(2, HIGH);  //Activamos led interno para indicar conexión WIFI establecida
   
}

// Reconexion Wifi si detecta que no está conectado
void ReconnectionWifi(){
  
  miRSSI = String (WiFi.RSSI());
  if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousWifiMillis >=intervalWifi)) {
    digitalWrite(2, LOW);
    WiFi.disconnect();
    WiFi.reconnect();
    previousWifiMillis = currentMillis;
    Serial.println("Intento Conexion");
  } else if (WiFi.status() == WL_CONNECTED){
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
