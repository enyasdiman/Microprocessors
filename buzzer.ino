int green = 5;
int red = 10;
int fan = 11;
int buzzer = 12;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  float ham = analogRead(A0);
  float gerilim = (ham/1023)*5000;
  float sicaklik = (gerilim/10.0);

  if(sicaklik > 50) {
    digitalWrite(red, 1);
    digitalWrite(fan, 1);
    digitalWrite(green, 0);
    tone(buzzer, 1000);
  }
  else {
    digitalWrite(red, 0);
    digitalWrite(fan, 0);
    digitalWrite(green, 1);
    noTone(buzzer);
  }
}
