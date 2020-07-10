/* Originally posted on www.bbangpan.com
   Program Description: PMS7003 dust sensor, plantower
   Tested on : Arduino 1.8.5, Arduino UNO
   
   Copyright (c) 2020 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */

#include <SoftwareSerial.h>

// VCC to V5, GND to GND, RX(PMS7003) to D6(Arduino), TX(PMS7003) to D7(Arduino)
#define PIN_TX_PMS7003 7  // PIN matched with TX of PMS7003  
#define PIX_RX_PMS7003 6  // PIN matched with RX of PMS7003  

#define HEAD_1 0x42
#define HEAD_2 0x4d

#define PMS7003_BAUD_RATE 9600 // Serial Speed of PMS7003

SoftwareSerial pmsSerial(PIN_TX_PMS7003,PIX_RX_PMS7003); // RX, TX of Arduino UNO
unsigned char pmsbytes[32]; // array for 32 bytes stream from PMS7003

void setup() {
  Serial.begin(115200); // Serial Monitor baud to 115200 on Arduino IDE
  pmsSerial.begin(PMS7003_BAUD_RATE);
}

void loop() {
  if(pmsSerial.available()>=32){
    int i=0;

    //initialize first two bytes with 0x00
    pmsbytes[0] = 0x00;
    pmsbytes[1] = 0x00;
    
    for(i=0; i<32 ; i++){
      pmsbytes[i] = pmsSerial.read();

      //check first two bytes - HEAD_1 and HEAD_2, exit when it's not normal and read again from the start
      if( (i==0 && pmsbytes[0] != HEAD_1) || (i==1 && pmsbytes[1] != HEAD_2) ) {
        break;
      }
    }

    if(i>2) { // only when first two stream bytes are normal
      if(pmsbytes[29] == 0x00) {  // only when stream error code is 0
        int PM1_0_val = (pmsbytes[10]<<8) | pmsbytes[11]; // pmsbytes[10]:HighByte + pmsbytes[11]:LowByte => two bytes
        int PM2_5_val = (pmsbytes[12]<<8) | pmsbytes[13]; // pmsbytes[12]:HighByte + pmsbytes[13]:LowByte => two bytes
        int PM10_val = (pmsbytes[14]<<8) | pmsbytes[15]; // pmsbytes[14]:HighByte + pmsbytes[15]:LowByte => two bytes
        
        Serial.print("PMS7003 sensor - PM1.0 : ");
        Serial.print(PM1_0_val);
        Serial.print(" ug/m^3,  PM2.5 : ");
        Serial.print(PM2_5_val);
        Serial.print(" ug/m^3,  PM10 : ");
        Serial.print(PM10_val);
        Serial.println(" ug/m^3");
      } else {
        Serial.println("Error skipped..");
      }
    } else {
      Serial.println("Bad stream format error");
    }
  }
}
