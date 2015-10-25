/* Originally posted on www.bbangpan.com

   Program Description: FC-03 IR tachometer sensor test code
   Tested on : Arduino 1.7.6, Arduino UNO R3, FC-03
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */

#define encdpin               2

volatile int count, countold;
unsigned long ignoremilli = 10;	// to prevent unexpected peak
unsigned long oldtime = 0;
unsigned long time = 0;

void setup()
{
  count = 0;
  countold = 0; 
  oldtime = millis();
  
  pinMode(encdpin, INPUT);
  pinMode(13, OUTPUT); 
  attachInterrupt(digitalPinToInterrupt(encdpin), sensor1, FALLING);

  Serial.begin(9600); 
  Serial.println("start");
}

void loop()
{
  if (countold != count)
  {
    Serial.println(count);
       countold = count;
  }
}

void sensor1()
{
  time = millis();
  
  if( (time - oldtime) > ignoremilli ) {
   count++; 
  }
  oldtime = millis();
  
}


