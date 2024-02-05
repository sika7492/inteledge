import queue
import threading
import time
import RPi.GPIO as GPIO



#핀설정
led_pin=[4,5,6]
sw_pin=[12,13,14,15]
motor_pin=[20,21,22,23]
buzzer_pin=18



GPIO.setmode(GPIO.BCM)

LED_PIN = 4
BUTTON_PIN = 12

GPIO.setup(LED_PIN, GPIO.OUT)
GPIO.setup(BUTTON_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)

led_status = False

def button_callback(channel):
    global led_status
    led_status = not led_status
    GPIO.output(LED_PIN, led_status)

#GPIO 버튼 인터럽트 발생시 callback 함수를 실행한다
GPIO.add_event_detect(BUTTON_PIN, GPIO.FALLING, callback=button_callback, bouncetime=300)

try:
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    GPIO.cleanup()