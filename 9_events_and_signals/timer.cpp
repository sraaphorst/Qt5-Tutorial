/**
 * timer.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "timer.h"

#include <QApplication>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QTime>

Timer::Timer(QWidget *parent)
    : QWidget(parent) {

    auto hbox = new QHBoxLayout(this);
    hbox->setSpacing(5);

    label = new QLabel(QTime::currentTime().toString());
    hbox->addWidget(label, 0, Qt::AlignLeft | Qt::AlignTop);

    auto cb = new QCheckBox("Timer active");
    cb->setCheckState(Qt::Checked);
    hbox->addWidget(cb, 0, Qt::AlignLeft | Qt::AlignTop);
    connect(cb, &QCheckBox::stateChanged, this, &Timer::toggleTimer);

    // NOTE: Every 1000 ms, an event is generated!
    timerId = startTimer(1000);
}

void Timer::toggleTimer(int state) {
    if (state == Qt::Unchecked)
        killTimer(timerId);
    else
        timerId = startTimer(1000);
}

void Timer::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e)

    label->setText(QTime::currentTime().toString());
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Timer window;
    window.setWindowTitle("Timer");
    window.resize(250, 150);
    window.show();

    return app.exec();
}