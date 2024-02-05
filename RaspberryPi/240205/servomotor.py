from flask import Flask, render_template, request   # flask 모듈과 관련함수 불러옴​

import RPi.GPIO as GPIO     # 라즈베리파이 GPIO 관련 모듈을 불러옴​

import time                 # 시간 관련 모듈을 불러옴​



GPIO.setmode(GPIO.BCM)      # GPIO 핀들의 번호를 지정하는 규칙 설정​


motor_pin=[20,21,22,23]                 # 서보핀은 라즈베리파이 GPIO 14번핀으로 ​
motor_reverse_pin=[23,22,21,20]                 # 서보핀은 라즈베리파이 GPIO 14번핀으로 ​
for i in motor_pin:
    GPIO.setup(i, GPIO.OUT)  # 서보핀을 출력으로 설정 ​



current_deg = 90 #현재각도

def setmotor(degree):
    global current_deg
    

    #각도가 증가 했을경우 정회전
    if current_deg<degree:

        #약 600회에 1바퀴로 계산 각 횟수를 정수로 처리
        degree_temp=int(((degree-current_deg)*600)/360)
        
        for i in range(degree_temp):
    
        #각핀을 순서대로 on off 한다.
            for j in motor_pin:                    
                GPIO.output(j,GPIO.HIGH)
                time.sleep(0.002)
                GPIO.output(j,GPIO.LOW)
        current_deg=degree

    #각도가 감소했을 경우 역회전
    elif current_deg>degree:
        degree_temp=int(((current_deg-degree)*600)/360)
        
        for i in range(degree_temp):
    
        #각핀을 순서대로 on off 한다.
            for j in motor_reverse_pin:                    
                GPIO.output(j,GPIO.HIGH)
                time.sleep(0.002)
                GPIO.output(j,GPIO.LOW)
         
        current_deg=degree




print(current_deg)          ##현재상태 체크용
    

#setmotor(current_deg)

app = Flask(__name__)               # Flask라는 이름의 객체 생성

@app.route('/')                     # 기본 주소​

def home():                         # 여기서 servoMotor.html을 화면에 보여주며, 서보모터 각도를 전달​

    return render_template('servomotor.html', deg=current_deg)



@app.route('/servo_control')        # 서보모터를 제어하기 위한 주소​

def servo_control():                # 서보모터를 제어하기 위한 뷰함수​
    
    deg = request.args.get('deg')   # html파일에서 각도를 입력받음​

    deg = int(deg)                  # 각도를 정수형으로 바꿔주고 적절한 범위로바꿔줌​

    if deg < 0: deg = 0

    elif deg > 180: deg = 180

    setmotor(deg)     # 서보모터 각도를 바꿔줌​

    # index#20.html로 돌아가는데, 이때, deg 값을 넘겨줌(이 넘겨준 값은 html에서 사용할 수 있음)​

    return render_template('servomotor.html', deg=deg)


if __name__ == "__main__":  # 웹사이트를 호스팅하여 접속자에게 보여주기 위한 부분​

   app.run(host="192.168.0.40", port = "8080")

   # host는 현재 라즈베리파이의 내부 IP, port는 임의로 설정​

   # 해당 내부 IP와 port를 포트포워딩 해두면 외부에서도 접속가능