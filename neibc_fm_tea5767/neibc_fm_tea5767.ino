/* Originally posted on www.bbangpan.com

   Program Description: FM module test code
   Needed library : Wire
   Tested on : Arduino 1.6.1, Arduino UNO R3,TEA5767
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */
   
#include <Wire.h>

unsigned char frequencyH = 0;
unsigned char frequencyL = 0;
unsigned int frequencyB;

double frequency = 0;

void setup()
{
  Wire.begin();
  frequency = 93.1; //starting frequency
  setFrequency();
  Serial.begin(9600);
  Serial.println(frequency);
}

void loop()
{
  if(Serial.available()) {
    int rc = Serial.read();
    if(rc == '+' && frequency <= 108.0) {
      frequency += 0.1;
      setFrequency();
      Serial.println(frequency);
    } else if(rc == '-' && frequency >= 88.0) {
      frequency -= 0.1;
      setFrequency();
      Serial.println(frequency);
    } 
  }
}

void setFrequency()
{
  frequencyB = 4 * (frequency * 1000000 + 225000) / 32768;
  frequencyH = frequencyB >> 8;
  frequencyL = frequencyB & 0XFF;
  delay(100);
  Wire.beginTransmission(0x60);
  Wire.write(frequencyH);
  Wire.write(frequencyL);
  Wire.write(0xB0);
  Wire.write(0x10);
  Wire.write((byte)0x00);
  Wire.endTransmission();
  delay(100);  
}

