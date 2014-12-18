#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QWidget>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>

//#include "Q8DigitSpinBox.h"
#include "myDoubleSpinBox.h"
#include "colorwheel.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
    QWidget *centralWidget;
    //QHBoxLayout *hbox;   // hbox9
 public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void add_widget( QWidget* p_widget );
    void preColorClicked(int);
    void setColor(QPushButton* [][4], int i, int j, QColor);
    void setColor(QPushButton* [][12], int i, int j, QColor);
    void setColor(QPushButton* [][12], int i, int j);
    void setColor(QPushButton*);
    void setColorToDefault(QPushButton*);
    QColor getPreColor(int idx);        // get color from predefined array
    QColor getPreCurColor(QPushButton*);// get color from "pre cur"  button
    void setSpinBoxValue();
    void setHeight(QPlainTextEdit *edit, int nRows);
    void addFrame(QGridLayout*);
    void open();
    void printH(QColor color);
    void printM(QColor color);
    void printE(QColor color);
    void printP(QColor color);
    void printR(QColor color);

 private:
    QGraphicsScene* scene;
    QGraphicsView* gview;
    QPixmap pix;

    QPushButton *mButton[2][34];  // for predifined colors
    QGridLayout* gridPreColor;
    QPushButton* mButt[20][12];
    QGridLayout* gridView[5];
    QPushButton* mBut1[10][4];
    QPushButton* mBut2[10][4];
    QPushButton* mBut3[10][4];
    QPushButton* mBut4[10][4];
    QPushButton* mBut5[10][4];
    QPushButton* dir[4][3];
    QString filename;
    QPushButton *pre; // store the last color used
    QPushButton *cur; // for preview current color
    QPlainTextEdit *tedit;
    MyDoubleSpinBox *atimeEdit;
    QSpinBox *rspinBox;
    QSpinBox *gspinBox;
    QSpinBox *bspinBox;
    QColor newColor;
    QColor curColor;
    public slots:
        void tbrowBtnClicked(); // for .tan file "Browse" button

        // for "pre" "cur" button to get latest color used
        void preBtnClicked(){newColor = getPreCurColor(pre);setColor(cur);setSpinBoxValue();}
        void curBtnClicked(){newColor = getPreCurColor(cur);setColor(cur);setSpinBoxValue();}
        // for colorwheel clicked
        void colorwheelClicked(QColor color) {        
            newColor = color;
            setColor(cur);
            setSpinBoxValue();
        }
        
        // for 17 predefined color slots
        void preColorClicked0() {newColor = getPreColor(0);setColor(cur);setSpinBoxValue();mButton[0][0]->setCheckable(true);mButton[0][0]->setAutoExclusive(false);}
        void preColorClicked1() {newColor = getPreColor(1);setColor(cur);setSpinBoxValue();mButton[0][1]->setCheckable(true);mButton[0][1]->setAutoExclusive(false);}
        void preColorClicked2() {newColor = getPreColor(2);setColor(cur);setSpinBoxValue();mButton[0][2]->setCheckable(true);mButton[0][2]->setAutoExclusive(false);}
        void preColorClicked3() {newColor = getPreColor(3);setColor(cur);setSpinBoxValue();mButton[0][3]->setCheckable(true);mButton[0][3]->setAutoExclusive(false);}
        void preColorClicked4() {newColor = getPreColor(4);setColor(cur);setSpinBoxValue();mButton[0][4]->setCheckable(true);mButton[0][4]->setAutoExclusive(false);}
        void preColorClicked5() {newColor = getPreColor(5);setColor(cur);setSpinBoxValue();mButton[0][5]->setCheckable(true);mButton[0][5]->setAutoExclusive(false);}
        void preColorClicked6() {newColor = getPreColor(6);setColor(cur);setSpinBoxValue();}
        void preColorClicked7() {newColor = getPreColor(7);setColor(cur);setSpinBoxValue();}
        void preColorClicked8() {newColor = getPreColor(8);setColor(cur);setSpinBoxValue();}
        void preColorClicked9() {newColor = getPreColor(9);setColor(cur);setSpinBoxValue();}
        void preColorClicked10() {newColor = getPreColor(10);setColor(cur);setSpinBoxValue();}
        void preColorClicked11() {newColor = getPreColor(11);setColor(cur);setSpinBoxValue();}
        void preColorClicked12() {newColor = getPreColor(12);setColor(cur);setSpinBoxValue();}
        void preColorClicked13() {newColor = getPreColor(13);setColor(cur);setSpinBoxValue();}
        void preColorClicked14() {newColor = getPreColor(14);setColor(cur);setSpinBoxValue();}
        void preColorClicked15() {newColor = getPreColor(15);setColor(cur);setSpinBoxValue();}
        void preColorClicked16() {newColor = getPreColor(16);setColor(cur);setSpinBoxValue();}

        // for 12x6 grid slots
        void gridLayoutClicked00();
        void gridLayoutClicked01();
        void gridLayoutClicked02();
        void gridLayoutClicked03();
        void gridLayoutClicked04();
        void gridLayoutClicked05();
        void gridLayoutClicked10();
        void gridLayoutClicked11();
        void gridLayoutClicked12();
        void gridLayoutClicked13();
        void gridLayoutClicked14();
        void gridLayoutClicked15();
        void gridLayoutClicked20();
        void gridLayoutClicked21();
        void gridLayoutClicked22();
        void gridLayoutClicked23();
        void gridLayoutClicked24();
        void gridLayoutClicked25();
        void gridLayoutClicked30();
        void gridLayoutClicked31();
        void gridLayoutClicked32();
        void gridLayoutClicked33();
        void gridLayoutClicked34();
        void gridLayoutClicked35();
        void gridLayoutClicked40();
        void gridLayoutClicked41();
        void gridLayoutClicked42();
        void gridLayoutClicked43();
        void gridLayoutClicked44();
        void gridLayoutClicked45();
        void gridLayoutClicked50();
        void gridLayoutClicked51();
        void gridLayoutClicked52();
        void gridLayoutClicked53();
        void gridLayoutClicked54();
        void gridLayoutClicked55();
        void gridLayoutClicked60();
        void gridLayoutClicked61();
        void gridLayoutClicked62();
        void gridLayoutClicked63();
        void gridLayoutClicked64();
        void gridLayoutClicked65();
        void gridLayoutClicked70();
        void gridLayoutClicked71();
        void gridLayoutClicked72();
        void gridLayoutClicked73();
        void gridLayoutClicked74();
        void gridLayoutClicked75();
        void gridLayoutClicked80();
        void gridLayoutClicked81();
        void gridLayoutClicked82();
        void gridLayoutClicked83();
        void gridLayoutClicked84();
        void gridLayoutClicked85();
        void gridLayoutClicked90();
        void gridLayoutClicked91();
        void gridLayoutClicked92();
        void gridLayoutClicked93();
        void gridLayoutClicked94();
        void gridLayoutClicked95();
        void gridLayoutClicked100();
        void gridLayoutClicked101();
        void gridLayoutClicked102();
        void gridLayoutClicked103();
        void gridLayoutClicked104();
        void gridLayoutClicked105();
        void gridLayoutClicked110();
        void gridLayoutClicked111();
        void gridLayoutClicked112();
        void gridLayoutClicked113();
        void gridLayoutClicked114();
        void gridLayoutClicked115();
        void gridLayoutClicked06();
        void gridLayoutClicked07();
        void gridLayoutClicked08();
        void gridLayoutClicked09();
        void gridLayoutClicked010();
        void gridLayoutClicked011();
        void gridLayoutClicked16();
        void gridLayoutClicked17();
        void gridLayoutClicked18();
        void gridLayoutClicked19();
        void gridLayoutClicked1m10();
        void gridLayoutClicked1m11();
        void gridLayoutClicked26();
        void gridLayoutClicked27();
        void gridLayoutClicked28();
        void gridLayoutClicked29();
        void gridLayoutClicked210();
        void gridLayoutClicked211();
        void gridLayoutClicked36();
        void gridLayoutClicked37();
        void gridLayoutClicked38();
        void gridLayoutClicked39();
        void gridLayoutClicked310();
        void gridLayoutClicked311();
        void gridLayoutClicked46();
        void gridLayoutClicked47();
        void gridLayoutClicked48();
        void gridLayoutClicked49();
        void gridLayoutClicked410();
        void gridLayoutClicked411();
        void gridLayoutClicked56();
        void gridLayoutClicked57();
        void gridLayoutClicked58();
        void gridLayoutClicked59();
        void gridLayoutClicked510();
        void gridLayoutClicked511();
        void gridLayoutClicked66();
        void gridLayoutClicked67();
        void gridLayoutClicked68();
        void gridLayoutClicked69();
        void gridLayoutClicked610();
        void gridLayoutClicked611();
        void gridLayoutClicked76();
        void gridLayoutClicked77();
        void gridLayoutClicked78();
        void gridLayoutClicked79();
        void gridLayoutClicked710();
        void gridLayoutClicked711();
        void gridLayoutClicked86();
        void gridLayoutClicked87();
        void gridLayoutClicked88();
        void gridLayoutClicked89();
        void gridLayoutClicked810();
        void gridLayoutClicked811();
        void gridLayoutClicked96();
        void gridLayoutClicked97();
        void gridLayoutClicked98();
        void gridLayoutClicked99();
        void gridLayoutClicked910();
        void gridLayoutClicked911();
        void gridLayoutClicked106();
        void gridLayoutClicked107();
        void gridLayoutClicked108();
        void gridLayoutClicked109();
        void gridLayoutClicked1010();
        void gridLayoutClicked1011();
        void gridLayoutClicked116();
        void gridLayoutClicked117();
        void gridLayoutClicked118();
        void gridLayoutClicked119();
        void gridLayoutClicked1110();
        void gridLayoutClicked1111();
        void gridLayoutClicked126();
        void gridLayoutClicked127();
        void gridLayoutClicked128();
        void gridLayoutClicked129();
        void gridLayoutClicked1210();
        void gridLayoutClicked1211();
        void gridLayoutClicked136();
        void gridLayoutClicked137();
        void gridLayoutClicked138();
        void gridLayoutClicked139();
        void gridLayoutClicked1310();
        void gridLayoutClicked1311();
        void gridLayoutClicked146();
        void gridLayoutClicked147();
        void gridLayoutClicked148();
        void gridLayoutClicked149();
        void gridLayoutClicked1410();
        void gridLayoutClicked1411();
        void gridLayoutClicked156();
        void gridLayoutClicked157();
        void gridLayoutClicked158();
        void gridLayoutClicked159();
        void gridLayoutClicked1510();
        void gridLayoutClicked1511();
        void gridLayoutClicked166();
        void gridLayoutClicked167();
        void gridLayoutClicked168();
        void gridLayoutClicked169();
        void gridLayoutClicked1610();
        void gridLayoutClicked1611();
        void gridLayoutClicked176();
        void gridLayoutClicked177();
        void gridLayoutClicked178();
        void gridLayoutClicked179();
        void gridLayoutClicked1710();
        void gridLayoutClicked1711();
        void gridLayoutClicked186();
        void gridLayoutClicked187();
        void gridLayoutClicked188();
        void gridLayoutClicked189();
        void gridLayoutClicked1810();
        void gridLayoutClicked1811();
        void gridLayoutClicked196();
        void gridLayoutClicked197();
        void gridLayoutClicked198();
        void gridLayoutClicked199();
        void gridLayoutClicked1910();
        void gridLayoutClicked1911();
        void gridLayoutClicked120();
        void gridLayoutClicked121();
        void gridLayoutClicked122();
        void gridLayoutClicked123();
        void gridLayoutClicked124();
        void gridLayoutClicked125();
        void gridLayoutClicked130();
        void gridLayoutClicked131();
        void gridLayoutClicked132();
        void gridLayoutClicked133();
        void gridLayoutClicked134();
        void gridLayoutClicked135();
        void gridLayoutClicked140();
        void gridLayoutClicked141();
        void gridLayoutClicked142();
        void gridLayoutClicked143();
        void gridLayoutClicked144();
        void gridLayoutClicked145();
        void gridLayoutClicked150();
        void gridLayoutClicked151();
        void gridLayoutClicked152();
        void gridLayoutClicked153();
        void gridLayoutClicked154();
        void gridLayoutClicked155();
        void gridLayoutClicked160();
        void gridLayoutClicked161();
        void gridLayoutClicked162();
        void gridLayoutClicked163();
        void gridLayoutClicked164();
        void gridLayoutClicked165();
        void gridLayoutClicked170();
        void gridLayoutClicked171();
        void gridLayoutClicked172();
        void gridLayoutClicked173();
        void gridLayoutClicked174();
        void gridLayoutClicked175();
        void gridLayoutClicked180();
        void gridLayoutClicked181();
        void gridLayoutClicked182();
        void gridLayoutClicked183();
        void gridLayoutClicked184();
        void gridLayoutClicked185();
        void gridLayoutClicked190();
        void gridLayoutClicked191();
        void gridLayoutClicked192();
        void gridLayoutClicked193();
        void gridLayoutClicked194();
        void gridLayoutClicked195();
};
    
#endif
