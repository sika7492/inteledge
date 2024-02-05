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
for i in led_pin:
    GPIO.setup(i,GPIO.OUT)     
    GPIO.output(i,GPIO.HIGH)

def led_on(color,sec):
    
    GPIO.output(led_pin[color],GPIO.HIGH)
    time.sleep(sec)
    GPIO.output(led_pin[color],GPIO.LOW)
    time.sleep(sec)




flag_exit = False

def t1():
        while True:
            led_on(1,1.3)

            if flag_exit: 
                break
def t2():
        while True:
            led_on(2,1.7)

            if flag_exit: 
                break

thread1 = threading.Thread(target=t1)
thread2 = threading.Thread(target=t2)
thread1.start()
thread2.start()





try:
    key_input=1
    br=1
    while True:
            
        
            led_on(0,0.7)
                   
except KeyboardInterrupt:
    pass




flag_exit = True

thread1.join()
thread2.join()
GPIO.cleanup()