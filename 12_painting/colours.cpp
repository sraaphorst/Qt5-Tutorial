/**
 * colours.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QApplication>
#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QVector>

#include "colours.h"

Colours::Colours(QWidget *parent)
    : QWidget(parent) {}

void Colours::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    doPainting();
}

void Colours::doPainting() {
    QPainter painter(this);

    // The pen draws the outlines of shapes.
    painter.setPen(QColor("#d4d4d4"));

    // The brush draws the interior of shapes.
    QVector<QVector<QBrush>> brushes {
            {QBrush("#c56c00"), QBrush("#1ac500"), QBrush("#539e47")},
            {QBrush("#004fc5"), QBrush("#c50024"), QBrush("#9e4757")},
            {QBrush("#5f3b00"), QBrush("#4c4c4c"), QBrush("#785f36")}
    };

    for (auto i=0; i < 3; ++i) {
        for (auto j=0; j < 3; ++j) {
            const auto brush = brushes[i][j];
            //or painter.setBrush(brush); qpainter.drawRect(...);
            painter.fillRect(10 + j * 120, 15 + i * 90, 90, 60, brush);
        }
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Colours window;
    window.setWindowTitle("Colours");
    window.resize(360, 280);
    window.setVisible(true);

    return app.exec();
}