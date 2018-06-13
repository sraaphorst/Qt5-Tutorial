/**
 * burning.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QHBoxLayout>
#include <QSlider>
#include <QVBoxLayout>

#include "burning.h"

Burning::Burning(QWidget *parent)
    : QFrame(parent) {

    initUI();
}

void Burning::initUI() {

    constexpr int MAX_VALUE = 750;
    cur_width = 0;

    slider = new QSlider(Qt::Horizontal, this);
    slider->setMaximum(MAX_VALUE);
    slider->setGeometry(50, 50, 130, 30);
    connect(slider, &QSlider::valueChanged, this, &Burning::valueChanged);

    auto *hbox = new QHBoxLayout;
    widget = new Widget(this);  // TODO: do we need this here? I think so.
    hbox->addWidget(widget, 0); // 0 stretch

    auto *vbox = new QVBoxLayout(this);
    vbox->addStretch(1);
    vbox->addLayout(hbox);

    setLayout(vbox);
}

void Burning::valueChanged(int val) {
    cur_width = val;
    widget->repaint();
}

int Burning::getCurrentWidth() {
    return cur_width;
};