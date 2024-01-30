import RPi.GPIO as GPIO
import time

led_Red_pin =4

led_Green_pin = 5

led_Blue_pin =6

GPIO.setmode(GPIO.BCM)

GPIO.setup(led_Red_pin,GPIO.OUT)

GPIO.setup(led_Blue_pin,GPIO.OUT)

GPIO.setup(led_Green_pin,GPIO.OUT)


for i in range(20):
		GPIO.output(led_Red_pin,True)
		GPIO.output(led_Green_pin,False)
		GPIO.output(led_Blue_pin,False)
		print(i+1,"번째")
		print("Red on")
		time.sleep(0.5)
		GPIO.output(led_Red_pin,False)
		GPIO.output(led_Green_pin,True)
		GPIO.output(led_Blue_pin,False)
		print("Green")
		time.sleep(0.5)
		GPIO.output(led_Red_pin,False)
		GPIO.output(led_Green_pin,False)
		GPIO.output(led_Blue_pin,True)
		print("Blue")
		time.sleep(0.5)
GPIO.cleanup()
