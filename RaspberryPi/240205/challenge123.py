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

GPIO.setup(sw_pin[0], GPIO.IN, pull_up_down=GPIO.PUD_UP)


button_status=0

def button_callback(channel):
    global button_status
    buzzer(button_status)
    print(button_status)

    button_status=(button_status+1)%8
    

#GPIO 버튼 인터럽트 발생시 callback 함수를 실행한다
GPIO.add_event_detect(sw_pin[0], GPIO.FALLING, callback=button_callback, bouncetime=1000)

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
   
    while True:
            time.sleep(0.1)
                   
except KeyboardInterrupt:
    pass


GPIO.cleanup()
