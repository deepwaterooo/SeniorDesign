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
#include <QObject>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QScrollArea>
#include <string>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle(tr("Tower-iLLuminati Main Window"));

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QMenu *edit = menuBar()->addMenu(tr("&Edit"));
    QMenu *mplay = menuBar()->addMenu(tr("&Play"));
    QMenu *select = menuBar()->addMenu(tr("&Select"));
    QMenu *view = menuBar()->addMenu(tr("&MTools"));
    QMenu *help = menuBar()->addMenu(tr("&Help"));

    QAction *newAct = new QAction(QIcon(":/images/newI"), tr("&New"), this);
    QAction *openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open"), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing .wav file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);
    QAction *openAction3 = new QAction(QIcon(":/images/saveI"), tr("&Save"), this);
    QAction *openAction3as = new QAction(QIcon(":/images/saveasI"), tr("&Save As"), this);
    QAction *openAction2 = new QAction(QIcon(":/images/doc-close"), tr("&Close"), this);
    QAction *mexport = new QAction(tr("&Export"), this);
    QAction *mexit = new QAction(tr("&Exit"), this);

    QAction *cutAct = new QAction(QIcon(":/images/cutI"), tr("&Cut"), this);
    QAction *openAction4 = new QAction(QIcon(":/images/copyI"), tr("&Copy"), this);
    QAction *openAction5 = new QAction(QIcon(":/images/pasteI"), tr("&Paste"), this);
    QAction *undoAct = new QAction(QIcon(":/images/undoI"), tr("Undo"), this);
    QAction *redoAct = new QAction(QIcon(":/images/redoI"), tr("Redo"), this);
    QAction *addAct = new QAction(QIcon(":/images/plusI"), tr("Add"), this);
    QAction *minusAct = new QAction(QIcon(":/images/minusI"), tr("Minus"), this);
    fileMenu->addAction(newAct);      //new
    fileMenu->addAction(openAction);  //open
    fileMenu->addAction(openAction3); //save
    fileMenu->addAction(openAction3as); //save as
    fileMenu->addAction(mexport);       //export
    fileMenu->addAction(openAction2);//close
    fileMenu->addAction(mexit);      //exit

    openAction2->setShortcuts(QKeySequence::Close);
    openAction2->setStatusTip(tr("Close an existing .wav file"));

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(newAct);      //new
    toolBar->addAction(openAction);  //open
    toolBar->addAction(openAction3); //save
    toolBar->addAction(openAction2); //close
    toolBar->addAction(cutAct);
    toolBar->addAction(openAction4);//copy
    toolBar->addAction(openAction5);//paste
    toolBar->addAction(undoAct);
    toolBar->addAction(redoAct);
    toolBar->addAction(addAct);
    toolBar->addAction(minusAct);

    // for Edit
    QAction *cut = new QAction(QIcon(":/images/cutI"), tr("&Cut"), this);
    QAction *copy = new QAction(QIcon(":/images/copyI"), tr("&Copy"), this);
    QAction *paste = new QAction(QIcon(":/images/pasteI"), tr("&Paste"), this);
    QAction *minsert = new QAction(tr("&Insert"), this);
    QAction *mdelete = new QAction(tr("&Delete"), this);
    QAction *mclear = new QAction(QIcon(":/images/clearI"), tr("&Clear Frame"), this);
    edit->addAction(cut);
    edit->addAction(copy);
    edit->addAction(paste);
    edit->addAction(minsert);
    edit->addAction(mdelete);
    edit->addAction(mclear);
    edit->addAction(undoAct);
    edit->addAction(redoAct);

    // for play
    QAction *playBef = new QAction(QIcon(":/images/beginI"), tr("from &Beginning"), this);
    QAction *playCur = new QAction(tr("from &Current"), this);
    QAction *mpause = new QAction(QIcon(":/images/pauseI"), tr("&Pause"), this);
    QAction *mstop = new QAction(QIcon(":/images/stophsI"), tr("&Stop"), this);
    QMenu *moveForw = mplay->addMenu(QIcon(":/images/forwardI"), tr("Move &Forward"));
    moveForw->addAction(tr("15 Sec"));
    moveForw->addAction(tr("30 Sec"));
    moveForw->addAction(tr("45 Sec"));
    /*  // don't think I need the images here
    QAction *fone = moveForw->addAction(QIcon(":/images/forwardI"), tr("15 Sec"));
    QAction *ftwo = moveForw->addAction(QIcon(":/images/fastforwardI"), tr("30 Sec"));
    QAction *fthree = moveForw->addAction(QIcon(":/images/fastforwardI"), tr("45 Sec"));
    */
    QMenu *moveBacw = mplay->addMenu(QIcon(":/images/backwardI"), tr("Move &Backward"));
    moveBacw->addAction(tr("15 Sec"));
    moveBacw->addAction(tr("30 Sec"));
    moveBacw->addAction(tr("45 Sec"));
    QAction *preView = new QAction(tr("P&review Mode"), this);
    QAction *selRow = new QAction(tr("&Row"), this);
    QAction *selCol = new QAction(tr("&Column"), this);
    QAction *selAll = new QAction(tr("&All"), this);
    QAction *invertSel = new QAction(tr("&Invert Select"), this);
    QAction *deselect = new QAction(tr("&Deselect"), this);
    QAction *insertShapes = new QAction(tr("&Insert Shapes"), this);
    QAction *defPath = new QAction(tr("&Define Pattern*"), this);
    QAction *colorG = new QAction(tr("&Color Gradient*"), this);
    QAction *doc = new QAction(tr("&Documentation"), this);
    QAction *about = new QAction(tr("&About"), this);
    mplay->addAction(playBef);
    mplay->addAction(playCur);
    mplay->addAction(mpause);
    mplay->addAction(mstop);
    mplay->addSeparator();
    mplay->addMenu(moveForw);
    mplay->addMenu(moveBacw);
    mplay->addSeparator();
    mplay->addAction(preView);
    select->addAction(selRow);
    select->addAction(selCol);
    select->addAction(selAll);
    select->addAction(invertSel);
    select->addAction(deselect);
    view->addAction(insertShapes);
    view->addAction(defPath);
    view->addAction(colorG);
    help->addAction(doc);
    help->addAction(about);


    centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    QHBoxLayout *hbox9 = new QHBoxLayout(this);
    QVBoxLayout *vbox = new QVBoxLayout(this);


    // for graphicsscene
    gview = new QGraphicsView();
    scene = new QGraphicsScene();
    gview->setGeometry(QRect(50, 50, 800, 200));
    QImage image(":/images/waveI");
    pix = QPixmap::fromImage(image);
    gview->setScene(scene);
    scene->addPixmap(pix);
    vbox->addWidget(gview);

    QHBoxLayout *hbox02 = new QHBoxLayout(this);
    //MyDoubleSpinBox *b02 = new MyDoubleSpinBox;
    QSpinBox *b02 = new QSpinBox(this);
    b02->setRange(0.000, 13);
    b02->setSingleStep(2);
    b02->setValue(5);   
    QSlider *slider02 = new QSlider(Qt::Horizontal, this);
    //spinBox->setRange(0, 25);
    slider02->setRange(0, 5.25);
    QObject::connect(slider02, &QSlider::valueChanged, b02, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
    QObject::connect(b02, spinBoxSignal, slider02, &QSlider::setValue);
    b02->setValue(25);
    hbox02->addWidget(slider02);
    hbox02->addWidget(b02);
    vbox->addStretch(1);
    vbox->addLayout(hbox02);

    
    // hbox10 for 5 images
    QHBoxLayout *hbox10 = new QHBoxLayout(this);
    for (int i = 0; i < 5; ++i) {        
        gridView[i] = new QGridLayout(this);
        gridView[i]->setSpacing(10);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< 4; j++) {
            mBut1[i][j] = new QPushButton(this);
            mBut1[i][j]->setFixedSize(13, 17);
            gridView[0]->addWidget(mBut1[i][j], i, j);
        }
    }
    printH(QColor::fromRgb(135,226,250));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< 4; j++) {
            mBut2[i][j] = new QPushButton(this);
            mBut2[i][j]->setFixedSize(13, 17);
            gridView[1]->addWidget(mBut2[i][j], i, j);
        }
    }
    printM(QColor::fromRgb(255,222,0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< 4; j++) {
            mBut3[i][j] = new QPushButton(this);
            mBut3[i][j]->setFixedSize(13, 17);
            gridView[2]->addWidget(mBut3[i][j], i, j);
        }
    }
    printR(QColor::fromRgb(143, 228, 143));  
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< 4; j++) {
            mBut4[i][j] = new QPushButton(this);
            mBut4[i][j]->setFixedSize(13, 17);
            gridView[3]->addWidget(mBut4[i][j], i, j);
        }
    }
    printP(QColor::fromRgb(176, 226, 222));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j< 4; j++) {
            mBut5[i][j] = new QPushButton(this);
            mBut5[i][j]->setFixedSize(13, 17);
            gridView[4]->addWidget(mBut5[i][j], i, j);
        }
    }
    printE(QColor::fromRgb(255, 105, 180));
    addFrame(gridView[3]);
    hbox10->addLayout(gridView[0]);
    hbox10->addLayout(gridView[1]);
    hbox10->addLayout(gridView[3]);  // P
    hbox10->addLayout(gridView[2]);  // R
    hbox10->addLayout(gridView[4]);
    //vbox->addLayout(hbox10);

    
    // for buttons
    QHBoxLayout *hbox1 = new QHBoxLayout(this);
    QSpinBox *spinBox = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal, this);
    spinBox->setRange(0, 200);
    slider->setRange(0, 200);
    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
    //void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
    QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);
    spinBox->setValue(25);
    
    hbox1->addWidget(slider);
    hbox1->addWidget(spinBox);
    vbox->addStretch(1);
    //vbox->addLayout(hbox1);                     // move to the end

    /* 
    //don't need this one for now
    // .tan file open dialog hboxes hboxw, hboxt
    QHBoxLayout *hboxt = new QHBoxLayout(this);
    QLabel *tan = new QLabel();
    tan->setText(".tan File: ");
    tedit = new QPlainTextEdit;
    tedit->setFont(QFont ("Courier", 10));
    setHeight(tedit, 2);
    QPushButton *tbrow  = new QPushButton(QIcon(":/images/doc-open"), tr("&Browse"));
    tbrow->setFixedSize(80, 30);
    hboxt->addWidget(tan);
    hboxt->addWidget(tedit);
    hboxt->addWidget(tbrow);
    connect(tbrow, SIGNAL(released()), this, SLOT(tbrowBtnClicked()));
    */
    
    // for Save-Pause line buttons
    QHBoxLayout *hbox2 = new QHBoxLayout(this);
    QPushButton *first = new QPushButton(QIcon(":/images/beginI"), QObject::tr(""), this);
    QPushButton *play = new QPushButton(QIcon(":/images/playhsI"), QObject::tr(""), this);
    QPushButton *pause = new QPushButton(QIcon(":/images/pauseI"), QObject::tr(""), this);
    QPushButton *stop = new QPushButton(QIcon(":/images/stophsI"), QObject::tr(""), this);
    QPushButton *last = new QPushButton(QIcon(":/images/lastI"), QObject::tr(""), this);
    // add these four for myself
    QPushButton *forward = new QPushButton(QIcon(":/images/forwardI"), QObject::tr(""), this);
    QPushButton *backward = new QPushButton(QIcon(":/images/backwardI"), QObject::tr(""), this);
    QPushButton *fastforward = new QPushButton(QIcon(":/images/fastforwardI"), QObject::tr(""), this);
    QPushButton *fastbackward = new QPushButton(QIcon(":/images/fastbackwardI"), QObject::tr(""), this);
    first->setFixedSize(80,30);
    play->setFixedSize(80,30);
    pause->setFixedSize(80,30);
    stop->setFixedSize(80,30);
    last->setFixedSize(80,30);
    forward->setFixedSize(80, 30);
    backward->setFixedSize(80, 30);
    fastforward->setFixedSize(80, 30);
    fastbackward->setFixedSize(80, 30);
    
    hbox2->addWidget(first, 0, Qt::AlignLeft);
    hbox2->addWidget(fastbackward, 0, Qt::AlignCenter);
    hbox2->addWidget(backward, 0, Qt::AlignCenter);
    hbox2->addWidget(play, 0, Qt::AlignRight);
    hbox2->addWidget(pause, 0, Qt::AlignRight);
    hbox2->addWidget(stop, 0, Qt::AlignRight);
    hbox2->addWidget(forward, 0, Qt::AlignCenter);
    hbox2->addWidget(fastforward, 0, Qt::AlignCenter);
    hbox2->addWidget(last, 0, Qt::AlignRight);
            //vbox->addLayout(hbox2); 

    // for 8 direction square
    QGridLayout* direction = new QGridLayout(this);
    direction->setSpacing(10);
    dir[0][0] = new QPushButton(QIcon(":/images/upleftI"), tr(""), this);
    dir[0][1] = new QPushButton(QIcon(":/images/upI"), tr(""), this);
    dir[0][2] = new QPushButton(QIcon(":/images/uprightI"), tr(""), this);
    dir[1][0] = new QPushButton(QIcon(":/images/leftI"), tr(""), this);
    dir[1][1] = new QPushButton(this);
    dir[1][2] = new QPushButton(QIcon(":/images/rightI"), tr(""), this);
    dir[2][0] = new QPushButton(QIcon(":/images/downleftI"), tr(""), this);
    dir[2][1] = new QPushButton(QIcon(":/images/downI"), tr(""), this);
    dir[2][2] = new QPushButton(QIcon(":/images/downrightI"), tr(""), this);
    dir[3][0] = new QPushButton(this);
    dir[3][1] = new QPushButton(this);
    dir[3][2] = new QPushButton(this);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j ) {
            dir[i][j]->setFixedSize(50, 50);
            direction->addWidget(dir[i][j], i, j);
        }
    }
    dir[1][1]->setFlat(true);
    for (int i = 0; i < 3; ++i) 
        dir[3][i]->setFixedSize(50, 70);  // 50, 80
    
    // inserted verticalbox part
    QVBoxLayout *vbox2 = new QVBoxLayout();
    QHBoxLayout *hbox = new QHBoxLayout(this);
    QHBoxLayout *hbox7 = new QHBoxLayout(this);
    QHBoxLayout *hbox3 = new QHBoxLayout(this);
    QHBoxLayout *hbox4 = new QHBoxLayout(this);
    QHBoxLayout *hbox5 = new QHBoxLayout(this);
    vbox->setSpacing(5);

    // two time boxes
    QLabel *atimel = new QLabel;
    atimel->setText(tr("Frame Start Time: "));
    QLabel *btimel = new QLabel;
    btimel->setText(tr("Increment Amount: "));
    atimeEdit = new MyDoubleSpinBox();                ////////////////////////////////////////
    //atimeEdit->setValue(5.25);
    atimeEdit->setValue(5.338);
    /*    
    atimeEdit = new Q8DigitSpinBox;
    //atimeEdit->setValue(328.0);
    QDoubleSpinBox *btimeEdit = new QDoubleSpinBox();
    btimeEdit->setRange(0.000, 60.000);
    btimeEdit->setSingleStep(0.001);
    btimeEdit->setValue(13.320);   // partially working now
    */  
    MyDoubleSpinBox *btimeEdit = new MyDoubleSpinBox;
    btimeEdit->setRange(0.000, 60.000);
    btimeEdit->setSingleStep(0.001);
    //btimeEdit->setValue(13.320);
    btimeEdit->setValue(13.548);   

    atimel->setFixedSize(115,30);
    btimel->setFixedSize(115,30);
    hbox->addWidget(atimel);
    hbox->addWidget(atimeEdit);
    hbox7->addWidget(btimel);
    hbox7->addWidget(btimeEdit);
    
    // integer spinbox
    QLabel *alabel = new QLabel(tr("Red:  "));
    alabel->setStyleSheet("QLabel { background-color : red; color : black; }");
    rspinBox = new QSpinBox;
    rspinBox->setRange(0, 255);
    rspinBox->setSingleStep(1);
    rspinBox->setValue(255);
    QLabel *blabel = new QLabel(tr("Green:"));
    blabel->setStyleSheet("QLabel { background-color : green; color : black; }");
    gspinBox = new QSpinBox;
    gspinBox->setRange(0, 255);
    gspinBox->setSingleStep(1);
    gspinBox->setValue(255);
    QLabel *clabel = new QLabel(tr("Blue: "));
    clabel->setStyleSheet("QLabel { background-color : blue; color : black; }");
    bspinBox = new QSpinBox;
    bspinBox->setRange(0, 255);
    bspinBox->setSingleStep(1);
    bspinBox->setValue(255);
    hbox3->addWidget(alabel);
    hbox3->addWidget(rspinBox);
    hbox4->addWidget(blabel);
    hbox4->addWidget(gspinBox);
    hbox5->addWidget(clabel);
    hbox5->addWidget(bspinBox);
    vbox2->addLayout(hbox);
    vbox2->addLayout(hbox7);
    /*
    vbox2->addWidget(atimel);
    vbox2->addWidget(atimeEdit);
    vbox2->addWidget(btimel);
    vbox2->addWidget(btimeEdit);
    */
    QVBoxLayout* vboxRgb = new QVBoxLayout();  // for R G B
    vboxRgb->addLayout(hbox3);
    vboxRgb->addLayout(hbox4);
    vboxRgb->addLayout(hbox5);
    
    // inserted verticalbox3 part for color preview
    QVBoxLayout *vbox3 = new QVBoxLayout();
    vbox3->setAlignment(Qt::AlignHCenter);
    //QLabel *prelabel = new QLabel(tr("Previous Color: "));    // didn't use these ones
    //QLabel *curlabel = new QLabel(tr("New Color Preview:"));
    pre = new QPushButton(this);
    cur = new QPushButton(this);
    pre->setFixedSize(110,60);
    cur->setFixedSize(110,60);
    vbox3->setAlignment(pre, Qt::AlignCenter);
    vbox3->setAlignment(cur, Qt::AlignCenter);
    //vbox3->addWidget(prelabel);
    vbox3->addWidget(pre);
    //vbox3->addWidget(curlabel);
    vbox3->addWidget(cur);
    connect(pre, SIGNAL(released()), this, SLOT(preBtnClicked()));
    connect(cur, SIGNAL(released()), this, SLOT(curBtnClicked()));
    QHBoxLayout* hboxRgb = new QHBoxLayout(this);
    hboxRgb->addLayout(vboxRgb);
    hboxRgb->addLayout(vbox3);
    QHBoxLayout *hbox11 = new QHBoxLayout(this);
    ColorWheel* color = new ColorWheel(this);
    // set signal slot for color
    connect(color, SIGNAL(colorChange(const QColor&)), this, SLOT(colorwheelClicked(QColor)));
    vbox2->addLayout(hboxRgb); // R G B preview hbox

    // added a line in between the two part
    QFrame *line2 = new QFrame(this);    // <<< this does the trick
    line2->setLineWidth(3);
    line2->setMidLineWidth(2);
    line2->setFrameShape(QFrame::VLine);
    line2->setFrameShadow(QFrame::Raised);
    QFrame *line3 = new QFrame(this);    // <<< this does the trick
    line3->setLineWidth(3);
    line3->setMidLineWidth(2);
    line3->setFrameShape(QFrame::VLine);
    line3->setFrameShadow(QFrame::Raised);
    QFrame *line4 = new QFrame();    // <<< this does the trick
    line4->setLineWidth(3);
    line4->setMidLineWidth(2);
    line4->setFrameShape(QFrame::VLine);
    line4->setFrameShadow(QFrame::Raised);
    QFrame *line5 = new QFrame();    // <<< this does the trick
    line5->setLineWidth(3);
    line5->setMidLineWidth(2);
    line5->setFrameShape(QFrame::VLine);
    line5->setFrameShadow(QFrame::Raised);
    hbox11->addLayout(direction, Qt::AlignLeft);
    hbox11->addWidget(line2);

    //hbox11->addLayout(vbox2, Qt::AlignCenter);
    hbox11->addLayout(vbox2, Qt::AlignLeft);
    //hbox11->addLayout(vbox2);
    hbox11->addWidget(line3);
    //hbox11->addLayout(vboxRgb);
    //hbox11->addWidget(line4);
    //hbox11->addLayout(vbox3);
    //hbox11->addWidget(line5);
    //hbox11->setSpacing(15);
    
    QVBoxLayout *vcolor = new QVBoxLayout();
    QLabel *mytmp = new QLabel;
    QLabel *mytmp2 = new QLabel;
    vcolor->addWidget(mytmp, Qt::AlignRight);
    vcolor->addWidget(color, Qt::AlignRight);
    vcolor->addWidget(mytmp2, Qt::AlignRight);

    // grid with scroll bar command button layout
    QScrollArea * scrollArea = new QScrollArea(this);
     QWidget *contentsWidget = new QWidget(scrollArea);
     //QGridLayout *grid0 = new QGridLayout(contentsWidget);
     QVBoxLayout *grid0 = new QVBoxLayout();
     grid0->setSpacing(1);
     scrollArea->setWidgetResizable(true);
     scrollArea->setWidget(contentsWidget);
     contentsWidget->setLayout(grid0);
     //contentsWidget->setMinimumSize(scrollArea->width(), scrollArea->height());
     //grid0->setHorizontalSpacing(0);
     //grid0->setVerticalSpacing(0);
     QPushButton *brow[12];
     brow[0] = new QPushButton(tr(" &Color Gradient"));
     brow[1] = new QPushButton(tr(" &Star"));
     brow[2] = new QPushButton(tr(" &Heart"));
     brow[3] = new QPushButton(tr(" &Sine Wave"));
     brow[4] = new QPushButton(tr(" &Triangle"));
     brow[5] = new QPushButton(tr(" &Rectangle"));
     brow[6] = new QPushButton(tr(" &Polygen Five"));
     brow[7] = new QPushButton(tr(" &H print H"));
     brow[8] = new QPushButton(tr(" &B print B"));
     brow[9] = new QPushButton(tr(" &P print P"));
     brow[10] = new QPushButton(tr(" &R print R"));
     brow[11] = new QPushButton(tr(" &E print E"));
     //                                                  "border:5px;\n"
     for (int i = 0; i < 12; ++i) {
         brow[i]->setFixedSize(150, 30);
         brow[i]->setStyleSheet(QString::fromUtf8("font-weight:300;\n"
                                                  "color:black;\n"
                                                  "text-align:left;"));
         grid0->addWidget(brow[i], Qt::AlignLeft);
         //grid0->addWidget(brow[i], i, 0, Qt::AlignLeft);
     }

     // hbox11 added to vbox overall layout
     hbox11->addLayout(vcolor, Qt::AlignLeft);
     hbox11->addWidget(line4);
     hbox11->addWidget(scrollArea, Qt::AlignLeft);
     //vbox->addLayout(hbox11);
     vbox->addLayout(hbox11, Qt::AlignRight);

    
    // for predefined color button background colors
    gridPreColor = new QGridLayout(this);
    gridPreColor->setSpacing(3);
    for(int j = 0; j < 2; j++) {        
        for (int i = 0; i < 34; i++) {
            mButton[j][i] = new QPushButton(this);
            mButton[j][i]->setFixedSize(22, 22);  // 31 originally
            gridPreColor->addWidget(mButton[j][i], j, i);
        }
    }
    vbox->addLayout(gridPreColor);
    vbox->addLayout(hbox10);
            vbox->addLayout(hbox1);
            vbox->addLayout(hbox2);
            
    QString temp = "QPushButton{color:red;background-color:rgb(";
    QString temp2 = QString::number(0);
    temp = temp + temp2 + "," + temp2 + "," + temp2 + ")}";
    mButton[0][0]->setStyleSheet(temp);
    mButton[0][1]->setStyleSheet("QPushButton{color:red;background-color:rgb(255,255,255)}");
    mButton[0][2]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,255,255)}");
    mButton[0][3]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,139,139)}");
    mButton[0][4]->setStyleSheet("QPushButton{color:red;background-color:rgb(255,0,0)}");
    mButton[0][5]->setStyleSheet("QPushButton{color:red;background-color:rgb(139,0,0)}");
    mButton[0][6]->setStyleSheet("QPushButton{color:red;background-color:rgb(255,0,255)}");
    mButton[0][7]->setStyleSheet("QPushButton{color:red;background-color:rgb(139,0,139)}");
    mButton[0][8]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,128,0)}");
    mButton[0][9]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,100,0)}");
    mButton[0][10]->setStyleSheet("QPushButton{color:red;background-color:rgb(255,255,0)}");
    mButton[0][11]->setStyleSheet("QPushButton{color:red;background-color:rgb(233,150,122)}"); // darkyello, darkSalmon
    mButton[0][12]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,0,255)}");
    mButton[0][13]->setStyleSheet("QPushButton{color:red;background-color:rgb(0,0,139)}");
    mButton[0][14]->setStyleSheet("QPushButton{color:red;background-color:rgb(128,128,128)}");
    mButton[0][15]->setStyleSheet("QPushButton{color:red;background-color:rgb(169,169,169)}");
    mButton[0][16]->setStyleSheet("QPushButton{color:red;background-color:rgb(211,211,211)}");
    connect(mButton[0][0], SIGNAL(released()), this, SLOT(preColorClicked0()));
    connect(mButton[0][1], SIGNAL(released()), this, SLOT(preColorClicked1()));
    connect(mButton[0][2], SIGNAL(released()), this, SLOT(preColorClicked2()));
    connect(mButton[0][3], SIGNAL(released()), this, SLOT(preColorClicked3()));
    connect(mButton[0][4], SIGNAL(released()), this, SLOT(preColorClicked4()));
    connect(mButton[0][5], SIGNAL(released()), this, SLOT(preColorClicked5()));
    connect(mButton[0][6], SIGNAL(released()), this, SLOT(preColorClicked6()));
    connect(mButton[0][7], SIGNAL(released()), this, SLOT(preColorClicked7()));
    connect(mButton[0][8], SIGNAL(released()), this, SLOT(preColorClicked8()));
    connect(mButton[0][9], SIGNAL(released()), this, SLOT(preColorClicked9()));
    connect(mButton[0][10], SIGNAL(released()), this, SLOT(preColorClicked10()));
    connect(mButton[0][11], SIGNAL(released()), this, SLOT(preColorClicked11()));
    connect(mButton[0][12], SIGNAL(released()), this, SLOT(preColorClicked12()));
    connect(mButton[0][13], SIGNAL(released()), this, SLOT(preColorClicked13()));
    connect(mButton[0][14], SIGNAL(released()), this, SLOT(preColorClicked14()));
    connect(mButton[0][15], SIGNAL(released()), this, SLOT(preColorClicked15()));
    connect(mButton[0][16], SIGNAL(released()), this, SLOT(preColorClicked16()));
    //vbox->addLayout(hbox8);


    // left hand side grid section
    QGridLayout* grid = new QGridLayout(this);
    grid->setSpacing(13);
    for (int i = 0; i < 20; ++i ) {
        for (int j = 0; j < 12; ++j ) {
            mButt[i][j] = new QPushButton(this);
            mButt[i][j]->setFixedSize(23, 28);
            grid->addWidget(mButt[i][j], i, j);
        }
    }
    connect(mButt[0][0], SIGNAL(released()), this, SLOT(gridLayoutClicked00()));   
    connect(mButt[0][1], SIGNAL(released()), this, SLOT(gridLayoutClicked01()));   
    connect(mButt[0][2], SIGNAL(released()), this, SLOT(gridLayoutClicked02()));   
    connect(mButt[0][3], SIGNAL(released()), this, SLOT(gridLayoutClicked03()));   
    connect(mButt[0][4], SIGNAL(released()), this, SLOT(gridLayoutClicked04()));   
    connect(mButt[0][5], SIGNAL(released()), this, SLOT(gridLayoutClicked05()));   
    connect(mButt[1][0], SIGNAL(released()), this, SLOT(gridLayoutClicked10()));   
    connect(mButt[1][1], SIGNAL(released()), this, SLOT(gridLayoutClicked11()));   
    connect(mButt[1][2], SIGNAL(released()), this, SLOT(gridLayoutClicked12()));   
    connect(mButt[1][3], SIGNAL(released()), this, SLOT(gridLayoutClicked13()));   
    connect(mButt[1][4], SIGNAL(released()), this, SLOT(gridLayoutClicked14()));   
    connect(mButt[1][5], SIGNAL(released()), this, SLOT(gridLayoutClicked15()));   
    connect(mButt[2][0], SIGNAL(released()), this, SLOT(gridLayoutClicked20()));   
    connect(mButt[2][1], SIGNAL(released()), this, SLOT(gridLayoutClicked21()));   
    connect(mButt[2][2], SIGNAL(released()), this, SLOT(gridLayoutClicked22()));   
    connect(mButt[2][3], SIGNAL(released()), this, SLOT(gridLayoutClicked23()));   
    connect(mButt[2][4], SIGNAL(released()), this, SLOT(gridLayoutClicked24()));   
    connect(mButt[2][5], SIGNAL(released()), this, SLOT(gridLayoutClicked25()));   
    connect(mButt[3][0], SIGNAL(released()), this, SLOT(gridLayoutClicked30()));   
    connect(mButt[3][1], SIGNAL(released()), this, SLOT(gridLayoutClicked31()));   
    connect(mButt[3][2], SIGNAL(released()), this, SLOT(gridLayoutClicked32()));   
    connect(mButt[3][3], SIGNAL(released()), this, SLOT(gridLayoutClicked33()));   
    connect(mButt[3][4], SIGNAL(released()), this, SLOT(gridLayoutClicked34()));   
    connect(mButt[3][5], SIGNAL(released()), this, SLOT(gridLayoutClicked35()));   
    connect(mButt[4][0], SIGNAL(released()), this, SLOT(gridLayoutClicked40()));   
    connect(mButt[4][1], SIGNAL(released()), this, SLOT(gridLayoutClicked41()));   
    connect(mButt[4][2], SIGNAL(released()), this, SLOT(gridLayoutClicked42()));   
    connect(mButt[4][3], SIGNAL(released()), this, SLOT(gridLayoutClicked43()));   
    connect(mButt[4][4], SIGNAL(released()), this, SLOT(gridLayoutClicked44()));   
    connect(mButt[4][5], SIGNAL(released()), this, SLOT(gridLayoutClicked45()));   
    connect(mButt[5][0], SIGNAL(released()), this, SLOT(gridLayoutClicked50()));   
    connect(mButt[5][1], SIGNAL(released()), this, SLOT(gridLayoutClicked51()));   
    connect(mButt[5][2], SIGNAL(released()), this, SLOT(gridLayoutClicked52()));   
    connect(mButt[5][3], SIGNAL(released()), this, SLOT(gridLayoutClicked53()));   
    connect(mButt[5][4], SIGNAL(released()), this, SLOT(gridLayoutClicked54()));   
    connect(mButt[5][5], SIGNAL(released()), this, SLOT(gridLayoutClicked55()));   
    connect(mButt[6][0], SIGNAL(released()), this, SLOT(gridLayoutClicked60()));   
    connect(mButt[6][1], SIGNAL(released()), this, SLOT(gridLayoutClicked61()));   
    connect(mButt[6][2], SIGNAL(released()), this, SLOT(gridLayoutClicked62()));   
    connect(mButt[6][3], SIGNAL(released()), this, SLOT(gridLayoutClicked63()));   
    connect(mButt[6][4], SIGNAL(released()), this, SLOT(gridLayoutClicked64()));   
    connect(mButt[6][5], SIGNAL(released()), this, SLOT(gridLayoutClicked65()));   
    connect(mButt[7][0], SIGNAL(released()), this, SLOT(gridLayoutClicked70()));   
    connect(mButt[7][1], SIGNAL(released()), this, SLOT(gridLayoutClicked71()));   
    connect(mButt[7][2], SIGNAL(released()), this, SLOT(gridLayoutClicked72()));   
    connect(mButt[7][3], SIGNAL(released()), this, SLOT(gridLayoutClicked73()));   
    connect(mButt[7][4], SIGNAL(released()), this, SLOT(gridLayoutClicked74()));   
    connect(mButt[7][5], SIGNAL(released()), this, SLOT(gridLayoutClicked75()));   
    connect(mButt[8][0], SIGNAL(released()), this, SLOT(gridLayoutClicked80()));   
    connect(mButt[8][1], SIGNAL(released()), this, SLOT(gridLayoutClicked81()));   
    connect(mButt[8][2], SIGNAL(released()), this, SLOT(gridLayoutClicked82()));   
    connect(mButt[8][3], SIGNAL(released()), this, SLOT(gridLayoutClicked83()));   
    connect(mButt[8][4], SIGNAL(released()), this, SLOT(gridLayoutClicked84()));   
    connect(mButt[8][5], SIGNAL(released()), this, SLOT(gridLayoutClicked85()));   
    connect(mButt[9][0], SIGNAL(released()), this, SLOT(gridLayoutClicked90()));   
    connect(mButt[9][1], SIGNAL(released()), this, SLOT(gridLayoutClicked91()));   
    connect(mButt[9][2], SIGNAL(released()), this, SLOT(gridLayoutClicked92()));   
    connect(mButt[9][3], SIGNAL(released()), this, SLOT(gridLayoutClicked93()));   
    connect(mButt[9][4], SIGNAL(released()), this, SLOT(gridLayoutClicked94()));   
    connect(mButt[9][5], SIGNAL(released()), this, SLOT(gridLayoutClicked95()));   
    connect(mButt[10][0], SIGNAL(released()), this, SLOT(gridLayoutClicked100()));   
    connect(mButt[10][1], SIGNAL(released()), this, SLOT(gridLayoutClicked101()));   
    connect(mButt[10][2], SIGNAL(released()), this, SLOT(gridLayoutClicked102()));   
    connect(mButt[10][3], SIGNAL(released()), this, SLOT(gridLayoutClicked103()));   
    connect(mButt[10][4], SIGNAL(released()), this, SLOT(gridLayoutClicked104()));   
    connect(mButt[10][5], SIGNAL(released()), this, SLOT(gridLayoutClicked105()));   
    connect(mButt[11][0], SIGNAL(released()), this, SLOT(gridLayoutClicked110()));   
    connect(mButt[11][1], SIGNAL(released()), this, SLOT(gridLayoutClicked111()));   
    connect(mButt[11][2], SIGNAL(released()), this, SLOT(gridLayoutClicked112()));   
    connect(mButt[11][3], SIGNAL(released()), this, SLOT(gridLayoutClicked113()));   
    connect(mButt[11][4], SIGNAL(released()), this, SLOT(gridLayoutClicked114()));   
    connect(mButt[11][5], SIGNAL(released()), this, SLOT(gridLayoutClicked115()));   
    setLayout(grid);

    // try to set a frame inside the grid
    QFrame* line[28];
    for (int i = 0; i < 28; ++i) {        
        line[i] = new QFrame(); 
        line[i]->setLineWidth(4);
        line[i]->setMidLineWidth(3);
        line[i]->setFrameShadow(QFrame::Raised);
        line[i]->setFrameShape(QFrame::VLine);
        line[i]->setPalette(QPalette(QColor(255, 0, 0)));  // give it a color to stand out
    }
    for (int i = 20; i < 28; ++i) {        
        line[i] = new QFrame(); 
        line[i]->setLineWidth(3);
        line[i]->setMidLineWidth(2);
        line[i]->setFrameShadow(QFrame::Raised);
        line[i]->setFrameShape(QFrame::HLine);
    }
    for (int i = 0; i < 10; ++i) {        
        grid->addWidget(line[i], 5+i, 4, Qt::AlignLeft);
    }
    for (int i = 0; i < 10; ++i) {        
        grid->addWidget(line[i+10], 5+i, 7, Qt::AlignRight);
    }
    for (int i = 20; i < 24; ++i) {        
        line[i]->setPalette(QPalette(QColor(255, 0, 0)));  // give it a color to stand out
        grid->addWidget(line[i], 5, i-16, Qt::AlignTop);
    }
    for (int i = 24; i < 28; ++i) {        
        line[i]->setPalette(QPalette(QColor(255, 0, 0)));  // give it a color to stand out
        grid->addWidget(line[i], 14, i-20, Qt::AlignBottom);
    }
    
    // added a line in between left and right side
    QFrame *linea1 = new QFrame(this);    
    linea1->setLineWidth(3);
    linea1->setMidLineWidth(2);
    linea1->setFrameShape(QFrame::VLine);
    linea1->setFrameShadow(QFrame::Raised);
    //linea1->setPalette(QPalette(QColor(255, 0, 0)));  // could set line color here
    hbox9->addLayout(grid);
    hbox9->addWidget(linea1);
    hbox9->addLayout(vbox);
    centralWidget->setLayout(hbox9);
}

