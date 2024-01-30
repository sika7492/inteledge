import RPi.GPIO as GPIO
import time

def main_menu():                                ##메인메뉴를 표시하는 함수
    print("1. LED 켜기 :\n2. LED 끄기\n3. LED 3초간 점점 밝기\n4. LED 3초간 점점 어둡기")
    print("5. LED 3초간 점점 밝다가 3초간 점점 어둡기\n6. 원하는값 입력\n   입력한 초동안 점점 밝아지다가 어두워지기 ")
    print("7. 색상변경(1.red 2.green 3. blue)\n9. 메뉴 다시보기 \n0. 종료")  

def LED_brighter(sec):
    t_high=0
    cnt=0
    while True:
        GPIO.output(led_pin,True)
        time.sleep(t_high)
        GPIO.output(led_pin,False)
        time.sleep(0.01-t_high)
        t_high+=(0.01/(sec*100))
        if t_high>0.01:                         ##만약 time.sleep 함수의 인자가 음수라면 에러가 발생함으로 0.01보다 커질시 0.01로 변환
            t_high=0.01
        cnt+=1
        if cnt==(sec*100):
            break


def LED_dimmer(sec):                           ## led가 점점 밝아지는 함수
    t_high=0
    cnt=0
    while True:
            
        GPIO.output(led_pin,True)
        time.sleep(0.012-t_high)
        GPIO.output(led_pin,False)
        time.sleep(t_high)
        t_high+=(0.01/(sec*100))
        if t_high>0.01:                       ##만약 time.sleep 함수의 인자가 음수라면 에러가 발생함으로 0.01보다 커질시 0.01로 변환
            t_high=0.01
        cnt+=1
        if cnt==sec*100:
            break
       


led_pin =4                                  

GPIO.setmode(GPIO.BCM)                      ##GPIO핀을 사용할때 BCM모드로 사용한다  

GPIO.setup(led_pin,GPIO.OUT)                ##GPIO 4번 핀을 출력으로 설정합니다
main_menu()   

while True:

    try:
        menu=int(input("메뉴를 입력하세요"))
    except:
        print("\n정수값을 입력하세요")
        continue
    if menu==1:
        print("LED 켜기")
        GPIO.output(led_pin,True)
        #break
    elif menu ==2:
        print("LED 끄기")
        GPIO.output(led_pin,False)
        #break
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
        LED_brighter(select_time/2)
        LED_dimmer(select_time/2)
    elif menu==7:
        try:
            color=int(input("색상변경(1.red 2.green 3. blue):"))
        except:
            print("\n정수값을 입력하세요")
        continue
        if color==1:
            print("red")
            
            led_pin=4
            GPIO.setup(led_pin,GPIO.OUT)
            GPIO.output(led_pin,False)
        elif color==2:
            print("green")
            
            led_pin=5
            GPIO.setup(led_pin,GPIO.OUT)
            GPIO.output(led_pin,False) 
        elif color==3:
            print("blue")
            
            led_pin=6
            GPIO.setup(led_pin,GPIO.OUT)
            GPIO.output(led_pin,False) 
    elif menu==9:
        main_menu()     
    elif menu==0:
        print("종료합니다")
        break
   
        
        
        
GPIO.cleanup()
    

                    

     



        


    

                    

     



        



