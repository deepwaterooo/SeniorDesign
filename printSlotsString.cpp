#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    /*
    for (int i = 0; i < 20; ++i)
        for (int j = 6; j < 12; ++j )
            cout << "void MainWindow::gridLayoutClicked" << i << j << "(){setColor(mButt," << i << "," << j << ");setColor(pre);curColor = newColor;setColorToDefault(cur);}" << endl;
    for (int i = 12; i < 20; ++i)
        for (int j = 0; j < 6; ++j )
            cout << "void MainWindow::gridLayoutClicked" << i << j << "(){setColor(mButt," << i << "," << j << ");setColor(pre);curColor = newColor;setColorToDefault(cur);}" << endl;

    for (int i = 0; i < 20; ++i)
        for (int j = 6; j < 12; ++j )
            cout << "void gridLayoutClicked" << i << j << "();" << endl;
    for (int i = 12; i < 20; ++i)
        for (int j = 0; j < 6; ++j )
            cout << "void gridLayoutClicked" << i << j << "();" << endl;
    */

    for (int i = 0; i < 20; ++i)
        for (int j = 6; j < 12; ++j )
            cout << "connect(mButt[" << i << "][" << j << "], SIGNAL(released()), this, SLOT(gridLayoutClicked" << i << j << "()));" << endl;
    for (int i = 12; i < 20; ++i)
        for (int j = 0; j < 6; ++j )
            cout << "connect(mButt[" << i << "][" << j << "], SIGNAL(released()), this, SLOT(gridLayoutClicked" << i << j << "()));" << endl;

    return 0;
}

