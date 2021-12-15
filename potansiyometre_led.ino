int led;
int pot = 0;

void setup() {
  for(led = 2; led < 12; led++) {
    pinMode(led, OUTPUT);
  }
}

void loop() {
  for(led = 2; led < 12; led++) {
    pot = analogRead(A0);
    pot = map(pot, 0, 1023, 0, 1000);
    digitalWrite(led, 1);
    delay(pot);
    digitalWrite(led, 0);
  }
}
