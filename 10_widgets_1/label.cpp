/**
 * label.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "label.h"

#include <QApplication>
#include <QFont>
#include <QVBoxLayout>

Label::Label(QWidget *parent)
    : QWidget(parent) {

    QString lyrics = "Who doesn't long for someone to hold\n\
Who knows how to love you without being told\n\
Somebody tell me why I'm on my own\n\
If there's a soulmate for everyone\n\
\n\
Here we are again, circles never end\n\
How do I find the perfect fit\n\
There's enough for everyone\n\
But I'm still waiting in line\n\
\n\
Who doesn't long for someone to hold\n\
Who knows how to love you without being told\n\
Somebody tell me why I'm on my own\n\
If there's a soulmate for everyone";

    label = new QLabel(lyrics);
    label->setFont(QFont("Purisa", 10));

    auto vbox = new QVBoxLayout(this);
    vbox->addWidget(label);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Label window;
    window.setWindowTitle("QLabel");
    window.show();

    return app.exec();
}