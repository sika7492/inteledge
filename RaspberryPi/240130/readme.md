### 라즈베리파이 wiringpi 라이브러리 설치 및 예제

1. SD 카드에 이미지 설치
2. 부팅
3. 3. wiringpi 라이브러리 설치
   1. cd ~ 
   2. git clone https://github.com/WiringPi/WiringPi
   3. cd WiringPi
   4. ./build
   5. gpio -v
   6. gpio readall
홈디렉토리에서 : cd ~/Documents -> mkdir 0130 -> cd 0130 -> nano led_rgb.c
4. c 소스 파일 작성
5. 컴파일 : gcc -o led_rgb led_rgb.c -l wiringPi
6. 실행 : ./led_rgb

mv ~/WiringPi/led*.*  ~/Documents/0130
cd ~/0130

7. 파이썬 프로그램 작성
   (첫번째 라인에 import RPi.GPIO as GPIO 추가)
8. 실행 : sudo python ./ledRed.py


Mission 01: 
파일 이름 : HGDmission013001.py
Red, Green, Blue Led 20번 깜박이는 프로그램을 작성하시오.


윈도우에서 라즈베리파이 파일 공유하기
sudo apt install samba samba-common-bin
samba -V
sudo smbpasswd -a busan     #새로운 아이디, 패스워드
	city2024
	city2024

sudo nano /etc/samba/smb.conf	#설정 파일 변경

화면을 아래로 스크롤 시키면 [profiles]라고 하는 부분을 아래와 같이 변경

[pi]
    commnet = superuser
    path = /home/
    valid users = busan
    guest ok = no
    browseable = yes
    writable = yes
    create mask = 0777
    directory mask = 0777
    
sudo service smbd restart

윈도우 탐색기에서 주소 창에 \\라즈베리파이내부IP
