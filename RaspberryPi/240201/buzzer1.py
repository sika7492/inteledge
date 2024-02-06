import RPi.GPIO as GPIO
import time
buzzer =18
freq=[523,587,659,698,784,880,988,1047]
freq2=[1047,1175,1319,1397,1568,1760,1976,2093]
GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer,GPIO.OUT)


pwm=GPIO.PWM(buzzer,1.0)
pwm.start(30.0)
def delay():
    pwm.stop()
    time.sleep(0.1)
    pwm.start(10.0)
def do(octave,sec):
    freq=[16,33,65,131,262,523,1047,2093,4186]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()
def doshop(octave,sec):
    freq=[17,35,69,139,278,554,1109,2218,4435]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()  
def re(octave,sec):
    freq=[18,37,73,147,294,587,1175,2349,4699]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()
def reshop(octave,sec):
    freq=[20,39,78,156,311,622,1245,2489,4978]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()
def mi(octave,sec):
    freq=[21,41,82,165,330,659,1319,2637,5274]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()
def fa(octave,sec):
    freq=[22,44,87,175,349,699,1397,2794,5588]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()
def fashop(octave,sec):
    freq=[23,46,93,185,370,740,1475,2960,5920]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()
def sol(octave,sec):
    freq=[25,49,98,196,392,784,1568,3136,6272]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()
def solshop(octave,sec):
    freq=[26,52,104,208,415,831,1661,3322,6645]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()
def la(octave,sec):
    freq=[28,55,110,220,440,880,1760,3520,7040]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()
def rashop(octave,sec):
    freq=[29,58,117,233,466,932,1865,3729,7459]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()
def si(octave,sec):
    freq=[31,62,124,247,494,988,1976,3951,7902]
    pwm.ChangeFrequency(freq[octave])
    time.sleep(sec)
    delay()



try:

    do(4,10)
except KeyboardInterrupt:
    pass
finally:
    pwm.stop()
    GPIO.cleanup()