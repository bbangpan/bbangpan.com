/* Originally posted on www.bbangpan.com
   Program Description: HC-06 bluetooth 2.0 / HM-10 BLE test code
   DataPin : 2,3 to TX, RX of HC-06(cross connection)
   Tested on : Arduino 1.0.6, Arduino UNO R3, HC-06 or HM-10 BLE
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */
   
#include <SoftwareSerial.h>
  
SoftwareSerial BTSerial(2, 3); // SoftwareSerial(RX, TX)
  
void setup()  
{
  Serial.begin(9600);
  Serial.println("Hello!");

  // set the data rate for the BT port
  BTSerial.begin(9600);
}
void loop(){
  while (BTSerial.available()){ // if BT sends something
    byte data = BTSerial.read();
    Serial.write(data); // write it to serial(serial monitor)
  }
  
  while (Serial.available()){ // if Serial has input(from serial monitor)
    byte data = Serial.read();

    BTSerial.write(data); // write it to BT
  }
  
}

