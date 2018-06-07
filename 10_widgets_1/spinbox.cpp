/**
 * spinbox.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "spinbox.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>

SpinBox::SpinBox(QWidget *parent)
    : QWidget(parent) {

    auto hbox = new QHBoxLayout(this);
    hbox->setSpacing(15);

    auto spinBox = new QSpinBox;
    spinBox->setRange(1, 300);
    hbox->addWidget(spinBox, 0, Qt::AlignTop | Qt::AlignLeft);

    auto label = new QLabel("1");
    hbox->addWidget(label, 0, Qt::AlignTop | Qt::AlignLeft);

    hbox->addSpacing(50);

    auto spinBox2 = new QSpinBox;
    spinBox2->setRange(1, 300);
    hbox->addWidget(spinBox2, 0, Qt::AlignTop | Qt::AlignLeft);

    auto label2 = new QLabel("1");
    hbox->addWidget(label2, 0, Qt::AlignTop | Qt::AlignLeft);

    hbox->addStretch(1);

    connect(spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            label, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    connect(spinBox2, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            label2, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    SpinBox window;
    window.resize(250, 150);
    window.setWindowTitle("QSpinBox");
    window.show();

    return app.exec();
}