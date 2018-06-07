/**
 * reviewform.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "reviewform.h"

#include <QApplication>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>

ReviewForm::ReviewForm(QWidget *parent)
    : QWidget(parent) {

    auto titleEdit = new QLineEdit;
    auto authorEdit = new QLineEdit;
    auto reviewEdit = new QTextEdit;

    auto formLayout = new QFormLayout;
    formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    formLayout->setAlignment(Qt::AlignRight | Qt::AlignTop);
    formLayout->addRow("Title:", titleEdit);
    formLayout->addRow("Author:", authorEdit);
    formLayout->addRow("Review:", reviewEdit);

    setLayout(formLayout);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ReviewForm window;
    window.setWindowTitle("Review Form");
    window.show();

    return app.exec();
}