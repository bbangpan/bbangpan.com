/* Originally posted on www.bbangpan.com

   Program Description: 433/315Mhz receiver(XY-MK-5V) test code
   Needed library : VirtualWire http://www.pjrc.com/teensy/td_libs_VirtualWire.html
   DataPin : 11 to 433/315Mhz receiver DATA
   Tested on : Arduino 1.0.6, Arduino UNO R3, VirtualWire
   
   Inspired by http://www.buildcircuit.com/how-to-use-rf-module-with-arduino/
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */
   
#include <VirtualWire.h>

byte message[VW_MAX_MESSAGE_LEN]; // a buffer to store the incoming messages
byte messageLength = VW_MAX_MESSAGE_LEN; // the size of the message

const int RX_DIO_Pin = 11; // default 11

void setup()
{
  Serial.begin(9600);
  Serial.println("Ready to receive:");
  vw_set_rx_pin(RX_DIO_Pin); // Initialize RX pin
  vw_setup(2000); // Transfer speed : 2000 bits per sec
  vw_rx_start(); // Start the receiver
}

void loop()
{
  if (vw_get_message(message, &messageLength)) // Non-blocking
  {
    Serial.print("Received: ");
    for (int i = 0; i < messageLength; i++)
    {
      Serial.write(message[i]);
    }
    Serial.println();
  }
}

