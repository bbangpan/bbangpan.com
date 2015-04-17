//  Author:Frankie.Chu
//  Date:9 April,2012
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//  http://www.seeedstudio.com/wiki/Grove_-_4-Digit_Display
//  Modified record:
//
//  Added by bbangpan.com RTClib( https://github.com/adafruit/RTClib ) combined
//
/*******************************************************************************/
#include <Wire.h>
#include "RTClib.h"
#include <TimerOne.h>
#include "TM1637.h"
#define ON 1
#define OFF 0
 
RTC_DS1307 RTC;
 
int8_t TimeDisp[] = {0x00,0x00,0x00,0x00};
unsigned char ClockPoint = 1;
unsigned char Update;
unsigned char halfsecond = 0;
unsigned char second;
unsigned char minute = 0;
unsigned char hour = 24;

#define CLK 4//pins definitions for TM1637 and can be changed to other ports    
#define DIO 3
TM1637 tm1637(CLK,DIO);

void setup()
{
  Wire.begin();
  RTC.begin();
  tm1637.set();
  tm1637.init();
  Timer1.initialize(500000);//timing for 500ms
  Timer1.attachInterrupt(TimingISR);//declare the interrupt serve routine:TimingISR
  DateTime now = RTC.now();
  
  hour = (unsigned char)now.hour();
  minute = (unsigned char)now.minute();
  second = (unsigned char)now.second();
}
void loop()
{
  if(Update == ON)
  {
    TimeUpdate();
    tm1637.display(TimeDisp);
  }
  
}
void TimingISR()
{
  halfsecond ++;
  Update = ON;
  if(halfsecond == 2){
    second ++;
    if(second == 60)
    {
      minute ++;
      if(minute == 60)
      {
        hour ++;
        if(hour == 24)hour = 0;
        minute = 0;
      }
      second = 0;
    }
    halfsecond = 0;  
  }
 // Serial.println(second);
  ClockPoint = (~ClockPoint) & 0x01;
}
void TimeUpdate(void)
{
  if(ClockPoint)tm1637.point(POINT_ON);
  else tm1637.point(POINT_OFF); 
  TimeDisp[0] = hour / 10;
  TimeDisp[1] = hour % 10;
  TimeDisp[2] = minute / 10;
  TimeDisp[3] = minute % 10;
/*
  TimeDisp[0] = minute / 10;
  TimeDisp[1] = minute % 10;
  TimeDisp[2] = second / 10;
  TimeDisp[3] = second % 10;
  */
  Update = OFF;
}