void MainWindow::setHeight(QPlainTextEdit *edit, int nRows) { 
    QFontMetrics m (edit -> font()) ;
    int RowHeight = m.lineSpacing() ;
    edit -> setFixedHeight  (nRows * RowHeight) ;
}

void MainWindow::tbrowBtnClicked() {
    filename = QFileDialog::getOpenFileName(this, tr("Open file"), "/home/jenny/480/qt/tower/", tr("Tan files (*.tan);;Wave files (*.wav);;All files (*.*)"));
    tedit->insertPlainText(filename);
}

void MainWindow::setColor(QPushButton* ptrBtn[][4], int i, int j, QColor color) {
    int r,g,b;
    color.getRgb(&r, &g, &b);
    QString temp = "QPushButton{color:red;background-color:rgb(";
    QString tempr = QString::number(r);
    QString tempg = QString::number(g);
    QString tempb = QString::number(b);
    temp = temp + tempr + "," + tempg + "," + tempb + ")}";
    ptrBtn[i][j]->setStyleSheet(temp); 
}

void MainWindow::setColor(QPushButton* ptrBtn[][12], int i, int j, QColor color) {
    int r,g,b;
    color.getRgb(&r, &g, &b);
    QString temp = "QPushButton{color:red;background-color:rgb(";
    QString tempr = QString::number(r);
    QString tempg = QString::number(g);
    QString tempb = QString::number(b);
    temp = temp + tempr + "," + tempg + "," + tempb + ")}";
    ptrBtn[i][j]->setStyleSheet(temp); 
}

