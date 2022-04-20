WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "es.pool.ntp.org", 3600, 60000);

//Modo automatico persianas

void modoAuto()
{
  timeClient.update();
  
  /**
  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }
  **/
  //Modo Noche
  if (modoNoche){
    if ((horaBajadaAuto == timeClient.getHours()) && (minutoBajadaAuto == timeClient.getMinutes()) 
        && (segundosBajadaAuto == timeClient.getSeconds())) {
      emisorBajar1();
      emisorBajar2();
    }
  }
  //Serial.println(timeClient.getFormattedTime());
  Serial.println(timeClient.getHours());
  Serial.println(timeClient.getMinutes());
  
}


void InitTime(){
  
  timeClient.begin();
  Serial.println("Iniciamos NTP");
}

//Temporizado para subir a media altura la persiana

void temporizadoMediaPersiana(){

  while (mitadPersiana && botonSubir){ 
    
    for (int i=0; i <= (tiempoTotalSubida/2); i++ ){
      delay(1000);
      Serial.println ("Temporizado subida persina");
    }   
    emisorStop1();
    delay (10);
    emisorStop2();
    botonSubir = false;   
  }
  
  botonSubir = false;
}
