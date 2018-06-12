/**
 * puff.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>

class Puff : public QWidget {
public:
    Puff(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e) override;
    void timerEvent(QTimerEvent *e) override;

private:
    int x;
    qreal opacity;
    int timerId;

    void doPainting();
};


