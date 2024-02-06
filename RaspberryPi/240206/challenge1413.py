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

for i in motor_pin:                      
    GPIO.setup(i,GPIO.OUT)
    GPIO.output(i,GPIO.LOW)



def LED_dimmer(color,sec):                           ## led가 점점 밝아지는 함수
    t_high=0
    cnt=0
    while True:
            
        GPIO.output(led_pin[color],True)
        time.sleep(0.012-t_high)
        GPIO.output(led_pin[color],False)
        time.sleep(t_high)
        t_high+=(0.01/(sec*100))
        if t_high>0.01:                       ##만약 time.sleep 함수의 인자가 음수라면 에러가 발생함으로 0.01보다 커질시 0.01로 변환
            t_high=0.01
        cnt+=1
        if cnt==sec*100:
            break
def LED_brighter(color,sec):
    t_high=0
    cnt=0
    while True:
        GPIO.output(led_pin[color],True)
        time.sleep(t_high)
        GPIO.output(led_pin[color],False)
        time.sleep(0.01-t_high)
        t_high+=(0.01/(sec*100))
        if t_high>0.01:                         ##만약 time.sleep 함수의 인자가 음수라면 에러가 발생함으로 0.01보다 커질시 0.01로 변환
            t_high=0.01
        cnt+=1
        if cnt==(sec*100):
            break
def led_on(color,sec):
    
    GPIO.output(led_pin[color],GPIO.HIGH)
    time.sleep(sec)
    GPIO.output(led_pin[color],GPIO.LOW)
    time.sleep(sec)

def setmotor(degree):
    if degree ==0:
         return
    for i in range(degree):
    
    #각핀을 순서대로 on off 한다.
        for j in motor_pin:                    
            GPIO.output(j,GPIO.HIGH)
            time.sleep(0.002)
            GPIO.output(j,GPIO.LOW)

flag_exit = False

def t1():
        while True:
            led_on(1,1.2)
            
            if flag_exit: 
                break
def t2():
        while True:
            LED_brighter(2,2.04)
            LED_dimmer(2,2.04)
            

            if flag_exit: 
                break
def t3():
        while True:
            setmotor(300)
            time.sleep(3.6)
            

            if flag_exit: 
                break

thread1 = threading.Thread(target=t1)
thread2 = threading.Thread(target=t2)
thread3 = threading.Thread(target=t3)
thread1.start()
thread2.start()
thread3.start()





try:
    while True:
            
            led_on(0,0.6)
            
                   
except KeyboardInterrupt:
    pass




flag_exit = True

thread1.join()
thread2.join()
thread3.join()
GPIO.cleanup()