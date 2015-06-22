
/* Originally posted on www.bbangpan.com

   Program Description: TTL laser module
   Tested on : Arduino 1.7.4, Arduino UNO R3, 
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */
   
const int SigPin=8;
const int ledPin=13;

void setup() {
  pinMode(SigPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  Serial.begin(9600);
} 
 
void loop() {
  digitalWrite(SigPin,HIGH);
  digitalWrite(ledPin,HIGH);
  delay(1000);
  digitalWrite(SigPin,LOW );
  digitalWrite(ledPin,LOW);
  delay(1000);
}
