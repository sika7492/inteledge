import RPi.GPIO as GPIO
import time

led_pin = 18 # 1 for WiringPi​


GPIO.setmode(GPIO.BCM)

GPIO.setup(led_pin, GPIO.OUT)

pwm = GPIO.PWM(led_pin, 100) # channel=led_pin frequency=100Hz​

pwm.start(0)


def main_menu():                                ##메인메뉴를 표시하는 함수
    print("1. LED 켜기 :\n2. LED 끄기\n3. LED 3초간 점점 밝기\n4. LED 3초간 점점 어둡기")
    print("5. LED 3초간 점점 밝다가 3초간 점점 어둡기\n6. 원하는값 입력\n   입력한 초동안 점점 밝아지다가 어두워지기 ")
    print("7. 색상변경(1.red 2.green 3. blue)\n9. 메뉴 다시보기 \n0. 종료")  

def LED_brighter(sec):
    cnt=0
    for i in range(0, 100, 1):
        while True:
            if cnt==sec:
                break
            pwm.ChangeDutyCycle(i)
            time.sleep(0.01)
            cnt+=1
        
    pwm.ChangeDutyCycle(100)


def LED_dimmer(sec):                           ## led가 점점 밝아지는 함수
    cnt=0
    for i in range(100, 0, -1):
        while True:
            if cnt==sec:
                break
        pwm.ChangeDutyCycle(i)
        time.sleep(0.01)
    pwm.ChangeDutyCycle(0)

                               
 


main_menu()   

while True:

    try:
        menu=int(input("메뉴를 입력하세요"))
    except:
        print("\n정수값을 입력하세요")
        continue
    if menu==1:
        print("LED 켜기")
        pwm.ChangeDutyCycle(100)
        #break
    elif menu ==2:
        print("LED 끄기")
        pwm.ChangeDutyCycle(0)
        
    elif menu ==3:
        print("LED 3초간 점점 밝기")
        LED_brighter(3)
    elif menu==4:
        print("LED 3초간 점점 어둡기")
        LED_dimmer(3)
    elif menu==5:
        print("LED 3초간 점점 밝다가 3초간 점점 어둡기")
        LED_brighter(3)
        LED_dimmer(3)    
               
    elif menu==6:
        print("원하는값 입력\n   입력한 초동안 점점 밝아지다가 어두워지기")
        
        select_time=float(input("원하는 시간(초)을 입력하세요"))
        LED_brighter(select_time)
        LED_dimmer(select_time)
    elif menu==9:
        main_menu()     
    elif menu==0:
        print("종료합니다")
        break
   
        
        
pwm.stop()        
GPIO.cleanup()
    

                    

     



        



