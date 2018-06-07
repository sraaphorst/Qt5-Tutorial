/**
 * keypress.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "keypress.h"

#include <QApplication>
#include <QKeyEvent>
#include <QTextStream>

KeyPress::KeyPress(QWidget *parent)
    : QWidget(parent), str{stdout} {
}

void KeyPress::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Escape)
        qApp->quit();
    str << static_cast<char>(e->key());
    str.flush();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    KeyPress window;
    window.resize(250, 150);
    window.setWindowTitle("Key Press");
    window.show();

    return app.exec();
}