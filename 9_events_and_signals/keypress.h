/**
 * keypress.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <QWidget>
#include <QTextStream>

class KeyPress : public QWidget {
public:
    KeyPress(QWidget *parent = nullptr);

protected:
    // No connect needed: this is an override of a method in QWidget.
    void keyPressEvent(QKeyEvent *e) override;

private:
    QTextStream str;
};




