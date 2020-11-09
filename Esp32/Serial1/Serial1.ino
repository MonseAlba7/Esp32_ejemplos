int Contador=0;

void setup() {
  Serial.begin(115200);//configuracion de puerto serial(Velocidad)
}


void loop() {
  Contador=Contador+100; //es como un contador en java, contador+1
  Serial.println(Contador);
  delay(2000);        
}
