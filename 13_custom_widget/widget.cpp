/**
 * widget.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QtGui>

#include "widget.h"
#include "burning.h"

constexpr int PANEL_HEIGHT = 30;

Widget::Widget(QWidget *parent)
    : QFrame{parent}, m_parent{parent} {
    setMinimumHeight(PANEL_HEIGHT);
}

void Widget::paintEvent(QPaintEvent *e) {
    QPainter qp{this};
    drawWidget(qp);

    QFrame::paintEvent(e);
}

void Widget::drawWidget(QPainter &qp) {
    QString num[] {"75", "150", "225", "300", "375", "450", "525", "600", "675"};
    auto asize = sizeof(num) / sizeof(num[1]);

    QColor redColor{ 255, 175, 175 };
    QColor yellowColor{ 255, 255, 184 };

    auto width = size().width();

    //auto burn = static_cast<Burning*>(m_parent);
    auto burn = (Burning*) m_parent;
    int cur_width = burn->getCurrentWidth();

//    auto step = static_cast<int>(qRound((double) width / DIVISIONS));
//    auto till = static_cast<int>((width / MAX_CAPACITY) * cur_width);
//    auto full = static_cast<int>((width / MAX_CAPACITY) * FULL_CAPACITY);
    auto step = (int) qRound((double) width / DIVISIONS);
    auto till = (int) ((width / MAX_CAPACITY) * cur_width);
    auto full = (int) ((width / MAX_CAPACITY) * FULL_CAPACITY);


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

    QColor grayColor{ 90, 80, 60 };
    qp.setPen(grayColor);

    for (auto i=1; i <= asize; ++i) {
        qp.drawLine(i*step, 0, i*step, LINE_WIDTH);
        QFont newFont = font();
        newFont.setPointSize(7);
        setFont(newFont);

        QFontMetrics metrics(font());
        int w = metrics.width(num[i-1]);
        qp.drawText(i*step - w/2, DISTANCE, num[i-1]);
    }
}