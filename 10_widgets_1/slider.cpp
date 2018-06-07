/**
 * slider.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "slider.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>

Slider::Slider(QWidget *parent)
    : QWidget(parent) {

    auto vbox = new QVBoxLayout(this);

    auto hbox = new QHBoxLayout;
    auto hslider = new QSlider(Qt::Horizontal);
    hbox->addWidget(hslider);
    auto hlabel = new QLabel("0");
    hbox->addWidget(hlabel);

    vbox->addLayout(hbox);
    auto vslider = new QSlider(Qt::Vertical);
    vslider->setRange(-50, 50);
    vslider->setValue(0);
    vbox->addWidget(vslider, 0, Qt::AlignCenter | Qt::AlignTop);
    auto vlabel = new QLabel("0");
    vbox->addWidget(vlabel, 0, Qt::AlignCenter | Qt::AlignTop);

    // Use static cast because setNum is an overloaded method.
    connect(hslider, &QSlider::valueChanged, hlabel, static_cast<void(QLabel::*)(int)>(&QLabel::setNum));
    connect(vslider, &QSlider::valueChanged, vlabel, static_cast<void(QLabel::*)(int)>(&QLabel::setNum));
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Slider window;
    window.setWindowTitle("QSlider");
    window.show();

    return app.exec();
}