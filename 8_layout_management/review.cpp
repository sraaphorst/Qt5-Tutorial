/**
 * review.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "review.h"

#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>

Review::Review(QWidget *parent)
    : QWidget(parent) {

    auto grid = new QGridLayout;
    grid->setVerticalSpacing(15);
    grid->setHorizontalSpacing(10);

    auto titleLabel = new QLabel("Title:");
    grid->addWidget(titleLabel, 0, 0, 1, 1); // row column rowspan columnspan
    titleLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    auto titleEditor = new QLineEdit;
    grid->addWidget(titleEditor, 0, 1, 1, 1);

    auto authorLabel = new QLabel("Author:");
    grid->addWidget(authorLabel, 1, 0, 1, 1);
    authorLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    auto authorEditor = new QLineEdit;
    grid->addWidget(authorEditor, 1, 1, 1, 1);

    auto reviewLabel = new QLabel("Review:");
    grid->addWidget(reviewLabel, 2, 0, 1, 1);
    reviewLabel->setAlignment(Qt::AlignRight | Qt::AlignTop);

    auto reviewEditor = new QTextEdit;
    grid->addWidget(reviewEditor, 2, 1, 3, 1);

    setLayout(grid);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Review window;
    window.setWindowTitle("Review");
    window.show();

    return app.exec();
}