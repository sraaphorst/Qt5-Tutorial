/**
 * shapes.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "shapes.h"

#include <QApplication>
#include <QBrush>
#include <QFont>
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QPoint>
#include <QPointF>
#include <QPolygon>


Shapes::Shapes(QWidget *parent)
    : QWidget(parent) {}

void Shapes::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e)

    doPainting();
}

void Shapes::doPainting() {
    QPainter painter{this};
    QBrush brush{"#888"};
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen{brush, 1});
    painter.setBrush(brush);

    QPainterPath path1;
    path1.moveTo(5, 5);
    path1.cubicTo(40, 5, 50, 50, 99, 99);
    path1.cubicTo(5, 99, 50, 50, 5, 5);
    painter.drawPath(path1);

    painter.drawPie(130, 20, 90, 60, 30*16, 120*16);
    painter.drawChord(240, 30, 90, 60, 0, 16*180);
    painter.drawRoundRect(20, 120, 80, 50);

    QPolygon polygon{{QPoint{130, 140}, QPoint{180, 170}, QPoint{180, 140},
                     QPoint{220, 110}, QPoint{140, 100}}};
    painter.drawPolygon(polygon);

    painter.drawRect(250, 110, 60, 60);

    // THIS is what we will want for mazes: floating point position in plane!
    QPointF baseline{20, 250};
    QFont font{"Georgia", 55};
    QPainterPath path2;
    path2.addText(baseline, font, "æ");
    painter.drawPath(path2);

    // First two coords are top left of bounding box.
    painter.drawEllipse(140, 200, 60, 60);
    painter.drawEllipse(240, 200, 90, 60);
}

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};

    Shapes window;
    window.setWindowTitle("Shapes");
    window.resize(350, 280);
    window.setVisible(true);

    return app.exec();
}