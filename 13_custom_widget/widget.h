/**
 * widget.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QFrame>

class Burning;

class Widget : public QFrame {
public:
    Widget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e) override;
    void drawWidget(QPainter &qp);

private:
    QWidget *m_parent;

    static constexpr int DISTANCE = 19;
    static constexpr int LINE_WIDTH = 5;
    static constexpr int DIVISIONS = 10;
    static constexpr float FULL_CAPACITY = 700.0;
    static constexpr float MAX_CAPACITY = 750.0;
};


