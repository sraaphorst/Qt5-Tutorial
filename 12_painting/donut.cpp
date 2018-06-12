/**
 * donut.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "donut.h"

#include <QApplication>
#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QTextStream>

Donut::Donut(QWidget *parent)
    : QWidget(parent) {}

void Donut::resizeEvent(QResizeEvent *e) {
    QWidget::resizeEvent(e);
    QTextStream out{ stdout };
    auto oldSize = e->oldSize();
    auto newSize = e->size();
    out << "Dimension was: (" << oldSize.width() << "," << oldSize.height() << ")"
        << ", now: (" << newSize.width() << "," << newSize.height() << ")"  << endl;

}
void Donut::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e)

    doPainting();
}

void Donut::doPainting() {
    QPainter painter { this };

    // The supplied brush is used to fill strokes generated with the pen.
    painter.setPen(QPen{QBrush{"#535353"}, 0.5});
    painter.setRenderHint(QPainter::Antialiasing);

    int x = width();
    int y = height();
    // Translate the coordinate system into the middle of the window.
    painter.translate(QPoint{x / 2, y / 2});

    for (auto rot=0; rot < 360; rot += 5) {
        painter.drawEllipse(-125, -40, 250, 80);
        painter.rotate(5.0);
    }
}

int main(int argc, char *argv[]) {
    QApplication app { argc, argv };

    Donut window;
    window.setWindowTitle("Donut");
    window.resize(280, 280);
    window.setVisible(true);

    return app.exec();
}