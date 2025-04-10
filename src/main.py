# main.py
import sys

from PyQt5.QtWidgets import QApplication
from window import Window

def run():
    """Sets up the application."""
    
    app = QApplication([])

    window = Window()

    # Run Qt event loop
    sys.exit(app.exec())

if __name__ == "__main__":
    run()