import RPi.GPIO as GPIO
import time
import random



def title():
    print("--------------------------------------------------------------------")
    print("                            빛의 삼원색 게임                         ")
    print("        -색을 확인하고 합쳐지면 어떤 색이 되는지 맞춰보자-              ")
    print("--------------------------------------------------------------------")


##led 초기화 
def all_off():                              
    GPIO.output(led_red_pin,False)
    GPIO.output(led_green_pin,False)
    GPIO.output(led_blue_pin,False)


# GPIO 핀 번호 설정
led_red_pin =4 
led_green_pin=5
led_blue_pin=6                                 


#핀모드 설정
GPIO.setmode(GPIO.BCM)                      ##GPIO핀을 사용할때 BCM모드로 사용한다  
GPIO.setup(led_red_pin,GPIO.OUT)            ##각 GPIO포트 456번을 출력으로 변경
GPIO.setup(led_green_pin,GPIO.OUT)  
GPIO.setup(led_blue_pin,GPIO.OUT) 
all_off()                                           
                                            ##GPIO.output(led_red_pin,False)
                                            ##GPIO.output(led_green_pin,False)
                                            ##GPIO.output(led_blue_pin,False)   

#타이틀 출력
title()

#색상의 배열 생성
colors={led_red_pin,led_green_pin,led_blue_pin} 

#색상을 랜덤으로 두개를 추출 
select_color=random.sample(colors,2)


#정답 초기화
answer=0

#선택된 색상을 출력하고 각각의 경우에 따른 정답을 설정
if select_color[0]==led_red_pin:
    GPIO.output(led_red_pin,True)
    if select_color[1]==led_green_pin:
        answer=1
        GPIO.output(led_green_pin,True)
    elif select_color[1]==led_blue_pin:
        answer=2
        GPIO.output(led_blue_pin,True)

if select_color[0]==led_green_pin:
    GPIO.output(led_green_pin,True)
    if select_color[1]==led_red_pin:
        answer=1
        GPIO.output(led_red_pin,True)
    elif select_color[1]==led_blue_pin:
        answer=3
        GPIO.output(led_blue_pin,True)

if select_color[0]==led_blue_pin:
    GPIO.output(led_blue_pin,True)
    if select_color[1]==led_red_pin:
        answer=2
        GPIO.output(led_red_pin,True)
    elif select_color[1]==led_green_pin:
        answer=3
        GPIO.output(led_green_pin,True)

#선택창 출력
print("--------------------------------------------------------------------")
print("1. yellow\n2.magenta\n3.cyan\n4.whhie")
print("--------------------------------------------------------------------\n")

#정답을 입력받음 
while True:
    try:
        number=int(input("숫자를 입력하세요: "))
        break
    except:
        print("\n정수값을 입력하세요")

#정답을 맞았을경우 led를 초기화를 하고 빨초파순으로 점등이후 led 끄기
if number==answer:
    print("정답입니다.")
    all_off()
    time.sleep(0.5)
    GPIO.output(led_red_pin,True)
    time.sleep(0.5)
    GPIO.output(led_green_pin,True)
    time.sleep(0.5)
    GPIO.output(led_blue_pin,True)
    time.sleep(0.5)
    all_off() 
    
#정답이 아니였을경우 led를 초기화를 하고 빨간색 led 3번 깜빡임
else:
    print("틀렸습니다.")
    all_off() 
    time.sleep(0.5)
    for i in range(3):
        GPIO.output(led_red_pin,True)
        time.sleep(0.5)
        GPIO.output(led_red_pin,False)
        time.sleep(0.5)

#GPIO포트 초기화
GPIO.cleanup()


