/* Originally posted on www.bbangpan.com

   Program Description: ATTINY85 test code
   Needed library : None
   Tested on : Arduino 1.0.6, Arduino UNO R3/ATTINY85
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */

int led = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
      digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(400);               // wait for a second
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
      delay(400);               // wait for a second
      digitalWrite(led, HIGH);
      delay(800);
      digitalWrite(led, LOW);
      delay(400);
      digitalWrite(led, HIGH);
      delay(400);
      digitalWrite(led, LOW);
      delay(400);
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
}
