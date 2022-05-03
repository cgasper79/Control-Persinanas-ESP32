//Configuración WIFI

const char* ssid     = "Cris_Monike";
const char* password = "gascoing1979";
const char* hostname = "ESP32_Persianas";

IPAddress ip(192, 168, 1, 230);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(1, 1, 1, 1); 
IPAddress secondaryDNS(1, 0, 0, 1);

// Variables información conexión
String miIP;
String macAddr;
String mascaraRed;
String puertaEnlace;
String miDNS;
String miRSSI;

// variables para tiempo reconexion wifi (cada 30 segundos comprueba) 
// y tiempo subida persiana
unsigned long previousWifiMillis = 0;
unsigned long currentMillis = 0;
unsigned long previousPushMillis = 0;
unsigned long intervalWifi = 10000;
unsigned long intervalTotalSubida = 24000;

// variables 

//Variables configuración
bool modoNoche = true;
bool modoDia = false; 
bool mitadPersiana = true;
bool horarioVerano = true;

//variables detección boton subir
bool botonSubir = false;

//Variables tiempo y modo automático Noche/dia
int tiempoTotalSubida = 24; //en segundos
int horaBajadaAuto = 23;
int minutoBajadaAuto = 59;
int segundosBajadaAuto = 0;
int horaSubidaAuto = 8;
int minutoSubidaAuto = 59;
int segundosSubidaAuto = 0;
String horaActual;
String horaModoDia;
String horaModoNoche;

//RF
char codigoSubir1[] = "0Q0F010FFF0F0Q0F0F0F";  //Constante que almacena el codigo del mando para subir la persiana 1
char codigoBajar1[] = "0Q0F010FFF0F0Q0F0110";  //Constante que almacena el codigo del mando para bajar la persiana 1
char codigoStop1[] = "0Q0F010FFF0F0Q0FFFFF";   //Constante que almacena el codigo del mando para parar la persiana 1
char codigoSubir2[] = "0Q00010F11Q0Q10F0F1Q";  //Constante que almacena el codigo del mando para subir la persiana 2
char codigoBajar2[] = "0Q00010F11Q0Q10F0110";  //Constante que almacena el codigo del mando para bajar la persiana 2
char codigoStop2[] = "0Q00010F11Q0Q10FFFFF";   //Constante que almacena el codigo del mando para parar la persiana 2
const int LED = 13; //Salida para RF
