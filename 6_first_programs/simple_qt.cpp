/**
 * simple.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QApplication>
#include <QIcon>
#include <QWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.resize(250, 150);
    window.move(300, 300);
    window.setWindowTitle("Simple example");
    window.setToolTip("QWidget");
    window.setWindowIcon(QIcon("Alex.png"));

    window.show();

    return app.exec();
}