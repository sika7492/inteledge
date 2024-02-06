import RPi.GPIO as GPIO
import time

#각 핀들 번호 세팅
button_pin1=22
button_pin2=23
button_pin3=24
button_pin4=25
led_pin_red=4
led_pin_green=5
led_pin_blue=6

#부저 세팅
buzzer =18
freq=[523,587,659,698,784,880,988,1047]
freq2=[1047,1175,1319,1397,1568,1760,1976,2093]
GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer,GPIO.OUT)
pwm=GPIO.PWM(buzzer,1.0)
pwm.start(10.0)
pwm.stop()

#버튼 세팅
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(button_pin1,GPIO.IN)
GPIO.setup(button_pin2,GPIO.IN)
GPIO.setup(button_pin3,GPIO.IN)
GPIO.setup(button_pin4,GPIO.IN)

#led 출력으로
GPIO.setup(led_pin_red,GPIO.OUT)
GPIO.setup(led_pin_green,GPIO.OUT)
GPIO.setup(led_pin_blue,GPIO.OUT)
#led 초기화
GPIO.output(led_pin_red,False)
GPIO.output(led_pin_green,False)
GPIO.output(led_pin_blue,False)

#도레미파솔라시도 
def delay():
    pwm.stop()
    time.sleep(0.1)
    pwm.start(10.0)
def do1(sec):
    pwm.ChangeFrequency(262)
    time.sleep(sec)
    delay()
def do2(sec):
    pwm.ChangeFrequency(523)
    time.sleep(sec)
    delay()
def do3(sec):
    pwm.ChangeFrequency(1047)
    time.sleep(sec)
    delay()
def re1(sec):
    pwm.ChangeFrequency(294)
    time.sleep(sec)
    delay()
def re2(sec):
    pwm.ChangeFrequency(587)
    time.sleep(sec)
    delay()
def re3(sec):
    pwm.ChangeFrequency(1175)
    time.sleep(sec)
    delay()
def mi1(sec):
    pwm.ChangeFrequency(330)
    time.sleep(sec)
    delay()
def mi2(sec):
    pwm.ChangeFrequency(659)
    time.sleep(sec)
    delay()
def mi3(sec):
    pwm.ChangeFrequency(1319)
    time.sleep(sec)
    delay()
def fa1(sec):
    pwm.ChangeFrequency(349)
    time.sleep(sec)
    delay()
def fa2(sec):
    pwm.ChangeFrequency(699)
    time.sleep(sec)
    delay()
def fa3(sec):
    pwm.ChangeFrequency(1397)
    time.sleep(sec)
    delay()
def sol1(sec):
    pwm.ChangeFrequency(392)
    time.sleep(sec)
    delay()
def sol2(sec):
    pwm.ChangeFrequency(784)
    time.sleep(sec)
    delay()
def sol3(sec):
    pwm.ChangeFrequency(1568)
    time.sleep(sec)
    delay()
def ra1(sec):
    pwm.ChangeFrequency(440)
    time.sleep(sec)
    delay()
def ra2(sec):
    pwm.ChangeFrequency(880)
    time.sleep(sec)
    delay()
def ra3(sec):
    pwm.ChangeFrequency(1760)
    time.sleep(sec)
    delay()
def si1(sec):
    pwm.ChangeFrequency(494)
    time.sleep(sec)
    delay()
def si2(sec):
    pwm.ChangeFrequency(988)
    time.sleep(sec)
    delay()
def si3(sec):
    pwm.ChangeFrequency(1976)
    time.sleep(sec)
    delay()



#둉요1
def twinkle():
    twinkle=[1,1,5,5,6,6,5,4,4,3,3,2,2,1,
        5,5,4,4,3,3,2,5,5,4,4,3,3,2,
        1,1,5,5,6,6,5,4,4,3,3,2,2,1]
    pwm.start(10.0)
    GPIO.output(led_pin_red,True)
    try:
        for i in range(0,43):
            pwm.ChangeFrequency(freq[twinkle[i-1]])
            if i==6 or i==13 or i==20 or i==27 or i==34 or i==41:
                time.sleep(0.9)
                delay()
            else:
                time.sleep(0.4)
                delay()
        pwm.stop()
    except KeyboardInterrupt:
        GPIO.output(led_pin_red,False)
        pwm.stop()
    finally:
        GPIO.output(led_pin_red,False)
        


#동요나비
def nabi():
    
    pwm.start(10.0)
    a=0.4
    b=0.9
    GPIO.output(led_pin_green,True)
    try:
        sol1(a);mi1(a);mi1(b);fa1(a);re1(a);re1(b);do1(a);re1(a);mi1(a);fa1(a);sol1(a);sol1(a)
        sol1(b);sol1(a);mi1(a);mi1(a);mi1(a);fa1(a);re1(a);re1(b);do1(a);mi1(a)
        sol1(a);sol1(a);mi1(a);mi1(a);mi1(b);re1(a);re1(a);re1(a);re1(a);re1(a);re1(a);fa1(b)
        mi1(a);mi1(a);mi1(a);mi1(a);mi1(a);fa1(a);sol1(b);sol1(a);mi1(a)
        mi1(a);fa1(a);re1(a);re1(b);do1(a);mi1(a);sol1(a);sol1(a);mi1(a);mi1(a);mi1(b)
    except KeyboardInterrupt:
        GPIO.output(led_pin_green,False)
        pwm.stop()
    finally:
        GPIO.output(led_pin_green,False)
        pwm.stop()
        
    
 #동요 비행기   
def air():
    a=0.4
    b=0.9
    c=1.9
    pwm.start(10.0)
    GPIO.output(led_pin_blue,True)
    try:
        for i in range(2):
            mi1(a+a/2);re1(a/2);do1(a);re1(a);mi1(a);mi1(a);mi1(b);re1(a);re1(a);re1(b);mi1(a);sol1(a);sol1(b)
            mi1(a+a/2);re1(a/2);do1(a);re1(a);mi1(a);mi1(a);mi1(b);re1(a);re1(a);mi1(a);re1(a);do1(c)
    except KeyboardInterrupt:
        GPIO.output(led_pin_blue,True)
        pwm.stop()
    finally:
        GPIO.output(led_pin_blue,True)
        pwm.stop()
        
     


#메인 로직
while 1:
    if GPIO.input(button_pin1)==GPIO.LOW:
        print("Button 1 pushed")
        twinkle()
        
    if GPIO.input(button_pin2)==GPIO.LOW:
        print("Button 2 pushed")
        nabi()
        
    if GPIO.input(button_pin3)==GPIO.LOW:
        print("Button 3 pushed")
        air()
        
    if GPIO.input(button_pin4)==GPIO.LOW:
        print("Button 4 pushed")
        
GPIO.cleanup()