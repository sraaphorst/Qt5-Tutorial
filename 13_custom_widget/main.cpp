/**
 * main.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QApplication>
#include "burning_widget.h"

int main(int argc, char *argv[]) {
    QApplication app { argc, argv };

    BurningWidget window;
    window.resize(370, 200);
    window.setWindowTitle("The BurningWidget");
    window.setVisible(true);

    return app.exec();
}