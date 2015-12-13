/* Redistributed by www.bbangpan.com

   Program Description: TMP1638 8 digits/LEDs module
   Needed library : TMP1538 https://github.com/rjbatista/tm1638-library
   DataPin : DIO->D8, CLK->D9, STB->D7
   Tested on : Arduino 1.7.4, Arduino UNO R3
   
   Inspired by https://grenville.wordpress.com/2012/06/02/an-led-display-with-pushbuttons-for-arduino-io/
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely. 
   
Original comments--------------------------------------------------------

Copyright (C) 2011 Ricardo Batista <rjbatista at gmail dot com>

This program is free software: you can redistribute it and/or modify
it under the terms of the version 3 GNU General Public License as 
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

https://grenville.wordpress.com/2012/06/02/an-led-display-with-pushbuttons-for-arduino-io/
*/

#include <TM1638.h>

// DIO->D8, CLK->D9, STB->D7
TM1638 module(8, 9, 7);

byte dots = 1;
// Initial value for couting
long value = 300;
int incstep = 1;

void setup() {
 Serial.begin(9600);
 module.setDisplayToDecNumber(value, 0xFF); // 0xFF for enabling all dots

 delay(3000);
}

void loop() {
 byte keys = module.getButtons();  // 1 for S1, 2 for S2, 4 for S4, ....(2 bits)
 Serial.println(dots);
 module.setDisplayToDecNumber(value, dots, true);
 Serial.println(keys);
 module.setLEDs(keys); // 1 for LED1, 2 for LED2, 4 for LED3, 8 for LED4, 16 for LED05.. (2 bits)
 
 if(keys == 1) {
  leftdirled();
 } else if(keys == 2) {
  rightdirled();
 } else if(keys == 4) {
  incstep = -1;
 } else if(keys == 8) {
  incstep = 0;
 } else if(keys == 16) {
  incstep = 1;
 }
 delay(50);

 dots = (dots * 2);
 if (dots == 0) {
 dots = 1;
 }

 value = (value + incstep );
 
 if(value > 99999999) {
   value=0;
 } else if(value < 0) {
   value=99999999;
 }

}

void leftdirled() {
  byte tmp;
  
  for(tmp = 1; tmp=tmp*2; tmp<=128) {
    module.setLEDs(tmp);
    delay(100);
  } 
}

void rightdirled() {
  byte tmp;
  
  for(tmp = 128; tmp=tmp/2; tmp>=1) {
    module.setLEDs(tmp);
    delay(100);
  } 
}

