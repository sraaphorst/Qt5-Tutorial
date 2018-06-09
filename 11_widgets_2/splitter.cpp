/**
 * splitter.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "splitter.h"

#include <QApplication>
#include <QFrame>
#include <QHBoxLayout>
#include <QSplitter>

Splitter::Splitter(QWidget *parent)
    : QWidget(parent) {

    auto hbox = new QHBoxLayout(this);

    auto topLeft = new QFrame;
    topLeft->setFrameShape(QFrame::StyledPanel);

    auto topRight = new QFrame;
    topRight->setFrameShape(QFrame::StyledPanel);

    auto splitter1 = new QSplitter(Qt::Horizontal);
    splitter1->addWidget(topLeft);
    splitter1->addWidget(topRight);

    auto bottom = new QFrame;
    bottom->setFrameShape(QFrame::StyledPanel);

    auto splitter2 = new QSplitter(Qt::Vertical);
    splitter2->addWidget(splitter1);
    splitter2->addWidget(bottom);

    QList<int> sizes{50, 100};
    splitter2->setSizes(sizes);

    hbox->addWidget(splitter2);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Splitter window;
    window.setWindowTitle("QSplitter");
    window.resize(300, 300);
    window.show();

    return app.exec();
}