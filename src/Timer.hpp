int gmtHora;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

// Poner Hora NTP

void horaNTP(){
  //Revisamos horario Verano
  if (horarioVerano){
    gmtHora = 7200;
  } else {
    gmtHora = 3600;
  }
  //Actualizamos hora NTP local
  timeClient.setTimeOffset(gmtHora);
  timeClient.update();
  horaActual = timeClient.getFormattedTime();  
}

//Modo automatico persianas
void modoAuto()
{
  //Montar hora Subida/bajada para subirlo a Websockets
  horaModoDia = String (horaSubidaAuto) + ':' + String (minutoSubidaAuto);
  horaModoNoche = String (horaBajadaAuto) + ':' + String (minutoBajadaAuto);
  
  //Modo Noche
  if (modoNoche){
    if ((horaBajadaAuto == timeClient.getHours()) && (minutoBajadaAuto == timeClient.getMinutes()) 
        && (segundosBajadaAuto == timeClient.getSeconds())) {
      emisorBajar1();
      emisorBajar2();
    }
  }

  //Modo Dia
  if (modoDia){
    if ((horaSubidaAuto == timeClient.getHours()) && (minutoSubidaAuto == timeClient.getMinutes()) 
        && (segundosSubidaAuto == timeClient.getSeconds())) {
      emisorSubir1();
      emisorSubir2();
      modoDia = false;
    }
  }
}


void InitTime(){
  
  timeClient.begin();
  Serial.println("Iniciamos NTP");
}

//Temporizado para subir a media altura la persiana

void temporizadoMediaPersiana(){

  if ((mitadPersiana) && (botonSubir) && (currentMillis - previousPushMillis >= intervalTotalSubida/2)){
    
    Serial.println ("Temporizado subida persina");
    botonSubir = false;
    emisorStop1();
    emisorStop2();
  }

}

//Calculamos tiempo encendido en horas
void timeStartUp(){
  int secondsStartUP = currentMillis / 1000;
  int minutsStartUP = secondsStartUP / 60;
  int hoursStartUP = minutsStartUP / 60;
  int daysStartUP = hoursStartUP / 24;

  timeUntilStartUp = String (daysStartUP) + 'd' + ' ' + String (hoursStartUP % 24) + 'h' + ' ' + String (minutsStartUP % 60) + 'm'; 
  
  Serial.println (timeUntilStartUp);

  updateInformationString(18,timeUntilStartUp);

}
