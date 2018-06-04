/**
 * PlusMinus.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "PlusMinus.h"
#include <QGridLayout>

PlusMinus::PlusMinus(QWidget *parent)
    : QWidget(parent) {
    QPushButton *plsButton = new QPushButton("+", this);
    QPushButton *minButton = new QPushButton("-", this);
    lbl = new QLabel("0", this);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(plsButton, 0, 0);
    grid->addWidget(minButton, 0, 1);
    grid->addWidget(lbl, 1, 1);

    setLayout(grid);

    connect(plsButton, &QPushButton::clicked, this, &PlusMinus::OnPlus);
    connect(minButton, &QPushButton::clicked, this, &PlusMinus::OnMinus);
}

void PlusMinus::OnPlus() {
    int val = lbl->text().toInt();
    ++val;
    lbl->setText(QString::number(val));
}

void PlusMinus::OnMinus() {
    int val = lbl->text().toInt();
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