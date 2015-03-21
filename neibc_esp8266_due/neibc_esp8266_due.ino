/* Originally posted on www.bbangpan.com

   Program Description: ESP8266 WiFi Module testing code
   Needed library : None
   Tested on : Arduino 1.6.1, Arduino Due
   
   reference : http://www.seeedstudio.com/blog/2014/09/11/getting-started-with-esp8266/
   
   Copyright (c) 2015 www.bbangpan.com. All rights reserved.
   This program can be used for any non-commercial purpose freely.   */
   
#define SSID "xxxx" // wifi name
#define PASS "xxxx" // wifi password
#define DST_IP "143.248.5.153" //www.kaist.ac.kr

void setup()
{
     // Open Serial1 communications and wait for port to open:
     Serial2.begin(9600);
     Serial2.setTimeout(5000);
     Serial.begin(9600); //can't be faster than 19200 for softSerial1
     Serial.println("ESP8266 Demo");
     //test if the module is ready
     Serial2.println("AT+RST");
     delay(2000);
     if(Serial2.find("eady")) {
       Serial.println("Module is ready");
     } else {
       Serial.println("Module has no response.");
       while(1);
     }
     delay(1000);
     //connect to the wifi
     boolean connected=false;
     for(int i=0;i<5;i++) {
       if(connectWiFi()) {
         connected = true;
         break;
       }
     }

     if (!connected) {
       while(1);
     }
     delay(5000);
     //set the single connection mode
     Serial2.println("AT+CIPMUX=0");
}
   
void loop()
{
     String cmd = "AT+CIPSTART=\"TCP\",\"";
     cmd += DST_IP;
     cmd += "\",80";
     Serial2.println(cmd);
     Serial.println(cmd);
     if(Serial2.find("Error")) return;
     cmd = "GET / HTTP/1.0\r\n\r\n";
     Serial2.print("AT+CIPSEND=");
     Serial2.println(cmd.length());
     if(Serial2.find(">")) {
       Serial.print(">");
     } else {
         Serial2.println("AT+CIPCLOSE");
         Serial.println("connect timeout");
         delay(1000);
         return;
     }
     Serial2.print(cmd);
     delay(2000);
     //Serial1.find("+IPD");
     while (Serial2.available()) {
       char c = Serial2.read();
       Serial.write(c);
       if(c=='\r') Serial.print('\n');
     }
     delay(1000);
     while (Serial2.available()) {
       char c = Serial2.read();
       Serial.write(c);
       if(c=='\r') Serial2.print('\n');
     }
     Serial.println("====");
     delay(1000);
}
     
boolean connectWiFi() {
     Serial2.println("AT+CWMODE=1");
     String cmd="AT+CWJAP=\"";
     cmd+=SSID;
     cmd+="\",\"";
     cmd+=PASS;
     cmd+="\"";
     Serial.println(cmd);
     Serial2.println(cmd);
     delay(2000);
     if(Serial2.find("OK")) {
       Serial.println("OK, Connected to WiFi.");
       return true;
     } else  {
       Serial.println("Can not connect to the WiFi.");
       return false;
     }
 }
