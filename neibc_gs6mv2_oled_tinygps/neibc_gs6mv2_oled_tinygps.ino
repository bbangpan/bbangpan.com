/* Originally posted on www.bbangpan.com

   Program Description: FM module test code
   Needed library : TinyGPS https://github.com/mikalhart/TinyGPS
   Tested on : Arduino 1.7.4, Arduino Mega ADK, blox Neo 6M GPS Module, TigyGPS
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */

//#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

//SoftwareSerial mySerial(3,4); // RX(<-TX of GPS module), TX(<-RX of GPS module)
TinyGPS gps;

void gpsdump(TinyGPS &gps);
void printFloat(double f, int digits = 2);

void setup()  
{
  Serial.begin(9600);

  // set the data rate for the SerialPort(use SoftwareSerial port on Arduino UNO)
  Serial2.begin(9600);  // Serial2->mySerial on Arduino UNO
  
  delay(1000);
  Serial.print("uBlox Neo 6M / TinyGPS testing - ");
  Serial.println(TinyGPS::library_version());

  u8g.setFont(u8g_font_unifont);
  u8g.drawFrame(2,2,126,62);
  u8g.firstPage();  
  do {
    u8g.setPrintPos(6,20);
    u8g.print("GPS Ready"); 
  } while( u8g.nextPage() );
}

void draw(float lat, float lon, unsigned long l_date, unsigned long l_time, float f_alt, float f_speed) {
  u8g.setFont(u8g_font_unifont);
  
  u8g.firstPage();
  do {
      u8g.setPrintPos(1,10);
      u8g.print("A:"); 
      u8g.print(lat);  // latitude
      u8g.setPrintPos(1,20);
      u8g.print("O:"); 
      u8g.print(lon); // longitude
      u8g.setPrintPos(1,30);
      u8g.print("D:"); 
      u8g.print(l_date); // date(ddmmyy, UTC 0)
      u8g.setPrintPos(1,40);
      u8g.print("T:"); 
      u8g.print(l_time); // time(hhmmsscc, UTC 0)
      u8g.setPrintPos(1,50);
      u8g.print("A:"); 
      u8g.print(f_alt); // altitude(cm)
      u8g.print("/S:"); 
      u8g.print(f_speed); // speed(km per hour)
  } while( u8g.nextPage() );
}

void loop() // run over and over
{
  bool newdata = false;
  unsigned long start = millis();
  float flat, flon, falt, fspeed;
  unsigned long date, time, age;
  
  // Every 2 seconds we print an update
  while (millis() - start < 5000) {
    if (Serial2.available() && gps.encode(Serial2.read())) {
        newdata = true;
        // break;  // uncomment to print new data immediately!
    }
  }
  
  if (newdata) {
    gps.f_get_position(&flat, &flon, &age);
    gps.get_datetime(&date, &time, &age);
    fspeed = gps.f_speed_kmph();
    falt = gps.f_altitude();
    draw(flat, flon, date, time, falt,fspeed);
  }
}  


