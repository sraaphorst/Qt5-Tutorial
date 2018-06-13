/**
 * burning.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QHBoxLayout>
#include <QSlider>
#include <QVBoxLayout>

#include "burning_widget.h"

BurningWidget::BurningWidget(QWidget *parent)
    : QFrame(parent) {

    initUI();
}

void BurningWidget::initUI() {

    constexpr int MAX_VALUE = 750;
    cur_width = 0;

    auto slider = new QSlider{Qt::Horizontal, this};
    slider->setMaximum(MAX_VALUE);
    slider->setGeometry(50, 50, 130, 30);
    connect(slider, &QSlider::valueChanged, this, &BurningWidget::valueChanged);

    auto *hbox = new QHBoxLayout;
    widget = new BurningScale{this};
    hbox->addWidget(widget, 0); // 0 stretch

    auto *vbox = new QVBoxLayout{this};
    vbox->addStretch(1);
    vbox->addLayout(hbox);

    setLayout(vbox);
}

void BurningWidget::valueChanged(int val) {
    cur_width = val;
    widget->repaint();
}

int BurningWidget::getCurrentWidth() {
    return cur_width;
};