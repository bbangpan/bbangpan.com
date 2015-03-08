# Originally posted on www.bbangpan.com
#  Program Description: LED blink, raspberry pi2 test
#  Tested on : Raspbian
#
#  Copyright (c) 2015 www.bbangpan.com. All rights reserved.
#  This program can be used for any non-commercial purpose freely.

import RPi.GPIO as GPIO
import time

# blink function
def blink(pin):
        GPIO.output(pin,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(pin,GPIO.LOW)
        time.sleep(1)
        return

# start main
GPIO.setmode(GPIO.BCM)
GPIO.setup(23, GPIO.OUT)

try:
        for i in range(0,100):
                blink(23)
except KeyboardInterrupt:
    GPIO.cleanup()
