/* Originally posted on www.bbangpan.com

   Program Description: Servo motor test code(angle change)
   Needed library : Servo(Arduino's default library)
   Tested on : Arduino 1.0.6, Arduino UNO R3, Small size servo motor
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */

#include <Servo.h> 
 
int servoPin = 9;

Servo servo; 

int angle = 0; // servo position in degrees 

void setup() 
{ 
  servo.attach(servoPin); 
  Serial.begin(9600);
} 

void loop() 
{ 
  // 0 to 180 degrees
  for(angle = 0; angle < 180; angle = angle + 10) 
  { 
    Serial.print("normal mode/angle : ");
    Serial.println(angle);
    servo.write(angle); 
    delay(1000); 
  } 
  // 180 to 0 degrees
  for(angle = 180; angle > 0; angle = angle - 10) 
  { 
    Serial.print("reverse mode/angle : ");
    Serial.println(angle);
    servo.write(angle); 
    delay(1000); 
  } 
} 
