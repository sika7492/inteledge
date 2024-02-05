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
GPIO.output(led_pin[0],GPIO.HIGH)


HOW_MANY_MESSAGES = 10

mq = queue.Queue(HOW_MANY_MESSAGES)


flag_exit = False

def t1():
        value = ''


        while True:
                value = input()

                mq.put(value)

                time.sleep(0.1)

                if flag_exit: 
                     break


thread = threading.Thread(target=t1)

thread.start()


def led_on(br):
    
    GPIO.output(led_pin[0],GPIO.HIGH)
    time.sleep(0.01*(br))
    GPIO.output(led_pin[0],GPIO.LOW)
    time.sleep(0.01*(1-br))





try:
    key_input=1
    br=1
    while True:
            
            if not mq.empty():
                key_input=mq.get()  # 1초 동안 기다립니다.
            
            if key_input == '0':
                br=0
            if key_input == '5':
                br=0.5
            if key_input == 't':      
                br=1 
            led_on(br)
                   
except KeyboardInterrupt:
    pass


GPIO.cleanup()

flag_exit = True

thread.join()