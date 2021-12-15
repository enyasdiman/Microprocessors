int buton1 = 2;
int buton2 = 3;
int sayi;

void setup() {
  pinMode(buton1, INPUT);
  pinMode(buton2, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(buton1)==LOW) {
    sayi++;
    while(digitalRead(buton1)==LOW) {}
  }
  if(digitalRead(buton2)==LOW) {
    sayi--;
    while(digitalRead(buton2)==LOW) {}
  }
  Serial.print("sayi= ");
  Serial.println(sayi);
  delay(250);
}
