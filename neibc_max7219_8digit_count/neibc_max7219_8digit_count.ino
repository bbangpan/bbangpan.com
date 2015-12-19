/* Originally posted on www.bbangpan.com

   Program Description: MAX7219 8digits LED with dots
   Needed library : LedControl
   Tested on : Arduino 1.7.4, Arduino UNO R3, MAX7219 8 digits LED
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */

#include "LedControl.h" // Arduino Pin 7 to DIN, 6 to Clk, 5 to LOAD, no.of devices is 1 
LedControl lc=LedControl(7,6,5,1); 
int digitval[8];

void setup() { // Initialize the MAX7219 device 
  lc.shutdown(0,false); // Enable display 
  lc.setIntensity(0,10); // Set brightness level (0 is min, 15 is max) 
  lc.clearDisplay(0); // Clear display register 
  
  digitval[0]=3;
  digitval[1]=2;
  digitval[2]=1;
  digitval[3]=0;
  digitval[4]=0;
  digitval[5]=0;
  digitval[6]=0;
  digitval[7]=0;
  
} 

void loop() { 
  for(int i=0; i<8; i++){
    lc.setDigit(0,i,digitval[i],true);
  } 
  delay(10);
  
  digitval[0]=digitval[0]+1;

  for(int i=0; i<7; i++) {  
    if(digitval[i]>9) {
     digitval[i]=0;
     digitval[i+1]=digitval[i+1]+1;
    }
  }
}

