/**
 * widget.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <cassert>
#include <QtGui>

#include "burning_scale.h"
#include "burning_widget.h"

const QColor BurningScale::redColor{ 255, 175, 175 };
const QColor BurningScale::yellowColor{ 255, 255, 184 };
const QColor BurningScale::grayColor{ 90, 80, 60 };
const QStringList BurningScale::labels {"75", "150", "225", "300", "375", "450", "525", "600", "675"};

BurningScale::BurningScale(BurningWidget *parent)
    : QFrame{parent}, burning{parent} {
    assert(burning != nullptr);
    setMinimumHeight(PANEL_HEIGHT);
}

void BurningScale::paintEvent(QPaintEvent *e) {
    QPainter qp{this};
    drawWidget(qp);

    QFrame::paintEvent(e);
}

void BurningScale::drawWidget(QPainter &qp) {
    auto width = size().width();
    auto cur_width = burning->getCurrentWidth();
    auto step = qRound((double) width / DIVISIONS);
    auto till = static_cast<int>((width / MAX_CAPACITY) * cur_width);
    auto full = static_cast<int>((width / MAX_CAPACITY) * FULL_CAPACITY);


    if (cur_width >= FULL_CAPACITY) {
        qp.setPen(yellowColor);
        qp.setBrush(yellowColor);
        qp.drawRect(0, 0, full, 30);
        qp.setPen(redColor);
        qp.setBrush(redColor);
        qp.drawRect(full, 0, till - full, PANEL_HEIGHT);
    } else if (till > 0) {
        qp.setPen(yellowColor);
        qp.setBrush(yellowColor);
        qp.drawRect(0, 0, till, PANEL_HEIGHT);
    }

    qp.setPen(grayColor);

    for (auto i=0; i < labels.size(); ++i) {
        qp.drawLine((i + 1) * step, 0, (i + 1) * step, LINE_WIDTH);
        QFont newFont{font()};
        newFont.setPointSize(7);
        setFont(newFont);

        QFontMetrics metrics{font()};
        auto w = metrics.width(labels[i]);
        qp.drawText((i + 1) * step - w/2, DISTANCE, labels[i]);
    }
}