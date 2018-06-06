/**
 * buttons.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>
#include <QPushButton>

class Buttons : public QWidget {
public:
    Buttons(QWidget *parent = nullptr);

private:
    QPushButton *okButton;
    QPushButton *applyButton;
};


