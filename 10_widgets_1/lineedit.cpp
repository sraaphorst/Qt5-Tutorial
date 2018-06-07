/**
 * lineedit.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "lineedit.h"

#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

LineEdit::LineEdit(QWidget *parent)
    : QWidget(parent) {

    QStringList labels { "Name:", "Age:", "Occupation:" };
    auto grid = new QGridLayout(this);

    for (int i=0; i < labels.size(); ++i) {
        auto label = new QLabel(labels[i]);
        label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        auto editor = new QLineEdit;

        grid->addWidget(label, i, 0);
        grid->addWidget(editor, i, 1);
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    LineEdit window;
    window.setWindowTitle("QLineEdit");
    window.show();

    return app.exec();
}