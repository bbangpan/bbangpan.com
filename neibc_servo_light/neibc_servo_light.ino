/* Originally posted on www.bbangpan.com

Program Description: Servo motor & light sensor test code
Needed library : Servo(Arduino's default library)
Tested on : Arduino 1.8.5, Arduino UNO R3, Small size servo motor

Copyright (c) 2020 www.bbangpan.com. All right reserved.

This program can be used for any non-commercial purpose freely. */

#include <Servo.h>

int servoPin = 9;
int cdsPin = A0;
int jump = 0;
int readytojump = 0;
int cdst1 = 0;
int cdst2 = 0;
 
Servo servo;

int angle = 0; // servo position in degrees

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
  servo.write(0);
  delay(1000);
}

 

void loop() {
  int  cdst3 = analogRead(cdsPin);

  // averaging past three values
  int  cds = (cdst1 + cdst2 + cdst3) / 3                ;
  cdst1 = cdst2;
  cdst2 = cdst3;

  if (cds > 206 && readytojump == 1) {
      jump = 1;
      readytojump = 0;
  } else if(cds < 190) {
      readytojump = 1;
      jump = 0; 
  }
 if (cds > 185) {
    Serial.print("cds =  ");
    Serial.println(cds);
  }
  if(jump == 1) { 
    jump = 0;
    Serial.println("JUMP!");
    servo.write(80);
    delay(150);
    servo.write(0);                                               
  }

}

