
int LED_BUILTIN=2;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // Encender el LED
  delay(1);                       // tiempo de ensendido
  digitalWrite(LED_BUILTIN, LOW);    // Apagar LED
  delay(1);                       // tiempo de apagado
}
