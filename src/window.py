# window.py

from PyQt5 import QtWidgets

class Window(QtWidgets.QWidget):
    """Creates the main window of the application."""

    def __init__(self, parent=None):
        super().__init__(parent)

        # Window size
        self.width = 1800
        self.height = 1000
        self.resize(self.width, self.height)

        # Window title
        self.title = "Titan Rocket 2025 Ground Station"
        self.setWindowTitle(self.title)

        # Set application widget layout
        layout = QtWidgets.QGridLayout()
        self.setLayout(layout)

        self.show()