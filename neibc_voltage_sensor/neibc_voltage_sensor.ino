/* Redistributed by www.bbangpan.com

   Program Description: Voltage Sensor(Meter)
   DataPin : Voltage Sensor Sig -> A1, GND -> GND
   Tested on : Arduino 1.7.4, Arduino UNO R3
   Refsite : http://henrysbench.capnfatz.com/henrys-bench/arduino-voltage-measurements/arduino-25v-voltage-sensor-module-user-manual/
   
   Copyright (c) 2016 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.
*/


float vout = 0.0;
float vin = 0.0;
float R1 = 30000.0;  
float R2 = 7500.0; 
int SPIN = A1;
int value = 0;

void setup(){
   pinMode(SPIN, INPUT);
   
   Serial.begin(9600);
   Serial.print("Voltage:");
}

void loop(){
   value = analogRead(SPIN);
   vout = (value * 5.0) / 1024.0;
   vin = vout / ( R2 / ( R1 + R2) ); 
   
   Serial.print("V: ");
   Serial.println(vin,2);
   
   delay(1000);
}
