/**
 * styles.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <QApplication>
#include <QStyleFactory>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include "styles.h"

Styles::Styles(QWidget *parent)
    : QWidget(parent) {

    auto *vbox = new QVBoxLayout(this);

    auto *hbox = new QHBoxLayout;
    vbox->addLayout(hbox);

    auto *combo = new QComboBox;
    QStringList items { "Item1", "Item2", "Item3" };
    combo->addItems(items);
    hbox->addWidget(combo);
    hbox->addSpacing(40);

    auto *label = new QLabel("Which?");
    hbox->addWidget(label);
    connect(combo, static_cast<void(QComboBox::*)(const QString&)>(&QComboBox::activated), label, &QLabel::setText);

    auto *button = new QPushButton("Push it");
    vbox->addWidget(button);
    connect(button, &QPushButton::clicked, qApp, &QApplication::quit);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette p;
    p = qApp->palette();
    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    p.setColor(QPalette::WindowText, QColor(0xff,0xff,0xff));
    p.setColor(QPalette::Text, QColor(0xff,0xff,0xff));

    qApp->setPalette(p);

    Styles window;
    window.resize(400, 300);
    window.setWindowTitle("Lallala");
    window.setVisible(true);

    return app.exec();
}