
//Detección modos Configuración
void setGPIO(String id, bool state)
{
   //Serial.print("Set GPIO ");
   //Serial.print(id);
   //Serial.print(": ");
   //Serial.println(state);

   switch (id.toInt() ){
    
    // Modo Noche
    case 9:
      modoNoche = (state);
      break;

    // Modo Noche
    case 10:
      modoDia = (state);
      break;

    // Mitad recorrido persiana
    case 11:
      mitadPersiana  = (state);
      break;

    // Horario Verano
    case 12:
      horarioVerano = (state);

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
