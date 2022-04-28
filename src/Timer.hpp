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