void MainWindow::setColor(QPushButton* ptrBtn[][12], int i, int j) {
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

void MainWindow::setColorToDefault(QPushButton* ptrBtn) { // 239,235,231
    QString temp = "QPushButton{color:red;background-color:rgb(";
    QString tempr = QString::number(239);
    QString tempg = QString::number(235);
    QString tempb = QString::number(231);
    temp = temp + tempr + "," + tempg + "," + tempb + ")}";
    ptrBtn->setStyleSheet(temp); 
}

void MainWindow::setColor(QPushButton* ptrBtn) {
    int r,g,b;
    newColor.getRgb(&r, &g, &b);
    QString temp = "QPushButton{color:red;background-color:rgb(";
    QString tempr = QString::number(r);
    QString tempg = QString::number(g);
    QString tempb = QString::number(b);
    temp = temp + tempr + "," + tempg + "," + tempb + ")}";
    ptrBtn->setStyleSheet(temp); 
    // set newColor to be curColor
    curColor = newColor;    // ?
}

QColor MainWindow::getPreColor(int idx) {
    QColor color;
    color = mButton[0][idx]->palette().color(QPalette::Button);
    return color;
}
// overloaded for "pre" button slot function
QColor MainWindow::getPreCurColor(QPushButton* tmp) { 
    QColor color;
    color = tmp->palette().color(QPalette::Button);
    return color;
}

void MainWindow::preColorClicked(int idx) {
    newColor = getPreColor(idx);        
    setColor(cur);
}

void MainWindow::setSpinBoxValue() {
    int r,g,b;
    newColor.getRgb(&r, &g, &b);
    rspinBox->setValue(r);
    gspinBox->setValue(g);
    bspinBox->setValue(b);
}

void MainWindow::addFrame(QGridLayout* grid) {
    QFrame* line[28];
    for (int i = 0; i < 28; ++i) {        
        line[i] = new QFrame(); 
        line[i]->setLineWidth(3);
        line[i]->setMidLineWidth(2);
        line[i]->setFrameShadow(QFrame::Raised);
        line[i]->setFrameShape(QFrame::VLine);
        line[i]->setPalette(QPalette(QColor(255, 0, 0)));  // give it a color to stand out
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
        line[i]->setPalette(QPalette(QColor(255, 0, 0)));  // give it a color to stand out
        grid->addWidget(line[i], 0, i-20, Qt::AlignTop);
    }
    for (int i = 24; i < 28; ++i) {        
        line[i]->setPalette(QPalette(QColor(255, 0, 0)));  // give it a color to stand out
        grid->addWidget(line[i], 9, i-24, Qt::AlignBottom);
    }
}

void MainWindow::gridLayoutClicked00(){setColor(mButt,0,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked01(){setColor(mButt,0,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked02(){setColor(mButt,0,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked03(){setColor(mButt,0,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked04(){setColor(mButt,0,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked05(){setColor(mButt,0,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked10(){setColor(mButt,1,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked11(){setColor(mButt,1,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked12(){setColor(mButt,1,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked13(){setColor(mButt,1,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked14(){setColor(mButt,1,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked15(){setColor(mButt,1,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked20(){setColor(mButt,2,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked21(){setColor(mButt,2,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked22(){setColor(mButt,2,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked23(){setColor(mButt,2,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked24(){setColor(mButt,2,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked25(){setColor(mButt,2,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked30(){setColor(mButt,3,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked31(){setColor(mButt,3,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked32(){setColor(mButt,3,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked33(){setColor(mButt,3,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked34(){setColor(mButt,3,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked35(){setColor(mButt,3,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked40(){setColor(mButt,4,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked41(){setColor(mButt,4,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked42(){setColor(mButt,4,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked43(){setColor(mButt,4,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked44(){setColor(mButt,4,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked45(){setColor(mButt,4,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked50(){setColor(mButt,5,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked51(){setColor(mButt,5,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked52(){setColor(mButt,5,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked53(){setColor(mButt,5,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked54(){setColor(mButt,5,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked55(){setColor(mButt,5,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked60(){setColor(mButt,6,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked61(){setColor(mButt,6,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked62(){setColor(mButt,6,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked63(){setColor(mButt,6,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked64(){setColor(mButt,6,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked65(){setColor(mButt,6,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked70(){setColor(mButt,7,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked71(){setColor(mButt,7,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked72(){setColor(mButt,7,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked73(){setColor(mButt,7,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked74(){setColor(mButt,7,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked75(){setColor(mButt,7,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked80(){setColor(mButt,8,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked81(){setColor(mButt,8,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked82(){setColor(mButt,8,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked83(){setColor(mButt,8,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked84(){setColor(mButt,8,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked85(){setColor(mButt,8,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked90(){setColor(mButt,9,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked91(){setColor(mButt,9,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked92(){setColor(mButt,9,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked93(){setColor(mButt,9,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked94(){setColor(mButt,9,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked95(){setColor(mButt,9,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked100(){setColor(mButt,10,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked101(){setColor(mButt,10,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked102(){setColor(mButt,10,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked103(){setColor(mButt,10,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked104(){setColor(mButt,10,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked105(){setColor(mButt,10,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked110(){setColor(mButt,11,0);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked111(){setColor(mButt,11,1);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked112(){setColor(mButt,11,2);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked113(){setColor(mButt,11,3);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked114(){setColor(mButt,11,4);setColor(pre);curColor = newColor;setColorToDefault(cur);}
void MainWindow::gridLayoutClicked115(){setColor(mButt,11,5);setColor(pre);curColor = newColor;setColorToDefault(cur);}

void MainWindow::printH(QColor color){ // LightSkyBlue 135,206,250
    for (int i = 0; i < 7; ++i) {
        setColor(mBut1, i, 0, color);
        setColor(mBut1, i, 3, color);
    }
    setColor(mBut1, 3, 1, color);
    setColor(mBut1, 3, 2, color);
}

void MainWindow::printM(QColor color){ // 255,215,0
    for (int i = 0; i < 7; ++i) {
        setColor(mBut2, i, 0, color);
        setColor(mBut2, i, 3, color);
    }
    for (int i = 1; i < 3; ++i) {        
        setColor(mBut2, 0, i, color);
        setColor(mBut2, 3, i, color);
        setColor(mBut2, 6, i, color);
    }
}

void MainWindow::printP(QColor color){
    for (int i = 0; i < 7; ++i)
        setColor(mBut4, i, 0, color);
    for (int i = 0; i < 4; ++i)
        setColor(mBut4, i, 3, color);
    for (int i = 1; i < 3; ++i) {        
        setColor(mBut4, 0, i, color);
        setColor(mBut4, 3, i, color);
    }
}

void MainWindow::printR(QColor color){
    for (int i = 0; i < 7; ++i) 
        setColor(mBut3, i, 0, color);
    for (int i = 0; i < 4; ++i)
        setColor(mBut3, i, 3, color);
    for (int i = 1; i < 3; ++i) {        
        setColor(mBut3, 0, i, color);
        setColor(mBut3, 3, i, color);
    }
    setColor(mBut3, 4, 1, color);
    setColor(mBut3, 5, 2, color);
    setColor(mBut3, 6, 3, color);
}

void MainWindow::printE(QColor color){
    for (int i = 0; i < 7; ++i) 
        setColor(mBut5, i, 0, color);
    for (int i = 0; i < 4; ++i) {        
        setColor(mBut5, 0, i, color);
        setColor(mBut5, 6, i, color);
    }
    setColor(mBut5, 3, 1, color);
    setColor(mBut5, 3, 2, color);
}

void MainWindow::open() {
    QMessageBox::information(this, tr("Information"), tr("Open"));
}


MainWindow::~MainWindow() {
    // release memory resource: memory leak problem
}
