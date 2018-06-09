/**
 * nesting.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "nesting.h"

#include <algorithm>
#include <QApplication>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>

Nesting::Nesting(QWidget *parent)
    : QWidget(parent) {

    QVector<QString> movies {
        "The Omen",
        "The Exorcist",
        "Notes on a Scandal",
        "Fargo",
        "Capote"
    };
    std::sort(movies.begin(), movies.end());

    auto lw = new QListWidget;
    std::for_each(movies.begin(), movies.end(), [lw](const auto s) { lw->addItem(s); });

    auto vbox = new QVBoxLayout;
    vbox->setSpacing(3);
    vbox->addStretch(1);

    QVector<QString> labels {
        "Add",
        "Rename",
        "Remove",
        "Remove All"
    };
    QVector<QPushButton*> buttons;
    buttons.reserve(labels.size());
    std::transform(labels.cbegin(), labels.cend(), buttons.begin(), [vbox](const auto s) {
       auto b = new QPushButton(s);
       vbox->addWidget(b);
       return b;
    });

    vbox->addStretch(1);

    auto hbox = new QHBoxLayout;
    hbox->addWidget(lw);
    hbox->addSpacing(15);
    hbox->addLayout(vbox);

    setLayout(hbox);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Nesting window;
    window.setWindowTitle("Nesting Layouts");
    window.show();

    return app.exec();
}