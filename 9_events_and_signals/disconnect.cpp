/**
 * disconnect.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "disconnect.h"

#include <QApplication>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QTextStream>

Disconnect::Disconnect(QWidget *parent)
    : QWidget(parent) {

    auto hbox = new QHBoxLayout(this);
    hbox->setSpacing(5);

    button = new QPushButton("Click");
    hbox->addWidget(button, 0, Qt::AlignLeft | Qt::AlignTop);

    auto cb = new QCheckBox("Connect");
    cb->setCheckState(Qt::Checked);
    hbox->addWidget(cb, 0, Qt::AlignLeft | Qt::AlignTop);

    connect(button, &QPushButton::clicked, this, &Disconnect::onClick);
    connect(cb, &QCheckBox::stateChanged, this, &Disconnect::onCheck);
}

void Disconnect::onClick() {
    QTextStream out { stdout };
    out << "Button clicked" << endl;
}

void Disconnect::onCheck(int state) {
    if (state == Qt::Checked)
        connect(button, &QPushButton::clicked, this, &Disconnect::onClick);
    else
        disconnect(button, &QPushButton::clicked, this, &Disconnect::onClick);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Disconnect window;
    window.setWindowTitle("Disconnect");
    window.resize(250, 150);
    window.show();

    return app.exec();
}