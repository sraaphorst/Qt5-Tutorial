/**
 * buttons.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "buttons.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>

Buttons::Buttons(QWidget *parent)
    : QWidget(parent) {
    QVBoxLayout *vbox = new QVBoxLayout(this);
    QHBoxLayout *hbox = new QHBoxLayout();

    // addWidget automatically sets the parent, so we don't have to.
    okButton = new QPushButton("OK");
    applyButton = new QPushButton("Apply");

    hbox->addWidget(okButton, 1, Qt::AlignRight);
    hbox->addWidget(applyButton, 0);

    vbox->addStretch(1);

    // addLayout automatically sets the parent.
    vbox->addLayout(hbox);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Buttons window;
    window.resize(290, 170);
    window.show();

    return app.exec();
}