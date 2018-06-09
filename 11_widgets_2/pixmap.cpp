/**
 * pixmap.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "pixmap.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>

Pixmap::Pixmap(QWidget *parent)
    : QWidget(parent) {

    auto hbox { new QHBoxLayout(this) };

    QPixmap pixmap("alex_workout.jpg");
    auto label { new QLabel };
    label->setPixmap(pixmap);

    hbox->addWidget(label, 0, Qt::AlignTop);
}

int main(int argc, char *argv[]) {
    QApplication app { argc, argv };

    Pixmap window;
    window.setWindowTitle("QPixmap");
    window.show();

    return app.exec();
}