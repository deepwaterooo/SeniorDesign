from PyQt4 import QtGui
import sys
sys.path.append("~/480/qt/SeniorDesign/");
from QxDoubleSpinBox import QxDoubleSpinBox

class Window(QtGui.QWidget):
    def __init__(self):
        super(Window, self).__init__()
        self.createDoubleSpinBoxes()
        layout = QtGui.QHBoxLayout()
        layout.addWidget(self.doubleSpinBoxesGroup)
        self.setLayout(layout)
        self.setWindowTitle("Spin Boxes")

    def createDoubleSpinBoxes(self):
        self.doubleSpinBoxesGroup = QtGui.QGroupBox("Double precision spinboxes")
        self.doubleSpinBox = QxDoubleSpinBox(self, 2.025)
        spinBoxLayout = QtGui.QVBoxLayout()
        spinBoxLayout.addWidget(self.doubleSpinBox)
        self.doubleSpinBoxesGroup.setLayout(spinBoxLayout)

if __name__ == '__main__':
    import sys
    app = QtGui.QApplication(sys.argv) 
    window = Window()
    window.show() 
    sys.exit(app.exec_())
