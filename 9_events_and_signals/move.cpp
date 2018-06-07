/**
 * move.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "Move.h"

#include <QApplication>
#include <QMoveEvent>

Move::Move(QWidget *parent)
    : QWidget(parent) {
}

void Move::moveEvent(QMoveEvent *e) {
    auto x = e->pos().x();
    auto y = e->pos().y();

    QString text = QString::number(x) + "," + QString::number(y);
    setWindowTitle(text);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Move window;
    window.resize(250, 150);
    window.setWindowTitle("Move");
    window.show();

    return app.exec();
}