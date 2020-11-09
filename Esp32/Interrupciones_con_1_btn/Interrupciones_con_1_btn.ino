#define btn 27

int i = 0;

void isr()
{
  Serial.println("!interrupcion");  
} 

void setup() {
  Serial.begin(115200);

  pinMode(btn.INPUT_PULLDOWN);
  attachInterrupt(btn, isr, RISING);
}

void loop() {
  Serial.println(i);
  i++;
  delay(200);
}
