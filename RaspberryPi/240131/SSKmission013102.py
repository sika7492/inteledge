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


#핀모드 설정
#GPIO핀을 사용할때 BCM모드로 사용한다 
#각 GPIO포트 456번을 출력으로 변경 
GPIO.setmode(GPIO.BCM)                      
GPIO.setup(led_red_pin,GPIO.OUT)            
GPIO.setup(led_green_pin,GPIO.OUT)  
GPIO.setup(led_blue_pin,GPIO.OUT) 
all_off()   

# 패턴생성 인수만큼의 
def generatePattern(level):
    ##[random.choices([led_red_pin,led_green_pin,led_blue_pin]) for i in range(level)]
    colors = [led_red_pin, led_green_pin, led_blue_pin]
    result = [random.choice(colors) for i in range(level)]
    return result

# 패턴의 led 점등
def LED_Pattern(pattern):
    for i in pattern:
        GPIO.output(i,True)
        time.sleep(0.5)
        GPIO.output(i,False)
        time.sleep(0.5) 
#오답 함수
def LEDwrong():
    all_off() 
    time.sleep(0.5)
    for i in range(3):
        GPIO.output(led_red_pin,True)
        time.sleep(0.5)
        GPIO.output(led_red_pin,False)
        time.sleep(0.5)
#정답 함수 
def LEDcorrect():
    all_off()
    time.sleep(0.5)
    GPIO.output(led_red_pin,True)
    time.sleep(0.5)
    GPIO.output(led_green_pin,True)
    time.sleep(0.5)
    GPIO.output(led_blue_pin,True)
    time.sleep(0.5)
    all_off()


##메인 로직
    
print("안녕하세요 LED 패턴 암기 테스트입니다")
level=0
while True:
    #레벨증가
    level+=1

    #키를 입력받으면 시작함
    print("아무키나 입력하세요")
    input()
    print(level,"Level start!")
    
    #패턴생성
    pattern=generatePattern(level)
    LED_Pattern(pattern)
    print("정답을 입력해주세요. 빨강 = 4, 초록 = 5, 파랑 = 6")
    player_pattern = [0 for i in range(level)]

    #정답 입력 받기
    for i in range(level):
        while True:
            try:
                player_pattern[i]=int(input())
                break
            except:
                print("\n정수값을 입력하세요")
    
    if pattern == player_pattern:
        print("정답입니다 다음 레벨로 ")
        LEDcorrect()
    else:
        print("오답")
        print("입력한 값은 ", player_pattern ," 입니다")
        print("정답은 ", pattern ," 입니다")
        LEDwrong()
        break 


#GPIO포트 초기화
GPIO.cleanup()