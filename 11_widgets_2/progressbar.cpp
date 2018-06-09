/**
 * progressbar.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "progressbar.h"

#include <QApplication>
#include <QProgressBar>
#include <QTimer>
#include <QGridLayout>

ProgressBar::ProgressBar(QWidget *parent)
    : QWidget(parent) {

    progress = 0;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ProgressBar::updateBar);

    // *** Give column 3 a stretch of 1 ***
    auto grid = new QGridLayout(this);
    grid->setColumnStretch(3, 1);

    // Position (0,0), span 1 row and 4 cols.
    pbar = new QProgressBar;
    pbar->setRange(0, MAX_VALUE);
    grid->addWidget(pbar, 0, 0, 1, 4);

    start = new QPushButton("Start");
    grid->addWidget(start, 1, 0);
    connect(start, &QPushButton::clicked, this, &ProgressBar::startMyTimer);

    stop = new QPushButton("Stop");
    stop->setEnabled(false);
    grid->addWidget(stop, 1, 1);
    connect(stop, &QPushButton::clicked, this, &ProgressBar::stopMyTimer);

    reset = new QPushButton("Reset");
    reset->setEnabled(false);
    grid->addWidget(reset, 1, 2);
    connect(reset, &QPushButton::clicked, this, &ProgressBar::resetBar);
}

void ProgressBar::startMyTimer() {
    if (progress >= MAX_VALUE) {
        progress = 0;
        pbar->setValue(0);
    }

    // If the timer is not active, start it: hence why we disable start and enable stop.
    if (!timer->isActive()) {
        start->setEnabled(false);
        stop->setEnabled(true);
        timer->start(DELAY);
    }
}

void ProgressBar::stopMyTimer() {
    if (timer->isActive()) {
        start->setEnabled(true);
        stop->setEnabled(false);
        timer->stop();
    }
}

void ProgressBar::updateBar() {
    ++progress;

    if (progress <= MAX_VALUE) {
        pbar->setValue(progress);
        reset->setEnabled(true);
    } else {
        timer->stop();
        start->setEnabled(false);
        stop->setEnabled(false);
    }
}

void ProgressBar::resetBar() {
    timer->stop();
    pbar->reset();
    start->setEnabled(true);
    stop->setEnabled(false);
    reset->setEnabled(false);
    progress = 0;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ProgressBar window;
    window.setWindowTitle("QProgressBar");
    window.resize(250, 150);
    window.show();

    return app.exec();
}
