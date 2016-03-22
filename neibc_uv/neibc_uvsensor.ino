/* Redistributed by www.bbangpan.com

   Program Description: UV Sensor test
   DataPin : GND->GND, VCC->5V, OUT->A0
   Tested on : Arduino 1.7.4, Arduino UNO R3
   
   Copyright (c) 2016 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.
   
*/

// index : voltage
// UV0 : ~50
// UV1 : ~227
// UV2 : ~318
// UV3 : ~408
// UV4 : ~504
// UV5 : ~606
// UV6 : ~696
// UV7 : ~795
// UV8 : ~881
// UV9 : ~976
// UV10 : ~1079
// UV11 : 1170~

int analogPin = 0;
int val = 0;


void setup()
{
  Serial.begin(9600);          //  setup serial
}

void loop()
{
  val = analogRead(analogPin);    // read the input pin
  Serial.println(val);             // debug value
}
