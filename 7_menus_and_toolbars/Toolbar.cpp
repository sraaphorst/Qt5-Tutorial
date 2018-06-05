/**
 * Toolbar.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "Toolbar.h"

#include <QAction>
#include <QIcon>
#include <QPixmap>
#include <QToolBar>

Toolbar::Toolbar(QWidget *parent)
    : QMainWindow(parent) {
    QPixmap newIcon("resources/new.png");
    QPixmap openIcon("resources/open.png");
    QPixmap quitIcon("resources/quit.png");

    QToolBar *toolBar = addToolBar("main toolbar");
    toolBar->addAction(QIcon(newIcon), "New File");
    toolBar->addAction(QIcon(openIcon), "Open File");
    toolBar->addSeparator();
    QAction *quit = toolBar->addAction(QIcon(quitIcon), "Quit Application");

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Toolbar tb;
    tb.resize(300, 200);
    tb.setWindowTitle("QToolBar");
    tb.show();

    return app.exec();
}