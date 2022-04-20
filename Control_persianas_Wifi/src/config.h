//Configuración WIFI

const char* ssid     = "Cris_Monike";
const char* password = "gascoing1979";
const char* hostname = "ESP32_Persianas";

IPAddress ip(192, 168, 1, 230);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(1, 1, 1, 1); 
IPAddress secondaryDNS(1, 0, 0, 1);

//Variables funciones
bool modoNoche = true;
bool mitadPersiana = true;

//variables detección boton subir
bool botonSubir = false;

//Variables tiempo y modo automático Noche
int tiempoTotalSubida = 24; //en segundos
int horaBajadaAuto = 23;
int minutoBajadaAuto = 59;
int segundosBajadaAuto = 0;


//RF
char codigoSubir1[] = "0Q0F010FFF0F0Q0F0F0F";  //Constante que almacena el codigo del mando para subir la persiana 1
char codigoBajar1[] = "0Q0F010FFF0F0Q0F0110";  //Constante que almacena el codigo del mando para bajar la persiana 1
char codigoStop1[] = "0Q0F010FFF0F0Q0FFFFF";   //Constante que almacena el codigo del mando para parar la persiana 1
char codigoSubir2[] = "0Q00010F11Q0Q10F0F1Q";  //Constante que almacena el codigo del mando para subir la persiana 2
char codigoBajar2[] = "0Q00010F11Q0Q10F0110";  //Constante que almacena el codigo del mando para bajar la persiana 2
char codigoStop2[] = "0Q00010F11Q0Q10FFFFF";   //Constante que almacena el codigo del mando para parar la persiana 2
const int LED = 13; //Salida para RF
