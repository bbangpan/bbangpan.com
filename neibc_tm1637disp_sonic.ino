#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 3
#define DIO 4

TM1637Display display(CLK, DIO);
const int trigPin = 8;    //Trig 핀 할당
const int echoPin = 7;    //Echo 핀 할당

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  long duration, cm=9999;

  display.setBrightness(0x0f);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = duration / 29 / 2;
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  display.showNumberDec(cm, true); 
  delay(100);
}

