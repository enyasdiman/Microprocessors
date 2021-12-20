#include <SPI.h> //seri iletişim kütüphanesi
#include <nRF24L01p.h>
#define CSN 7
#define CE 8

nRF24L01p verici(CSN, CE); //haberleşmenin yapıldığı pinler 

void setup() {
  Serial.begin(9600); //hızını tanımladık
  SPI.begin();
  SPI.setBitOrder(MSBFIRST); //alıcı tarafta da MSB(most significant byte) olması gerekir
  verici channel(90); //125 tane kanal var, istediğimizi kullanabiliriz ikisinin de kanalı aynı olmalı - kablosuz ağlar da bu şekilde - IEEE'de 12 tane
  verici Txadress("elektronik");
  verici.init();
}

void loop() {
  verici.TxPL("MERHABA");
  boolean durum = verici.send(SLOW); //fast ve slow oü. 2 yöntemi var gönderip göndermediğini test ediyoruz
    if(durum == TRUE) {
      Serial.println("Basarili");
    }
    else {
      Serial.println("Hatali");
    }
}

//buraya kadar vericiydi
