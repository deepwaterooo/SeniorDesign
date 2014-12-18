#include <QPushButton>
#include <QGridLayout>
#include <cstring>
#include <QPalette>
#include <QColor>
#include <QObject>

#include "myGridLayout.h"
using namespace std;

//MyGridLayout::MyGridLayout(int row, int col) {
MyGridLayout::MyGridLayout(QWidget *parent)
    : QGridLayout(parent) {
    //int mRow = 10;
    //int mCol = 4;
    for (int i = 0; i < mRow; ++i) {
        for (int j = 0; j < mCol; ++j) {
            ptrBtn[i][j] = new MyPushButton();
            ptrBtn[i][j]->setLocation(i, j);
            ptrBtn[i][j]->setFixedSize(22, 22);
            //ptrBtn[i][j]->setMColor(i, j, QColor::fromRgb(255,255,255));  // privatee
            //ptrBtn[i][j]->getMClicked(i, j, QColor::fromRgb(255,255,255)); 
            addWidget((QWidget*)ptrBtn[i][j], i, j);
        }
    }
    
    /*
    //mRow = row;
    //mCol = col;
    ptrBtn = new MyPushButton [mRow];
    for (int i = 0; i < mRow; ++i) {
        ptrBtn[i] = new MyPushButton [mCol];
    }
    for (int i = 0; i < mRow; ++i) {
        for (int j = 0; j < mRow; ++j) {
            ptrBtn[i][j] = new MyPushButton();
            setButtonSize(22, 32);
        }
    }
    */
}

MyGridLayout::~MyGridLayout() {
    /* how to handle this  ???????????
    for (int i = 0; i < mRow; ++i)         
        delete [] ptrBtn[i];
    delete [] ptrBtn;
    */
}

void MyGridLayout::setColor(int &i, int &j, QColor color) {
    QPalette pal;
    pal = ptrBtn[i][j]->palette();
    pal.setColor(QPalette::Button, color);
    ptrBtn[i][j]->setPalette(pal);
    ptrBtn[i][j]->setAutoFillBackground(true);
}

void MyGridLayout::getClicked(int &x, int &y, QColor color) {
    for (int i = 0; i < mRow; ++i) {    
        for (int j = 0; j < mRow; ++j) {
            if (ptrBtn[i][j]->getLocation().getX() == x && ptrBtn[i][j]->getLocation().getY() == y)
                ptrBtn[i][j]->getMClicked(x, y, color);
        }
    }
}

/*
void MyGridLayout::setButtonSize(int i, int j){
    //mx = i;
    //my = j;
    for (int i = 0; i < mRow; ++i) 
        for (int j = 0; j < mCol; ++j) 
            ptrBtn[i][j]->setFixedSize(i, j);
            }  */
/*
void MyGridLayout::setSpacing(int x) {
    mSpacing = x;
    ptrGrid->setSpacing(x);
}

QGridLayout* MyGridLayout::getPtrQGridLayout() {
    return ptrGrid;
}

void MyGridLayout::printH(QColor color){ // LightSkyBlue 135,206,250
    for (int i = 0; i < 7; ++i) {
        setColor(i, 0, color);
        setColor(i, 3, color);
    }
    setColor(3, 1, color);
    setColor(3, 2, color);
}
void MyGridLayout::printM(QColor color){ // 255,215,0
    for (int i = 0; i < 7; ++i) {
        setColor(i, 0, color);
        setColor(i, 3, color);
    }
    for (int i = 1; i < 3; ++i) {        
        setColor(0, i, color);
        setColor(3, i, color);
        setColor(6, i, color);
    }
}

void MyGridLayout::printE(QColor color){
    for (int i = 0; i < 7; ++i) 
        setColor(i, 0, color);
    for (int i = 0; i < 4; ++i) {        
        setColor(0, i, color);
        setColor(6, i, color);
    }
    setColor(3, 1, color);
    setColor(3, 2, color);
}

void MyGridLayout::printR(QColor color){
    for (int i = 0; i < 7; ++i) 
        setColor(i, 0, color);
    for (int i = 0; i < 4; ++i)
        setColor(i, 3, color);
    for (int i = 1; i < 3; ++i) {        
        setColor(0, i, color);
        setColor(3, i, color);
    }
    setColor(4, 1, color);
    setColor(5, 2, color);
    setColor(6, 3, color);
}

void MyGridLayout::printP(QColor color){
    for (int i = 0; i < 7; ++i)
        setColor(i, 0, color);
    for (int i = 0; i < 4; ++i)
        setColor(i, 3, color);
    for (int i = 1; i < 3; ++i) {        
        setColor(0, i, color);
        setColor(3, i, color);
    }
}

MyGridLayout::MyGridLayout(int row, int col, QWidget *parent)
    : QWidget(parent) {
    mRow = row;
    mCol = col;

    ptrBtn = new QPushButton** [mRow];
    for (int j = 0; j < mRow; ++j) 
        ptrBtn[j] = new QPushButton*[mCol];
    
    ptrGrid = new QGridLayout();
    ptrGrid->setSpacing(5);

    for (int i = 0; i < mRow; i++) {
        for (int j = 0; j< mCol; j++) {
            ptrBtn[i][j] = new QPushButton();
            ptrBtn[i][j]->setFixedSize(40, 40);
            ptrGrid->addWidget(ptrBtn[i][j], i, j);
        }
    }
    setLayout(ptrGrid);
}

QColor MyGridLayout::getColor(int i, int j) {
    QColor color = ptrBtn[i][j]->palette().color(QPalette::Button);
    return color;
}
*/
/*
// all kinds of errors on this one, but temporatorially leave it here
MyGridLayout& MyGridLayout::operator=(const MyGridLayout& src) {
    if (this != src) {
        MyGridLayout a(mRow, mCol);
        a.setSpacing(src.mSpacing);
        for (int i = 0; i < src.mRow; ++i ) {
            for (int j = 0; j < src.mCol; ++j ) {
                setColor(i, j, src.getColor(i, j));
            }
        }
        a.setButtonSize(src.getmx(), src.getmy());
    }
    return a;
}

MyGridLayout* MyGridLayout::operator[](int indx) {
    if (this != src) {
        MyGridLayout a(mRow, mCol);
        a.setSpacing(src.mSpacing);
        for (int i = 0; i < src.mRow; ++i ) {
            for (int j = 0; j < src.mCol; ++j ) {
                setColor(i, j, src.getColor(i, j));
            }
        }
        a.setButtonSize(src.getmx(), src.getmy());
    }
    return a;
}
*/
/*
MyGridLayout* MyGridLayout::operator[][](MyPushButton, int) {
    if (this != src) {
        MyGridLayout a(mRow, mCol);
        a.setSpacing(src.mSpacing);
        for (int i = 0; i < src.mRow; ++i ) {
            for (int j = 0; j < src.mCol; ++j ) {
                setColor(i, j, src.getColor(i, j));
            }
        }
        a.setButtonSize(src.getmx(), src.getmy());
    }
    return a;
}
*/
