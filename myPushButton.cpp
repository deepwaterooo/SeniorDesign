#include <QObject>
#include <QPushButton>
#include <QString>

#include "myPushButton.h"
/*
Loc MyPushButton::setLocation(Loc x) {
    locx = x.x;
    locy = x.y;
}
*/
void MyPushButton::setLocation(int x, int y) {
    locx = x;
    locy = y;
}

Loc MyPushButton::getLocation() {
    Loc result(locx, locy);
    return result;
}
/*
MyPushButton& MyPushButton::operator=(MyPushButton &rhs) {
    if (rhs != (*this)) {
        locx = rhs.locx;
        locy = rhs.locy;
    }
    return *this;
}
*/
MyPushButton* MyPushButton::operator=(MyPushButton* rhs) {
    if (this != rhs) {
        MyPushButton* result;
        result->locx = rhs->locx;
        result->locy = rhs->locy;
        return result;
    }
    return NULL;
}
/*
MyPushButton* MyPushButton::operator[](int idx) {

}
*/
void MyPushButton::getMClicked(int &x, int &y, QColor color) {
    setMColor(x, y, color);
    emit released(x, y, color);
}
/*
void MyPushButton::setFixedSize(int x, int y) {
    (QWidget*)this->setFixedSize(x, y);
}
*/

void MyPushButton::setMColor(int &x, int &y, QColor color) {
    if (locx == x && locy == y) {
        setColor(color);
    }

}

void MyPushButton::setColor(QColor color) {
    int r,g,b;
    color.getRgb(&r, &g, &b);
    QString temp = "QPushButton{color:red;background-color:rgb(";
    QString tempr = QString::number(r);
    QString tempg = QString::number(g);
    QString tempb = QString::number(b);
    temp = temp + tempr + "," + tempg + "," + tempb + ")}";
    setStyleSheet(temp); 
}
