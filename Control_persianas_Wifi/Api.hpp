
//Variables funciones
bool modoNocheDia;
bool mitadPersiana;

//variables detección boton subir
bool botonSubir;

//Variables tiempo
unsigned long previousMillis = 0; 
unsigned long tiempoTotalSubida = 24000; 


//Detección modos funcionamiento
void setGPIO(String id, bool state)
{
   Serial.print("Set GPIO ");
   Serial.print(id);
   Serial.print(": ");
   Serial.println(state);

   switch (id.toInt() ){
    
    // Modo Noche/dia
    case 9:
      modoNocheDia = (state);
      break;

    // Mitad recorrido persiana
    case 10:
      mitadPersiana  = (state);
      break;

    default:
      break;
   }   
}


//Función detección botón orden persiana

void doAction(String actionId)
{
   Serial.print("Botón acción: ");
   Serial.println(actionId);

  switch (actionId.toInt()){
    
    case 0:
      emisorSubir1();
      botonSubir = true;
      break;

    case 1:
      emisorBajar1(); 
      break;

    case 2:
      emisorStop1();
      break;

    case 3:
      emisorSubir2();
      botonSubir = true;
      break;

    case 4:
      emisorBajar2();
      break;

    case 5:
      emisorStop2();
      break;

    case 6:
      emisorSubir1();
      delay (10);
      emisorSubir2();
      botonSubir = true;
      break;

    case 7:
      emisorBajar1();
      delay (10);
      emisorBajar2();
      break;

    case 8:
      emisorStop1();
      delay (10);
      emisorStop2();
      break;
      
    default:
      break;    
  }
}


//Temporizado para subir a media altura la persiana

void temporizadoMediaPersiana(){
  
   unsigned long currentMillis = millis();

   if (currentMillis - previousMillis >= (tiempoTotalSubida/2)){
      previousMillis = currentMillis;
      
      if (mitadPersiana && botonSubir){
         emisorStop1();
         delay (10);
         emisorStop2();
      }
      botonSubir = false;
  }
  
}
