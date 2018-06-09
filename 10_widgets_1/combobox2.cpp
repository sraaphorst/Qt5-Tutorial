/**
 * combobox2.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "combobox2.h"

#include <QApplication>
#include <QComboBox>
#include <QLabel>
#include <QVariant>
#include <QVBoxLayout>

ComboBoxEx2::ComboBoxEx2(QWidget *parent)
    : QWidget(parent) {

    auto vbox = new QVBoxLayout(this);

    label = new QLabel("<Pick>");
    vbox->addWidget(label, 0, Qt::AlignCenter | Qt::AlignTop);

    combo = new QComboBox;
    combo->addItem("128 m", QVariant(128));
    combo->addItem("256 m", QVariant(256));
    combo->addItem("512 m", QVariant(512));
    vbox->addWidget(combo, 0, Qt::AlignCenter | Qt::AlignTop);
    vbox->addStretch(1);

    connect(combo, static_cast<void(QComboBox::*)(int)>(&QComboBox::activated), this, &ComboBoxEx2::setLabel);
}

void ComboBoxEx2::setLabel(int idx) {
    auto val = combo->itemData(idx).toInt();
    label->setText("Picked: " + QString::number(val));
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ComboBoxEx2 window;
    window.resize(200, 200);
    window.setWindowTitle("QComboBox");
    window.show();

    return app.exec();
}