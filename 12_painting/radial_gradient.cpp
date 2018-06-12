/**
 * radial_gradient.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "radial_gradient.h"

#include <QApplication>
#include <QColor>
#include <QPainter>
#include <QRadialGradient>

RadialGradient::RadialGradient(QWidget *parent)
    : QWidget(parent) {}

void RadialGradient::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e)

    doPainting();
}

void RadialGradient::doPainting() {
    QPainter painter{this};

    auto h = height();
    auto w = width();

    auto color = QColor{"#032E91"};
    QRadialGradient grad{w/2.0, h/2.0, qMax(h, w) * 1.0};
    grad.setColorAt(0, color);
    grad.setColorAt(0.3, Qt::white);
    grad.setColorAt(1, color);

    painter.fillRect(0, 0, w, h, grad);
}

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};

    RadialGradient window;
    window.setWindowTitle("Radial Gradient");
    window.resize(300, 250);
    window.setVisible(true);

    return app.exec();
}