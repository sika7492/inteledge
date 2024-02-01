import RPi.GPIO as GPIO
import time
buzzer =18
freq=[523,587,659,698,784,880,988,1047]
freq2=[1047,1175,1319,1397,1568,1760,1976,2093]
GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer,GPIO.OUT)
def delay():
    pwm.stop()
    time.sleep(0.1)
    pwm.start(10.0)

pwm=GPIO.PWM(buzzer,1.0)
pwm.start(10.0)

twinkle=[1,1,5,5,6,6,5,4,4,3,3,2,2,1,
        5,5,4,4,3,3,2,5,5,4,4,3,3,2,
        1,1,5,5,6,6,5,4,4,3,3,2,2,1]
try:
    for i in range(0,43):
        pwm.ChangeFrequency(freq[twinkle[i-1]])
        if i==6 or i==13 or i==20 or i==27 or i==34 or i==41:
            time.sleep(0.9)
            delay()
        else:
            time.sleep(0.4)
            delay()
    pwm.stop()
finally:
    GPIO.cleanup()

