
//Declaramos variables para el envío del código de la persina por RF
RCSwitch mySwitch = RCSwitch();  //Generem mySwitch per l'envio del codi RF



void InitRF(){

  Serial.println("Iniciamos RF");
  mySwitch.enableTransmit(LED);  //Transmitimos RF por el pin D13
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
