import sys

from PyQt6.QtWidgets import QApplication,QPushButton

app=QApplication(sys.argv)


window=QPushButton("Push me")

window.show()

app.exec()