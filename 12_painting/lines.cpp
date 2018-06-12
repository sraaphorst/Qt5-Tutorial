/**
 * lines.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "lines.h"

#include <QApplication>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>
#include <QVector>

Lines::Lines(QWidget *parent)
    : QWidget(parent) {
}

void Lines::paintEvent(QPaintEvent *event) {
    // Suppress compiler warnings.
    Q_UNUSED(event);

    QPainter qp(this);
    drawLines(&qp);
}

void Lines::drawLines(QPainter *qp) {
    QVector<Qt::PenStyle> penStyles{Qt::SolidLine, Qt::DashLine, Qt::DashDotLine, Qt::DotLine, Qt::DashDotDotLine};

    auto i = 40;
    for (auto style: penStyles) {
        QPen pen{Qt::black, 2, style};
        qp->setPen(pen);
        qp->drawLine(20, i, 250, i);
        i += 40;
    }

    QVector<qreal> dashes;
    qreal space = 4;
    dashes << 1 << space << 5 << space;
    QPen pen(Qt::black, 2, Qt::CustomDashLine);
    pen.setDashPattern(dashes);
    qp->setPen(pen);
    qp->drawLine(20, 240, 250, 240);
}

#include <QDebug>
#include <QStyleFactory>
int main(int argc, char *argv[]) {
    qDebug() << QStyleFactory::keys();
    QApplication app{argc, argv};

    Lines window;
    window.setWindowTitle("Lines");
    window.resize(280, 270);
    window.show();

    return QApplication::exec();
}