#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QDialogButtonBox>
#include <QtGui>
#include <QSplitter>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QSpinBox>
#include <QSlider>
#include <QPalette>
#include <QPushButton>
#include <QLabel>
#include <QTime>
#include <QTimeEdit>
#include <QComboBox>
#include <QPixmap>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <string>
#include <QObject>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QSpinBox>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>

#include "popwindow.h"

void PopWindow::leftGridClicked(int &x, int &y, QColor color) {
    QColor fcolor = QColor::fromRgb(255,255,255);
    //mGrid->getClicked(x, y, fcolor);  // for changing back to QGridLayout and compile only
}

PopWindow::PopWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle(tr("Tower-iLLuminati Animation Window"));

    centralWidget = new QWidget();
    this->setCentralWidget(centralWidget);
    QVBoxLayout *vbox = new QVBoxLayout();   // for overall vertical boxa

    view = new QGraphicsView(this);
    scene = new QGraphicsScene();
    view->setGeometry(QRect(50, 50, 800, 200));
    //QGraphicsScene scene;
    QImage image(":/images/waveI");
    pix = QPixmap::fromImage(image);
    //QGraphicsPixmapItem item(QPixmap(":/images/waveI"));
    view->setScene(scene);
    scene->addPixmap(pix);
    //scene->addItem(&item);
    //view->scale(1, -1);
    //view->show();
    vbox->addWidget(view);
    
    /*
    // for .wav graphics
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    QGraphicsView view2(&scene);
    QGraphicsPixmapItem item(QPixmap(":/images/waveI"));
    //QGraphicsPixmapItem item2(QPixmap(":/images/h"));
    scene.addItem(&item);
    //scene.addItem(&item2);
    view.show();
    vbox->addWidget(&view);

    
      mGrid = new MyGridLayout();
      mGrid->setContentsMargins (0, 0, 0, 0);
      mGrid->setSizeConstraint (QLayout::SetFixedSize);
      //mGrid->setSpacing(13);
      // this connection does not work yet
      //connect(mGrid, SIGNAL(released(int&, int&, QColor)), this, SLOT(leftGridClicked(int&, int&, QColor)));
      printH(QColor::fromRgb(135,206,250));
    */

    // for mGrid Animation
    mGrid = new QGridLayout();
    mGrid->setContentsMargins (0, 0, 0, 0);
    mGrid->setSizeConstraint (QLayout::SetFixedSize);
    mGrid->setSpacing(13);
    for (int i = 0; i < 10; ++i) {        
        for (int j = 0; j < 4; ++j) {
            mButt[i][j] = new QPushButton();
            mButt[i][j]->setFixedSize(22, 22);
            mGrid->addWidget(mButt[i][j], i, j);
        }
    }
    printH(QColor::fromRgb(135,206,250));
    //addFrame(mGrid);  // cold remove this one
    
    //vbox->addLayout(mGrid);
    // to pack grid in the middle
    QHBoxLayout *hbox = new QHBoxLayout();
    QLabel *tmp1 = new QLabel;
    QLabel *tmp2 = new QLabel;
    tmp1->setFixedSize(80, 50);
    tmp2->setFixedSize(80, 50);
    hbox->addWidget(tmp1);
    hbox->addLayout(mGrid);
    hbox->addWidget(tmp2);
    vbox->addLayout(hbox);
    
    
    // for spinBox slider
    QHBoxLayout *hbox1 = new QHBoxLayout();
    QSpinBox *spinBox = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal, this);
    spinBox->setRange(0, 200);
    slider->setRange(0, 200);
    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
    QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);
    spinBox->setValue(25);
    
    hbox1->addWidget(slider);
    hbox1->addWidget(spinBox);
    vbox->addStretch(1);
    vbox->addLayout(hbox1);


    // for Save-Pause line buttons
    QHBoxLayout *hbox2 = new QHBoxLayout();
    QPushButton *first = new QPushButton(QIcon(":/images/beginI"), QObject::tr(""));
    play = new QPushButton(QIcon(":/images/playhsI"), QObject::tr(""));
    pause = new QPushButton(QIcon(":/images/pauseI"), QObject::tr(""));
    stop = new QPushButton(QIcon(":/images/stophsI"), QObject::tr(""));
    QPushButton *last = new QPushButton(QIcon(":/images/lastI"), QObject::tr(""));
    // add these four for myself
    QPushButton *forward = new QPushButton(QIcon(":/images/forwardI"), QObject::tr(""));
    QPushButton *backward = new QPushButton(QIcon(":/images/backwardI"), QObject::tr(""));
    QPushButton *fastforward = new QPushButton(QIcon(":/images/fastforwardI"), QObject::tr(""));
    QPushButton *fastbackward = new QPushButton(QIcon(":/images/fastbackwardI"), QObject::tr(""));
    first->setFixedSize(80,40);
    play->setFixedSize(80,40);
    pause->setFixedSize(80,40);
    stop->setFixedSize(80,40);
    last->setFixedSize(80,40);
    forward->setFixedSize(80, 40);
    backward->setFixedSize(80, 40);
    fastforward->setFixedSize(80, 40);
    fastbackward->setFixedSize(80, 40);
    
    hbox2->addWidget(first, 0, Qt::AlignLeft);
    hbox2->addWidget(fastbackward, 0, Qt::AlignCenter);
    hbox2->addWidget(backward, 0, Qt::AlignCenter);
    hbox2->addWidget(play, 0, Qt::AlignRight);
    hbox2->addWidget(pause, 0, Qt::AlignRight);
    hbox2->addWidget(stop, 0, Qt::AlignRight);
    hbox2->addWidget(forward, 0, Qt::AlignCenter);
    hbox2->addWidget(fastforward, 0, Qt::AlignCenter);
    hbox2->addWidget(last, 0, Qt::AlignRight);
    vbox->addLayout(hbox2); 

    
    // for overall layout
    centralWidget->setLayout(vbox);
}

