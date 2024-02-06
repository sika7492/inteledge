import RPi.GPIO as GPIO
import time

# GPIO 핀 번호 설정
led_red_pin =4 
led_green_pin=5
led_blue_pin=6    



led_pin = [led_red_pin,led_green_pin,led_blue_pin]

#led를 모드 끄는 함수
def all_off():                              
    GPIO.output(led_red_pin,False)
    GPIO.output(led_green_pin,False)
    GPIO.output(led_blue_pin,False)

#핀모드 설정
#GPIO핀을 사용할때 BCM모드로 사용한다 
#각 GPIO포트 456번을 출력으로 변경 
GPIO.setmode(GPIO.BCM)                      
GPIO.setup(led_red_pin,GPIO.OUT)            
GPIO.setup(led_green_pin,GPIO.OUT)  
GPIO.setup(led_blue_pin,GPIO.OUT) 



all_off()  


def led_onoff(color,sec):
    
    GPIO.output(led_pin[color],GPIO.HIGH)
    time.sleep(sec)
    GPIO.output(led_pin[color],GPIO.LOW)
    time.sleep(sec)

try:
    for i in range(10):
        
        for j in range(3):
            led_onoff(j,0.1)
        
except KeyboardInterrupt:
    pass

GPIO.cleanup()
    
