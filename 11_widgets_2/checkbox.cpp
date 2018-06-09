/**
 * checkbox.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "checkbox.h"

#include <QApplication>
#include <QCheckBox>
#include <QHBoxLayout>

CheckBox::CheckBox(QWidget *parent)
    : QWidget(parent) {

    auto hbox = new QHBoxLayout(this);

    auto *cb = new QCheckBox("Show Title");
    cb->setChecked(Qt::Checked);
    hbox->addWidget(cb, 0, Qt::AlignLeft | Qt::AlignTop);

    connect(cb, &QCheckBox::stateChanged, this, &CheckBox::showTitle);
}

void CheckBox::showTitle(int state) {
    setWindowTitle(state == Qt::Checked ? "QCheckBox" : "");
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CheckBox window;
    window.resize(250, 150);
    window.setWindowTitle("QCheckBox");
    window.show();

    return app.exec();
}