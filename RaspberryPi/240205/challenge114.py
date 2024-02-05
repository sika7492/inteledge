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

for i in motor_pin:                      
    GPIO.setup(i,GPIO.OUT)
    GPIO.output(i,GPIO.LOW)

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



def setmotor(degree):
    if degree ==0:
         return
    for i in range(degree):
    
    #각핀을 순서대로 on off 한다.
        for j in motor_pin:                    
            GPIO.output(j,GPIO.HIGH)
            time.sleep(0.002)
            GPIO.output(j,GPIO.LOW)




try:
    key_input=1
    
    while True:
            degree=0
            
            if not mq.empty():
                key_input=mq.get()  
            
            if key_input == 'q':
                degree=0
                key_input=1
            elif key_input == 'w':
                degree=150
                key_input=1
            elif key_input == 'e':      
                degree=300
                key_input=1
           
           
            setmotor(degree)
            
                   
except KeyboardInterrupt:
    pass


GPIO.cleanup()

flag_exit = True

thread.join()