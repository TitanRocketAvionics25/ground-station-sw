# graphs.py

from PyQt5 import QtWidgets

class Graphs(QtWidgets.QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)

        self.box = QtWidgets.QTextEdit("Test")

        layout = QtWidgets.QGridLayout()
        layout.addWidget(self.box)
        self.setLayout(layout)

        self.show()