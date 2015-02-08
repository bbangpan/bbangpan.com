/* Originally posted on www.bbangpan.com

   Program Description: OLED 128x64 0.96" test code
   Needed library : U8glib
   Tested on : Arduino 1.0.6, Arduino UNO R3/NANO, OLED 128x64
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */
   
#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

void printText() {
  u8g.setFont(u8g_font_unifont);
  
  u8g.setPrintPos(6,15);
  u8g.print("Hello, world!"); 
  u8g.drawFrame(2,2,126,62);
}

void setup(void) {
}

void loop(void) {
  delay(1000); // dummy code
  u8g.firstPage();  
  do {
    printText();
  } while( u8g.nextPage() );
}

