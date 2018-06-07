/**
 * MySkeleton.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QAction>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QStaticArrayData>
#include <QStatusBar>
#include <QTextEdit>
#include <QToolBar>

#include "myskeleton.h"

MySkeleton::MySkeleton(QWidget *parent)
    : QMainWindow(parent) {
    QIcon newIcon{QPixmap{"resources/new.png"}};
    QIcon openIcon{QPixmap{"resources/open.png"}};
    QIcon quitIcon{QPixmap{"resources/quit.png"}};

    QMenu *file = menuBar()->addMenu("&File");

    QAction *quit = new QAction(quitIcon, "&Quit", this);
    file->addAction(quit);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    QToolBar *toolbar = addToolBar("main toolbar");
    toolbar->addAction(newIcon, "New File");
    toolbar->addAction(openIcon, "Open File");
    toolbar->addSeparator();
    toolbar->addAction(quit);

    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);

    statusBar()->showMessage("Ready");
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MySkeleton w;
    w.resize(350, 250);
    w.setWindowTitle("Application Skeleton");
    w.show();

    return app.exec();
}