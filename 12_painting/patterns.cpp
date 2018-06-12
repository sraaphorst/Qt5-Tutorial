/**
 * patterns.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QApplication>
#include <QBrush>
#include <QPainter>
#include <QVector>

#include "patterns.h"

Patterns::Patterns(QWidget *parent)
    : QWidget(parent) {}

void Patterns::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    doPainting();
}

void Patterns::doPainting() {
    QPainter painter(this);
    painter.setPen(Qt::NoPen);

    QVector<QVector<Qt::BrushStyle>> brushStyles = {
            {Qt::HorPattern, Qt::VerPattern, Qt::CrossPattern},
            {Qt::Dense7Pattern, Qt::Dense6Pattern, Qt::Dense5Pattern},
            {Qt::BDiagPattern, Qt::FDiagPattern, Qt::DiagCrossPattern}
    };

    for (auto i=0; i < 3; ++i)
        for (auto j=0; j < 3; ++j)
            painter.fillRect(10 + 120 * j, 15 + 90 * i, 90, 60, brushStyles[i][j]);
}

int main(int argc, char *argv[]) {
    QApplication app { argc, argv };

    Patterns window;
    window.setWindowTitle("Patterns");
    window.resize(350, 280);
    window.setVisible(true);

    return app.exec();
}