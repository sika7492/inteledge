import RPi.GPIO as GPIO
import time
import random



##led 초기화 
def all_off():                              
    GPIO.output(led_red_pin,False)
    GPIO.output(led_green_pin,False)
    GPIO.output(led_blue_pin,False)
    
# GPIO 핀 번호 설정
led_red_pin =4 
led_green_pin=5
led_blue_pin=6 
button_pin1 = 22
button_pin2 = 23
button_pin3 = 24
button_pin4 = 25



#핀모드 설정
#GPIO핀을 사용할때 BCM모드로 사용한다 
#각 GPIO포트 456번을 출력으로 변경 
GPIO.setmode(GPIO.BCM)                      
GPIO.setup(led_red_pin,GPIO.OUT)            
GPIO.setup(led_green_pin,GPIO.OUT)  
GPIO.setup(led_blue_pin,GPIO.OUT) 
all_off()   

#버튼 세팅
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(button_pin1,GPIO.IN)
GPIO.setup(button_pin2,GPIO.IN)
GPIO.setup(button_pin3,GPIO.IN)
GPIO.setup(button_pin4,GPIO.IN)

# 패턴생성 인수만큼의 
def generatePattern(level):
    ##[random.choices([led_red_pin,led_green_pin,led_blue_pin]) for i in range(level)]
    colors = [led_red_pin, led_green_pin, led_blue_pin]
    result = [random.choice(colors) for i in range(level)]
    return result




##메인 로직
    
print("===순발력 게임===")


#키를 입력받으면 시작함
input("아무키나 입력하세요")
   
    
#패턴생성
pattern=generatePattern(10)
print("정답을 입력해주세요. 빨강 = 4, 초록 = 5, 파랑 = 6")
    

colors = [led_red_pin, led_green_pin, led_blue_pin]
total=0
for i in range(10):
    judgment = 0 # 판정1 : 버튼을 올바르게 눌렀는지 
    judgment2 = 0 # 판정2 : 시간내에 버튼을 눌었는지 아닌지
    
    color = random.choice(colors)
    
        
    #0.5초에서 1초사이의 시간만큼 불이켜짐
    sleep_time=random.uniform(0.5, 1)
    GPIO.output(color,True)
    start_time = time.time()
    while True:                # 랜덤 시간 만큼 반복
        ret = GPIO.input(button_pin2)  # 빨강 - SW2
        if ret == 0:
            judgment2 = 1
            if color != led_red_pin:
                judgment = 1
        
        ret = GPIO.input(button_pin3)  # 초록 - SW3
        if ret == 0:
            judgment2 = 1
            if color != led_green_pin:
                judgment = 1
        
        ret = GPIO.input(button_pin4)  # 파랑 - SW4
        if ret == 0:
            judgment2 = 1
            if color != led_blue_pin:
                judgment = 1

        current_time = time.time()
        if current_time - start_time >= sleep_time: # 지정한 시간이 지나면 종료 
            break
    
    if judgment == 1:     # 틀린 버튼을 누르는 경우
        print("bad")
    elif judgment2 == 0:  # 버튼을 시간내에 누르지 못한 경우
        print("miss")
    else:                 # 시간내에 올바른 버튼을 누른 경우 
        total += 1
        print("perfect")  

    GPIO.output(color, GPIO.LOW)

                 
    

#GPIO포트 초기화
GPIO.cleanup()