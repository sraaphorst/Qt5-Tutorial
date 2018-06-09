/**
 * toolbar.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "toolbar.h"

#include <QAction>
#include <QIcon>
#include <QPixmap>
#include <QToolbar>

ToolBar::ToolBar(QWidget *parent)
    : QMainWindow(parent) {
    QPixmap newIcon("resources/new.png");
    QPixmap openIcon("resources/open.png");
    QPixmap quitIcon("resources/quit.png");

    auto Toolbar = addToolBar("main Toolbar");
    Toolbar->addAction(QIcon(newIcon), "New File");
    Toolbar->addAction(QIcon(openIcon), "Open File");
    Toolbar->addSeparator();
    auto quit = Toolbar->addAction(QIcon(quitIcon), "Quit Application");

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ToolBar tb;
    tb.resize(300, 200);
    tb.setWindowTitle("QToolbar");
    tb.show();

    return app.exec();
}