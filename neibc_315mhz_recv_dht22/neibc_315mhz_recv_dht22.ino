/* Originally posted on www.bbangpan.com
   Program Description: 315Mhz receiver(MX-RM-5V, MX-05V) test code (for dht22 transmit)
   Needed library : VirtualWire http://www.pjrc.com/teensy/td_libs_VirtualWire.html
   DataPin : 11 to 315Mhz receiver DATA
   Tested on : Arduino 1.0.6, Arduino UNO R3, VirtualWire
   
   Inspired by http://www.buildcircuit.com/how-to-use-rf-module-with-arduino/
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */
   
#include <VirtualWire.h>

const int RX_DIO_Pin = 11; // default 11

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
  Serial.println("Ready to receive:");
  vw_set_rx_pin(RX_DIO_Pin); // Initialize RX pin
  vw_setup(2000); // Transfer speed : 2000 bits per sec
  vw_rx_start(); // Start the receiver
}

/* Main program */
void loop()
{
  /* Set the receive buffer size to 2 bytes */
  uint8_t Buffer_Size = 4;
  float t=0, h=0;  
  /* Holds the recived data */
  unsigned int Data;
  
  /* The receive buffer */
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
        
        delay(500);
  }
}

