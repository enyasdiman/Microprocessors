#include <LCD5110_Basic.h>
LCD5110 myGLCD(8,9,10,11,12);
extern uint8_t BigNumbers[];
extern uint8_t smallFont[];
int trigpin = 3;
int echopin = 2;
int sure;
float mesafe = 0;

void setup() {
  pinMode(trigpin, OUTPUT);

  for(int i = 0; i<2; i++) {
    myGLCD.invert(true);
    delay(500);
    myGLCD.invert(false);
    delay(500);
  }
  myGLCD.clrScr();
}

void loop() {
  digitalWrite(trigpin, 1);
  delayMicroseconds(10);
  digitalWrite(trigpin, 0);
  delayMicroseconds(5);

  sure = pulseIn(echopin, HIGH);
  mesafe = sure / 58.2;

  myGLCD.setFont(smallFont);
  myGLCD.print("mesafe= ", LEFT, 10);
  myGLCD.setFont(BigNumbers);
  myGLCD.printNumI(mesafe, 40, 20);
  delay(100);

  myGLCD.clrScr();
}
