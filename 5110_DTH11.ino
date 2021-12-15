#include <dht11.h>
#include <LCD5110_Basic.h>
int DHT11_pin = 2;
dht11 DHT11_sensor;
LCD5110 myGLCD(8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t BigNumbers[];
int istenilen_sicaklik = 25;
int istenilen_nem = 32;


int led_nem= 5;
int led_sicaklik= 6;

void setup(){
  myGLCD.InitLCD();
  pinMode(led_nem,OUTPUT);
  pinMode(led_sicaklik,OUTPUT);
}
void loop(){
  int veri = DHT11_sensor.read(DHT11_pin);
  float h = DHT11_sensor.humidity; 
  float t = DHT11_sensor.temperature;
  
  int pot_sicaklik = analogRead(A1);
  int pot_nem = analogRead(A2);
  int pot_sicaklik1 = map(pot_sicaklik,0,1023,0,50);
  int pot_nem1 = map(pot_nem,0,1023,0,100);
  myGLCD.setFont(SmallFont);
  myGLCD.clrScr();
  myGLCD.print(("NEM"),LEFT,10);
  delay(300);
  myGLCD.setFont(BigNumbers);
  myGLCD.printNumI(h,40,20);

  if(pot_nem1>=istenilen_nem){
    digitalWrite(5,HIGH);}
  else{
    digitalWrite(5,LOW);
  }
  if (pot_sicaklik1>=istenilen_sicaklik){
    digitalWrite(6,HIGH);}
    else{
    digitalWrite(6,LOW);
  }

  
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
 
