const int BUTTON1 = 2;
const int BUTTON2 = 4;
const int BLUE = 8;
const int RED = 12;
int BUTTONstate1 = 0;
int BUTTONstate2 = 0;

void setup()
{
pinMode(BUTTON1, INPUT);
pinMode(BUTTON2, INPUT);
pinMode(BLUE, OUTPUT);
pinMode(RED, OUTPUT);
}

void loop()
{
BUTTONstate1 = digitalRead(BUTTON1);
if (BUTTONstate1 == HIGH)
{
digitalWrite(BLUE, HIGH);
}
else{
digitalWrite(BLUE, LOW);
}
BUTTONstate2 = digitalRead(BUTTON2);
if (BUTTONstate2 == LOW)
{
digitalWrite(RED, LOW);
}
else{
digitalWrite(RED, HIGH);
}
}
