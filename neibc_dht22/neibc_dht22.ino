/* Originally posted on www.bbangpan.com

   Program Description: DHT22 sensor test code
   Needed library : DHT
   Tested on : Arduino 1.0.6, Arduino UNO R3, DHT22(registor integrated)
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */


#include "DHT.h"

#define DHTPIN 2     // data pin to DHT22
#define DHTTYPE DHT22   // using DHT 22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("DHT22 test:");
 
  dht.begin();
}

void loop() {
  float hum = dht.readHumidity();
  float tmp = dht.readTemperature();

  // check if returns are valid
  if (isnan(tmp) || isnan(hum)) {
    Serial.println("Reading error..");
  } else {
    Serial.print("Temperature: "); 
    Serial.print(tmp);
    Serial.print(" C\t");
    Serial.print("Humidity: "); 
    Serial.print(hum);
    Serial.println(" %");
  }
}
