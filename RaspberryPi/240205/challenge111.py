import queue
import threading
import time
import RPi.GPIO as GPIO



#핀설정
led_pin=[4,5,6]
sw_pin=[12,13,14,15]
motor_pin=[20,21,22,23]
buzzer_pin=18


#모드 설정
GPIO.setmode(GPIO.BCM)

GPIO.setup(led_pin[0],GPIO.OUT)     
GPIO.output(led_pin[0],GPIO.LOW)


HOW_MANY_MESSAGES = 10

mq = queue.Queue(HOW_MANY_MESSAGES)


flag_exit = False

def t1():
        value = ''


        while True:
                value = input()

                mq.put(value)

                time.sleep(0.1)

                if flag_exit: break


thread = threading.Thread(target=t1)

thread.start()


def led_on():
    GPIO.output(led_pin[0],GPIO.HIGH)

def led_off():
     GPIO.output(led_pin[0],GPIO.LOW)



try:
    while True:
            key_input=mq.get()
            if key_input == 'n':
                led_on()
            if key_input == 'f':
                led_off()    
                 

except KeyboardInterrupt:
    pass

GPIO.cleanup()

flag_exit = True

thread.join()