/* Originally posted on www.bbangpan.com
   Program Description: Mobile browser controlled servo motor on WeMos D1 WiFi board
   Tested on : Arduino 1.8.5, Arduino Compatible D1 WiFi, Servo Motor
   
   Copyright (c) 2019 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely. */

#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "MY_WIFI_SSID!!"; // should be changed
const char* pass = "MY_WIFI_PASS!!"; // should be changed

ESP8266WebServer server(80);
Servo myservo;

void setup(void){
  Serial.begin(115200);
  Serial.println(".");
  
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", [](){
    server.send(200, "text/html", "<h1>ON or OFF : <a href=\"/on\">ON</a> &nbsp;&nbsp;or <a href=\"/on\">OFF</a> or URL : /s?degree=90</h1>");
  });

  server.on("/s", [](){
    String sdegree = server.arg("degree");
    int degree = sdegree.toInt();
    Serial.print("degree: ");
    Serial.println(degree);
    myservo.write(degree);
    server.send(200, "text/plain", String(degree, DEC));
  });

  server.on("/on", [](){
    Serial.println("ON");
    myservo.write(180);
    server.send(200, "text/html", "<h1>ON! : <a href=\"/off\">OFF</a> or URL : /s?degree=90 </h1>");
  });

  server.on("/off", [](){
    Serial.println("OFF");
    myservo.write(0);
    server.send(200, "text/html", "<h1>OFF! : <a href=\"/on\">ON</a> or URL : /s?degree=90 </h1>");
  });
  
  server.begin();
  Serial.println("HTTP server started");
  
  myservo.attach(D5);   // Servo attached to D5 pin
  myservo.write(0);
}
 
void loop(void){
  server.handleClient();
} 
