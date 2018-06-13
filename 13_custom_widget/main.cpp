/**
 * main.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QApplication>
#include "burning.h"

int main(int argc, char *argv[]) {
    QApplication app { argc, argv };

    Burning window;
    window.resize(370, 200);
    window.setWindowTitle("The Burning Widget");
    window.setVisible(true);

    return app.exec();
}