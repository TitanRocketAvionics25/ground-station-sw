# window.py

from PyQt5 import QtWidgets
from PyQt5.QtCore import Qt

from graphs import Graphs
from logger import Logger
from expanded_panel import ExpandedPanel

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

        self.windowComponents()
       
        self.show()

    def windowComponents(self):
        # Window areas
        graphs = Graphs()
        logger = Logger()
        expanded_panel = ExpandedPanel()

        # Main data display panels
        main_sections = QtWidgets.QSplitter(Qt.Vertical)
        main_sections.addWidget(graphs)
        main_sections.addWidget(logger)
        # Separator style
        main_sections.setChildrenCollapsible(False)
        main_sections.setHandleWidth(15)

        # All panels
        sections = QtWidgets.QSplitter(Qt.Horizontal)
        sections.addWidget(main_sections)
        sections.addWidget(expanded_panel)
        # Separator style
        sections.setChildrenCollapsible(False)

        # Set application widget layout with components
        layout = QtWidgets.QGridLayout()
        layout.addWidget(sections)
        self.setLayout(layout)

        self.showMaximized()