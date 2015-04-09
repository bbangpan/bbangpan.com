/* Originally posted on www.bbangpan.com

   Program Description: APC220 network module (recv test)
   Tested on : Arduino 1.6.1, Arduino UNO R3, APC220
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */
   
#include <SoftwareSerial.h>

SoftwareSerial APC(3, 4); // RX and TX
 
void setup()
{
  APC.begin(9600);    // start serial to APC
  Serial.begin(9600);
}

void loop()
{
   while(APC.available()) {
     Serial.print((char)APC.read());
   }
   delay(1000);
}
