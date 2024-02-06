from flask import Flask, render_template, request   # flask 모듈과 관련함수 불러옴​

import RPi.GPIO as GPIO     # 라즈베리파이 GPIO 관련 모듈을 불러옴​

import time                 # 시간 관련 모듈을 불러옴​



GPIO.setmode(GPIO.BCM)      # GPIO 핀들의 번호를 지정하는 규칙 설정​

#버튼 핀번호 세팅
sw_pin=[22,23,24]

#스탭 모터 핀번호를 설정
motor_pin=[16,17,18,19]                 

#스탭 모터 출력으로 세팅
for i in motor_pin:
    GPIO.setup(i, GPIO.OUT)  

for i in sw_pin:
     GPIO.setup(i, GPIO.IN)  




def setmotor(degree):
    
        for i in range(degree):
    
        #각핀을 순서대로 on off 한다.
            for j in motor_pin:                    
                GPIO.output(j,GPIO.HIGH)
                time.sleep(0.002)
                GPIO.output(j,GPIO.LOW)
try:
    while 1:
        if GPIO.input(sw_pin[0])==GPIO.LOW:
            setmotor(65)
            
        time.sleep(0.1)
        if GPIO.input(sw_pin[1])==GPIO.LOW:
            setmotor(130)
            
        time.sleep(0.1)
        if GPIO.input(sw_pin[2])==GPIO.LOW:
            setmotor(260)
            
        time.sleep(0.1)
except KeyboardInterrupt:
     pass

GPIO.cleanup()
       

