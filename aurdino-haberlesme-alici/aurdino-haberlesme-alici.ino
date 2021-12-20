#include <SPI.h>
#include <nRF24L01p.h>
#define CSN 2
#define CE 8

nRF24L01p alici(CSN, CE);
string mesaj;

void setup(9 {
  Serial.begin(9600);
  SPI.setBitOrder(MSBFIRST);
  alici.channel(90);
  alici.Rxadress("elektronik");
  alici.init();
}

void loop() {
  if(alici.available()) {
    alici.read();
    alici.rxPL(mesaj);
    Serial.println(mesaj);
  }
}
