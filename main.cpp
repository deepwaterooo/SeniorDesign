#include <QApplication>
#include <QTextEdit>
#include <QSplitter>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QPushButton>
#include <QMenuBar>
#include <QLabel>
#include <QPlainTextEdit>
#include <QMainWindow>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QSpinBox>
#include <QSlider>
#include <QObject>
#include <QTimeEdit>
#include <QtGui/QIcon>
#include <QTreeView>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <iostream>
#include <cstring>

//#include "mainwindow.h"
#include "popwindow.h"
#include "colorwheel.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();
    /*
      PopWindow window0;
    window0.show();
    */

    return app.exec();
}
