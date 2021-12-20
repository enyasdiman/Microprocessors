//sıcaklık gönderip LCD'de gösteren kablosuz bir termometre
#include <String.h>
#include <SPI.h>
#include <nRF24L01p.h>
#define CSN 7
#define CE 8

float sicaklik;
static char veri[10];
nRF24L01p verici(CSN, CE);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  SPI.setBitOrder(LBSFIRST);
  verici.channel(70);
  verici.Txadress("termometre");
  verici.init();
}

void loop() {
  int ham = analogRead(A0);
  float gerilim = (ham/1023.0)*5000;
  sicaklik = gerilim/10.0;
  Serial.println(sicaklik);
  dtostrf(sicaklik,5,2, veri);
  //mesela 38,96 virgül dahil 5 karakterli, virgülden sonraki 2 bsm baz alıyoruz
  verici.TxPL(veri);
  boolean durum = verici.send(FAST);
    if(durum == true) {
      Serial.println("basarili");
    }
    else {
      Serial.println("hatali");
      delay(1000);
    }
}
