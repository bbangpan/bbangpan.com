/* Originally posted on www.bbangpan.com

Program Description: HC-06 bluetooth 2.0 test code
DataPin : 2,3 to TX, RX of HC-06(cross connection)
Tested on : Arduino 1.0.6, Arduino UNO R3, HC-06

Copyright (c) 2015 www.bbangpan.com. All rights reserved.
This program can be used for any non-commercial purpose freely. */

#include <SoftwareSerial.h>

#define RXPIN 2 //to TX of HC-06
#define TXPIN 3 //to RX of HC-06
SoftwareSerial BTSerial(RXPIN, TXPIN);
 
void setup(){
  Serial.begin(9600);
  BTSerial.begin(9600);
}
 
void loop(){
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
