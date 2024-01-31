import RPi.GPIO as GPIO
import time
buzzer =18
freq=[523,587,659,698,784,880,988,1047]
GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer,GPIO.OUT)
GPIO.setwarnings(False)

pwm=GPIO.PWM(buzzer,1.0)
pwm.start(50.0)
time.sleep(1.5)
for cnt in range(0,3):
    pwm.ChangeFrequency(freq[0])
    time.sleep(1.0)
    pwm.ChangeFrequency(freq[1])
    time.sleep(1.0)
    pwm.ChangeFrequency(freq[2])
    time.sleep(1.0)

pwm.stop()
GPIO.cleanup()