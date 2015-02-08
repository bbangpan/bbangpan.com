/* Originally posted on www.bbangpan.com

   Program Description: IR send test(olleh TV turn on/off)DHT22 sensor test code
   Needed library : IRremote
   Tested on : Arduino 1.0.6, Arduino UNO R3, IR LED
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */

#include <IRremote.h>

IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  sendIR_OTS(1);
  delay(10000);
}

void sendIR_OTS(int type) {
    if (type == 1) { // turn on/off OLLEH TV
      sendIR_OTS(2);
      sendIR_OTS(3);
    } else if (type == 2) {
      irsend.sendNEC(0x20DF10EF, 32); //IR_TVPOWER 
    } else if (type == 3) {
      irsend.sendSony(0x9CA800FF, 32); // IR_STBPOWER 
    } else if (type == 4) {
      irsend.sendNEC(0x9CA88E71, 32); // IR_MOVIE 
    } else if (type == 5) {
      irsend.sendNEC(0x9CA84EB1, 32); // IR_TVREVIEW
    } else if (type == 6) {
      irsend.sendNEC(0x9CA8AE51, 32); // IR_APPSTORE
    } else if (type == 7) {
      irsend.sendNEC(0x9CA8827D, 32); // IR_MENU
    } else if (type == 8) {
      irsend.sendNEC(0x9CA8D827, 32); // IR_EPG
    } else if (type == 9) {
      irsend.sendNEC(0x9CA8F807, 32); // IR_VOLUP
    } else if (type == 10) {
      irsend.sendNEC(0x9CA802FD, 32); // IR_VOLDN
    } else if (type == 11) {
      irsend.sendNEC(0x9CA8C837, 32); // IR_OK
    } else if (type == 12) {
      irsend.sendNEC(0x9CA8926D, 32); // IR_CHUP
    } else if (type == 13) {
      irsend.sendNEC(0x9CA852AD, 32); // IR_CHDN
    } else if (type == 14) {
      irsend.sendNEC(0x9CA848B7, 32); // IR_GOFIRST
    } else if (type == 15) {
      irsend.sendNEC(0x9CA828D7, 32); // IR_GOLAST
    } else if (type == 16) {
      irsend.sendNEC(0x9CA88877, 32); // IR_UP
    } else if (type == 17) {
      irsend.sendNEC(0x9CA8A857, 32); // IR_DOWN
    } else if (type == 18) {
      irsend.sendNEC(0x9CA88679, 32); // IR_PREV
    } else if (type == 19) {
      irsend.sendNEC(0x9CA818E7, 32); // IR_MUTE
    } else if (type == 20) {
      irsend.sendNEC(0x9CA846B9, 32); // IR_EXIT
    } else if (type == 21) {
      irsend.sendNEC(0x9CA8A659, 32); // IR_REW
    } else if (type == 22) {
      irsend.sendNEC(0x9CA806F9, 32); // IR_PAUSE
    } else if (type == 23) {
      irsend.sendNEC(0x9CA8C639, 32); // IR_STOP
    } else if (type == 24) {
      irsend.sendNEC(0x9CA826D9, 32); // IR_FF
    } else if (type == 25) {
      irsend.sendNEC(0x9CA8C03F, 32); // IR_NUM1
    } else if (type == 26) {
      irsend.sendNEC(0x9CA820DF, 32); // IR_NUM2
    } else if (type == 27) {
      irsend.sendNEC(0x9CA8A05F, 32); // IR_NUM3
    } else if (type == 28) {
      irsend.sendNEC(0x9CA8609F, 32); // IR_NUM4
    } else if (type == 29) {
      irsend.sendNEC(0x9CA8E01F, 32); // IR_NUM5
    } else if (type == 30) {
      irsend.sendNEC(0x9CA810EF, 32); // IR_NUM6
    } else if (type == 31) {
      irsend.sendNEC(0x9CA8906F, 32); // IR_NUM7
    } else if (type == 32) {
      irsend.sendNEC(0x9CA850AF, 32); // IR_NUM8
    } else if (type == 33) {
      irsend.sendNEC(0x9CA8D02F, 32); // IR_NUM9
    } else if (type == 34) {
      irsend.sendNEC(0x9CA8728D, 32); // IR_ASTER
    } else if (type == 35) {
      irsend.sendNEC(0x9CA830CF, 32); // IR_NUM0
    } else if (type == 36) {
      irsend.sendNEC(0x9CA8F20D, 32); // IR_SHARP
    } else if (type == 37) {
      irsend.sendNEC(0x9CA82ED1, 32); // IR_SEARCH
    } else if (type == 38) {
      irsend.sendNEC(0x9CA86897, 32); // IR_ERASE
    } else if (type == 39) {
      irsend.sendNEC(0x9CA8B04F, 32); // IR_KORTOGGLE
    } else if (type == 40) {
      irsend.sendNEC(0x9CA838C7, 32); // IR_RED
    } else if (type == 41) {
      irsend.sendNEC(0x9CA8B847, 32); // IR_ORANGE
    } else if (type == 42) {
      irsend.sendNEC(0x9CA858A7, 32); // IR_GREEN
    } else if (type == 43) {
      irsend.sendNEC(0x9CA87887, 32); // IR_BLUE
    } else if (type == 44) {
      irsend.sendNEC(0x9CA856A9, 32); // IR_MYMENU
    } else if (type == 45) {
      irsend.sendNEC(0x9CA86E91, 32); // IR_SHOPPING
    } else if (type == 46) {
      irsend.sendNEC(0x9CA8C23D, 32); // IR_WIDGET
    } else if (type == 47) {
      irsend.sendNEC(0x9CA8B24D, 32); // IR_WEBSEARCH
    } else if (type == 48) {
      irsend.sendNEC(0x20DFD02F, 32); // IR_EXTINPUT
    } else if (type == 49) {
      irsend.sendNEC(0x20DF40BF, 32); // IR_TVVOLUP
    } else if (type == 50) {
      irsend.sendNEC(0x20DFC03F, 32); // IR_TVVOLDN
    }
}
 
