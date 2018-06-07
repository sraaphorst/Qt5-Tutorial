/**
 * statusbar.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include "statusbar.h"

#include <QApplication>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStatusBar>

StatusBar::StatusBar(QWidget *parent)
    : QMainWindow(parent) {

    // A frame is a border.
    auto frame = new QFrame(this);
    setCentralWidget(frame);

    auto *hbox = new QHBoxLayout(frame);

    auto *okButton = new QPushButton("OK");
    hbox->addWidget(okButton, 0, Qt::AlignLeft | Qt::AlignTop);

    auto *applyButton = new QPushButton("Apply");
    hbox->addWidget(applyButton, 1, Qt::AlignLeft | Qt::AlignTop);

    // Makes the status bar. Returns it, but we can always get it again via this function.
    statusBar();

    connect(okButton, &QPushButton::clicked, this, &StatusBar::OnOkPressed);
    connect(applyButton, &QPushButton::clicked, this, &StatusBar::OnApplyPressed);
}

void StatusBar::OnOkPressed() {
    // Timeout parameter
    statusBar()->showMessage("OK button pressed", 2000);
}

void StatusBar::OnApplyPressed() {
    statusBar()->showMessage("Apply button pressed");
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    StatusBar window;
    window.setWindowTitle("QStatusBar");
    window.show();

    return app.exec();
}