/**
 * combobox.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "combobox.h"

#include <QApplication>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>

ComboBoxEx::ComboBoxEx(QWidget *parent)
    : QWidget(parent) {

    QStringList distros { "Arch", "Xubuntu", "Redhat", "Debian", "Mandriva" };

    auto hbox = new QHBoxLayout(this);

    auto combo = new QComboBox;
    combo->addItems(distros);
    hbox->addWidget(combo);
    hbox->addSpacing(15);

    auto label = new QLabel("Arch");
    hbox->addWidget(label);

    connect(combo, static_cast<void(QComboBox::*)(const QString&)>(&QComboBox::activated), label, &QLabel::setText);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ComboBoxEx window;
    window.resize(300, 150);
    window.setWindowTitle("QComboBox");
    window.show();

    return app.exec();
}