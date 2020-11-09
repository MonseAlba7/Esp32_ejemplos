#include "WiFi.h" //libreria

void setup()
{
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA); 
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");//Desconecta
}

void loop()
{
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
    }
    Serial.println("");

    // Wait a bit before scanning again
    delay(10000);//segundos para seguir leyendo las señales disponibles de WIFI
}
