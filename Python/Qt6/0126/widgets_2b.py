import os
import sys



from PyQt6.QtGui import QPixmap
from PyQt6.QtWidgets import (   
     QApplication,
     QMainWindow,
     QLabel
)                                                          ## 공통 Qt위젯은 항상 QtWidgets 네임스페이스에서 가져온다.


basedir=os.path.dirname(__file__)
print("Current working folder:",os.getcwd())
print("Paths are relative to :,basedir")

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()                                  ##항상  super() 클래스의 __init__ 메서드를 호출해야한다

        self.setWindowTitle("My App: 송시경")               ##윈도우 창의 이름을 설정한다

        widget =QLabel("Hello")
        widget.setPixmap(QPixmap(os.path.join(basedir,"lenna.bmp")))
        widget.setScaledContents(True)
        
        #윈도우 중앙 위젯 설정
        self.setCentralWidget(widget)   

    def the_button_was_clicked(self):                        ##버튼이 입력하면 실행되는 코드           
        print("Clicked!")


app=QApplication(sys.argv)                                   ##애플리케이션에 전달된 커맨드라인 인수가 포함된 파이썬리스트인 sys.arg를 전달하는 QApplication을 생성한다
                                                             ##c에서 숨겨진 메인문 같은 느낌  

window=MainWindow()                                          ##window를 MainWindow() 지정

window.show()                                                ##window를 화면에 출력한다

app.exec()                                                   ##do_while문 같은 개념인듯
