# graphs.py

from PyQt5 import QtWidgets
import pyqtgraph as pg

from graphs.gyro import Gyro
from graphs.pressure import Pressure
from graphs.temperature import Temperature
from graphs.velocity import Velocity
from graphs.acceleration import Acceleration
from graphs.location import Location

class GraphPanel(pg.GraphicsLayoutWidget):
    def __init__(self, parent=None):
        super().__init__(parent)

        self.gyro = Gyro()
        self.pressure = Pressure()
        self.temperature = Temperature()
        self.velocity = Velocity()
        self.acceleration = Acceleration()
        self.location = Location()

        self.addItem(self.gyro, 0, 0, 1, 1)
        self.addItem(self.pressure, 0, 1, 1, 1)
        self.addItem(self.temperature, 0, 2, 1, 1)
        self.addItem(self.velocity, 1, 0, 1, 1)
        self.addItem(self.acceleration, 1, 1, 1, 1)
        self.addItem(self.location, 1, 2, 1, 1)