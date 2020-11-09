#include <WiFi.h>
#include <WiFiUdp.h>
#include "WiFi.h"

const char *ssid     = "TP-LINK_7A0A";
const char *password = "7A3L1B9A";

void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA); 
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");//Desconecta

    Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();//Cantidad de redes encontradas
    Serial.println("scan done"); //Manda un mensaje por serial de cada señal WIFI
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);//Imprime las redes 
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));//Metodos controlados para mostrar las señales Wifi disponibles. Estan en la biblioteca WIFI
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));//Metodos controlados para mostrar las señales Wifi disponibles. Estan en la biblioteca de WIFI
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");//Encripa.Encuentra las señales 
            delay(10);//cada ** milisegundos
        }

    Serial.println("");

    // Wait a bit before scanning again
    delay(10000);//segundos para seguir leyendo las señales disponibles de WIFI
          }
Serial.begin(115200);//Puerto serial
  WiFi_Setup();//Intenta conectarse con los datos
  DatosWIFI();//Intenta conectarse con los datos
}

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


//No se ejecuta muchas veces porque no se puso nada en el void loop
void loop() {
 
}
