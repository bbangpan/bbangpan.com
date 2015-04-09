/* Originally posted on www.bbangpan.com

   Program Description: APC220 network module (send test)
   Tested on : Arduino 1.6.1, Arduino UNO R3, APC220
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */
   
#include <SoftwareSerial.h>

SoftwareSerial APC(3, 4); // RX and TX
 
void setup()
{
  APC.begin(9600);    // start serial to APC
}

void loop()
{

   APC.print("H");
   delay(2000);
   APC.print("e");
   delay(2000);
   APC.print("l");
   delay(2000);
   APC.print("l");
   delay(2000);
   APC.print("o");
   delay(2000);
   APC.print(" world!");
   delay(2000);
}
