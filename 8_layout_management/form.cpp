/**
 * form.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "form.h"

#include <QApplication>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

FormEx::FormEx(QWidget *parent)
    : QWidget(parent) {

    auto *nameEdit = new QLineEdit;
    auto *addrEdit = new QLineEdit;
    auto *occpEdit = new QLineEdit;

    auto *formLayout = new QFormLayout;
    formLayout->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    formLayout->addRow(tr("&Name:"), nameEdit);
    formLayout->addRow(tr("&Email:"), addrEdit);
    formLayout->addRow(tr("&Occupation:"), occpEdit);

    setLayout(formLayout);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FormEx window;
    window.setWindowTitle("QFormLayout Example");
    window.show();

    return app.exec();
}