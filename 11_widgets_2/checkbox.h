/**
 * checkbox.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>

class CheckBox : public QWidget {

    Q_OBJECT

public:
    CheckBox(QWidget *parent = nullptr);

private slots:
    void showTitle(int);
};


