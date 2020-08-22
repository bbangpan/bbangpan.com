  
/* Originally posted on www.bbangpan.com
   Program Description: HC-12 network module (send test)
   Tested on : Arduino 1.8.5, Arduino UNO R3, HC-12
   
   Copyright (c) 2020 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */
   
#include <SoftwareSerial.h>
SoftwareSerial HC12(2,3); // HC-12 TX Pin, HC-12 RX Pin

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);        // Serial port to computer
  HC12.begin(9600);         // Serial port to HC12
}

void loop()
{
  while(HC12.available()) {
    Serial.print((char)HC12.read());
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  }
  delay(200);
}



