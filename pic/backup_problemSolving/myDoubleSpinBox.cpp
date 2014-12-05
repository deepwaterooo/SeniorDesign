#include "myDoubleSpinBox.h"

#include <QDoubleSpinBox>

double __SINGLESTEP__ = 0.001;
int __DECIMALS__ = 3;
double __PRECISION__ = 0.001;
    int __HSPACING__ = 1; //5
int __LABELWIDTH__ = 100;
int __2ndWIDGET_WIDTH__ = 150;
/*
myDoubleSpinBox::myDoubleSpinBox(QWidget *parent)
    : QDoubleSpinBox(parent) {
    setRange(0., 300.);
    setValue(2.025);
    setSingleStep(__SINGLESTEP__);
    setFixedWidth(__2ndWIDGET_WIDTH__ );
    setWrapping(True);
    setDecimals(__DECIMALS__);
}
*/
QString myDoubleSpinBox::textFromValue(double value) const {
    QString result = "0" + QString::number((int)(value / 60)) + ":";

    int intPart = abs(value - value / 60);
    double restPart = (value - value / 60) - abs(value - value / 60);
    if (intPart > 9)
        result += (QString::number(intPart) + ".");
    else
        result += ("0" + QString::number(intPart) + ".");

    int rest = restPart * 1000;
    if (rest < 10)
        result = result + "00" + QString::number(rest);
    else if (rest < 100)
        result = result + "0" + QString::number(rest);
    else
        result += QString::number(rest);
        
    return result;
}