void PopWindow::setHeight(QPlainTextEdit *edit, int nRows) { 
    QFontMetrics m (edit -> font()) ;
    int RowHeight = m.lineSpacing() ;
    edit -> setFixedHeight  (nRows * RowHeight) ;
}

void PopWindow::tbrowBtnClicked() {
    filename = QFileDialog::getOpenFileName(this, tr("Open file"), "/home/jenny/480/qt/tower/", tr("Tan files (*.tan);;Wave files (*.wav);;All files (*.*)"));
    tedit->insertPlainText(filename);
}

void PopWindow::setColor(QPushButton* ptrBtn[][4], int i, int j, QColor color) {
    int r,g,b;
    color.getRgb(&r, &g, &b);
    QString temp = "QPushButton{color:red;background-color:rgb(";
    QString tempr = QString::number(r);
    QString tempg = QString::number(g);
    QString tempb = QString::number(b);
    temp = temp + tempr + "," + tempg + "," + tempb + ")}";
    ptrBtn[i][j]->setStyleSheet(temp); 
}
/*
  void PopWindow::setColor(QPushButton* ptrBtn[][6], int i, int j, QColor color) {
  int r,g,b;
  color.getRgb(&r, &g, &b);
  QString temp = "QPushButton{color:red;background-color:rgb(";
  QString tempr = QString::number(r);
  QString tempg = QString::number(g);
  QString tempb = QString::number(b);
  temp = temp + tempr + "," + tempg + "," + tempb + ")}";
  ptrBtn[i][j]->setStyleSheet(temp); 
  }

  void PopWindow::setColor(QPushButton* ptrBtn[][6], int i, int j) {
  int r,g,b;
  newColor.getRgb(&r, &g, &b);
  QString temp = "QPushButton{color:red;background-color:rgb(";
  QString tempr = QString::number(r);
  QString tempg = QString::number(g);
  QString tempb = QString::number(b);
  temp = temp + tempr + "," + tempg + "," + tempb + ")}";
  ptrBtn[i][j]->setStyleSheet(temp); 
  // set newColor to be curColor
  curColor = newColor;
  }
*/
void PopWindow::setColorToDefault(QPushButton* ptrBtn) { // 239,235,231
    QString temp = "QPushButton{color:red;background-color:rgb(";
    QString tempr = QString::number(239);
    QString tempg = QString::number(235);
    QString tempb = QString::number(231);
    temp = temp + tempr + "," + tempg + "," + tempb + ")}";
    ptrBtn->setStyleSheet(temp); 
}

void PopWindow::setColor(QPushButton* ptrBtn) {
    int r,g,b;
    newColor.getRgb(&r, &g, &b);
    QString temp = "QPushButton{color:red;background-color:rgb(";
    QString tempr = QString::number(r);
    QString tempg = QString::number(g);
    QString tempb = QString::number(b);
    temp = temp + tempr + "," + tempg + "," + tempb + ")}";
    ptrBtn->setStyleSheet(temp); 
    // set newColor to be curColor
    curColor = newColor;
}
/*
  QColor PopWindow::getPreColor(int idx) {
  QColor color;
  color = mButton[idx]->palette().color(QPalette::Button);
  return color;
  }  
  // overloaded for "pre" button slot function
  QColor PopWindow::getPreCurColor(QPushButton* tmp) { 
  QColor color;
  color = tmp->palette().color(QPalette::Button);
  return color;
  }

  void PopWindow::preColorClicked(int idx) {
  newColor = getPreColor(idx);        
  setColor(cur);
  }
*/
void PopWindow::setSpinBoxValue() {
    int r,g,b;
    newColor.getRgb(&r, &g, &b);
    rspinBox->setValue(r);
    gspinBox->setValue(g);
    bspinBox->setValue(b);
}

void PopWindow::addFrame(QGridLayout* grid) {
    QFrame* line[28];
    for (int i = 0; i < 28; ++i) {        
        line[i] = new QFrame(); 
        line[i]->setLineWidth(3);
        line[i]->setMidLineWidth(2);
        line[i]->setFrameShadow(QFrame::Raised);
        line[i]->setFrameShape(QFrame::VLine);
    }
    for (int i = 20; i < 28; ++i) {        
        line[i] = new QFrame(); 
        line[i]->setLineWidth(3);
        line[i]->setMidLineWidth(2);
        line[i]->setFrameShadow(QFrame::Raised);
        line[i]->setFrameShape(QFrame::HLine);
    }
    for (int i = 0; i < 10; ++i) {        
        grid->addWidget(line[i], i, 0, Qt::AlignLeft);
    }
    for (int i = 0; i < 10; ++i) {        
        grid->addWidget(line[i+10], i, 3, Qt::AlignRight);
    }
    for (int i = 20; i < 24; ++i) {        
        grid->addWidget(line[i], 0, i-20, Qt::AlignTop);
    }
    for (int i = 24; i < 28; ++i) {        
        grid->addWidget(line[i], 9, i-24, Qt::AlignBottom);
    }
}

void PopWindow::printH(QColor color){ // LightSkyBlue 135,206,250
    for (int i = 0; i < 7; ++i) {
        setColor(mButt, i, 0, color);
        setColor(mButt, i, 3, color);
    }
    setColor(mButt, 3, 1, color);
    setColor(mButt, 3, 2, color);
}
void PopWindow::open() {
    QMessageBox::information(this, tr("Information"), tr("Open"));
}


PopWindow::~PopWindow() {
}
