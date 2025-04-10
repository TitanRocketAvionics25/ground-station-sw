# location.py

import pyqtgraph as pg

class Location(pg.PlotItem):
    def __init__(self, parent=None):
        super().__init__(parent)

        x = [1, 3, 5, 7]
        y = [9, 8, 7, 6]

        self.plot(x, y)