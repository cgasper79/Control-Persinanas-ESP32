WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

void modoAuto()
{
  timeClient.update();
  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }

  while (modoNoche){
    //Modo Noche
    if ((horaBajadaAuto == timeClient.getHours()) && (minutoBajadaAuto == timeClient.getMinutes()) 
        && (segundosBajadaAuto == timeClient.getSeconds())) {
      emisorBajar1();
      emisorBajar2();
    }
  }
  //Serial.println(timeClient.getFormattedTime());
  //Serial.println(timeClient.getHours());
  //Serial.println(timeClient.getMinutes());
  delay(1000);
}


void InitTime(){
  
  timeClient.begin();
  Serial.println("Iniciamos NTP");
}
