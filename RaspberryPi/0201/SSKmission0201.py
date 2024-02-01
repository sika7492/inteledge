import RPi.GPIO as GPIO
import time


buzzer =18
#gpio 모드선택
GPIO.setmode(GPIO.BCM)
GPIO.setup(27,GPIO.IN)
GPIO.setup(buzzer,GPIO.OUT)
pwm=GPIO.PWM(buzzer,1.0)
pwm.start(10.0)
pwm.stop()

while 1:
    if GPIO.input(27):
        print("Detected")
        pwm.start(10.0)
    else:
        print("Not Detected")
        pwm.stop()
    time.sleep(0.5)

GPIO.clanup()