/* Originally posted on www.bbangpan.com

   Program Description: 433/315Mhz receiver(XY-MK-5V) test code (for dht22 transmit, oled display)
   Needed library : VirtualWire http://www.airspayce.com/mikem/arduino/VirtualWire/index.html, U8glib
   DataPin : 11 to 433/315Mhz receiver DATA
   Tested on : Arduino 1.0.6, Arduino UNO R3, VirtualWire, U8glib
   
   Inspired by http://www.buildcircuit.com/how-to-use-rf-module-with-arduino/
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */ 
   

#include <VirtualWire.h>
#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

const int RX_DIO_Pin = 11; // default 11
float t,h;

void draw(float tval, float hval) {
  u8g.setFont(u8g_font_unifont);
  
  u8g.setPrintPos(1,10);
  u8g.print("Temp: "); 
  u8g.print(tval);
  u8g.print(" C"); 
  u8g.setPrintPos(1,23);
  u8g.print("Hum: "); 
  u8g.print(hval);
  u8g.print(" %"); 
}

void setup()
{
    t=0;
    h=0;
    
    pinMode(13, OUTPUT);
    Serial.begin(9600);

    vw_set_rx_pin(RX_DIO_Pin);
    vw_setup(2000);
    vw_rx_start(); 

    u8g.firstPage();  
    do {
      draw(0,0);
    } while( u8g.nextPage() );
}

void loop()
{
  uint8_t Buffer_Size = 4;
  int Data;
  uint8_t RxBuffer[Buffer_Size];

  /* Accept the transmitted data */
  if (vw_get_message(RxBuffer, &Buffer_Size)) // Non-blocking
  {
    /* If so, then turn on the LED connected to DIO 13 
       to indicate this */
    digitalWrite(13, HIGH); 
   
    /* Store the received high and low byte data */
    Data = RxBuffer[0] << 8 | RxBuffer[1];
    t = (float)Data / 10.0;
    Data = RxBuffer[2] << 8 | RxBuffer[3];
    h = (float)Data / 10.0;
        
    Serial.print("Temparature : ");
    Serial.print(t);  
    Serial.print("  Humidity : ");
    Serial.println(h);  
    /* Turn off the LED on pin 13 to indicate that the 
       data has now been received */
    digitalWrite(13, LOW);
        
    u8g.firstPage();  
    do {
       draw(t, h);
    } while( u8g.nextPage() );

    delay(500);
  }
}

