import RPi.GPIO as GPIO
import time
buzzer =18
freq=[523,587,659,698,784,880,988,1047]
GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer,GPIO.OUT)


pwm=GPIO.PWM(buzzer,1.0)
pwm.start(5.0)

for i in range(0,8):
    pwm.ChangeFrequency(freq[i])
    time.sleep(1.0)

pwm.stop()
GPIO.cleanup()