import RPi.GPIO as GPIO
import time



#부저 세팅
buzzer =18


freq=[523,587,659,698,784,880,988,1047]

GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer,GPIO.OUT)
pwm=GPIO.PWM(buzzer,1.0)
pwm.start(10.0)
pwm.stop()

#음을 구분하게 해주는 함수
def delay():
    pwm.stop()
    time.sleep(0.1)
    pwm.start(10.0)


#둉요1
def main():
    twinkle=[1,1,5,5,6,6,5,4,4,3,3,2,2,1,
        5,5,4,4,3,3,2,5,5,4,4,3,3,2,
        1,1,5,5,6,6,5,4,4,3,3,2,2,1]
    pwm.start(10.0)

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
        
        pwm.stop()
    finally:
        pwm.stop() 



if __name__ == "__main__":
    main()

GPIO.cleanup()
