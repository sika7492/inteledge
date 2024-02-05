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

for i in led_pin:
     GPIO.setup(i,GPIO.OUT)
     GPIO.output(i,GPIO.LOW)

GPIO.setup(sw_pin[0], GPIO.IN, pull_up_down=GPIO.PUD_UP)
     
def all_led_off():
     for i in led_pin:
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
button_status=0

def button_callback(channel):
    global button_status
    led(button_status)
    ##print(button_status)

    button_status=(button_status+1)%4
    

#GPIO 버튼 인터럽트 발생시 callback 함수를 실행한다
GPIO.add_event_detect(sw_pin[0], GPIO.FALLING, callback=button_callback, bouncetime=1000)


def led(color):
    if color==3:
        all_led_off()
        return
    else :
        all_led_off()  
        GPIO.output(led_pin[color],GPIO.HIGH)




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