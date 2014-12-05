#include <QApplication>
#include <QGridLayout>
#include <QWidget>
#include <QSplitter>
#include <QTextEdit>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>

#include "mainwindow.h"
//#include "popwindow.h"
//#include "myGridLayout.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();
      
/*
    PopWindow window;
    window.show();

      // for .wav graphics
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    QGraphicsView view2(&scene);
    QGraphicsPixmapItem item(QPixmap(":/images/waveI"));
    //QGraphicsPixmapItem item2(QPixmap(":/images/h"));
    scene.addItem(&item);
    //scene.addItem(&item2);
    view.show();

    // try to work on MyPushButton only
    int mRow = 10;
    int mCol = 4;
    MyPushButton* ptrBtn[mRow][mCol];
    QGridLayout grid;// = new QGridLayout;
    //grid.addWidget(ptrBtn);
    
    for (int i = 0; i < mRow; ++i) {
        for (int j = 0; j < mRow; ++j) {
            grid.addWidget((QWidget*)ptrBtn[i][j]);
            ptrBtn[i][j]->setLocation(i, j);
            //QObject::connect(&ptrBtn[i][j], )
            //setButtonSize(22, 32);
        }
    }

    // worked
    MyGridLayout* myptr = new MyGridLayout();
    QWidget *container = new QWidget;
    QSplitter *split1 = new QSplitter;
    QTextEdit *editor2 = new QTextEdit;
    QTextEdit *editor1 = new QTextEdit;
    split1->addWidget(editor1);
    split1->addWidget(editor2);
    QVBoxLayout *container_layout = new QVBoxLayout;
    container_layout->addWidget(split1);
    container->setLayout(container_layout);
    */

    /*
    QWidget *container = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *container_layout = new QVBoxLayout;
    QSplitter *split1 = new QSplitter;
    QTextEdit *editor2 = new QTextEdit;
    split1->addWidget(myptr);
    split1->addWidget(editor2);
    container_layout->addWidget(split1);
    container->setLayout(container_layout);
    */
    /*
      PopWindow window0;
      window0.show();
    */

    return app.exec();
}
