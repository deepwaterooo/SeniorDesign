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

class PopWindow : public QMainWindow {
    Q_OBJECT
    QWidget *centralWidget;
    //QHBoxLayout *hbox;   // hbox9
 public:
    explicit PopWindow(QWidget *parent = 0);
    ~PopWindow();
    void add_widget( QWidget* p_widget );
    void preColorClicked(int);
    void setColor(QPushButton* [][4], int i, int j, QColor);
    void setColor(QPushButton*);
    void setColorToDefault(QPushButton*);
    void setSpinBoxValue();
    void setHeight(QPlainTextEdit *edit, int nRows);
    void addFrame(QGridLayout*);
    void open();
    void printH(QColor color);
    void printM(QColor color);
    void printE(QColor color);
    void printP(QColor color);
    void printR(QColor color);

    public slots:
        void tbrowBtnClicked(); // for .tan file "Browse" button
 private:
        QPushButton *save;
        QPushButton *play;
        QPushButton *stop;
        QPushButton *pause;
        QPushButton *plus;
        QPushButton *minus;
        QPushButton *duplicate;
        QPushButton *clear;
        QGridLayout* gridPreColor;
        
        QPushButton* mButt[10][4];
        QGridLayout* mGrid;
        QString filename;
        QPushButton* scrLeft;
        QPushButton* scrRight;
        QPlainTextEdit *tedit;
        QPushButton *pre; // store the last color used
        QPushButton *cur; // for preview current color
        QSpinBox *rspinBox;
        QSpinBox *gspinBox;
        QSpinBox *bspinBox;
        QColor newColor;
        QColor curColor;

};
#endif
