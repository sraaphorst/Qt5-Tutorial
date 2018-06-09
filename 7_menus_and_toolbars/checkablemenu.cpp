/**
 * CheckableMenu.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

#include "checkablemenu.h"

CheckableMenu::CheckableMenu(QWidget *parent)
    : QMainWindow(parent) {
    viewst = new QAction("&View status bar", this);
    viewst->setCheckable(true);
    viewst->setChecked(true);

    auto file = menuBar()->addMenu("&File");
    file->addAction(viewst);

    statusBar();

    connect(viewst, &QAction::triggered, this, &CheckableMenu::toggleStatusBar);
}

void CheckableMenu::toggleStatusBar() {
    statusBar()->setVisible(viewst->isChecked());
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CheckableMenu w;
    w.resize(250, 150);
    w.setWindowTitle("Checkable Menu");
    w.show();

    return app.exec();
}