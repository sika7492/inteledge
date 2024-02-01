import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(4,GPIO.OUT)
GPIO.setup(27,GPIO.IN)

try:
    while 1:
        if GPIO.input(27):
            GPIO.output(4,True)
            print("Detected")
            time.sleep(1)
        else:
            GPIO.output(4,False)
            print("Not Detected")
            time.sleep(1)
except KeyboardInterrupt:
    GPIO.clanup()
    pass


