import RPi.GPIO as GPIO
import time
buzzer =18
GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer,GPIO.OUT)
GPIO.setwarnings(False)

pwm=GPIO.PWM(buzzer,524)
pwm.start(50.0)
time.sleep(1.5)

pwm.stop()
GPIO.cleanup()