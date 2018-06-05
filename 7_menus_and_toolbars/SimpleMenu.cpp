/**
 * SimpleMenu.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QTextStream>
#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>

class SimpleMenu : public QMainWindow {
public:
    explicit SimpleMenu(QWidget *parent = 0);

private slots:
    void testme() {
        QTextStream out { stdout };
        out << "Don't test me, boy!" << endl;
    };
};

SimpleMenu::SimpleMenu(QWidget *parent)
        : QMainWindow(parent) {

    /** NOTE: Qt5 for OS X suppresses the quit action, and even from the file menu! **/
    QAction *quit = new QAction("&Quitters!", this);

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(quit);
    connect(quit, &QAction::triggered, qApp, QApplication::quit);
    file->addAction(new QAction("Squatting", this));

    QAction *copy = new QAction("&Copy", this);
    QMenu *edit = menuBar()->addMenu("&Edit");
    edit->addAction(copy);
    connect(copy, &QAction::triggered, this, &SimpleMenu::testme);
}

int main(int argv, char *argc[]) {
    QApplication app(argv, argc);

    SimpleMenu window;
    window.resize(250, 150);
    window.setWindowTitle("Simple Menu");
    window.show();

    return app.exec();
}