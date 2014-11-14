#include <QApplication>
#include <QTextEdit>
#include <QSplitter>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <cstring>
#include <iostream>
#include "myGridLayout.h"

#include "buttons.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // for buttons for final
    Buttons button;
    button.resize(290, 170);
    button.move(300, 300);  
    button.setWindowTitle("Tower iLLuminati");
    button.show();
    return app.exec();
}
