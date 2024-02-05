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

GPIO.setup(sw_pin[0], GPIO.IN, pull_up_down=GPIO.PUD_UP)


setmotor_status=0

def button_callback(channel):
    global setmotor_status
    setmotor(setmotor_status)
    print(setmotor_status)

    setmotor_status=(setmotor_status+150)%450
    

#GPIO 버튼 인터럽트 발생시 callback 함수를 실행한다
GPIO.add_event_detect(sw_pin[0], GPIO.FALLING, callback=button_callback, bouncetime=1000)


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
   
    while True:
            time.sleep(0.1)
                   
except KeyboardInterrupt:
    pass


GPIO.cleanup()
