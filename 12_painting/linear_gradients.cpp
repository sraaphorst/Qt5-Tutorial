/**
 * linear_gradients.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "linear_gradients.h"

#include <QApplication>
#include <QLinearGradient>
#include <QPainter>

LinearGradients::LinearGradients(QWidget *parent)
    : QWidget(parent) {}

void LinearGradients::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e)

    doPainting();
}

void LinearGradients::doPainting() {
    QPainter painter(this);

    QLinearGradient grad1{0, 20, 0, 110};
    grad1.setColorAt(0.1, Qt::black);
    grad1.setColorAt(0.5, Qt::yellow);
    grad1.setColorAt(0.9, Qt::black);
    painter.fillRect(20, 20, 300, 90, grad1);

    QLinearGradient grad2{0, 55, 250, 0};
    grad2.setColorAt(0.2, Qt::black);
    grad2.setColorAt(0.5, Qt::cyan);
    grad2.setColorAt(0.8, Qt::darkRed);
    painter.fillRect(20, 140, 300, 100, grad2);
}

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};

    LinearGradients window;
    window.setWindowTitle("Linear Gradients");
    window.resize(350, 260);
    window.setVisible(true);

    return app.exec();
}