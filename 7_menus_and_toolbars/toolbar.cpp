/**
 * toolbar.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "toolbar.h"

#include <QAction>
#include <QIcon>
#include <QPixmap>
#include <QStatusBar>
#include <QToolbar>
#include <QWhatsThis>

ToolBar::ToolBar(QWidget *parent)
    : QMainWindow(parent) {
    QPixmap newIcon("resources/new.png");
    QPixmap openIcon("resources/open.png");
    QPixmap quitIcon("resources/quit.png");

    auto Toolbar = addToolBar("main Toolbar");

    auto newFile = Toolbar->addAction(QIcon(newIcon), tr("&New File"));
    newFile->setWhatsThis(tr("This is a button that allows the user to open a new file."));

    auto openFile = Toolbar->addAction(QIcon(openIcon), tr("&Open File"));
    openFile->setWhatsThis(tr("This is a button that allows the user to open an existing file."));

    Toolbar->addSeparator();

    auto quitApp = Toolbar->addAction(QIcon(quitIcon), tr("&Quit Application"));
    quitApp->setWhatsThis(tr("Quit the application"));

    Toolbar->addSeparator();
    Toolbar->addAction(QWhatsThis::createAction());

    statusBar()->showMessage("Ready");

    connect(newFile, &QAction::triggered, this, &ToolBar::newFileClicked);
    connect(openFile, &QAction::triggered, this, &ToolBar::openFileClicked);
    connect(quitApp, &QAction::triggered, qApp, &QApplication::quit);
}

void ToolBar::newFileClicked() {
    statusBar()->showMessage("Opening new file...", 2000);
}

void ToolBar::openFileClicked() {
    statusBar()->showMessage("Opening file...", 2000);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ToolBar tb;
    tb.resize(300, 200);
    tb.setWindowTitle("QToolbar");
    tb.show();

    return app.exec();
}