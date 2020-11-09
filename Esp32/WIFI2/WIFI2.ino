#include <WiFi.h>
#include <WiFiUdp.h>
// WiFi details
const char *ssid     = "TP-LINK_7A0A";
const char *password = "7A3L1B9A";

//
void WiFi_Setup(){

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected!");
}

//Procedimiento datos wifi
void DatosWIFI(){
  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());//Metodos, informacion acerca de la red
  Serial.print("ESP Mac Address: ");
  Serial.println(WiFi.macAddress());//Metodos, informacion acerca de la red
  Serial.print("Subnet Mask: ");
  Serial.println(WiFi.subnetMask());//Metodos, informacion acerca de la red
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());//Metodos, informacion acerca de la red
  Serial.print("DNS: ");
  Serial.println(WiFi.dnsIP());//Metodos, informacion acerca de la red
  }

//
void setup(){
  Serial.begin(115200);//Puerto serial
  WiFi_Setup();//Intenta conectarse con los datos
  DatosWIFI();//
}

//No se ejecuta muchas veces porque no se puso nada en el void loop
void loop() {
 
}
