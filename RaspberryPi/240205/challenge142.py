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



flag_exit = False

def t1():
        while True:
            LED_brighter(1,1.3)
            LED_dimmer(1,1.3)
            
            if flag_exit: 
                break
def t2():
        while True:
            LED_brighter(2,1.7)
            LED_dimmer(2,1.7)
            

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
            
            LED_brighter(0,0.7)
            LED_dimmer(0,0.7)
            
                   
except KeyboardInterrupt:
    pass




flag_exit = True

thread1.join()
thread2.join()
GPIO.cleanup()