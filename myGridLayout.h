#ifndef myGridLayout_H
#define myGridLayout_H

#include <QWidget>
#include <QPushButton>
#include <cstring>
#include <QColor>
#include <QGridLayout>
#include <QObject>

#include "myPushButton.h"
#include "loc.h"

using namespace std;

class MyGridLayout : public QGridLayout {
    Q_OBJECT
 public:
    MyGridLayout(QWidget *parent = 0);
    //MyGridLayout(int row, int col);
    //virtual MyGridLayout* operator=(MyGridLayout*);
    //virtual MyGridLayout* operator[](int);
    //virtual MyGridLayout* operator[](int, int);

    int mRow = 10;
    int mCol = 4;
    //void setButtonSize(int i, int j);
    void setSpacing(int x);
    int getSpacing() {return mSpacing;}
    void setColor(int &i, int &j, QColor color);
    QColor getColor(int i, int j);
    QGridLayout* getPtrQGridLayout();
    QGridLayout* ptrGrid;
    
    ~MyGridLayout();
    //void printH(QColor color);
    //void printM(QColor color);
    //void printE(QColor color);
    //void printP(QColor color);
    //void printR(QColor color);
    MyPushButton* ptrBtn[10][4];
 public:
 signals:
    void released(int&, int&, QColor);
    public slots:
        void getClicked(int&, int&, QColor);
 private:
        //int mRow;
        //int mCol;
        int mSpacing = 5;
        int mx = 40;
        int my = 40;
};

#endif // MYGRIDLAYOUT_H
