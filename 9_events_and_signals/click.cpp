/**
 * click.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "click.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>

Click::Click(QWidget *parent)
    : QWidget(parent) {
    auto *hbox = new QHBoxLayout(this);
    hbox->setSpacing(5);

    auto *quitButton = new QPushButton("Quit");
    hbox->addWidget(quitButton, 0, Qt::AlignLeft | Qt::AlignTop);

    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Click window;
    window.setWindowTitle("Click");
    window.show();

    return app.exec();
}