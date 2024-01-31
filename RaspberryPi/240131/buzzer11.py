import RPi.GPIO as GPIO
import time
buzzer =18
freq=[523,587,659,698,784,880,988,1047]
freq2=[1047,1175,1319,1397,1568,1760,1976,2093]
GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer,GPIO.OUT)


pwm=GPIO.PWM(buzzer,1.0)
pwm.start(10.0)
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


#1/4
a=0.4
b=0.9
input("아무키나 누르시오")
sol1(a)
mi1(a)
mi1(b)
fa1(a)
re1(a)
re1(b)
do1(a)
re1(a)
mi1(a)
fa1(a)
sol1(a)
sol1(a)
sol1(b)
sol1(a)
mi1(a)
mi1(a)
mi1(a)
fa1(a)
re1(a)
re1(b)
do1(a)
mi1(a)
sol1(a)
sol1(a)
mi1(a)
mi1(a)
mi1(b)
re1(a)
re1(a)
re1(a)
re1(a)
re1(a)
re1(a)
fa1(b)
mi1(a)
mi1(a)
mi1(a)
mi1(a)
mi1(a)
fa1(a)
sol1(b)
sol1(a)
mi1(a)
mi1(a)
fa1(a)
re1(a)
re1(b)
do1(a)
mi1(a)
sol1(a)
sol1(a)
mi1(a)
mi1(a)
mi1(b)







pwm.stop()
GPIO.cleanup()





