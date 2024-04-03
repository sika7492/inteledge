from PyQt6.QtWidgets import (   
     QApplication,
     QMainWindow,
     QPushButton
)                                                          ## 공통 Qt위젯은 항상 QtWidgets 네임스페이스에서 가져온다.


import sys

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()                                  ##항상  super() 클래스의 __init__ 메서드를 호출해야한다

        self.setWindowTitle("My App: 송시경")               ##윈도우 창의 이름을 설정한다

        button = QPushButton("Press Me!")                   ##button에 표시되는 글자를  QPushButton 설정한다.
        button.setCheckable(True)                           ##
        button.clicked.connect(self.the_button_was_clicked) ##입력이 들어올시 시작하는 코드를 불러온다
        
        #윈도우 중앙 위젯 설정
        self.setCentralWidget(button)   

    def the_button_was_clicked(self):                        ##버튼이 입력하면 실행되는 코드           
        print("Clicked!")


app=QApplication(sys.argv)                                   ##애플리케이션에 전달된 커맨드라인 인수가 포함된 파이썬리스트인 sys.arg를 전달하는 QApplication을 생성한다


window=MainWindow()                                          ##window를 MainWindow() 지정

window.show()                                                ##window를 화면에 출력한다

app.exec()                                                   ##생성된 이벤트를 루프한다
