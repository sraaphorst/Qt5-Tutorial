/**
 * progressbar.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QTimer>

class ProgressBar : public QWidget {

    Q_OBJECT

public:
    explicit ProgressBar(QWidget *parent = nullptr);

private:
    int progress;
    QTimer *timer;
    QProgressBar *pbar;
    QPushButton *start;
    QPushButton *stop;
    QPushButton *reset;

    static constexpr auto DELAY = 50;
    static constexpr auto MAX_VALUE = 100;

    void updateBar();
    void startMyTimer();
    void stopMyTimer();
    void resetBar();
};


