# logger.py

from PyQt5 import QtWidgets

class Logger(QtWidgets.QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)

        self.box = QtWidgets.QTextEdit("Test2")

        self.setMinimumHeight(200)

        layout = QtWidgets.QGridLayout()
        layout.addWidget(self.box)
        self.setLayout(layout)

        self.show()