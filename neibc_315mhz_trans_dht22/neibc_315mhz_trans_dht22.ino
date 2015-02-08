/* Originally posted on www.bbangpan.com
   Program Description: 315Mhz transmitter(FS1000A or MX-FS-03V) and DHT22 test code
   Needed library : VirtualWire  http://www.pjrc.com/teensy/td_libs_VirtualWire.html , DHT
   DataPin : 4 to 315Mhz transmitter DATA(near GND), 9 to DHT22
   Tested on : Arduino 1.0.6, Arduino UNO R3, VirtualWire, DHT
   
   Inspired by http://www.HobbyComponents.com
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */

#include <VirtualWire.h>
#include "DHT.h"

#define DHTPIN 9     // what pin we're connected to
#define DHTTYPE DHT22

/* Digital IO pin that will be used for sending data to the transmitter */
const int TX_DIO_Pin = 4;
const int SENDINTERVAL = 5000;

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  
  dht.begin();
  pinMode(13, OUTPUT);
  vw_set_tx_pin(TX_DIO_Pin);
  vw_setup(2000); // transmit speed : 2000 bits per sec
}

/* Main program */
void loop()
{
  int Data;
  byte TxBuffer[4];
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
    
    Data = (int)(t*10);
    TxBuffer[0] = Data >> 8;
    TxBuffer[1] = Data;
    Data = (int)(h*10);
    TxBuffer[2] = Data >> 8;
    TxBuffer[3] = Data;
  
    digitalWrite(13, HIGH); 
    /* Send the data (2 bytes) */
    vw_send((byte *)TxBuffer, 4);
    /* Wait until the data has been sent */
    vw_wait_tx(); 
  
    /* Turn off the LED on pin 13 to indicate that we have 
     now sent the data */
    digitalWrite(13, LOW); 
  }
  delay(SENDINTERVAL);
}
