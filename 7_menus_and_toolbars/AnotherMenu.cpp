/**
 * AnotherMenu.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QAction>
#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPixmap>

/** NOTE THAT MAC OS X THROWS QUIT IN THE PROGRAM MENU, BUT WITH THE ICON! **/
class AnotherMenu : public QMainWindow {
public:
    AnotherMenu(QWidget *parent = nullptr);
};

AnotherMenu::AnotherMenu(QWidget *parent)
    : QMainWindow(parent ){

    QPixmap newIcon("resources/new.png");
    QPixmap openIcon("resources/open.png");
    QPixmap quitIcon("resources/quit.png");

    QAction *newA  = new QAction(newIcon,  "&New",  this);
    QAction *openA = new QAction(openIcon, "&Open", this);
    QAction *quitA = new QAction(quitIcon, "&Quit", this);
    quitA->setShortcut(tr("CTRL+Q"));

    QMenu *file = menuBar()->addMenu("&File");
    file->addAction(newA);
    file->addAction(openA);
    file->addSeparator();
    file->addAction(quitA);

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);
    connect(quitA, &QAction::triggered, qApp, &QApplication::quit);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    AnotherMenu m;
    m.resize(350, 200);
    m.setWindowTitle("More goodies");
    m.show();

    return app.exec();
}