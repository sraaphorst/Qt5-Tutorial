/**
 * verticalbox.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <algorithm>
#include "verticalbox.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVector>

VerticalBox::VerticalBox(QWidget *parent)
    : QWidget(parent) {

    auto vbox = new QVBoxLayout(this);
    vbox->setSpacing(1);

    QVector<QString> labels {
        "Settings",
        "Accounts",
        "Loans",
        "Cash",
        "Debts"
    };

    QVector<QPushButton*> buttons;
    buttons.reserve(labels.size());
    std::transform(labels.cbegin(), labels.cend(), buttons.begin(), [this, &vbox](const auto str){
       auto b = new QPushButton(str, this);
       b->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
       vbox->addWidget(b);
       return b;
    });

    setLayout(vbox);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    VerticalBox window;
    window.resize(240, 230);
    window.show();

    return app.exec();
}