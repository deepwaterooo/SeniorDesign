#include <QObject>
#include <QPushButton>
#include <QObject>

#include "loc.h"

class MyPushButton : public QPushButton {
    Q_OBJECT
 public:
    MyPushButton(QWidget * parent = 0)
        : QPushButton(parent){}
    ~MyPushButton(){}
    
    //virtual MyPushButton& operator=(MyPushButton &);
    virtual MyPushButton* operator=(MyPushButton*);
    //virtual MyPushButton* operator[](int);
    //void setFixedSize(int, int);
    
    void setLocation(Loc x);
    void setLocation(int x, int y);
    Loc getLocation();

    void setColor(QColor);
 signals:
    void released(int &x, int &y, QColor);
    //void released(Loc src);
    public slots:
        void getMClicked(int &x, int &y, QColor);
        //void getClicked(Loc src);
 private:
        //bool isClicked;
    int locx;
    int locy;
    private slots:
        void setMColor(int &x, int &y, QColor);
};
