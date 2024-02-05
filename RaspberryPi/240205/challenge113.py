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

GPIO.setup(buzzer_pin,GPIO.OUT)     
pwm=GPIO.PWM(buzzer_pin,1.0)
pwm.start(10.0)
pwm.stop()


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

freq=[523,587,659,698,784,880,988,1047]
def buzzer(freq_num):
    if freq_num==10:
        return
    else :
        pwm.ChangeFrequency(freq[freq_num])
        pwm.start(10.0)
        time.sleep(0.5)
        pwm.stop()






try:
    key_input=1
    
    while True:
            freq_num=10
            
            if not mq.empty():
                key_input=mq.get()  
            
            if key_input == 'a':
                freq_num=0
                key_input=1
            elif key_input == 's':
                freq_num=1
                key_input=1
            elif key_input == 'd':      
                freq_num=2
                key_input=1
            elif key_input == 'f':      
                freq_num=3
                key_input=1
            elif key_input == 'g':      
                freq_num=4
                key_input=1
            elif key_input == 'r':      
                freq_num=5 
                key_input=1  
            elif key_input == 'l':      
                freq_num=6
                key_input=1
            elif key_input == 'k':      
                freq_num=7 
                key_input=1    
           
            buzzer(freq_num)
            
                   
except KeyboardInterrupt:
    pass


GPIO.cleanup()

flag_exit = True

thread.join()