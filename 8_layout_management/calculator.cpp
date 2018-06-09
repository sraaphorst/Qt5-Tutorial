/**
 * calculator.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "calculator.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QStyle>
#include <QVector>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent) {
    auto grid = new QGridLayout;
    grid->setSpacing(2);

    QVector<QVector<QString>> buttons {
            {"7", "8", "9", "/"},
            {"4", "5", "6", "*"},
            {"1", "2", "3", "-"},
            {"0", ".", "=", "+"}
    };

    for (int i=0; i < 4; ++i) {
        for (int j=0; j < 4; ++j) {
            auto b = new QPushButton(buttons[i][j]);
            b->setFixedSize(40, 40);
            grid->addWidget(b, i, j);
        }
    }

    setLayout(grid);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Calculator window;
    window.setWindowTitle("Calculator");
    window.resize(window.minimumSize());
    window.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, window.size(), qApp->desktop()->availableGeometry()));
    window.show();

    return app.exec();
}