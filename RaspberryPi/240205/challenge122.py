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
GPIO.setup(sw_pin[0], GPIO.IN, pull_up_down=GPIO.PUD_UP)

br=0
led_status = 0

def button_callback(channel):
    global led_status,br

    if led_status==0:
         br=0
    elif led_status==1:
         br=0.5
    elif led_status==2:
         br=1
    led_status=(led_status+1)%3
    

#GPIO 버튼 인터럽트 발생시 callback 함수를 실행한다
GPIO.add_event_detect(sw_pin[0], GPIO.FALLING, callback=button_callback, bouncetime=300)



def led_on(br):
    
    GPIO.output(led_pin[0],GPIO.HIGH)
    time.sleep(0.01*(br))
    GPIO.output(led_pin[0],GPIO.LOW)
    time.sleep(0.01*(1-br))





try:
   
    while True:
            led_on(br)
            
                   
except KeyboardInterrupt:
    pass


GPIO.cleanup()



