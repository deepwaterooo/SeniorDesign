from PyQt4 import QtCore, QtGui

__SINGLESTEP__ = 0.001
__DECIMALS__ = 3
__PRECISION__ = 0.001
__HSPACING__ = 1 #5
__LABELWIDTH__ = 100
__2ndWIDGET_WIDTH__ = 150

class QxDoubleSpinBox(QtGui.QDoubleSpinBox):
    def __init__(self, parent=None, value=0.):
        QtGui.QDoubleSpinBox.__init__(self, parent)
        self.setRange(0., 300.)
        self.setValue(2.025)
        self.setSingleStep(__SINGLESTEP__)
        self.setFixedWidth(__2ndWIDGET_WIDTH__ )
        self.setWrapping(True)
        self.setDecimals(__DECIMALS__)
    
    def valueFromText(self, str):
        return FixedPoint(str, 9)

    def textFromValue(self, value):
        print "textFromValue = ", value
        #return str(value)

        #self modification
        result = "0" + str((int)(value//60)) + ":"
        #print "result 0: " + result
        
        i, d = divmod(value, 1)
        #print "i: " + str(i)
        #print "d: " + str(d)
        
        if (i > 9.0):
            result += str(i * 10 // 10) + "."
            #print "result 01: " + result
        else:
            #print str(abs(value))
            #print str(abs(value) %60)
            #print str(i * 10 // 10)
            result += ("0" + str(i * 10 // 10))                       
            result = result[:-1]
            #print "result 02: " + result
        #print "result 1: " + result
            
        val = d * 1000
        #print val
        if val < 10:
                result = result + "00" + str(val)
        elif val < 100:
                result = result + "0" + str(val)
        else:
                result += str(val)
        #print "result 2: " + result
        result = result[:-2]
        return result
        
