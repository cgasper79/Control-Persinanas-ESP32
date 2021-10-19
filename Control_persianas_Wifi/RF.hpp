
//Declaramos variables para el envío del código de la persina por RF
RCSwitch mySwitch = RCSwitch();  //Generem mySwitch per l'envio del codi RF
char codigoSubir1[] = "0Q0F010FFF0F0Q0F0F0F";  //Constante que almacena el codigo del mando para subir la persiana 1
char codigoBajar1[] = "0Q0F010FFF0F0Q0F0110";  //Constante que almacena el codigo del mando para bajar la persiana 1
char codigoStop1[] = "0Q0F010FFF0F0Q0FFFFF";   //Constante que almacena el codigo del mando para parar la persiana 1
char codigoSubir2[] = "0Q00010F11Q0Q10F0F1Q";  //Constante que almacena el codigo del mando para subir la persiana 2
char codigoBajar2[] = "0Q00010F11Q0Q10F0110";  //Constante que almacena el codigo del mando para bajar la persiana 2
char codigoStop2[] = "0Q00010F11Q0Q10FFFFF";   //Constante que almacena el codigo del mando para parar la persiana 2
const int LED = 4; 


void InitRF(){

  Serial.println("Iniciamos RF");
  pinMode(LED, OUTPUT);
  mySwitch.enableTransmit(LED);  //Transmitimos RF por el pin 9
  mySwitch.setProtocol(4);    //Seleccionamos el protocol QUADSTATE  
}

void emisorSubir1() {
  Serial.println("Subimos persiana 1");
  mySwitch.sendQuadState (codigoSubir1); //Enviamos el código RF para subir la persina 1
  delay (200);
}


void emisorBajar1() {
  Serial.println("Bajamos persiana 1");
  mySwitch.sendQuadState (codigoBajar1); //Enviamos el código RF para bajar la persina 1
  delay (200);
}

void emisorStop1() {
  Serial.println("Paramos persiana 1");
  mySwitch.sendQuadState (codigoStop1); //Enviamos el código RF para Stop la persina 1
  delay (200);
}

void emisorSubir2() {
  Serial.println("Subimos persiana 2");
  mySwitch.sendQuadState (codigoSubir2); //Enviamos el código RF para subir la persina 2
  delay (200);
}

void emisorBajar2() {
  Serial.println("Bajamos persiana 2");
  mySwitch.sendQuadState (codigoBajar2); //Enviamos el código RF para bajar la persina 2
  delay (200);
}

void emisorStop2() {
  Serial.println("Paramos persiana 2");
  mySwitch.sendQuadState (codigoStop2); //Enviamos el código RF para Stop la persina 2
  delay (200);
}
