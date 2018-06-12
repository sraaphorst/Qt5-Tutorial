/**
 * transparent_rectangles.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QApplication>
#include <QPainter>
#include <QPainterPath>

#include "transparent_rectangles.h"

TransparentRectangles::TransparentRectangles(QWidget *parent)
    : QWidget(parent) {}

void TransparentRectangles::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    doPainting();
}

void TransparentRectangles::doPainting() {
    QPainter painter(this);

    for (int i=0; i <= 10; ++i) {
        painter.setOpacity(i * 0.1);
        painter.fillRect(50 * (i + 1), 20, 40, 40, Qt::darkGray);
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TransparentRectangles window;
    window.setWindowTitle("Transparent Rectangles");
    window.resize(630, 90);
    window.setVisible(true);

    return app.exec();
}
