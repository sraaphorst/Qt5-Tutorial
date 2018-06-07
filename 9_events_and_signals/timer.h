/**
 * timer.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>
#include <QLabel>

class Timer : public QWidget {
public:
    Timer(QWidget *parent = nullptr);

protected:
    void timerEvent(QTimerEvent *e) override;

private slots:
    void toggleTimer(int state);

private:
    QLabel *label;
    int timerId;
};




