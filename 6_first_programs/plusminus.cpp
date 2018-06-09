/**
 * plusminus.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "plusminus.h"
#include <QGridLayout>

PlusMinus::PlusMinus(QWidget *parent)
    : QWidget(parent) {
    auto plsButton = new QPushButton("+", this);
    auto minButton = new QPushButton("-", this);
    lbl = new QLabel("0", this);

    auto grid = new QGridLayout(this);
    grid->addWidget(plsButton, 0, 0);
    grid->addWidget(minButton, 0, 1);
    grid->addWidget(lbl, 1, 1);

    setLayout(grid);

    connect(plsButton, &QPushButton::clicked, this, &PlusMinus::OnPlus);
    connect(minButton, &QPushButton::clicked, this, &PlusMinus::OnMinus);
}

void PlusMinus::OnPlus() {
    auto val = lbl->text().toInt();
    ++val;
    lbl->setText(QString::number(val));
}

void PlusMinus::OnMinus() {
    auto val = lbl->text().toInt();
    --val;
    lbl->setText(QString::number(val));
}


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    PlusMinus window;
    window.resize(300, 190);
    window.setWindowTitle("Plus Minus");
    window.show();

    return app.exec();
}