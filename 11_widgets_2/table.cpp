/**
 * table.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "table.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QTableWidget>

Table::Table(QWidget *parent)
    : QWidget(parent) {

    auto hbox = new QHBoxLayout(this);
    auto table = new QTableWidget(15, 10);
    hbox->addWidget(table);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Table window;
    window.setWindowTitle("QTableWidget");
    window.resize(400, 250);
    window.show();

    return app.exec();
}