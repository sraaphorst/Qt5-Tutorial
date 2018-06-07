/**
 * disconnect.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QPushButton>
#include <QWidget>

class Disconnect : public QWidget {

    Q_OBJECT

public:
    Disconnect(QWidget *parent = nullptr);

private slots:
    void onClick();
    void onCheck(int);

private:
    QPushButton *button;
};




