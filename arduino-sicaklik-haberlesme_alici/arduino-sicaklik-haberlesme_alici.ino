-//sıcaklık gönderip LCD'de gösteren kablosuz bir termometrenin alıcısı
#include <String.h>
#include <SPI.h>
#include <nRF24L01p.h>
#define CSN 7
#define CE 8
#include <LiquidCrystal.h>

nRF24L01p alici(CSN, CE);
LiquidCrystal lcd(1,2,3,4,5);

void setup() {
  string sicaklik;
  lcd.begin(16,2);
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);
  alici.channel(70);
  alici.Rxadress("termometre");
  alici.init();
}

void loop() {
  while(alici.available()) {
    alici.read();
    alici.rxPL(sicaklik);
      if (sicaklik.length() > 0) {
        lcd.clear();
        lcd.println(sicaklik);
        sicaklik = " ";
      }
  }
}
